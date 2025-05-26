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
	public ref class Output : public System::Windows::Forms::Form
	{
	private: Form^ obj5;
	public:
		Output(void) {
			InitializeComponent();

		}

		Output(Form^ obj) {
			InitializeComponent();
			this->obj5 = obj;
		}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Output()
		{

			if (components)
			{
				delete components;
			}
		}

	private:
		int lastSortedColumn = -1;
		bool sortAscending = true;

	private: System::Windows::Forms::Button^ Close_btn;
	private: Point pos;
	private: bool is_drag = false;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::Label^ label1_logo;
	private: System::Windows::Forms::LinkLabel^ log_out_btn;
	private: System::Windows::Forms::LinkLabel^ purchase_link;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ show_btn;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerFrom;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerTo;
	private: System::Windows::Forms::CheckBox^ checkBoxDateFilter;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Output::typeid));
			this->Close_btn = (gcnew System::Windows::Forms::Button());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label1_logo = (gcnew System::Windows::Forms::Label());
			this->log_out_btn = (gcnew System::Windows::Forms::LinkLabel());
			this->purchase_link = (gcnew System::Windows::Forms::LinkLabel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->show_btn = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->dateTimePickerFrom = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePickerTo = (gcnew System::Windows::Forms::DateTimePicker());
			this->checkBoxDateFilter = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
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
			this->Close_btn->Click += gcnew System::EventHandler(this, &Output::Close_btn_Click);
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
			this->linkLabel1->Location = System::Drawing::Point(346, 460);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(49, 16);
			this->linkLabel1->TabIndex = 10;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Yaboku";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Output::linkLabel1_LinkClicked);
			// 
			// label1_logo
			// 
			this->label1_logo->AutoSize = true;
			this->label1_logo->BackColor = System::Drawing::Color::Transparent;
			this->label1_logo->Font = (gcnew System::Drawing::Font(L"Ink Free", 40, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_logo->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->label1_logo->Location = System::Drawing::Point(-20, -16);
			this->label1_logo->Name = L"label1_logo";
			this->label1_logo->Size = System::Drawing::Size(221, 67);
			this->label1_logo->TabIndex = 0;
			this->label1_logo->Text = L"Finances";
			// 
			// log_out_btn
			// 
			this->log_out_btn->AutoSize = true;
			this->log_out_btn->BackColor = System::Drawing::Color::Transparent;
			this->log_out_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->log_out_btn->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->log_out_btn->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->log_out_btn->LinkColor = System::Drawing::SystemColors::ButtonFace;
			this->log_out_btn->Location = System::Drawing::Point(642, 2);
			this->log_out_btn->Name = L"log_out_btn";
			this->log_out_btn->Size = System::Drawing::Size(43, 13);
			this->log_out_btn->TabIndex = 13;
			this->log_out_btn->TabStop = true;
			this->log_out_btn->Text = L"Log out";
			this->log_out_btn->VisitedLinkColor = System::Drawing::Color::WhiteSmoke;
			this->log_out_btn->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Output::log_out_btn_LinkClicked);
			// 
			// purchase_link
			// 
			this->purchase_link->ActiveLinkColor = System::Drawing::SystemColors::ButtonHighlight;
			this->purchase_link->AutoSize = true;
			this->purchase_link->BackColor = System::Drawing::Color::Transparent;
			this->purchase_link->DisabledLinkColor = System::Drawing::SystemColors::ButtonHighlight;
			this->purchase_link->Font = (gcnew System::Drawing::Font(L"Impact", 16));
			this->purchase_link->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->purchase_link->LinkColor = System::Drawing::SystemColors::ButtonHighlight;
			this->purchase_link->Location = System::Drawing::Point(551, 19);
			this->purchase_link->Name = L"purchase_link";
			this->purchase_link->Size = System::Drawing::Size(135, 27);
			this->purchase_link->TabIndex = 12;
			this->purchase_link->TabStop = true;
			this->purchase_link->Text = L"Add purchase";
			this->purchase_link->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Output::linkLabel2_LinkClicked);
			this->purchase_link->Click += gcnew System::EventHandler(this, &Output::purchase_link_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->ForeColor = System::Drawing::Color::White;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->ItemHeight = 15;
			this->comboBox1->Location = System::Drawing::Point(461, 124);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(120, 23);
			this->comboBox1->TabIndex = 14;
			// 
			// show_btn
			// 
			this->show_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->show_btn->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->show_btn->Location = System::Drawing::Point(603, 123);
			this->show_btn->Name = L"show_btn";
			this->show_btn->Size = System::Drawing::Size(75, 25);
			this->show_btn->TabIndex = 17;
			this->show_btn->Text = L"Show";
			this->show_btn->UseVisualStyleBackColor = true;
			this->show_btn->Click += gcnew System::EventHandler(this, &Output::show_btn_Click);
			// 
			// listView1
			// 
			this->listView1->AllowColumnReorder = true;
			this->listView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listView1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->listView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listView1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listView1->ForeColor = System::Drawing::Color::White;
			this->listView1->FullRowSelect = true;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(35, 165);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(655, 286);
			this->listView1->TabIndex = 18;
			this->listView1->TileSize = System::Drawing::Size(288, 46);
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Output::listView1_MouseClick);
			// 
			// dateTimePickerFrom
			// 
			this->dateTimePickerFrom->CalendarMonthBackground = System::Drawing::SystemColors::InactiveCaption;
			this->dateTimePickerFrom->CalendarTitleBackColor = System::Drawing::SystemColors::InactiveCaption;
			this->dateTimePickerFrom->CalendarTitleForeColor = System::Drawing::SystemColors::ControlText;
			this->dateTimePickerFrom->Checked = false;
			this->dateTimePickerFrom->Location = System::Drawing::Point(35, 125);
			this->dateTimePickerFrom->Name = L"dateTimePickerFrom";
			this->dateTimePickerFrom->Size = System::Drawing::Size(200, 20);
			this->dateTimePickerFrom->TabIndex = 19;
			// 
			// dateTimePickerTo
			// 
			this->dateTimePickerTo->CalendarMonthBackground = System::Drawing::SystemColors::InactiveCaption;
			this->dateTimePickerTo->CalendarTitleBackColor = System::Drawing::SystemColors::InactiveCaption;
			this->dateTimePickerTo->CalendarTitleForeColor = System::Drawing::SystemColors::ControlText;
			this->dateTimePickerTo->Checked = false;
			this->dateTimePickerTo->Location = System::Drawing::Point(244, 125);
			this->dateTimePickerTo->Name = L"dateTimePickerTo";
			this->dateTimePickerTo->Size = System::Drawing::Size(200, 20);
			this->dateTimePickerTo->TabIndex = 20;
			// 
			// checkBoxDateFilter
			// 
			this->checkBoxDateFilter->AutoSize = true;
			this->checkBoxDateFilter->BackColor = System::Drawing::Color::Transparent;
			this->checkBoxDateFilter->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->checkBoxDateFilter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->checkBoxDateFilter->ForeColor = System::Drawing::Color::White;
			this->checkBoxDateFilter->Location = System::Drawing::Point(370, 108);
			this->checkBoxDateFilter->Name = L"checkBoxDateFilter";
			this->checkBoxDateFilter->Size = System::Drawing::Size(76, 17);
			this->checkBoxDateFilter->TabIndex = 21;
			this->checkBoxDateFilter->Text = L"Apply date";
			this->checkBoxDateFilter->UseVisualStyleBackColor = false;
			this->checkBoxDateFilter->CheckedChanged += gcnew System::EventHandler(this, &Output::checkBoxDateFilter_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Impact", 10));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(461, 105);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 18);
			this->label1->TabIndex = 22;
			this->label1->Text = L"Category:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Impact", 10));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(35, 105);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 18);
			this->label2->TabIndex = 23;
			this->label2->Text = L"Date from:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Impact", 10));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(244, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 18);
			this->label3->TabIndex = 24;
			this->label3->Text = L"Date to:";
			// 
			// Output
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(725, 486);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBoxDateFilter);
			this->Controls->Add(this->dateTimePickerTo);
			this->Controls->Add(this->dateTimePickerFrom);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->show_btn);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->log_out_btn);
			this->Controls->Add(this->purchase_link);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->Close_btn);
			this->Controls->Add(this->label1_logo);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Output";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &Output::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Output::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Output::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Output::MyForm_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Close_btn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buy_txt_Click(System::Object^ sender, System::EventArgs^ e) {};
	private: System::Void log_out_btn_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
	private: System::Void linkLabel2_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {}
	private: System::Void reg_link_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {}
	private: System::Void show_btn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void purchase_link_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void listView1_MouseClick(System::Object^ sender, MouseEventArgs^ e);
	private: System::Void checkBoxDateFilter_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	public:  int get_from_comboBox(System::Windows::Forms::ComboBox^ cb);
	public: System::Void listView1_ColumnClick(System::Object^ sender, ColumnClickEventArgs^ e);
	};
}

