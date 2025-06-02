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
	public ref class Price_main : public System::Windows::Forms::Form
	{
	private: Form^ obj3;
	public:
		Price_main(void) {
			InitializeComponent();
		}

		Price_main(Form^ obj) {
			InitializeComponent();
			this->obj3 = obj;
		}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Price_main()
		{

			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ price_txt;
	private: System::Windows::Forms::Label^ label_logo;
	private: System::Windows::Forms::TextBox^ textBox_price;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textBox_descr;
	private: System::Windows::Forms::Button^ loggin_btn;
	private: System::Windows::Forms::Button^ Close_btn;
	private: Point pos;
	private: bool is_drag = false;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ textBox_item;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::LinkLabel^ spending_htr_link;
	private: System::Windows::Forms::LinkLabel^ log_out_btn;
	private: System::Windows::Forms::LinkLabel^ necessary_basic;
	private: System::Windows::Forms::LinkLabel^ necessity_necessity;
	private: System::Windows::Forms::LinkLabel^ necessity_not_necessity;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ welcome_label;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Price_main::typeid));
			this->price_txt = (gcnew System::Windows::Forms::Label());
			this->label_logo = (gcnew System::Windows::Forms::Label());
			this->textBox_price = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox_descr = (gcnew System::Windows::Forms::TextBox());
			this->loggin_btn = (gcnew System::Windows::Forms::Button());
			this->Close_btn = (gcnew System::Windows::Forms::Button());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBox_item = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->spending_htr_link = (gcnew System::Windows::Forms::LinkLabel());
			this->log_out_btn = (gcnew System::Windows::Forms::LinkLabel());
			this->necessary_basic = (gcnew System::Windows::Forms::LinkLabel());
			this->necessity_necessity = (gcnew System::Windows::Forms::LinkLabel());
			this->necessity_not_necessity = (gcnew System::Windows::Forms::LinkLabel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->welcome_label = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// price_txt
			// 
			this->price_txt->AutoSize = true;
			this->price_txt->BackColor = System::Drawing::Color::Transparent;
			this->price_txt->Font = (gcnew System::Drawing::Font(L"Impact", 10));
			this->price_txt->ForeColor = System::Drawing::Color::White;
			this->price_txt->Location = System::Drawing::Point(30, 93);
			this->price_txt->Name = L"price_txt";
			this->price_txt->Size = System::Drawing::Size(38, 18);
			this->price_txt->TabIndex = 1;
			this->price_txt->Text = L"Price";
			this->price_txt->Click += gcnew System::EventHandler(this, &Price_main::buy_txt_Click);
			// 
			// label_logo
			// 
			this->label_logo->AutoSize = true;
			this->label_logo->BackColor = System::Drawing::Color::Transparent;
			this->label_logo->Font = (gcnew System::Drawing::Font(L"Impact", 10));
			this->label_logo->ForeColor = System::Drawing::Color::White;
			this->label_logo->Location = System::Drawing::Point(30, 249);
			this->label_logo->Name = L"label_logo";
			this->label_logo->Size = System::Drawing::Size(75, 18);
			this->label_logo->TabIndex = 2;
			this->label_logo->Text = L"Description";
			// 
			// textBox_price
			// 
			this->textBox_price->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox_price->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_price->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_price->ForeColor = System::Drawing::Color::White;
			this->textBox_price->Location = System::Drawing::Point(9, 5);
			this->textBox_price->Name = L"textBox_price";
			this->textBox_price->Size = System::Drawing::Size(160, 26);
			this->textBox_price->TabIndex = 4;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->panel1->Controls->Add(this->textBox_price);
			this->panel1->Location = System::Drawing::Point(25, 115);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(180, 37);
			this->panel1->TabIndex = 5;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->panel2->Controls->Add(this->textBox_descr);
			this->panel2->Location = System::Drawing::Point(25, 271);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(675, 149);
			this->panel2->TabIndex = 6;
			// 
			// textBox_descr
			// 
			this->textBox_descr->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox_descr->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_descr->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_descr->ForeColor = System::Drawing::Color::White;
			this->textBox_descr->Location = System::Drawing::Point(9, 3);
			this->textBox_descr->Multiline = true;
			this->textBox_descr->Name = L"textBox_descr";
			this->textBox_descr->Size = System::Drawing::Size(655, 133);
			this->textBox_descr->TabIndex = 4;
			// 
			// loggin_btn
			// 
			this->loggin_btn->BackColor = System::Drawing::Color::White;
			this->loggin_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->loggin_btn->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->loggin_btn->Location = System::Drawing::Point(318, 430);
			this->loggin_btn->Name = L"loggin_btn";
			this->loggin_btn->Size = System::Drawing::Size(90, 27);
			this->loggin_btn->TabIndex = 7;
			this->loggin_btn->Text = L"Add";
			this->loggin_btn->UseVisualStyleBackColor = false;
			this->loggin_btn->Click += gcnew System::EventHandler(this, &Price_main::button1_Click);
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
			this->Close_btn->Location = System::Drawing::Point(689, 1);
			this->Close_btn->Name = L"Close_btn";
			this->Close_btn->Size = System::Drawing::Size(35, 35);
			this->Close_btn->TabIndex = 8;
			this->Close_btn->Text = L"X";
			this->Close_btn->UseVisualStyleBackColor = false;
			this->Close_btn->Click += gcnew System::EventHandler(this, &Price_main::Close_btn_Click);
			// 
			// linkLabel1
			// 
			this->linkLabel1->ActiveLinkColor = System::Drawing::Color::White;
			this->linkLabel1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->BackColor = System::Drawing::Color::Transparent;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"MV Boli", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linkLabel1->ForeColor = System::Drawing::Color::White;
			this->linkLabel1->LinkColor = System::Drawing::Color::White;
			this->linkLabel1->Location = System::Drawing::Point(341, 467);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(49, 16);
			this->linkLabel1->TabIndex = 10;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Yaboku";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Price_main::linkLabel1_LinkClicked);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Ink Free", 40, System::Drawing::FontStyle::Italic));
			this->label1->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->label1->Location = System::Drawing::Point(-20, -16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(221, 67);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Finances";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->panel3->Controls->Add(this->textBox_item);
			this->panel3->Location = System::Drawing::Point(25, 197);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(300, 37);
			this->panel3->TabIndex = 7;
			// 
			// textBox_item
			// 
			this->textBox_item->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox_item->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox_item->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_item->ForeColor = System::Drawing::Color::White;
			this->textBox_item->Location = System::Drawing::Point(9, 3);
			this->textBox_item->Name = L"textBox_item";
			this->textBox_item->Size = System::Drawing::Size(280, 26);
			this->textBox_item->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Impact", 10));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(30, 175);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 18);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Items name";
			// 
			// spending_htr_link
			// 
			this->spending_htr_link->ActiveLinkColor = System::Drawing::SystemColors::ButtonHighlight;
			this->spending_htr_link->AutoSize = true;
			this->spending_htr_link->BackColor = System::Drawing::Color::Transparent;
			this->spending_htr_link->DisabledLinkColor = System::Drawing::SystemColors::ControlDarkDark;
			this->spending_htr_link->Font = (gcnew System::Drawing::Font(L"Impact", 16));
			this->spending_htr_link->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->spending_htr_link->LinkColor = System::Drawing::Color::White;
			this->spending_htr_link->Location = System::Drawing::Point(523, 19);
			this->spending_htr_link->Name = L"spending_htr_link";
			this->spending_htr_link->Size = System::Drawing::Size(165, 27);
			this->spending_htr_link->TabIndex = 12;
			this->spending_htr_link->TabStop = true;
			this->spending_htr_link->Text = L"Spending history";
			this->spending_htr_link->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Price_main::spending_htr_link_LinkClicked);
			// 
			// log_out_btn
			// 
			this->log_out_btn->AutoSize = true;
			this->log_out_btn->BackColor = System::Drawing::Color::Transparent;
			this->log_out_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->log_out_btn->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->log_out_btn->LinkColor = System::Drawing::Color::White;
			this->log_out_btn->Location = System::Drawing::Point(642, 2);
			this->log_out_btn->Name = L"log_out_btn";
			this->log_out_btn->Size = System::Drawing::Size(43, 13);
			this->log_out_btn->TabIndex = 13;
			this->log_out_btn->TabStop = true;
			this->log_out_btn->Text = L"Log out";
			this->log_out_btn->VisitedLinkColor = System::Drawing::Color::Black;
			this->log_out_btn->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Price_main::log_out_btn_LinkClicked);
			// 
			// necessary_basic
			// 
			this->necessary_basic->ActiveLinkColor = System::Drawing::Color::SaddleBrown;
			this->necessary_basic->AutoSize = true;
			this->necessary_basic->BackColor = System::Drawing::Color::Transparent;
			this->necessary_basic->Font = (gcnew System::Drawing::Font(L"Impact", 14));
			this->necessary_basic->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->necessary_basic->LinkColor = System::Drawing::Color::Ivory;
			this->necessary_basic->Location = System::Drawing::Point(408, 204);
			this->necessary_basic->Name = L"necessary_basic";
			this->necessary_basic->Size = System::Drawing::Size(51, 29);
			this->necessary_basic->TabIndex = 14;
			this->necessary_basic->TabStop = true;
			this->necessary_basic->Text = L"Basic";
			this->necessary_basic->UseCompatibleTextRendering = true;
			this->necessary_basic->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Price_main::necessary_basic_LinkClicked);
			// 
			// necessity_necessity
			// 
			this->necessity_necessity->ActiveLinkColor = System::Drawing::Color::DarkOrange;
			this->necessity_necessity->AutoSize = true;
			this->necessity_necessity->BackColor = System::Drawing::Color::Transparent;
			this->necessity_necessity->Font = (gcnew System::Drawing::Font(L"Impact", 14));
			this->necessity_necessity->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->necessity_necessity->LinkColor = System::Drawing::Color::BlanchedAlmond;
			this->necessity_necessity->Location = System::Drawing::Point(474, 204);
			this->necessity_necessity->Name = L"necessity_necessity";
			this->necessity_necessity->Size = System::Drawing::Size(85, 29);
			this->necessity_necessity->TabIndex = 15;
			this->necessity_necessity->TabStop = true;
			this->necessity_necessity->Text = L"Necessity";
			this->necessity_necessity->UseCompatibleTextRendering = true;
			this->necessity_necessity->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Price_main::necessity_necessity_LinkClicked);
			// 
			// necessity_not_necessity
			// 
			this->necessity_not_necessity->ActiveLinkColor = System::Drawing::Color::Transparent;
			this->necessity_not_necessity->AutoSize = true;
			this->necessity_not_necessity->BackColor = System::Drawing::Color::Transparent;
			this->necessity_not_necessity->Font = (gcnew System::Drawing::Font(L"Impact", 14));
			this->necessity_not_necessity->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->necessity_not_necessity->LinkColor = System::Drawing::Color::Maroon;
			this->necessity_not_necessity->Location = System::Drawing::Point(567, 204);
			this->necessity_not_necessity->Name = L"necessity_not_necessity";
			this->necessity_not_necessity->Size = System::Drawing::Size(114, 29);
			this->necessity_not_necessity->TabIndex = 16;
			this->necessity_not_necessity->TabStop = true;
			this->necessity_not_necessity->Text = L"Not necessity";
			this->necessity_not_necessity->UseCompatibleTextRendering = true;
			this->necessity_not_necessity->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Price_main::necessity_not_necessity_LinkClicked);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Impact", 10));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(470, 175);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 18);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Level of necessity";
			// 
			// welcome_label
			// 
			this->welcome_label->AutoSize = true;
			this->welcome_label->BackColor = System::Drawing::Color::Transparent;
			this->welcome_label->Font = (gcnew System::Drawing::Font(L"Impact", 8));
			this->welcome_label->ForeColor = System::Drawing::Color::White;
			this->welcome_label->Location = System::Drawing::Point(525, 46);
			this->welcome_label->Name = L"welcome_label";
			this->welcome_label->Size = System::Drawing::Size(37, 15);
			this->welcome_label->TabIndex = 26;
			this->welcome_label->Text = L"label4";
			// 
			// Price_main
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(725, 486);
			this->Controls->Add(this->welcome_label);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->necessity_not_necessity);
			this->Controls->Add(this->necessity_necessity);
			this->Controls->Add(this->necessary_basic);
			this->Controls->Add(this->log_out_btn);
			this->Controls->Add(this->spending_htr_link);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->Close_btn);
			this->Controls->Add(this->loggin_btn);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label_logo);
			this->Controls->Add(this->price_txt);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Price_main";
			this->Text = L"Finance by Yaboku";
			this->Load += gcnew System::EventHandler(this, &Price_main::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Price_main::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Price_main::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Price_main::MyForm_MouseUp);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Close_btn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buy_txt_Click(System::Object^ sender, System::EventArgs^ e) {};
	private: System::Void log_out_btn_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	private: System::Void necessary_basic_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	private: System::Void necessity_necessity_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	private: System::Void necessity_not_necessity_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	private: System::Void spending_htr_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	private: void wf::Price_main::set_welcome_text();
};
}
