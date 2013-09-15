#pragma once
#include "MainForm.h"
#include "Hacks.h"
#include "MapleStory.h"
#include "AutoSkill.h"
#include "ChangeChannel.h"
#include "SPControlDialog.h"
#include "PacketDialog.h"
#include "StopWatch.h"
#include "Log.h"

using namespace WatyBotRevamp;

//Hack CheckBoxes
void MainForm::FusionAttack_CheckedChanged(Object^ sender, EventArgs^ e)
{
	FusionAttack->Checked = Hacks::FusionAttack.Enable(FusionAttack->Checked);
}
void MainForm::NoKB_CheckedChanged(Object^ sender, EventArgs^ e)
{
	NoKB->Checked = Hacks::NoKB.Enable(NoKB->Checked);
}
void MainForm::PerfectLoot_CheckedChanged(Object^ sender, EventArgs^ e)
{
	PerfectLoot->Checked = Hacks::PerfectLoot.Enable(PerfectLoot->Checked);
}
void MainForm::VacRight_CheckedChanged(Object^ sender, EventArgs^ e)
{
	VacRight->Checked = Hacks::VacRight.Enable(VacRight->Checked);
}
void MainForm::WalkRight_CheckedChanged(Object^ sender, EventArgs^ e)
{
	WalkRight->Checked = Hacks::WalkRight.Enable(WalkRight->Checked);
}
void MainForm::JumpRight_CheckedChanged(Object^ sender, EventArgs^ e)
{
	JumpRight->Checked = Hacks::JumpRight.Enable(JumpRight->Checked);
}
void MainForm::MobDisarm_CheckedChanged(Object^ sender, EventArgs^ e)
{
	MobDisarm->Checked = Hacks::MobDisarm.Enable(MobDisarm->Checked);
}
void MainForm::NoBackground_CheckedChanged(Object^ sender, EventArgs^ e)
{
	NoBackground->Checked = Hacks::NoBackground.Enable(NoBackground->Checked);
}
void MainForm::JDA_CheckedChanged(Object^ sender, EventArgs^ e)
{
	JDA->Checked = Hacks::JDA.Enable(JDA->Checked);
}
void MainForm::PinPicTyper_CheckedChanged(Object^ sender, EventArgs^ e)
{
	PinPicTyper->Checked = Hacks::PinPicTyper.Enable(PinPicTyper->Checked);
}
void MainForm::DojangGodmode_CheckedChanged(Object^ sender, EventArgs^ e)
{
	DojangGodmode->Checked = Hacks::DojangGodmode.Enable(DojangGodmode->Checked);
}
void MainForm::IceGuard_CheckedChanged(Object^ sender, EventArgs^ e)
{
	this->nudIceGuard->Enabled = !this->IceGuard->Checked;
	Hacks::SetIceGuardLimit((int) nudIceGuard->Value);
	IceGuard->Checked = Hacks::IceGuard.Enable(IceGuard->Checked);
}
void MainForm::UnlimitedMorph_CheckedChanged(Object^ sender, EventArgs^ e)
{
	UnlimitedMorph->Checked = Hacks::UnlimitedMorph.Enable(UnlimitedMorph->Checked);
}
void MainForm::FasterMobs_CheckedChanged(Object^ sender, EventArgs^ e)
{
	FasterMobs->Checked = Hacks::FasterMobs.Enable(FasterMobs->Checked);
}
void MainForm::NDAllAttacks_CheckedChanged(Object^ sender, EventArgs^ e)
{
	NDAllAttacks->Checked = Hacks::NDAllAttacks.Enable(NDAllAttacks->Checked);
}
void MainForm::NoMobs_CheckedChanged(Object^ sender, EventArgs^ e)
{
	NoMobs->Checked = Hacks::NoMobs.Enable(NoMobs->Checked);
}
void MainForm::AutoAggro_CheckedChanged(Object^ sender, EventArgs^ e)
{
	AutoAggro->Checked = Hacks::AutoAggro.Enable(AutoAggro->Checked);
}
void MainForm::SitHack_CheckedChanged(Object^ sender, EventArgs^ e)
{
	SitHack->Checked = Hacks::SitHack.Enable(SitHack->Checked);
}
void MainForm::SecondGodmode_CheckedChanged(Object^ sender, EventArgs^ e)
{
	SecondGodmode->Checked = Hacks::SecondGodmode.Enable(SecondGodmode->Checked);
}
void MainForm::LogoSkipper_CheckedChanged(Object^ sender, EventArgs^ e)
{
	LogoSkipper->Checked = Hacks::LogoSkipper.Enable(LogoSkipper->Checked);
}
void MainForm::ViewSwears_CheckedChanged(Object^ sender, EventArgs^ e)
{
	ViewSwears->Checked = Hacks::NoSwears.Enable(ViewSwears->Checked);
}
void MainForm::ItemVac_CheckedChanged(Object^ sender, EventArgs^ e)
{
	ItemVac->Checked = Hacks::ItemVac.Enable(ItemVac->Checked);
}
void MainForm::cbLockItemVac_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	Hacks::LockItemVac(cbLockItemVac->Checked);
}
void MainForm::FMA_CheckedChanged(Object^ sender, EventArgs^ e)
{
	DisableFinalAttack->Checked = FMA->Checked;
	ItemVac->Checked = FMA->Checked;
	ItemVac->Enabled = !FMA->Checked;
	FMA->Checked = Hacks::FMA.Enable(FMA->Checked);
}
void MainForm::ScareMobs_CheckedChanged(Object^ sender, EventArgs^ e)
{
	ScareMobs->Checked = Hacks::ScareMobs.Enable(ScareMobs->Checked);
}
void MainForm::FaceLeftAfterCC_CheckedChanged(Object^ sender, EventArgs^ e)
{
	FaceLeftAfterCC->Checked = Hacks::FaceLeftAfterCC.Enable(FaceLeftAfterCC->Checked);
}
void MainForm::CPUHack_CheckedChanged(Object^ sender, EventArgs^ e)
{
	CPUHack->Checked = Hacks::CPUHack.Enable(CPUHack->Checked);
}
void MainForm::UnlimitedAttack_CheckedChanged(Object^ sender, EventArgs^ e)
{
	UnlimitedAttack->Checked = Hacks::UnlimitedAttack.Enable(UnlimitedAttack->Checked);
}
void MainForm::DisableFinalAttack_CheckedChanged(Object^ sender, EventArgs^ e)
{
	DisableFinalAttack->Checked = Hacks::DisableFinalAttack.Enable(DisableFinalAttack->Checked);
}
void MainForm::NDMining_CheckedChanged(Object^ sender, EventArgs^ e)
{
	NDMining->Checked = Hacks::NDMining.Enable(NDMining->Checked);
}
void MainForm::HideDamage_CheckedChanged(Object^ sender, EventArgs^ e)
{
	HideDamage->Checked = Hacks::HideDamage.Enable(HideDamage->Checked);
}
void MainForm::MercedesCombo_CheckedChanged(Object^ sender, EventArgs^ e)
{
	MercedesCombo->Checked = Hacks::MercedesCombo.Enable(MercedesCombo->Checked);
}
void MainForm::NoFadeStages_CheckedChanged(Object^ sender, EventArgs^ e)
{
	NoFadeStages->Checked = Hacks::NoFadeStages.Enable(NoFadeStages->Checked);
}
void MainForm::MouseFly_CheckedChanged(Object^ sender, EventArgs^ e)
{
	MouseFly->Checked = Hacks::MouseFly.Enable(MouseFly->Checked);
}
void MainForm::NoCCBoxes_CheckedChanged(Object^ sender, EventArgs^ e)
{
	NoCCBoxes->Checked = Hacks::NoCCBoxes.Enable(NoCCBoxes->Checked);
}
void MainForm::cbIFS_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::InstantFinalSlash.Enable(cbIFS->Checked);
	Hacks::SetIFSClass(ddbIFS->SelectedIndex);
	ddbIFS->Enabled = !cbIFS->Checked;
}

//AutoBot Events
StopWatch<milliseconds> BreathCounter(milliseconds(5500));
Void MainForm::cbAutoAttack_CheckedChanged(Object^ sender, EventArgs^ e)
{
	this->nudAutoAttack->Enabled = !cbAutoAttack->Checked;
	this->nudSAWSIL->Enabled = !cbAutoAttack->Checked;
	this->ddbAutoAttackKey->Enabled = !cbAutoAttack->Checked;

	CMS::SAWSIL = (int) nudSAWSIL->Value;
	this->tAutoAttack->Interval = (int) nudAutoAttack->Value;
	this->tAutoAttack->Enabled = cbAutoAttack->Checked;
}
Void MainForm::tAutoAttack_Tick(Object^ sender, EventArgs^ e)
{
	if (CMS::ShouldAttack())
	{
		BreathCounter.Start();
		CMS::SpamSwitch(ddbAutoAttackKey->SelectedIndex);
	}
}
Void MainForm::cbAutoLoot_CheckedChanged(Object^ sender, EventArgs^ e)
{
	this->nudAutoLoot->Enabled = !this->cbAutoLoot->Checked;
	this->ddbAutoLootKey->Enabled = !this->cbAutoLoot->Checked;
	this->cbOLWNA->Enabled = !this->cbAutoLoot->Checked;

	CMS::OLWNA = cbOLWNA->Checked;
	tAutoLoot->Interval = (int) nudAutoLoot->Value;
	tAutoLoot->Enabled = cbAutoLoot->Checked;
}
Void MainForm::tAutoLoot_Tick(Object^ sender, EventArgs^ e)
{
	if (CMS::ShouldLoot())
	{
		CMS::Tubi = 0;
		CMS::SpamSwitch(ddbAutoLootKey->SelectedIndex);
	}
}
Void MainForm::cbAutoHP_CheckedChanged(Object^ sender, EventArgs^ e)
{
	nudAutoHP->Enabled = !cbAutoHP->Checked;
	ddbAutoHPKey->Enabled = !cbAutoHP->Checked;
}
Void MainForm::cbAutoMP_CheckedChanged(Object^ sender, EventArgs^ e)
{
	nudAutoMP->Enabled = !cbAutoMP->Checked;
	ddbAutoMPKey->Enabled = !cbAutoMP->Checked;
}
Void MainForm::cbCCPeople_CheckedChanged(Object^ sender, EventArgs^ e)
{
	nudCCPeople->Enabled = !cbCCPeople->Checked;
}
Void MainForm::cbCCTimed_CheckedChanged(Object^ sender, EventArgs^ e)
{
	this->ddbTimedType->Enabled = !this->cbCCTimed->Checked;
	this->nudCCTimed->Enabled = !this->cbCCTimed->Checked;

	tTimedCC->Interval = (int) nudCCTimed->Value * 1000;
	tTimedCC->Enabled = cbCCTimed->Checked;
}
Void MainForm::tTimedCC_Tick(Object^ sender, EventArgs^ e)
{
	CC::CCSwitch((CCType) ddbTimedType->SelectedIndex);
}
Void MainForm::cbCCAttacks_CheckedChanged(Object^ sender, EventArgs^ e)
{
	nudCCAttacks->Enabled = !cbCCAttacks->Checked;
}

//General Trainer events
int TabHeight [] = { 541, 461, 286, 431, 266 };
Void Main(void)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm);
	Application::Exit();
}
Void ShowError(String^ Message)
{
	MainForm::notifyIcon->ShowBalloonTip(1000, "WatyBot", Message, ToolTipIcon::Error);
	Log::WriteLine(Message);
}
Void ShowErrorDialog(String^ Message)
{
	MessageBox::Show(Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
Void MainForm::MainForm_Load(Object^ sender, EventArgs^ e)
{
	Log::WriteLine();
	Log::WriteLine("Starting WatyBot");
	//Initialize the NotifyIcon
	notifyIcon = gcnew NotifyIcon;
	notifyIcon->Icon = SystemIcons::Error;
	notifyIcon->Visible = true;

	//Load all the settings and innitialize all the classes
	LoadSPControl();
	LoadPackets();
	LoadAutoSkill();
	LoadSettings();

	// Fix the size of the tabs
	MainForm::Height = TabHeight[MainTabControl->SelectedTab->TabIndex];
	MainTabControl->Height = TabHeight[MainTabControl->SelectedTab->TabIndex] - 30;
	extern void EnableStatsHook(bool enable);
	EnableStatsHook(true);
	extern void EnableItemHook(bool state);
	EnableItemHook(true);
}
Void MainForm::StatsTimer_Tick(Object^ sender, EventArgs^ e)
{
	this->MobCountLabel->Text = "Mobs: " + CMS::MobCount;
	this->ItemCountLabel->Text = "Items: " + CMS::ItemCount;
	this->PeopleCountLabel->Text = "People: " + CMS::PeopleCount;
	this->CharPosLabel->Text = "CharPos: (" + CMS::CharX + "," + CMS::CharY + ")";
	this->lMapID->Text = "MapID: " + CMS::MapId;
	this->AttackCountLabel->Text = "Attacks: " + CMS::AttackCount;
	this->BreathLabel->Text = "ClientBreath: " + CMS::Breath;
	this->lChannel->Text = "Channel: " + CMS::Channel;
	this->lPetFullness->Text = "PetFullness: " + CMS::PetFullness + "%";
	this->lInGame->Text = "InGame: " + CMS::InGame;
	this->lMSCRC->Text = "MSCRC: " + (CMS::gotMSCRC ? "Bypassed" : "Original!");

	if (CMS::InGame)
	{
		//AutoHP/MP happens here
		if (cbAutoHP->Checked && CMS::CurHP <= nudAutoHP->Value) CMS::SpamSwitch(ddbAutoHPKey->SelectedIndex);
		if (cbAutoMP->Checked && CMS::CurMP <= nudAutoMP->Value) CMS::SpamSwitch(ddbAutoMPKey->SelectedIndex);

		//AutoCC happens here
		if (cbCCPeople->Checked && (CMS::PeopleCount >= (int) nudCCPeople->Value)) CC::CCSwitch(CCType(ddbPeopleType->SelectedIndex));
		if (cbCCAttacks->Checked && (CMS::AttackCount >= (int) nudCCAttacks->Value)) CC::CCSwitch(CCType(ddbAttacksType->SelectedIndex));

		//PetFeeder happens here
		if (cbPetFeeder->Checked && (CMS::PetFullness <= nudPetFeeder->Value)) CMS::SendSwitch(ddbPetFeeder->SelectedIndex);
		MainForm::RedrawStatBars();
		MainForm::HotKeys();
	}
}
Void MainForm::RedrawStatBars()
{
	this->HPLabel->Text = "HP: " + CMS::CurHP + "/" + CMS::MaxHP;
	this->MPLabel->Text = "MP: " + CMS::CurMP + "/" + CMS::MaxMP;
	if (CMS::MaxEXP > 0 && CMS::MaxHP > 0 && CMS::MaxMP > 0)
	{
		auto ExpPercentage = ((double) CMS::CurEXP / (double) CMS::MaxEXP) * 100;
		this->EXPLabel->Text = "EXP: " + ExpPercentage.ToString("f2") + "%";

		static int lengtOfBars = 223;
		this->HPForeground->Width = ((double) CMS::CurHP / (double) CMS::MaxHP) * lengtOfBars;
		this->MPForeground->Width = ((double) CMS::CurMP / (double) CMS::MaxMP) * lengtOfBars;
		this->EXPForeground->Width = (ExpPercentage / 100) * lengtOfBars;
	}
}
Void MainForm::ReloadComboBox(ComboBox^ combobox)
{
	auto selectedItem = combobox->SelectedItem;

	//Clear the box and re-add the items
	combobox->Items->Clear();
	combobox->Items->AddRange(KeyNames);
	for each(Packet^ p in PacketSender::Packets) combobox->Items->Add(p->Name);

	//Restore the selectedindex if it still is valid
	if (selectedItem != nullptr && combobox->Items->Contains(selectedItem)) combobox->SelectedItem = selectedItem;
}
Void MainForm::MainTabControl_SelectedIndexChanged(Object^ sender, EventArgs^ e)
{
	MainForm::Height = TabHeight[MainTabControl->SelectedTab->TabIndex];
	MainTabControl->Height = TabHeight[MainTabControl->SelectedTab->TabIndex] - 30;
}
Void MainForm::MainForm_FormClosing(Object^ sender, Windows::Forms::FormClosingEventArgs^ e)
{
	switch (MessageBox::Show("Close MapleStory too?", "Terminate Maple?", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question))
	{
	case ::DialogResult::Yes:
		Log::WriteLine("Exiting process");
		if (notifyIcon) delete (IDisposable^) notifyIcon;
		SaveSettings();
		TerminateProcess(GetCurrentProcess(), 0);
		ExitProcess(0);
		break;

	case ::DialogResult::Cancel:
		e->Cancel = true;
		break;
	}
}

//Autoskill
Void MainForm::bAutoSkill_Click(Object^ sender, EventArgs^ e)
{
	if (nudAutoSkill->Value == 0) ShowError("The interval can't be 0!");
	else if (ddbAutoSkill->SelectedIndex == -1) ShowError("You must select a key!");
	else
	{
		ListViewItem^ item = gcnew ListViewItem(tbAutoSkill->Text);
		item->SubItems->Add(nudAutoSkill->Value.ToString());
		item->SubItems->Add(ddbAutoSkill->SelectedItem->ToString());
		lvAutoSkill->Items->Add(item);
		AutoSkill::AutoSkills->Add(gcnew AutoSkillEntry(tbAutoSkill->Text, (int) nudAutoSkill->Value, ddbAutoSkill->SelectedIndex));
	}
	Log::WriteLine("Added \"" + tbAutoSkill->Text + "\" to the AutoSkills.");
	AutoSkill::WriteXmlData();
}
Void MainForm::castToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	if (lvSPControl->SelectedItems->Count < 0) return;
	ListViewItem^ i = lvAutoSkill->SelectedItems[0];
	AutoSkill::AutoSkills[lvAutoSkill->Items->IndexOf(i)]->Cast();
}
Void MainForm::deleteToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	if (lvSPControl->SelectedIndices->Count < 0) return;
	AutoSkill::AutoSkills->RemoveAt(lvAutoSkill->SelectedIndices[0]);
	AutoSkill::WriteXmlData();
}
Void MainForm::lvAutoSkill_ItemCheck(Object^ sender, Windows::Forms::ItemCheckEventArgs^ e)
{
	if (e->CurrentValue == CheckState::Checked)
		AutoSkill::AutoSkills[e->Index]->Enabled = false;
	else if (e->CurrentValue == CheckState::Unchecked)
		AutoSkill::AutoSkills[e->Index]->Enabled = true;
}
Void MainForm::lvAutoSkill_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (lvAutoSkill->SelectedIndices->Count <= 0) return;
	if (e->KeyCode == Keys::Delete || e->KeyCode == Keys::Back)
	{
		AutoSkill::AutoSkills->RemoveAt(lvAutoSkill->SelectedIndices[0]);
		AutoSkill::WriteXmlData();
	}
	if (e->KeyCode == Keys::Enter) AutoSkill::AutoSkills[lvAutoSkill->SelectedIndices[0]]->Cast();
}
Void MainForm::LoadAutoSkill()
{
	AutoSkill::ReadXmlData();

	//Clear all AutoSkill controls
	tbAutoSkill->ResetText();
	nudAutoSkill->ResetText();
	ddbAutoSkill->Items->Clear();
	lvAutoSkill->Items->Clear();

	//Update ComboBox
	ddbAutoSkill->Items->AddRange(KeyNames);
	for each(Packet^ p in PacketSender::Packets) ddbAutoSkill->Items->Add(p->Name);

	//Update ListView
	for each(AutoSkillEntry^ as in AutoSkill::AutoSkills)
	{
		ListViewItem^ item = gcnew ListViewItem(as->Name);
		item->SubItems->Add(as->Interval.ToString());
		item->SubItems->Add(ddbAutoSkill->Items[as->keyIndex]->ToString());
		lvAutoSkill->Items->Add(item);
	}
}

//Controls on the PacketSender tab
Void MainForm::bAddPacket_Click(Object^ sender, EventArgs^ e)
{
	auto dialog = gcnew PacketDialog;
	if (dialog->ShowDialog() == ::DialogResult::OK)
	{
		Log::WriteLine("Added \"" + dialog->Packet->Name + "\" to the PacketSender.");
		PacketSender::Add(dialog->Packet);
	}
}
Void MainForm::bEditPacket_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (lvPackets->SelectedItems->Count < 1) return;
	auto dialog = gcnew PacketDialog(PacketSender::Packets[lvPackets->SelectedIndices[0]]);
	if (dialog->ShowDialog() == ::DialogResult::OK)
	{
		PacketSender::Packets[lvPackets->SelectedIndices[0]] = dialog->Packet;
		PacketSender::WriteXmlData();
	}
}
Void MainForm::lvPackets_SelectedIndexChanged(Object^ sender, EventArgs^ e)
{
	if (lvPackets->SelectedItems->Count < 1) return;
	PacketSender::SelectedPacket = PacketSender::Packets[lvPackets->SelectedItems[0]->Index];
}
Void MainForm::bSendPacket_Click(Object^ sender, EventArgs^ e)
{
	if (lvPackets->SelectedItems->Count < 1) return;
	PacketSender::Send();
}
Void MainForm::bDeletePacket_Click(Object^ sender, EventArgs^ e)
{
	if (lvPackets->SelectedIndices->Count <= 0) return;
	PacketSender::Packets->RemoveAt(lvPackets->SelectedIndices[0]);
	PacketSender::WriteXmlData();
}
Void MainForm::lvPackets_KeyDown(Object^ sender, Windows::Forms::KeyEventArgs^ e)
{
	if (lvPackets->SelectedIndices->Count <= 0) return;
	if (e->KeyCode == Keys::Delete || e->KeyCode == Keys::Back)
	{
		PacketSender::Packets->RemoveAt(lvPackets->SelectedIndices[0]);
		PacketSender::WriteXmlData();
	}
	if (e->KeyCode == Keys::Enter) PacketSender::Send();
}
Void MainForm::LoadPackets()
{
	PacketSender::ReadXmlData();
	lvPackets->Items->Clear();
	for each(Packet^ packet in PacketSender::Packets)
	{
		ListViewItem^ i = gcnew ListViewItem(packet->Name);
		i->SubItems->Add(packet->Data[0]);
		lvPackets->Items->Add(i);
	}
	for each (Object^ o in AutoBotGroupBox->Controls)
	{
		if (o->GetType() != ComboBox::typeid || o == ddbPeopleType || o == ddbTimedType || o == ddbAttacksType) continue;
		ReloadComboBox(static_cast<ComboBox^>(o));
	}
	ReloadComboBox(ddbAutoSkill);
}


//controls on SPControl Tab
Void MainForm::bAddSPCLocation_Click(Object^ sender, EventArgs^ e)
{
	String^ name = tbSPCName->Text;
	int mapid = (int) nudSPCMapId->Value;
	int x = (int) nudSPCX->Value;
	int y = (int) nudSPCY->Value;
	Log::WriteLine("Added \"" + name + "\" to SPControl.");
	SPControl::AddLocation(name, mapid, x, y);
}
Void MainForm::cbSPControl_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbSPControl->Checked = Hacks::SpawnControl.Enable(cbSPControl->Checked);
}
Void MainForm::SPControlDeleteItem_Click(Object^ sender, EventArgs^ e)
{
	{
		ListViewItem^ L = lvSPControl->SelectedItems[0];
		switch (MessageBox::Show("Are you sure you want to delete this location?", "Confirm deletion", MessageBoxButtons::YesNo, MessageBoxIcon::Question))
		{
		case ::DialogResult::Yes:
			SPControl::Locations->RemoveAt(lvSPControl->SelectedIndices[0]);
			SPControl::WriteXmlData();
			break;
		}
	}
}
Void MainForm::editLocationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	ListViewItem^ L = lvSPControl->SelectedItems[0];
	int index = lvSPControl->Items->IndexOf(L);
	auto SPCLoc = SPControl::Locations[index];
	EditSPControl^ dlg = gcnew EditSPControl(SPCLoc);
	if (dlg->ShowDialog() == ::DialogResult::OK)
	{
		SPCLoc = dlg->location;
		SPControl::WriteXmlData();
	}
}
Void MainForm::GetSPControlCoordsButton_Click(Object^ sender, EventArgs^ e)
{
	for (int i = 0; i < 10; i++)
	{
		CMS::SpamKey(VK_DOWN);
		Sleep(10);
	}
	this->nudSPCMapId->Value = CMS::MapId;
	this->nudSPCX->Value = CMS::CharX;
	this->nudSPCY->Value = CMS::CharY;
}
Void MainForm::lvSPControl_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (lvSPControl->SelectedIndices->Count <= 0) return;
	if (e->KeyCode == Keys::Delete || e->KeyCode == Keys::Back)
	{
		SPControl::Locations->RemoveAt(lvSPControl->SelectedIndices[0]);
		SPControl::WriteXmlData();
	}
}
Void MainForm::LoadSPControl()
{
	SPControl::ReadXmlData();
	lvSPControl->Items->Clear();
	this->tbSPCName->Clear();
	this->nudSPCMapId->ResetText();
	this->nudSPCX->ResetText();
	this->nudSPCY->ResetText();
	for each(SPControlLocation^ SP in SPControl::Locations)
	{
		ListViewItem^ item = gcnew ListViewItem(SP->Name);
		item->SubItems->Add(SP->MapId.ToString());
		item->SubItems->Add(SP->X.ToString());
		item->SubItems->Add(SP->Y.ToString());
		lvSPControl->Items->Add(item);
	}
}

//Loading/Saving AutoBot settings
Void MainForm::SaveSettings()
{
	Settings::Serialize(this, Path);
}
Void MainForm::LoadSettings()
{
	int count = 0;
	while (!Hacks::ThreadIdFix.Enable(true) && count < 25)
	{
		Sleep(100);
		count++;
	}
	if (!Hacks::ThreadIdFix.Enabled) Log::WriteLine("ThreadIdFix was not enabled!");
	Settings::Deserialize(this, Path);
}
Void MainForm::bSaveSettings_Click(Object^ sender, EventArgs^ e)
{
	SaveSettings();
	SPControl::WriteXmlData();
	PacketSender::WriteXmlData();
	AutoSkill::WriteXmlData();
}
Void MainForm::SettingsWatcher_Changed(System::Object^ sender, System::IO::FileSystemEventArgs^ e)
{
	if (e->FullPath == PacketSender::Path) LoadPackets();
	if (e->FullPath == SPControl::Path) LoadSPControl();
	if (e->FullPath == AutoSkill::Path) LoadAutoSkill();
}

//Hot Keys
int KeyCodes [] = { VK_SHIFT, VK_SPACE, VK_CONTROL, VK_MENU, VK_INSERT, VK_DELETE, VK_HOME, VK_END, VK_PRIOR, VK_NEXT, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6, VK_F7, VK_F8, VK_F9, VK_F10, VK_F11, VK_F12 };
int KeyCodesCount = sizeof(KeyCodes) / 4;
Void MainForm::HotKeys()
{
	if (this->cbHotKeyAttack->Checked)
	{
		if (GetAsyncKeyState(KeyCodes[ddbHotKeyAttack->SelectedIndex]))
		{
			this->cbAutoAttack->Checked = !this->cbAutoAttack->Checked;
			Sleep(250);
		}
	}
	if (this->cbHotKeyLoot->Checked)
	{
		if (GetAsyncKeyState(KeyCodes[ddbHotKeyLoot->SelectedIndex]))
		{
			this->cbAutoLoot->Checked = !this->cbAutoLoot->Checked;
			Sleep(250);
		}
	}
	if (this->cbHotKeyFMA->Checked)
	{
		if (GetAsyncKeyState(KeyCodes[ddbHotKeyFMA->SelectedIndex]))
		{
			this->FMA->Checked = !this->FMA->Checked;
			Sleep(250);
		}
	}
	if (this->cbHotKeyCCPeople->Checked)
	{
		if (GetAsyncKeyState(KeyCodes[ddbHotKeyCCPeople->SelectedIndex]))
		{
			this->cbCCPeople->Checked = !this->cbCCPeople->Checked;
			Sleep(250);
		}
	}
	if (this->cbHotKeySendPacket->Checked)
	{
		if (GetAsyncKeyState(KeyCodes[ddbHotKeySendPacket->SelectedIndex]))
		{
			PacketSender::Send();
			Sleep(250);
		}
	}
	if (this->cbHotKeyMouseFly->Checked)
	{
		if (GetAsyncKeyState(KeyCodes[ddbHotKeyMouseFly->SelectedIndex]))
		{
			this->MouseFly->Checked = !this->MouseFly->Checked;
			Sleep(250);
		}
	}
}
