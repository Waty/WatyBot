#pragma once

namespace CCPLZBirthday {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			ddbMouseFly->SelectedIndex = 1;
			ddbSitHack->SelectedIndex = 1;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		Button^  bHack;
		ComboBox^  ddbHotkey;
		bool Enabled;
		Timer^  sithackTimer;
		Label^  label1;
		Label^  label3;
		ComboBox^  ddbSitHack;
		Label^  label2;
		ComboBox^  ddbMouseFly;

		IContainer^  components;

		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->bHack = (gcnew System::Windows::Forms::Button());
			this->ddbHotkey = (gcnew System::Windows::Forms::ComboBox());
			this->sithackTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->ddbSitHack = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ddbMouseFly = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// bHack
			// 
			this->bHack->Location = System::Drawing::Point(12, 12);
			this->bHack->Name = L"bHack";
			this->bHack->Size = System::Drawing::Size(113, 23);
			this->bHack->TabIndex = 0;
			this->bHack->Text = L"Turn on Hacks";
			this->bHack->UseVisualStyleBackColor = true;
			this->bHack->Click += gcnew System::EventHandler(this, &MyForm::bHack_Click);
			// 
			// ddbHotkey
			// 
			this->ddbHotkey->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbHotkey->FormattingEnabled = true;
			this->ddbHotkey->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"F1", L"F2", L"F3", L"F4", L"F5", L"F6", L"F7", 
				L"F8", L"F9", L"F10", L"F11", L"F12"});
			this->ddbHotkey->Location = System::Drawing::Point(70, 95);
			this->ddbHotkey->Name = L"ddbHotkey";
			this->ddbHotkey->Size = System::Drawing::Size(55, 21);
			this->ddbHotkey->TabIndex = 1;
			// 
			// sithackTimer
			// 
			this->sithackTimer->Enabled = true;
			this->sithackTimer->Tick += gcnew System::EventHandler(this, &MyForm::sithackTimer_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 98);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Hotkey:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Sit Mode";
			// 
			// ddbSitHack
			// 
			this->ddbSitHack->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbSitHack->FormattingEnabled = true;
			this->ddbSitHack->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Always Sit", L"Hump Sit"});
			this->ddbSitHack->Location = System::Drawing::Point(70, 68);
			this->ddbSitHack->Name = L"ddbSitHack";
			this->ddbSitHack->Size = System::Drawing::Size(55, 21);
			this->ddbSitHack->TabIndex = 9;
			this->ddbSitHack->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ddbSitHack_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Fly Mode";
			// 
			// ddbMouseFly
			// 
			this->ddbMouseFly->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbMouseFly->FormattingEnabled = true;
			this->ddbMouseFly->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Always Fly", L"Click Fly"});
			this->ddbMouseFly->Location = System::Drawing::Point(70, 41);
			this->ddbMouseFly->Name = L"ddbMouseFly";
			this->ddbMouseFly->Size = System::Drawing::Size(55, 21);
			this->ddbMouseFly->TabIndex = 7;
			this->ddbMouseFly->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ddbMouseFly_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(137, 130);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->ddbSitHack);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->ddbMouseFly);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ddbHotkey);
			this->Controls->Add(this->bHack);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->Text = L"CCPLZ\'s Birthday";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Void bHack_Click(System::Object^  sender, System::EventArgs^  e);
		Void sithackTimer_Tick(System::Object^  sender, System::EventArgs^  e);
		Void Toggle();
		Void ddbMouseFly_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		Void ddbSitHack_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
};
}
