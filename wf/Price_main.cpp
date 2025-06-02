#include "MyForm.h"
#include "RegisterForm.h"
#include "Price_main.h"
#include "Output.h"

int necessity = 3;//for necessity pick

System::Void wf::Price_main::log_out_btn_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	System::IO::File::Delete("stay_logged.txt");
	MyForm^ myLogForm = gcnew MyForm();
	myLogForm->stay_log->Checked = false;

	AppState::lastPosition = this->Location;

	myLogForm->StartPosition = FormStartPosition::Manual;
	myLogForm->Location = AppState::lastPosition;

	this->Hide();
	myLogForm->ShowDialog();
}

System::Void wf::Price_main::Close_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

System::Void wf::Price_main::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ item = textBox_item->Text;
	double price = 0;
	String^ description = textBox_descr->Text;

	try {
		price = Convert::ToDouble(textBox_price->Text);
	}
	catch (FormatException^) {
		MessageBox::Show(this, "Invalid price. Please enter a valid number.", "Finance", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (price < 0) {
		MessageBox::Show(this, "Don't use minus in price", "Finance ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (item->Equals("")) {
		MessageBox::Show(this, "Enter item name ", "Finance ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (necessity == 3) {
		MessageBox::Show(this, "Select necessity", "Finance ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	DB* db = new DB;
	db->add_purchase(item, price, description, necessity);
	delete db;

	textBox_item->Text = "";
	textBox_price->Text = "";
	textBox_descr->Text = "";
	necessity = 3;

	MessageBox::Show(this, " Purchase Added!", "Finance", MessageBoxButtons::OK, MessageBoxIcon::Information);

};

System::Void wf::Price_main::MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	is_drag = true;
	pos = e->Location;
}

System::Void wf::Price_main::MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (is_drag) {
		this->Location = Point(this->Location.X + e->X - pos.X, this->Location.Y + e->Y - pos.Y);
	}
}

System::Void wf::Price_main::MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	is_drag = false;
}

System::Void wf::Price_main::linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	System::Diagnostics::Process::Start("https://github.com/Yabokua?tab=repositories");
}

void wf::Price_main::set_welcome_text() {
	DB* db = new DB;
	std::string user = db->get_username();
	delete db;

	System::String^ userManaged = gcnew System::String(user.c_str());
	this->welcome_label->Text = System::String::Concat("Hi, ", userManaged, "!");
}

System::Void wf::Price_main::MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	this->ActiveControl = label_logo;
	set_welcome_text();
}

System::Void wf::Price_main::necessary_basic_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	necessity = 0;
}

System::Void wf::Price_main::necessity_necessity_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	necessity = 1;
}

System::Void wf::Price_main::necessity_not_necessity_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	necessity = 2;
}

System::Void wf::Price_main::spending_htr_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	AppState::lastPosition = this->Location;

	Output^ myOutput = gcnew Output();
	myOutput->StartPosition = FormStartPosition::Manual;
	myOutput->Location = AppState::lastPosition;

	this->Hide();
	myOutput->ShowDialog();
}
