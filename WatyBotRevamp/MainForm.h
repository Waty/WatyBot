#pragma region ...
#pragma once
#include <Windows.h>

namespace WatyBotRevamp {

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
	private: System::Windows::Forms::TabControl^  MainTabControl;
	protected: 

	protected: 
	private: System::Windows::Forms::TabPage^  AutoBotTab;
	private: System::Windows::Forms::TabPage^  HacksTab;




	private: System::Windows::Forms::Timer^  StatsTimer;

	private: System::Windows::Forms::Label^  HPLabel;

	private: System::Windows::Forms::Label^  MPLabel;
	private: System::Windows::Forms::Label^  EXPLabel;
	private: System::Windows::Forms::PictureBox^  HPBackground;


	private: System::Windows::Forms::PictureBox^  MPBackground;
	private: System::Windows::Forms::PictureBox^  EXPForeground;
	private: System::Windows::Forms::PictureBox^  MPForeground;
	private: System::Windows::Forms::PictureBox^  HPForeground;
	private: System::Windows::Forms::PictureBox^  EXPBackground;















	private: System::Windows::Forms::CheckBox^  HPCheckBox;

	private: System::Windows::Forms::ComboBox^  HPComboBox;
	private: System::Windows::Forms::TextBox^  HPTextBox;


	private: System::Windows::Forms::ComboBox^  MPComboBox;
	private: System::Windows::Forms::TextBox^  MPTextBox;
	private: System::Windows::Forms::CheckBox^  MPCheckBox;
	private: System::Windows::Forms::ComboBox^  AttackComboBox;

	private: System::Windows::Forms::CheckBox^  AttackCheckBox;

	private: System::Windows::Forms::TrackBar^  AttackTrackBar;

	private: System::Windows::Forms::Label^  AttackDelayLabel;

	private: System::Windows::Forms::TabPage^  InfoTab;
	private: System::Windows::Forms::Label^  AttackCountLabel;
	private: System::Windows::Forms::Label^  ItemCountLabel;
	private: System::Windows::Forms::Label^  CharPosLabel;
	private: System::Windows::Forms::Label^  PeopleCountLabel;
	private: System::Windows::Forms::Label^  MobCountLabel;
	private: System::Windows::Forms::GroupBox^  PointerReadGroupBox;

	private: System::Windows::Forms::CheckBox^  AutoLootCheckBox;
	private: System::Windows::Forms::ComboBox^  AutoLootComboBox;
	private: System::Windows::Forms::Button^  FixStatsButton;
	private: System::Windows::Forms::CheckBox^  AutoSkill1CheckBox;

	private: System::Windows::Forms::TextBox^  AutoSkill1TextBox;
	private: System::Windows::Forms::ComboBox^  AutoSkill1ComboBox;
	private: System::Windows::Forms::GroupBox^  AutoBotGroupBox;

private: System::Windows::Forms::CheckBox^  AutoSkill4CheckBox;
private: System::Windows::Forms::TextBox^  AutoSkill4TextBox;
private: System::Windows::Forms::ComboBox^  AutoSkill4ComboBox;

private: System::Windows::Forms::CheckBox^  AutoSkill3CheckBox;
private: System::Windows::Forms::TextBox^  AutoSkill3TextBox;
private: System::Windows::Forms::ComboBox^  AutoSkill3ComboBox;
private: System::Windows::Forms::CheckBox^  AutoSkill2CheckBox;
private: System::Windows::Forms::TextBox^  AutoSkill2TextBox;
private: System::Windows::Forms::ComboBox^  AutoSkill2ComboBox;
private: System::Windows::Forms::Label^  TubiPointerLabel;
private: System::Windows::Forms::CheckBox^  PointerTubiCheckBox;



private: System::Windows::Forms::Label^  BreathLabel;
private: System::Windows::Forms::CheckBox^  CCPeopleCheckBox;

private: System::Windows::Forms::TextBox^  CCPeopleTextBox;












private: System::Windows::Forms::TabPage^  PacketSenderTab;
private: System::Windows::Forms::Button^  SendPacketButton;

private: System::Windows::Forms::ComboBox^  PacketSelectBox;
private: System::Windows::Forms::GroupBox^  AddPacketsGroupBox;
private: System::Windows::Forms::GroupBox^  SendPacketGroupBox;
private: System::Windows::Forms::Button^  AddPacketButton;
private: System::Windows::Forms::TextBox^  AddPacketPacketTextBox;
private: System::Windows::Forms::TextBox^  AddPacketNameTextBox;
private: System::Windows::Forms::Label^  AddPacketPacketLabel;
private: System::Windows::Forms::Label^  AddPacketNameLabel;
private: System::Windows::Forms::Label^  SpamPacketTimesLabel;
private: System::Windows::Forms::TextBox^  SpamPacketTimesTextBox;
private: System::Windows::Forms::Label^  SpamPacketsDelayLabel;

		 
private: System::Windows::Forms::TextBox^  SpamPacketsDelayTextBox;

private: System::Windows::Forms::Button^  SpamsPacketButton;


private: System::Windows::Forms::GroupBox^  DeletePacketsGroupBox;
private: System::Windows::Forms::ComboBox^  DeletePacketComboBox;
private: System::Windows::Forms::Button^  DeletePacketButton;


private: System::Windows::Forms::GroupBox^  EditPacketGroupBox;
private: System::Windows::Forms::Button^  SavePacketEditButton;
private: System::Windows::Forms::TextBox^  EditPacketPacketTextBox;
private: System::Windows::Forms::TextBox^  EditPacketNameTextBox;
private: System::Windows::Forms::ComboBox^  SelectPacketForEditingComboBox;

private: System::Windows::Forms::Timer^  SpamPacketsTimer;
private: System::Windows::Forms::TabPage^  SPControlTabPage;
private: System::Windows::Forms::CheckBox^  SPControlCheckBox;
private: System::Windows::Forms::TextBox^  CCAttacksTextBox;
		 
private: System::Windows::Forms::CheckBox^  CCAttacksCheckBox;
		 
private: System::Windows::Forms::TextBox^  CCTimedTextBox;
		 
private: System::Windows::Forms::CheckBox^  CCTimedCheckBox;
private: System::Windows::Forms::Label^  CCTimedLabel;
		 
private: System::Windows::Forms::Label^  CCPeopleLabel;
private: System::Windows::Forms::Label^  CCAttacksLabel;
private: System::Windows::Forms::Button^  SavePacketsButton;
private: System::Windows::Forms::ListView^  SPControlListView;
		 
private: System::Windows::Forms::ColumnHeader^  HeaderMapName;
private: System::Windows::Forms::ColumnHeader^  HeaderMapID;
private: System::Windows::Forms::ColumnHeader^  HeaderX;
private: System::Windows::Forms::ColumnHeader^  HeaderY;
private: System::Windows::Forms::Label^  SPControlNameLabel;
private: System::Windows::Forms::Label^  SPControlMapIDLabel;
private: System::Windows::Forms::Label^  SPControlXLabel;
private: System::Windows::Forms::Label^  SPControlYLabel;
private: System::Windows::Forms::GroupBox^  SPControlGroupBox;
private: System::Windows::Forms::TextBox^  SPControlYTextBox;
private: System::Windows::Forms::TextBox^  SPControlXTextBox;
private: System::Windows::Forms::TextBox^  SPControlMapIDTextBox;
private: System::Windows::Forms::TextBox^  SPControlNameTextBox;
private: System::Windows::Forms::Button^  SPControlAddButton;
private: System::Windows::Forms::ContextMenuStrip^  SPControlContextMenu;
private: System::Windows::Forms::ToolStripMenuItem^  deletePacketToolStripMenuItem;
private: System::Windows::Forms::Button^  GetSPControlCoordsButton;
private: System::Windows::Forms::GroupBox^  MobHacks;
private: System::Windows::Forms::CheckBox^  cbPerfectLoot;
private: System::Windows::Forms::CheckBox^  cbFusionAttack;
private: System::Windows::Forms::GroupBox^  gbMiscHacks;
private: System::Windows::Forms::CheckBox^  cbJDA;
private: System::Windows::Forms::CheckBox^  cbNoBG;
private: System::Windows::Forms::GroupBox^  gbCharHacks;
private: System::Windows::Forms::CheckBox^  cbInstantAirLoot;
private: System::Windows::Forms::CheckBox^  cbVacRight;

private: System::Windows::Forms::CheckBox^  cbJumpRight;
private: System::Windows::Forms::CheckBox^  cbWalkRight;
private: System::Windows::Forms::CheckBox^  cbPinTyper;
private: System::Windows::Forms::CheckBox^  cbNoKB;
private: System::Windows::Forms::CheckBox^  cbMobDisarm;
private: System::Windows::Forms::CheckBox^  cbDojangGodmode;
private: System::Windows::Forms::CheckBox^  cbUnlimitedMorph;
private: System::Windows::Forms::CheckBox^  cbFasterMobs;
private: System::Windows::Forms::CheckBox^  cbNDAllAttacks;
private: System::Windows::Forms::CheckBox^  cbNoMobs;
private: System::Windows::Forms::CheckBox^  cbAutoAggro;


	private: System::ComponentModel::IContainer^  components;


	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
#pragma endregion

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->MainTabControl = (gcnew System::Windows::Forms::TabControl());
			this->AutoBotTab = (gcnew System::Windows::Forms::TabPage());
			this->AutoBotGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->CCAttacksLabel = (gcnew System::Windows::Forms::Label());
			this->CCTimedLabel = (gcnew System::Windows::Forms::Label());
			this->CCPeopleLabel = (gcnew System::Windows::Forms::Label());
			this->FixStatsButton = (gcnew System::Windows::Forms::Button());
			this->CCAttacksTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CCAttacksCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CCTimedTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CCTimedCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AutoSkill4ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->CCPeopleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PointerTubiCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AutoSkill4CheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CCPeopleCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AutoSkill4TextBox = (gcnew System::Windows::Forms::TextBox());
			this->AutoSkill3CheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AutoSkill3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->AutoSkill3ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->AutoSkill2CheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AutoSkill2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->AutoSkill2ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->AttackCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AutoSkill1CheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->HPCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AutoSkill1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->HPTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AutoSkill1ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->HPComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->MPCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AutoLootComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->MPTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AutoLootCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->MPComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->AttackDelayLabel = (gcnew System::Windows::Forms::Label());
			this->AttackComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->AttackTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->EXPLabel = (gcnew System::Windows::Forms::Label());
			this->MPLabel = (gcnew System::Windows::Forms::Label());
			this->HPLabel = (gcnew System::Windows::Forms::Label());
			this->EXPForeground = (gcnew System::Windows::Forms::PictureBox());
			this->MPForeground = (gcnew System::Windows::Forms::PictureBox());
			this->HPForeground = (gcnew System::Windows::Forms::PictureBox());
			this->EXPBackground = (gcnew System::Windows::Forms::PictureBox());
			this->MPBackground = (gcnew System::Windows::Forms::PictureBox());
			this->HPBackground = (gcnew System::Windows::Forms::PictureBox());
			this->HacksTab = (gcnew System::Windows::Forms::TabPage());
			this->gbMiscHacks = (gcnew System::Windows::Forms::GroupBox());
			this->cbPinTyper = (gcnew System::Windows::Forms::CheckBox());
			this->cbJDA = (gcnew System::Windows::Forms::CheckBox());
			this->cbNoBG = (gcnew System::Windows::Forms::CheckBox());
			this->gbCharHacks = (gcnew System::Windows::Forms::GroupBox());
			this->cbNDAllAttacks = (gcnew System::Windows::Forms::CheckBox());
			this->cbUnlimitedMorph = (gcnew System::Windows::Forms::CheckBox());
			this->cbDojangGodmode = (gcnew System::Windows::Forms::CheckBox());
			this->cbNoKB = (gcnew System::Windows::Forms::CheckBox());
			this->cbInstantAirLoot = (gcnew System::Windows::Forms::CheckBox());
			this->cbFusionAttack = (gcnew System::Windows::Forms::CheckBox());
			this->cbPerfectLoot = (gcnew System::Windows::Forms::CheckBox());
			this->MobHacks = (gcnew System::Windows::Forms::GroupBox());
			this->cbNoMobs = (gcnew System::Windows::Forms::CheckBox());
			this->cbFasterMobs = (gcnew System::Windows::Forms::CheckBox());
			this->cbMobDisarm = (gcnew System::Windows::Forms::CheckBox());
			this->cbJumpRight = (gcnew System::Windows::Forms::CheckBox());
			this->cbWalkRight = (gcnew System::Windows::Forms::CheckBox());
			this->cbVacRight = (gcnew System::Windows::Forms::CheckBox());
			this->PacketSenderTab = (gcnew System::Windows::Forms::TabPage());
			this->SavePacketsButton = (gcnew System::Windows::Forms::Button());
			this->EditPacketGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->SavePacketEditButton = (gcnew System::Windows::Forms::Button());
			this->EditPacketPacketTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EditPacketNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SelectPacketForEditingComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DeletePacketsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->DeletePacketComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->DeletePacketButton = (gcnew System::Windows::Forms::Button());
			this->AddPacketsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->AddPacketButton = (gcnew System::Windows::Forms::Button());
			this->AddPacketPacketTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AddPacketNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AddPacketPacketLabel = (gcnew System::Windows::Forms::Label());
			this->AddPacketNameLabel = (gcnew System::Windows::Forms::Label());
			this->SendPacketGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->SpamsPacketButton = (gcnew System::Windows::Forms::Button());
			this->SpamPacketsDelayLabel = (gcnew System::Windows::Forms::Label());
			this->SpamPacketsDelayTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SpamPacketTimesLabel = (gcnew System::Windows::Forms::Label());
			this->SpamPacketTimesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PacketSelectBox = (gcnew System::Windows::Forms::ComboBox());
			this->SendPacketButton = (gcnew System::Windows::Forms::Button());
			this->SPControlTabPage = (gcnew System::Windows::Forms::TabPage());
			this->SPControlGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->GetSPControlCoordsButton = (gcnew System::Windows::Forms::Button());
			this->SPControlAddButton = (gcnew System::Windows::Forms::Button());
			this->SPControlMapIDLabel = (gcnew System::Windows::Forms::Label());
			this->SPControlCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->SPControlYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SPControlNameLabel = (gcnew System::Windows::Forms::Label());
			this->SPControlXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SPControlYLabel = (gcnew System::Windows::Forms::Label());
			this->SPControlMapIDTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SPControlXLabel = (gcnew System::Windows::Forms::Label());
			this->SPControlNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SPControlListView = (gcnew System::Windows::Forms::ListView());
			this->HeaderMapName = (gcnew System::Windows::Forms::ColumnHeader());
			this->HeaderMapID = (gcnew System::Windows::Forms::ColumnHeader());
			this->HeaderX = (gcnew System::Windows::Forms::ColumnHeader());
			this->HeaderY = (gcnew System::Windows::Forms::ColumnHeader());
			this->SPControlContextMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->deletePacketToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->InfoTab = (gcnew System::Windows::Forms::TabPage());
			this->PointerReadGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->BreathLabel = (gcnew System::Windows::Forms::Label());
			this->TubiPointerLabel = (gcnew System::Windows::Forms::Label());
			this->MobCountLabel = (gcnew System::Windows::Forms::Label());
			this->AttackCountLabel = (gcnew System::Windows::Forms::Label());
			this->PeopleCountLabel = (gcnew System::Windows::Forms::Label());
			this->ItemCountLabel = (gcnew System::Windows::Forms::Label());
			this->CharPosLabel = (gcnew System::Windows::Forms::Label());
			this->StatsTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SpamPacketsTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->cbAutoAggro = (gcnew System::Windows::Forms::CheckBox());
			this->MainTabControl->SuspendLayout();
			this->AutoBotTab->SuspendLayout();
			this->AutoBotGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->AttackTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EXPForeground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MPForeground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HPForeground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EXPBackground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MPBackground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HPBackground))->BeginInit();
			this->HacksTab->SuspendLayout();
			this->gbMiscHacks->SuspendLayout();
			this->gbCharHacks->SuspendLayout();
			this->MobHacks->SuspendLayout();
			this->PacketSenderTab->SuspendLayout();
			this->EditPacketGroupBox->SuspendLayout();
			this->DeletePacketsGroupBox->SuspendLayout();
			this->AddPacketsGroupBox->SuspendLayout();
			this->SendPacketGroupBox->SuspendLayout();
			this->SPControlTabPage->SuspendLayout();
			this->SPControlGroupBox->SuspendLayout();
			this->SPControlContextMenu->SuspendLayout();
			this->InfoTab->SuspendLayout();
			this->PointerReadGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// MainTabControl
			// 
			this->MainTabControl->Controls->Add(this->AutoBotTab);
			this->MainTabControl->Controls->Add(this->HacksTab);
			this->MainTabControl->Controls->Add(this->PacketSenderTab);
			this->MainTabControl->Controls->Add(this->SPControlTabPage);
			this->MainTabControl->Controls->Add(this->InfoTab);
			this->MainTabControl->Location = System::Drawing::Point(1, 1);
			this->MainTabControl->Name = L"MainTabControl";
			this->MainTabControl->SelectedIndex = 0;
			this->MainTabControl->Size = System::Drawing::Size(334, 422);
			this->MainTabControl->TabIndex = 0;
			this->MainTabControl->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::MainTabControl_SelectedIndexChanged);
			// 
			// AutoBotTab
			// 
			this->AutoBotTab->Controls->Add(this->AutoBotGroupBox);
			this->AutoBotTab->Controls->Add(this->EXPLabel);
			this->AutoBotTab->Controls->Add(this->MPLabel);
			this->AutoBotTab->Controls->Add(this->HPLabel);
			this->AutoBotTab->Controls->Add(this->EXPForeground);
			this->AutoBotTab->Controls->Add(this->MPForeground);
			this->AutoBotTab->Controls->Add(this->HPForeground);
			this->AutoBotTab->Controls->Add(this->EXPBackground);
			this->AutoBotTab->Controls->Add(this->MPBackground);
			this->AutoBotTab->Controls->Add(this->HPBackground);
			this->AutoBotTab->Location = System::Drawing::Point(4, 22);
			this->AutoBotTab->Name = L"AutoBotTab";
			this->AutoBotTab->Padding = System::Windows::Forms::Padding(3);
			this->AutoBotTab->Size = System::Drawing::Size(326, 396);
			this->AutoBotTab->TabIndex = 0;
			this->AutoBotTab->Text = L"AutoBot";
			this->AutoBotTab->UseVisualStyleBackColor = true;
			// 
			// AutoBotGroupBox
			// 
			this->AutoBotGroupBox->Controls->Add(this->CCAttacksLabel);
			this->AutoBotGroupBox->Controls->Add(this->CCTimedLabel);
			this->AutoBotGroupBox->Controls->Add(this->CCPeopleLabel);
			this->AutoBotGroupBox->Controls->Add(this->FixStatsButton);
			this->AutoBotGroupBox->Controls->Add(this->CCAttacksTextBox);
			this->AutoBotGroupBox->Controls->Add(this->CCAttacksCheckBox);
			this->AutoBotGroupBox->Controls->Add(this->CCTimedTextBox);
			this->AutoBotGroupBox->Controls->Add(this->CCTimedCheckBox);
			this->AutoBotGroupBox->Controls->Add(this->AutoSkill4ComboBox);
			this->AutoBotGroupBox->Controls->Add(this->CCPeopleTextBox);
			this->AutoBotGroupBox->Controls->Add(this->PointerTubiCheckBox);
			this->AutoBotGroupBox->Controls->Add(this->AutoSkill4CheckBox);
			this->AutoBotGroupBox->Controls->Add(this->CCPeopleCheckBox);
			this->AutoBotGroupBox->Controls->Add(this->AutoSkill4TextBox);
			this->AutoBotGroupBox->Controls->Add(this->AutoSkill3CheckBox);
			this->AutoBotGroupBox->Controls->Add(this->AutoSkill3TextBox);
			this->AutoBotGroupBox->Controls->Add(this->AutoSkill3ComboBox);
			this->AutoBotGroupBox->Controls->Add(this->AutoSkill2CheckBox);
			this->AutoBotGroupBox->Controls->Add(this->AutoSkill2TextBox);
			this->AutoBotGroupBox->Controls->Add(this->AutoSkill2ComboBox);
			this->AutoBotGroupBox->Controls->Add(this->AttackCheckBox);
			this->AutoBotGroupBox->Controls->Add(this->AutoSkill1CheckBox);
			this->AutoBotGroupBox->Controls->Add(this->HPCheckBox);
			this->AutoBotGroupBox->Controls->Add(this->AutoSkill1TextBox);
			this->AutoBotGroupBox->Controls->Add(this->HPTextBox);
			this->AutoBotGroupBox->Controls->Add(this->AutoSkill1ComboBox);
			this->AutoBotGroupBox->Controls->Add(this->HPComboBox);
			this->AutoBotGroupBox->Controls->Add(this->MPCheckBox);
			this->AutoBotGroupBox->Controls->Add(this->AutoLootComboBox);
			this->AutoBotGroupBox->Controls->Add(this->MPTextBox);
			this->AutoBotGroupBox->Controls->Add(this->AutoLootCheckBox);
			this->AutoBotGroupBox->Controls->Add(this->MPComboBox);
			this->AutoBotGroupBox->Controls->Add(this->AttackDelayLabel);
			this->AutoBotGroupBox->Controls->Add(this->AttackComboBox);
			this->AutoBotGroupBox->Controls->Add(this->AttackTrackBar);
			this->AutoBotGroupBox->Location = System::Drawing::Point(0, 70);
			this->AutoBotGroupBox->Name = L"AutoBotGroupBox";
			this->AutoBotGroupBox->Size = System::Drawing::Size(325, 326);
			this->AutoBotGroupBox->TabIndex = 36;
			this->AutoBotGroupBox->TabStop = false;
			this->AutoBotGroupBox->Text = L"Autobot";
			// 
			// CCAttacksLabel
			// 
			this->CCAttacksLabel->AutoSize = true;
			this->CCAttacksLabel->Location = System::Drawing::Point(199, 278);
			this->CCAttacksLabel->Name = L"CCAttacksLabel";
			this->CCAttacksLabel->Size = System::Drawing::Size(43, 13);
			this->CCAttacksLabel->TabIndex = 56;
			this->CCAttacksLabel->Text = L"Attacks";
			// 
			// CCTimedLabel
			// 
			this->CCTimedLabel->AutoSize = true;
			this->CCTimedLabel->Location = System::Drawing::Point(199, 251);
			this->CCTimedLabel->Name = L"CCTimedLabel";
			this->CCTimedLabel->Size = System::Drawing::Size(49, 13);
			this->CCTimedLabel->TabIndex = 55;
			this->CCTimedLabel->Text = L"Seconds";
			// 
			// CCPeopleLabel
			// 
			this->CCPeopleLabel->AutoSize = true;
			this->CCPeopleLabel->Location = System::Drawing::Point(199, 224);
			this->CCPeopleLabel->Name = L"CCPeopleLabel";
			this->CCPeopleLabel->Size = System::Drawing::Size(40, 13);
			this->CCPeopleLabel->TabIndex = 54;
			this->CCPeopleLabel->Text = L"People";
			// 
			// FixStatsButton
			// 
			this->FixStatsButton->Location = System::Drawing::Point(6, 300);
			this->FixStatsButton->Name = L"FixStatsButton";
			this->FixStatsButton->Size = System::Drawing::Size(311, 23);
			this->FixStatsButton->TabIndex = 31;
			this->FixStatsButton->Text = L"Fix Stats";
			this->FixStatsButton->UseVisualStyleBackColor = true;
			this->FixStatsButton->Click += gcnew System::EventHandler(this, &MainForm::FixStatsButton_Click);
			// 
			// CCAttacksTextBox
			// 
			this->CCAttacksTextBox->Location = System::Drawing::Point(91, 275);
			this->CCAttacksTextBox->Name = L"CCAttacksTextBox";
			this->CCAttacksTextBox->Size = System::Drawing::Size(102, 20);
			this->CCAttacksTextBox->TabIndex = 30;
			// 
			// CCAttacksCheckBox
			// 
			this->CCAttacksCheckBox->AutoSize = true;
			this->CCAttacksCheckBox->Location = System::Drawing::Point(6, 277);
			this->CCAttacksCheckBox->Name = L"CCAttacksCheckBox";
			this->CCAttacksCheckBox->Size = System::Drawing::Size(65, 17);
			this->CCAttacksCheckBox->TabIndex = 29;
			this->CCAttacksCheckBox->Text = L"Auto CC";
			this->CCAttacksCheckBox->UseVisualStyleBackColor = true;
			this->CCAttacksCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CCAttacksCheckBox_CheckedChanged);
			// 
			// CCTimedTextBox
			// 
			this->CCTimedTextBox->Location = System::Drawing::Point(91, 248);
			this->CCTimedTextBox->Name = L"CCTimedTextBox";
			this->CCTimedTextBox->Size = System::Drawing::Size(102, 20);
			this->CCTimedTextBox->TabIndex = 28;
			// 
			// CCTimedCheckBox
			// 
			this->CCTimedCheckBox->AutoSize = true;
			this->CCTimedCheckBox->Location = System::Drawing::Point(6, 250);
			this->CCTimedCheckBox->Name = L"CCTimedCheckBox";
			this->CCTimedCheckBox->Size = System::Drawing::Size(65, 17);
			this->CCTimedCheckBox->TabIndex = 27;
			this->CCTimedCheckBox->Text = L"Auto CC";
			this->CCTimedCheckBox->UseVisualStyleBackColor = true;
			this->CCTimedCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CCTimeCheckBox_CheckedChanged);
			// 
			// AutoSkill4ComboBox
			// 
			this->AutoSkill4ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoSkill4ComboBox->FormattingEnabled = true;
			this->AutoSkill4ComboBox->Location = System::Drawing::Point(202, 194);
			this->AutoSkill4ComboBox->Name = L"AutoSkill4ComboBox";
			this->AutoSkill4ComboBox->Size = System::Drawing::Size(115, 21);
			this->AutoSkill4ComboBox->TabIndex = 24;
			// 
			// CCPeopleTextBox
			// 
			this->CCPeopleTextBox->Location = System::Drawing::Point(91, 221);
			this->CCPeopleTextBox->Name = L"CCPeopleTextBox";
			this->CCPeopleTextBox->Size = System::Drawing::Size(102, 20);
			this->CCPeopleTextBox->TabIndex = 26;
			// 
			// PointerTubiCheckBox
			// 
			this->PointerTubiCheckBox->AutoSize = true;
			this->PointerTubiCheckBox->Location = System::Drawing::Point(91, 45);
			this->PointerTubiCheckBox->Name = L"PointerTubiCheckBox";
			this->PointerTubiCheckBox->Size = System::Drawing::Size(83, 17);
			this->PointerTubiCheckBox->TabIndex = 5;
			this->PointerTubiCheckBox->Text = L"Pointer Tubi";
			this->PointerTubiCheckBox->UseVisualStyleBackColor = true;
			this->PointerTubiCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::PointerTubiCheckBox_CheckedChanged);
			// 
			// AutoSkill4CheckBox
			// 
			this->AutoSkill4CheckBox->AutoSize = true;
			this->AutoSkill4CheckBox->Location = System::Drawing::Point(6, 196);
			this->AutoSkill4CheckBox->Name = L"AutoSkill4CheckBox";
			this->AutoSkill4CheckBox->Size = System::Drawing::Size(79, 17);
			this->AutoSkill4CheckBox->TabIndex = 22;
			this->AutoSkill4CheckBox->Text = L"Auto Skill 4";
			this->AutoSkill4CheckBox->UseVisualStyleBackColor = true;
			this->AutoSkill4CheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoSkill4CheckBox_CheckedChanged);
			// 
			// CCPeopleCheckBox
			// 
			this->CCPeopleCheckBox->AutoSize = true;
			this->CCPeopleCheckBox->Location = System::Drawing::Point(6, 223);
			this->CCPeopleCheckBox->Name = L"CCPeopleCheckBox";
			this->CCPeopleCheckBox->Size = System::Drawing::Size(65, 17);
			this->CCPeopleCheckBox->TabIndex = 25;
			this->CCPeopleCheckBox->Text = L"Auto CC";
			this->CCPeopleCheckBox->UseVisualStyleBackColor = true;
			this->CCPeopleCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CCPeopleCheckBox_CheckedChanged);
			// 
			// AutoSkill4TextBox
			// 
			this->AutoSkill4TextBox->Location = System::Drawing::Point(91, 194);
			this->AutoSkill4TextBox->MaxLength = 10;
			this->AutoSkill4TextBox->Name = L"AutoSkill4TextBox";
			this->AutoSkill4TextBox->Size = System::Drawing::Size(102, 20);
			this->AutoSkill4TextBox->TabIndex = 23;
			// 
			// AutoSkill3CheckBox
			// 
			this->AutoSkill3CheckBox->AutoSize = true;
			this->AutoSkill3CheckBox->Location = System::Drawing::Point(6, 170);
			this->AutoSkill3CheckBox->Name = L"AutoSkill3CheckBox";
			this->AutoSkill3CheckBox->Size = System::Drawing::Size(79, 17);
			this->AutoSkill3CheckBox->TabIndex = 19;
			this->AutoSkill3CheckBox->Text = L"Auto Skill 3";
			this->AutoSkill3CheckBox->UseVisualStyleBackColor = true;
			this->AutoSkill3CheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoSkill3CheckBox_CheckedChanged);
			// 
			// AutoSkill3TextBox
			// 
			this->AutoSkill3TextBox->Location = System::Drawing::Point(91, 168);
			this->AutoSkill3TextBox->MaxLength = 10;
			this->AutoSkill3TextBox->Name = L"AutoSkill3TextBox";
			this->AutoSkill3TextBox->Size = System::Drawing::Size(102, 20);
			this->AutoSkill3TextBox->TabIndex = 20;
			// 
			// AutoSkill3ComboBox
			// 
			this->AutoSkill3ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoSkill3ComboBox->FormattingEnabled = true;
			this->AutoSkill3ComboBox->Location = System::Drawing::Point(202, 168);
			this->AutoSkill3ComboBox->Name = L"AutoSkill3ComboBox";
			this->AutoSkill3ComboBox->Size = System::Drawing::Size(115, 21);
			this->AutoSkill3ComboBox->TabIndex = 21;
			// 
			// AutoSkill2CheckBox
			// 
			this->AutoSkill2CheckBox->AutoSize = true;
			this->AutoSkill2CheckBox->Location = System::Drawing::Point(6, 144);
			this->AutoSkill2CheckBox->Name = L"AutoSkill2CheckBox";
			this->AutoSkill2CheckBox->Size = System::Drawing::Size(79, 17);
			this->AutoSkill2CheckBox->TabIndex = 16;
			this->AutoSkill2CheckBox->Text = L"Auto Skill 2";
			this->AutoSkill2CheckBox->UseVisualStyleBackColor = true;
			this->AutoSkill2CheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoSkill2CheckBox_CheckedChanged);
			// 
			// AutoSkill2TextBox
			// 
			this->AutoSkill2TextBox->Location = System::Drawing::Point(91, 142);
			this->AutoSkill2TextBox->MaxLength = 10;
			this->AutoSkill2TextBox->Name = L"AutoSkill2TextBox";
			this->AutoSkill2TextBox->Size = System::Drawing::Size(102, 20);
			this->AutoSkill2TextBox->TabIndex = 17;
			// 
			// AutoSkill2ComboBox
			// 
			this->AutoSkill2ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoSkill2ComboBox->FormattingEnabled = true;
			this->AutoSkill2ComboBox->Location = System::Drawing::Point(202, 142);
			this->AutoSkill2ComboBox->Name = L"AutoSkill2ComboBox";
			this->AutoSkill2ComboBox->Size = System::Drawing::Size(115, 21);
			this->AutoSkill2ComboBox->TabIndex = 18;
			// 
			// AttackCheckBox
			// 
			this->AttackCheckBox->AutoSize = true;
			this->AttackCheckBox->Location = System::Drawing::Point(6, 18);
			this->AttackCheckBox->Name = L"AttackCheckBox";
			this->AttackCheckBox->Size = System::Drawing::Size(82, 17);
			this->AttackCheckBox->TabIndex = 1;
			this->AttackCheckBox->Text = L"Auto Attack";
			this->AttackCheckBox->UseVisualStyleBackColor = true;
			this->AttackCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AttackCheckBox_CheckedChanged);
			// 
			// AutoSkill1CheckBox
			// 
			this->AutoSkill1CheckBox->AutoSize = true;
			this->AutoSkill1CheckBox->Location = System::Drawing::Point(6, 118);
			this->AutoSkill1CheckBox->Name = L"AutoSkill1CheckBox";
			this->AutoSkill1CheckBox->Size = System::Drawing::Size(79, 17);
			this->AutoSkill1CheckBox->TabIndex = 13;
			this->AutoSkill1CheckBox->Text = L"Auto Skill 1";
			this->AutoSkill1CheckBox->UseVisualStyleBackColor = true;
			this->AutoSkill1CheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoSkill1CheckBox_CheckedChanged);
			// 
			// HPCheckBox
			// 
			this->HPCheckBox->AutoSize = true;
			this->HPCheckBox->Location = System::Drawing::Point(6, 69);
			this->HPCheckBox->Name = L"HPCheckBox";
			this->HPCheckBox->Size = System::Drawing::Size(66, 17);
			this->HPCheckBox->TabIndex = 7;
			this->HPCheckBox->Text = L"Auto HP";
			this->HPCheckBox->UseVisualStyleBackColor = true;
			this->HPCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::HPCheckBox_CheckedChanged);
			// 
			// AutoSkill1TextBox
			// 
			this->AutoSkill1TextBox->Location = System::Drawing::Point(91, 116);
			this->AutoSkill1TextBox->MaxLength = 10;
			this->AutoSkill1TextBox->Name = L"AutoSkill1TextBox";
			this->AutoSkill1TextBox->Size = System::Drawing::Size(102, 20);
			this->AutoSkill1TextBox->TabIndex = 14;
			// 
			// HPTextBox
			// 
			this->HPTextBox->Location = System::Drawing::Point(91, 66);
			this->HPTextBox->MaxLength = 10;
			this->HPTextBox->Name = L"HPTextBox";
			this->HPTextBox->Size = System::Drawing::Size(102, 20);
			this->HPTextBox->TabIndex = 8;
			// 
			// AutoSkill1ComboBox
			// 
			this->AutoSkill1ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoSkill1ComboBox->FormattingEnabled = true;
			this->AutoSkill1ComboBox->Location = System::Drawing::Point(202, 116);
			this->AutoSkill1ComboBox->Name = L"AutoSkill1ComboBox";
			this->AutoSkill1ComboBox->Size = System::Drawing::Size(115, 21);
			this->AutoSkill1ComboBox->TabIndex = 15;
			// 
			// HPComboBox
			// 
			this->HPComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->HPComboBox->FormattingEnabled = true;
			this->HPComboBox->Location = System::Drawing::Point(202, 66);
			this->HPComboBox->Name = L"HPComboBox";
			this->HPComboBox->Size = System::Drawing::Size(115, 21);
			this->HPComboBox->TabIndex = 9;
			// 
			// MPCheckBox
			// 
			this->MPCheckBox->AutoSize = true;
			this->MPCheckBox->Location = System::Drawing::Point(6, 95);
			this->MPCheckBox->Name = L"MPCheckBox";
			this->MPCheckBox->Size = System::Drawing::Size(67, 17);
			this->MPCheckBox->TabIndex = 10;
			this->MPCheckBox->Text = L"Auto MP";
			this->MPCheckBox->UseVisualStyleBackColor = true;
			this->MPCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::MPCheckBox_CheckedChanged);
			// 
			// AutoLootComboBox
			// 
			this->AutoLootComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoLootComboBox->FormattingEnabled = true;
			this->AutoLootComboBox->Location = System::Drawing::Point(202, 41);
			this->AutoLootComboBox->Name = L"AutoLootComboBox";
			this->AutoLootComboBox->Size = System::Drawing::Size(115, 21);
			this->AutoLootComboBox->TabIndex = 6;
			// 
			// MPTextBox
			// 
			this->MPTextBox->Location = System::Drawing::Point(91, 91);
			this->MPTextBox->MaxLength = 10;
			this->MPTextBox->Name = L"MPTextBox";
			this->MPTextBox->Size = System::Drawing::Size(102, 20);
			this->MPTextBox->TabIndex = 11;
			// 
			// AutoLootCheckBox
			// 
			this->AutoLootCheckBox->AutoSize = true;
			this->AutoLootCheckBox->Location = System::Drawing::Point(6, 45);
			this->AutoLootCheckBox->Name = L"AutoLootCheckBox";
			this->AutoLootCheckBox->Size = System::Drawing::Size(72, 17);
			this->AutoLootCheckBox->TabIndex = 4;
			this->AutoLootCheckBox->Text = L"Auto Loot";
			this->AutoLootCheckBox->UseVisualStyleBackColor = true;
			this->AutoLootCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoLootCheckBox_CheckedChanged);
			// 
			// MPComboBox
			// 
			this->MPComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->MPComboBox->FormattingEnabled = true;
			this->MPComboBox->Location = System::Drawing::Point(202, 91);
			this->MPComboBox->Name = L"MPComboBox";
			this->MPComboBox->Size = System::Drawing::Size(115, 21);
			this->MPComboBox->TabIndex = 12;
			// 
			// AttackDelayLabel
			// 
			this->AttackDelayLabel->AutoSize = true;
			this->AttackDelayLabel->Location = System::Drawing::Point(199, 19);
			this->AttackDelayLabel->Name = L"AttackDelayLabel";
			this->AttackDelayLabel->Size = System::Drawing::Size(35, 13);
			this->AttackDelayLabel->TabIndex = 28;
			this->AttackDelayLabel->Text = L"25 ms";
			// 
			// AttackComboBox
			// 
			this->AttackComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AttackComboBox->FormattingEnabled = true;
			this->AttackComboBox->Location = System::Drawing::Point(241, 16);
			this->AttackComboBox->Name = L"AttackComboBox";
			this->AttackComboBox->Size = System::Drawing::Size(76, 21);
			this->AttackComboBox->TabIndex = 3;
			// 
			// AttackTrackBar
			// 
			this->AttackTrackBar->AutoSize = false;
			this->AttackTrackBar->Location = System::Drawing::Point(91, 19);
			this->AttackTrackBar->Maximum = 500;
			this->AttackTrackBar->Minimum = 1;
			this->AttackTrackBar->Name = L"AttackTrackBar";
			this->AttackTrackBar->Size = System::Drawing::Size(102, 18);
			this->AttackTrackBar->TabIndex = 2;
			this->AttackTrackBar->TickFrequency = 10;
			this->AttackTrackBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->AttackTrackBar->Value = 1;
			// 
			// EXPLabel
			// 
			this->EXPLabel->BackColor = System::Drawing::Color::Transparent;
			this->EXPLabel->Location = System::Drawing::Point(3, 44);
			this->EXPLabel->Name = L"EXPLabel";
			this->EXPLabel->Size = System::Drawing::Size(100, 20);
			this->EXPLabel->TabIndex = 6;
			this->EXPLabel->Text = L"EXP: 99,99%";
			this->EXPLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MPLabel
			// 
			this->MPLabel->BackColor = System::Drawing::Color::Transparent;
			this->MPLabel->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->MPLabel->Location = System::Drawing::Point(3, 22);
			this->MPLabel->Name = L"MPLabel";
			this->MPLabel->Size = System::Drawing::Size(100, 20);
			this->MPLabel->TabIndex = 5;
			this->MPLabel->Text = L"MP: 100";
			this->MPLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// HPLabel
			// 
			this->HPLabel->BackColor = System::Drawing::Color::Transparent;
			this->HPLabel->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->HPLabel->Location = System::Drawing::Point(3, 0);
			this->HPLabel->Name = L"HPLabel";
			this->HPLabel->Size = System::Drawing::Size(100, 20);
			this->HPLabel->TabIndex = 4;
			this->HPLabel->Text = L"HP: 10000/10000";
			this->HPLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// EXPForeground
			// 
			this->EXPForeground->BackColor = System::Drawing::Color::Gold;
			this->EXPForeground->Location = System::Drawing::Point(103, 44);
			this->EXPForeground->Name = L"EXPForeground";
			this->EXPForeground->Size = System::Drawing::Size(223, 20);
			this->EXPForeground->TabIndex = 13;
			this->EXPForeground->TabStop = false;
			// 
			// MPForeground
			// 
			this->MPForeground->BackColor = System::Drawing::Color::MidnightBlue;
			this->MPForeground->Location = System::Drawing::Point(103, 22);
			this->MPForeground->Name = L"MPForeground";
			this->MPForeground->Size = System::Drawing::Size(223, 20);
			this->MPForeground->TabIndex = 12;
			this->MPForeground->TabStop = false;
			// 
			// HPForeground
			// 
			this->HPForeground->BackColor = System::Drawing::Color::DarkRed;
			this->HPForeground->Location = System::Drawing::Point(103, 0);
			this->HPForeground->Name = L"HPForeground";
			this->HPForeground->Size = System::Drawing::Size(223, 20);
			this->HPForeground->TabIndex = 11;
			this->HPForeground->TabStop = false;
			// 
			// EXPBackground
			// 
			this->EXPBackground->BackColor = System::Drawing::Color::DarkGray;
			this->EXPBackground->Location = System::Drawing::Point(103, 44);
			this->EXPBackground->Name = L"EXPBackground";
			this->EXPBackground->Size = System::Drawing::Size(223, 20);
			this->EXPBackground->TabIndex = 10;
			this->EXPBackground->TabStop = false;
			// 
			// MPBackground
			// 
			this->MPBackground->BackColor = System::Drawing::Color::DarkGray;
			this->MPBackground->Location = System::Drawing::Point(103, 22);
			this->MPBackground->Name = L"MPBackground";
			this->MPBackground->Size = System::Drawing::Size(223, 20);
			this->MPBackground->TabIndex = 9;
			this->MPBackground->TabStop = false;
			// 
			// HPBackground
			// 
			this->HPBackground->BackColor = System::Drawing::Color::DarkGray;
			this->HPBackground->Location = System::Drawing::Point(103, 0);
			this->HPBackground->Name = L"HPBackground";
			this->HPBackground->Size = System::Drawing::Size(223, 20);
			this->HPBackground->TabIndex = 7;
			this->HPBackground->TabStop = false;
			// 
			// HacksTab
			// 
			this->HacksTab->Controls->Add(this->gbMiscHacks);
			this->HacksTab->Controls->Add(this->gbCharHacks);
			this->HacksTab->Controls->Add(this->MobHacks);
			this->HacksTab->Location = System::Drawing::Point(4, 22);
			this->HacksTab->Name = L"HacksTab";
			this->HacksTab->Padding = System::Windows::Forms::Padding(3);
			this->HacksTab->Size = System::Drawing::Size(326, 396);
			this->HacksTab->TabIndex = 1;
			this->HacksTab->Text = L"Hacks";
			this->HacksTab->UseVisualStyleBackColor = true;
			// 
			// gbMiscHacks
			// 
			this->gbMiscHacks->Controls->Add(this->cbPinTyper);
			this->gbMiscHacks->Controls->Add(this->cbJDA);
			this->gbMiscHacks->Controls->Add(this->cbNoBG);
			this->gbMiscHacks->Location = System::Drawing::Point(7, 289);
			this->gbMiscHacks->Name = L"gbMiscHacks";
			this->gbMiscHacks->Size = System::Drawing::Size(310, 98);
			this->gbMiscHacks->TabIndex = 2;
			this->gbMiscHacks->TabStop = false;
			this->gbMiscHacks->Text = L"Other";
			// 
			// cbPinTyper
			// 
			this->cbPinTyper->AutoSize = true;
			this->cbPinTyper->Location = System::Drawing::Point(6, 65);
			this->cbPinTyper->Name = L"cbPinTyper";
			this->cbPinTyper->Size = System::Drawing::Size(71, 17);
			this->cbPinTyper->TabIndex = 2;
			this->cbPinTyper->Text = L"Pin Typer";
			this->cbPinTyper->UseVisualStyleBackColor = true;
			this->cbPinTyper->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbPinTyper_CheckedChanged);
			// 
			// cbJDA
			// 
			this->cbJDA->AutoSize = true;
			this->cbJDA->Location = System::Drawing::Point(6, 42);
			this->cbJDA->Name = L"cbJDA";
			this->cbJDA->Size = System::Drawing::Size(46, 17);
			this->cbJDA->TabIndex = 1;
			this->cbJDA->Text = L"JDA";
			this->cbJDA->UseVisualStyleBackColor = true;
			this->cbJDA->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbJDA_CheckedChanged);
			// 
			// cbNoBG
			// 
			this->cbNoBG->AutoSize = true;
			this->cbNoBG->Location = System::Drawing::Point(6, 19);
			this->cbNoBG->Name = L"cbNoBG";
			this->cbNoBG->Size = System::Drawing::Size(145, 17);
			this->cbNoBG->TabIndex = 0;
			this->cbNoBG->Text = L"No Background + Clouds";
			this->cbNoBG->UseVisualStyleBackColor = true;
			this->cbNoBG->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbNoBG_CheckedChanged);
			// 
			// gbCharHacks
			// 
			this->gbCharHacks->Controls->Add(this->cbNDAllAttacks);
			this->gbCharHacks->Controls->Add(this->cbUnlimitedMorph);
			this->gbCharHacks->Controls->Add(this->cbDojangGodmode);
			this->gbCharHacks->Controls->Add(this->cbNoKB);
			this->gbCharHacks->Controls->Add(this->cbInstantAirLoot);
			this->gbCharHacks->Controls->Add(this->cbFusionAttack);
			this->gbCharHacks->Controls->Add(this->cbPerfectLoot);
			this->gbCharHacks->Location = System::Drawing::Point(7, 3);
			this->gbCharHacks->Name = L"gbCharHacks";
			this->gbCharHacks->Size = System::Drawing::Size(310, 118);
			this->gbCharHacks->TabIndex = 1;
			this->gbCharHacks->TabStop = false;
			this->gbCharHacks->Text = L"Character";
			// 
			// cbNDAllAttacks
			// 
			this->cbNDAllAttacks->AutoSize = true;
			this->cbNDAllAttacks->Location = System::Drawing::Point(6, 88);
			this->cbNDAllAttacks->Name = L"cbNDAllAttacks";
			this->cbNDAllAttacks->Size = System::Drawing::Size(101, 17);
			this->cbNDAllAttacks->TabIndex = 8;
			this->cbNDAllAttacks->Text = L"ND - All Attacks";
			this->cbNDAllAttacks->UseVisualStyleBackColor = true;
			this->cbNDAllAttacks->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbNDAllAttacks_CheckedChanged);
			// 
			// cbUnlimitedMorph
			// 
			this->cbUnlimitedMorph->AutoSize = true;
			this->cbUnlimitedMorph->Location = System::Drawing::Point(159, 65);
			this->cbUnlimitedMorph->Name = L"cbUnlimitedMorph";
			this->cbUnlimitedMorph->Size = System::Drawing::Size(102, 17);
			this->cbUnlimitedMorph->TabIndex = 7;
			this->cbUnlimitedMorph->Text = L"Unlimited Morph";
			this->cbUnlimitedMorph->UseVisualStyleBackColor = true;
			this->cbUnlimitedMorph->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbUnlimitedMorph_CheckedChanged);
			// 
			// cbDojangGodmode
			// 
			this->cbDojangGodmode->AutoSize = true;
			this->cbDojangGodmode->Location = System::Drawing::Point(6, 42);
			this->cbDojangGodmode->Name = L"cbDojangGodmode";
			this->cbDojangGodmode->Size = System::Drawing::Size(109, 17);
			this->cbDojangGodmode->TabIndex = 6;
			this->cbDojangGodmode->Text = L"Dojang Godmode";
			this->cbDojangGodmode->UseVisualStyleBackColor = true;
			this->cbDojangGodmode->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbDojangGodmode_CheckedChanged);
			// 
			// cbNoKB
			// 
			this->cbNoKB->AutoSize = true;
			this->cbNoKB->Location = System::Drawing::Point(6, 65);
			this->cbNoKB->Name = L"cbNoKB";
			this->cbNoKB->Size = System::Drawing::Size(98, 17);
			this->cbNoKB->TabIndex = 5;
			this->cbNoKB->Text = L"No Knockback";
			this->cbNoKB->UseVisualStyleBackColor = true;
			this->cbNoKB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbNoKB_CheckedChanged);
			// 
			// cbInstantAirLoot
			// 
			this->cbInstantAirLoot->AutoSize = true;
			this->cbInstantAirLoot->Location = System::Drawing::Point(159, 42);
			this->cbInstantAirLoot->Name = L"cbInstantAirLoot";
			this->cbInstantAirLoot->Size = System::Drawing::Size(97, 17);
			this->cbInstantAirLoot->TabIndex = 2;
			this->cbInstantAirLoot->Text = L"Instant Air Loot";
			this->cbInstantAirLoot->UseVisualStyleBackColor = true;
			this->cbInstantAirLoot->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbInstantAirLoot_CheckedChanged);
			// 
			// cbFusionAttack
			// 
			this->cbFusionAttack->AutoSize = true;
			this->cbFusionAttack->Location = System::Drawing::Point(6, 19);
			this->cbFusionAttack->Name = L"cbFusionAttack";
			this->cbFusionAttack->Size = System::Drawing::Size(91, 17);
			this->cbFusionAttack->TabIndex = 0;
			this->cbFusionAttack->Text = L"Fusion Attack";
			this->cbFusionAttack->UseVisualStyleBackColor = true;
			this->cbFusionAttack->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbFusionAttack_CheckedChanged);
			// 
			// cbPerfectLoot
			// 
			this->cbPerfectLoot->AutoSize = true;
			this->cbPerfectLoot->Location = System::Drawing::Point(159, 19);
			this->cbPerfectLoot->Name = L"cbPerfectLoot";
			this->cbPerfectLoot->Size = System::Drawing::Size(84, 17);
			this->cbPerfectLoot->TabIndex = 1;
			this->cbPerfectLoot->Text = L"Perfect Loot";
			this->cbPerfectLoot->UseVisualStyleBackColor = true;
			this->cbPerfectLoot->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbPerfectLoot_CheckedChanged);
			// 
			// MobHacks
			// 
			this->MobHacks->Controls->Add(this->cbAutoAggro);
			this->MobHacks->Controls->Add(this->cbNoMobs);
			this->MobHacks->Controls->Add(this->cbFasterMobs);
			this->MobHacks->Controls->Add(this->cbMobDisarm);
			this->MobHacks->Controls->Add(this->cbJumpRight);
			this->MobHacks->Controls->Add(this->cbWalkRight);
			this->MobHacks->Controls->Add(this->cbVacRight);
			this->MobHacks->Location = System::Drawing::Point(7, 127);
			this->MobHacks->Name = L"MobHacks";
			this->MobHacks->Size = System::Drawing::Size(310, 156);
			this->MobHacks->TabIndex = 0;
			this->MobHacks->TabStop = false;
			this->MobHacks->Text = L"Mob";
			// 
			// cbNoMobs
			// 
			this->cbNoMobs->AutoSize = true;
			this->cbNoMobs->Location = System::Drawing::Point(6, 133);
			this->cbNoMobs->Name = L"cbNoMobs";
			this->cbNoMobs->Size = System::Drawing::Size(69, 17);
			this->cbNoMobs->TabIndex = 7;
			this->cbNoMobs->Text = L"No Mobs";
			this->cbNoMobs->UseVisualStyleBackColor = true;
			this->cbNoMobs->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbNoMobs_CheckedChanged);
			// 
			// cbFasterMobs
			// 
			this->cbFasterMobs->AutoSize = true;
			this->cbFasterMobs->Location = System::Drawing::Point(6, 111);
			this->cbFasterMobs->Name = L"cbFasterMobs";
			this->cbFasterMobs->Size = System::Drawing::Size(84, 17);
			this->cbFasterMobs->TabIndex = 6;
			this->cbFasterMobs->Text = L"Faster Mobs";
			this->cbFasterMobs->UseVisualStyleBackColor = true;
			this->cbFasterMobs->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbFasterMobs_CheckedChanged);
			// 
			// cbMobDisarm
			// 
			this->cbMobDisarm->AutoSize = true;
			this->cbMobDisarm->Location = System::Drawing::Point(6, 88);
			this->cbMobDisarm->Name = L"cbMobDisarm";
			this->cbMobDisarm->Size = System::Drawing::Size(101, 17);
			this->cbMobDisarm->TabIndex = 5;
			this->cbMobDisarm->Text = L"Full Mob Disarm";
			this->cbMobDisarm->UseVisualStyleBackColor = true;
			this->cbMobDisarm->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbMobDisarm_CheckedChanged);
			// 
			// cbJumpRight
			// 
			this->cbJumpRight->AutoSize = true;
			this->cbJumpRight->Location = System::Drawing::Point(6, 65);
			this->cbJumpRight->Name = L"cbJumpRight";
			this->cbJumpRight->Size = System::Drawing::Size(131, 17);
			this->cbJumpRight->TabIndex = 4;
			this->cbJumpRight->Text = L"Jump Unrandom Right";
			this->cbJumpRight->UseVisualStyleBackColor = true;
			this->cbJumpRight->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbJumpRight_CheckedChanged);
			// 
			// cbWalkRight
			// 
			this->cbWalkRight->AutoSize = true;
			this->cbWalkRight->Location = System::Drawing::Point(6, 42);
			this->cbWalkRight->Name = L"cbWalkRight";
			this->cbWalkRight->Size = System::Drawing::Size(131, 17);
			this->cbWalkRight->TabIndex = 2;
			this->cbWalkRight->Text = L"Walk Unrandom Right";
			this->cbWalkRight->UseVisualStyleBackColor = true;
			this->cbWalkRight->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbWalkRight_CheckedChanged);
			// 
			// cbVacRight
			// 
			this->cbVacRight->AutoSize = true;
			this->cbVacRight->Location = System::Drawing::Point(6, 19);
			this->cbVacRight->Name = L"cbVacRight";
			this->cbVacRight->Size = System::Drawing::Size(73, 17);
			this->cbVacRight->TabIndex = 3;
			this->cbVacRight->Text = L"Vac Right";
			this->cbVacRight->UseVisualStyleBackColor = true;
			this->cbVacRight->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbVacRight_CheckedChanged);
			// 
			// PacketSenderTab
			// 
			this->PacketSenderTab->Controls->Add(this->SavePacketsButton);
			this->PacketSenderTab->Controls->Add(this->EditPacketGroupBox);
			this->PacketSenderTab->Controls->Add(this->DeletePacketsGroupBox);
			this->PacketSenderTab->Controls->Add(this->AddPacketsGroupBox);
			this->PacketSenderTab->Controls->Add(this->SendPacketGroupBox);
			this->PacketSenderTab->Location = System::Drawing::Point(4, 22);
			this->PacketSenderTab->Name = L"PacketSenderTab";
			this->PacketSenderTab->Padding = System::Windows::Forms::Padding(3);
			this->PacketSenderTab->Size = System::Drawing::Size(326, 396);
			this->PacketSenderTab->TabIndex = 3;
			this->PacketSenderTab->Text = L"Packet Sender";
			this->PacketSenderTab->UseVisualStyleBackColor = true;
			// 
			// SavePacketsButton
			// 
			this->SavePacketsButton->Location = System::Drawing::Point(6, 367);
			this->SavePacketsButton->Name = L"SavePacketsButton";
			this->SavePacketsButton->Size = System::Drawing::Size(314, 23);
			this->SavePacketsButton->TabIndex = 7;
			this->SavePacketsButton->Text = L"Save Packets";
			this->SavePacketsButton->UseVisualStyleBackColor = true;
			this->SavePacketsButton->Click += gcnew System::EventHandler(this, &MainForm::SavePacketsButton_Click);
			// 
			// EditPacketGroupBox
			// 
			this->EditPacketGroupBox->Controls->Add(this->SavePacketEditButton);
			this->EditPacketGroupBox->Controls->Add(this->EditPacketPacketTextBox);
			this->EditPacketGroupBox->Controls->Add(this->EditPacketNameTextBox);
			this->EditPacketGroupBox->Controls->Add(this->SelectPacketForEditingComboBox);
			this->EditPacketGroupBox->Location = System::Drawing::Point(6, 180);
			this->EditPacketGroupBox->Name = L"EditPacketGroupBox";
			this->EditPacketGroupBox->Size = System::Drawing::Size(314, 72);
			this->EditPacketGroupBox->TabIndex = 6;
			this->EditPacketGroupBox->TabStop = false;
			this->EditPacketGroupBox->Text = L"Edit Packet";
			// 
			// SavePacketEditButton
			// 
			this->SavePacketEditButton->Location = System::Drawing::Point(209, 19);
			this->SavePacketEditButton->Name = L"SavePacketEditButton";
			this->SavePacketEditButton->Size = System::Drawing::Size(99, 21);
			this->SavePacketEditButton->TabIndex = 10;
			this->SavePacketEditButton->Text = L"Edit Packet";
			this->SavePacketEditButton->UseVisualStyleBackColor = true;
			this->SavePacketEditButton->Click += gcnew System::EventHandler(this, &MainForm::SavePacketEditButton_Click);
			// 
			// EditPacketPacketTextBox
			// 
			this->EditPacketPacketTextBox->Location = System::Drawing::Point(112, 46);
			this->EditPacketPacketTextBox->Name = L"EditPacketPacketTextBox";
			this->EditPacketPacketTextBox->Size = System::Drawing::Size(196, 20);
			this->EditPacketPacketTextBox->TabIndex = 5;
			// 
			// EditPacketNameTextBox
			// 
			this->EditPacketNameTextBox->Location = System::Drawing::Point(6, 46);
			this->EditPacketNameTextBox->Name = L"EditPacketNameTextBox";
			this->EditPacketNameTextBox->Size = System::Drawing::Size(100, 20);
			this->EditPacketNameTextBox->TabIndex = 5;
			// 
			// SelectPacketForEditingComboBox
			// 
			this->SelectPacketForEditingComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->SelectPacketForEditingComboBox->FormattingEnabled = true;
			this->SelectPacketForEditingComboBox->Location = System::Drawing::Point(6, 19);
			this->SelectPacketForEditingComboBox->Name = L"SelectPacketForEditingComboBox";
			this->SelectPacketForEditingComboBox->Size = System::Drawing::Size(197, 21);
			this->SelectPacketForEditingComboBox->TabIndex = 10;
			this->SelectPacketForEditingComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::SelectPacketForEditingComboBox_SelectedIndexChanged);
			// 
			// DeletePacketsGroupBox
			// 
			this->DeletePacketsGroupBox->Controls->Add(this->DeletePacketComboBox);
			this->DeletePacketsGroupBox->Controls->Add(this->DeletePacketButton);
			this->DeletePacketsGroupBox->Location = System::Drawing::Point(6, 258);
			this->DeletePacketsGroupBox->Name = L"DeletePacketsGroupBox";
			this->DeletePacketsGroupBox->Size = System::Drawing::Size(314, 51);
			this->DeletePacketsGroupBox->TabIndex = 5;
			this->DeletePacketsGroupBox->TabStop = false;
			this->DeletePacketsGroupBox->Text = L"Delete Packets";
			// 
			// DeletePacketComboBox
			// 
			this->DeletePacketComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->DeletePacketComboBox->FormattingEnabled = true;
			this->DeletePacketComboBox->Location = System::Drawing::Point(6, 19);
			this->DeletePacketComboBox->Name = L"DeletePacketComboBox";
			this->DeletePacketComboBox->Size = System::Drawing::Size(197, 21);
			this->DeletePacketComboBox->TabIndex = 4;
			// 
			// DeletePacketButton
			// 
			this->DeletePacketButton->Location = System::Drawing::Point(209, 19);
			this->DeletePacketButton->Name = L"DeletePacketButton";
			this->DeletePacketButton->Size = System::Drawing::Size(99, 21);
			this->DeletePacketButton->TabIndex = 3;
			this->DeletePacketButton->Text = L"Delete Packet";
			this->DeletePacketButton->UseVisualStyleBackColor = true;
			this->DeletePacketButton->Click += gcnew System::EventHandler(this, &MainForm::DeletePacketButton_Click);
			// 
			// AddPacketsGroupBox
			// 
			this->AddPacketsGroupBox->Controls->Add(this->AddPacketButton);
			this->AddPacketsGroupBox->Controls->Add(this->AddPacketPacketTextBox);
			this->AddPacketsGroupBox->Controls->Add(this->AddPacketNameTextBox);
			this->AddPacketsGroupBox->Controls->Add(this->AddPacketPacketLabel);
			this->AddPacketsGroupBox->Controls->Add(this->AddPacketNameLabel);
			this->AddPacketsGroupBox->Location = System::Drawing::Point(6, 85);
			this->AddPacketsGroupBox->Name = L"AddPacketsGroupBox";
			this->AddPacketsGroupBox->Size = System::Drawing::Size(314, 89);
			this->AddPacketsGroupBox->TabIndex = 4;
			this->AddPacketsGroupBox->TabStop = false;
			this->AddPacketsGroupBox->Text = L"Add Packets";
			// 
			// AddPacketButton
			// 
			this->AddPacketButton->Location = System::Drawing::Point(6, 59);
			this->AddPacketButton->Name = L"AddPacketButton";
			this->AddPacketButton->Size = System::Drawing::Size(302, 23);
			this->AddPacketButton->TabIndex = 4;
			this->AddPacketButton->Text = L"Add Packet";
			this->AddPacketButton->UseVisualStyleBackColor = true;
			this->AddPacketButton->Click += gcnew System::EventHandler(this, &MainForm::AddPacketButton_Click);
			// 
			// AddPacketPacketTextBox
			// 
			this->AddPacketPacketTextBox->Location = System::Drawing::Point(112, 32);
			this->AddPacketPacketTextBox->Name = L"AddPacketPacketTextBox";
			this->AddPacketPacketTextBox->Size = System::Drawing::Size(196, 20);
			this->AddPacketPacketTextBox->TabIndex = 3;
			// 
			// AddPacketNameTextBox
			// 
			this->AddPacketNameTextBox->Location = System::Drawing::Point(6, 32);
			this->AddPacketNameTextBox->Name = L"AddPacketNameTextBox";
			this->AddPacketNameTextBox->Size = System::Drawing::Size(100, 20);
			this->AddPacketNameTextBox->TabIndex = 2;
			// 
			// AddPacketPacketLabel
			// 
			this->AddPacketPacketLabel->AutoSize = true;
			this->AddPacketPacketLabel->Location = System::Drawing::Point(110, 16);
			this->AddPacketPacketLabel->Name = L"AddPacketPacketLabel";
			this->AddPacketPacketLabel->Size = System::Drawing::Size(44, 13);
			this->AddPacketPacketLabel->TabIndex = 1;
			this->AddPacketPacketLabel->Text = L"Packet:";
			// 
			// AddPacketNameLabel
			// 
			this->AddPacketNameLabel->AutoSize = true;
			this->AddPacketNameLabel->Location = System::Drawing::Point(6, 16);
			this->AddPacketNameLabel->Name = L"AddPacketNameLabel";
			this->AddPacketNameLabel->Size = System::Drawing::Size(38, 13);
			this->AddPacketNameLabel->TabIndex = 0;
			this->AddPacketNameLabel->Text = L"Name:";
			// 
			// SendPacketGroupBox
			// 
			this->SendPacketGroupBox->Controls->Add(this->SpamsPacketButton);
			this->SendPacketGroupBox->Controls->Add(this->SpamPacketsDelayLabel);
			this->SendPacketGroupBox->Controls->Add(this->SpamPacketsDelayTextBox);
			this->SendPacketGroupBox->Controls->Add(this->SpamPacketTimesLabel);
			this->SendPacketGroupBox->Controls->Add(this->SpamPacketTimesTextBox);
			this->SendPacketGroupBox->Controls->Add(this->PacketSelectBox);
			this->SendPacketGroupBox->Controls->Add(this->SendPacketButton);
			this->SendPacketGroupBox->Location = System::Drawing::Point(6, 6);
			this->SendPacketGroupBox->Name = L"SendPacketGroupBox";
			this->SendPacketGroupBox->Size = System::Drawing::Size(314, 73);
			this->SendPacketGroupBox->TabIndex = 3;
			this->SendPacketGroupBox->TabStop = false;
			this->SendPacketGroupBox->Text = L"Packet Sender";
			// 
			// SpamsPacketButton
			// 
			this->SpamsPacketButton->Location = System::Drawing::Point(6, 46);
			this->SpamsPacketButton->Name = L"SpamsPacketButton";
			this->SpamsPacketButton->Size = System::Drawing::Size(100, 20);
			this->SpamsPacketButton->TabIndex = 8;
			this->SpamsPacketButton->Text = L"Spam Packets";
			this->SpamsPacketButton->UseVisualStyleBackColor = true;
			this->SpamsPacketButton->Click += gcnew System::EventHandler(this, &MainForm::SpamsPacketButton_Click);
			// 
			// SpamPacketsDelayLabel
			// 
			this->SpamPacketsDelayLabel->AutoSize = true;
			this->SpamPacketsDelayLabel->Location = System::Drawing::Point(260, 50);
			this->SpamPacketsDelayLabel->Name = L"SpamPacketsDelayLabel";
			this->SpamPacketsDelayLabel->Size = System::Drawing::Size(48, 13);
			this->SpamPacketsDelayLabel->TabIndex = 7;
			this->SpamPacketsDelayLabel->Text = L"ms delay";
			// 
			// SpamPacketsDelayTextBox
			// 
			this->SpamPacketsDelayTextBox->Location = System::Drawing::Point(224, 46);
			this->SpamPacketsDelayTextBox->Name = L"SpamPacketsDelayTextBox";
			this->SpamPacketsDelayTextBox->Size = System::Drawing::Size(30, 20);
			this->SpamPacketsDelayTextBox->TabIndex = 6;
			// 
			// SpamPacketTimesLabel
			// 
			this->SpamPacketTimesLabel->AutoSize = true;
			this->SpamPacketTimesLabel->Location = System::Drawing::Point(158, 50);
			this->SpamPacketTimesLabel->Name = L"SpamPacketTimesLabel";
			this->SpamPacketTimesLabel->Size = System::Drawing::Size(60, 13);
			this->SpamPacketTimesLabel->TabIndex = 5;
			this->SpamPacketTimesLabel->Text = L"Times, with";
			// 
			// SpamPacketTimesTextBox
			// 
			this->SpamPacketTimesTextBox->Location = System::Drawing::Point(113, 46);
			this->SpamPacketTimesTextBox->Name = L"SpamPacketTimesTextBox";
			this->SpamPacketTimesTextBox->Size = System::Drawing::Size(41, 20);
			this->SpamPacketTimesTextBox->TabIndex = 4;
			// 
			// PacketSelectBox
			// 
			this->PacketSelectBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->PacketSelectBox->FormattingEnabled = true;
			this->PacketSelectBox->Location = System::Drawing::Point(6, 19);
			this->PacketSelectBox->Name = L"PacketSelectBox";
			this->PacketSelectBox->Size = System::Drawing::Size(197, 21);
			this->PacketSelectBox->TabIndex = 2;
			// 
			// SendPacketButton
			// 
			this->SendPacketButton->Location = System::Drawing::Point(209, 19);
			this->SendPacketButton->Name = L"SendPacketButton";
			this->SendPacketButton->Size = System::Drawing::Size(99, 21);
			this->SendPacketButton->TabIndex = 0;
			this->SendPacketButton->Text = L"Send Packet";
			this->SendPacketButton->UseVisualStyleBackColor = true;
			this->SendPacketButton->Click += gcnew System::EventHandler(this, &MainForm::SendPacketButton_Click);
			// 
			// SPControlTabPage
			// 
			this->SPControlTabPage->Controls->Add(this->SPControlGroupBox);
			this->SPControlTabPage->Controls->Add(this->SPControlListView);
			this->SPControlTabPage->Location = System::Drawing::Point(4, 22);
			this->SPControlTabPage->Name = L"SPControlTabPage";
			this->SPControlTabPage->Size = System::Drawing::Size(326, 396);
			this->SPControlTabPage->TabIndex = 4;
			this->SPControlTabPage->Text = L"Spawn Control";
			this->SPControlTabPage->UseVisualStyleBackColor = true;
			// 
			// SPControlGroupBox
			// 
			this->SPControlGroupBox->Controls->Add(this->GetSPControlCoordsButton);
			this->SPControlGroupBox->Controls->Add(this->SPControlAddButton);
			this->SPControlGroupBox->Controls->Add(this->SPControlMapIDLabel);
			this->SPControlGroupBox->Controls->Add(this->SPControlCheckBox);
			this->SPControlGroupBox->Controls->Add(this->SPControlYTextBox);
			this->SPControlGroupBox->Controls->Add(this->SPControlNameLabel);
			this->SPControlGroupBox->Controls->Add(this->SPControlXTextBox);
			this->SPControlGroupBox->Controls->Add(this->SPControlYLabel);
			this->SPControlGroupBox->Controls->Add(this->SPControlMapIDTextBox);
			this->SPControlGroupBox->Controls->Add(this->SPControlXLabel);
			this->SPControlGroupBox->Controls->Add(this->SPControlNameTextBox);
			this->SPControlGroupBox->Location = System::Drawing::Point(7, 295);
			this->SPControlGroupBox->Name = L"SPControlGroupBox";
			this->SPControlGroupBox->Size = System::Drawing::Size(310, 93);
			this->SPControlGroupBox->TabIndex = 37;
			this->SPControlGroupBox->TabStop = false;
			this->SPControlGroupBox->Text = L"Add New Location";
			// 
			// GetSPControlCoordsButton
			// 
			this->GetSPControlCoordsButton->Location = System::Drawing::Point(149, 59);
			this->GetSPControlCoordsButton->Name = L"GetSPControlCoordsButton";
			this->GetSPControlCoordsButton->Size = System::Drawing::Size(80, 23);
			this->GetSPControlCoordsButton->TabIndex = 38;
			this->GetSPControlCoordsButton->Text = L"Get Current";
			this->GetSPControlCoordsButton->UseVisualStyleBackColor = true;
			this->GetSPControlCoordsButton->Click += gcnew System::EventHandler(this, &MainForm::GetSPControlCoordsButton_Click);
			// 
			// SPControlAddButton
			// 
			this->SPControlAddButton->Location = System::Drawing::Point(9, 59);
			this->SPControlAddButton->Name = L"SPControlAddButton";
			this->SPControlAddButton->Size = System::Drawing::Size(134, 23);
			this->SPControlAddButton->TabIndex = 37;
			this->SPControlAddButton->Text = L"Add Location";
			this->SPControlAddButton->UseVisualStyleBackColor = true;
			this->SPControlAddButton->Click += gcnew System::EventHandler(this, &MainForm::SPControlAddButton_Click);
			// 
			// SPControlMapIDLabel
			// 
			this->SPControlMapIDLabel->Location = System::Drawing::Point(149, 16);
			this->SPControlMapIDLabel->Name = L"SPControlMapIDLabel";
			this->SPControlMapIDLabel->Size = System::Drawing::Size(80, 14);
			this->SPControlMapIDLabel->TabIndex = 32;
			this->SPControlMapIDLabel->Text = L"MapID";
			this->SPControlMapIDLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SPControlCheckBox
			// 
			this->SPControlCheckBox->Location = System::Drawing::Point(235, 63);
			this->SPControlCheckBox->Name = L"SPControlCheckBox";
			this->SPControlCheckBox->Size = System::Drawing::Size(66, 17);
			this->SPControlCheckBox->TabIndex = 27;
			this->SPControlCheckBox->Text = L"Enable";
			this->SPControlCheckBox->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->SPControlCheckBox->UseVisualStyleBackColor = true;
			// 
			// SPControlYTextBox
			// 
			this->SPControlYTextBox->Location = System::Drawing::Point(271, 33);
			this->SPControlYTextBox->Name = L"SPControlYTextBox";
			this->SPControlYTextBox->Size = System::Drawing::Size(30, 20);
			this->SPControlYTextBox->TabIndex = 36;
			// 
			// SPControlNameLabel
			// 
			this->SPControlNameLabel->Location = System::Drawing::Point(6, 16);
			this->SPControlNameLabel->Name = L"SPControlNameLabel";
			this->SPControlNameLabel->Size = System::Drawing::Size(137, 14);
			this->SPControlNameLabel->TabIndex = 29;
			this->SPControlNameLabel->Text = L"Name:";
			this->SPControlNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SPControlXTextBox
			// 
			this->SPControlXTextBox->Location = System::Drawing::Point(235, 33);
			this->SPControlXTextBox->Name = L"SPControlXTextBox";
			this->SPControlXTextBox->Size = System::Drawing::Size(30, 20);
			this->SPControlXTextBox->TabIndex = 35;
			// 
			// SPControlYLabel
			// 
			this->SPControlYLabel->Location = System::Drawing::Point(271, 16);
			this->SPControlYLabel->Name = L"SPControlYLabel";
			this->SPControlYLabel->Size = System::Drawing::Size(30, 14);
			this->SPControlYLabel->TabIndex = 30;
			this->SPControlYLabel->Text = L"Y";
			this->SPControlYLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SPControlMapIDTextBox
			// 
			this->SPControlMapIDTextBox->Location = System::Drawing::Point(149, 33);
			this->SPControlMapIDTextBox->Name = L"SPControlMapIDTextBox";
			this->SPControlMapIDTextBox->Size = System::Drawing::Size(80, 20);
			this->SPControlMapIDTextBox->TabIndex = 34;
			// 
			// SPControlXLabel
			// 
			this->SPControlXLabel->Location = System::Drawing::Point(235, 16);
			this->SPControlXLabel->Name = L"SPControlXLabel";
			this->SPControlXLabel->Size = System::Drawing::Size(30, 14);
			this->SPControlXLabel->TabIndex = 31;
			this->SPControlXLabel->Text = L"X";
			this->SPControlXLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SPControlNameTextBox
			// 
			this->SPControlNameTextBox->Location = System::Drawing::Point(9, 33);
			this->SPControlNameTextBox->Name = L"SPControlNameTextBox";
			this->SPControlNameTextBox->Size = System::Drawing::Size(134, 20);
			this->SPControlNameTextBox->TabIndex = 33;
			// 
			// SPControlListView
			// 
			this->SPControlListView->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SPControlListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->HeaderMapName, 
				this->HeaderMapID, this->HeaderX, this->HeaderY});
			this->SPControlListView->ContextMenuStrip = this->SPControlContextMenu;
			this->SPControlListView->GridLines = true;
			this->SPControlListView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->SPControlListView->Location = System::Drawing::Point(7, 3);
			this->SPControlListView->MultiSelect = false;
			this->SPControlListView->Name = L"SPControlListView";
			this->SPControlListView->Size = System::Drawing::Size(310, 281);
			this->SPControlListView->TabIndex = 28;
			this->SPControlListView->UseCompatibleStateImageBehavior = false;
			this->SPControlListView->View = System::Windows::Forms::View::Details;
			// 
			// HeaderMapName
			// 
			this->HeaderMapName->Text = L"Name";
			this->HeaderMapName->Width = 160;
			// 
			// HeaderMapID
			// 
			this->HeaderMapID->Text = L"MapID";
			this->HeaderMapID->Width = 80;
			// 
			// HeaderX
			// 
			this->HeaderX->Text = L"X";
			this->HeaderX->Width = 35;
			// 
			// HeaderY
			// 
			this->HeaderY->Text = L"Y";
			this->HeaderY->Width = 35;
			// 
			// SPControlContextMenu
			// 
			this->SPControlContextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->deletePacketToolStripMenuItem});
			this->SPControlContextMenu->Name = L"SPControlContextMenu";
			this->SPControlContextMenu->Size = System::Drawing::Size(146, 26);
			// 
			// deletePacketToolStripMenuItem
			// 
			this->deletePacketToolStripMenuItem->Name = L"deletePacketToolStripMenuItem";
			this->deletePacketToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->deletePacketToolStripMenuItem->Text = L"Delete Packet";
			this->deletePacketToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::SPControlDeleteItem_Click);
			// 
			// InfoTab
			// 
			this->InfoTab->Controls->Add(this->PointerReadGroupBox);
			this->InfoTab->Location = System::Drawing::Point(4, 22);
			this->InfoTab->Name = L"InfoTab";
			this->InfoTab->Padding = System::Windows::Forms::Padding(3);
			this->InfoTab->Size = System::Drawing::Size(326, 396);
			this->InfoTab->TabIndex = 2;
			this->InfoTab->Text = L"Info";
			this->InfoTab->UseVisualStyleBackColor = true;
			// 
			// PointerReadGroupBox
			// 
			this->PointerReadGroupBox->Controls->Add(this->BreathLabel);
			this->PointerReadGroupBox->Controls->Add(this->TubiPointerLabel);
			this->PointerReadGroupBox->Controls->Add(this->MobCountLabel);
			this->PointerReadGroupBox->Controls->Add(this->AttackCountLabel);
			this->PointerReadGroupBox->Controls->Add(this->PeopleCountLabel);
			this->PointerReadGroupBox->Controls->Add(this->ItemCountLabel);
			this->PointerReadGroupBox->Controls->Add(this->CharPosLabel);
			this->PointerReadGroupBox->Location = System::Drawing::Point(5, 5);
			this->PointerReadGroupBox->Name = L"PointerReadGroupBox";
			this->PointerReadGroupBox->Size = System::Drawing::Size(315, 385);
			this->PointerReadGroupBox->TabIndex = 25;
			this->PointerReadGroupBox->TabStop = false;
			this->PointerReadGroupBox->Text = L"Some Pointers Read";
			// 
			// BreathLabel
			// 
			this->BreathLabel->AutoSize = true;
			this->BreathLabel->Location = System::Drawing::Point(6, 94);
			this->BreathLabel->Name = L"BreathLabel";
			this->BreathLabel->Size = System::Drawing::Size(44, 13);
			this->BreathLabel->TabIndex = 26;
			this->BreathLabel->Text = L"Breath: ";
			// 
			// TubiPointerLabel
			// 
			this->TubiPointerLabel->AutoSize = true;
			this->TubiPointerLabel->Location = System::Drawing::Point(6, 81);
			this->TubiPointerLabel->Name = L"TubiPointerLabel";
			this->TubiPointerLabel->Size = System::Drawing::Size(28, 13);
			this->TubiPointerLabel->TabIndex = 25;
			this->TubiPointerLabel->Text = L"Tubi";
			// 
			// MobCountLabel
			// 
			this->MobCountLabel->AutoSize = true;
			this->MobCountLabel->Location = System::Drawing::Point(6, 16);
			this->MobCountLabel->Name = L"MobCountLabel";
			this->MobCountLabel->Size = System::Drawing::Size(51, 13);
			this->MobCountLabel->TabIndex = 20;
			this->MobCountLabel->Text = L"Mobs: 15";
			// 
			// AttackCountLabel
			// 
			this->AttackCountLabel->AutoSize = true;
			this->AttackCountLabel->Location = System::Drawing::Point(6, 68);
			this->AttackCountLabel->Name = L"AttackCountLabel";
			this->AttackCountLabel->Size = System::Drawing::Size(61, 13);
			this->AttackCountLabel->TabIndex = 24;
			this->AttackCountLabel->Text = L"Attacks: 50";
			// 
			// PeopleCountLabel
			// 
			this->PeopleCountLabel->AutoSize = true;
			this->PeopleCountLabel->Location = System::Drawing::Point(6, 29);
			this->PeopleCountLabel->Name = L"PeopleCountLabel";
			this->PeopleCountLabel->Size = System::Drawing::Size(52, 13);
			this->PeopleCountLabel->TabIndex = 21;
			this->PeopleCountLabel->Text = L"People: 0";
			// 
			// ItemCountLabel
			// 
			this->ItemCountLabel->AutoSize = true;
			this->ItemCountLabel->Location = System::Drawing::Point(6, 42);
			this->ItemCountLabel->Name = L"ItemCountLabel";
			this->ItemCountLabel->Size = System::Drawing::Size(56, 13);
			this->ItemCountLabel->TabIndex = 23;
			this->ItemCountLabel->Text = L"Items: 134";
			// 
			// CharPosLabel
			// 
			this->CharPosLabel->AutoSize = true;
			this->CharPosLabel->Location = System::Drawing::Point(6, 55);
			this->CharPosLabel->Name = L"CharPosLabel";
			this->CharPosLabel->Size = System::Drawing::Size(74, 13);
			this->CharPosLabel->TabIndex = 22;
			this->CharPosLabel->Text = L"CharPos: (0,0)";
			// 
			// StatsTimer
			// 
			this->StatsTimer->Enabled = true;
			this->StatsTimer->Interval = 15;
			this->StatsTimer->Tick += gcnew System::EventHandler(this, &MainForm::StatsTimer_Tick);
			// 
			// SpamPacketsTimer
			// 
			this->SpamPacketsTimer->Tick += gcnew System::EventHandler(this, &MainForm::SpamPacketsTimer_Tick);
			// 
			// cbAutoAggro
			// 
			this->cbAutoAggro->AutoSize = true;
			this->cbAutoAggro->Location = System::Drawing::Point(159, 19);
			this->cbAutoAggro->Name = L"cbAutoAggro";
			this->cbAutoAggro->Size = System::Drawing::Size(79, 17);
			this->cbAutoAggro->TabIndex = 8;
			this->cbAutoAggro->Text = L"Auto Aggro";
			this->cbAutoAggro->UseVisualStyleBackColor = true;
			this->cbAutoAggro->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbAutoAggro_CheckedChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(334, 423);
			this->Controls->Add(this->MainTabControl);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->Text = L"WatyBot - V1.8 - CCPLZ! - EMS 86.1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->MainTabControl->ResumeLayout(false);
			this->AutoBotTab->ResumeLayout(false);
			this->AutoBotGroupBox->ResumeLayout(false);
			this->AutoBotGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->AttackTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EXPForeground))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MPForeground))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HPForeground))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EXPBackground))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MPBackground))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HPBackground))->EndInit();
			this->HacksTab->ResumeLayout(false);
			this->gbMiscHacks->ResumeLayout(false);
			this->gbMiscHacks->PerformLayout();
			this->gbCharHacks->ResumeLayout(false);
			this->gbCharHacks->PerformLayout();
			this->MobHacks->ResumeLayout(false);
			this->MobHacks->PerformLayout();
			this->PacketSenderTab->ResumeLayout(false);
			this->EditPacketGroupBox->ResumeLayout(false);
			this->EditPacketGroupBox->PerformLayout();
			this->DeletePacketsGroupBox->ResumeLayout(false);
			this->AddPacketsGroupBox->ResumeLayout(false);
			this->AddPacketsGroupBox->PerformLayout();
			this->SendPacketGroupBox->ResumeLayout(false);
			this->SendPacketGroupBox->PerformLayout();
			this->SPControlTabPage->ResumeLayout(false);
			this->SPControlGroupBox->ResumeLayout(false);
			this->SPControlGroupBox->PerformLayout();
			this->SPControlContextMenu->ResumeLayout(false);
			this->InfoTab->ResumeLayout(false);
			this->PointerReadGroupBox->ResumeLayout(false);
			this->PointerReadGroupBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
#pragma region custom voids
	private: System::Void RefreshComboBoxes();
	private: System::Void RefreshSPControlListView();
	private: System::Void SaveSettings();
	private: System::Void LoadSettings();
#pragma endregion
#pragma region CheckBoxes
	private: System::Void StatsTimer_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void HPCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MPCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AttackCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void StatFixButton_Click(System::Object^  sender, System::EventArgs^  e){}
	private: System::Void AutoLootCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void FixStatsButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoSkill1CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoSkill2CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoSkill3CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoSkill4CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PointerTubiCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);;
	private: System::Void CCPeopleCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void CCTimeCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);	
	private: System::Void SendPacketButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MainTabControl_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	private: System::Void AddPacketButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void DeletePacketButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SpamsPacketButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SelectPacketForEditingComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SavePacketEditButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SpamPacketsTimer_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void CCAttacksCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SavePacketsButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SPControlAddButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SPControlDeleteItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void GetSPControlCoordsButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbFusionAttack_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbNoKB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbPerfectLoot_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbInstantAirLoot_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbVacRight_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbWalkRight_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbJumpRight_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbMobDisarm_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbNoBG_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbJDA_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbPinTyper_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbDojangGodmode_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbUnlimitedMorph_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void cbFasterMobs_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void cbNDAllAttacks_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void cbNoMobs_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void cbAutoAggro_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
};
	}
#pragma endregion