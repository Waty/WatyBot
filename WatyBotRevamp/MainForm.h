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
		System::Windows::Forms::CheckBox^ cbPerfectLoot;
		System::Windows::Forms::CheckBox^ cbFusionAttack;
		System::Windows::Forms::GroupBox^ gbMiscHacks;
		System::Windows::Forms::CheckBox^ cbJDA;
		System::Windows::Forms::CheckBox^ cbNoBG;
		System::Windows::Forms::GroupBox^ gbCharHacks;
		System::Windows::Forms::CheckBox^ cbVacRight;
		System::Windows::Forms::CheckBox^ cbJumpRight;
		System::Windows::Forms::CheckBox^ cbWalkRight;
		System::Windows::Forms::CheckBox^ cbPinTyper;
		System::Windows::Forms::CheckBox^ cbNoKB;
		System::Windows::Forms::CheckBox^ cbMobDisarm;
		System::Windows::Forms::CheckBox^ cbDojangGodmode;
		System::Windows::Forms::CheckBox^ cbUnlimitedMorph;
		System::Windows::Forms::CheckBox^ cbFasterMobs;
		System::Windows::Forms::CheckBox^ cbNDAllAttacks;
		System::Windows::Forms::CheckBox^ cbNoMobs;
		System::Windows::Forms::CheckBox^ cbUA;
		System::Windows::Forms::CheckBox^ cbSitHack;
		System::Windows::Forms::CheckBox^ cb50SecGM;
		System::Windows::Forms::CheckBox^ cbLogoSkipper;
		System::Windows::Forms::CheckBox^ cbViewSwears;
		System::Windows::Forms::CheckBox^ cbItemVac;
		System::Windows::Forms::CheckBox^ cbFMA;
		System::Windows::Forms::CheckBox^ cbScareMobs;
		System::Windows::Forms::CheckBox^ cbFLACC;
		System::Windows::Forms::CheckBox^ cbCPUHack;
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
		System::Windows::Forms::CheckBox^ cbNFA;
		System::Windows::Forms::CheckBox^ cbAutoAggro;
		System::Windows::Forms::Button^ bSaveSettings;
		System::Windows::Forms::ComboBox^ ddbHotKeyFMA;
		System::Windows::Forms::CheckBox^ cbHotKeyFMA;
		System::Windows::Forms::ComboBox^ ddbHotKeyCCPeople;
		System::Windows::Forms::CheckBox^ cbHotKeyCCPeople;
		System::Windows::Forms::CheckBox^ cbNDMining;
		System::Windows::Forms::ComboBox^ ddbHotKeySendPacket;
		System::Windows::Forms::CheckBox^ cbHotKeySendPacket;
		System::Windows::Forms::CheckBox^ cbHideDamage;
		System::Windows::Forms::CheckBox^ cbMercedesCombo;
		System::Windows::Forms::ToolTip^ InfoToolTip;
		System::Windows::Forms::CheckBox^  cbIFS;
		System::Windows::Forms::CheckBox^ cbNoFadeStages;
		System::Windows::Forms::CheckBox^ cbNoCCBlueBoxes;
		System::Windows::Forms::CheckBox^ cbMouseFly;
		System::Windows::Forms::NumericUpDown^ nudIceGuard;
		System::Windows::Forms::CheckBox^ cbIceGuard;
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
			this->cbMouseFly = (gcnew System::Windows::Forms::CheckBox());
			this->cbNoCCBlueBoxes = (gcnew System::Windows::Forms::CheckBox());
			this->cbNoFadeStages = (gcnew System::Windows::Forms::CheckBox());
			this->cbHideDamage = (gcnew System::Windows::Forms::CheckBox());
			this->cbCPUHack = (gcnew System::Windows::Forms::CheckBox());
			this->cbFLACC = (gcnew System::Windows::Forms::CheckBox());
			this->cbViewSwears = (gcnew System::Windows::Forms::CheckBox());
			this->cbLogoSkipper = (gcnew System::Windows::Forms::CheckBox());
			this->cbSitHack = (gcnew System::Windows::Forms::CheckBox());
			this->cbPinTyper = (gcnew System::Windows::Forms::CheckBox());
			this->cbJDA = (gcnew System::Windows::Forms::CheckBox());
			this->cbNoBG = (gcnew System::Windows::Forms::CheckBox());
			this->gbCharHacks = (gcnew System::Windows::Forms::GroupBox());
			this->ddbIFS = (gcnew System::Windows::Forms::ComboBox());
			this->cbLockItemVac = (gcnew System::Windows::Forms::CheckBox());
			this->nudIceGuard = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbIceGuard = (gcnew System::Windows::Forms::CheckBox());
			this->cbIFS = (gcnew System::Windows::Forms::CheckBox());
			this->cbMercedesCombo = (gcnew System::Windows::Forms::CheckBox());
			this->cbNDMining = (gcnew System::Windows::Forms::CheckBox());
			this->cbNFA = (gcnew System::Windows::Forms::CheckBox());
			this->cbFMA = (gcnew System::Windows::Forms::CheckBox());
			this->cbUA = (gcnew System::Windows::Forms::CheckBox());
			this->cbItemVac = (gcnew System::Windows::Forms::CheckBox());
			this->cb50SecGM = (gcnew System::Windows::Forms::CheckBox());
			this->cbNDAllAttacks = (gcnew System::Windows::Forms::CheckBox());
			this->cbUnlimitedMorph = (gcnew System::Windows::Forms::CheckBox());
			this->cbDojangGodmode = (gcnew System::Windows::Forms::CheckBox());
			this->cbNoKB = (gcnew System::Windows::Forms::CheckBox());
			this->cbFusionAttack = (gcnew System::Windows::Forms::CheckBox());
			this->cbPerfectLoot = (gcnew System::Windows::Forms::CheckBox());
			this->MobHacks = (gcnew System::Windows::Forms::GroupBox());
			this->cbAutoAggro = (gcnew System::Windows::Forms::CheckBox());
			this->cbScareMobs = (gcnew System::Windows::Forms::CheckBox());
			this->cbNoMobs = (gcnew System::Windows::Forms::CheckBox());
			this->cbFasterMobs = (gcnew System::Windows::Forms::CheckBox());
			this->cbMobDisarm = (gcnew System::Windows::Forms::CheckBox());
			this->cbJumpRight = (gcnew System::Windows::Forms::CheckBox());
			this->cbWalkRight = (gcnew System::Windows::Forms::CheckBox());
			this->cbVacRight = (gcnew System::Windows::Forms::CheckBox());
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
			this->gbMiscHacks->Controls->Add(this->cbMouseFly);
			this->gbMiscHacks->Controls->Add(this->cbNoCCBlueBoxes);
			this->gbMiscHacks->Controls->Add(this->cbNoFadeStages);
			this->gbMiscHacks->Controls->Add(this->cbHideDamage);
			this->gbMiscHacks->Controls->Add(this->cbCPUHack);
			this->gbMiscHacks->Controls->Add(this->cbFLACC);
			this->gbMiscHacks->Controls->Add(this->cbViewSwears);
			this->gbMiscHacks->Controls->Add(this->cbLogoSkipper);
			this->gbMiscHacks->Controls->Add(this->cbSitHack);
			this->gbMiscHacks->Controls->Add(this->cbPinTyper);
			this->gbMiscHacks->Controls->Add(this->cbJDA);
			this->gbMiscHacks->Controls->Add(this->cbNoBG);
			this->gbMiscHacks->Location = System::Drawing::Point(7, 273);
			this->gbMiscHacks->Name = L"gbMiscHacks";
			this->gbMiscHacks->Size = System::Drawing::Size(310, 127);
			this->gbMiscHacks->TabIndex = 2;
			this->gbMiscHacks->TabStop = false;
			this->gbMiscHacks->Text = L"Other";
			// 
			// cbMouseFly
			// 
			this->cbMouseFly->AutoSize = true;
			this->cbMouseFly->Location = System::Drawing::Point(159, 107);
			this->cbMouseFly->Name = L"cbMouseFly";
			this->cbMouseFly->Size = System::Drawing::Size(74, 17);
			this->cbMouseFly->TabIndex = 13;
			this->cbMouseFly->Text = L"Mouse Fly";
			this->InfoToolTip->SetToolTip(this->cbMouseFly, L"If you enable this hack, everywhere you click, you will get teleported");
			this->cbMouseFly->UseVisualStyleBackColor = true;
			this->cbMouseFly->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbMouseFly_CheckedChanged);
			// 
			// cbNoCCBlueBoxes
			// 
			this->cbNoCCBlueBoxes->AutoSize = true;
			this->cbNoCCBlueBoxes->Location = System::Drawing::Point(7, 107);
			this->cbNoCCBlueBoxes->Name = L"cbNoCCBlueBoxes";
			this->cbNoCCBlueBoxes->Size = System::Drawing::Size(110, 17);
			this->cbNoCCBlueBoxes->TabIndex = 12;
			this->cbNoCCBlueBoxes->Text = L"No CC BlueBoxes";
			this->InfoToolTip->SetToolTip(this->cbNoCCBlueBoxes, L"If you try to CC when breath is higher then 0, you won\'t get a breath message, bu"
				L"t you won\'t CC");
			this->cbNoCCBlueBoxes->UseVisualStyleBackColor = true;
			this->cbNoCCBlueBoxes->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbNoCCBlueBoxes_CheckedChanged);
			// 
			// cbNoFadeStages
			// 
			this->cbNoFadeStages->AutoSize = true;
			this->cbNoFadeStages->Location = System::Drawing::Point(159, 89);
			this->cbNoFadeStages->Name = L"cbNoFadeStages";
			this->cbNoFadeStages->Size = System::Drawing::Size(100, 17);
			this->cbNoFadeStages->TabIndex = 11;
			this->cbNoFadeStages->Text = L"No FadeStages";
			this->InfoToolTip->SetToolTip(this->cbNoFadeStages, L"On changin map or loggin in, the game won\'t Fade out or fade in");
			this->cbNoFadeStages->UseVisualStyleBackColor = true;
			this->cbNoFadeStages->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbNoFadeStages_CheckedChanged);
			// 
			// cbHideDamage
			// 
			this->cbHideDamage->AutoSize = true;
			this->cbHideDamage->Location = System::Drawing::Point(7, 89);
			this->cbHideDamage->Name = L"cbHideDamage";
			this->cbHideDamage->Size = System::Drawing::Size(147, 17);
			this->cbHideDamage->TabIndex = 8;
			this->cbHideDamage->Text = L"Hide Damage/Animations";
			this->InfoToolTip->SetToolTip(this->cbHideDamage, L"Hides all the damage you do, use if you DC because you have to much hits");
			this->cbHideDamage->UseVisualStyleBackColor = true;
			this->cbHideDamage->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbHideDamage_CheckedChanged);
			// 
			// cbCPUHack
			// 
			this->cbCPUHack->AutoSize = true;
			this->cbCPUHack->Location = System::Drawing::Point(159, 71);
			this->cbCPUHack->Name = L"cbCPUHack";
			this->cbCPUHack->Size = System::Drawing::Size(77, 17);
			this->cbCPUHack->TabIndex = 7;
			this->cbCPUHack->Text = L"CPU Hack";
			this->InfoToolTip->SetToolTip(this->cbCPUHack, L"Reduces CPU usage");
			this->cbCPUHack->UseVisualStyleBackColor = true;
			this->cbCPUHack->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbCPUHack_CheckedChanged);
			// 
			// cbFLACC
			// 
			this->cbFLACC->AutoSize = true;
			this->cbFLACC->Location = System::Drawing::Point(7, 71);
			this->cbFLACC->Name = L"cbFLACC";
			this->cbFLACC->Size = System::Drawing::Size(107, 17);
			this->cbFLACC->TabIndex = 6;
			this->cbFLACC->Text = L"Always Face Left";
			this->InfoToolTip->SetToolTip(this->cbFLACC, L"You will face left when you stand still");
			this->cbFLACC->UseVisualStyleBackColor = true;
			this->cbFLACC->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbFLACC_CheckedChanged);
			// 
			// cbViewSwears
			// 
			this->cbViewSwears->AutoSize = true;
			this->cbViewSwears->Location = System::Drawing::Point(159, 55);
			this->cbViewSwears->Name = L"cbViewSwears";
			this->cbViewSwears->Size = System::Drawing::Size(87, 17);
			this->cbViewSwears->TabIndex = 5;
			this->cbViewSwears->Text = L"View Swears";
			this->InfoToolTip->SetToolTip(this->cbViewSwears, L"Makes you able to view words without ***");
			this->cbViewSwears->UseVisualStyleBackColor = true;
			this->cbViewSwears->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbViewSwears_CheckedChanged);
			// 
			// cbLogoSkipper
			// 
			this->cbLogoSkipper->AutoSize = true;
			this->cbLogoSkipper->Location = System::Drawing::Point(159, 37);
			this->cbLogoSkipper->Name = L"cbLogoSkipper";
			this->cbLogoSkipper->Size = System::Drawing::Size(89, 17);
			this->cbLogoSkipper->TabIndex = 4;
			this->cbLogoSkipper->Text = L"Logo Skipper";
			this->InfoToolTip->SetToolTip(this->cbLogoSkipper, L"Skips the logo, making your ms start faster");
			this->cbLogoSkipper->UseVisualStyleBackColor = true;
			this->cbLogoSkipper->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbLogoSkipper_CheckedChanged);
			// 
			// cbSitHack
			// 
			this->cbSitHack->AutoSize = true;
			this->cbSitHack->Location = System::Drawing::Point(159, 19);
			this->cbSitHack->Name = L"cbSitHack";
			this->cbSitHack->Size = System::Drawing::Size(67, 17);
			this->cbSitHack->TabIndex = 3;
			this->cbSitHack->Text = L"Sit Hack";
			this->InfoToolTip->SetToolTip(this->cbSitHack, L"Makes your char sit");
			this->cbSitHack->UseVisualStyleBackColor = true;
			this->cbSitHack->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbSitHack_CheckedChanged);
			// 
			// cbPinTyper
			// 
			this->cbPinTyper->AutoSize = true;
			this->cbPinTyper->Location = System::Drawing::Point(7, 55);
			this->cbPinTyper->Name = L"cbPinTyper";
			this->cbPinTyper->Size = System::Drawing::Size(91, 17);
			this->cbPinTyper->TabIndex = 2;
			this->cbPinTyper->Text = L"Pin/Pic Typer";
			this->InfoToolTip->SetToolTip(this->cbPinTyper, L"Lets you type your pin instead of clicking it");
			this->cbPinTyper->UseVisualStyleBackColor = true;
			this->cbPinTyper->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbPinTyper_CheckedChanged);
			// 
			// cbJDA
			// 
			this->cbJDA->AutoSize = true;
			this->cbJDA->Location = System::Drawing::Point(7, 37);
			this->cbJDA->Name = L"cbJDA";
			this->cbJDA->Size = System::Drawing::Size(46, 17);
			this->cbJDA->TabIndex = 1;
			this->cbJDA->Text = L"JDA";
			this->InfoToolTip->SetToolTip(this->cbJDA, L"Lets you JumpDownAnywhere");
			this->cbJDA->UseVisualStyleBackColor = true;
			this->cbJDA->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbJDA_CheckedChanged);
			// 
			// cbNoBG
			// 
			this->cbNoBG->AutoSize = true;
			this->cbNoBG->Location = System::Drawing::Point(7, 19);
			this->cbNoBG->Name = L"cbNoBG";
			this->cbNoBG->Size = System::Drawing::Size(145, 17);
			this->cbNoBG->TabIndex = 0;
			this->cbNoBG->Text = L"No Background + Clouds";
			this->InfoToolTip->SetToolTip(this->cbNoBG, L"After CCing your background and clouds are gone");
			this->cbNoBG->UseVisualStyleBackColor = true;
			this->cbNoBG->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbNoBG_CheckedChanged);
			// 
			// gbCharHacks
			// 
			this->gbCharHacks->Controls->Add(this->ddbIFS);
			this->gbCharHacks->Controls->Add(this->cbLockItemVac);
			this->gbCharHacks->Controls->Add(this->nudIceGuard);
			this->gbCharHacks->Controls->Add(this->cbIceGuard);
			this->gbCharHacks->Controls->Add(this->cbIFS);
			this->gbCharHacks->Controls->Add(this->cbMercedesCombo);
			this->gbCharHacks->Controls->Add(this->cbNDMining);
			this->gbCharHacks->Controls->Add(this->cbNFA);
			this->gbCharHacks->Controls->Add(this->cbFMA);
			this->gbCharHacks->Controls->Add(this->cbUA);
			this->gbCharHacks->Controls->Add(this->cbItemVac);
			this->gbCharHacks->Controls->Add(this->cb50SecGM);
			this->gbCharHacks->Controls->Add(this->cbNDAllAttacks);
			this->gbCharHacks->Controls->Add(this->cbUnlimitedMorph);
			this->gbCharHacks->Controls->Add(this->cbDojangGodmode);
			this->gbCharHacks->Controls->Add(this->cbNoKB);
			this->gbCharHacks->Controls->Add(this->cbFusionAttack);
			this->gbCharHacks->Controls->Add(this->cbPerfectLoot);
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
			this->ddbIFS->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ddbIFS_SelectedIndexChanged);
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
			// cbIceGuard
			// 
			this->cbIceGuard->AutoSize = true;
			this->cbIceGuard->Location = System::Drawing::Point(6, 32);
			this->cbIceGuard->Name = L"cbIceGuard";
			this->cbIceGuard->Size = System::Drawing::Size(73, 17);
			this->cbIceGuard->TabIndex = 18;
			this->cbIceGuard->Text = L"Ice Guard";
			this->InfoToolTip->SetToolTip(this->cbIceGuard, L"Another godmode, use with caution, a to high amount could AB");
			this->cbIceGuard->UseVisualStyleBackColor = true;
			this->cbIceGuard->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbIceGuard_CheckedChanged);
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
			// cbMercedesCombo
			// 
			this->cbMercedesCombo->AutoSize = true;
			this->cbMercedesCombo->Location = System::Drawing::Point(159, 118);
			this->cbMercedesCombo->Name = L"cbMercedesCombo";
			this->cbMercedesCombo->Size = System::Drawing::Size(137, 17);
			this->cbMercedesCombo->TabIndex = 14;
			this->cbMercedesCombo->Text = L"Mercedes Perfect Skills";
			this->InfoToolTip->SetToolTip(this->cbMercedesCombo, L"Lets you use Aerial Barrage, Parting Shot, etc, without using Rising Rush first");
			this->cbMercedesCombo->UseVisualStyleBackColor = true;
			this->cbMercedesCombo->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbMercedesCombo_CheckedChanged);
			// 
			// cbNDMining
			// 
			this->cbNDMining->AutoSize = true;
			this->cbNDMining->Location = System::Drawing::Point(6, 118);
			this->cbNDMining->Name = L"cbNDMining";
			this->cbNDMining->Size = System::Drawing::Size(104, 17);
			this->cbNDMining->TabIndex = 13;
			this->cbNDMining->Text = L"No Delay Mining";
			this->InfoToolTip->SetToolTip(this->cbNDMining, L"Removes the delay on mining");
			this->cbNDMining->UseVisualStyleBackColor = true;
			this->cbNDMining->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbNDMining_CheckedChanged);
			// 
			// cbNFA
			// 
			this->cbNFA->AutoSize = true;
			this->cbNFA->Location = System::Drawing::Point(159, 102);
			this->cbNFA->Name = L"cbNFA";
			this->cbNFA->Size = System::Drawing::Size(99, 17);
			this->cbNFA->TabIndex = 12;
			this->cbNFA->Text = L"No Final Attack";
			this->InfoToolTip->SetToolTip(this->cbNFA, L"Removes your ability to have a FinalAttack, use it with FMA to not get DC\'d");
			this->cbNFA->UseVisualStyleBackColor = true;
			this->cbNFA->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbNFA_CheckedChanged);
			// 
			// cbFMA
			// 
			this->cbFMA->AutoSize = true;
			this->cbFMA->Location = System::Drawing::Point(159, 84);
			this->cbFMA->Name = L"cbFMA";
			this->cbFMA->Size = System::Drawing::Size(100, 17);
			this->cbFMA->TabIndex = 11;
			this->cbFMA->Text = L"Full Map Attack";
			this->InfoToolTip->SetToolTip(this->cbFMA, L"Let\'s you hit the whole map that\'s vissible for you, also called FMA");
			this->cbFMA->UseVisualStyleBackColor = true;
			this->cbFMA->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbFMA_CheckedChanged);
			// 
			// cbUA
			// 
			this->cbUA->AutoSize = true;
			this->cbUA->Location = System::Drawing::Point(6, 102);
			this->cbUA->Name = L"cbUA";
			this->cbUA->Size = System::Drawing::Size(103, 17);
			this->cbUA->TabIndex = 8;
			this->cbUA->Text = L"Unlimited Attack";
			this->InfoToolTip->SetToolTip(this->cbUA, L"Let\'s you attack without stopping after 100 attacks, (very small chance on a A/B)"
				L"");
			this->cbUA->UseVisualStyleBackColor = true;
			this->cbUA->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbUA_CheckedChanged);
			// 
			// cbItemVac
			// 
			this->cbItemVac->AutoSize = true;
			this->cbItemVac->Location = System::Drawing::Point(6, 84);
			this->cbItemVac->Name = L"cbItemVac";
			this->cbItemVac->Size = System::Drawing::Size(68, 17);
			this->cbItemVac->TabIndex = 10;
			this->cbItemVac->Text = L"Item Vac";
			this->InfoToolTip->SetToolTip(this->cbItemVac, L"All the items drop below your feet");
			this->cbItemVac->UseVisualStyleBackColor = true;
			this->cbItemVac->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbItemVac_CheckedChanged);
			// 
			// cb50SecGM
			// 
			this->cb50SecGM->AutoSize = true;
			this->cb50SecGM->Location = System::Drawing::Point(159, 14);
			this->cb50SecGM->Name = L"cb50SecGM";
			this->cb50SecGM->Size = System::Drawing::Size(132, 17);
			this->cb50SecGM->TabIndex = 9;
			this->cb50SecGM->Text = L"50 Seconds Godmode";
			this->InfoToolTip->SetToolTip(this->cb50SecGM, L"After you get hit you have godmode for 50 seconds");
			this->cb50SecGM->UseVisualStyleBackColor = true;
			this->cb50SecGM->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb50SecGM_CheckedChanged);
			// 
			// cbNDAllAttacks
			// 
			this->cbNDAllAttacks->AutoSize = true;
			this->cbNDAllAttacks->Location = System::Drawing::Point(6, 66);
			this->cbNDAllAttacks->Name = L"cbNDAllAttacks";
			this->cbNDAllAttacks->Size = System::Drawing::Size(104, 17);
			this->cbNDAllAttacks->TabIndex = 8;
			this->cbNDAllAttacks->Text = L"GenericNoDelay";
			this->InfoToolTip->SetToolTip(this->cbNDAllAttacks, L"Removes the AttackAnimation and the delay between attacks, and it gives Unlimited"
				L" MP");
			this->cbNDAllAttacks->UseVisualStyleBackColor = true;
			this->cbNDAllAttacks->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbNDAllAttacks_CheckedChanged);
			// 
			// cbUnlimitedMorph
			// 
			this->cbUnlimitedMorph->AutoSize = true;
			this->cbUnlimitedMorph->Location = System::Drawing::Point(159, 49);
			this->cbUnlimitedMorph->Name = L"cbUnlimitedMorph";
			this->cbUnlimitedMorph->Size = System::Drawing::Size(102, 17);
			this->cbUnlimitedMorph->TabIndex = 7;
			this->cbUnlimitedMorph->Text = L"Unlimited Morph";
			this->InfoToolTip->SetToolTip(this->cbUnlimitedMorph, L"Kaizers can get in their final form without having the morph gauge filled");
			this->cbUnlimitedMorph->UseVisualStyleBackColor = true;
			this->cbUnlimitedMorph->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbUnlimitedMorph_CheckedChanged);
			// 
			// cbDojangGodmode
			// 
			this->cbDojangGodmode->AutoSize = true;
			this->cbDojangGodmode->Location = System::Drawing::Point(6, 14);
			this->cbDojangGodmode->Name = L"cbDojangGodmode";
			this->cbDojangGodmode->Size = System::Drawing::Size(109, 17);
			this->cbDojangGodmode->TabIndex = 6;
			this->cbDojangGodmode->Text = L"Dojang Godmode";
			this->InfoToolTip->SetToolTip(this->cbDojangGodmode, L"Let\'s you get missed 7 times before taking a hit");
			this->cbDojangGodmode->UseVisualStyleBackColor = true;
			this->cbDojangGodmode->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbDojangGodmode_CheckedChanged);
			// 
			// cbNoKB
			// 
			this->cbNoKB->AutoSize = true;
			this->cbNoKB->Location = System::Drawing::Point(6, 49);
			this->cbNoKB->Name = L"cbNoKB";
			this->cbNoKB->Size = System::Drawing::Size(99, 17);
			this->cbNoKB->TabIndex = 5;
			this->cbNoKB->Text = L"No KnockBack";
			this->InfoToolTip->SetToolTip(this->cbNoKB, L"You won\'t get Knocked Back when you get hit");
			this->cbNoKB->UseVisualStyleBackColor = true;
			this->cbNoKB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbNoKB_CheckedChanged);
			// 
			// cbFusionAttack
			// 
			this->cbFusionAttack->AutoSize = true;
			this->cbFusionAttack->Location = System::Drawing::Point(159, 66);
			this->cbFusionAttack->Name = L"cbFusionAttack";
			this->cbFusionAttack->Size = System::Drawing::Size(91, 17);
			this->cbFusionAttack->TabIndex = 0;
			this->cbFusionAttack->Text = L"Fusion Attack";
			this->InfoToolTip->SetToolTip(this->cbFusionAttack, L"If you have an atack that hits 10 mobs 2 times, with fusion you will hit 1 mob 20"
				L" times");
			this->cbFusionAttack->UseVisualStyleBackColor = true;
			this->cbFusionAttack->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbFusionAttack_CheckedChanged);
			// 
			// cbPerfectLoot
			// 
			this->cbPerfectLoot->AutoSize = true;
			this->cbPerfectLoot->Location = System::Drawing::Point(159, 31);
			this->cbPerfectLoot->Name = L"cbPerfectLoot";
			this->cbPerfectLoot->Size = System::Drawing::Size(84, 17);
			this->cbPerfectLoot->TabIndex = 1;
			this->cbPerfectLoot->Text = L"Perfect Loot";
			this->InfoToolTip->SetToolTip(this->cbPerfectLoot, L"Removes drop and loot animation and loots faster");
			this->cbPerfectLoot->UseVisualStyleBackColor = true;
			this->cbPerfectLoot->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbPerfectLoot_CheckedChanged);
			// 
			// MobHacks
			// 
			this->MobHacks->Controls->Add(this->cbAutoAggro);
			this->MobHacks->Controls->Add(this->cbScareMobs);
			this->MobHacks->Controls->Add(this->cbNoMobs);
			this->MobHacks->Controls->Add(this->cbFasterMobs);
			this->MobHacks->Controls->Add(this->cbMobDisarm);
			this->MobHacks->Controls->Add(this->cbJumpRight);
			this->MobHacks->Controls->Add(this->cbWalkRight);
			this->MobHacks->Controls->Add(this->cbVacRight);
			this->MobHacks->Location = System::Drawing::Point(7, 174);
			this->MobHacks->Name = L"MobHacks";
			this->MobHacks->Size = System::Drawing::Size(310, 93);
			this->MobHacks->TabIndex = 0;
			this->MobHacks->TabStop = false;
			this->MobHacks->Text = L"Mob";
			// 
			// cbAutoAggro
			// 
			this->cbAutoAggro->AutoSize = true;
			this->cbAutoAggro->Enabled = false;
			this->cbAutoAggro->Location = System::Drawing::Point(159, 19);
			this->cbAutoAggro->Name = L"cbAutoAggro";
			this->cbAutoAggro->Size = System::Drawing::Size(79, 17);
			this->cbAutoAggro->TabIndex = 10;
			this->cbAutoAggro->Text = L"Auto Aggro";
			this->InfoToolTip->SetToolTip(this->cbAutoAggro, L"Let\'s all mobs get aggresive at you");
			this->cbAutoAggro->UseVisualStyleBackColor = true;
			this->cbAutoAggro->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbAutoAggro_CheckedChanged);
			// 
			// cbScareMobs
			// 
			this->cbScareMobs->AutoSize = true;
			this->cbScareMobs->Location = System::Drawing::Point(159, 55);
			this->cbScareMobs->Name = L"cbScareMobs";
			this->cbScareMobs->Size = System::Drawing::Size(83, 17);
			this->cbScareMobs->TabIndex = 9;
			this->cbScareMobs->Text = L"Scare Mobs";
			this->InfoToolTip->SetToolTip(this->cbScareMobs, L"Freezes mobs");
			this->cbScareMobs->UseVisualStyleBackColor = true;
			this->cbScareMobs->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbScareMobs_CheckedChanged);
			// 
			// cbNoMobs
			// 
			this->cbNoMobs->AutoSize = true;
			this->cbNoMobs->Location = System::Drawing::Point(159, 37);
			this->cbNoMobs->Name = L"cbNoMobs";
			this->cbNoMobs->Size = System::Drawing::Size(69, 17);
			this->cbNoMobs->TabIndex = 7;
			this->cbNoMobs->Text = L"No Mobs";
			this->InfoToolTip->SetToolTip(this->cbNoMobs, L"After ccing with NoMobs enabled, there will be no more mobs in the map");
			this->cbNoMobs->UseVisualStyleBackColor = true;
			this->cbNoMobs->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbNoMobs_CheckedChanged);
			// 
			// cbFasterMobs
			// 
			this->cbFasterMobs->AutoSize = true;
			this->cbFasterMobs->Location = System::Drawing::Point(159, 73);
			this->cbFasterMobs->Name = L"cbFasterMobs";
			this->cbFasterMobs->Size = System::Drawing::Size(84, 17);
			this->cbFasterMobs->TabIndex = 6;
			this->cbFasterMobs->Text = L"Faster Mobs";
			this->InfoToolTip->SetToolTip(this->cbFasterMobs, L"Mobs walk faster");
			this->cbFasterMobs->UseVisualStyleBackColor = true;
			this->cbFasterMobs->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbFasterMobs_CheckedChanged);
			// 
			// cbMobDisarm
			// 
			this->cbMobDisarm->AutoSize = true;
			this->cbMobDisarm->Location = System::Drawing::Point(6, 73);
			this->cbMobDisarm->Name = L"cbMobDisarm";
			this->cbMobDisarm->Size = System::Drawing::Size(101, 17);
			this->cbMobDisarm->TabIndex = 5;
			this->cbMobDisarm->Text = L"Full Mob Disarm";
			this->InfoToolTip->SetToolTip(this->cbMobDisarm, L"Makes mobs unable to use magical attack and other skills");
			this->cbMobDisarm->UseVisualStyleBackColor = true;
			this->cbMobDisarm->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbMobDisarm_CheckedChanged);
			// 
			// cbJumpRight
			// 
			this->cbJumpRight->AutoSize = true;
			this->cbJumpRight->Location = System::Drawing::Point(6, 55);
			this->cbJumpRight->Name = L"cbJumpRight";
			this->cbJumpRight->Size = System::Drawing::Size(131, 17);
			this->cbJumpRight->TabIndex = 4;
			this->cbJumpRight->Text = L"Jump Unrandom Right";
			this->InfoToolTip->SetToolTip(this->cbJumpRight, L"All jumping mobs jump right");
			this->cbJumpRight->UseVisualStyleBackColor = true;
			this->cbJumpRight->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbJumpRight_CheckedChanged);
			// 
			// cbWalkRight
			// 
			this->cbWalkRight->AutoSize = true;
			this->cbWalkRight->Location = System::Drawing::Point(6, 37);
			this->cbWalkRight->Name = L"cbWalkRight";
			this->cbWalkRight->Size = System::Drawing::Size(131, 17);
			this->cbWalkRight->TabIndex = 2;
			this->cbWalkRight->Text = L"Walk Unrandom Right";
			this->InfoToolTip->SetToolTip(this->cbWalkRight, L"All walking mobs walk right");
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
			this->InfoToolTip->SetToolTip(this->cbVacRight, L"Everyone in the map walk right, you too!");
			this->cbVacRight->UseVisualStyleBackColor = true;
			this->cbVacRight->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbVacRight_CheckedChanged);
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
			this->Text = L"WatyBot 3.4 - CCPLZ! - EMS 94.1";
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
		Void cbFusionAttack_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbNoKB_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbPerfectLoot_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbVacRight_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbWalkRight_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbJumpRight_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbNoBG_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbMobDisarm_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbJDA_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbPinTyper_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbDojangGodmode_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbUnlimitedMorph_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbFasterMobs_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbNDAllAttacks_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbNoMobs_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbUA_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbSitHack_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cb50SecGM_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbLogoSkipper_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbViewSwears_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbLockItemVac_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		Void cbItemVac_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbFMA_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbScareMobs_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbFLACC_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbCPUHack_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbNFA_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbAutoAggro_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbNDMining_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbHideDamage_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbMercedesCombo_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbNoFadeStages_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbNoCCBlueBoxes_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbMouseFly_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbIceGuard_CheckedChanged(Object^ sender, EventArgs^ e);
		Void cbIFS_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		Void ddbIFS_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);

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
