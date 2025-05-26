#include "DB.h"
#include "MyForm.h"
#include "RegisterForm.h"
#include "price_main.h"
#include "Output.h"

#include <iostream>
#include <mysql/jdbc.h>
#include <msclr/marshal_cppstd.h>

using namespace System::Windows::Forms;



void DB::connect() {
	try {
		sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
		conn = std::unique_ptr<sql::Connection>(driver->connect(SERVER, USER, PASSWORD));

		if (conn) conn->setSchema(DATABASE);
		else std::cout << "Error with connection" << std::endl;
	}
	catch (sql::SQLException& ex) {
		std::cout << ex.what() << std::endl;
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

ListBox::ObjectCollection^ DB::purchase_list(int x) {//из этого можно сделать сортировку
	DB::connect();

	std::unique_ptr<sql::Statement> stmt(conn->createStatement());
	std::unique_ptr<sql::ResultSet> res_data(stmt->executeQuery("SELECT * FROM finance"));

	DB::disconnect();

	if (!res_data->next()) return nullptr;

	ListBox^ prcs_list = gcnew ListBox;

	while (res_data->next()) {
		System::String^ value = gcnew System::String(res_data->getString("item_name").c_str());
		prcs_list->Items->Add(value);
	}
	return prcs_list->Items;
}

//System::Data::DataTable^ DB::get_all_db_data() {
//	try {
//		DB::connect();
//
//		std::string query = "SELECT * FROM finance";
//		std::unique_ptr<sql::PreparedStatement> ptmt(conn->prepareStatement(query));
//		std::unique_ptr<sql::ResultSet> res(ptmt->executeQuery());
//
//		// Создаем объект DataTable для хранения данных
//		System::Data::DataTable^ dataTable = gcnew System::Data::DataTable();
//
//		// Заполняем заголовки столбцов
//		int columnCount = res->getMetaData()->getColumnCount();
//		for (int i = 1; i <= columnCount; i++) {
//			dataTable->Columns->Add(gcnew System::String(res->getMetaData()->getColumnLabel(i).c_str()));
//		}
//
//		// Заполняем строки
//		while (res->next()) {
//			System::Data::DataRow^ row = dataTable->NewRow();
//			for (int i = 1; i <= columnCount; i++) {
//				row[i - 1] = gcnew System::String(res->getString(i).c_str());
//			}
//			dataTable->Rows->Add(row);
//		}
//
//		DB::disconnect(); // Закрываем соединение
//		//dataGridView1->DataSource = dataTable;
//
//		return dataTable;
//	}
//	catch (sql::SQLException& ex) {
//		std::cout << ex.what() << std::endl;
//
//	}
//}



void DB::loadDataIntoListView(ListView^ listView, int necssFilterValue, bool useDateFilter, System::DateTime fromDate, System::DateTime toDate) {
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

	// Заголовки
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

	// Данные
	while (res->next()) {
		int id = res->getInt(1);
		System::String^ name = gcnew System::String(res->getString(2).c_str());
		ListViewItem^ item = gcnew ListViewItem(name);
		item->Tag = id;

		for (int i = 3; i <= columnCount; i++) {
			std::string value = res->getString(i);
			if (i == 4) { // necessity
				if (value == "0") value = "Basic";
				else if (value == "1") value = "Necessity";
				else if (value == "2") value = "Not necessity";
			}

			if (i == 6) { // Description
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

