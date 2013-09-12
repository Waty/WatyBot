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
void MainForm::cbFusionAttack_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbFusionAttack->Checked = Hacks::FusionAttack.Enable(cbFusionAttack->Checked);
}
void MainForm::cbNoKB_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbNoKB->Checked = Hacks::NoKB.Enable(cbNoKB->Checked);
}
void MainForm::cbPerfectLoot_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbPerfectLoot->Checked = Hacks::PerfectLoot.Enable(cbPerfectLoot->Checked);
	cbPerfectLoot->Checked = Hacks::InstantAirLoot.Enable(cbPerfectLoot->Checked);
}
void MainForm::cbVacRight_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbVacRight->Checked = Hacks::VacRight.Enable(cbVacRight->Checked);
}
void MainForm::cbWalkRight_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbWalkRight->Checked = Hacks::WalkRight.Enable(cbWalkRight->Checked);
}
void MainForm::cbJumpRight_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbJumpRight->Checked = Hacks::JumpRight.Enable(cbJumpRight->Checked);
}
void MainForm::cbMobDisarm_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbMobDisarm->Checked = Hacks::MobDisarm.Enable(cbMobDisarm->Checked);
}
void MainForm::cbNoBG_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbNoBG->Checked = Hacks::NoBG.Enable(cbNoBG->Checked);
}
void MainForm::cbJDA_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbJDA->Checked = Hacks::JDA.Enable(cbJDA->Checked);
}
void MainForm::cbPinTyper_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbPinTyper->Checked = Hacks::PinTyper.Enable(cbPinTyper->Checked);
	cbPinTyper->Checked = Hacks::PicTyper1.Enable(cbPinTyper->Checked);
	cbPinTyper->Checked = Hacks::PicTyper2.Enable(cbPinTyper->Checked);
}
void MainForm::cbDojangGodmode_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbDojangGodmode->Checked = Hacks::DojangGodmode.Enable(cbDojangGodmode->Checked);
}
void MainForm::cbIceGuard_CheckedChanged(Object^ sender, EventArgs^ e)
{
	this->nudIceGuard->Enabled = !this->cbIceGuard->Checked;
	Hacks::SetIceGuardLimit((int) nudIceGuard->Value);
	cbIceGuard->Checked = Hacks::IceGuard.Enable(cbIceGuard->Checked);
}
void MainForm::cbUnlimitedMorph_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbUnlimitedMorph->Checked = Hacks::UnlimitedMorph.Enable(cbUnlimitedMorph->Checked);
}
void MainForm::cbFasterMobs_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbFasterMobs->Checked = Hacks::FasterMobs.Enable(cbFasterMobs->Checked);
}
void MainForm::cbNDAllAttacks_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbNDAllAttacks->Checked = Hacks::NDAllAttacks.Enable(cbNDAllAttacks->Checked);
}
void MainForm::cbNoMobs_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbNoMobs->Checked = Hacks::NoMobs.Enable(cbNoMobs->Checked);
}
void MainForm::cbAutoAggro_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbAutoAggro->Checked = Hacks::AutoAggro.Enable(cbAutoAggro->Checked);
}
void MainForm::cbSitHack_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbSitHack->Checked = Hacks::SitHack.Enable(cbSitHack->Checked);
}
void MainForm::cb50SecGM_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cb50SecGM->Checked = Hacks::SecondGodmode.Enable(cb50SecGM->Checked);
}
void MainForm::cbLogoSkipper_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbLogoSkipper->Checked = Hacks::LogoSkipper.Enable(cbLogoSkipper->Checked);
}
void MainForm::cbViewSwears_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbViewSwears->Checked = Hacks::NoSwears.Enable(cbViewSwears->Checked);
}
void MainForm::cbItemVac_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbItemVac->Checked = Hacks::ItemVac.Enable(cbItemVac->Checked);
}
void MainForm::cbLockItemVac_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	Hacks::LockItemVac(cbLockItemVac->Checked);
}
void MainForm::cbFMA_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbNFA->Checked = cbFMA->Checked;
	cbItemVac->Checked = cbFMA->Checked;
	cbItemVac->Enabled = !cbFMA->Checked;
	cbFMA->Checked = Hacks::FMA.Enable(cbFMA->Checked);
}
void MainForm::cbScareMobs_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbScareMobs->Checked = Hacks::ScareMobs.Enable(cbScareMobs->Checked);
}
void MainForm::cbFLACC_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbFLACC->Checked = Hacks::FaceLeftAfterCC.Enable(cbFLACC->Checked);
}
void MainForm::cbCPUHack_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbCPUHack->Checked = Hacks::CPUHack.Enable(cbCPUHack->Checked);
}
void MainForm::cbUA_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbUA->Checked = Hacks::UnlimitedAttack.Enable(cbUA->Checked);
}
void MainForm::cbNFA_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbNFA->Checked = Hacks::DisableFinalAttack.Enable(cbNFA->Checked);
}
void MainForm::cbNDMining_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbNDMining->Checked = Hacks::NDMining.Enable(cbNDMining->Checked);
}
void MainForm::cbHideDamage_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbHideDamage->Checked = Hacks::HideDamage1.Enable(cbHideDamage->Checked);
	cbHideDamage->Checked = Hacks::HideDamage2.Enable(cbHideDamage->Checked);
}
void MainForm::cbMercedesCombo_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbMercedesCombo->Checked = Hacks::MercedesCombo.Enable(cbMercedesCombo->Checked);
}
void MainForm::cbNoFadeStages_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbNoFadeStages->Checked = Hacks::NoFadeStages.Enable(cbNoFadeStages->Checked);
}
void MainForm::cbMouseFly_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbMouseFly->Checked = Hacks::MouseFly.Enable(cbMouseFly->Checked);
}
void MainForm::cbNoCCBlueBoxes_CheckedChanged(Object^ sender, EventArgs^ e)
{
	cbNoCCBlueBoxes->Checked = Hacks::NoCCBoxes.Enable(cbNoCCBlueBoxes->Checked);
}
void MainForm::cbIFS_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::InstantFinalSlash1.Enable(cbIFS->Checked);
	Hacks::InstantFinalSlash2.Enable(cbIFS->Checked);
	ddbIFS->Enabled = !cbIFS->Checked;
}
void MainForm::ddbIFS_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::SetIFSClass(ddbIFS->SelectedIndex);
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
		if (cbAutoHP->Checked && CMS::CharHP <= nudAutoHP->Value) CMS::SpamSwitch(ddbAutoHPKey->SelectedIndex);
		if (cbAutoMP->Checked && CMS::CharMP <= nudAutoMP->Value) CMS::SpamSwitch(ddbAutoMPKey->SelectedIndex);

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
	this->HPLabel->Text = "HP: " + CMS::CharHP + "/" + CMS::MaxHP;
	this->MPLabel->Text = "MP: " + CMS::CharMP + "/" + CMS::MaxMP;
	this->EXPLabel->Text = "EXP: " + CMS::CharEXP.ToString("f2") + "%";

	static int lengtOfBars = 223;
	double HPBarLength = ((double) CMS::CharHP / (double) CMS::MaxHP) * lengtOfBars;
	this->HPForeground->Width = HPBarLength;
	double MPBarLength = ((double) CMS::CharMP / (double) CMS::MaxMP) * lengtOfBars;
	this->MPForeground->Width = MPBarLength;
	double EXPBarLength = (CMS::CharEXP / 100) * lengtOfBars;
	this->EXPForeground->Width = EXPBarLength;
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
	cbSPControl->Checked = Hacks::SpawnControlCheck.Enable(cbSPControl->Checked);
	cbSPControl->Checked = Hacks::SpawnControlCave.Enable(cbSPControl->Checked);
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
			this->cbFMA->Checked = !this->cbFMA->Checked;
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
			this->cbMouseFly->Checked = !this->cbMouseFly->Checked;
			Sleep(250);
		}
	}
}
