#pragma once
#pragma region ...
#include <Windows.h>
#include "Settings.h"

namespace WatyBotRevamp {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			this->ddbAutoSkill->Items->AddRange(KeyNames);
			this->ddbPetFeeder->Items->AddRange(KeyNames);
			this->ddbAutoHPKey->Items->AddRange(KeyNames);
			this->ddbAutoLootKey->Items->AddRange(KeyNames);
			this->ddbAutoMPKey->Items->AddRange(KeyNames);
			this->ddbAutoAttackKey->Items->AddRange(KeyNames);
			this->ddbHotKeySendPacket->Items->AddRange(KeyNames);
			this->ddbHotKeyCCPeople->Items->AddRange(KeyNames);
			this->ddbHotKeyFMA->Items->AddRange(KeyNames);
			this->ddbHotKeyLoot->Items->AddRange(KeyNames);
			this->ddbHotKeyAttack->Items->AddRange(KeyNames);
			this->ddbHotKeyMouseFly->Items->AddRange(KeyNames);

			//Create the Waty directory in %appdata%
			auto Path = Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData), "Waty");
			if (!Directory::Exists(Path)) Directory::CreateDirectory(Path);
			this->SettingsWatcher->Path = Path;
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
	private:
		System::Windows::Forms::TabControl^ MainTabControl;
		System::Windows::Forms::TabPage^ AutoBotTab;
		System::Windows::Forms::TabPage^ HacksTab;
		System::Windows::Forms::Timer^ StatsTimer;
		System::Windows::Forms::Label^ HPLabel;
		System::Windows::Forms::Label^ MPLabel;
		System::Windows::Forms::Label^ EXPLabel;
		System::Windows::Forms::PictureBox^ HPBackground;
		System::Windows::Forms::PictureBox^ MPBackground;
		System::Windows::Forms::PictureBox^ EXPForeground;
		System::Windows::Forms::PictureBox^ MPForeground;
		System::Windows::Forms::PictureBox^ HPForeground;
		System::Windows::Forms::PictureBox^ EXPBackground;
		System::Windows::Forms::CheckBox^ cbAutoHP;
		System::Windows::Forms::ComboBox^ ddbAutoHPKey;
		System::Windows::Forms::ComboBox^ ddbAutoMPKey;
		System::Windows::Forms::CheckBox^ cbAutoMP;
		System::Windows::Forms::ComboBox^ ddbAutoAttackKey;
		System::Windows::Forms::CheckBox^ cbAutoAttack;
		System::Windows::Forms::TabPage^ InfoTab;
		System::Windows::Forms::Label^ AttackCountLabel;
		System::Windows::Forms::Label^ ItemCountLabel;
		System::Windows::Forms::Label^ CharPosLabel;
		System::Windows::Forms::Label^ PeopleCountLabel;
		System::Windows::Forms::Label^ MobCountLabel;
		System::Windows::Forms::GroupBox^ gbPointers;
		System::Windows::Forms::CheckBox^ cbAutoLoot;
		System::Windows::Forms::ComboBox^ ddbAutoLootKey;
		System::Windows::Forms::CheckBox^ cbPetFeeder;
		System::Windows::Forms::ComboBox^ ddbPetFeeder;
		System::Windows::Forms::GroupBox^ AutoBotGroupBox;
		System::Windows::Forms::Label^ BreathLabel;
		System::Windows::Forms::CheckBox^ cbCCPeople;
		System::Windows::Forms::TabPage^ PacketSenderTab;
		System::Windows::Forms::TabPage^ SPControlTabPage;
		System::Windows::Forms::CheckBox^ cbSPControl;
		System::Windows::Forms::CheckBox^ cbCCAttacks;
		System::Windows::Forms::CheckBox^ cbCCTimed;
		System::Windows::Forms::Label^ CCTimedLabel;
		System::Windows::Forms::Label^ CCPeopleLabel;
		System::Windows::Forms::Label^ CCAttacksLabel;
		System::Windows::Forms::ListView^ lvSPControl;
		System::Windows::Forms::ColumnHeader^ HeaderMapName;
		System::Windows::Forms::ColumnHeader^ HeaderMapID;
		System::Windows::Forms::ColumnHeader^ HeaderX;
		System::Windows::Forms::ColumnHeader^ HeaderY;
		System::Windows::Forms::Label^ SPControlNameLabel;
		System::Windows::Forms::Label^ SPControlMapIDLabel;
		System::Windows::Forms::Label^ SPControlXLabel;
		System::Windows::Forms::Label^ SPControlYLabel;
		System::Windows::Forms::GroupBox^ gbNewSPCLocation;
		System::Windows::Forms::TextBox^ tbSPCName;
		System::Windows::Forms::Button^ bAddSPCLocation;
		System::Windows::Forms::ContextMenuStrip^ SPControlContextMenu;
		System::Windows::Forms::ToolStripMenuItem^ deleteSPControlToolStripMenuItem;
		System::Windows::Forms::Button^ bSPCGetCurrent;
		System::Windows::Forms::GroupBox^ MobHacks;
		System::Windows::Forms::CheckBox^ PerfectLoot;
		System::Windows::Forms::CheckBox^ FusionAttack;
		System::Windows::Forms::GroupBox^ gbMiscHacks;
		System::Windows::Forms::CheckBox^ JDA;
		System::Windows::Forms::CheckBox^ NoBackground;
		System::Windows::Forms::GroupBox^ gbCharHacks;
		System::Windows::Forms::CheckBox^ VacRight;
		System::Windows::Forms::CheckBox^ JumpRight;
		System::Windows::Forms::CheckBox^ WalkRight;
		System::Windows::Forms::CheckBox^ PinPicTyper;
		System::Windows::Forms::CheckBox^ NoKB;
		System::Windows::Forms::CheckBox^ MobDisarm;
		System::Windows::Forms::CheckBox^ DojangGodmode;
		System::Windows::Forms::CheckBox^ UnlimitedMorph;
		System::Windows::Forms::CheckBox^ FasterMobs;
		System::Windows::Forms::CheckBox^ NDAllAttacks;
		System::Windows::Forms::CheckBox^ NoMobs;
		System::Windows::Forms::CheckBox^ UnlimitedAttack;
		System::Windows::Forms::CheckBox^ SitHack;
		System::Windows::Forms::CheckBox^ SecondGodmode;
		System::Windows::Forms::CheckBox^ LogoSkipper;
		System::Windows::Forms::CheckBox^ ViewSwears;
		System::Windows::Forms::CheckBox^ ItemVac;
		System::Windows::Forms::CheckBox^ FMA;
		System::Windows::Forms::CheckBox^ ScareMobs;
		System::Windows::Forms::CheckBox^ FaceLeftAfterCC;
		System::Windows::Forms::CheckBox^ CPUHack;
		System::Windows::Forms::Label^ lSAWSIL;
		System::Windows::Forms::ComboBox^ ddbTimedType;
		System::Windows::Forms::ComboBox^ ddbAttacksType;
		System::Windows::Forms::ComboBox^ ddbPeopleType;
		System::Windows::Forms::GroupBox^ gbHotKeys;
		System::Windows::Forms::CheckBox^ cbHotKeyAttack;
		System::Windows::Forms::ComboBox^ ddbHotKeyAttack;
		System::Windows::Forms::ComboBox^ ddbHotKeyLoot;
		System::Windows::Forms::CheckBox^ cbHotKeyLoot;
		System::Windows::Forms::Label^ lMapID;
		System::Windows::Forms::NumericUpDown^ nudSAWSIL;
		System::Windows::Forms::NumericUpDown^ nudAutoLoot;
		System::Windows::Forms::NumericUpDown^ nudAutoAttack;
		System::Windows::Forms::NumericUpDown^ nudAutoMP;
		System::Windows::Forms::NumericUpDown^ nudAutoHP;
		System::Windows::Forms::NumericUpDown^ nudCCAttacks;
		System::Windows::Forms::NumericUpDown^ nudCCTimed;
		System::Windows::Forms::NumericUpDown^ nudCCPeople;
		System::Windows::Forms::NumericUpDown^ nudPetFeeder;
		System::Windows::Forms::CheckBox^ DisableFinalAttack;
		System::Windows::Forms::CheckBox^ AutoAggro;
		System::Windows::Forms::Button^ bSaveSettings;
		System::Windows::Forms::ComboBox^ ddbHotKeyFMA;
		System::Windows::Forms::CheckBox^ cbHotKeyFMA;
		System::Windows::Forms::ComboBox^ ddbHotKeyCCPeople;
		System::Windows::Forms::CheckBox^ cbHotKeyCCPeople;
		System::Windows::Forms::CheckBox^ NDMining;
		System::Windows::Forms::ComboBox^ ddbHotKeySendPacket;
		System::Windows::Forms::CheckBox^ cbHotKeySendPacket;
		System::Windows::Forms::CheckBox^ HideDamage;
		System::Windows::Forms::CheckBox^ MercedesCombo;
		System::Windows::Forms::ToolTip^ InfoToolTip;
		System::Windows::Forms::CheckBox^  cbIFS;
		System::Windows::Forms::CheckBox^ NoFadeStages;
		System::Windows::Forms::CheckBox^ NoCCBoxes;
		System::Windows::Forms::CheckBox^ MouseFly;
		System::Windows::Forms::NumericUpDown^ nudIceGuard;
		System::Windows::Forms::CheckBox^ IceGuard;
		System::Windows::Forms::NumericUpDown^ nudSPCY;
		System::Windows::Forms::NumericUpDown^ nudSPCX;
		System::Windows::Forms::NumericUpDown^ nudSPCMapId;
		System::Windows::Forms::ContextMenuStrip^ AutoSkillContextMenu;
		System::Windows::Forms::ToolStripMenuItem^ castToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ deleteToolStripMenuItem;
		System::Windows::Forms::Label^ lPetFullness;
		System::Windows::Forms::GroupBox^ gbAutoSkill;
		System::Windows::Forms::ComboBox^ ddbAutoSkill;
		System::Windows::Forms::NumericUpDown^ nudAutoSkill;
		System::Windows::Forms::TextBox^ tbAutoSkill;
		System::Windows::Forms::Button^ bAutoSkill;
		System::Windows::Forms::ListView^ lvAutoSkill;
		System::Windows::Forms::ColumnHeader^ hName;
		System::Windows::Forms::ColumnHeader^ hInterval;
		System::Windows::Forms::ColumnHeader^ hKey;
		System::Windows::Forms::Timer^ tAutoAttack;
		System::Windows::Forms::Timer^ tAutoLoot;
		System::Windows::Forms::Timer^ tTimedCC;
		System::Windows::Forms::ListView^ lvPackets;
		System::Windows::Forms::ColumnHeader^ hPacketName;
		System::Windows::Forms::ColumnHeader^ hPacket;
		System::Windows::Forms::Button^ bAddPacket;
		System::Windows::Forms::ContextMenuStrip^ PacketContextMenu;
		System::Windows::Forms::ToolStripMenuItem^ bSendPacket;
		System::Windows::Forms::ToolStripMenuItem^ bDeletePacket;
		System::Windows::Forms::ComboBox^ ddbHotKeyMouseFly;
		System::Windows::Forms::CheckBox^ cbHotKeyMouseFly;
		System::Windows::Forms::ToolStripMenuItem^ editLocationToolStripMenuItem;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::ToolStripMenuItem^ bEditPacket;
		System::IO::FileSystemWatcher^ SettingsWatcher;
		System::Windows::Forms::CheckBox^ cbLockItemVac;
		System::Windows::Forms::CheckBox^ cbOLWNA;
		System::Windows::Forms::Label^  lMSCRC;
		System::Windows::Forms::Label^  lInGame;
		System::Windows::Forms::Label^  lChannel;
		System::Windows::Forms::ComboBox^  ddbIFS;
		System::ComponentModel::IContainer^ components;
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
			this->gbAutoSkill = (gcnew System::Windows::Forms::GroupBox());
			this->ddbAutoSkill = (gcnew System::Windows::Forms::ComboBox());
			this->nudAutoSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->tbAutoSkill = (gcnew System::Windows::Forms::TextBox());
			this->bAutoSkill = (gcnew System::Windows::Forms::Button());
			this->lvAutoSkill = (gcnew System::Windows::Forms::ListView());
			this->hName = (gcnew System::Windows::Forms::ColumnHeader());
			this->hInterval = (gcnew System::Windows::Forms::ColumnHeader());
			this->hKey = (gcnew System::Windows::Forms::ColumnHeader());
			this->AutoSkillContextMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->castToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AutoBotGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->cbOLWNA = (gcnew System::Windows::Forms::CheckBox());
			this->nudCCAttacks = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudCCTimed = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudCCPeople = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudPetFeeder = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudAutoMP = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudAutoHP = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudAutoLoot = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudAutoAttack = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudSAWSIL = (gcnew System::Windows::Forms::NumericUpDown());
			this->ddbTimedType = (gcnew System::Windows::Forms::ComboBox());
			this->ddbAttacksType = (gcnew System::Windows::Forms::ComboBox());
			this->ddbPeopleType = (gcnew System::Windows::Forms::ComboBox());
			this->lSAWSIL = (gcnew System::Windows::Forms::Label());
			this->CCAttacksLabel = (gcnew System::Windows::Forms::Label());
			this->CCTimedLabel = (gcnew System::Windows::Forms::Label());
			this->CCPeopleLabel = (gcnew System::Windows::Forms::Label());
			this->cbCCAttacks = (gcnew System::Windows::Forms::CheckBox());
			this->cbCCTimed = (gcnew System::Windows::Forms::CheckBox());
			this->cbCCPeople = (gcnew System::Windows::Forms::CheckBox());
			this->cbAutoAttack = (gcnew System::Windows::Forms::CheckBox());
			this->cbPetFeeder = (gcnew System::Windows::Forms::CheckBox());
			this->cbAutoHP = (gcnew System::Windows::Forms::CheckBox());
			this->ddbPetFeeder = (gcnew System::Windows::Forms::ComboBox());
			this->ddbAutoHPKey = (gcnew System::Windows::Forms::ComboBox());
			this->cbAutoMP = (gcnew System::Windows::Forms::CheckBox());
			this->ddbAutoLootKey = (gcnew System::Windows::Forms::ComboBox());
			this->cbAutoLoot = (gcnew System::Windows::Forms::CheckBox());
			this->ddbAutoMPKey = (gcnew System::Windows::Forms::ComboBox());
			this->ddbAutoAttackKey = (gcnew System::Windows::Forms::ComboBox());
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
			this->MouseFly = (gcnew System::Windows::Forms::CheckBox());
			this->NoCCBoxes = (gcnew System::Windows::Forms::CheckBox());
			this->NoFadeStages = (gcnew System::Windows::Forms::CheckBox());
			this->HideDamage = (gcnew System::Windows::Forms::CheckBox());
			this->CPUHack = (gcnew System::Windows::Forms::CheckBox());
			this->FaceLeftAfterCC = (gcnew System::Windows::Forms::CheckBox());
			this->ViewSwears = (gcnew System::Windows::Forms::CheckBox());
			this->LogoSkipper = (gcnew System::Windows::Forms::CheckBox());
			this->SitHack = (gcnew System::Windows::Forms::CheckBox());
			this->PinPicTyper = (gcnew System::Windows::Forms::CheckBox());
			this->JDA = (gcnew System::Windows::Forms::CheckBox());
			this->NoBackground = (gcnew System::Windows::Forms::CheckBox());
			this->gbCharHacks = (gcnew System::Windows::Forms::GroupBox());
			this->ddbIFS = (gcnew System::Windows::Forms::ComboBox());
			this->cbLockItemVac = (gcnew System::Windows::Forms::CheckBox());
			this->nudIceGuard = (gcnew System::Windows::Forms::NumericUpDown());
			this->IceGuard = (gcnew System::Windows::Forms::CheckBox());
			this->cbIFS = (gcnew System::Windows::Forms::CheckBox());
			this->MercedesCombo = (gcnew System::Windows::Forms::CheckBox());
			this->NDMining = (gcnew System::Windows::Forms::CheckBox());
			this->DisableFinalAttack = (gcnew System::Windows::Forms::CheckBox());
			this->FMA = (gcnew System::Windows::Forms::CheckBox());
			this->UnlimitedAttack = (gcnew System::Windows::Forms::CheckBox());
			this->ItemVac = (gcnew System::Windows::Forms::CheckBox());
			this->SecondGodmode = (gcnew System::Windows::Forms::CheckBox());
			this->NDAllAttacks = (gcnew System::Windows::Forms::CheckBox());
			this->UnlimitedMorph = (gcnew System::Windows::Forms::CheckBox());
			this->DojangGodmode = (gcnew System::Windows::Forms::CheckBox());
			this->NoKB = (gcnew System::Windows::Forms::CheckBox());
			this->FusionAttack = (gcnew System::Windows::Forms::CheckBox());
			this->PerfectLoot = (gcnew System::Windows::Forms::CheckBox());
			this->MobHacks = (gcnew System::Windows::Forms::GroupBox());
			this->AutoAggro = (gcnew System::Windows::Forms::CheckBox());
			this->ScareMobs = (gcnew System::Windows::Forms::CheckBox());
			this->NoMobs = (gcnew System::Windows::Forms::CheckBox());
			this->FasterMobs = (gcnew System::Windows::Forms::CheckBox());
			this->MobDisarm = (gcnew System::Windows::Forms::CheckBox());
			this->JumpRight = (gcnew System::Windows::Forms::CheckBox());
			this->WalkRight = (gcnew System::Windows::Forms::CheckBox());
			this->VacRight = (gcnew System::Windows::Forms::CheckBox());
			this->PacketSenderTab = (gcnew System::Windows::Forms::TabPage());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->bAddPacket = (gcnew System::Windows::Forms::Button());
			this->lvPackets = (gcnew System::Windows::Forms::ListView());
			this->hPacketName = (gcnew System::Windows::Forms::ColumnHeader());
			this->hPacket = (gcnew System::Windows::Forms::ColumnHeader());
			this->PacketContextMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->bSendPacket = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bEditPacket = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bDeletePacket = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SPControlTabPage = (gcnew System::Windows::Forms::TabPage());
			this->gbNewSPCLocation = (gcnew System::Windows::Forms::GroupBox());
			this->nudSPCY = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudSPCX = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudSPCMapId = (gcnew System::Windows::Forms::NumericUpDown());
			this->bSPCGetCurrent = (gcnew System::Windows::Forms::Button());
			this->bAddSPCLocation = (gcnew System::Windows::Forms::Button());
			this->SPControlMapIDLabel = (gcnew System::Windows::Forms::Label());
			this->cbSPControl = (gcnew System::Windows::Forms::CheckBox());
			this->SPControlNameLabel = (gcnew System::Windows::Forms::Label());
			this->SPControlYLabel = (gcnew System::Windows::Forms::Label());
			this->SPControlXLabel = (gcnew System::Windows::Forms::Label());
			this->tbSPCName = (gcnew System::Windows::Forms::TextBox());
			this->lvSPControl = (gcnew System::Windows::Forms::ListView());
			this->HeaderMapName = (gcnew System::Windows::Forms::ColumnHeader());
			this->HeaderMapID = (gcnew System::Windows::Forms::ColumnHeader());
			this->HeaderX = (gcnew System::Windows::Forms::ColumnHeader());
			this->HeaderY = (gcnew System::Windows::Forms::ColumnHeader());
			this->SPControlContextMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->editLocationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteSPControlToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->InfoTab = (gcnew System::Windows::Forms::TabPage());
			this->bSaveSettings = (gcnew System::Windows::Forms::Button());
			this->gbHotKeys = (gcnew System::Windows::Forms::GroupBox());
			this->ddbHotKeyMouseFly = (gcnew System::Windows::Forms::ComboBox());
			this->cbHotKeyMouseFly = (gcnew System::Windows::Forms::CheckBox());
			this->ddbHotKeySendPacket = (gcnew System::Windows::Forms::ComboBox());
			this->cbHotKeySendPacket = (gcnew System::Windows::Forms::CheckBox());
			this->ddbHotKeyCCPeople = (gcnew System::Windows::Forms::ComboBox());
			this->cbHotKeyCCPeople = (gcnew System::Windows::Forms::CheckBox());
			this->ddbHotKeyFMA = (gcnew System::Windows::Forms::ComboBox());
			this->cbHotKeyFMA = (gcnew System::Windows::Forms::CheckBox());
			this->ddbHotKeyLoot = (gcnew System::Windows::Forms::ComboBox());
			this->cbHotKeyLoot = (gcnew System::Windows::Forms::CheckBox());
			this->ddbHotKeyAttack = (gcnew System::Windows::Forms::ComboBox());
			this->cbHotKeyAttack = (gcnew System::Windows::Forms::CheckBox());
			this->gbPointers = (gcnew System::Windows::Forms::GroupBox());
			this->lChannel = (gcnew System::Windows::Forms::Label());
			this->lMSCRC = (gcnew System::Windows::Forms::Label());
			this->lInGame = (gcnew System::Windows::Forms::Label());
			this->lPetFullness = (gcnew System::Windows::Forms::Label());
			this->lMapID = (gcnew System::Windows::Forms::Label());
			this->BreathLabel = (gcnew System::Windows::Forms::Label());
			this->MobCountLabel = (gcnew System::Windows::Forms::Label());
			this->AttackCountLabel = (gcnew System::Windows::Forms::Label());
			this->PeopleCountLabel = (gcnew System::Windows::Forms::Label());
			this->ItemCountLabel = (gcnew System::Windows::Forms::Label());
			this->CharPosLabel = (gcnew System::Windows::Forms::Label());
			this->StatsTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->InfoToolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->tAutoAttack = (gcnew System::Windows::Forms::Timer(this->components));
			this->tAutoLoot = (gcnew System::Windows::Forms::Timer(this->components));
			this->tTimedCC = (gcnew System::Windows::Forms::Timer(this->components));
			this->SettingsWatcher = (gcnew System::IO::FileSystemWatcher());
			this->MainTabControl->SuspendLayout();
			this->AutoBotTab->SuspendLayout();
			this->gbAutoSkill->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudAutoSkill))->BeginInit();
			this->AutoSkillContextMenu->SuspendLayout();
			this->AutoBotGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudCCAttacks))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudCCTimed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudCCPeople))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudPetFeeder))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudAutoMP))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudAutoHP))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudAutoLoot))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudAutoAttack))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudSAWSIL))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EXPForeground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MPForeground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HPForeground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->EXPBackground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MPBackground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->HPBackground))->BeginInit();
			this->HacksTab->SuspendLayout();
			this->gbMiscHacks->SuspendLayout();
			this->gbCharHacks->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudIceGuard))->BeginInit();
			this->MobHacks->SuspendLayout();
			this->PacketSenderTab->SuspendLayout();
			this->PacketContextMenu->SuspendLayout();
			this->SPControlTabPage->SuspendLayout();
			this->gbNewSPCLocation->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudSPCY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudSPCX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudSPCMapId))->BeginInit();
			this->SPControlContextMenu->SuspendLayout();
			this->InfoTab->SuspendLayout();
			this->gbHotKeys->SuspendLayout();
			this->gbPointers->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SettingsWatcher))->BeginInit();
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
			this->MainTabControl->Size = System::Drawing::Size(334, 568);
			this->MainTabControl->TabIndex = 0;
			this->MainTabControl->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::MainTabControl_SelectedIndexChanged);
			// 
			// AutoBotTab
			// 
			this->AutoBotTab->Controls->Add(this->gbAutoSkill);
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
			this->AutoBotTab->Size = System::Drawing::Size(326, 542);
			this->AutoBotTab->TabIndex = 0;
			this->AutoBotTab->Text = L"AutoBot";
			this->AutoBotTab->UseVisualStyleBackColor = true;
			// 
			// gbAutoSkill
			// 
			this->gbAutoSkill->Controls->Add(this->ddbAutoSkill);
			this->gbAutoSkill->Controls->Add(this->nudAutoSkill);
			this->gbAutoSkill->Controls->Add(this->tbAutoSkill);
			this->gbAutoSkill->Controls->Add(this->bAutoSkill);
			this->gbAutoSkill->Controls->Add(this->lvAutoSkill);
			this->gbAutoSkill->Location = System::Drawing::Point(0, 300);
			this->gbAutoSkill->Name = L"gbAutoSkill";
			this->gbAutoSkill->Size = System::Drawing::Size(325, 185);
			this->gbAutoSkill->TabIndex = 37;
			this->gbAutoSkill->TabStop = false;
			this->gbAutoSkill->Text = L"AutoSkill";
			// 
			// ddbAutoSkill
			// 
			this->ddbAutoSkill->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbAutoSkill->FormattingEnabled = true;
			this->ddbAutoSkill->Location = System::Drawing::Point(242, 156);
			this->ddbAutoSkill->Name = L"ddbAutoSkill";
			this->ddbAutoSkill->Size = System::Drawing::Size(76, 21);
			this->ddbAutoSkill->TabIndex = 90;
			// 
			// nudAutoSkill
			// 
			this->nudAutoSkill->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->nudAutoSkill->Location = System::Drawing::Point(163, 156);
			this->nudAutoSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->nudAutoSkill->Name = L"nudAutoSkill";
			this->nudAutoSkill->Size = System::Drawing::Size(75, 20);
			this->nudAutoSkill->TabIndex = 89;
			// 
			// tbAutoSkill
			// 
			this->tbAutoSkill->Location = System::Drawing::Point(49, 157);
			this->tbAutoSkill->Name = L"tbAutoSkill";
			this->tbAutoSkill->Size = System::Drawing::Size(108, 20);
			this->tbAutoSkill->TabIndex = 88;
			// 
			// bAutoSkill
			// 
			this->bAutoSkill->Location = System::Drawing::Point(7, 156);
			this->bAutoSkill->Name = L"bAutoSkill";
			this->bAutoSkill->Size = System::Drawing::Size(35, 23);
			this->bAutoSkill->TabIndex = 87;
			this->bAutoSkill->Text = L"Add";
			this->bAutoSkill->UseVisualStyleBackColor = true;
			this->bAutoSkill->Click += gcnew System::EventHandler(this, &MainForm::bAutoSkill_Click);
			// 
			// lvAutoSkill
			// 
			this->lvAutoSkill->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lvAutoSkill->CheckBoxes = true;
			this->lvAutoSkill->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->hName, this->hInterval,
					this->hKey
			});
			this->lvAutoSkill->ContextMenuStrip = this->AutoSkillContextMenu;
			this->lvAutoSkill->FullRowSelect = true;
			this->lvAutoSkill->Location = System::Drawing::Point(7, 19);
			this->lvAutoSkill->MultiSelect = false;
			this->lvAutoSkill->Name = L"lvAutoSkill";
			this->lvAutoSkill->Size = System::Drawing::Size(310, 131);
			this->lvAutoSkill->TabIndex = 86;
			this->lvAutoSkill->UseCompatibleStateImageBehavior = false;
			this->lvAutoSkill->View = System::Windows::Forms::View::Details;
			this->lvAutoSkill->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &MainForm::lvAutoSkill_ItemCheck);
			this->lvAutoSkill->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::lvAutoSkill_KeyDown);
			// 
			// hName
			// 
			this->hName->Text = L"Name";
			this->hName->Width = 160;
			// 
			// hInterval
			// 
			this->hInterval->Text = L"Interval";
			this->hInterval->Width = 75;
			// 
			// hKey
			// 
			this->hKey->Text = L"Key";
			this->hKey->Width = 75;
			// 
			// AutoSkillContextMenu
			// 
			this->AutoSkillContextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->castToolStripMenuItem,
					this->deleteToolStripMenuItem
			});
			this->AutoSkillContextMenu->Name = L"AutoSkillContextMenu";
			this->AutoSkillContextMenu->Size = System::Drawing::Size(108, 48);
			// 
			// castToolStripMenuItem
			// 
			this->castToolStripMenuItem->Name = L"castToolStripMenuItem";
			this->castToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->castToolStripMenuItem->Text = L"Cast";
			this->castToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::castToolStripMenuItem_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->deleteToolStripMenuItem->Text = L"Delete";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::deleteToolStripMenuItem_Click);
			// 
			// AutoBotGroupBox
			// 
			this->AutoBotGroupBox->Controls->Add(this->cbOLWNA);
			this->AutoBotGroupBox->Controls->Add(this->nudCCAttacks);
			this->AutoBotGroupBox->Controls->Add(this->nudCCTimed);
			this->AutoBotGroupBox->Controls->Add(this->nudCCPeople);
			this->AutoBotGroupBox->Controls->Add(this->nudPetFeeder);
			this->AutoBotGroupBox->Controls->Add(this->nudAutoMP);
			this->AutoBotGroupBox->Controls->Add(this->nudAutoHP);
			this->AutoBotGroupBox->Controls->Add(this->nudAutoLoot);
			this->AutoBotGroupBox->Controls->Add(this->nudAutoAttack);
			this->AutoBotGroupBox->Controls->Add(this->nudSAWSIL);
			this->AutoBotGroupBox->Controls->Add(this->ddbTimedType);
			this->AutoBotGroupBox->Controls->Add(this->ddbAttacksType);
			this->AutoBotGroupBox->Controls->Add(this->ddbPeopleType);
			this->AutoBotGroupBox->Controls->Add(this->lSAWSIL);
			this->AutoBotGroupBox->Controls->Add(this->CCAttacksLabel);
			this->AutoBotGroupBox->Controls->Add(this->CCTimedLabel);
			this->AutoBotGroupBox->Controls->Add(this->CCPeopleLabel);
			this->AutoBotGroupBox->Controls->Add(this->cbCCAttacks);
			this->AutoBotGroupBox->Controls->Add(this->cbCCTimed);
			this->AutoBotGroupBox->Controls->Add(this->cbCCPeople);
			this->AutoBotGroupBox->Controls->Add(this->cbAutoAttack);
			this->AutoBotGroupBox->Controls->Add(this->cbPetFeeder);
			this->AutoBotGroupBox->Controls->Add(this->cbAutoHP);
			this->AutoBotGroupBox->Controls->Add(this->ddbPetFeeder);
			this->AutoBotGroupBox->Controls->Add(this->ddbAutoHPKey);
			this->AutoBotGroupBox->Controls->Add(this->cbAutoMP);
			this->AutoBotGroupBox->Controls->Add(this->ddbAutoLootKey);
			this->AutoBotGroupBox->Controls->Add(this->cbAutoLoot);
			this->AutoBotGroupBox->Controls->Add(this->ddbAutoMPKey);
			this->AutoBotGroupBox->Controls->Add(this->ddbAutoAttackKey);
			this->AutoBotGroupBox->Location = System::Drawing::Point(0, 70);
			this->AutoBotGroupBox->Name = L"AutoBotGroupBox";
			this->AutoBotGroupBox->Size = System::Drawing::Size(325, 224);
			this->AutoBotGroupBox->TabIndex = 36;
			this->AutoBotGroupBox->TabStop = false;
			this->AutoBotGroupBox->Text = L"Autobot";
			this->InfoToolTip->SetToolTip(this->AutoBotGroupBox, L"StopAttackingWhenSpawnIsLow");
			// 
			// cbOLWNA
			// 
			this->cbOLWNA->AutoSize = true;
			this->cbOLWNA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbOLWNA->Location = System::Drawing::Point(138, 46);
			this->cbOLWNA->Name = L"cbOLWNA";
			this->cbOLWNA->Size = System::Drawing::Size(103, 16);
			this->cbOLWNA->TabIndex = 81;
			this->cbOLWNA->Text = L"WhenNotAttacking";
			this->InfoToolTip->SetToolTip(this->cbOLWNA, L"OnlyLootWhenNotAttacking");
			this->cbOLWNA->UseVisualStyleBackColor = true;
			// 
			// nudCCAttacks
			// 
			this->nudCCAttacks->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->nudCCAttacks->Location = System::Drawing::Point(91, 197);
			this->nudCCAttacks->Name = L"nudCCAttacks";
			this->nudCCAttacks->Size = System::Drawing::Size(107, 20);
			this->nudCCAttacks->TabIndex = 80;
			// 
			// nudCCTimed
			// 
			this->nudCCTimed->Location = System::Drawing::Point(91, 171);
			this->nudCCTimed->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7200, 0, 0, 0 });
			this->nudCCTimed->Name = L"nudCCTimed";
			this->nudCCTimed->Size = System::Drawing::Size(107, 20);
			this->nudCCTimed->TabIndex = 79;
			// 
			// nudCCPeople
			// 
			this->nudCCPeople->Location = System::Drawing::Point(91, 143);
			this->nudCCPeople->Name = L"nudCCPeople";
			this->nudCCPeople->Size = System::Drawing::Size(107, 20);
			this->nudCCPeople->TabIndex = 78;
			// 
			// nudPetFeeder
			// 
			this->nudPetFeeder->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->nudPetFeeder->Location = System::Drawing::Point(91, 119);
			this->nudPetFeeder->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->nudPetFeeder->Name = L"nudPetFeeder";
			this->nudPetFeeder->Size = System::Drawing::Size(107, 20);
			this->nudPetFeeder->TabIndex = 74;
			this->InfoToolTip->SetToolTip(this->nudPetFeeder, L"The amount of fullness that your pet shouldn\'t get under");
			// 
			// nudAutoMP
			// 
			this->nudAutoMP->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->nudAutoMP->Location = System::Drawing::Point(91, 94);
			this->nudAutoMP->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->nudAutoMP->Name = L"nudAutoMP";
			this->nudAutoMP->Size = System::Drawing::Size(107, 20);
			this->nudAutoMP->TabIndex = 73;
			this->InfoToolTip->SetToolTip(this->nudAutoMP, L"Keeps an eye on your MP, if it gets too low, it will send a key to use a potion");
			// 
			// nudAutoHP
			// 
			this->nudAutoHP->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->nudAutoHP->Location = System::Drawing::Point(91, 69);
			this->nudAutoHP->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->nudAutoHP->Name = L"nudAutoHP";
			this->nudAutoHP->Size = System::Drawing::Size(107, 20);
			this->nudAutoHP->TabIndex = 72;
			this->InfoToolTip->SetToolTip(this->nudAutoHP, L"Keeps an eye on your HP, if it gets too low, it will send a key to use a potion");
			// 
			// nudAutoLoot
			// 
			this->nudAutoLoot->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->nudAutoLoot->Location = System::Drawing::Point(91, 43);
			this->nudAutoLoot->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1500, 0, 0, 0 });
			this->nudAutoLoot->Name = L"nudAutoLoot";
			this->nudAutoLoot->Size = System::Drawing::Size(44, 20);
			this->nudAutoLoot->TabIndex = 71;
			this->InfoToolTip->SetToolTip(this->nudAutoLoot, L"The delay in milliseconds between pressing keys in MapleStory");
			this->nudAutoLoot->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// nudAutoAttack
			// 
			this->nudAutoAttack->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->nudAutoAttack->Location = System::Drawing::Point(91, 15);
			this->nudAutoAttack->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1500, 0, 0, 0 });
			this->nudAutoAttack->Name = L"nudAutoAttack";
			this->nudAutoAttack->Size = System::Drawing::Size(44, 20);
			this->nudAutoAttack->TabIndex = 70;
			this->InfoToolTip->SetToolTip(this->nudAutoAttack, L"The delay in milliseconds between pressing keys in MapleStory");
			this->nudAutoAttack->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// nudSAWSIL
			// 
			this->nudSAWSIL->Location = System::Drawing::Point(202, 15);
			this->nudSAWSIL->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 25, 0, 0, 0 });
			this->nudSAWSIL->Name = L"nudSAWSIL";
			this->nudSAWSIL->Size = System::Drawing::Size(35, 20);
			this->nudSAWSIL->TabIndex = 68;
			this->InfoToolTip->SetToolTip(this->nudSAWSIL, L"SAWSIL: Stop Attacking When Spawn Is Low, the number is for the amount of mobs th"
				L"at need to be in the map for AutoAttack to attack");
			this->nudSAWSIL->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// ddbTimedType
			// 
			this->ddbTimedType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbTimedType->FormattingEnabled = true;
			this->ddbTimedType->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"CC", L"CS", L"DC" });
			this->ddbTimedType->Location = System::Drawing::Point(47, 169);
			this->ddbTimedType->Name = L"ddbTimedType";
			this->ddbTimedType->Size = System::Drawing::Size(38, 21);
			this->ddbTimedType->TabIndex = 67;
			this->InfoToolTip->SetToolTip(this->ddbTimedType, L"Set here the method you want to use. CC is ChangeChannel, CS is enter/leave cashs"
				L"hop, DC is relog to character select screen");
			// 
			// ddbAttacksType
			// 
			this->ddbAttacksType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbAttacksType->FormattingEnabled = true;
			this->ddbAttacksType->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"CC", L"CS", L"DC" });
			this->ddbAttacksType->Location = System::Drawing::Point(47, 196);
			this->ddbAttacksType->Name = L"ddbAttacksType";
			this->ddbAttacksType->Size = System::Drawing::Size(38, 21);
			this->ddbAttacksType->TabIndex = 66;
			this->InfoToolTip->SetToolTip(this->ddbAttacksType, L"Set here the method you want to use. CC is ChangeChannel, CS is enter/leave cashs"
				L"hop, DC is relog to character select screen");
			// 
			// ddbPeopleType
			// 
			this->ddbPeopleType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbPeopleType->FormattingEnabled = true;
			this->ddbPeopleType->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"CC", L"CS", L"DC" });
			this->ddbPeopleType->Location = System::Drawing::Point(47, 143);
			this->ddbPeopleType->Name = L"ddbPeopleType";
			this->ddbPeopleType->Size = System::Drawing::Size(38, 21);
			this->ddbPeopleType->TabIndex = 65;
			this->InfoToolTip->SetToolTip(this->ddbPeopleType, L"Set here the method you want to use. CC is ChangeChannel, CS is enter/leave cashs"
				L"hop, DC is relog to character select screen");
			// 
			// lSAWSIL
			// 
			this->lSAWSIL->AutoSize = true;
			this->lSAWSIL->Location = System::Drawing::Point(140, 18);
			this->lSAWSIL->Name = L"lSAWSIL";
			this->lSAWSIL->Size = System::Drawing::Size(56, 13);
			this->lSAWSIL->TabIndex = 63;
			this->lSAWSIL->Text = L"MobCount";
			this->InfoToolTip->SetToolTip(this->lSAWSIL, L"MobCount makes AutoAttack stop when the amount of mobs in the map is lower then t"
				L"he amount you inputted");
			// 
			// CCAttacksLabel
			// 
			this->CCAttacksLabel->AutoSize = true;
			this->CCAttacksLabel->Location = System::Drawing::Point(199, 198);
			this->CCAttacksLabel->Name = L"CCAttacksLabel";
			this->CCAttacksLabel->Size = System::Drawing::Size(43, 13);
			this->CCAttacksLabel->TabIndex = 56;
			this->CCAttacksLabel->Text = L"Attacks";
			// 
			// CCTimedLabel
			// 
			this->CCTimedLabel->AutoSize = true;
			this->CCTimedLabel->Location = System::Drawing::Point(199, 172);
			this->CCTimedLabel->Name = L"CCTimedLabel";
			this->CCTimedLabel->Size = System::Drawing::Size(49, 13);
			this->CCTimedLabel->TabIndex = 55;
			this->CCTimedLabel->Text = L"Seconds";
			// 
			// CCPeopleLabel
			// 
			this->CCPeopleLabel->AutoSize = true;
			this->CCPeopleLabel->Location = System::Drawing::Point(199, 144);
			this->CCPeopleLabel->Name = L"CCPeopleLabel";
			this->CCPeopleLabel->Size = System::Drawing::Size(40, 13);
			this->CCPeopleLabel->TabIndex = 54;
			this->CCPeopleLabel->Text = L"People";
			// 
			// cbCCAttacks
			// 
			this->cbCCAttacks->AutoSize = true;
			this->cbCCAttacks->Location = System::Drawing::Point(6, 198);
			this->cbCCAttacks->Name = L"cbCCAttacks";
			this->cbCCAttacks->Size = System::Drawing::Size(48, 17);
			this->cbCCAttacks->TabIndex = 29;
			this->cbCCAttacks->Text = L"Auto";
			this->cbCCAttacks->UseVisualStyleBackColor = true;
			this->cbCCAttacks->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbCCAttacks_CheckedChanged);
			// 
			// cbCCTimed
			// 
			this->cbCCTimed->AutoSize = true;
			this->cbCCTimed->Location = System::Drawing::Point(6, 171);
			this->cbCCTimed->Name = L"cbCCTimed";
			this->cbCCTimed->Size = System::Drawing::Size(48, 17);
			this->cbCCTimed->TabIndex = 27;
			this->cbCCTimed->Text = L"Auto";
			this->cbCCTimed->UseVisualStyleBackColor = true;
			this->cbCCTimed->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbCCTimed_CheckedChanged);
			// 
			// cbCCPeople
			// 
			this->cbCCPeople->AutoSize = true;
			this->cbCCPeople->Location = System::Drawing::Point(6, 144);
			this->cbCCPeople->Name = L"cbCCPeople";
			this->cbCCPeople->Size = System::Drawing::Size(48, 17);
			this->cbCCPeople->TabIndex = 25;
			this->cbCCPeople->Text = L"Auto";
			this->cbCCPeople->UseVisualStyleBackColor = true;
			this->cbCCPeople->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbCCPeople_CheckedChanged);
			// 
			// cbAutoAttack
			// 
			this->cbAutoAttack->AutoSize = true;
			this->cbAutoAttack->Location = System::Drawing::Point(6, 18);
			this->cbAutoAttack->Name = L"cbAutoAttack";
			this->cbAutoAttack->Size = System::Drawing::Size(82, 17);
			this->cbAutoAttack->TabIndex = 1;
			this->cbAutoAttack->Text = L"Auto Attack";
			this->InfoToolTip->SetToolTip(this->cbAutoAttack, L"Lets you character spam his skill just like you would smash your keyboard");
			this->cbAutoAttack->UseVisualStyleBackColor = true;
			this->cbAutoAttack->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbAutoAttack_CheckedChanged);
			// 
			// cbPetFeeder
			// 
			this->cbPetFeeder->AutoSize = true;
			this->cbPetFeeder->Location = System::Drawing::Point(6, 121);
			this->cbPetFeeder->Name = L"cbPetFeeder";
			this->cbPetFeeder->Size = System::Drawing::Size(75, 17);
			this->cbPetFeeder->TabIndex = 13;
			this->cbPetFeeder->Text = L"PetFeeder";
			this->InfoToolTip->SetToolTip(this->cbPetFeeder, L"Feeds your pet to keep him alive while you are botting ;)");
			this->cbPetFeeder->UseVisualStyleBackColor = true;
			// 
			// cbAutoHP
			// 
			this->cbAutoHP->AutoSize = true;
			this->cbAutoHP->Location = System::Drawing::Point(6, 72);
			this->cbAutoHP->Name = L"cbAutoHP";
			this->cbAutoHP->Size = System::Drawing::Size(66, 17);
			this->cbAutoHP->TabIndex = 7;
			this->cbAutoHP->Text = L"Auto HP";
			this->InfoToolTip->SetToolTip(this->cbAutoHP, L"Keeps an eye on your HP, if it gets too low, it will send a key to use a potion");
			this->cbAutoHP->UseVisualStyleBackColor = true;
			this->cbAutoHP->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbAutoHP_CheckedChanged);
			// 
			// ddbPetFeeder
			// 
			this->ddbPetFeeder->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbPetFeeder->FormattingEnabled = true;
			this->ddbPetFeeder->Location = System::Drawing::Point(202, 119);
			this->ddbPetFeeder->Name = L"ddbPetFeeder";
			this->ddbPetFeeder->Size = System::Drawing::Size(115, 21);
			this->ddbPetFeeder->TabIndex = 15;
			this->InfoToolTip->SetToolTip(this->ddbPetFeeder, L"Key PetFeeder will send");
			// 
			// ddbAutoHPKey
			// 
			this->ddbAutoHPKey->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbAutoHPKey->FormattingEnabled = true;
			this->ddbAutoHPKey->Location = System::Drawing::Point(202, 69);
			this->ddbAutoHPKey->Name = L"ddbAutoHPKey";
			this->ddbAutoHPKey->Size = System::Drawing::Size(115, 21);
			this->ddbAutoHPKey->TabIndex = 9;
			this->InfoToolTip->SetToolTip(this->ddbAutoHPKey, L"Key for HP potions");
			// 
			// cbAutoMP
			// 
			this->cbAutoMP->AutoSize = true;
			this->cbAutoMP->Location = System::Drawing::Point(6, 98);
			this->cbAutoMP->Name = L"cbAutoMP";
			this->cbAutoMP->Size = System::Drawing::Size(67, 17);
			this->cbAutoMP->TabIndex = 10;
			this->cbAutoMP->Text = L"Auto MP";
			this->InfoToolTip->SetToolTip(this->cbAutoMP, L"Keeps an eye on your MP, if it gets too low, it will send a key to use a potion");
			this->cbAutoMP->UseVisualStyleBackColor = true;
			this->cbAutoMP->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbAutoMP_CheckedChanged);
			// 
			// ddbAutoLootKey
			// 
			this->ddbAutoLootKey->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbAutoLootKey->FormattingEnabled = true;
			this->ddbAutoLootKey->Location = System::Drawing::Point(241, 42);
			this->ddbAutoLootKey->Name = L"ddbAutoLootKey";
			this->ddbAutoLootKey->Size = System::Drawing::Size(76, 21);
			this->ddbAutoLootKey->TabIndex = 6;
			this->InfoToolTip->SetToolTip(this->ddbAutoLootKey, L"The key WatyBot will press for looting");
			// 
			// cbAutoLoot
			// 
			this->cbAutoLoot->AutoSize = true;
			this->cbAutoLoot->Location = System::Drawing::Point(6, 45);
			this->cbAutoLoot->Name = L"cbAutoLoot";
			this->cbAutoLoot->Size = System::Drawing::Size(72, 17);
			this->cbAutoLoot->TabIndex = 4;
			this->cbAutoLoot->Text = L"Auto Loot";
			this->InfoToolTip->SetToolTip(this->cbAutoLoot, L"Very fast looting, faster then normally");
			this->cbAutoLoot->UseVisualStyleBackColor = true;
			this->cbAutoLoot->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbAutoLoot_CheckedChanged);
			// 
			// ddbAutoMPKey
			// 
			this->ddbAutoMPKey->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbAutoMPKey->FormattingEnabled = true;
			this->ddbAutoMPKey->Location = System::Drawing::Point(202, 94);
			this->ddbAutoMPKey->Name = L"ddbAutoMPKey";
			this->ddbAutoMPKey->Size = System::Drawing::Size(115, 21);
			this->ddbAutoMPKey->TabIndex = 12;
			this->InfoToolTip->SetToolTip(this->ddbAutoMPKey, L"Key for MP potions");
			// 
			// ddbAutoAttackKey
			// 
			this->ddbAutoAttackKey->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbAutoAttackKey->FormattingEnabled = true;
			this->ddbAutoAttackKey->Location = System::Drawing::Point(241, 14);
			this->ddbAutoAttackKey->Name = L"ddbAutoAttackKey";
			this->ddbAutoAttackKey->Size = System::Drawing::Size(76, 21);
			this->ddbAutoAttackKey->TabIndex = 3;
			this->InfoToolTip->SetToolTip(this->ddbAutoAttackKey, L"The key WatyBot will press for attacking");
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
			this->HacksTab->Size = System::Drawing::Size(326, 542);
			this->HacksTab->TabIndex = 1;
			this->HacksTab->Text = L"Hacks";
			this->HacksTab->UseVisualStyleBackColor = true;
			// 
			// gbMiscHacks
			// 
			this->gbMiscHacks->Controls->Add(this->MouseFly);
			this->gbMiscHacks->Controls->Add(this->NoCCBoxes);
			this->gbMiscHacks->Controls->Add(this->NoFadeStages);
			this->gbMiscHacks->Controls->Add(this->HideDamage);
			this->gbMiscHacks->Controls->Add(this->CPUHack);
			this->gbMiscHacks->Controls->Add(this->FaceLeftAfterCC);
			this->gbMiscHacks->Controls->Add(this->ViewSwears);
			this->gbMiscHacks->Controls->Add(this->LogoSkipper);
			this->gbMiscHacks->Controls->Add(this->SitHack);
			this->gbMiscHacks->Controls->Add(this->PinPicTyper);
			this->gbMiscHacks->Controls->Add(this->JDA);
			this->gbMiscHacks->Controls->Add(this->NoBackground);
			this->gbMiscHacks->Location = System::Drawing::Point(7, 273);
			this->gbMiscHacks->Name = L"gbMiscHacks";
			this->gbMiscHacks->Size = System::Drawing::Size(310, 127);
			this->gbMiscHacks->TabIndex = 2;
			this->gbMiscHacks->TabStop = false;
			this->gbMiscHacks->Text = L"Other";
			// 
			// MouseFly
			// 
			this->MouseFly->AutoSize = true;
			this->MouseFly->Location = System::Drawing::Point(159, 107);
			this->MouseFly->Name = L"MouseFly";
			this->MouseFly->Size = System::Drawing::Size(74, 17);
			this->MouseFly->TabIndex = 13;
			this->MouseFly->Text = L"Mouse Fly";
			this->InfoToolTip->SetToolTip(this->MouseFly, L"If you enable this hack, everywhere you click, you will get teleported");
			this->MouseFly->UseVisualStyleBackColor = true;
			this->MouseFly->CheckedChanged += gcnew System::EventHandler(this, &MainForm::MouseFly_CheckedChanged);
			// 
			// NoCCBoxes
			// 
			this->NoCCBoxes->AutoSize = true;
			this->NoCCBoxes->Location = System::Drawing::Point(7, 107);
			this->NoCCBoxes->Name = L"NoCCBoxes";
			this->NoCCBoxes->Size = System::Drawing::Size(110, 17);
			this->NoCCBoxes->TabIndex = 12;
			this->NoCCBoxes->Text = L"No CC BlueBoxes";
			this->InfoToolTip->SetToolTip(this->NoCCBoxes, L"If you try to CC when breath is higher then 0, you won\'t get a breath message, bu"
				L"t you won\'t CC");
			this->NoCCBoxes->UseVisualStyleBackColor = true;
			this->NoCCBoxes->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoCCBoxes_CheckedChanged);
			// 
			// NoFadeStages
			// 
			this->NoFadeStages->AutoSize = true;
			this->NoFadeStages->Location = System::Drawing::Point(159, 89);
			this->NoFadeStages->Name = L"NoFadeStages";
			this->NoFadeStages->Size = System::Drawing::Size(100, 17);
			this->NoFadeStages->TabIndex = 11;
			this->NoFadeStages->Text = L"No FadeStages";
			this->InfoToolTip->SetToolTip(this->NoFadeStages, L"On changin map or loggin in, the game won\'t Fade out or fade in");
			this->NoFadeStages->UseVisualStyleBackColor = true;
			this->NoFadeStages->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoFadeStages_CheckedChanged);
			// 
			// HideDamage
			// 
			this->HideDamage->AutoSize = true;
			this->HideDamage->Location = System::Drawing::Point(7, 89);
			this->HideDamage->Name = L"HideDamage";
			this->HideDamage->Size = System::Drawing::Size(147, 17);
			this->HideDamage->TabIndex = 8;
			this->HideDamage->Text = L"Hide Damage/Animations";
			this->InfoToolTip->SetToolTip(this->HideDamage, L"Hides all the damage you do, use if you DC because you have to much hits");
			this->HideDamage->UseVisualStyleBackColor = true;
			this->HideDamage->CheckedChanged += gcnew System::EventHandler(this, &MainForm::HideDamage_CheckedChanged);
			// 
			// CPUHack
			// 
			this->CPUHack->AutoSize = true;
			this->CPUHack->Location = System::Drawing::Point(159, 71);
			this->CPUHack->Name = L"CPUHack";
			this->CPUHack->Size = System::Drawing::Size(77, 17);
			this->CPUHack->TabIndex = 7;
			this->CPUHack->Text = L"CPU Hack";
			this->InfoToolTip->SetToolTip(this->CPUHack, L"Reduces CPU usage");
			this->CPUHack->UseVisualStyleBackColor = true;
			this->CPUHack->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CPUHack_CheckedChanged);
			// 
			// FaceLeftAfterCC
			// 
			this->FaceLeftAfterCC->AutoSize = true;
			this->FaceLeftAfterCC->Location = System::Drawing::Point(7, 71);
			this->FaceLeftAfterCC->Name = L"FaceLeftAfterCC";
			this->FaceLeftAfterCC->Size = System::Drawing::Size(107, 17);
			this->FaceLeftAfterCC->TabIndex = 6;
			this->FaceLeftAfterCC->Text = L"Always Face Left";
			this->InfoToolTip->SetToolTip(this->FaceLeftAfterCC, L"You will face left when you stand still");
			this->FaceLeftAfterCC->UseVisualStyleBackColor = true;
			this->FaceLeftAfterCC->CheckedChanged += gcnew System::EventHandler(this, &MainForm::FaceLeftAfterCC_CheckedChanged);
			// 
			// ViewSwears
			// 
			this->ViewSwears->AutoSize = true;
			this->ViewSwears->Location = System::Drawing::Point(159, 55);
			this->ViewSwears->Name = L"ViewSwears";
			this->ViewSwears->Size = System::Drawing::Size(87, 17);
			this->ViewSwears->TabIndex = 5;
			this->ViewSwears->Text = L"View Swears";
			this->InfoToolTip->SetToolTip(this->ViewSwears, L"Makes you able to view words without ***");
			this->ViewSwears->UseVisualStyleBackColor = true;
			this->ViewSwears->CheckedChanged += gcnew System::EventHandler(this, &MainForm::ViewSwears_CheckedChanged);
			// 
			// LogoSkipper
			// 
			this->LogoSkipper->AutoSize = true;
			this->LogoSkipper->Location = System::Drawing::Point(159, 37);
			this->LogoSkipper->Name = L"LogoSkipper";
			this->LogoSkipper->Size = System::Drawing::Size(89, 17);
			this->LogoSkipper->TabIndex = 4;
			this->LogoSkipper->Text = L"Logo Skipper";
			this->InfoToolTip->SetToolTip(this->LogoSkipper, L"Skips the logo, making your ms start faster");
			this->LogoSkipper->UseVisualStyleBackColor = true;
			this->LogoSkipper->CheckedChanged += gcnew System::EventHandler(this, &MainForm::LogoSkipper_CheckedChanged);
			// 
			// SitHack
			// 
			this->SitHack->AutoSize = true;
			this->SitHack->Location = System::Drawing::Point(159, 19);
			this->SitHack->Name = L"SitHack";
			this->SitHack->Size = System::Drawing::Size(67, 17);
			this->SitHack->TabIndex = 3;
			this->SitHack->Text = L"Sit Hack";
			this->InfoToolTip->SetToolTip(this->SitHack, L"Makes your char sit");
			this->SitHack->UseVisualStyleBackColor = true;
			this->SitHack->CheckedChanged += gcnew System::EventHandler(this, &MainForm::SitHack_CheckedChanged);
			// 
			// PinPicTyper
			// 
			this->PinPicTyper->AutoSize = true;
			this->PinPicTyper->Location = System::Drawing::Point(7, 55);
			this->PinPicTyper->Name = L"PinPicTyper";
			this->PinPicTyper->Size = System::Drawing::Size(91, 17);
			this->PinPicTyper->TabIndex = 2;
			this->PinPicTyper->Text = L"Pin/Pic Typer";
			this->InfoToolTip->SetToolTip(this->PinPicTyper, L"Lets you type your pin instead of clicking it");
			this->PinPicTyper->UseVisualStyleBackColor = true;
			this->PinPicTyper->CheckedChanged += gcnew System::EventHandler(this, &MainForm::PinPicTyper_CheckedChanged);
			// 
			// JDA
			// 
			this->JDA->AutoSize = true;
			this->JDA->Location = System::Drawing::Point(7, 37);
			this->JDA->Name = L"JDA";
			this->JDA->Size = System::Drawing::Size(46, 17);
			this->JDA->TabIndex = 1;
			this->JDA->Text = L"JDA";
			this->InfoToolTip->SetToolTip(this->JDA, L"Lets you JumpDownAnywhere");
			this->JDA->UseVisualStyleBackColor = true;
			this->JDA->CheckedChanged += gcnew System::EventHandler(this, &MainForm::JDA_CheckedChanged);
			// 
			// NoBackground
			// 
			this->NoBackground->AutoSize = true;
			this->NoBackground->Location = System::Drawing::Point(7, 19);
			this->NoBackground->Name = L"NoBackground";
			this->NoBackground->Size = System::Drawing::Size(145, 17);
			this->NoBackground->TabIndex = 0;
			this->NoBackground->Text = L"No Background + Clouds";
			this->InfoToolTip->SetToolTip(this->NoBackground, L"After CCing your background and clouds are gone");
			this->NoBackground->UseVisualStyleBackColor = true;
			this->NoBackground->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoBackground_CheckedChanged);
			// 
			// gbCharHacks
			// 
			this->gbCharHacks->Controls->Add(this->ddbIFS);
			this->gbCharHacks->Controls->Add(this->cbLockItemVac);
			this->gbCharHacks->Controls->Add(this->nudIceGuard);
			this->gbCharHacks->Controls->Add(this->IceGuard);
			this->gbCharHacks->Controls->Add(this->cbIFS);
			this->gbCharHacks->Controls->Add(this->MercedesCombo);
			this->gbCharHacks->Controls->Add(this->NDMining);
			this->gbCharHacks->Controls->Add(this->DisableFinalAttack);
			this->gbCharHacks->Controls->Add(this->FMA);
			this->gbCharHacks->Controls->Add(this->UnlimitedAttack);
			this->gbCharHacks->Controls->Add(this->ItemVac);
			this->gbCharHacks->Controls->Add(this->SecondGodmode);
			this->gbCharHacks->Controls->Add(this->NDAllAttacks);
			this->gbCharHacks->Controls->Add(this->UnlimitedMorph);
			this->gbCharHacks->Controls->Add(this->DojangGodmode);
			this->gbCharHacks->Controls->Add(this->NoKB);
			this->gbCharHacks->Controls->Add(this->FusionAttack);
			this->gbCharHacks->Controls->Add(this->PerfectLoot);
			this->gbCharHacks->Location = System::Drawing::Point(7, 6);
			this->gbCharHacks->Name = L"gbCharHacks";
			this->gbCharHacks->Size = System::Drawing::Size(310, 162);
			this->gbCharHacks->TabIndex = 1;
			this->gbCharHacks->TabStop = false;
			this->gbCharHacks->Text = L"Character";
			// 
			// ddbIFS
			// 
			this->ddbIFS->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbIFS->FormattingEnabled = true;
			this->ddbIFS->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Kaizer", L"Demon Slayer" });
			this->ddbIFS->Location = System::Drawing::Point(83, 135);
			this->ddbIFS->Name = L"ddbIFS";
			this->ddbIFS->Size = System::Drawing::Size(70, 21);
			this->ddbIFS->TabIndex = 22;
			// 
			// cbLockItemVac
			// 
			this->cbLockItemVac->AutoSize = true;
			this->cbLockItemVac->Location = System::Drawing::Point(75, 84);
			this->cbLockItemVac->Name = L"cbLockItemVac";
			this->cbLockItemVac->Size = System::Drawing::Size(50, 17);
			this->cbLockItemVac->TabIndex = 21;
			this->cbLockItemVac->Text = L"Lock";
			this->cbLockItemVac->UseVisualStyleBackColor = true;
			this->cbLockItemVac->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbLockItemVac_CheckedChanged);
			// 
			// nudIceGuard
			// 
			this->nudIceGuard->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->nudIceGuard->Location = System::Drawing::Point(95, 31);
			this->nudIceGuard->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
			this->nudIceGuard->Name = L"nudIceGuard";
			this->nudIceGuard->Size = System::Drawing::Size(59, 20);
			this->nudIceGuard->TabIndex = 20;
			this->InfoToolTip->SetToolTip(this->nudIceGuard, L"Another godmode, use with caution, a to high amount could AB");
			this->nudIceGuard->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			// 
			// IceGuard
			// 
			this->IceGuard->AutoSize = true;
			this->IceGuard->Location = System::Drawing::Point(6, 32);
			this->IceGuard->Name = L"IceGuard";
			this->IceGuard->Size = System::Drawing::Size(73, 17);
			this->IceGuard->TabIndex = 18;
			this->IceGuard->Text = L"Ice Guard";
			this->InfoToolTip->SetToolTip(this->IceGuard, L"Another godmode, use with caution, a to high amount could AB");
			this->IceGuard->UseVisualStyleBackColor = true;
			this->IceGuard->CheckedChanged += gcnew System::EventHandler(this, &MainForm::IceGuard_CheckedChanged);
			// 
			// cbIFS
			// 
			this->cbIFS->AutoSize = true;
			this->cbIFS->Location = System::Drawing::Point(6, 137);
			this->cbIFS->Name = L"cbIFS";
			this->cbIFS->Size = System::Drawing::Size(77, 17);
			this->cbIFS->TabIndex = 15;
			this->cbIFS->Text = L"Final Slash";
			this->InfoToolTip->SetToolTip(this->cbIFS, L"Makes you skip the 2 attacks before the final attack");
			this->cbIFS->UseVisualStyleBackColor = true;
			this->cbIFS->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbIFS_CheckedChanged);
			// 
			// MercedesCombo
			// 
			this->MercedesCombo->AutoSize = true;
			this->MercedesCombo->Location = System::Drawing::Point(159, 118);
			this->MercedesCombo->Name = L"MercedesCombo";
			this->MercedesCombo->Size = System::Drawing::Size(137, 17);
			this->MercedesCombo->TabIndex = 14;
			this->MercedesCombo->Text = L"Mercedes Perfect Skills";
			this->InfoToolTip->SetToolTip(this->MercedesCombo, L"Lets you use Aerial Barrage, Parting Shot, etc, without using Rising Rush first");
			this->MercedesCombo->UseVisualStyleBackColor = true;
			this->MercedesCombo->CheckedChanged += gcnew System::EventHandler(this, &MainForm::MercedesCombo_CheckedChanged);
			// 
			// NDMining
			// 
			this->NDMining->AutoSize = true;
			this->NDMining->Location = System::Drawing::Point(6, 118);
			this->NDMining->Name = L"NDMining";
			this->NDMining->Size = System::Drawing::Size(104, 17);
			this->NDMining->TabIndex = 13;
			this->NDMining->Text = L"No Delay Mining";
			this->InfoToolTip->SetToolTip(this->NDMining, L"Removes the delay on mining");
			this->NDMining->UseVisualStyleBackColor = true;
			this->NDMining->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NDMining_CheckedChanged);
			// 
			// DisableFinalAttack
			// 
			this->DisableFinalAttack->AutoSize = true;
			this->DisableFinalAttack->Location = System::Drawing::Point(159, 102);
			this->DisableFinalAttack->Name = L"DisableFinalAttack";
			this->DisableFinalAttack->Size = System::Drawing::Size(99, 17);
			this->DisableFinalAttack->TabIndex = 12;
			this->DisableFinalAttack->Text = L"No Final Attack";
			this->InfoToolTip->SetToolTip(this->DisableFinalAttack, L"Removes your ability to have a FinalAttack, use it with FMA to not get DC\'d");
			this->DisableFinalAttack->UseVisualStyleBackColor = true;
			this->DisableFinalAttack->CheckedChanged += gcnew System::EventHandler(this, &MainForm::DisableFinalAttack_CheckedChanged);
			// 
			// FMA
			// 
			this->FMA->AutoSize = true;
			this->FMA->Location = System::Drawing::Point(159, 84);
			this->FMA->Name = L"FMA";
			this->FMA->Size = System::Drawing::Size(100, 17);
			this->FMA->TabIndex = 11;
			this->FMA->Text = L"Full Map Attack";
			this->InfoToolTip->SetToolTip(this->FMA, L"Let\'s you hit the whole map that\'s vissible for you, also called FMA");
			this->FMA->UseVisualStyleBackColor = true;
			this->FMA->CheckedChanged += gcnew System::EventHandler(this, &MainForm::FMA_CheckedChanged);
			// 
			// UnlimitedAttack
			// 
			this->UnlimitedAttack->AutoSize = true;
			this->UnlimitedAttack->Location = System::Drawing::Point(6, 102);
			this->UnlimitedAttack->Name = L"UnlimitedAttack";
			this->UnlimitedAttack->Size = System::Drawing::Size(103, 17);
			this->UnlimitedAttack->TabIndex = 8;
			this->UnlimitedAttack->Text = L"Unlimited Attack";
			this->InfoToolTip->SetToolTip(this->UnlimitedAttack, L"Let\'s you attack without stopping after 100 attacks, (very small chance on a A/B)"
				L"");
			this->UnlimitedAttack->UseVisualStyleBackColor = true;
			this->UnlimitedAttack->CheckedChanged += gcnew System::EventHandler(this, &MainForm::UnlimitedAttack_CheckedChanged);
			// 
			// ItemVac
			// 
			this->ItemVac->AutoSize = true;
			this->ItemVac->Location = System::Drawing::Point(6, 84);
			this->ItemVac->Name = L"ItemVac";
			this->ItemVac->Size = System::Drawing::Size(68, 17);
			this->ItemVac->TabIndex = 10;
			this->ItemVac->Text = L"Item Vac";
			this->InfoToolTip->SetToolTip(this->ItemVac, L"All the items drop below your feet");
			this->ItemVac->UseVisualStyleBackColor = true;
			this->ItemVac->CheckedChanged += gcnew System::EventHandler(this, &MainForm::ItemVac_CheckedChanged);
			// 
			// SecondGodmode
			// 
			this->SecondGodmode->AutoSize = true;
			this->SecondGodmode->Location = System::Drawing::Point(159, 14);
			this->SecondGodmode->Name = L"SecondGodmode";
			this->SecondGodmode->Size = System::Drawing::Size(132, 17);
			this->SecondGodmode->TabIndex = 9;
			this->SecondGodmode->Text = L"50 Seconds Godmode";
			this->InfoToolTip->SetToolTip(this->SecondGodmode, L"After you get hit you have godmode for 50 seconds");
			this->SecondGodmode->UseVisualStyleBackColor = true;
			this->SecondGodmode->CheckedChanged += gcnew System::EventHandler(this, &MainForm::SecondGodmode_CheckedChanged);
			// 
			// NDAllAttacks
			// 
			this->NDAllAttacks->AutoSize = true;
			this->NDAllAttacks->Location = System::Drawing::Point(6, 66);
			this->NDAllAttacks->Name = L"NDAllAttacks";
			this->NDAllAttacks->Size = System::Drawing::Size(104, 17);
			this->NDAllAttacks->TabIndex = 8;
			this->NDAllAttacks->Text = L"GenericNoDelay";
			this->InfoToolTip->SetToolTip(this->NDAllAttacks, L"Removes the AttackAnimation and the delay between attacks, and it gives Unlimited"
				L" MP");
			this->NDAllAttacks->UseVisualStyleBackColor = true;
			this->NDAllAttacks->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NDAllAttacks_CheckedChanged);
			// 
			// UnlimitedMorph
			// 
			this->UnlimitedMorph->AutoSize = true;
			this->UnlimitedMorph->Location = System::Drawing::Point(159, 49);
			this->UnlimitedMorph->Name = L"UnlimitedMorph";
			this->UnlimitedMorph->Size = System::Drawing::Size(102, 17);
			this->UnlimitedMorph->TabIndex = 7;
			this->UnlimitedMorph->Text = L"Unlimited Morph";
			this->InfoToolTip->SetToolTip(this->UnlimitedMorph, L"Kaizers can get in their final form without having the morph gauge filled");
			this->UnlimitedMorph->UseVisualStyleBackColor = true;
			this->UnlimitedMorph->CheckedChanged += gcnew System::EventHandler(this, &MainForm::UnlimitedMorph_CheckedChanged);
			// 
			// DojangGodmode
			// 
			this->DojangGodmode->AutoSize = true;
			this->DojangGodmode->Location = System::Drawing::Point(6, 14);
			this->DojangGodmode->Name = L"DojangGodmode";
			this->DojangGodmode->Size = System::Drawing::Size(109, 17);
			this->DojangGodmode->TabIndex = 6;
			this->DojangGodmode->Text = L"Dojang Godmode";
			this->InfoToolTip->SetToolTip(this->DojangGodmode, L"Let\'s you get missed 7 times before taking a hit");
			this->DojangGodmode->UseVisualStyleBackColor = true;
			this->DojangGodmode->CheckedChanged += gcnew System::EventHandler(this, &MainForm::DojangGodmode_CheckedChanged);
			// 
			// NoKB
			// 
			this->NoKB->AutoSize = true;
			this->NoKB->Location = System::Drawing::Point(6, 49);
			this->NoKB->Name = L"NoKB";
			this->NoKB->Size = System::Drawing::Size(99, 17);
			this->NoKB->TabIndex = 5;
			this->NoKB->Text = L"No KnockBack";
			this->InfoToolTip->SetToolTip(this->NoKB, L"You won\'t get Knocked Back when you get hit");
			this->NoKB->UseVisualStyleBackColor = true;
			this->NoKB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoKB_CheckedChanged);
			// 
			// FusionAttack
			// 
			this->FusionAttack->AutoSize = true;
			this->FusionAttack->Location = System::Drawing::Point(159, 66);
			this->FusionAttack->Name = L"FusionAttack";
			this->FusionAttack->Size = System::Drawing::Size(91, 17);
			this->FusionAttack->TabIndex = 0;
			this->FusionAttack->Text = L"Fusion Attack";
			this->InfoToolTip->SetToolTip(this->FusionAttack, L"If you have an atack that hits 10 mobs 2 times, with fusion you will hit 1 mob 20"
				L" times");
			this->FusionAttack->UseVisualStyleBackColor = true;
			this->FusionAttack->CheckedChanged += gcnew System::EventHandler(this, &MainForm::FusionAttack_CheckedChanged);
			// 
			// PerfectLoot
			// 
			this->PerfectLoot->AutoSize = true;
			this->PerfectLoot->Location = System::Drawing::Point(159, 31);
			this->PerfectLoot->Name = L"PerfectLoot";
			this->PerfectLoot->Size = System::Drawing::Size(84, 17);
			this->PerfectLoot->TabIndex = 1;
			this->PerfectLoot->Text = L"Perfect Loot";
			this->InfoToolTip->SetToolTip(this->PerfectLoot, L"Removes drop and loot animation and loots faster");
			this->PerfectLoot->UseVisualStyleBackColor = true;
			this->PerfectLoot->CheckedChanged += gcnew System::EventHandler(this, &MainForm::PerfectLoot_CheckedChanged);
			// 
			// MobHacks
			// 
			this->MobHacks->Controls->Add(this->AutoAggro);
			this->MobHacks->Controls->Add(this->ScareMobs);
			this->MobHacks->Controls->Add(this->NoMobs);
			this->MobHacks->Controls->Add(this->FasterMobs);
			this->MobHacks->Controls->Add(this->MobDisarm);
			this->MobHacks->Controls->Add(this->JumpRight);
			this->MobHacks->Controls->Add(this->WalkRight);
			this->MobHacks->Controls->Add(this->VacRight);
			this->MobHacks->Location = System::Drawing::Point(7, 174);
			this->MobHacks->Name = L"MobHacks";
			this->MobHacks->Size = System::Drawing::Size(310, 93);
			this->MobHacks->TabIndex = 0;
			this->MobHacks->TabStop = false;
			this->MobHacks->Text = L"Mob";
			// 
			// AutoAggro
			// 
			this->AutoAggro->AutoSize = true;
			this->AutoAggro->Enabled = false;
			this->AutoAggro->Location = System::Drawing::Point(159, 19);
			this->AutoAggro->Name = L"AutoAggro";
			this->AutoAggro->Size = System::Drawing::Size(79, 17);
			this->AutoAggro->TabIndex = 10;
			this->AutoAggro->Text = L"Auto Aggro";
			this->InfoToolTip->SetToolTip(this->AutoAggro, L"Let\'s all mobs get aggresive at you");
			this->AutoAggro->UseVisualStyleBackColor = true;
			this->AutoAggro->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoAggro_CheckedChanged);
			// 
			// ScareMobs
			// 
			this->ScareMobs->AutoSize = true;
			this->ScareMobs->Location = System::Drawing::Point(159, 55);
			this->ScareMobs->Name = L"ScareMobs";
			this->ScareMobs->Size = System::Drawing::Size(83, 17);
			this->ScareMobs->TabIndex = 9;
			this->ScareMobs->Text = L"Scare Mobs";
			this->InfoToolTip->SetToolTip(this->ScareMobs, L"Freezes mobs");
			this->ScareMobs->UseVisualStyleBackColor = true;
			this->ScareMobs->CheckedChanged += gcnew System::EventHandler(this, &MainForm::ScareMobs_CheckedChanged);
			// 
			// NoMobs
			// 
			this->NoMobs->AutoSize = true;
			this->NoMobs->Location = System::Drawing::Point(159, 37);
			this->NoMobs->Name = L"NoMobs";
			this->NoMobs->Size = System::Drawing::Size(69, 17);
			this->NoMobs->TabIndex = 7;
			this->NoMobs->Text = L"No Mobs";
			this->InfoToolTip->SetToolTip(this->NoMobs, L"After ccing with NoMobs enabled, there will be no more mobs in the map");
			this->NoMobs->UseVisualStyleBackColor = true;
			this->NoMobs->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoMobs_CheckedChanged);
			// 
			// FasterMobs
			// 
			this->FasterMobs->AutoSize = true;
			this->FasterMobs->Location = System::Drawing::Point(159, 73);
			this->FasterMobs->Name = L"FasterMobs";
			this->FasterMobs->Size = System::Drawing::Size(84, 17);
			this->FasterMobs->TabIndex = 6;
			this->FasterMobs->Text = L"Faster Mobs";
			this->InfoToolTip->SetToolTip(this->FasterMobs, L"Mobs walk faster");
			this->FasterMobs->UseVisualStyleBackColor = true;
			this->FasterMobs->CheckedChanged += gcnew System::EventHandler(this, &MainForm::FasterMobs_CheckedChanged);
			// 
			// MobDisarm
			// 
			this->MobDisarm->AutoSize = true;
			this->MobDisarm->Location = System::Drawing::Point(6, 73);
			this->MobDisarm->Name = L"MobDisarm";
			this->MobDisarm->Size = System::Drawing::Size(101, 17);
			this->MobDisarm->TabIndex = 5;
			this->MobDisarm->Text = L"Full Mob Disarm";
			this->InfoToolTip->SetToolTip(this->MobDisarm, L"Makes mobs unable to use magical attack and other skills");
			this->MobDisarm->UseVisualStyleBackColor = true;
			this->MobDisarm->CheckedChanged += gcnew System::EventHandler(this, &MainForm::MobDisarm_CheckedChanged);
			// 
			// JumpRight
			// 
			this->JumpRight->AutoSize = true;
			this->JumpRight->Location = System::Drawing::Point(6, 55);
			this->JumpRight->Name = L"JumpRight";
			this->JumpRight->Size = System::Drawing::Size(131, 17);
			this->JumpRight->TabIndex = 4;
			this->JumpRight->Text = L"Jump Unrandom Right";
			this->InfoToolTip->SetToolTip(this->JumpRight, L"All jumping mobs jump right");
			this->JumpRight->UseVisualStyleBackColor = true;
			this->JumpRight->CheckedChanged += gcnew System::EventHandler(this, &MainForm::JumpRight_CheckedChanged);
			// 
			// WalkRight
			// 
			this->WalkRight->AutoSize = true;
			this->WalkRight->Location = System::Drawing::Point(6, 37);
			this->WalkRight->Name = L"WalkRight";
			this->WalkRight->Size = System::Drawing::Size(131, 17);
			this->WalkRight->TabIndex = 2;
			this->WalkRight->Text = L"Walk Unrandom Right";
			this->InfoToolTip->SetToolTip(this->WalkRight, L"All walking mobs walk right");
			this->WalkRight->UseVisualStyleBackColor = true;
			this->WalkRight->CheckedChanged += gcnew System::EventHandler(this, &MainForm::WalkRight_CheckedChanged);
			// 
			// VacRight
			// 
			this->VacRight->AutoSize = true;
			this->VacRight->Location = System::Drawing::Point(6, 19);
			this->VacRight->Name = L"VacRight";
			this->VacRight->Size = System::Drawing::Size(73, 17);
			this->VacRight->TabIndex = 3;
			this->VacRight->Text = L"Vac Right";
			this->InfoToolTip->SetToolTip(this->VacRight, L"Everyone in the map walk right, you too!");
			this->VacRight->UseVisualStyleBackColor = true;
			this->VacRight->CheckedChanged += gcnew System::EventHandler(this, &MainForm::VacRight_CheckedChanged);
			// 
			// PacketSenderTab
			// 
			this->PacketSenderTab->Controls->Add(this->button1);
			this->PacketSenderTab->Controls->Add(this->bAddPacket);
			this->PacketSenderTab->Controls->Add(this->lvPackets);
			this->PacketSenderTab->Location = System::Drawing::Point(4, 22);
			this->PacketSenderTab->Name = L"PacketSenderTab";
			this->PacketSenderTab->Padding = System::Windows::Forms::Padding(3);
			this->PacketSenderTab->Size = System::Drawing::Size(326, 542);
			this->PacketSenderTab->TabIndex = 2;
			this->PacketSenderTab->Text = L"Packets";
			this->PacketSenderTab->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 202);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Send";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// bAddPacket
			// 
			this->bAddPacket->Location = System::Drawing::Point(205, 202);
			this->bAddPacket->Name = L"bAddPacket";
			this->bAddPacket->Size = System::Drawing::Size(115, 23);
			this->bAddPacket->TabIndex = 3;
			this->bAddPacket->Text = L"Add Packet";
			this->bAddPacket->UseVisualStyleBackColor = true;
			this->bAddPacket->Click += gcnew System::EventHandler(this, &MainForm::bAddPacket_Click);
			// 
			// lvPackets
			// 
			this->lvPackets->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->hPacketName, this->hPacket });
			this->lvPackets->ContextMenuStrip = this->PacketContextMenu;
			this->lvPackets->FullRowSelect = true;
			this->lvPackets->GridLines = true;
			this->lvPackets->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->lvPackets->Location = System::Drawing::Point(6, 7);
			this->lvPackets->MultiSelect = false;
			this->lvPackets->Name = L"lvPackets";
			this->lvPackets->Size = System::Drawing::Size(314, 189);
			this->lvPackets->TabIndex = 0;
			this->lvPackets->UseCompatibleStateImageBehavior = false;
			this->lvPackets->View = System::Windows::Forms::View::Details;
			this->lvPackets->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::lvPackets_SelectedIndexChanged);
			this->lvPackets->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::lvPackets_KeyDown);
			// 
			// hPacketName
			// 
			this->hPacketName->Text = L"Name";
			this->hPacketName->Width = 120;
			// 
			// hPacket
			// 
			this->hPacket->Text = L"Packet(s)";
			this->hPacket->Width = 180;
			// 
			// PacketContextMenu
			// 
			this->PacketContextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->bSendPacket,
					this->bEditPacket, this->bDeletePacket
			});
			this->PacketContextMenu->Name = L"PacketContextMenu";
			this->PacketContextMenu->Size = System::Drawing::Size(108, 70);
			// 
			// bSendPacket
			// 
			this->bSendPacket->Name = L"bSendPacket";
			this->bSendPacket->Size = System::Drawing::Size(107, 22);
			this->bSendPacket->Text = L"Send";
			this->bSendPacket->Click += gcnew System::EventHandler(this, &MainForm::bSendPacket_Click);
			// 
			// bEditPacket
			// 
			this->bEditPacket->Name = L"bEditPacket";
			this->bEditPacket->Size = System::Drawing::Size(107, 22);
			this->bEditPacket->Text = L"Edit";
			this->bEditPacket->Click += gcnew System::EventHandler(this, &MainForm::bEditPacket_Click);
			// 
			// bDeletePacket
			// 
			this->bDeletePacket->Name = L"bDeletePacket";
			this->bDeletePacket->Size = System::Drawing::Size(107, 22);
			this->bDeletePacket->Text = L"Delete";
			this->bDeletePacket->Click += gcnew System::EventHandler(this, &MainForm::bDeletePacket_Click);
			// 
			// SPControlTabPage
			// 
			this->SPControlTabPage->Controls->Add(this->gbNewSPCLocation);
			this->SPControlTabPage->Controls->Add(this->lvSPControl);
			this->SPControlTabPage->Location = System::Drawing::Point(4, 22);
			this->SPControlTabPage->Name = L"SPControlTabPage";
			this->SPControlTabPage->Size = System::Drawing::Size(326, 542);
			this->SPControlTabPage->TabIndex = 3;
			this->SPControlTabPage->Text = L"SPControl";
			this->SPControlTabPage->UseVisualStyleBackColor = true;
			// 
			// gbNewSPCLocation
			// 
			this->gbNewSPCLocation->Controls->Add(this->nudSPCY);
			this->gbNewSPCLocation->Controls->Add(this->nudSPCX);
			this->gbNewSPCLocation->Controls->Add(this->nudSPCMapId);
			this->gbNewSPCLocation->Controls->Add(this->bSPCGetCurrent);
			this->gbNewSPCLocation->Controls->Add(this->bAddSPCLocation);
			this->gbNewSPCLocation->Controls->Add(this->SPControlMapIDLabel);
			this->gbNewSPCLocation->Controls->Add(this->cbSPControl);
			this->gbNewSPCLocation->Controls->Add(this->SPControlNameLabel);
			this->gbNewSPCLocation->Controls->Add(this->SPControlYLabel);
			this->gbNewSPCLocation->Controls->Add(this->SPControlXLabel);
			this->gbNewSPCLocation->Controls->Add(this->tbSPCName);
			this->gbNewSPCLocation->Location = System::Drawing::Point(7, 279);
			this->gbNewSPCLocation->Name = L"gbNewSPCLocation";
			this->gbNewSPCLocation->Size = System::Drawing::Size(310, 93);
			this->gbNewSPCLocation->TabIndex = 37;
			this->gbNewSPCLocation->TabStop = false;
			this->gbNewSPCLocation->Text = L"Add New Location";
			// 
			// nudSPCY
			// 
			this->nudSPCY->Location = System::Drawing::Point(269, 33);
			this->nudSPCY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->nudSPCY->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->nudSPCY->Name = L"nudSPCY";
			this->nudSPCY->Size = System::Drawing::Size(36, 20);
			this->nudSPCY->TabIndex = 43;
			// 
			// nudSPCX
			// 
			this->nudSPCX->Location = System::Drawing::Point(230, 33);
			this->nudSPCX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->nudSPCX->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->nudSPCX->Name = L"nudSPCX";
			this->nudSPCX->Size = System::Drawing::Size(36, 20);
			this->nudSPCX->TabIndex = 42;
			// 
			// nudSPCMapId
			// 
			this->nudSPCMapId->Location = System::Drawing::Point(150, 33);
			this->nudSPCMapId->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1410065408, 2, 0, 0 });
			this->nudSPCMapId->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->nudSPCMapId->Name = L"nudSPCMapId";
			this->nudSPCMapId->Size = System::Drawing::Size(77, 20);
			this->nudSPCMapId->TabIndex = 41;
			// 
			// bSPCGetCurrent
			// 
			this->bSPCGetCurrent->Location = System::Drawing::Point(149, 59);
			this->bSPCGetCurrent->Name = L"bSPCGetCurrent";
			this->bSPCGetCurrent->Size = System::Drawing::Size(78, 23);
			this->bSPCGetCurrent->TabIndex = 38;
			this->bSPCGetCurrent->TabStop = false;
			this->bSPCGetCurrent->Text = L"Get Current";
			this->bSPCGetCurrent->UseVisualStyleBackColor = true;
			this->bSPCGetCurrent->Click += gcnew System::EventHandler(this, &MainForm::GetSPControlCoordsButton_Click);
			// 
			// bAddSPCLocation
			// 
			this->bAddSPCLocation->Location = System::Drawing::Point(9, 59);
			this->bAddSPCLocation->Name = L"bAddSPCLocation";
			this->bAddSPCLocation->Size = System::Drawing::Size(134, 23);
			this->bAddSPCLocation->TabIndex = 37;
			this->bAddSPCLocation->TabStop = false;
			this->bAddSPCLocation->Text = L"Add Location";
			this->bAddSPCLocation->UseVisualStyleBackColor = true;
			this->bAddSPCLocation->Click += gcnew System::EventHandler(this, &MainForm::bAddSPCLocation_Click);
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
			// cbSPControl
			// 
			this->cbSPControl->Location = System::Drawing::Point(235, 63);
			this->cbSPControl->Name = L"cbSPControl";
			this->cbSPControl->Size = System::Drawing::Size(66, 17);
			this->cbSPControl->TabIndex = 27;
			this->cbSPControl->TabStop = false;
			this->cbSPControl->Text = L"Enable";
			this->cbSPControl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->cbSPControl->UseVisualStyleBackColor = true;
			this->cbSPControl->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbSPControl_CheckedChanged);
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
			// SPControlYLabel
			// 
			this->SPControlYLabel->Location = System::Drawing::Point(271, 16);
			this->SPControlYLabel->Name = L"SPControlYLabel";
			this->SPControlYLabel->Size = System::Drawing::Size(30, 14);
			this->SPControlYLabel->TabIndex = 30;
			this->SPControlYLabel->Text = L"Y";
			this->SPControlYLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			// tbSPCName
			// 
			this->tbSPCName->Location = System::Drawing::Point(9, 33);
			this->tbSPCName->Name = L"tbSPCName";
			this->tbSPCName->Size = System::Drawing::Size(134, 20);
			this->tbSPCName->TabIndex = 40;
			// 
			// lvSPControl
			// 
			this->lvSPControl->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lvSPControl->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->HeaderMapName,
					this->HeaderMapID, this->HeaderX, this->HeaderY
			});
			this->lvSPControl->ContextMenuStrip = this->SPControlContextMenu;
			this->lvSPControl->FullRowSelect = true;
			this->lvSPControl->GridLines = true;
			this->lvSPControl->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->lvSPControl->Location = System::Drawing::Point(7, 12);
			this->lvSPControl->MultiSelect = false;
			this->lvSPControl->Name = L"lvSPControl";
			this->lvSPControl->Size = System::Drawing::Size(310, 261);
			this->lvSPControl->TabIndex = 28;
			this->lvSPControl->TabStop = false;
			this->lvSPControl->UseCompatibleStateImageBehavior = false;
			this->lvSPControl->View = System::Windows::Forms::View::Details;
			this->lvSPControl->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::lvSPControl_KeyDown);
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
			this->SPControlContextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->editLocationToolStripMenuItem,
					this->deleteSPControlToolStripMenuItem
			});
			this->SPControlContextMenu->Name = L"SPControlContextMenu";
			this->SPControlContextMenu->Size = System::Drawing::Size(157, 48);
			// 
			// editLocationToolStripMenuItem
			// 
			this->editLocationToolStripMenuItem->Name = L"editLocationToolStripMenuItem";
			this->editLocationToolStripMenuItem->Size = System::Drawing::Size(156, 22);
			this->editLocationToolStripMenuItem->Text = L"Edit Location";
			this->editLocationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::editLocationToolStripMenuItem_Click);
			// 
			// deleteSPControlToolStripMenuItem
			// 
			this->deleteSPControlToolStripMenuItem->Name = L"deleteSPControlToolStripMenuItem";
			this->deleteSPControlToolStripMenuItem->Size = System::Drawing::Size(156, 22);
			this->deleteSPControlToolStripMenuItem->Text = L"Delete Location";
			this->deleteSPControlToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::SPControlDeleteItem_Click);
			// 
			// InfoTab
			// 
			this->InfoTab->Controls->Add(this->bSaveSettings);
			this->InfoTab->Controls->Add(this->gbHotKeys);
			this->InfoTab->Controls->Add(this->gbPointers);
			this->InfoTab->Location = System::Drawing::Point(4, 22);
			this->InfoTab->Name = L"InfoTab";
			this->InfoTab->Padding = System::Windows::Forms::Padding(3);
			this->InfoTab->Size = System::Drawing::Size(326, 542);
			this->InfoTab->TabIndex = 4;
			this->InfoTab->Text = L"Info";
			this->InfoTab->UseVisualStyleBackColor = true;
			// 
			// bSaveSettings
			// 
			this->bSaveSettings->Location = System::Drawing::Point(6, 178);
			this->bSaveSettings->Name = L"bSaveSettings";
			this->bSaveSettings->Size = System::Drawing::Size(314, 28);
			this->bSaveSettings->TabIndex = 27;
			this->bSaveSettings->Text = L"Save Settings";
			this->bSaveSettings->UseVisualStyleBackColor = true;
			this->bSaveSettings->Click += gcnew System::EventHandler(this, &MainForm::bSaveSettings_Click);
			// 
			// gbHotKeys
			// 
			this->gbHotKeys->Controls->Add(this->ddbHotKeyMouseFly);
			this->gbHotKeys->Controls->Add(this->cbHotKeyMouseFly);
			this->gbHotKeys->Controls->Add(this->ddbHotKeySendPacket);
			this->gbHotKeys->Controls->Add(this->cbHotKeySendPacket);
			this->gbHotKeys->Controls->Add(this->ddbHotKeyCCPeople);
			this->gbHotKeys->Controls->Add(this->cbHotKeyCCPeople);
			this->gbHotKeys->Controls->Add(this->ddbHotKeyFMA);
			this->gbHotKeys->Controls->Add(this->cbHotKeyFMA);
			this->gbHotKeys->Controls->Add(this->ddbHotKeyLoot);
			this->gbHotKeys->Controls->Add(this->cbHotKeyLoot);
			this->gbHotKeys->Controls->Add(this->ddbHotKeyAttack);
			this->gbHotKeys->Controls->Add(this->cbHotKeyAttack);
			this->gbHotKeys->Location = System::Drawing::Point(6, 7);
			this->gbHotKeys->Name = L"gbHotKeys";
			this->gbHotKeys->Size = System::Drawing::Size(189, 165);
			this->gbHotKeys->TabIndex = 26;
			this->gbHotKeys->TabStop = false;
			this->gbHotKeys->Text = L"Hot Keys";
			// 
			// ddbHotKeyMouseFly
			// 
			this->ddbHotKeyMouseFly->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbHotKeyMouseFly->FormattingEnabled = true;
			this->ddbHotKeyMouseFly->Location = System::Drawing::Point(100, 135);
			this->ddbHotKeyMouseFly->Name = L"ddbHotKeyMouseFly";
			this->ddbHotKeyMouseFly->Size = System::Drawing::Size(80, 21);
			this->ddbHotKeyMouseFly->TabIndex = 20;
			// 
			// cbHotKeyMouseFly
			// 
			this->cbHotKeyMouseFly->AutoSize = true;
			this->cbHotKeyMouseFly->Location = System::Drawing::Point(6, 137);
			this->cbHotKeyMouseFly->Name = L"cbHotKeyMouseFly";
			this->cbHotKeyMouseFly->Size = System::Drawing::Size(71, 17);
			this->cbHotKeyMouseFly->TabIndex = 19;
			this->cbHotKeyMouseFly->Text = L"MouseFly";
			this->cbHotKeyMouseFly->UseVisualStyleBackColor = true;
			// 
			// ddbHotKeySendPacket
			// 
			this->ddbHotKeySendPacket->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbHotKeySendPacket->FormattingEnabled = true;
			this->ddbHotKeySendPacket->Location = System::Drawing::Point(100, 111);
			this->ddbHotKeySendPacket->Name = L"ddbHotKeySendPacket";
			this->ddbHotKeySendPacket->Size = System::Drawing::Size(80, 21);
			this->ddbHotKeySendPacket->TabIndex = 18;
			// 
			// cbHotKeySendPacket
			// 
			this->cbHotKeySendPacket->AutoSize = true;
			this->cbHotKeySendPacket->Location = System::Drawing::Point(6, 113);
			this->cbHotKeySendPacket->Name = L"cbHotKeySendPacket";
			this->cbHotKeySendPacket->Size = System::Drawing::Size(88, 17);
			this->cbHotKeySendPacket->TabIndex = 17;
			this->cbHotKeySendPacket->Text = L"Send Packet";
			this->cbHotKeySendPacket->UseVisualStyleBackColor = true;
			// 
			// ddbHotKeyCCPeople
			// 
			this->ddbHotKeyCCPeople->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbHotKeyCCPeople->FormattingEnabled = true;
			this->ddbHotKeyCCPeople->Location = System::Drawing::Point(100, 87);
			this->ddbHotKeyCCPeople->Name = L"ddbHotKeyCCPeople";
			this->ddbHotKeyCCPeople->Size = System::Drawing::Size(80, 21);
			this->ddbHotKeyCCPeople->TabIndex = 16;
			// 
			// cbHotKeyCCPeople
			// 
			this->cbHotKeyCCPeople->AutoSize = true;
			this->cbHotKeyCCPeople->Location = System::Drawing::Point(6, 89);
			this->cbHotKeyCCPeople->Name = L"cbHotKeyCCPeople";
			this->cbHotKeyCCPeople->Size = System::Drawing::Size(76, 17);
			this->cbHotKeyCCPeople->TabIndex = 15;
			this->cbHotKeyCCPeople->Text = L"CC People";
			this->cbHotKeyCCPeople->UseVisualStyleBackColor = true;
			// 
			// ddbHotKeyFMA
			// 
			this->ddbHotKeyFMA->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbHotKeyFMA->FormattingEnabled = true;
			this->ddbHotKeyFMA->Location = System::Drawing::Point(100, 63);
			this->ddbHotKeyFMA->Name = L"ddbHotKeyFMA";
			this->ddbHotKeyFMA->Size = System::Drawing::Size(80, 21);
			this->ddbHotKeyFMA->TabIndex = 14;
			// 
			// cbHotKeyFMA
			// 
			this->cbHotKeyFMA->AutoSize = true;
			this->cbHotKeyFMA->Location = System::Drawing::Point(6, 65);
			this->cbHotKeyFMA->Name = L"cbHotKeyFMA";
			this->cbHotKeyFMA->Size = System::Drawing::Size(48, 17);
			this->cbHotKeyFMA->TabIndex = 13;
			this->cbHotKeyFMA->Text = L"FMA";
			this->cbHotKeyFMA->UseVisualStyleBackColor = true;
			// 
			// ddbHotKeyLoot
			// 
			this->ddbHotKeyLoot->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbHotKeyLoot->FormattingEnabled = true;
			this->ddbHotKeyLoot->Location = System::Drawing::Point(100, 39);
			this->ddbHotKeyLoot->Name = L"ddbHotKeyLoot";
			this->ddbHotKeyLoot->Size = System::Drawing::Size(80, 21);
			this->ddbHotKeyLoot->TabIndex = 12;
			// 
			// cbHotKeyLoot
			// 
			this->cbHotKeyLoot->AutoSize = true;
			this->cbHotKeyLoot->Location = System::Drawing::Point(6, 41);
			this->cbHotKeyLoot->Name = L"cbHotKeyLoot";
			this->cbHotKeyLoot->Size = System::Drawing::Size(69, 17);
			this->cbHotKeyLoot->TabIndex = 11;
			this->cbHotKeyLoot->Text = L"AutoLoot";
			this->cbHotKeyLoot->UseVisualStyleBackColor = true;
			// 
			// ddbHotKeyAttack
			// 
			this->ddbHotKeyAttack->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ddbHotKeyAttack->FormattingEnabled = true;
			this->ddbHotKeyAttack->Location = System::Drawing::Point(100, 15);
			this->ddbHotKeyAttack->Name = L"ddbHotKeyAttack";
			this->ddbHotKeyAttack->Size = System::Drawing::Size(80, 21);
			this->ddbHotKeyAttack->TabIndex = 10;
			// 
			// cbHotKeyAttack
			// 
			this->cbHotKeyAttack->AutoSize = true;
			this->cbHotKeyAttack->Location = System::Drawing::Point(6, 17);
			this->cbHotKeyAttack->Name = L"cbHotKeyAttack";
			this->cbHotKeyAttack->Size = System::Drawing::Size(79, 17);
			this->cbHotKeyAttack->TabIndex = 0;
			this->cbHotKeyAttack->Text = L"AutoAttack";
			this->cbHotKeyAttack->UseVisualStyleBackColor = true;
			// 
			// gbPointers
			// 
			this->gbPointers->Controls->Add(this->lChannel);
			this->gbPointers->Controls->Add(this->lMSCRC);
			this->gbPointers->Controls->Add(this->lInGame);
			this->gbPointers->Controls->Add(this->lPetFullness);
			this->gbPointers->Controls->Add(this->lMapID);
			this->gbPointers->Controls->Add(this->BreathLabel);
			this->gbPointers->Controls->Add(this->MobCountLabel);
			this->gbPointers->Controls->Add(this->AttackCountLabel);
			this->gbPointers->Controls->Add(this->PeopleCountLabel);
			this->gbPointers->Controls->Add(this->ItemCountLabel);
			this->gbPointers->Controls->Add(this->CharPosLabel);
			this->gbPointers->Location = System::Drawing::Point(195, 7);
			this->gbPointers->Name = L"gbPointers";
			this->gbPointers->Size = System::Drawing::Size(125, 165);
			this->gbPointers->TabIndex = 25;
			this->gbPointers->TabStop = false;
			this->gbPointers->Text = L"Pointers";
			// 
			// lChannel
			// 
			this->lChannel->AutoSize = true;
			this->lChannel->Location = System::Drawing::Point(6, 94);
			this->lChannel->Name = L"lChannel";
			this->lChannel->Size = System::Drawing::Size(58, 13);
			this->lChannel->TabIndex = 31;
			this->lChannel->Text = L"Channel: 0";
			// 
			// lMSCRC
			// 
			this->lMSCRC->AutoSize = true;
			this->lMSCRC->Location = System::Drawing::Point(6, 145);
			this->lMSCRC->Name = L"lMSCRC";
			this->lMSCRC->Size = System::Drawing::Size(96, 13);
			this->lMSCRC->TabIndex = 30;
			this->lMSCRC->Text = L"MSCRC: bypassed";
			// 
			// lInGame
			// 
			this->lInGame->AutoSize = true;
			this->lInGame->Location = System::Drawing::Point(6, 132);
			this->lInGame->Name = L"lInGame";
			this->lInGame->Size = System::Drawing::Size(68, 13);
			this->lInGame->TabIndex = 29;
			this->lInGame->Text = L"InGame: true";
			// 
			// lPetFullness
			// 
			this->lPetFullness->AutoSize = true;
			this->lPetFullness->Location = System::Drawing::Point(6, 119);
			this->lPetFullness->Name = L"lPetFullness";
			this->lPetFullness->Size = System::Drawing::Size(93, 13);
			this->lPetFullness->TabIndex = 19;
			this->lPetFullness->Text = L"PetFullness: 100%";
			// 
			// lMapID
			// 
			this->lMapID->AutoSize = true;
			this->lMapID->Location = System::Drawing::Point(6, 81);
			this->lMapID->Name = L"lMapID";
			this->lMapID->Size = System::Drawing::Size(75, 13);
			this->lMapID->TabIndex = 27;
			this->lMapID->Text = L"MapID: 12345";
			// 
			// BreathLabel
			// 
			this->BreathLabel->AutoSize = true;
			this->BreathLabel->Location = System::Drawing::Point(6, 106);
			this->BreathLabel->Name = L"BreathLabel";
			this->BreathLabel->Size = System::Drawing::Size(50, 13);
			this->BreathLabel->TabIndex = 26;
			this->BreathLabel->Text = L"Breath: 0";
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
			this->PeopleCountLabel->Location = System::Drawing::Point(6, 42);
			this->PeopleCountLabel->Name = L"PeopleCountLabel";
			this->PeopleCountLabel->Size = System::Drawing::Size(52, 13);
			this->PeopleCountLabel->TabIndex = 21;
			this->PeopleCountLabel->Text = L"People: 0";
			// 
			// ItemCountLabel
			// 
			this->ItemCountLabel->AutoSize = true;
			this->ItemCountLabel->Location = System::Drawing::Point(6, 29);
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
			this->StatsTimer->Tick += gcnew System::EventHandler(this, &MainForm::StatsTimer_Tick);
			// 
			// tAutoAttack
			// 
			this->tAutoAttack->Tick += gcnew System::EventHandler(this, &MainForm::tAutoAttack_Tick);
			// 
			// tAutoLoot
			// 
			this->tAutoLoot->Tick += gcnew System::EventHandler(this, &MainForm::tAutoLoot_Tick);
			// 
			// tTimedCC
			// 
			this->tTimedCC->Tick += gcnew System::EventHandler(this, &MainForm::tTimedCC_Tick);
			// 
			// SettingsWatcher
			// 
			this->SettingsWatcher->EnableRaisingEvents = true;
			this->SettingsWatcher->Filter = L"*.xml";
			this->SettingsWatcher->NotifyFilter = System::IO::NotifyFilters::LastWrite;
			this->SettingsWatcher->SynchronizingObject = this;
			this->SettingsWatcher->Changed += gcnew System::IO::FileSystemEventHandler(this, &MainForm::SettingsWatcher_Changed);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(334, 622);
			this->Controls->Add(this->MainTabControl);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->Text = L"WatyBot 3.4.1 - CCPLZ! - EMS 94.1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->MainTabControl->ResumeLayout(false);
			this->AutoBotTab->ResumeLayout(false);
			this->gbAutoSkill->ResumeLayout(false);
			this->gbAutoSkill->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudAutoSkill))->EndInit();
			this->AutoSkillContextMenu->ResumeLayout(false);
			this->AutoBotGroupBox->ResumeLayout(false);
			this->AutoBotGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudCCAttacks))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudCCTimed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudCCPeople))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudPetFeeder))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudAutoMP))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudAutoHP))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudAutoLoot))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudAutoAttack))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudSAWSIL))->EndInit();
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudIceGuard))->EndInit();
			this->MobHacks->ResumeLayout(false);
			this->MobHacks->PerformLayout();
			this->PacketSenderTab->ResumeLayout(false);
			this->PacketContextMenu->ResumeLayout(false);
			this->SPControlTabPage->ResumeLayout(false);
			this->gbNewSPCLocation->ResumeLayout(false);
			this->gbNewSPCLocation->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudSPCY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudSPCX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->nudSPCMapId))->EndInit();
			this->SPControlContextMenu->ResumeLayout(false);
			this->InfoTab->ResumeLayout(false);
			this->gbHotKeys->ResumeLayout(false);
			this->gbHotKeys->PerformLayout();
			this->gbPointers->ResumeLayout(false);
			this->gbPointers->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->SettingsWatcher))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	public:
		static String^ Path = System::IO::Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData), "Waty", "Settings.xml");
		static array<String^>^ KeyNames = gcnew array<String^>{"Shift", "Space", "Ctrl", "Alt", "Insert", "Delete", "Home", "End", "Page Up", "Page Down",
			"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
			"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12"};
		static NotifyIcon^ notifyIcon = gcnew NotifyIcon;

	private:
		//General private class members
		Void LoadSettings();
		Void SaveSettings();
		Void RedrawStatBars();
		Void ReloadComboBox(ComboBox^ combobox);
		Void HotKeys();

		//General trainer events
		Void MainForm_Load(Object^ sender, EventArgs^ e);
		Void StatsTimer_Tick(Object^ sender, EventArgs^ e);
		Void MainTabControl_SelectedIndexChanged(Object^ sender, EventArgs^ e);
		Void MainForm_FormClosing(Object^ sender, Windows::Forms::FormClosingEventArgs^ e);
		Void bSaveSettings_Click(Object^ sender, EventArgs^ e);
		Void SettingsWatcher_Changed(System::Object^ sender, System::IO::FileSystemEventArgs^ e);

		//AutoBot Events
		Void cbAutoAttack_CheckedChanged(Object^ sender, EventArgs^ e);
		Void tAutoAttack_Tick(Object^ sender, EventArgs^ e);
		Void cbAutoLoot_CheckedChanged(Object^ sender, EventArgs^ e);
		Void tAutoLoot_Tick(Object^ sender, EventArgs^ e);
		Void cbAutoHP_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbAutoMP_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbCCPeople_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbCCTimed_CheckedChanged(Object^ sender, EventArgs^ e);
		Void tTimedCC_Tick(Object^ sender, EventArgs^ e);
		Void cbCCAttacks_CheckedChanged(Object^ sender, EventArgs^ e);

		//AutoSkill
		Void bAutoSkill_Click(Object^ sender, EventArgs^ e);
		Void castToolStripMenuItem_Click(Object^ sender, EventArgs^ e);
		Void deleteToolStripMenuItem_Click(Object^ sender, EventArgs^ e);
		Void lvAutoSkill_ItemCheck(Object^ sender, Windows::Forms::ItemCheckEventArgs^ e);
		Void lvAutoSkill_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
		Void LoadAutoSkill();

		//SPControl
		Void bAddSPCLocation_Click(Object^ sender, EventArgs^ e);
		Void cbSPControl_CheckedChanged(Object^ sender, EventArgs^ e);
		Void SPControlDeleteItem_Click(Object^ sender, EventArgs^ e);
		Void editLocationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		Void GetSPControlCoordsButton_Click(Object^ sender, EventArgs^ e);
		Void lvSPControl_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
		Void LoadSPControl();

		//Hacks
		Void FusionAttack_CheckedChanged(Object^ sender, EventArgs^ e);
		Void NoKB_CheckedChanged(Object^ sender, EventArgs^ e);
		Void PerfectLoot_CheckedChanged(Object^ sender, EventArgs^ e);
		Void VacRight_CheckedChanged(Object^ sender, EventArgs^ e);
		Void WalkRight_CheckedChanged(Object^ sender, EventArgs^ e);
		Void JumpRight_CheckedChanged(Object^ sender, EventArgs^ e);
		Void NoBackground_CheckedChanged(Object^ sender, EventArgs^ e);
		Void MobDisarm_CheckedChanged(Object^ sender, EventArgs^ e);
		Void JDA_CheckedChanged(Object^ sender, EventArgs^ e);
		Void PinPicTyper_CheckedChanged(Object^ sender, EventArgs^ e);
		Void DojangGodmode_CheckedChanged(Object^ sender, EventArgs^ e);
		Void UnlimitedMorph_CheckedChanged(Object^ sender, EventArgs^ e);
		Void FasterMobs_CheckedChanged(Object^ sender, EventArgs^ e);
		Void NDAllAttacks_CheckedChanged(Object^ sender, EventArgs^ e);
		Void NoMobs_CheckedChanged(Object^ sender, EventArgs^ e);
		Void UnlimitedAttack_CheckedChanged(Object^ sender, EventArgs^ e);
		Void SitHack_CheckedChanged(Object^ sender, EventArgs^ e);
		Void SecondGodmode_CheckedChanged(Object^ sender, EventArgs^ e);
		Void LogoSkipper_CheckedChanged(Object^ sender, EventArgs^ e);
		Void ViewSwears_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbLockItemVac_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		Void ItemVac_CheckedChanged(Object^ sender, EventArgs^ e);
		Void FMA_CheckedChanged(Object^ sender, EventArgs^ e);
		Void ScareMobs_CheckedChanged(Object^ sender, EventArgs^ e);
		Void FaceLeftAfterCC_CheckedChanged(Object^ sender, EventArgs^ e);
		Void CPUHack_CheckedChanged(Object^ sender, EventArgs^ e);
		Void DisableFinalAttack_CheckedChanged(Object^ sender, EventArgs^ e);
		Void AutoAggro_CheckedChanged(Object^ sender, EventArgs^ e);
		Void NDMining_CheckedChanged(Object^ sender, EventArgs^ e);
		Void HideDamage_CheckedChanged(Object^ sender, EventArgs^ e);
		Void MercedesCombo_CheckedChanged(Object^ sender, EventArgs^ e);
		Void NoFadeStages_CheckedChanged(Object^ sender, EventArgs^ e);
		Void NoCCBoxes_CheckedChanged(Object^ sender, EventArgs^ e);
		Void MouseFly_CheckedChanged(Object^ sender, EventArgs^ e);
		Void IceGuard_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbIFS_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

		//PacketSender events
		Void bAddPacket_Click(Object^ sender, EventArgs^ e);
		Void lvPackets_SelectedIndexChanged(Object^ sender, EventArgs^ e);
		Void bSendPacket_Click(Object^ sender, EventArgs^ e);
		Void bDeletePacket_Click(Object^ sender, EventArgs^ e);
		Void lvPackets_KeyDown(Object^ sender, KeyEventArgs^ e);
		Void bEditPacket_Click(System::Object^ sender, System::EventArgs^ e);
		Void LoadPackets();
	};
}
