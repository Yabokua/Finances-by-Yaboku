#pragma once
#include "DB.h"

using namespace System::Drawing;

namespace wf {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	private: Form^ obj;
	public:
		RegisterForm(void) {
			InitializeComponent();
		}

		RegisterForm(Form^ obj) {
			InitializeComponent();
			this->obj = obj;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label_logo;
	private: System::Windows::Forms::TextBox^ textBox_login;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textBox_pass;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ Close_btn;
	private: Point pos;
	private: bool is_drag = false;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::LinkLabel^ login_link;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label_logo = (gcnew System::Windows::Forms::Label());
			this->textBox_login = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox_pass = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Close_btn = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->login_link = (gcnew System::Windows::Forms::LinkLabel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Impact", 13));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Location = System::Drawing::Point(33, 112);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 22);
			this->label2->TabIndex = 1;
			this->label2->Text = L"LOGIN";
			// 
			// label_logo
			// 
			this->label_logo->AutoSize = true;
			this->label_logo->BackColor = System::Drawing::Color::Transparent;
			this->label_logo->Font = (gcnew System::Drawing::Font(L"Impact", 13));
			this->label_logo->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label_logo->Location = System::Drawing::Point(33, 204);
			this->label_logo->Name = L"label_logo";
			this->label_logo->Size = System::Drawing::Size(91, 22);
			this->label_logo->TabIndex = 2;
			this->label_logo->Text = L"PASSWORD";
			// 
			// textBox_login
			// 
			this->textBox_login->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox_login->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_login->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_login->ForeColor = System::Drawing::Color::White;
			this->textBox_login->Location = System::Drawing::Point(9, 3);
			this->textBox_login->Name = L"textBox_login";
			this->textBox_login->Size = System::Drawing::Size(186, 26);
			this->textBox_login->TabIndex = 4;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->panel1->Controls->Add(this->textBox_login);
			this->panel1->Location = System::Drawing::Point(37, 134);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(205, 32);
			this->panel1->TabIndex = 5;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->panel2->Controls->Add(this->textBox_pass);
			this->panel2->Location = System::Drawing::Point(37, 226);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(205, 32);
			this->panel2->TabIndex = 6;
			// 
			// textBox_pass
			// 
			this->textBox_pass->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox_pass->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_pass->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_pass->ForeColor = System::Drawing::Color::White;
			this->textBox_pass->Location = System::Drawing::Point(9, 3);
			this->textBox_pass->Name = L"textBox_pass";
			this->textBox_pass->Size = System::Drawing::Size(183, 26);
			this->textBox_pass->TabIndex = 4;
			this->textBox_pass->UseSystemPasswordChar = true;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Location = System::Drawing::Point(84, 304);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 28);
			this->button1->TabIndex = 7;
			this->button1->Text = L"CREATE";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &RegisterForm::register_Click);
			// 
			// Close_btn
			// 
			this->Close_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Close_btn->BackColor = System::Drawing::Color::Transparent;
			this->Close_btn->FlatAppearance->BorderSize = 0;
			this->Close_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Close_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Close_btn->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->Close_btn->Location = System::Drawing::Point(243, 1);
			this->Close_btn->Name = L"Close_btn";
			this->Close_btn->Size = System::Drawing::Size(35, 35);
			this->Close_btn->TabIndex = 8;
			this->Close_btn->Text = L"X";
			this->Close_btn->UseVisualStyleBackColor = false;
			this->Close_btn->Click += gcnew System::EventHandler(this, &RegisterForm::Close_btn_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::Color::Transparent;
			this->checkBox1->ForeColor = System::Drawing::Color::White;
			this->checkBox1->Location = System::Drawing::Point(37, 265);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(101, 17);
			this->checkBox1->TabIndex = 9;
			this->checkBox1->Text = L"Show password";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &RegisterForm::checkBox1_CheckedChanged);
			// 
			// linkLabel1
			// 
			this->linkLabel1->ActiveLinkColor = System::Drawing::Color::Brown;
			this->linkLabel1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"MV Boli", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linkLabel1->LinkColor = System::Drawing::Color::White;
			this->linkLabel1->Location = System::Drawing::Point(118, 344);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(49, 16);
			this->linkLabel1->TabIndex = 10;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Yaboku";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &RegisterForm::linkLabel1_LinkClicked);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(29, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(171, 45);
			this->label1->TabIndex = 0;
			this->label1->Text = L"CREATE";
			// 
			// login_link
			// 
			this->login_link->ActiveLinkColor = System::Drawing::SystemColors::ActiveCaption;
			this->login_link->AutoSize = true;
			this->login_link->BackColor = System::Drawing::Color::Transparent;
			this->login_link->DisabledLinkColor = System::Drawing::SystemColors::ActiveCaption;
			this->login_link->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->login_link->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->login_link->LinkColor = System::Drawing::SystemColors::InactiveCaption;
			this->login_link->Location = System::Drawing::Point(35, 60);
			this->login_link->Name = L"login_link";
			this->login_link->Size = System::Drawing::Size(65, 24);
			this->login_link->TabIndex = 13;
			this->login_link->TabStop = true;
			this->login_link->Text = L"LOGIN";
			this->login_link->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &RegisterForm::login_link_LinkClicked);
			// 
			// RegisterForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(279, 364);
			this->Controls->Add(this->login_link);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->Close_btn);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label_logo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"RegisterForm";
			this->Text = L"Finance by Yaboku";
			this->Load += gcnew System::EventHandler(this, &RegisterForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &RegisterForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &RegisterForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &RegisterForm::MyForm_MouseUp);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Close_btn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void register_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void login_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	};
}

public ref class AppState {// класс для хранения позиции окна
public:
	static Point lastPosition = Point(100, 100); // Начальная позиция окна
};