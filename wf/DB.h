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

	ListBox::ObjectCollection^ purchase_list(int x);// не юзаю

	System::Data::DataTable^ get_all_db_data() {
		try {
			connect();

			std::string query = "SELECT * FROM finance"; 
			std::unique_ptr<sql::PreparedStatement> ptmt(conn->prepareStatement(query));
			std::unique_ptr<sql::ResultSet> res(ptmt->executeQuery());

			// Создаем объект DataTable для хранения данных
			System::Data::DataTable^ dataTable = gcnew System::Data::DataTable();

			// Заполняем заголовки столбцов
			int columnCount = res->getMetaData()->getColumnCount();
			for (int i = 1; i <= columnCount; i++) {
				dataTable->Columns->Add(gcnew System::String(res->getMetaData()->getColumnLabel(i).c_str()));
			}

			// Заполняем строки
			while (res->next()) {
				System::Data::DataRow^ row = dataTable->NewRow();
				for (int i = 1; i <= columnCount; i++) {
					row[i - 1] = gcnew System::String(res->getString(i).c_str());
				}
				dataTable->Rows->Add(row);
			}

			disconnect(); // Закрываем соединение
			//dataGridView1->DataSource = dataTable;

			return dataTable;
		}
		catch (sql::SQLException& ex) {
			std::cout << ex.what() << std::endl;

		}
	}

	void loadDataIntoListView(System::Windows::Forms::ListView^ listView, int necssFilterValue, bool useDateFilter, System::DateTime fromDate, System::DateTime toDate);
	void delete_string_by_id(int id);
}; 