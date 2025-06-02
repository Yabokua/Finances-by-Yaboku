#pragma once

#include <iostream>
#include <mysql/jdbc.h>
#include <msclr/marshal_cppstd.h>

using namespace System::Windows::Forms;

class DB {
private:
	const std::string SERVER = "tcp://localhost:3306";
	const std::string USER = "root";
	const std::string PASSWORD = "";
	const std::string DATABASE = "dbfirst";

	std::unique_ptr<sql::Connection> conn;
	std::unique_ptr<sql::PreparedStatement> ptmt;
	std::unique_ptr<sql::ResultSet> res;

	void connect();

	void disconnect();

public:

	void add_user(System::String^ login, System::String^ password);

	bool get_user_from_db(System::String^ login, System::String^ password);

	void add_purchase(System::String^ item_name, double price, System::String^ description, int neces);



	void loadDataIntoListView(System::Windows::Forms::ListView^ listView, int necssFilterValue, bool useDateFilter, System::DateTime fromDate, System::DateTime toDate, double& sum_count);
	void delete_string_by_id(int id);
	std::string get_username();
	double totalPrice;
	double getTotalPrice() { return totalPrice; }
	void ensure_tables_exist();
}; 