#pragma once
#include "SPControl.h"

namespace WatyBotRevamp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SpawnControl;

	/// <summary>
	/// Summary for EditSPControl
	/// </summary>
	public ref class EditSPControl : public Form
	{
	public:
		EditSPControl(CSPControlLocation^ loc)
		{
			InitializeComponent();

			tbMapName->Text = loc->Name;
			nudMapId->Value = loc->MapId;
			nudXLoc->Value = loc->X;
			nudYLoc->Value = loc->Y;

			location = loc;
		}
		CSPControlLocation^ location;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditSPControl()
		{
			if (components)
			{
				delete components;
			}
		}
		TextBox^  tbMapName;
		NumericUpDown^  nudMapId;
		NumericUpDown^  nudXLoc;
		NumericUpDown^  nudYLoc;
		Button^  bGetCurrentLoc;
		Button^  bSaveChanges;
		Button^  bCancel;
		Windows::Forms::Label^  lName;
		Windows::Forms::Label^  lMapId;
		Windows::Forms::Label^  lYLoc;
		Windows::Forms::Label^  lXLoc;
		
		Void bGetCurrentLoc_Click(System::Object^  sender, System::EventArgs^  e);
		Void bSaveChanges_Click(System::Object^  sender, System::EventArgs^  e);
		Void bCancel_Click(System::Object^  sender, System::EventArgs^  e);

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
			this->nudYLoc = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudXLoc = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudMapId = (gcnew System::Windows::Forms::NumericUpDown());
			this->bGetCurrentLoc = (gcnew System::Windows::Forms::Button());
			this->bSaveChanges = (gcnew System::Windows::Forms::Button());
			this->lMapId = (gcnew System::Windows::Forms::Label());
			this->lName = (gcnew System::Windows::Forms::Label());
			this->lYLoc = (gcnew System::Windows::Forms::Label());
			this->lXLoc = (gcnew System::Windows::Forms::Label());
			this->tbMapName = (gcnew System::Windows::Forms::TextBox());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudYLoc))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudXLoc))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudMapId))->BeginInit();
			this->SuspendLayout();
			// 
			// nudYLoc
			// 
			this->nudYLoc->Location = System::Drawing::Point(264, 21);
			this->nudYLoc->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, 0});
			this->nudYLoc->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, System::Int32::MinValue});
			this->nudYLoc->Name = L"nudYLoc";
			this->nudYLoc->Size = System::Drawing::Size(36, 20);
			this->nudYLoc->TabIndex = 4;
			// 
			// nudXLoc
			// 
			this->nudXLoc->Location = System::Drawing::Point(225, 21);
			this->nudXLoc->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, 0});
			this->nudXLoc->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, System::Int32::MinValue});
			this->nudXLoc->Name = L"nudXLoc";
			this->nudXLoc->Size = System::Drawing::Size(36, 20);
			this->nudXLoc->TabIndex = 3;
			// 
			// nudMapId
			// 
			this->nudMapId->Location = System::Drawing::Point(145, 21);
			this->nudMapId->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1410065408, 2, 0, 0});
			this->nudMapId->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10000, 0, 0, System::Int32::MinValue});
			this->nudMapId->Name = L"nudMapId";
			this->nudMapId->Size = System::Drawing::Size(77, 20);
			this->nudMapId->TabIndex = 2;
			// 
			// bGetCurrentLoc
			// 
			this->bGetCurrentLoc->Location = System::Drawing::Point(164, 47);
			this->bGetCurrentLoc->Name = L"bGetCurrentLoc";
			this->bGetCurrentLoc->Size = System::Drawing::Size(137, 23);
			this->bGetCurrentLoc->TabIndex = 7;
			this->bGetCurrentLoc->Text = L"Get Current";
			this->bGetCurrentLoc->UseVisualStyleBackColor = true;
			this->bGetCurrentLoc->Click += gcnew System::EventHandler(this, &EditSPControl::bGetCurrentLoc_Click);
			// 
			// bSaveChanges
			// 
			this->bSaveChanges->Location = System::Drawing::Point(3, 47);
			this->bSaveChanges->Name = L"bSaveChanges";
			this->bSaveChanges->Size = System::Drawing::Size(76, 23);
			this->bSaveChanges->TabIndex = 5;
			this->bSaveChanges->Text = L"Save Changes";
			this->bSaveChanges->UseVisualStyleBackColor = true;
			this->bSaveChanges->Click += gcnew System::EventHandler(this, &EditSPControl::bSaveChanges_Click);
			// 
			// lMapId
			// 
			this->lMapId->Location = System::Drawing::Point(144, 4);
			this->lMapId->Name = L"lMapId";
			this->lMapId->Size = System::Drawing::Size(60, 14);
			this->lMapId->TabIndex = 6;
			this->lMapId->Text = L"MapID";
			this->lMapId->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lName
			// 
			this->lName->Location = System::Drawing::Point(1, 4);
			this->lName->Name = L"lName";
			this->lName->Size = System::Drawing::Size(137, 14);
			this->lName->TabIndex = 7;
			this->lName->Text = L"Name:";
			this->lName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lYLoc
			// 
			this->lYLoc->Location = System::Drawing::Point(266, 4);
			this->lYLoc->Name = L"lYLoc";
			this->lYLoc->Size = System::Drawing::Size(17, 14);
			this->lYLoc->TabIndex = 8;
			this->lYLoc->Text = L"Y";
			this->lYLoc->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lXLoc
			// 
			this->lXLoc->Location = System::Drawing::Point(230, 4);
			this->lXLoc->Name = L"lXLoc";
			this->lXLoc->Size = System::Drawing::Size(14, 14);
			this->lXLoc->TabIndex = 9;
			this->lXLoc->Text = L"X";
			this->lXLoc->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tbMapName
			// 
			this->tbMapName->Location = System::Drawing::Point(4, 21);
			this->tbMapName->Name = L"tbMapName";
			this->tbMapName->Size = System::Drawing::Size(134, 20);
			this->tbMapName->TabIndex = 1;
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(85, 47);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(76, 23);
			this->bCancel->TabIndex = 6;
			this->bCancel->Text = L"Cancel";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &EditSPControl::bCancel_Click);
			// 
			// EditSPControl
			// 
			this->AcceptButton = this->bSaveChanges;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(305, 74);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->nudYLoc);
			this->Controls->Add(this->nudXLoc);
			this->Controls->Add(this->nudMapId);
			this->Controls->Add(this->bGetCurrentLoc);
			this->Controls->Add(this->bSaveChanges);
			this->Controls->Add(this->lMapId);
			this->Controls->Add(this->lName);
			this->Controls->Add(this->lYLoc);
			this->Controls->Add(this->lXLoc);
			this->Controls->Add(this->tbMapName);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"EditSPControl";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Edit SPControl Location";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudYLoc))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudXLoc))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudMapId))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
};
}
