#pragma once
#include "DB.h"

namespace wf {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: Form^ obj2;
	public:
		MyForm(void)
		{
			InitializeComponent();

		}
		MyForm(Form^ obj)
		{
			InitializeComponent();
			this->obj2 = obj;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
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
	private: System::Windows::Forms::Button^ loggin_btn;
	private: System::Windows::Forms::Button^ Close_btn;
	private: Point pos;
	private: bool is_drag = false;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::LinkLabel^ reg_link;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::CheckBox^ stay_log;
	private:


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label_logo = (gcnew System::Windows::Forms::Label());
			this->textBox_login = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox_pass = (gcnew System::Windows::Forms::TextBox());
			this->loggin_btn = (gcnew System::Windows::Forms::Button());
			this->Close_btn = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->reg_link = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->stay_log = (gcnew System::Windows::Forms::CheckBox());
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
			// loggin_btn
			// 
			this->loggin_btn->BackColor = System::Drawing::Color::White;
			this->loggin_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->loggin_btn->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->loggin_btn->Location = System::Drawing::Point(84, 304);
			this->loggin_btn->Name = L"loggin_btn";
			this->loggin_btn->Size = System::Drawing::Size(110, 28);
			this->loggin_btn->TabIndex = 7;
			this->loggin_btn->Text = L"LOGIN";
			this->loggin_btn->UseVisualStyleBackColor = false;
			this->loggin_btn->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
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
			this->Close_btn->Location = System::Drawing::Point(244, 0);
			this->Close_btn->Name = L"Close_btn";
			this->Close_btn->Size = System::Drawing::Size(35, 35);
			this->Close_btn->TabIndex = 8;
			this->Close_btn->Text = L"X";
			this->Close_btn->UseVisualStyleBackColor = false;
			this->Close_btn->Click += gcnew System::EventHandler(this, &MyForm::Close_btn_Click);
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
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
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
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::linkLabel1_LinkClicked);
			// 
			// reg_link
			// 
			this->reg_link->ActiveLinkColor = System::Drawing::SystemColors::ActiveCaption;
			this->reg_link->AutoSize = true;
			this->reg_link->BackColor = System::Drawing::Color::Transparent;
			this->reg_link->DisabledLinkColor = System::Drawing::SystemColors::ActiveCaption;
			this->reg_link->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->reg_link->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->reg_link->LinkColor = System::Drawing::SystemColors::InactiveCaption;
			this->reg_link->Location = System::Drawing::Point(35, 59);
			this->reg_link->Name = L"reg_link";
			this->reg_link->Size = System::Drawing::Size(149, 21);
			this->reg_link->TabIndex = 11;
			this->reg_link->TabStop = true;
			this->reg_link->Text = L"CREATE ACCOUNT";
			this->reg_link->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::reg_link_LinkClicked);
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
			this->label1->Size = System::Drawing::Size(141, 45);
			this->label1->TabIndex = 0;
			this->label1->Text = L"LOGIN";
			// 
			// stay_log
			// 
			this->stay_log->AutoSize = true;
			this->stay_log->BackColor = System::Drawing::Color::Transparent;
			this->stay_log->ForeColor = System::Drawing::Color::White;
			this->stay_log->Location = System::Drawing::Point(149, 265);
			this->stay_log->Name = L"stay_log";
			this->stay_log->Size = System::Drawing::Size(93, 17);
			this->stay_log->TabIndex = 12;
			this->stay_log->Text = L"Stay logged in";
			this->stay_log->UseVisualStyleBackColor = false;
			this->stay_log->CheckedChanged += gcnew System::EventHandler(this, &MyForm::stay_log_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(279, 364);
			this->Controls->Add(this->stay_log);
			this->Controls->Add(this->reg_link);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->Close_btn);
			this->Controls->Add(this->loggin_btn);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label_logo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void Close_btn_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
		private: System::Void reg_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
		private: System::Void stay_log_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	};
}
