#pragma once
#include <Windows.h>

namespace WatyBotManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: String^ MSLocation;
	public: String^ WatyBotLocation;

	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mapleStoryLocationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  watyBotLocationToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  dlgSelectMS;
	private: System::Windows::Forms::OpenFileDialog^  dlgSelectWatyBot;

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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mapleStoryLocationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->watyBotLocationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dlgSelectMS = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dlgSelectWatyBot = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Location = System::Drawing::Point(3, 22);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1383, 809);
			this->tabControl1->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->settingsToolStripMenuItem, 
				this->menuToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip1->Size = System::Drawing::Size(1387, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->mapleStoryLocationToolStripMenuItem, 
				this->watyBotLocationToolStripMenuItem});
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// mapleStoryLocationToolStripMenuItem
			// 
			this->mapleStoryLocationToolStripMenuItem->Name = L"mapleStoryLocationToolStripMenuItem";
			this->mapleStoryLocationToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->mapleStoryLocationToolStripMenuItem->Text = L"MapleStory Location";
			this->mapleStoryLocationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::mapleStoryLocationToolStripMenuItem_Click);
			// 
			// watyBotLocationToolStripMenuItem
			// 
			this->watyBotLocationToolStripMenuItem->Name = L"watyBotLocationToolStripMenuItem";
			this->watyBotLocationToolStripMenuItem->Size = System::Drawing::Size(183, 22);
			this->watyBotLocationToolStripMenuItem->Text = L"WatyBot Location";
			this->watyBotLocationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::watyBotLocationToolStripMenuItem_Click);
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(88, 20);
			this->menuToolStripMenuItem->Text = L"Start new MS";
			this->menuToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::menuToolStripMenuItem_Click);
			// 
			// dlgSelectMS
			// 
			this->dlgSelectMS->DefaultExt = L"exe";
			this->dlgSelectMS->FileName = L"MapleStory.exe";
			this->dlgSelectMS->Filter = L"MapleStory|MapleStory.exe";
			this->dlgSelectMS->RestoreDirectory = true;
			// 
			// dlgSelectWatyBot
			// 
			this->dlgSelectWatyBot->DefaultExt = L"dll";
			this->dlgSelectWatyBot->FileName = L"WatyBot.dll";
			this->dlgSelectWatyBot->Filter = L"WatyBot|WatyBot.dll";
			this->dlgSelectWatyBot->RestoreDirectory = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1387, 833);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->Text = L"WatyBotManager";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
private: System::Void menuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void mapleStoryLocationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void watyBotLocationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
};
}
