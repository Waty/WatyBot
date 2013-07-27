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
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Timer^  sithackTimer;
	private: System::Windows::Forms::Label^  label1;
	private: System::ComponentModel::IContainer^  components;

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
			this->ddbHotkey->Location = System::Drawing::Point(70, 41);
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
			this->label1->Location = System::Drawing::Point(12, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Hotkey:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(137, 71);
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
	};
}
