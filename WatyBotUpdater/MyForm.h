#pragma once
#include <Windows.h>

namespace WatyBotUpdater {

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
	private: System::Windows::Forms::Button^  bUpdate;
	private: System::Windows::Forms::ListView^  lvAddys;
	private: System::Windows::Forms::ColumnHeader^  chName;
	private: System::Windows::Forms::ColumnHeader^  chAddy;
	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bUpdate = (gcnew System::Windows::Forms::Button());
			this->lvAddys = (gcnew System::Windows::Forms::ListView());
			this->chName = (gcnew System::Windows::Forms::ColumnHeader());
			this->chAddy = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// bUpdate
			// 
			this->bUpdate->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->bUpdate->Location = System::Drawing::Point(2, 271);
			this->bUpdate->Name = L"bUpdate";
			this->bUpdate->Size = System::Drawing::Size(234, 23);
			this->bUpdate->TabIndex = 0;
			this->bUpdate->Text = L"Update";
			this->bUpdate->UseVisualStyleBackColor = true;
			this->bUpdate->Click += gcnew System::EventHandler(this, &MyForm::bUpdate_Click);
			// 
			// lvAddys
			// 
			this->lvAddys->AllowColumnReorder = true;
			this->lvAddys->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->chName, this->chAddy});
			this->lvAddys->FullRowSelect = true;
			this->lvAddys->GridLines = true;
			this->lvAddys->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->lvAddys->Location = System::Drawing::Point(2, 2);
			this->lvAddys->MultiSelect = false;
			this->lvAddys->Name = L"lvAddys";
			this->lvAddys->Size = System::Drawing::Size(234, 267);
			this->lvAddys->TabIndex = 1;
			this->lvAddys->UseCompatibleStateImageBehavior = false;
			this->lvAddys->View = System::Windows::Forms::View::Details;
			// 
			// chName
			// 
			this->chName->Text = L"Name";
			this->chName->Width = 111;
			// 
			// chAddy
			// 
			this->chAddy->Text = L"Address";
			this->chAddy->Width = 99;
			// 
			// MyForm
			// 
			this->AcceptButton = this->bUpdate;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(238, 295);
			this->Controls->Add(this->lvAddys);
			this->Controls->Add(this->bUpdate);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"WatyBotUpdater";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bUpdate_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	};
}
