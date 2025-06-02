#include "MyForm.h"
#include "RegisterForm.h"
#include "Price_main.h"
#include "Output.h"
#include "DB.h"

double sum;

void wf::Output::set_welcome_text() {
	DB* db = new DB;
	std::string user = db->get_username();
	delete db;

	System::String^ userManaged = gcnew System::String(user.c_str());
	this->welcome_label->Text = System::String::Concat("Hi, ", userManaged, "!");
}


System::Void wf::Output::log_out_btn_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	System::IO::File::Delete("stay_logged.txt");
	MyForm^ myLogFornInOutput = gcnew MyForm();
	myLogFornInOutput->stay_log->Checked = false;

	AppState::lastPosition = this->Location;

	myLogFornInOutput->StartPosition = FormStartPosition::Manual;
	myLogFornInOutput->Location = AppState::lastPosition;

	this->Hide();
	myLogFornInOutput->ShowDialog();
}

System::Void wf::Output::Close_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

System::Void wf::Output::MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	is_drag = true;
	pos = e->Location;
}

System::Void wf::Output::MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (is_drag) {
		this->Location = Point(this->Location.X + e->X - pos.X, this->Location.Y + e->Y - pos.Y);
	}
}

System::Void wf::Output::MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	is_drag = false;
}

System::Void wf::Output::linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	System::Diagnostics::Process::Start("https://github.com/Yabokua?tab=repositories");
}

System::Void wf::Output::MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	this->ActiveControl = label1_logo;


	if (comboBox1->Items->Count == 0) {
		comboBox1->Items->Add("Basic");
		comboBox1->Items->Add("Not necessity");
		comboBox1->Items->Add("Necessity");
		comboBox1->Items->Add("All");
		comboBox1->SelectedItem = "All";

		bool enabled = checkBoxDateFilter->Checked;
		dateTimePickerFrom->Enabled = enabled;
		dateTimePickerTo->Enabled = enabled;

		this->listView1->ColumnClick += gcnew ColumnClickEventHandler(this, &Output::listView1_ColumnClick);
	}
	set_welcome_text();
}

System::Void wf::Output::show_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	listView1->Items->Clear();


	int selectedFilter = get_from_comboBox(this->comboBox1);

	bool useDateFilter = checkBoxDateFilter->Checked;
	DateTime fromDate = dateTimePickerFrom->Value.Date;
	DateTime toDate = dateTimePickerTo->Value.Date;

	DB* db = new DB;
	db->loadDataIntoListView(listView1, selectedFilter, useDateFilter, fromDate, toDate, sum);
	delete db;

	set_count_label();
}

void wf::Output::set_count_label() {
	this->count_label->Text = System::String::Concat("Total spend: ", sum);
};

System::Void wf::Output::purchase_link_Click(System::Object^ sender, System::EventArgs^ e) {
	AppState::lastPosition = this->Location; 

	Price_main^ add_prc = gcnew Price_main();
	add_prc->StartPosition = FormStartPosition::Manual;
	add_prc->Location = AppState::lastPosition;

	this->Hide();
	add_prc->ShowDialog(); 
}

int wf::Output::get_from_comboBox(System::Windows::Forms::ComboBox^ cb) {
	if (cb->SelectedItem == nullptr)
		return 3;

	System::String^ selected = cb->SelectedItem->ToString();

	if (selected == "Basic") return 0;
	else if (selected == "Necessity") return 1;
	else if (selected == "Not necessity") return 2;
	else if (selected == "All") return 3;

	return 3; 
}

System::Void wf::Output::listView1_MouseClick(System::Object^ sender, MouseEventArgs^ e) {
	ListViewHitTestInfo^ info = listView1->HitTest(e->Location);

	if (info->Item != nullptr) {
		int columnIndex = -1;
		int x = 0;

		for (int i = 0; i < listView1->Columns->Count; i++) {// check click on column
			x += listView1->Columns[i]->Width;
			if (e->X < x) {
				columnIndex = i;
				break;
			}
		}

		if (columnIndex == listView1->Columns->Count - 2) {// if click on "Delete"
			System::Windows::Forms::DialogResult result = MessageBox::Show("Delete purchase?", "Confirmation", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			if (result == System::Windows::Forms::DialogResult::Yes) {
				int id = safe_cast<int>(info->Item->Tag);

				DB* db = new DB;
				db->delete_string_by_id(id);
				delete db;

				listView1->Items->Remove(info->Item);
			}
		}
	}
}

ref class ListViewItemComparer : public System::Collections::IComparer {// for sort in listView

private:
	int column;
	bool ascending;  

public:
	ListViewItemComparer(int columnIndex, bool asc) {
		column = columnIndex;
		ascending = asc;
	}

	virtual int Compare(Object^ x, Object^ y) {
		ListViewItem^ item1 = dynamic_cast<ListViewItem^>(x);
		ListViewItem^ item2 = dynamic_cast<ListViewItem^>(y);

		System::String^ val1 = item1->SubItems[column]->Text;
		System::String^ val2 = item2->SubItems[column]->Text;

		int result = 0;
		double num1, num2;
		System::DateTime dt1, dt2;

		if (System::Double::TryParse(val1, num1) && System::Double::TryParse(val2, num2)) {
			result = num1.CompareTo(num2);
		}
		else if (System::DateTime::TryParse(val1, dt1) && System::DateTime::TryParse(val2, dt2)) {
			result = dt1.CompareTo(dt2);
		}
		else {
			result = System::String::Compare(val1, val2);
		}

		return ascending ? result : -result;
	}

};

System::Void wf::Output::checkBoxDateFilter_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	bool enabled = checkBoxDateFilter->Checked;
	dateTimePickerFrom->Enabled = enabled;
	dateTimePickerTo->Enabled = enabled;
}

System::Void wf::Output::listView1_ColumnClick(System::Object^ sender, ColumnClickEventArgs^ e) {
	if (e->Column == lastSortedColumn)
		sortAscending = !sortAscending;
	else {
		lastSortedColumn = e->Column;
		sortAscending = true;
	}

	listView1->ListViewItemSorter = gcnew ListViewItemComparer(e->Column, sortAscending);
	listView1->Sort();
}

