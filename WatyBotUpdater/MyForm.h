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
			this->SuspendLayout();
			// 
			// bUpdate
			// 
			this->bUpdate->Location = System::Drawing::Point(0, 0);
			this->bUpdate->Name = L"bUpdate";
			this->bUpdate->Size = System::Drawing::Size(124, 23);
			this->bUpdate->TabIndex = 0;
			this->bUpdate->Text = L"Update";
			this->bUpdate->UseVisualStyleBackColor = true;
			this->bUpdate->Click += gcnew System::EventHandler(this, &MyForm::bUpdate_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(124, 23);
			this->Controls->Add(this->bUpdate);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bUpdate_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	};
}
