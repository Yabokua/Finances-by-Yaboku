#include "MyForm.h"
#include "RegisterForm.h"
#include "price_main.h"
#include "Output.h"

System::Void wf::MyForm::reg_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	AppState::lastPosition = this->Location;

	RegisterForm^ registerForm = gcnew RegisterForm();
	registerForm->StartPosition = FormStartPosition::Manual;
	registerForm->Location = AppState::lastPosition;

	this->Hide();
	registerForm->ShowDialog();
}

System::Void wf::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {

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
	delete db;

	if (!result) {
		MessageBox::Show(this, "User not found!");
		return;
	}

	textBox_login->Text = "";
	textBox_pass->Text = "";

	AppState::lastPosition = this->Location;

	Output^ output_form = gcnew Output();
	output_form->StartPosition = FormStartPosition::Manual;
	output_form->Location = AppState::lastPosition;

	this->Hide();
	output_form->ShowDialog();

};

System::Void wf::MyForm::Close_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

System::Void wf::MyForm::MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	is_drag = true;
	pos = e->Location;
}

System::Void wf::MyForm::MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (is_drag) {
		this->Location = Point(this->Location.X + e->X - pos.X, this->Location.Y + e->Y - pos.Y);
	}
}

System::Void wf::MyForm::MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	is_drag = false;
}

System::Void wf::MyForm::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox1->Checked) this->textBox_pass->UseSystemPasswordChar = false;//show password
	else this->textBox_pass->UseSystemPasswordChar = true;
}

System::Void wf::MyForm::linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	System::Diagnostics::Process::Start("https://github.com/Yabokua?tab=repositories");
}

System::Void wf::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	this->ActiveControl = label_logo;

	if (System::IO::File::Exists("stay_logged.txt")) {//check stay log
		stay_log->Checked = true;

		AppState::lastPosition = this->Location; //save location

		Output^ outputForm = gcnew Output();
		outputForm->StartPosition = FormStartPosition::Manual;
		outputForm->Location = AppState::lastPosition;

		this->Hide();
		outputForm->ShowDialog();
	}
}


System::Void wf::MyForm::stay_log_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (stay_log->Checked) {
		System::IO::File::WriteAllText("stay_logged.txt", "1");// save flag in file
	}
	else {
		if (System::IO::File::Exists("stay_logged.txt"))
			System::IO::File::Delete("stay_logged.txt");// delete flag
	}
}
