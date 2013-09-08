#pragma once
#include "PacketSender.h"
extern Void ShowErrorDialog(System::String^ Message);

namespace WatyBotRevamp {

	using namespace System;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PacketDialog
	/// </summary>
	public ref class PacketDialog : public Form
	{
	public:
		PacketDialog()
		{
			InitializeComponent();
			Packet = gcnew WatyBotRevamp::Packet();
		}
		PacketDialog(Packet^ pd)
		{
			InitializeComponent();

			this->Text = "Edit Packet Dialog";
			this->bSave->Text = "Save Changes";

			this->tbName->Text = pd->Name;
			this->tbData->Lines = pd->Data->ToArray();
			this->nudInterval->Value = pd->Interval;

			this->Packet = pd;
		}

		Packet^ Packet;

	protected:
		/// <summar>
		/// Clean up any resources being used.
		/// </summary>
		~PacketDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		Label^  lName;
		TextBox^  tbName;
		Windows::Forms::Label^  lData;
		TextBox^  tbData;
		Windows::Forms::Label^  lInterval;
		NumericUpDown^  nudInterval;

		Button^  bSave;
		Button^  bCancel;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bSave = (gcnew System::Windows::Forms::Button());
			this->tbData = (gcnew System::Windows::Forms::TextBox());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->lName = (gcnew System::Windows::Forms::Label());
			this->lData = (gcnew System::Windows::Forms::Label());
			this->lInterval = (gcnew System::Windows::Forms::Label());
			this->nudInterval = (gcnew System::Windows::Forms::NumericUpDown());
			this->bCancel = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudInterval))->BeginInit();
			this->SuspendLayout();
			// 
			// bSave
			// 
			this->bSave->Location = System::Drawing::Point(12, 91);
			this->bSave->Name = L"bSave";
			this->bSave->Size = System::Drawing::Size(115, 23);
			this->bSave->TabIndex = 8;
			this->bSave->Text = L"Add Packet";
			this->bSave->UseVisualStyleBackColor = true;
			this->bSave->Click += gcnew System::EventHandler(this, &PacketDialog::bSave_Click);
			// 
			// tbData
			// 
			this->tbData->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->tbData->Location = System::Drawing::Point(133, 25);
			this->tbData->Multiline = true;
			this->tbData->Name = L"tbData";
			this->tbData->Size = System::Drawing::Size(192, 60);
			this->tbData->TabIndex = 7;
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(12, 25);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(115, 20);
			this->tbName->TabIndex = 6;
			// 
			// lName
			// 
			this->lName->AutoSize = true;
			this->lName->Location = System::Drawing::Point(12, 9);
			this->lName->Name = L"lName";
			this->lName->Size = System::Drawing::Size(38, 13);
			this->lName->TabIndex = 9;
			this->lName->Text = L"Name:";
			// 
			// lData
			// 
			this->lData->AutoSize = true;
			this->lData->Location = System::Drawing::Point(130, 9);
			this->lData->Name = L"lData";
			this->lData->Size = System::Drawing::Size(33, 13);
			this->lData->TabIndex = 10;
			this->lData->Text = L"Data:";
			// 
			// lInterval
			// 
			this->lInterval->AutoSize = true;
			this->lInterval->Location = System::Drawing::Point(12, 48);
			this->lInterval->Name = L"lInterval";
			this->lInterval->Size = System::Drawing::Size(82, 13);
			this->lInterval->TabIndex = 11;
			this->lInterval->Text = L"Interval per line:";
			// 
			// nudInterval
			// 
			this->nudInterval->Location = System::Drawing::Point(13, 65);
			this->nudInterval->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 276447232, 23283, 0, 0 });
			this->nudInterval->Name = L"nudInterval";
			this->nudInterval->Size = System::Drawing::Size(114, 20);
			this->nudInterval->TabIndex = 12;
			// 
			// bCancel
			// 
			this->bCancel->Location = System::Drawing::Point(133, 91);
			this->bCancel->Name = L"bCancel";
			this->bCancel->Size = System::Drawing::Size(192, 23);
			this->bCancel->TabIndex = 13;
			this->bCancel->Text = L"Cancel";
			this->bCancel->UseVisualStyleBackColor = true;
			this->bCancel->Click += gcnew System::EventHandler(this, &PacketDialog::bCancel_Click);
			// 
			// PacketDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(337, 126);
			this->Controls->Add(this->bCancel);
			this->Controls->Add(this->nudInterval);
			this->Controls->Add(this->lInterval);
			this->Controls->Add(this->lData);
			this->Controls->Add(this->lName);
			this->Controls->Add(this->bSave);
			this->Controls->Add(this->tbData);
			this->Controls->Add(this->tbName);
			this->Name = L"PacketDialog";
			this->Text = L"New Packet Dialog";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudInterval))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
		Void bSave_Click(System::Object^  sender, System::EventArgs^  e)
		{
			Packet->Name = tbName->Text;
			auto data = gcnew List<String^>;
			data->AddRange(this->tbData->Lines);
			Packet->Data = data;
			Packet->Interval = (int) nudInterval->Value;

			String^ strError = String::Empty;
			if (!Packet->IsValidPacket(strError))
			{
				ShowErrorDialog(strError);
				return;
			}
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			Close();
		}

		Void bCancel_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			Close();
		}
	};
}
