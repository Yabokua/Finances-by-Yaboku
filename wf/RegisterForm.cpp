#include "MyForm.h"
#include "RegisterForm.h"
#include "price_main.h"

System::Void wf::RegisterForm::Close_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

System::Void wf::RegisterForm::register_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ login = textBox_login->Text->Trim();
	String^ pass = textBox_pass->Text->Trim();

	if (login->Equals("")) {
		MessageBox::Show(this, "Enter your login ", "Finance ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (pass->Equals("")) {
		MessageBox::Show(this, "Enter your password ", "Finance ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	DB* db = new DB;
	bool result = db->get_user_from_db(login, pass);

	if (result) {
		MessageBox::Show(this, "Login alredy in use!");
		textBox_login->Text = "";
		textBox_pass->Text = "";
		return;
	}
	db->add_user(login, pass);
	delete db;

	textBox_login->Text = "";
	textBox_pass->Text = "";
	MessageBox::Show(this, "Account created!");
};

System::Void wf::RegisterForm::MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	is_drag = true; 
	pos = e->Location;
}

System::Void wf::RegisterForm::MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (is_drag) {
		this->Location = Point(this->Location.X + e->X - pos.X, this->Location.Y + e->Y - pos.Y);
	}
}

System::Void wf::RegisterForm::MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	is_drag = false;
}

System::Void wf::RegisterForm::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox1->Checked) this->textBox_pass->UseSystemPasswordChar = false;
	else this->textBox_pass->UseSystemPasswordChar = true;
}

System::Void wf::RegisterForm::linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	System::Diagnostics::Process::Start("https://github.com/Yabokua?tab=repositories");
}

System::Void wf::RegisterForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	this->ActiveControl = label_logo;
}

System::Void wf::RegisterForm::login_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	AppState::lastPosition = this->Location;

	MyForm^ my_login = gcnew MyForm();
	my_login->StartPosition = FormStartPosition::Manual;
	my_login->Location = AppState::lastPosition;

	this->Hide();
	my_login->ShowDialog();
}

