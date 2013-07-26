#pragma once
#include <Windows.h>
#include "Address.h"

#define appdatadir  Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData) + "\\Waty\\Updater\\"
#define aobfile (appdatadir + "AOBs.xml")
#define outputfile (appdatadir + "Addys.h")

#define ShowInfo(Message)		MessageBox::Show(Message, "Information", MessageBoxButtons::OK, MessageBoxIcon::Information)
#define ShowError(Message)		MessageBox::Show(Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error)

namespace WatyBotUpdater
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			ReadXmlData();
			AOBFileWatcher->Path = appdatadir;
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

		ListView^  lvAddys;
		ColumnHeader^  chName;
		ColumnHeader^  chAddy;
		ColumnHeader^  chType;
		ColumnHeader^  chAOB;
		ColumnHeader^  chComments;

		OpenFileDialog^  InputFileDialog;
		XmlSerializer^ serializer;
		List<Address^>^ addressList;
		System::IO::FileSystemWatcher^  AOBFileWatcher;
		MenuStrip^  menuStrip1;
		ToolStripMenuItem^  updateToolStripMenuItem;
		ToolStripMenuItem^  loadDifferentFileItem;
		ToolStripMenuItem^  saveAOBItem;

		GroupBox^  gbNewAOB;
		TextBox^  tbName;
		ComboBox^  ddbType;
		TextBox^  tbAOB;
		TextBox^  tbComment;
		Button^  bAdd;
		Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
		Windows::Forms::ToolStripMenuItem^  copySearchResultToolStripMenuItem;
		Windows::Forms::ToolStripMenuItem^  copyAOBToolStripMenuItem;
		Windows::Forms::ToolStripMenuItem^  copyCommentToolStripMenuItem;
		Windows::Forms::ToolStripMenuItem^  deleteEntryToolStripMenuItem;
		Windows::Forms::ToolStripMenuItem^  openFileLocationToolStripMenuItem;

		IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lvAddys = (gcnew System::Windows::Forms::ListView());
			this->chName = (gcnew System::Windows::Forms::ColumnHeader());
			this->chAddy = (gcnew System::Windows::Forms::ColumnHeader());
			this->chType = (gcnew System::Windows::Forms::ColumnHeader());
			this->chAOB = (gcnew System::Windows::Forms::ColumnHeader());
			this->chComments = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->copySearchResultToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyAOBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyCommentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteEntryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileLocationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->InputFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->AOBFileWatcher = (gcnew System::IO::FileSystemWatcher());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->updateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadDifferentFileItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAOBItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->ddbType = (gcnew System::Windows::Forms::ComboBox());
			this->gbNewAOB = (gcnew System::Windows::Forms::GroupBox());
			this->bAdd = (gcnew System::Windows::Forms::Button());
			this->tbComment = (gcnew System::Windows::Forms::TextBox());
			this->tbAOB = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->AOBFileWatcher))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->gbNewAOB->SuspendLayout();
			this->SuspendLayout();
			// 
			// lvAddys
			// 
			this->lvAddys->AllowColumnReorder = true;
			this->lvAddys->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {this->chName, this->chAddy, 
				this->chType, this->chAOB, this->chComments});
			this->lvAddys->ContextMenuStrip = this->contextMenuStrip1;
			this->lvAddys->FullRowSelect = true;
			this->lvAddys->GridLines = true;
			this->lvAddys->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->lvAddys->Location = System::Drawing::Point(12, 27);
			this->lvAddys->MultiSelect = false;
			this->lvAddys->Name = L"lvAddys";
			this->lvAddys->Size = System::Drawing::Size(920, 509);
			this->lvAddys->TabIndex = 1;
			this->lvAddys->UseCompatibleStateImageBehavior = false;
			this->lvAddys->View = System::Windows::Forms::View::Details;
			// 
			// chName
			// 
			this->chName->Text = L"Name";
			this->chName->Width = 125;
			// 
			// chAddy
			// 
			this->chAddy->Text = L"Address";
			this->chAddy->Width = 70;
			// 
			// chType
			// 
			this->chType->Text = L"Type";
			this->chType->Width = 70;
			// 
			// chAOB
			// 
			this->chAOB->Text = L"AOB";
			this->chAOB->Width = 500;
			// 
			// chComments
			// 
			this->chComments->Text = L"Comment";
			this->chComments->Width = 500;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->copySearchResultToolStripMenuItem, 
				this->copyAOBToolStripMenuItem, this->copyCommentToolStripMenuItem, this->deleteEntryToolStripMenuItem, this->openFileLocationToolStripMenuItem});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(172, 114);
			// 
			// copySearchResultToolStripMenuItem
			// 
			this->copySearchResultToolStripMenuItem->Name = L"copySearchResultToolStripMenuItem";
			this->copySearchResultToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->copySearchResultToolStripMenuItem->Text = L"Copy search result";
			this->copySearchResultToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::copySearchResultToolStripMenuItem_Click);
			// 
			// copyAOBToolStripMenuItem
			// 
			this->copyAOBToolStripMenuItem->Name = L"copyAOBToolStripMenuItem";
			this->copyAOBToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->copyAOBToolStripMenuItem->Text = L"Copy AOB";
			this->copyAOBToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::copyAOBToolStripMenuItem_Click);
			// 
			// copyCommentToolStripMenuItem
			// 
			this->copyCommentToolStripMenuItem->Name = L"copyCommentToolStripMenuItem";
			this->copyCommentToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->copyCommentToolStripMenuItem->Text = L"Copy Comment";
			this->copyCommentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::copyCommentToolStripMenuItem_Click);
			// 
			// deleteEntryToolStripMenuItem
			// 
			this->deleteEntryToolStripMenuItem->Name = L"deleteEntryToolStripMenuItem";
			this->deleteEntryToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->deleteEntryToolStripMenuItem->Text = L"Delete entry";
			this->deleteEntryToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deleteEntryToolStripMenuItem_Click);
			// 
			// openFileLocationToolStripMenuItem
			// 
			this->openFileLocationToolStripMenuItem->Name = L"openFileLocationToolStripMenuItem";
			this->openFileLocationToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->openFileLocationToolStripMenuItem->Text = L"Open file location";
			this->openFileLocationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openFileLocationToolStripMenuItem_Click);
			// 
			// InputFileDialog
			// 
			this->InputFileDialog->DefaultExt = L"xml";
			this->InputFileDialog->FileName = L"AOBs";
			this->InputFileDialog->Filter = L"Xml files (*.xml)|*.xml";
			this->InputFileDialog->InitialDirectory = L"WatyBotUpdater";
			this->InputFileDialog->RestoreDirectory = true;
			this->InputFileDialog->Title = L"Open the xml file containing all the AOB\'s";
			// 
			// AOBFileWatcher
			// 
			this->AOBFileWatcher->EnableRaisingEvents = true;
			this->AOBFileWatcher->Filter = L"*.xml";
			this->AOBFileWatcher->SynchronizingObject = this;
			this->AOBFileWatcher->Changed += gcnew System::IO::FileSystemEventHandler(this, &MyForm::AOBFileWatcher_Changed);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->updateToolStripMenuItem, 
				this->loadDifferentFileItem, this->saveAOBItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menuStrip1->Size = System::Drawing::Size(944, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// updateToolStripMenuItem
			// 
			this->updateToolStripMenuItem->Name = L"updateToolStripMenuItem";
			this->updateToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->updateToolStripMenuItem->Text = L"Update";
			this->updateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::update_Click);
			// 
			// loadDifferentFileItem
			// 
			this->loadDifferentFileItem->Name = L"loadDifferentFileItem";
			this->loadDifferentFileItem->Size = System::Drawing::Size(144, 20);
			this->loadDifferentFileItem->Text = L"Load a different aob file";
			this->loadDifferentFileItem->Click += gcnew System::EventHandler(this, &MyForm::loadDifferentFile_Click);
			// 
			// saveAOBItem
			// 
			this->saveAOBItem->Name = L"saveAOBItem";
			this->saveAOBItem->Size = System::Drawing::Size(97, 20);
			this->saveAOBItem->Text = L"Save AOBs.xml";
			this->saveAOBItem->Click += gcnew System::EventHandler(this, &MyForm::saveAOBItem_Click);
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(6, 19);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(116, 20);
			this->tbName->TabIndex = 3;
			// 
			// ddbType
			// 
			this->ddbType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbType->FormattingEnabled = true;
			this->ddbType->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Address", L"Pointer", L"Offset"});
			this->ddbType->Location = System::Drawing::Point(129, 19);
			this->ddbType->Name = L"ddbType";
			this->ddbType->Size = System::Drawing::Size(103, 21);
			this->ddbType->TabIndex = 4;
			// 
			// gbNewAOB
			// 
			this->gbNewAOB->Controls->Add(this->bAdd);
			this->gbNewAOB->Controls->Add(this->tbComment);
			this->gbNewAOB->Controls->Add(this->tbAOB);
			this->gbNewAOB->Controls->Add(this->tbName);
			this->gbNewAOB->Controls->Add(this->ddbType);
			this->gbNewAOB->Location = System::Drawing::Point(12, 542);
			this->gbNewAOB->Name = L"gbNewAOB";
			this->gbNewAOB->Size = System::Drawing::Size(920, 47);
			this->gbNewAOB->TabIndex = 5;
			this->gbNewAOB->TabStop = false;
			// 
			// bAdd
			// 
			this->bAdd->Location = System::Drawing::Point(796, 19);
			this->bAdd->Name = L"bAdd";
			this->bAdd->Size = System::Drawing::Size(118, 20);
			this->bAdd->TabIndex = 12;
			this->bAdd->Text = L"Add!";
			this->bAdd->UseVisualStyleBackColor = true;
			this->bAdd->Click += gcnew System::EventHandler(this, &MyForm::bAdd_Click);
			// 
			// tbComment
			// 
			this->tbComment->Location = System::Drawing::Point(589, 19);
			this->tbComment->Name = L"tbComment";
			this->tbComment->Size = System::Drawing::Size(201, 20);
			this->tbComment->TabIndex = 10;
			// 
			// tbAOB
			// 
			this->tbAOB->Location = System::Drawing::Point(238, 19);
			this->tbAOB->Name = L"tbAOB";
			this->tbAOB->Size = System::Drawing::Size(345, 20);
			this->tbAOB->TabIndex = 8;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(944, 601);
			this->Controls->Add(this->gbNewAOB);
			this->Controls->Add(this->lvAddys);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"WatyUpdater Bèta 2.0";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->SizeChanged += gcnew System::EventHandler(this, &MyForm::MyForm_SizeChanged);
			this->contextMenuStrip1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->AOBFileWatcher))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->gbNewAOB->ResumeLayout(false);
			this->gbNewAOB->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Void ReadXmlData();
		Void WriteXmlData();
		Void AOBFileWatcher_Changed(System::Object^  sender, System::IO::FileSystemEventArgs^  e);
		
		Void update_Click(System::Object^  sender, System::EventArgs^  e);
		Void loadDifferentFile_Click(System::Object^  sender, System::EventArgs^  e);
		Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
		Void MyForm_SizeChanged(System::Object^  sender, System::EventArgs^  e);
		Void saveAOBItem_Click(System::Object^  sender, System::EventArgs^  e);
		Void bAdd_Click(System::Object^  sender, System::EventArgs^  e);
		
		Void copySearchResultToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		Void copyAOBToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		Void copyCommentToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		Void deleteEntryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		Void openFileLocationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
