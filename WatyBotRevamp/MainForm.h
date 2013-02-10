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
	private: System::Windows::Forms::GroupBox^  CharacterHacksGroupBox;

	private: System::Windows::Forms::CheckBox^  PinTyperCheckBox;

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

	private: System::Windows::Forms::GroupBox^  MobHacksGroupBox;

	private: System::Windows::Forms::CheckBox^  FullMobDisarmCheckBox;
	private: System::Windows::Forms::GroupBox^  GeneralHacksGroupBox;
	private: System::Windows::Forms::CheckBox^  NoCharKBCheckBox;
	private: System::Windows::Forms::CheckBox^  JumpDownAnywhereCheckBox;
	private: System::Windows::Forms::CheckBox^  FastMobsCheckBox;
	private: System::Windows::Forms::CheckBox^  PerfectLootCheckBox;
	private: System::Windows::Forms::CheckBox^  NDAllAttacksCheckBox;
	private: System::Windows::Forms::CheckBox^  UnlimitedMorphCheckBox;
	private: System::Windows::Forms::CheckBox^  HideDamageCheckBox;
	private: System::Windows::Forms::CheckBox^  CPUHackCheckBox;
	private: System::Windows::Forms::CheckBox^  NoAttackLimitCheckBox;
	private: System::Windows::Forms::CheckBox^  NDMiningCheckBox;
	private: System::Windows::Forms::CheckBox^  HPCheckBox;

	private: System::Windows::Forms::ComboBox^  HPComboBox;
	private: System::Windows::Forms::TextBox^  HPTextBox;
	private: System::Windows::Forms::CheckBox^  UncensorCheckBox;

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

private: System::Windows::Forms::CheckBox^  SevenMissCheckBox;
private: System::Windows::Forms::CheckBox^  NoSkillMovementCheckBox;
private: System::Windows::Forms::Label^  BreathLabel;
private: System::Windows::Forms::CheckBox^  CCPeopleCheckBox;

private: System::Windows::Forms::TextBox^  CCPeopleTextBox;















private: System::Windows::Forms::CheckBox^  NoSwearsCheckBox;
private: System::Windows::Forms::CheckBox^  VacRightCheckBox;
private: System::Windows::Forms::CheckBox^  FusionAttackCheckBox;
private: System::Windows::Forms::CheckBox^  NoBackGroundCheckBox;

private: System::Windows::Forms::CheckBox^  NoMobsCheckBox;
private: System::Windows::Forms::CheckBox^  MobLagCheckBox;
private: System::Windows::Forms::CheckBox^  InstantAirLootCheckBox;
private: System::Windows::Forms::CheckBox^  RainingMobsCheckBox;
private: System::Windows::Forms::CheckBox^  NDMilleCheckBox;
private: System::Windows::Forms::CheckBox^  FLACCCheckBox;
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
private: System::Windows::Forms::CheckBox^  FMACheckBox;

private: System::Windows::Forms::GroupBox^  EditPacketGroupBox;
private: System::Windows::Forms::Button^  SavePacketEditButton;
private: System::Windows::Forms::TextBox^  EditPacketPacketTextBox;
private: System::Windows::Forms::TextBox^  EditPacketNameTextBox;
private: System::Windows::Forms::ComboBox^  SelectPacketForEditingComboBox;
private: System::Windows::Forms::CheckBox^  AutoAggroCheckBox;
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
			this->GeneralHacksGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->FLACCCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->NoBackGroundCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->UncensorCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CPUHackCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->HideDamageCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->PinTyperCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->MobHacksGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->AutoAggroCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->RainingMobsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->MobLagCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->NoMobsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->VacRightCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->FastMobsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->FullMobDisarmCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CharacterHacksGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->FMACheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->NDMilleCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->InstantAirLootCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->FusionAttackCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->NoSwearsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->NoSkillMovementCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->UnlimitedMorphCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->NDAllAttacksCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->NoCharKBCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->SevenMissCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->NDMiningCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->NoAttackLimitCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->PerfectLootCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->JumpDownAnywhereCheckBox = (gcnew System::Windows::Forms::CheckBox());
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
			this->SPControlAddButton = (gcnew System::Windows::Forms::Button());
			this->SPControlMapIDLabel = (gcnew System::Windows::Forms::Label());
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
			this->SPControlCheckBox = (gcnew System::Windows::Forms::CheckBox());
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
			this->GeneralHacksGroupBox->SuspendLayout();
			this->MobHacksGroupBox->SuspendLayout();
			this->CharacterHacksGroupBox->SuspendLayout();
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
			this->FixStatsButton->TabIndex = 32;
			this->FixStatsButton->Text = L"Fix Stats";
			this->FixStatsButton->UseVisualStyleBackColor = true;
			this->FixStatsButton->Click += gcnew System::EventHandler(this, &MainForm::FixStatsButton_Click);
			// 
			// CCAttacksTextBox
			// 
			this->CCAttacksTextBox->Location = System::Drawing::Point(91, 275);
			this->CCAttacksTextBox->Name = L"CCAttacksTextBox";
			this->CCAttacksTextBox->Size = System::Drawing::Size(102, 20);
			this->CCAttacksTextBox->TabIndex = 53;
			this->CCAttacksTextBox->Text = L"90";
			// 
			// CCAttacksCheckBox
			// 
			this->CCAttacksCheckBox->AutoSize = true;
			this->CCAttacksCheckBox->Location = System::Drawing::Point(6, 277);
			this->CCAttacksCheckBox->Name = L"CCAttacksCheckBox";
			this->CCAttacksCheckBox->Size = System::Drawing::Size(65, 17);
			this->CCAttacksCheckBox->TabIndex = 52;
			this->CCAttacksCheckBox->Text = L"Auto CC";
			this->CCAttacksCheckBox->UseVisualStyleBackColor = true;
			this->CCAttacksCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CCAttacksCheckBox_CheckedChanged);
			// 
			// CCTimedTextBox
			// 
			this->CCTimedTextBox->Location = System::Drawing::Point(91, 248);
			this->CCTimedTextBox->Name = L"CCTimedTextBox";
			this->CCTimedTextBox->Size = System::Drawing::Size(102, 20);
			this->CCTimedTextBox->TabIndex = 50;
			this->CCTimedTextBox->Text = L"50";
			// 
			// CCTimedCheckBox
			// 
			this->CCTimedCheckBox->AutoSize = true;
			this->CCTimedCheckBox->Location = System::Drawing::Point(6, 250);
			this->CCTimedCheckBox->Name = L"CCTimedCheckBox";
			this->CCTimedCheckBox->Size = System::Drawing::Size(65, 17);
			this->CCTimedCheckBox->TabIndex = 46;
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
			this->AutoSkill4ComboBox->TabIndex = 42;
			// 
			// CCPeopleTextBox
			// 
			this->CCPeopleTextBox->Location = System::Drawing::Point(91, 221);
			this->CCPeopleTextBox->Name = L"CCPeopleTextBox";
			this->CCPeopleTextBox->Size = System::Drawing::Size(102, 20);
			this->CCPeopleTextBox->TabIndex = 48;
			this->CCPeopleTextBox->Text = L"1";
			// 
			// PointerTubiCheckBox
			// 
			this->PointerTubiCheckBox->AutoSize = true;
			this->PointerTubiCheckBox->Location = System::Drawing::Point(91, 45);
			this->PointerTubiCheckBox->Name = L"PointerTubiCheckBox";
			this->PointerTubiCheckBox->Size = System::Drawing::Size(83, 17);
			this->PointerTubiCheckBox->TabIndex = 45;
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
			this->AutoSkill4CheckBox->TabIndex = 44;
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
			this->CCPeopleCheckBox->TabIndex = 46;
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
			this->AutoSkill4TextBox->TabIndex = 43;
			// 
			// AutoSkill3CheckBox
			// 
			this->AutoSkill3CheckBox->AutoSize = true;
			this->AutoSkill3CheckBox->Location = System::Drawing::Point(6, 170);
			this->AutoSkill3CheckBox->Name = L"AutoSkill3CheckBox";
			this->AutoSkill3CheckBox->Size = System::Drawing::Size(79, 17);
			this->AutoSkill3CheckBox->TabIndex = 41;
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
			this->AutoSkill3TextBox->TabIndex = 40;
			// 
			// AutoSkill3ComboBox
			// 
			this->AutoSkill3ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoSkill3ComboBox->FormattingEnabled = true;
			this->AutoSkill3ComboBox->Location = System::Drawing::Point(202, 168);
			this->AutoSkill3ComboBox->Name = L"AutoSkill3ComboBox";
			this->AutoSkill3ComboBox->Size = System::Drawing::Size(115, 21);
			this->AutoSkill3ComboBox->TabIndex = 39;
			// 
			// AutoSkill2CheckBox
			// 
			this->AutoSkill2CheckBox->AutoSize = true;
			this->AutoSkill2CheckBox->Location = System::Drawing::Point(6, 144);
			this->AutoSkill2CheckBox->Name = L"AutoSkill2CheckBox";
			this->AutoSkill2CheckBox->Size = System::Drawing::Size(79, 17);
			this->AutoSkill2CheckBox->TabIndex = 38;
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
			this->AutoSkill2TextBox->TabIndex = 37;
			// 
			// AutoSkill2ComboBox
			// 
			this->AutoSkill2ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoSkill2ComboBox->FormattingEnabled = true;
			this->AutoSkill2ComboBox->Location = System::Drawing::Point(202, 142);
			this->AutoSkill2ComboBox->Name = L"AutoSkill2ComboBox";
			this->AutoSkill2ComboBox->Size = System::Drawing::Size(115, 21);
			this->AutoSkill2ComboBox->TabIndex = 36;
			// 
			// AttackCheckBox
			// 
			this->AttackCheckBox->AutoSize = true;
			this->AttackCheckBox->Location = System::Drawing::Point(6, 18);
			this->AttackCheckBox->Name = L"AttackCheckBox";
			this->AttackCheckBox->Size = System::Drawing::Size(82, 17);
			this->AttackCheckBox->TabIndex = 24;
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
			this->AutoSkill1CheckBox->TabIndex = 35;
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
			this->HPCheckBox->TabIndex = 15;
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
			this->AutoSkill1TextBox->TabIndex = 34;
			// 
			// HPTextBox
			// 
			this->HPTextBox->Location = System::Drawing::Point(91, 66);
			this->HPTextBox->MaxLength = 10;
			this->HPTextBox->Name = L"HPTextBox";
			this->HPTextBox->Size = System::Drawing::Size(102, 20);
			this->HPTextBox->TabIndex = 16;
			this->HPTextBox->Text = L"7000";
			// 
			// AutoSkill1ComboBox
			// 
			this->AutoSkill1ComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoSkill1ComboBox->FormattingEnabled = true;
			this->AutoSkill1ComboBox->Location = System::Drawing::Point(202, 116);
			this->AutoSkill1ComboBox->Name = L"AutoSkill1ComboBox";
			this->AutoSkill1ComboBox->Size = System::Drawing::Size(115, 21);
			this->AutoSkill1ComboBox->TabIndex = 33;
			// 
			// HPComboBox
			// 
			this->HPComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->HPComboBox->FormattingEnabled = true;
			this->HPComboBox->Location = System::Drawing::Point(202, 66);
			this->HPComboBox->Name = L"HPComboBox";
			this->HPComboBox->Size = System::Drawing::Size(115, 21);
			this->HPComboBox->TabIndex = 17;
			// 
			// MPCheckBox
			// 
			this->MPCheckBox->AutoSize = true;
			this->MPCheckBox->Location = System::Drawing::Point(6, 95);
			this->MPCheckBox->Name = L"MPCheckBox";
			this->MPCheckBox->Size = System::Drawing::Size(67, 17);
			this->MPCheckBox->TabIndex = 21;
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
			this->AutoLootComboBox->TabIndex = 31;
			// 
			// MPTextBox
			// 
			this->MPTextBox->Location = System::Drawing::Point(91, 91);
			this->MPTextBox->MaxLength = 10;
			this->MPTextBox->Name = L"MPTextBox";
			this->MPTextBox->Size = System::Drawing::Size(102, 20);
			this->MPTextBox->TabIndex = 22;
			this->MPTextBox->Text = L"200";
			// 
			// AutoLootCheckBox
			// 
			this->AutoLootCheckBox->AutoSize = true;
			this->AutoLootCheckBox->Location = System::Drawing::Point(6, 45);
			this->AutoLootCheckBox->Name = L"AutoLootCheckBox";
			this->AutoLootCheckBox->Size = System::Drawing::Size(72, 17);
			this->AutoLootCheckBox->TabIndex = 30;
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
			this->MPComboBox->TabIndex = 23;
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
			this->AttackComboBox->TabIndex = 26;
			// 
			// AttackTrackBar
			// 
			this->AttackTrackBar->AutoSize = false;
			this->AttackTrackBar->Location = System::Drawing::Point(91, 19);
			this->AttackTrackBar->Maximum = 500;
			this->AttackTrackBar->Minimum = 1;
			this->AttackTrackBar->Name = L"AttackTrackBar";
			this->AttackTrackBar->Size = System::Drawing::Size(102, 18);
			this->AttackTrackBar->TabIndex = 27;
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
			this->HacksTab->Controls->Add(this->GeneralHacksGroupBox);
			this->HacksTab->Controls->Add(this->MobHacksGroupBox);
			this->HacksTab->Controls->Add(this->CharacterHacksGroupBox);
			this->HacksTab->Location = System::Drawing::Point(4, 22);
			this->HacksTab->Name = L"HacksTab";
			this->HacksTab->Padding = System::Windows::Forms::Padding(3);
			this->HacksTab->Size = System::Drawing::Size(326, 396);
			this->HacksTab->TabIndex = 1;
			this->HacksTab->Text = L"Hacks";
			this->HacksTab->UseVisualStyleBackColor = true;
			// 
			// GeneralHacksGroupBox
			// 
			this->GeneralHacksGroupBox->Controls->Add(this->FLACCCheckBox);
			this->GeneralHacksGroupBox->Controls->Add(this->NoBackGroundCheckBox);
			this->GeneralHacksGroupBox->Controls->Add(this->UncensorCheckBox);
			this->GeneralHacksGroupBox->Controls->Add(this->CPUHackCheckBox);
			this->GeneralHacksGroupBox->Controls->Add(this->HideDamageCheckBox);
			this->GeneralHacksGroupBox->Controls->Add(this->PinTyperCheckBox);
			this->GeneralHacksGroupBox->Location = System::Drawing::Point(7, 186);
			this->GeneralHacksGroupBox->Name = L"GeneralHacksGroupBox";
			this->GeneralHacksGroupBox->Size = System::Drawing::Size(313, 88);
			this->GeneralHacksGroupBox->TabIndex = 2;
			this->GeneralHacksGroupBox->TabStop = false;
			this->GeneralHacksGroupBox->Text = L"General Hacks";
			// 
			// FLACCCheckBox
			// 
			this->FLACCCheckBox->AutoSize = true;
			this->FLACCCheckBox->Location = System::Drawing::Point(164, 65);
			this->FLACCCheckBox->Name = L"FLACCCheckBox";
			this->FLACCCheckBox->Size = System::Drawing::Size(59, 17);
			this->FLACCCheckBox->TabIndex = 7;
			this->FLACCCheckBox->Text = L"FLACC";
			this->FLACCCheckBox->UseVisualStyleBackColor = true;
			this->FLACCCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::FLACCCheckBox_CheckedChanged);
			// 
			// NoBackGroundCheckBox
			// 
			this->NoBackGroundCheckBox->AutoSize = true;
			this->NoBackGroundCheckBox->Location = System::Drawing::Point(6, 65);
			this->NoBackGroundCheckBox->Name = L"NoBackGroundCheckBox";
			this->NoBackGroundCheckBox->Size = System::Drawing::Size(145, 17);
			this->NoBackGroundCheckBox->TabIndex = 6;
			this->NoBackGroundCheckBox->Text = L"No Background + Clouds";
			this->NoBackGroundCheckBox->UseVisualStyleBackColor = true;
			this->NoBackGroundCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoBackGroundCheckBox_CheckedChanged);
			// 
			// UncensorCheckBox
			// 
			this->UncensorCheckBox->AutoSize = true;
			this->UncensorCheckBox->Location = System::Drawing::Point(6, 42);
			this->UncensorCheckBox->Name = L"UncensorCheckBox";
			this->UncensorCheckBox->Size = System::Drawing::Size(78, 17);
			this->UncensorCheckBox->TabIndex = 5;
			this->UncensorCheckBox->Text = L"Uncensore";
			this->UncensorCheckBox->UseVisualStyleBackColor = true;
			this->UncensorCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::UncensorCheckBox_CheckedChanged);
			// 
			// CPUHackCheckBox
			// 
			this->CPUHackCheckBox->AutoSize = true;
			this->CPUHackCheckBox->Location = System::Drawing::Point(164, 19);
			this->CPUHackCheckBox->Name = L"CPUHackCheckBox";
			this->CPUHackCheckBox->Size = System::Drawing::Size(77, 17);
			this->CPUHackCheckBox->TabIndex = 4;
			this->CPUHackCheckBox->Text = L"CPU Hack";
			this->CPUHackCheckBox->UseVisualStyleBackColor = true;
			this->CPUHackCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CPUHackCheckBox_CheckedChanged);
			// 
			// HideDamageCheckBox
			// 
			this->HideDamageCheckBox->AutoSize = true;
			this->HideDamageCheckBox->Enabled = false;
			this->HideDamageCheckBox->Location = System::Drawing::Point(164, 42);
			this->HideDamageCheckBox->Name = L"HideDamageCheckBox";
			this->HideDamageCheckBox->Size = System::Drawing::Size(91, 17);
			this->HideDamageCheckBox->TabIndex = 3;
			this->HideDamageCheckBox->Text = L"Hide Damage";
			this->HideDamageCheckBox->UseVisualStyleBackColor = true;
			this->HideDamageCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::HideDamageCheckBox_CheckedChanged);
			// 
			// PinTyperCheckBox
			// 
			this->PinTyperCheckBox->AutoSize = true;
			this->PinTyperCheckBox->Location = System::Drawing::Point(6, 19);
			this->PinTyperCheckBox->Name = L"PinTyperCheckBox";
			this->PinTyperCheckBox->Size = System::Drawing::Size(71, 17);
			this->PinTyperCheckBox->TabIndex = 0;
			this->PinTyperCheckBox->Text = L"Pin Typer";
			this->PinTyperCheckBox->UseVisualStyleBackColor = true;
			this->PinTyperCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::PinTyperCheckBox_CheckedChanged);
			// 
			// MobHacksGroupBox
			// 
			this->MobHacksGroupBox->Controls->Add(this->AutoAggroCheckBox);
			this->MobHacksGroupBox->Controls->Add(this->RainingMobsCheckBox);
			this->MobHacksGroupBox->Controls->Add(this->MobLagCheckBox);
			this->MobHacksGroupBox->Controls->Add(this->NoMobsCheckBox);
			this->MobHacksGroupBox->Controls->Add(this->VacRightCheckBox);
			this->MobHacksGroupBox->Controls->Add(this->FastMobsCheckBox);
			this->MobHacksGroupBox->Controls->Add(this->FullMobDisarmCheckBox);
			this->MobHacksGroupBox->Location = System::Drawing::Point(7, 280);
			this->MobHacksGroupBox->Name = L"MobHacksGroupBox";
			this->MobHacksGroupBox->Size = System::Drawing::Size(313, 111);
			this->MobHacksGroupBox->TabIndex = 1;
			this->MobHacksGroupBox->TabStop = false;
			this->MobHacksGroupBox->Text = L"Mob Hacks";
			// 
			// AutoAggroCheckBox
			// 
			this->AutoAggroCheckBox->AutoSize = true;
			this->AutoAggroCheckBox->Location = System::Drawing::Point(6, 65);
			this->AutoAggroCheckBox->Name = L"AutoAggroCheckBox";
			this->AutoAggroCheckBox->Size = System::Drawing::Size(79, 17);
			this->AutoAggroCheckBox->TabIndex = 8;
			this->AutoAggroCheckBox->Text = L"Auto Aggro";
			this->AutoAggroCheckBox->UseVisualStyleBackColor = true;
			this->AutoAggroCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoAggroCheckBox_CheckedChanged);
			// 
			// RainingMobsCheckBox
			// 
			this->RainingMobsCheckBox->AutoSize = true;
			this->RainingMobsCheckBox->Location = System::Drawing::Point(164, 42);
			this->RainingMobsCheckBox->Name = L"RainingMobsCheckBox";
			this->RainingMobsCheckBox->Size = System::Drawing::Size(91, 17);
			this->RainingMobsCheckBox->TabIndex = 5;
			this->RainingMobsCheckBox->Text = L"Raining Mobs";
			this->RainingMobsCheckBox->UseVisualStyleBackColor = true;
			this->RainingMobsCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::RainingMobsCheckBox_CheckedChanged);
			// 
			// MobLagCheckBox
			// 
			this->MobLagCheckBox->AutoSize = true;
			this->MobLagCheckBox->Location = System::Drawing::Point(164, 19);
			this->MobLagCheckBox->Name = L"MobLagCheckBox";
			this->MobLagCheckBox->Size = System::Drawing::Size(68, 17);
			this->MobLagCheckBox->TabIndex = 4;
			this->MobLagCheckBox->Text = L"Mob Lag";
			this->MobLagCheckBox->UseVisualStyleBackColor = true;
			this->MobLagCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::MobLagCheckBox_CheckedChanged);
			// 
			// NoMobsCheckBox
			// 
			this->NoMobsCheckBox->AutoSize = true;
			this->NoMobsCheckBox->Location = System::Drawing::Point(164, 65);
			this->NoMobsCheckBox->Name = L"NoMobsCheckBox";
			this->NoMobsCheckBox->Size = System::Drawing::Size(69, 17);
			this->NoMobsCheckBox->TabIndex = 3;
			this->NoMobsCheckBox->Text = L"No Mobs";
			this->NoMobsCheckBox->UseVisualStyleBackColor = true;
			this->NoMobsCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoMobsCheckBox_CheckedChanged);
			// 
			// VacRightCheckBox
			// 
			this->VacRightCheckBox->AutoSize = true;
			this->VacRightCheckBox->Location = System::Drawing::Point(6, 19);
			this->VacRightCheckBox->Name = L"VacRightCheckBox";
			this->VacRightCheckBox->Size = System::Drawing::Size(73, 17);
			this->VacRightCheckBox->TabIndex = 2;
			this->VacRightCheckBox->Text = L"Vac Right";
			this->VacRightCheckBox->UseVisualStyleBackColor = true;
			this->VacRightCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::VacRightCheckBox_CheckedChanged);
			// 
			// FastMobsCheckBox
			// 
			this->FastMobsCheckBox->AutoSize = true;
			this->FastMobsCheckBox->Location = System::Drawing::Point(6, 42);
			this->FastMobsCheckBox->Name = L"FastMobsCheckBox";
			this->FastMobsCheckBox->Size = System::Drawing::Size(75, 17);
			this->FastMobsCheckBox->TabIndex = 1;
			this->FastMobsCheckBox->Text = L"Fast Mobs";
			this->FastMobsCheckBox->UseVisualStyleBackColor = true;
			this->FastMobsCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::FastMobsCheckBox_CheckedChanged);
			// 
			// FullMobDisarmCheckBox
			// 
			this->FullMobDisarmCheckBox->AutoSize = true;
			this->FullMobDisarmCheckBox->Location = System::Drawing::Point(6, 88);
			this->FullMobDisarmCheckBox->Name = L"FullMobDisarmCheckBox";
			this->FullMobDisarmCheckBox->Size = System::Drawing::Size(101, 17);
			this->FullMobDisarmCheckBox->TabIndex = 0;
			this->FullMobDisarmCheckBox->Text = L"Full Mob Disarm";
			this->FullMobDisarmCheckBox->UseVisualStyleBackColor = true;
			this->FullMobDisarmCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::FullMobDisarmCheckBox_CheckedChanged);
			// 
			// CharacterHacksGroupBox
			// 
			this->CharacterHacksGroupBox->Controls->Add(this->FMACheckBox);
			this->CharacterHacksGroupBox->Controls->Add(this->NDMilleCheckBox);
			this->CharacterHacksGroupBox->Controls->Add(this->InstantAirLootCheckBox);
			this->CharacterHacksGroupBox->Controls->Add(this->FusionAttackCheckBox);
			this->CharacterHacksGroupBox->Controls->Add(this->NoSwearsCheckBox);
			this->CharacterHacksGroupBox->Controls->Add(this->NoSkillMovementCheckBox);
			this->CharacterHacksGroupBox->Controls->Add(this->UnlimitedMorphCheckBox);
			this->CharacterHacksGroupBox->Controls->Add(this->NDAllAttacksCheckBox);
			this->CharacterHacksGroupBox->Controls->Add(this->NoCharKBCheckBox);
			this->CharacterHacksGroupBox->Controls->Add(this->SevenMissCheckBox);
			this->CharacterHacksGroupBox->Controls->Add(this->NDMiningCheckBox);
			this->CharacterHacksGroupBox->Controls->Add(this->NoAttackLimitCheckBox);
			this->CharacterHacksGroupBox->Controls->Add(this->PerfectLootCheckBox);
			this->CharacterHacksGroupBox->Controls->Add(this->JumpDownAnywhereCheckBox);
			this->CharacterHacksGroupBox->Location = System::Drawing::Point(7, 6);
			this->CharacterHacksGroupBox->Name = L"CharacterHacksGroupBox";
			this->CharacterHacksGroupBox->Size = System::Drawing::Size(313, 174);
			this->CharacterHacksGroupBox->TabIndex = 0;
			this->CharacterHacksGroupBox->TabStop = false;
			this->CharacterHacksGroupBox->Text = L"Character Hacks";
			// 
			// FMACheckBox
			// 
			this->FMACheckBox->AutoSize = true;
			this->FMACheckBox->Location = System::Drawing::Point(6, 152);
			this->FMACheckBox->Name = L"FMACheckBox";
			this->FMACheckBox->Size = System::Drawing::Size(48, 17);
			this->FMACheckBox->TabIndex = 11;
			this->FMACheckBox->Text = L"FMA";
			this->FMACheckBox->UseVisualStyleBackColor = true;
			this->FMACheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::FMACheckBox_CheckedChanged);
			// 
			// NDMilleCheckBox
			// 
			this->NDMilleCheckBox->AutoSize = true;
			this->NDMilleCheckBox->Location = System::Drawing::Point(164, 152);
			this->NDMilleCheckBox->Name = L"NDMilleCheckBox";
			this->NDMilleCheckBox->Size = System::Drawing::Size(66, 17);
			this->NDMilleCheckBox->TabIndex = 10;
			this->NDMilleCheckBox->Text = L"ND Mille";
			this->NDMilleCheckBox->UseVisualStyleBackColor = true;
			this->NDMilleCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NDMilleCheckBox_CheckedChanged);
			// 
			// InstantAirLootCheckBox
			// 
			this->InstantAirLootCheckBox->AutoSize = true;
			this->InstantAirLootCheckBox->Location = System::Drawing::Point(164, 42);
			this->InstantAirLootCheckBox->Name = L"InstantAirLootCheckBox";
			this->InstantAirLootCheckBox->Size = System::Drawing::Size(97, 17);
			this->InstantAirLootCheckBox->TabIndex = 9;
			this->InstantAirLootCheckBox->Text = L"Instant Air Loot";
			this->InstantAirLootCheckBox->UseVisualStyleBackColor = true;
			this->InstantAirLootCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::InstantAirLootCheckBox_CheckedChanged);
			// 
			// FusionAttackCheckBox
			// 
			this->FusionAttackCheckBox->AutoSize = true;
			this->FusionAttackCheckBox->Location = System::Drawing::Point(6, 130);
			this->FusionAttackCheckBox->Name = L"FusionAttackCheckBox";
			this->FusionAttackCheckBox->Size = System::Drawing::Size(91, 17);
			this->FusionAttackCheckBox->TabIndex = 7;
			this->FusionAttackCheckBox->Text = L"Fusion Attack";
			this->FusionAttackCheckBox->UseVisualStyleBackColor = true;
			this->FusionAttackCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::FusionAttackCheckBox_CheckedChanged);
			// 
			// NoSwearsCheckBox
			// 
			this->NoSwearsCheckBox->AutoSize = true;
			this->NoSwearsCheckBox->Location = System::Drawing::Point(164, 110);
			this->NoSwearsCheckBox->Name = L"NoSwearsCheckBox";
			this->NoSwearsCheckBox->Size = System::Drawing::Size(78, 17);
			this->NoSwearsCheckBox->TabIndex = 6;
			this->NoSwearsCheckBox->Text = L"No Swears";
			this->NoSwearsCheckBox->UseVisualStyleBackColor = true;
			this->NoSwearsCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoSwearsCheckBox_CheckedChanged);
			// 
			// NoSkillMovementCheckBox
			// 
			this->NoSkillMovementCheckBox->AutoSize = true;
			this->NoSkillMovementCheckBox->Location = System::Drawing::Point(164, 130);
			this->NoSkillMovementCheckBox->Name = L"NoSkillMovementCheckBox";
			this->NoSkillMovementCheckBox->Size = System::Drawing::Size(115, 17);
			this->NoSkillMovementCheckBox->TabIndex = 5;
			this->NoSkillMovementCheckBox->Text = L"No Skill Movement";
			this->NoSkillMovementCheckBox->UseVisualStyleBackColor = true;
			this->NoSkillMovementCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoSkillMovementCheckBox_CheckedChanged);
			// 
			// UnlimitedMorphCheckBox
			// 
			this->UnlimitedMorphCheckBox->AutoSize = true;
			this->UnlimitedMorphCheckBox->Location = System::Drawing::Point(6, 65);
			this->UnlimitedMorphCheckBox->Name = L"UnlimitedMorphCheckBox";
			this->UnlimitedMorphCheckBox->Size = System::Drawing::Size(102, 17);
			this->UnlimitedMorphCheckBox->TabIndex = 2;
			this->UnlimitedMorphCheckBox->Text = L"Unlimited Morph";
			this->UnlimitedMorphCheckBox->UseVisualStyleBackColor = true;
			this->UnlimitedMorphCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::UnlimitedMorphCheckBox_CheckedChanged);
			// 
			// NDAllAttacksCheckBox
			// 
			this->NDAllAttacksCheckBox->AutoSize = true;
			this->NDAllAttacksCheckBox->Location = System::Drawing::Point(6, 42);
			this->NDAllAttacksCheckBox->Name = L"NDAllAttacksCheckBox";
			this->NDAllAttacksCheckBox->Size = System::Drawing::Size(101, 17);
			this->NDAllAttacksCheckBox->TabIndex = 1;
			this->NDAllAttacksCheckBox->Text = L"ND - All Attacks";
			this->NDAllAttacksCheckBox->UseVisualStyleBackColor = true;
			this->NDAllAttacksCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NDAllAttacksCheckBox_CheckedChanged);
			// 
			// NoCharKBCheckBox
			// 
			this->NoCharKBCheckBox->AutoSize = true;
			this->NoCharKBCheckBox->Location = System::Drawing::Point(6, 19);
			this->NoCharKBCheckBox->Name = L"NoCharKBCheckBox";
			this->NoCharKBCheckBox->Size = System::Drawing::Size(82, 17);
			this->NoCharKBCheckBox->TabIndex = 0;
			this->NoCharKBCheckBox->Text = L"No Char KB";
			this->NoCharKBCheckBox->UseVisualStyleBackColor = true;
			this->NoCharKBCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoCharKBCheckBox_CheckedChanged);
			// 
			// SevenMissCheckBox
			// 
			this->SevenMissCheckBox->AutoSize = true;
			this->SevenMissCheckBox->Location = System::Drawing::Point(6, 110);
			this->SevenMissCheckBox->Name = L"SevenMissCheckBox";
			this->SevenMissCheckBox->Size = System::Drawing::Size(102, 17);
			this->SevenMissCheckBox->TabIndex = 0;
			this->SevenMissCheckBox->Text = L"7Miss Godmode";
			this->SevenMissCheckBox->UseVisualStyleBackColor = true;
			this->SevenMissCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::SevenMissCheckBox_CheckedChanged);
			// 
			// NDMiningCheckBox
			// 
			this->NDMiningCheckBox->AutoSize = true;
			this->NDMiningCheckBox->Location = System::Drawing::Point(164, 87);
			this->NDMiningCheckBox->Name = L"NDMiningCheckBox";
			this->NDMiningCheckBox->Size = System::Drawing::Size(76, 17);
			this->NDMiningCheckBox->TabIndex = 4;
			this->NDMiningCheckBox->Text = L"ND Mining";
			this->NDMiningCheckBox->UseVisualStyleBackColor = true;
			this->NDMiningCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NDMiningCheckBox_CheckedChanged);
			// 
			// NoAttackLimitCheckBox
			// 
			this->NoAttackLimitCheckBox->AutoSize = true;
			this->NoAttackLimitCheckBox->Location = System::Drawing::Point(6, 87);
			this->NoAttackLimitCheckBox->Name = L"NoAttackLimitCheckBox";
			this->NoAttackLimitCheckBox->Size = System::Drawing::Size(98, 17);
			this->NoAttackLimitCheckBox->TabIndex = 3;
			this->NoAttackLimitCheckBox->Text = L"No Attack Limit";
			this->NoAttackLimitCheckBox->UseVisualStyleBackColor = true;
			this->NoAttackLimitCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoAttackLimitCheckBox_CheckedChanged);
			// 
			// PerfectLootCheckBox
			// 
			this->PerfectLootCheckBox->AutoSize = true;
			this->PerfectLootCheckBox->Location = System::Drawing::Point(164, 19);
			this->PerfectLootCheckBox->Name = L"PerfectLootCheckBox";
			this->PerfectLootCheckBox->Size = System::Drawing::Size(84, 17);
			this->PerfectLootCheckBox->TabIndex = 2;
			this->PerfectLootCheckBox->Text = L"Perfect Loot";
			this->PerfectLootCheckBox->UseVisualStyleBackColor = true;
			this->PerfectLootCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::PerfectLootCheckBox_CheckedChanged);
			// 
			// JumpDownAnywhereCheckBox
			// 
			this->JumpDownAnywhereCheckBox->AutoSize = true;
			this->JumpDownAnywhereCheckBox->Location = System::Drawing::Point(164, 65);
			this->JumpDownAnywhereCheckBox->Name = L"JumpDownAnywhereCheckBox";
			this->JumpDownAnywhereCheckBox->Size = System::Drawing::Size(46, 17);
			this->JumpDownAnywhereCheckBox->TabIndex = 1;
			this->JumpDownAnywhereCheckBox->Text = L"JDA";
			this->JumpDownAnywhereCheckBox->UseVisualStyleBackColor = true;
			this->JumpDownAnywhereCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::JumpDownAnywhereCheckBox_CheckedChanged);
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
			this->SPControlTabPage->Controls->Add(this->SPControlCheckBox);
			this->SPControlTabPage->Location = System::Drawing::Point(4, 22);
			this->SPControlTabPage->Name = L"SPControlTabPage";
			this->SPControlTabPage->Size = System::Drawing::Size(326, 396);
			this->SPControlTabPage->TabIndex = 4;
			this->SPControlTabPage->Text = L"Spawn Control";
			this->SPControlTabPage->UseVisualStyleBackColor = true;
			// 
			// SPControlGroupBox
			// 
			this->SPControlGroupBox->Controls->Add(this->SPControlAddButton);
			this->SPControlGroupBox->Controls->Add(this->SPControlMapIDLabel);
			this->SPControlGroupBox->Controls->Add(this->SPControlYTextBox);
			this->SPControlGroupBox->Controls->Add(this->SPControlNameLabel);
			this->SPControlGroupBox->Controls->Add(this->SPControlXTextBox);
			this->SPControlGroupBox->Controls->Add(this->SPControlYLabel);
			this->SPControlGroupBox->Controls->Add(this->SPControlMapIDTextBox);
			this->SPControlGroupBox->Controls->Add(this->SPControlXLabel);
			this->SPControlGroupBox->Controls->Add(this->SPControlNameTextBox);
			this->SPControlGroupBox->Location = System::Drawing::Point(7, 222);
			this->SPControlGroupBox->Name = L"SPControlGroupBox";
			this->SPControlGroupBox->Size = System::Drawing::Size(307, 91);
			this->SPControlGroupBox->TabIndex = 37;
			this->SPControlGroupBox->TabStop = false;
			this->SPControlGroupBox->Text = L"Add New Location";
			// 
			// SPControlAddButton
			// 
			this->SPControlAddButton->Location = System::Drawing::Point(6, 62);
			this->SPControlAddButton->Name = L"SPControlAddButton";
			this->SPControlAddButton->Size = System::Drawing::Size(295, 23);
			this->SPControlAddButton->TabIndex = 37;
			this->SPControlAddButton->Text = L"Add Location";
			this->SPControlAddButton->UseVisualStyleBackColor = true;
			this->SPControlAddButton->Click += gcnew System::EventHandler(this, &MainForm::SPControlAddButton_Click);
			// 
			// SPControlMapIDLabel
			// 
			this->SPControlMapIDLabel->Location = System::Drawing::Point(106, 16);
			this->SPControlMapIDLabel->Name = L"SPControlMapIDLabel";
			this->SPControlMapIDLabel->Size = System::Drawing::Size(83, 14);
			this->SPControlMapIDLabel->TabIndex = 32;
			this->SPControlMapIDLabel->Text = L"MapID";
			this->SPControlMapIDLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SPControlYTextBox
			// 
			this->SPControlYTextBox->Location = System::Drawing::Point(255, 33);
			this->SPControlYTextBox->Name = L"SPControlYTextBox";
			this->SPControlYTextBox->Size = System::Drawing::Size(45, 20);
			this->SPControlYTextBox->TabIndex = 36;
			// 
			// SPControlNameLabel
			// 
			this->SPControlNameLabel->Location = System::Drawing::Point(6, 16);
			this->SPControlNameLabel->Name = L"SPControlNameLabel";
			this->SPControlNameLabel->Size = System::Drawing::Size(98, 14);
			this->SPControlNameLabel->TabIndex = 29;
			this->SPControlNameLabel->Text = L"Name:";
			this->SPControlNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SPControlXTextBox
			// 
			this->SPControlXTextBox->Location = System::Drawing::Point(197, 33);
			this->SPControlXTextBox->Name = L"SPControlXTextBox";
			this->SPControlXTextBox->Size = System::Drawing::Size(45, 20);
			this->SPControlXTextBox->TabIndex = 35;
			// 
			// SPControlYLabel
			// 
			this->SPControlYLabel->Location = System::Drawing::Point(256, 16);
			this->SPControlYLabel->Name = L"SPControlYLabel";
			this->SPControlYLabel->Size = System::Drawing::Size(59, 14);
			this->SPControlYLabel->TabIndex = 30;
			this->SPControlYLabel->Text = L"Y";
			this->SPControlYLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SPControlMapIDTextBox
			// 
			this->SPControlMapIDTextBox->Location = System::Drawing::Point(105, 33);
			this->SPControlMapIDTextBox->Name = L"SPControlMapIDTextBox";
			this->SPControlMapIDTextBox->Size = System::Drawing::Size(80, 20);
			this->SPControlMapIDTextBox->TabIndex = 34;
			// 
			// SPControlXLabel
			// 
			this->SPControlXLabel->Location = System::Drawing::Point(185, 16);
			this->SPControlXLabel->Name = L"SPControlXLabel";
			this->SPControlXLabel->Size = System::Drawing::Size(68, 14);
			this->SPControlXLabel->TabIndex = 31;
			this->SPControlXLabel->Text = L"X";
			this->SPControlXLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SPControlNameTextBox
			// 
			this->SPControlNameTextBox->Location = System::Drawing::Point(9, 33);
			this->SPControlNameTextBox->Name = L"SPControlNameTextBox";
			this->SPControlNameTextBox->Size = System::Drawing::Size(83, 20);
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
			this->SPControlListView->Size = System::Drawing::Size(310, 213);
			this->SPControlListView->TabIndex = 28;
			this->SPControlListView->UseCompatibleStateImageBehavior = false;
			this->SPControlListView->View = System::Windows::Forms::View::Details;
			// 
			// HeaderMapName
			// 
			this->HeaderMapName->Text = L"Name";
			this->HeaderMapName->Width = 100;
			// 
			// HeaderMapID
			// 
			this->HeaderMapID->Text = L"MapID";
			this->HeaderMapID->Width = 88;
			// 
			// HeaderX
			// 
			this->HeaderX->Text = L"X";
			// 
			// HeaderY
			// 
			this->HeaderY->Text = L"Y";
			// 
			// SPControlContextMenu
			// 
			this->SPControlContextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->deletePacketToolStripMenuItem});
			this->SPControlContextMenu->Name = L"SPControlContextMenu";
			this->SPControlContextMenu->Size = System::Drawing::Size(146, 26);
			// 
			// deletePacketToolStripMenuItem
			// 
			this->deletePacketToolStripMenuItem->Name = L"SPControlDeletePacket";
			this->deletePacketToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->deletePacketToolStripMenuItem->Text = L"Delete Packet";
			this->deletePacketToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::SPControlDeleteItem_Click);
			// 
			// SPControlCheckBox
			// 
			this->SPControlCheckBox->AutoSize = true;
			this->SPControlCheckBox->Location = System::Drawing::Point(7, 371);
			this->SPControlCheckBox->Name = L"SPControlCheckBox";
			this->SPControlCheckBox->Size = System::Drawing::Size(73, 17);
			this->SPControlCheckBox->TabIndex = 27;
			this->SPControlCheckBox->Text = L"SPControl";
			this->SPControlCheckBox->UseVisualStyleBackColor = true;
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
			this->GeneralHacksGroupBox->ResumeLayout(false);
			this->GeneralHacksGroupBox->PerformLayout();
			this->MobHacksGroupBox->ResumeLayout(false);
			this->MobHacksGroupBox->PerformLayout();
			this->CharacterHacksGroupBox->ResumeLayout(false);
			this->CharacterHacksGroupBox->PerformLayout();
			this->PacketSenderTab->ResumeLayout(false);
			this->EditPacketGroupBox->ResumeLayout(false);
			this->EditPacketGroupBox->PerformLayout();
			this->DeletePacketsGroupBox->ResumeLayout(false);
			this->AddPacketsGroupBox->ResumeLayout(false);
			this->AddPacketsGroupBox->PerformLayout();
			this->SendPacketGroupBox->ResumeLayout(false);
			this->SendPacketGroupBox->PerformLayout();
			this->SPControlTabPage->ResumeLayout(false);
			this->SPControlTabPage->PerformLayout();
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
#pragma endregion
#pragma region CheckBoxes
	private: System::Void PinTyperCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MobCountLabel_Click(System::Object^  sender, System::EventArgs^  e){}
	private: System::Void StatsTimer_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void FullMobDisarmCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NoCharKBCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void JumpDownAnywhereCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void FastMobsCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PerfectLootCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NDAllAttacksCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void UnlimitedMorphCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void HideDamageCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void CPUHackCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NoAttackLimitCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NDMiningCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void HPCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void UncensorCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
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
	private: System::Void PointerTubiCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SevenMissCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NoSkillMovementCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void CCPeopleCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void CCTimeCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NoSwearsCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void VacRightCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void FusionAttackCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NoBackGroundCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);	
	private: System::Void NoMobsCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MobLagCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void InstantAirLootCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void RainingMobsCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NDMilleCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void FLACCCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SendPacketButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MainTabControl_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	private: System::Void AddPacketButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void DeletePacketButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void FMACheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SpamsPacketButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SelectPacketForEditingComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SavePacketEditButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoAggroCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SpamPacketsTimer_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SPControlCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void CCAttacksCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SavePacketsButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SPControlAddButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SPControlDeleteItem_Click(System::Object^  sender, System::EventArgs^  e);
	};
	}
#pragma endregion