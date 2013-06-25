#pragma once
#include "MainForm.h"
#include "Defines.h"
#include "Hacks.h"

using namespace Settings;
using namespace WatyBotRevamp;

//Hack CheckBoxes
void MainForm::cbFusionAttack_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbFusionAttack->Checked = Hacks::cmFusionAttack.Enable(cbFusionAttack->Checked);
}
void MainForm::cbNoKB_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbNoKB->Checked = Hacks::cmNoKB.Enable(cbNoKB->Checked);
}
void MainForm::cbPerfectLoot_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbPerfectLoot->Checked = Hacks::cmPerfectLoot.Enable(cbPerfectLoot->Checked);
	cbPerfectLoot->Checked = Hacks::cmInstantAirLoot.Enable(cbPerfectLoot->Checked);
}
void MainForm::cbVacRight_CheckedChanged(Object^  sender, EventArgs^  e)
{
	 cbVacRight->Checked = Hacks::cmVacRight.Enable(cbVacRight->Checked);
}
void MainForm::cbWalkRight_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbWalkRight->Checked = Hacks::cmWalkRight.Enable(cbWalkRight->Checked);
}
void MainForm::cbJumpRight_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbJumpRight->Checked = Hacks::cmJumpRight.Enable(cbJumpRight->Checked);
}
void MainForm::cbMobDisarm_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbMobDisarm->Checked = Hacks::cmMobDisarm.Enable(cbMobDisarm->Checked);
}
void MainForm::cbNoBG_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbNoBG->Checked = Hacks::cmNoBG.Enable(cbNoBG->Checked);
}
void MainForm::cbJDA_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbJDA->Checked = Hacks::cmJDA.Enable(cbJDA->Checked);
}
void MainForm::cbPinTyper_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbPinTyper->Checked = Hacks::cmPinTyper.Enable(cbPinTyper->Checked);
	cbPinTyper->Checked = Hacks::cmPicTyper.Enable(cbPinTyper->Checked);
}
void MainForm::cbDojangGodmode_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbDojangGodmode->Checked = Hacks::cmDojangGodmode.Enable(cbDojangGodmode->Checked);
}
void MainForm::cbIceGuard_CheckedChanged(Object^  sender, EventArgs^  e)
{
	this->nudIceGuard->Enabled = !this->cbIceGuard->Checked;
	Hacks::iIceGuardLimit = (int)nudIceGuard->Value;
	cbIceGuard->Checked = Hacks::cmIceGuard.Enable(cbIceGuard->Checked);
}
void MainForm::cbUnlimitedMorph_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbUnlimitedMorph->Checked = Hacks::cmUnlimitedMorph.Enable(cbUnlimitedMorph->Checked);
}
void MainForm::cbFasterMobs_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbFasterMobs->Checked = Hacks::cmFasterMobs.Enable(cbFasterMobs->Checked);
}
void MainForm::cbNDAllAttacks_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbNDAllAttacks->Checked = Hacks::cmNDAllAttacks.Enable(cbNDAllAttacks->Checked);
}
void MainForm::cbNoMobs_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbNoMobs->Checked = Hacks::cmNoMobs.Enable(cbNoMobs->Checked);
}
void MainForm::cbAutoAggro_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbAutoAggro->Checked = Hacks::cmAutoAggro.Enable(cbAutoAggro->Checked);
}
void MainForm::cbSitHack_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbSitHack->Checked = Hacks::cmSitHack.Enable(cbSitHack->Checked);
}
void MainForm::cb50SecGM_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cb50SecGM->Checked = Hacks::cm50SecGM.Enable(cb50SecGM->Checked);
}
void MainForm::cbLogoSkipper_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbLogoSkipper->Checked = Hacks::cmLogoSkipper.Enable(cbLogoSkipper->Checked);
}
void MainForm::cbViewSwears_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbViewSwears->Checked = Hacks::cmNoSwears.Enable(cbViewSwears->Checked);
}
void MainForm::cbItemVac_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbItemVac->Checked = Hacks::cmItemVac.Enable(cbItemVac->Checked);
}
void MainForm::cbFMA_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbNFA->Checked = cbFMA->Checked;
	cbItemVac->Checked = cbFMA->Checked;
	cbItemVac->Enabled = !cbFMA->Checked;
	cbFMA->Checked = Hacks::cmFMA.Enable(cbFMA->Checked);
}
void MainForm::cbScareMobs_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbScareMobs->Checked = Hacks::cmScareMobs.Enable(cbScareMobs->Checked);
}
void MainForm::cbFLACC_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbFLACC->Checked = Hacks::cmFLACC.Enable(cbFLACC->Checked);
}
void MainForm::cbCPUHack_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbCPUHack->Checked = Hacks::cmCPUHack.Enable(cbCPUHack->Checked);
}
void MainForm::cbUA_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbUA->Checked = Hacks::cmUA.Enable(cbUA->Checked);
}
void MainForm::cbNFA_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbNFA->Checked = Hacks::cmDFA.Enable(cbNFA->Checked);
}
void MainForm::cbNDMining_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbNDMining->Checked = Hacks::cmNDMining.Enable(cbNDMining->Checked);
}
void MainForm::cbHideDamage_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbHideDamage->Checked = Hacks::cmHideDamage1.Enable(cbHideDamage->Checked);
	cbHideDamage->Checked = Hacks::cmHideDamage2.Enable(cbHideDamage->Checked);
}
void MainForm::cbMercedesCombo_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbMercedesCombo->Checked = Hacks::cmMercedesCombo.Enable(cbMercedesCombo->Checked);
}
void MainForm::cbNoFadeStages_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbNoFadeStages->Checked = Hacks::cmNoFadeStages.Enable(cbNoFadeStages->Checked);
}
void MainForm::cbMouseFly_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbMouseFly->Checked = Hacks::cmMouseFly.Enable(cbMouseFly->Checked);
}
void MainForm::cbSkillInjection_CheckedChanged(Object^  sender, EventArgs^  e)
{
	/* Patched :(
	if(ddbSkillInjection->SelectedIndex < 0)
	{
		if(cbSkillInjection->Checked)
		{
			ShowError("Please Select a Skill");
			cbSkillInjection->Checked = false;
		}
	}
	else
	{
		//set variables
		Hacks::iSkillInjectionSkillID = SkillInjectionSkills[ddbSkillInjection->SelectedIndex];
		SkillInjectionStopWatch.SetDelay(milliseconds((int) nudSkillInjection->Value));

		cbNFA->Checked = false;
		cbSkillInjection->Checked = Hacks::cmSkillInjectionChecks.Enable(cbSkillInjection->Checked);
		cbSkillInjection->Checked = Hacks::cmSkillInjectionCave.Enable(cbSkillInjection->Checked);
		cbNoCCBlueBoxes->Checked = cbSkillInjection->Checked;
		cbNoCCBlueBoxes->Enabled = !cbSkillInjection->Checked;
	}
	*/
}
void MainForm::nudSkillInjectionDelay_ValueChanged(Object^  sender, EventArgs^  e)
{
	SkillInjectionStopWatch.SetDelay(milliseconds((int) nudSkillInjection->Value));
}
void MainForm::ddbSkillInjectionSkills_SelectedIndexChanged(Object^  sender, EventArgs^  e)
{
	//Patched
	//Hacks::iSkillInjectionSkillID = SkillInjectionSkills[ddbSkillInjection->SelectedIndex];
}
void MainForm::cbNoCCBlueBoxes_CheckedChanged(Object^  sender, EventArgs^  e)
{
	cbNoCCBlueBoxes->Checked = Hacks::cmNoCCBoxes.Enable(cbNoCCBlueBoxes->Checked);
}

//AutoBot Events
Void MainForm::cbAutoAttack_CheckedChanged(Object^  sender, EventArgs^  e)
{
	this->nudAutoAttack->Enabled = !cbAutoAttack->Checked;
	this->nudSAWSIL->Enabled = !cbAutoAttack->Checked;
	this->ddbAutoAttackKey->Enabled = !cbAutoAttack->Checked;

	CMS->SAWSIL = (int) nudSAWSIL->Value;
	this->tAutoAttack->Interval = (int) nudAutoAttack->Value;
	this->tAutoAttack->Enabled = cbAutoAttack->Checked;
}
Void MainForm::tAutoAttack_Tick(Object^  sender, EventArgs^  e)
{
	if(!CMS->InGame || CC->Busy || CMS->MobCount < CMS->SAWSIL || UsingAutoSkill) return;
	BreathCounter.Start();
	CMS->SpamSwitch(ddbAutoAttackKey->SelectedIndex);
}
Void MainForm::ddbAutoAttackKey_DropDown(System::Object^  sender, System::EventArgs^  e)	 
{
	ddbAutoAttackKey->Items->Clear();
	ddbAutoAttackKey->Items->AddRange(KeyNames);
	for each(CPacketData^ p in CPacket->Packets) ddbAutoAttackKey->Items->Add(p->Name);
}
Void MainForm::cbAutoLoot_CheckedChanged(Object^  sender, EventArgs^  e)
{
	this->nudAutoLoot->Enabled = !this->cbAutoLoot->Checked;
	this->ddbAutoLootKey->Enabled = !this->cbAutoLoot->Checked;
	this->nudSLWIB->Enabled = !this->cbAutoLoot->Checked;
		
	CMS->SLWIB = (int) nudSLWIB->Value;
	tAutoLoot->Interval = ((int) nudAutoLoot->Value);
	tAutoLoot->Enabled = cbAutoLoot->Checked;
}
Void MainForm::tAutoLoot_Tick(Object^  sender, EventArgs^  e)
{
	if(!CMS->InGame || CMS->ItemCount < CMS->SLWIB || UsingAutoSkill) return;
	CMS->Tubi = 0;
	CMS->SpamSwitch(ddbAutoLootKey->SelectedIndex);
}
Void MainForm::ddbAutoLootKey_DropDown(Object^  sender, EventArgs^ e)
{
	ddbAutoLootKey->Items->Clear();
	ddbAutoLootKey->Items->AddRange(KeyNames);
	for each(CPacketData^ p in CPacket->Packets) ddbAutoLootKey->Items->Add(p->Name);
}
Void MainForm::cbAutoHP_CheckedChanged(Object^  sender, EventArgs^  e)
{
	nudAutoHP->Enabled = !cbAutoHP->Checked;
	ddbAutoHPKey->Enabled = !cbAutoHP->Checked;
}
Void MainForm::ddbAutoHPKey_DropDown(Object^  sender, EventArgs^ e)
{
	ddbAutoHPKey->Items->Clear();
	ddbAutoHPKey->Items->AddRange(KeyNames);
	for each(CPacketData^ p in CPacket->Packets) ddbAutoHPKey->Items->Add(p->Name);
}
Void MainForm::cbAutoMP_CheckedChanged(Object^  sender, EventArgs^  e)
{
	nudAutoMP->Enabled = !cbAutoMP->Checked;
	ddbAutoMPKey->Enabled = !cbAutoMP->Checked;
}
Void MainForm::ddbAutoMPKey_DropDown(Object^  sender, EventArgs^ e)
{
	ddbAutoMPKey->Items->Clear();
	ddbAutoMPKey->Items->AddRange(KeyNames);
	for each(CPacketData^ p in CPacket->Packets) ddbAutoMPKey->Items->Add(p->Name);
}
Void MainForm::ddbPetFeeder_DropDown(::Object^  sender, EventArgs^  e)
{
	ddbPetFeeder->Items->Clear();
	ddbPetFeeder->Items->AddRange(KeyNames);
	for each(CPacketData^ p in CPacket->Packets) ddbPetFeeder->Items->Add(p->Name);
}
Void MainForm::cbCCPeople_CheckedChanged(Object^  sender, EventArgs^  e)
{
	nudCCPeople->Enabled = !cbCCPeople->Checked;
}
Void MainForm::cbCCTimed_CheckedChanged(Object^  sender, EventArgs^  e)
{
	this->ddbTimedType->Enabled = !this->cbCCTimed->Checked;
	this->nudCCTimed->Enabled = !this->cbCCTimed->Checked;

	tTimedCC->Interval = (int) nudCCTimed->Value * 1000;
	tTimedCC->Enabled = cbCCTimed->Checked;
}
Void MainForm::tTimedCC_Tick(Object^  sender, EventArgs^  e)
{
	CC->CCSwitch((CCType) ddbTimedType->SelectedIndex);
}
Void MainForm::cbCCAttacks_CheckedChanged(Object^  sender, EventArgs^  e)
{
	nudCCAttacks->Enabled = !cbCCAttacks->Checked;
}

//General Trainer events
void Main(void)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm);
	Application::Exit();
}
void MainForm::MainForm_Load(Object^  sender, EventArgs^  e)
{
	//Create the Waty directory in %appdata%
	if(!Directory::Exists(WatyBotWorkingDirectory))	Directory::CreateDirectory(WatyBotWorkingDirectory);

	//Initialize the NotifyIcon
	notifyIcon = gcnew NotifyIcon;
	notifyIcon->Icon = SystemIcons::Error;
	notifyIcon->Visible = true;

	//Load all the settings and innitialize all the classes
	CC = gcnew CChangeChannel;
	CMS = gcnew CMapleStory;
	SPControl = gcnew CSPControl;
	InitializePacketSender();
	LoadSettings();
	AutoSkills = LoadAutoSkill();

	RefreshSPControlListView();

	// Fix the size of the tabs
	MainForm::Height = TabHeight[MainTabControl->SelectedTab->TabIndex];
	MainTabControl->Height = TabHeight[MainTabControl->SelectedTab->TabIndex] - 30;
}
void MainForm::StatsTimer_Tick(Object^  sender, EventArgs^  e)
{
	this->MobCountLabel->Text =		"Mobs: "		+ CMS->MobCount;
	this->PeopleCountLabel->Text =	"People: "		+ CMS->PeopleCount;
	this->CharPosLabel->Text =		"CharPos: ("	+ CMS->CharX +","+ CMS->CharY+")";
	this->ItemCountLabel->Text =	"Items: "		+ CMS->ItemCount;
	this->AttackCountLabel->Text =	"Attacks: "		+ CMS->AttackCount;
	this->TubiPointerLabel->Text =	"Tubi: "		+ CMS->Tubi;
	this->BreathLabel->Text =		"Breath: "		+ CMS->Breath;
	this->lMapID->Text =			"MapID: "		+ CMS->MapId;
	this->lCharacterpID->Text =		"Char pID: "	+ CMS->CharpId;
	this->lKnockBack->Text =		"KnockBack: "	+ CMS->KnockBack;
	this->lPetFullness->Text =		"PetFullness: "	+ CMS->PetFullness;
	
	if(CMS->InGame)
	{
		//AutoHP/MP happens here
		if(cbAutoHP->Checked && CMS->CharHP <= nudAutoHP->Value) CMS->SpamSwitch(ddbAutoHPKey->SelectedIndex);
		if(cbAutoMP->Checked && CMS->CharMP <= nudAutoMP->Value) CMS->SpamSwitch(ddbAutoMPKey->SelectedIndex);

		//AutoCC happens here
		if(cbCCPeople->Checked && (CMS->PeopleCount >= (int) nudCCPeople->Value)) CC->CCSwitch((CCType) ddbPeopleType->SelectedIndex);	
		if(cbCCAttacks->Checked && (CMS->AttackCount >= (int) nudCCAttacks->Value)) CC->CCSwitch((CCType) ddbAttacksType->SelectedIndex);

		//PetFeeder happens here
		if(cbPetFeeder->Checked && (CMS->PetFullness <= nudPetFeeder->Value)) CMS->SendSwitch(ddbPetFeeder->SelectedIndex);
		MainForm::RedrawStatBars();
		MainForm::HotKeys();
	}
}
void MainForm::RedrawStatBars()
{
	this->HPLabel->Text = "HP: " + CMS->CharHP + "/" + CMS->MaxHP;
	this->MPLabel->Text = "MP: " + CMS->CharMP + "/" + CMS->MaxMP;
	this->EXPLabel->Text = "EXP: " + CMS->CharEXP.ToString("f2") +"%";

	static int lengtOfBars = 223;
	double HPBarLength = ((double) CMS->CharHP / (double) CMS->MaxHP) * lengtOfBars;
	this->HPForeground->Width = HPBarLength;
	double MPBarLength = ((double) CMS->CharMP / (double) CMS->MaxMP) * lengtOfBars;
	this->MPForeground->Width = MPBarLength;
	double EXPBarLength = (CMS->CharEXP / 100) * lengtOfBars;
	this->EXPForeground->Width = EXPBarLength;
}
void MainForm::MainTabControl_SelectedIndexChanged(Object^  sender, EventArgs^  e)
{
	MainForm::Height = TabHeight[MainTabControl->SelectedTab->TabIndex];
	MainTabControl->Height = TabHeight[MainTabControl->SelectedTab->TabIndex] - 30;
}
void MainForm::MainForm_FormClosing(Object^  sender, Windows::Forms::FormClosingEventArgs^  e)
{
	switch(MessageBox::Show("Close MapleStory too?", "Terminate Maple?", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question))
	{
		case ::DialogResult::Yes:
			notifyIcon->Visible = false;
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
Void MainForm::bAutoSkill_Click(Object^  sender, EventArgs^  e)
{
	if(nudAutoSkill->Value == 0) ShowError("The interval can't be 0!");
	else if(ddbAutoSkill->SelectedIndex == -1) ShowError("You must select a key!");
	else
	{
		ListViewItem^ item = gcnew ListViewItem(tbAutoSkill->Text);
		item->SubItems->Add(nudAutoSkill->Value.ToString());
		item->SubItems->Add(ddbAutoSkill->SelectedItem->ToString());
		lvAutoSkill->Items->Add(item);
		AutoSkills->Add(gcnew CAutoSkill(tbAutoSkill->Text, (int) nudAutoSkill->Value, ddbAutoSkill->SelectedIndex));
	}
	SaveAutoSkill();
}
Void MainForm::ddbAutoSkill_DropDown(Object^  sender, EventArgs^  e)
{
	ddbAutoSkill->Items->Clear();
	ddbAutoSkill->Items->AddRange(KeyNames);
	for each(CPacketData^ p in CPacket->Packets) ddbAutoSkill->Items->Add(p->Name);
}
Void MainForm::castToolStripMenuItem_Click(Object^  sender, EventArgs^  e)
{
	if(lvSPControl->SelectedItems->Count < 0) return;
	ListViewItem^ i = lvAutoSkill->SelectedItems[0];
	AutoSkills[lvAutoSkill->Items->IndexOf(i)]->Cast();
}
Void MainForm::deleteToolStripMenuItem_Click(Object^  sender, EventArgs^  e)
{
	if(lvSPControl->SelectedItems->Count < 0) return;
	ListViewItem^ i = lvAutoSkill->SelectedItems[0];
	int index = lvAutoSkill->Items->IndexOf(i);
	delete AutoSkills[index];
	AutoSkills->RemoveAt(index);
	lvAutoSkill->Items->RemoveAt(index);
	SaveAutoSkill();
}
Void MainForm::lvAutoSkill_ItemCheck(Object^  sender, Windows::Forms::ItemCheckEventArgs^  e)
{
	if(e->CurrentValue == CheckState::Checked)
		AutoSkills[e->Index]->Enabled = false;
	else if(e->CurrentValue == CheckState::Unchecked)
		AutoSkills[e->Index]->Enabled = true;
}

List<CAutoSkill^>^ MainForm::LoadAutoSkill()
{
	if(!File::Exists(AutoSkillFileName))
	{
		auto stream = File::Create(AutoSkillFileName);
		stream->Close();
	}
	
	TextReader^ reader = gcnew StreamReader(AutoSkillFileName);
	AutoSkillSerializer = gcnew XmlSerializer(List<CAutoSkill^>::typeid);
	List<CAutoSkill^>^ AutoSkill;
	try
	{
		AutoSkill = safe_cast<List<CAutoSkill^>^>(AutoSkillSerializer->Deserialize(reader));
	}
	catch(Exception^)
	{
	}	
	reader->Close();
	if(AutoSkill == nullptr) AutoSkill = gcnew List<CAutoSkill^>;
	ddbAutoSkill->Items->Clear();
	ddbAutoSkill->Items->AddRange(KeyNames);
	ddbAutoSkill->BeginUpdate();
	for each(CPacketData^ p in CPacket->Packets) ddbAutoSkill->Items->Add(p->Name);
	ddbAutoSkill->EndUpdate();
	lvAutoSkill->BeginUpdate();
	for each(CAutoSkill^ as in AutoSkill)
	{
		ListViewItem^ item = gcnew ListViewItem(as->Name);
		item->SubItems->Add(as->Interval.ToString());
		item->SubItems->Add(ddbAutoSkill->Items[as->keyIndex]->ToString());
		lvAutoSkill->Items->Add(item);
	}
	lvAutoSkill->EndUpdate();
	return AutoSkill;
}
void MainForm::SaveAutoSkill()
{
	TextWriter^ writer = gcnew StreamWriter(AutoSkillFileName);
	try
	{
		AutoSkillSerializer->Serialize(writer, AutoSkills);
	}
	catch(Exception^)
	{
	}
	writer->Close();
}

//Controls on the PacketSender tab
Void MainForm::InitializePacketSender()
{
	CPacket = gcnew CPackets;
	lvPackets->BeginUpdate();
	for each(CPacketData^ packet in CPacket->Packets)
	{
		ListViewItem^ i = gcnew ListViewItem(packet->Name);
		if(packet->Data->Count > 0) i->SubItems->Add(packet->Data->Count > 1 ? packet->Data[0] + " + more" : packet->Data[0]);
		lvPackets->Items->Add(i);
	}
	lvPackets->EndUpdate();
}
Void MainForm::bAddPacket_Click(Object^  sender, EventArgs^  e)
{
	List<String^>^ Data = gcnew List<String^>;
	Data->AddRange(tbPacketData->Lines);
	for each(String^ str in Data)
	{
		String^ strError = String::Empty;
		if(!CPacket->VerifyPacket(str, strError))
		{
			ShowNotifyIcon(strError);
			return;
		}
	}

	ListViewItem^ i = gcnew ListViewItem(tbPacketName->Text);
	i->SubItems->Add(Data->Count > 1 ? Data[0] + " + more" : Data[0]);
	lvPackets->Items->Add(i);

	CPacket->Add(tbPacketName->Text, Data);
	CPacket->Save();
}
Void MainForm::bSaveChangedPacket_Click(Object^  sender, EventArgs^  e)
{
	String^ newName = tbPacketName->Text;
	List<String^>^ newData = gcnew List<String^>;
	newData->AddRange(tbPacketData->Lines);

	auto item = lvPackets->SelectedItems[0];
	item->Text = newName;
	item->SubItems[1]->Text = newData->Count > 1 ? newData[0] + " + more" : newData[0];
	CPacketData^ p = CPacket->Packets[item->Index];
	p->Name = newName;
	p->Data = newData;
	CPacket->Packets[item->Index] = p;
	CPacket->Save();
}
Void MainForm::lvPackets_SelectedIndexChanged(Object^  sender, EventArgs^  e)
{
	if(lvPackets->SelectedItems->Count <= 0)
	{
		bSaveChangedPacket->Enabled = false;
		CPacket->SelectedPacket = nullptr;
		tbPacketName->Text = String::Empty;
		tbPacketData->Text = String::Empty;
		return;
	}
	bSaveChangedPacket->Enabled = true;
	CPacketData^ p = CPacket->Packets[lvPackets->SelectedItems[0]->Index];
	CPacket->SelectedPacket = p;
	tbPacketName->Text = p->Name;
	tbPacketData->Lines = p->Data->ToArray();
}
Void MainForm::bSendPacket_Click(Object^  sender, EventArgs^  e)
{
	if(lvPackets->SelectedItems->Count <= 0) return;
	CPacket->Send();
}
Void MainForm::bDeletePacket_Click(Object^  sender, EventArgs^  e)
{
	if(lvPackets->SelectedItems->Count <= 0) return;
	int index = lvPackets->SelectedItems[0]->Index;
	lvPackets->Items->RemoveAt(index);
	CPacket->Packets->RemoveAt(index);
	CPacket->Save();
}
Void MainForm::lvPackets_KeyDown(Object^  sender, Windows::Forms::KeyEventArgs^  e)
{
	if(lvPackets->SelectedItems->Count <= 0) return;
	if(e->KeyCode == Keys::Delete)
	{
		if(lvPackets->SelectedItems->Count <= 0) return;
		int index = lvPackets->SelectedItems[0]->Index;
		lvPackets->Items->RemoveAt(index);
		CPacket->Packets->RemoveAt(index);
		CPacket->Save();
	}
	if(e->KeyCode == Keys::Enter) CPacket->Send();
}

//controls on SPControl Tab
void MainForm::bAddSPCLocation_Click(Object^  sender, EventArgs^  e)
{
	String^ name = tbSPCName->Text;
	int mapid = (int) nudSPCMapId->Value;
	int x = (int) nudSPCX->Value;
	int y = (int) nudSPCY->Value;

	SPControl->AddLocation(name, mapid, x, y);
	RefreshSPControlListView();
}
void MainForm::cbSPControl_CheckedChanged(Object^  sender, EventArgs^  e)
{
	SPControl->Enable(cbSPControl->Checked);
}
void MainForm::SPControlDeleteItem_Click(Object^  sender, EventArgs^  e)
{
	{
		ListViewItem^ L = lvSPControl->SelectedItems[0];
		switch(MessageBox::Show("Are you sure you want to delete this location?", "Confirm deletion", MessageBoxButtons::YesNo, MessageBoxIcon::Question))
		{
		case ::DialogResult::Yes:
			SPControl->Locations->RemoveAt(lvSPControl->Items->IndexOf(L));
			SPControl->Save();
			RefreshSPControlListView();
			break;
		}
	}
}
void MainForm::GetSPControlCoordsButton_Click(Object^  sender, EventArgs^  e)
{
	for(int i = 0; i < 10; i++)
	{
		CMS->SpamKey(VK_DOWN);
		Sleep(10);
	}
	this->nudSPCMapId->Value = CMS->MapId;
	this->nudSPCX->Value = CMS->CharX;
	this->nudSPCY->Value = CMS->CharY;
}
void MainForm::RefreshSPControlListView()
{
	lvSPControl->Items->Clear();
	this->tbSPCName->Clear();
	this->nudSPCMapId->ResetText();
	this->nudSPCX->ResetText();
	this->nudSPCY->ResetText();
	lvSPControl->BeginUpdate();
	for each(CSPControlLocation^ SP in SPControl->Locations)
	{
		ListViewItem^ item = gcnew ListViewItem(SP->Name);
		item->SubItems->Add(SP->MapId.ToString());
		item->SubItems->Add(SP->X.ToString());
		item->SubItems->Add(SP->Y.ToString());
		lvSPControl->Items->Add(item);
	}
	lvSPControl->EndUpdate();
}

//Loading/Saving AutoBot settings
enum SettingsIndex{
	AutoAttackDelay, SAWSIL, AutoAttackKey, AutoLootDelay, SLWIB, AutoLootKey, AutoHPValue, AutoHPKey, AutoMPValue, AutoMPKey, PetFeederValue, PetFeederKey,
	CCPeople, CCPeopleType, CCTimed, CCTimedType, CCAttacks, CCAttacksType, HotKeyAttack, HotKeyLoot, HotKeyFMA, HotKeyCCPeople, HotKeySendPacket,
	/*SelectedPacket, PacketSpamAmount, PacketSpamDelay, */SkillInjectionDelay, SkillInjectionIndex, IceGuard, PinTyper, LogoSkipper, SettingCount
};
Void MainForm::SaveSettings()
{
	ReloadSettings();
	TextWriter^ writer = gcnew StreamWriter(SettingsFileName);
	try
	{
		XmlSerializer^ serializer = gcnew XmlSerializer(List<SettingsEntry^>::typeid);
		serializer->Serialize(writer, Settings);
	}
	catch(Exception^)
	{
	}
	writer->Close();
}
Void MainForm::LoadSettings()
{
	if(!File::Exists(SettingsFileName))
	{
		auto stream = File::Create(SettingsFileName);
		stream->Close();
	}

	TextReader^ reader = gcnew StreamReader(SettingsFileName);
	s = gcnew XmlSerializer(List<SettingsEntry^>::typeid);
	try
	{
		Settings = safe_cast<List<SettingsEntry^>^>(s->Deserialize(reader));
	}
	catch(Exception^)
	{
	}	
	reader->Close();
	if(Settings == nullptr) Settings = gcnew List<SettingsEntry^>;
	else
	{
		if(Settings->Count != SettingCount) ShowNotifyIcon("The Loaded settings file is invalid!\n" + "WatyBot Will try to load it anyways :)\n" + "Found: " + Settings->Count + " Should be: " + (int) SettingCount);
		try
		{
			//AutoAttack
			nudAutoAttack->Value = (Decimal)			Settings[AutoAttackDelay]->Value;
			nudSAWSIL->Value = (Decimal)				Settings[SAWSIL]->Value;
			ddbAutoAttackKey->SelectedIndex = (int)		Settings[AutoAttackKey]->Value;
			//AutoLoot
			nudAutoLoot->Value = (Decimal)				Settings[AutoLootDelay]->Value;
			nudSLWIB->Value = (Decimal)					Settings[SLWIB]->Value;
			ddbAutoLootKey->SelectedIndex = (int)		Settings[AutoLootKey]->Value;
			//AutoHP
			nudAutoHP->Value = (Decimal)				Settings[AutoHPValue]->Value;
			ddbAutoHPKey->SelectedIndex = (int)			Settings[AutoHPKey]->Value;
			//AutoMP
			nudAutoMP->Value = (Decimal)				Settings[AutoMPValue]->Value;
			ddbAutoMPKey->SelectedIndex = (int)			Settings[AutoMPKey]->Value;
			//PetFeeder
			nudPetFeeder->Value = (Decimal)				Settings[PetFeederValue]->Value;
			ddbPetFeeder->SelectedIndex = (int)			Settings[PetFeederKey]->Value;
			//CC People
			nudCCPeople->Value = (Decimal)				Settings[CCPeople]->Value;
			ddbPeopleType->SelectedIndex = (int)		Settings[CCPeopleType]->Value;
			//CC Timed
			nudCCTimed->Value = (Decimal)				Settings[CCTimed]->Value;
			ddbTimedType->SelectedIndex = (int)			Settings[CCTimedType]->Value;
			//CC Attacks
			nudCCAttacks->Value = (Decimal)				Settings[CCAttacks]->Value;
			ddbAttacksType->SelectedIndex = (int)		Settings[CCAttacksType]->Value;
			//HotKeys
			ddbHotKeyAttack->SelectedIndex = (int)		Settings[HotKeyAttack]->Value;
			ddbHotKeyLoot->SelectedIndex = (int)		Settings[HotKeyLoot]->Value;
			ddbHotKeyFMA->SelectedIndex = (int)			Settings[HotKeyFMA]->Value;
			ddbHotKeyCCPeople->SelectedIndex = (int)	Settings[HotKeyCCPeople]->Value;
			ddbHotKeySendPacket->SelectedIndex = (int)	Settings[HotKeySendPacket]->Value;
			//PacketSender
//			ddbSelectedPacket->SelectedIndex = (int)	Settings[SelectedPacket]->Value;
//			nudSpamAmount->Value = (Decimal)			Settings[PacketSpamAmount]->Value;
//			nudSpamDelay->Value = (Decimal)				Settings[PacketSpamDelay]->Value;
			//Hacks Tab
			nudSkillInjection->Value = (Decimal)		Settings[SkillInjectionDelay]->Value;
			ddbSkillInjection->SelectedIndex = (int)	Settings[SkillInjectionIndex]->Value;
			nudIceGuard->Value = (Decimal)				Settings[IceGuard]->Value;

			//try's 5 seconds long if your CRC is ready for the hacks
			int i = 0;
			while(i<50 && !CMS->GotMSCRC)
			{
				Sleep(100);
				i++;
			}
			if(CMS->GotMSCRC)
			{
				cbPinTyper->Checked = (bool)				Settings[PinTyper]->Value;
				cbLogoSkipper->Checked = (bool)				Settings[LogoSkipper]->Value;
				Hacks::cmPacketSenderFix.Enable(true);
			}
		}
		catch(Exception^)
		{
		}
	}
}
Void MainForm::ReloadSettings()
{
	List<SettingsEntry^>^ s = gcnew List<SettingsEntry^>(SettingCount);
	//AutoAttack
	s->Add(gcnew SettingsEntry(nudAutoAttack));
	s->Add(gcnew SettingsEntry(nudSAWSIL));
	s->Add(gcnew SettingsEntry(ddbAutoAttackKey));
	//AutoLoot
	s->Add(gcnew SettingsEntry(nudAutoLoot));
	s->Add(gcnew SettingsEntry(nudSLWIB));
	s->Add(gcnew SettingsEntry(ddbAutoLootKey));
	//AutoHP
	s->Add(gcnew SettingsEntry(nudAutoHP));
	s->Add(gcnew SettingsEntry(ddbAutoHPKey));
	//AutoMP
	s->Add(gcnew SettingsEntry(nudAutoMP));
	s->Add(gcnew SettingsEntry(ddbAutoMPKey));
	//PetFeeder
	s->Add(gcnew SettingsEntry(nudPetFeeder));
	s->Add(gcnew SettingsEntry(ddbPetFeeder));
	//CC People
	s->Add(gcnew SettingsEntry(nudCCPeople));
	s->Add(gcnew SettingsEntry(ddbPeopleType));
	//CC Timed
	s->Add(gcnew SettingsEntry(nudCCTimed));
	s->Add(gcnew SettingsEntry(ddbTimedType));
	//CC Attacks
	s->Add(gcnew SettingsEntry(nudCCAttacks));
	s->Add(gcnew SettingsEntry(ddbAttacksType));
	//HotKeys
	s->Add(gcnew SettingsEntry(ddbHotKeyAttack));
	s->Add(gcnew SettingsEntry(ddbHotKeyLoot));
	s->Add(gcnew SettingsEntry(ddbHotKeyFMA));
	s->Add(gcnew SettingsEntry(ddbHotKeyCCPeople));
	s->Add(gcnew SettingsEntry(ddbHotKeySendPacket));
	//PacketSender
	//s->Add(gcnew SettingsEntry(ddbSelectedPacket));
	//s->Add(gcnew SettingsEntry(nudSpamAmount));
	//s->Add(gcnew SettingsEntry(nudSpamDelay));
	//Hacks Tab
	s->Add(gcnew SettingsEntry(nudSkillInjection));
	s->Add(gcnew SettingsEntry(ddbSkillInjection));
	s->Add(gcnew SettingsEntry(nudIceGuard));

	s->Add(gcnew SettingsEntry(cbPinTyper));
	s->Add(gcnew SettingsEntry(cbLogoSkipper));
	Settings = s;
}
Void MainForm::bSaveSettings_Click(Object^  sender, EventArgs^  e)
{
	SaveSettings();
	SPControl->Save();
	CPacket->Save();
	SaveAutoSkill();
}

//Hot Keys
Void MainForm::HotKeys()
{
	if(this->cbHotKeyAttack->Checked)
	{
		if(GetAsyncKeyState(KeyCodes[ddbHotKeyAttack->SelectedIndex]))
		{
			this->cbAutoAttack->Checked = !this->cbAutoAttack->Checked;
			Sleep(250);
		}
	}
	if(this->cbHotKeyLoot->Checked)
	{
		if(GetAsyncKeyState(KeyCodes[ddbHotKeyLoot->SelectedIndex]))
		{
			this->cbAutoLoot->Checked = !this->cbAutoLoot->Checked;
			Sleep(250);
		}
	}
	if(this->cbHotKeyFMA->Checked)
	{
		if(GetAsyncKeyState(KeyCodes[ddbHotKeyFMA->SelectedIndex]))
		{
			this->cbFMA->Checked = !this->cbFMA->Checked;
			Sleep(250);
		}
	}
	if(this->cbHotKeyCCPeople->Checked)
	{
		if(GetAsyncKeyState(KeyCodes[ddbHotKeyCCPeople->SelectedIndex]))
		{
			this->cbCCPeople->Checked = !this->cbCCPeople->Checked;
			Sleep(250);
		}
	}
	if(this->cbHotKeySendPacket->Checked)
	{
		if(GetAsyncKeyState(KeyCodes[ddbHotKeySendPacket->SelectedIndex]))
		{
			CPacket->Send();
			Sleep(250);
		}
	}
	if(this->cbHotKeyMouseFly->Checked)
	{
		if(GetAsyncKeyState(KeyCodes[ddbHotKeyMouseFly->SelectedIndex]))
		{
			this->cbHotKeyMouseFly->Checked = !this->cbHotKeyMouseFly->Checked;
			Sleep(250);
		}
	}
}
