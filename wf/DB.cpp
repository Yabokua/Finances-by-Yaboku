#include "DB.h"
#include "MyForm.h"
#include "RegisterForm.h"
#include "price_main.h"
#include "Output.h"

#include <iostream>
#include <mysql/jdbc.h>
#include <msclr/marshal_cppstd.h>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace System::Windows::Forms;

std::string loadUsername();

std::string username = loadUsername();

void saveUsername(const std::string& username) {
	std::ofstream ofs("username.txt");
	if (ofs.is_open()) {
		ofs << username;
	}
}

std::string loadUsername() {
	std::ifstream ifs("username.txt");
	std::string usernameFromFile;
	if (ifs.is_open()) {
		std::getline(ifs, usernameFromFile);
	}
	return usernameFromFile;
}

void DB::ensure_tables_exist() {
	try {
		std::unique_ptr<sql::Statement> stmt(conn->createStatement());

		std::string createUsersTable = R"(
            CREATE TABLE IF NOT EXISTS users (
                id INT AUTO_INCREMENT PRIMARY KEY,
                login VARCHAR(255) NOT NULL UNIQUE,
                password VARCHAR(255) NOT NULL
            )
        )";

		std::string createFinanceTable = R"(
            CREATE TABLE IF NOT EXISTS finance (
                id INT AUTO_INCREMENT PRIMARY KEY,
                item_name VARCHAR(255) NOT NULL,
                price DOUBLE NOT NULL,
                description TEXT,
                necessity INT NOT NULL,
                date DATE DEFAULT CURRENT_DATE,
				delete_str VARCHAR(255) DEFAULT '     X',
                null_teminated VARCHAR(255)
            )
        )";

		stmt->execute(createUsersTable);
		stmt->execute(createFinanceTable);
	}
	catch (sql::SQLException& ex) {
		std::cout << "Error ensuring tables exist: " << ex.what() << std::endl;
	}
}


void DB::connect() {
	try {
		sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
		conn = std::unique_ptr<sql::Connection>(driver->connect(SERVER, USER, PASSWORD));

		std::unique_ptr<sql::Statement> stmt(conn->createStatement());
		stmt->execute("CREATE DATABASE IF NOT EXISTS " + DATABASE);

		conn->setSchema(DATABASE);

		ensure_tables_exist();
	}
	catch (sql::SQLException& ex) {
		std::cout << "Connection error: " << ex.what() << std::endl;
	}
}

void DB::disconnect() {
	if (conn) {
		conn->close();
	}
}


void DB::add_user(System::String^ login, System::String^ password) {
	DB::connect();

	std::string user_login = msclr::interop::marshal_as<std::string>(login);
	std::string user_pass = msclr::interop::marshal_as<std::string>(password);

	try {
		ptmt = std::unique_ptr<sql::PreparedStatement>(conn->prepareStatement("INSERT INTO users(login, password) VALUES(?, ?)"));

		ptmt->setString(1, user_login);
		ptmt->setString(2, user_pass);
		ptmt->execute();
	}
	catch (sql::SQLException& ex) {
		std::cout << ex.what() << std::endl;
	}

	DB::disconnect();
}

bool DB::get_user_from_db(System::String^ login, System::String^ password) {
	bool is_user_found = false;

	std::string user_login = msclr::interop::marshal_as<std::string>(login);
	std::string user_pass = msclr::interop::marshal_as<std::string>(password);

	try {
		DB::connect();

		ptmt = std::unique_ptr<sql::PreparedStatement>(conn->prepareStatement("SELECT id FROM users WHERE login = ? AND password = ?"));

		ptmt->setString(1, user_login);
		ptmt->setString(2, user_pass);
		res = std::unique_ptr<sql::ResultSet>(ptmt->executeQuery());

		is_user_found = res->next();
		if (is_user_found) {
			username = user_login;
			saveUsername(username);
		}
	}
	catch (sql::SQLException& ex) {
		std::cout << ex.what() << std::endl;
	}

	DB::disconnect();

	return is_user_found;
}

void DB::add_purchase(System::String^ item_name, double price, System::String^ description, int neces) {
	DB::connect();
	std::string input_item = msclr::interop::marshal_as<std::string>(item_name);
	std::string input_descr = msclr::interop::marshal_as<std::string>(description);

	try {

		ptmt = std::unique_ptr<sql::PreparedStatement>(conn->prepareStatement("INSERT INTO finance(item_name, price, description, necessity) VALUES(?, ?, ?, ?)"));

		ptmt->setString(1, input_item);
		ptmt->setDouble(2, price);
		ptmt->setString(3, input_descr);
		ptmt->setInt(4, neces);

		ptmt->execute();
	}
	catch (sql::SQLException& ex) {
		std::cout << ex.what() << std::endl;
	}

	DB::disconnect();
}

void DB::loadDataIntoListView(ListView^ listView, int necssFilterValue, bool useDateFilter, System::DateTime fromDate, System::DateTime toDate, double& sum_count) {
	listView->Items->Clear();
	listView->Columns->Clear();
	listView->View = View::Details;

	DB::connect();

	std::string query = "SELECT id, item_name, price, necessity, date, description, delete_str, null_teminated "
		"FROM finance WHERE (? = 3 OR necessity = ?)";

	if (useDateFilter) {
		query += " AND date BETWEEN ? AND ?";
	}

	ptmt = std::unique_ptr<sql::PreparedStatement>(conn->prepareStatement(query));
	ptmt->setInt(1, necssFilterValue);
	ptmt->setInt(2, necssFilterValue);

	if (useDateFilter) {
		ptmt->setString(3, msclr::interop::marshal_as<std::string>(fromDate.ToString("yyyy-MM-dd")));
		ptmt->setString(4, msclr::interop::marshal_as<std::string>(toDate.ToString("yyyy-MM-dd")));
	}

	res = std::unique_ptr<sql::ResultSet>(ptmt->executeQuery());

	int columnCount = res->getMetaData()->getColumnCount();
	for (int i = 2; i <= columnCount; i++) {
		std::string columnName = res->getMetaData()->getColumnLabel(i);
		if (columnName == "item_name") columnName = "Name";
		if (columnName == "price") columnName = "Price";
		if (columnName == "necessity") columnName = "Necessity";
		if (columnName == "date") columnName = "Date";
		if (columnName == "description") columnName = "Description";
		if (columnName == "delete_str") columnName = "Delete";
		if (columnName == "null_teminated") columnName = "";

		listView->Columns->Add(gcnew System::String(columnName.c_str()), -2, HorizontalAlignment::Left);
	}

	sum_count = 0.0;

	while (res->next()) {
		int id = res->getInt(1);
		System::String^ name = gcnew System::String(res->getString(2).c_str());
		ListViewItem^ item = gcnew ListViewItem(name);
		item->Tag = id;

		for (int i = 3; i <= columnCount; i++) {
			std::string value = res->getString(i);

			if (i == 3) {//price
				try {
					double priceVal = std::stod(value);
					sum_count += priceVal;

					std::ostringstream oss;
					if (priceVal == static_cast<int>(priceVal)) {
						oss << static_cast<int>(priceVal);
					}
					else {
						oss << std::fixed << std::setprecision(2) << priceVal;
					}
					value = oss.str();
				}
				catch (...) {
				}
			}

			if (i == 4) { // necessity
				if (value == "0") value = "Basic";
				else if (value == "1") value = "Necessity";
				else if (value == "2") value = "Not necessity";
			}

			if (i == 6) { // description
				if (value.length() > 31) {
					value = value.substr(0, 31) + "...";
				}
			}

			item->SubItems->Add(gcnew System::String(value.c_str()));
		}


		listView->Items->Add(item);
	}

	DB::disconnect();

	listView->AutoResizeColumns(ColumnHeaderAutoResizeStyle::HeaderSize);
}


void DB::delete_string_by_id(int id) {
	DB::connect();

	std::string query = "DELETE FROM finance WHERE id = ?";
	ptmt = std::unique_ptr<sql::PreparedStatement>(conn->prepareStatement(query));
	ptmt->setInt(1, id);
	ptmt->execute();

	DB::disconnect();
}

std::string DB::get_username() {
	return username;
};

