#pragma once
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;

extern std::string inputfile; 
extern std::string outputfile; 

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
	private: System::Windows::Forms::Button^  bInput;
	private: System::Windows::Forms::Button^  bOutput;
	private: System::Windows::Forms::OpenFileDialog^  InputFileDialog;
	private: System::Windows::Forms::SaveFileDialog^  OutputFileDialog;

	private: System::ComponentModel::IContainer^  components;
	protected: 

	protected: 

	private:
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
			this->bUpdate = (gcnew System::Windows::Forms::Button());
			this->lvAddys = (gcnew System::Windows::Forms::ListView());
			this->chName = (gcnew System::Windows::Forms::ColumnHeader());
			this->chAddy = (gcnew System::Windows::Forms::ColumnHeader());
			this->bInput = (gcnew System::Windows::Forms::Button());
			this->bOutput = (gcnew System::Windows::Forms::Button());
			this->InputFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->OutputFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
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
			this->lvAddys->Location = System::Drawing::Point(2, 27);
			this->lvAddys->MultiSelect = false;
			this->lvAddys->Name = L"lvAddys";
			this->lvAddys->Size = System::Drawing::Size(234, 240);
			this->lvAddys->TabIndex = 1;
			this->lvAddys->UseCompatibleStateImageBehavior = false;
			this->lvAddys->View = System::Windows::Forms::View::Details;
			// 
			// chName
			// 
			this->chName->Text = L"Name";
			this->chName->Width = 140;
			// 
			// chAddy
			// 
			this->chAddy->Text = L"Address";
			this->chAddy->Width = 73;
			// 
			// bInput
			// 
			this->bInput->Location = System::Drawing::Point(2, 2);
			this->bInput->Name = L"bInput";
			this->bInput->Size = System::Drawing::Size(116, 23);
			this->bInput->TabIndex = 2;
			this->bInput->Text = L"Input File";
			this->bInput->UseVisualStyleBackColor = true;
			this->bInput->Click += gcnew System::EventHandler(this, &MyForm::bInput_Click);
			// 
			// bOutput
			// 
			this->bOutput->Location = System::Drawing::Point(120, 2);
			this->bOutput->Name = L"bOutput";
			this->bOutput->Size = System::Drawing::Size(116, 23);
			this->bOutput->TabIndex = 3;
			this->bOutput->Text = L"Output File";
			this->bOutput->UseVisualStyleBackColor = true;
			this->bOutput->Click += gcnew System::EventHandler(this, &MyForm::bOutput_Click);
			// 
			// InputFileDialog
			// 
			this->InputFileDialog->DefaultExt = L"ini";
			this->InputFileDialog->FileName = L"AOBs";
			this->InputFileDialog->Filter = L"Ini files (*.ini)|*.ini";
			this->InputFileDialog->InitialDirectory = L"WatyBotUpdater";
			this->InputFileDialog->RestoreDirectory = true;
			this->InputFileDialog->Title = L"Open the ini file containing all the AOB\'s";
			// 
			// OutputFileDialog
			// 
			this->OutputFileDialog->DefaultExt = L"h";
			this->OutputFileDialog->FileName = L"Addys";
			this->OutputFileDialog->Filter = L"Header Files (*.h)|*.h";
			this->OutputFileDialog->InitialDirectory = L"WatyBotUpdater";
			this->OutputFileDialog->OverwritePrompt = false;
			this->OutputFileDialog->Title = L"Select the file you want to save the updated addys to";
			// 
			// MyForm
			// 
			this->AcceptButton = this->bUpdate;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(238, 295);
			this->Controls->Add(this->bOutput);
			this->Controls->Add(this->bInput);
			this->Controls->Add(this->lvAddys);
			this->Controls->Add(this->bUpdate);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"WatyBotUpdater Bèta 1.0";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bUpdate_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	private: System::Void bInput_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bOutput_Click(System::Object^  sender, System::EventArgs^  e);
};
}
