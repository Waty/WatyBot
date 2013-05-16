#pragma once
#pragma warning(disable : 4793 4244)
#include <Windows.h>
#include "MainForm.h"
#include "Memory.h"
#include "Pointers.h"
#include "Packet.h"
#include "SPControl.h"
#include "Hacks.h"
#include "MapleStory.h"
#include "Settings.h"
#include "Defines.h"

using namespace Settings;
using namespace WatyBotRevamp;
using namespace System::IO;

//Hack CheckBoxes
void MainForm::cbFusionAttack_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbFusionAttack->Checked = Hacks::cmFusionAttack.Enable(cbFusionAttack->Checked);
}
void MainForm::cbNoKB_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbNoKB->Checked = Hacks::cmNoKB.Enable(cbNoKB->Checked);
}
void MainForm::cbPerfectLoot_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbPerfectLoot->Checked = Hacks::cmPerfectLoot.Enable(cbPerfectLoot->Checked);
	cbPerfectLoot->Checked = Hacks::cmInstantAirLoot.Enable(cbPerfectLoot->Checked);
}
void MainForm::cbVacRight_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	 cbVacRight->Checked = Hacks::cmVacRight.Enable(cbVacRight->Checked);
}
void MainForm::cbWalkRight_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbWalkRight->Checked = Hacks::cmWalkRight.Enable(cbWalkRight->Checked);
}
void MainForm::cbJumpRight_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbJumpRight->Checked = Hacks::cmJumpRight.Enable(cbJumpRight->Checked);
}
void MainForm::cbMobDisarm_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbMobDisarm->Checked = Hacks::cmMobDisarm.Enable(cbMobDisarm->Checked);
}
void MainForm::cbNoBG_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbNoBG->Checked = Hacks::cmNoBG.Enable(cbNoBG->Checked);
}
void MainForm::cbJDA_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbJDA->Checked = Hacks::cmJDA.Enable(cbJDA->Checked);
}
void MainForm::cbPinTyper_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbPinTyper->Checked = Hacks::cmPinTyper.Enable(cbPinTyper->Checked);
}
void MainForm::cbDojangGodmode_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbDojangGodmode->Checked = Hacks::cmDojangGodmode.Enable(cbDojangGodmode->Checked);
}
void MainForm::cbIceGuard_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->nudIceGuard->Enabled = !this->cbIceGuard->Checked;
	Hacks::iIceGuardLimit = (int)nudIceGuard->Value;
	cbIceGuard->Checked = Hacks::cmIceGuard.Enable(cbIceGuard->Checked);
}
void MainForm::cbUnlimitedMorph_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbUnlimitedMorph->Checked = Hacks::cmUnlimitedMorph.Enable(cbUnlimitedMorph->Checked);
}
void MainForm::cbFasterMobs_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbFasterMobs->Checked = Hacks::cmFasterMobs.Enable(cbFasterMobs->Checked);
}
void MainForm::cbNDAllAttacks_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbNDAllAttacks->Checked = Hacks::cmNDAllAttacks.Enable(cbNDAllAttacks->Checked);
}
void MainForm::cbNoMobs_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbNoMobs->Checked = Hacks::cmNoMobs.Enable(cbNoMobs->Checked);
}
void MainForm::cbAutoAggro_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbAutoAggro->Checked = Hacks::cmAutoAggro.Enable(cbAutoAggro->Checked);
}
void MainForm::cbSitHack_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbSitHack->Checked = Hacks::cmSitHack.Enable(cbSitHack->Checked);
}
void MainForm::cb50SecGM_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cb50SecGM->Checked = Hacks::cm50SecGM.Enable(cb50SecGM->Checked);
}
void MainForm::cbLogoSkipper_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbLogoSkipper->Checked = Hacks::cmLogoSkipper.Enable(cbLogoSkipper->Checked);
}
void MainForm::cbViewSwears_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbViewSwears->Checked = Hacks::cmNoSwears.Enable(cbViewSwears->Checked);
}
void MainForm::cbItemVac_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbItemVac->Checked = Hacks::cmItemVac.Enable(cbItemVac->Checked);
}
void MainForm::cbFMA_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbNFA->Checked = cbFMA->Checked;
	cbItemVac->Checked = cbFMA->Checked;
	cbItemVac->Enabled = !cbFMA->Checked;
	cbFMA->Checked = Hacks::cmFMA.Enable(cbFMA->Checked);
}
void MainForm::cbScareMobs_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbScareMobs->Checked = Hacks::cmScareMobs.Enable(cbScareMobs->Checked);
}
void MainForm::cbFLACC_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbFLACC->Checked = Hacks::cmFLACC.Enable(cbFLACC->Checked);
}
void MainForm::cbCPUHack_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbCPUHack->Checked = Hacks::cmCPUHack.Enable(cbCPUHack->Checked);
}
void MainForm::cbUA_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbUA->Checked = Hacks::cmUA.Enable(cbUA->Checked);
}
void MainForm::cbNFA_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbNFA->Checked = Hacks::cmDFA.Enable(cbNFA->Checked);
}
void MainForm::cbNDMining_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbNDMining->Checked = Hacks::cmNDMining.Enable(cbNDMining->Checked);
}
void MainForm::cbHideDamage_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbHideDamage->Checked = Hacks::cmHideDamage.Enable(cbHideDamage->Checked);
}
void MainForm::cbMercedesCombo_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbMercedesCombo->Checked = Hacks::cmMercedesCombo.Enable(cbMercedesCombo->Checked);
}
void MainForm::cbNoFadeStages_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbNoFadeStages->Checked = Hacks::cmNoFadeStages.Enable(cbNoFadeStages->Checked);
}
void MainForm::cbMouseFly_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbMouseFly->Checked = Hacks::cmMouseFly.Enable(cbMouseFly->Checked);
}
void MainForm::cbSkillInjection_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
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
}
void MainForm::nudSkillInjectionDelay_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	SkillInjectionStopWatch.SetDelay(milliseconds((int) nudSkillInjection->Value));
}
void MainForm::ddbSkillInjectionSkills_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::iSkillInjectionSkillID = SkillInjectionSkills[ddbSkillInjection->SelectedIndex];
}
void MainForm::cbNoCCBlueBoxes_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbNoCCBlueBoxes->Checked = Hacks::cmNoCCBoxes.Enable(cbNoCCBlueBoxes->Checked);
}

//AutoHP/MP/CC Checkboxes
void MainForm::HPCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	nudAutoHP->Enabled = !cbAutoHP->Checked;
	ddbAutoHPKey->Enabled = !cbAutoHP->Checked;
}
void MainForm::MPCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	nudAutoMP->Enabled = !cbAutoMP->Checked;
	ddbAutoMPKey->Enabled = !cbAutoMP->Checked;
}
void MainForm::CCPeopleCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	nudCCPeople->Enabled = !cbCCPeople->Checked;
}

//Macro's
bool canAttack()
{
	if(CC->Busy) return false;
	if(CMS->MobCount >= CMS->SAWSIL && CMS->InGame) return true;
	return false;
}
bool canLoot()
{
	if(!CMS->InGame) return false;
	if(CMS->ItemCount < CMS->SLWIB) return false;
	if(!CMS->WritePointer(ServerBasePtr, TubiOffset, 0)) return false;
	return true;
}
BOOL WINAPI GetCoords()
{
	int iMapID = CMS->MapId;
	for each(SpawnControl::CSPControlLocation^ location in SPControl->Locations)
	{
		if(iMapID == location->MapId)
		{
			extern int spawn_x, spawn_y;
			spawn_x = location->X;
			spawn_y = location->Y;
			return TRUE;
		}
	}
	return FALSE;
}
void AutoSkill(int KeyCodeIndex)
{
	if(KeyCodeIndex < KeyCodesSize)
	{
		//Send Key
		while(CC->Busy || CMS->UsingAutoSkill) Sleep(500);
		CMS->UsingAutoSkill = true;
		Sleep(500);
		CMS->SendKey(KeyCodes[KeyCodeIndex]);
		Sleep(500);
		CMS->UsingAutoSkill = false;		
	}
	else
	{
		//Send Packet
		CPacket->Send(CPacket->Packets[KeyCodeIndex - KeyCodesSize]);
	}
}
void TimedCC()
{
	CC->CCSwitch(CCType(CCMacro->GetValue()));
}
void InitializeMacros()
{
	//Start the MacroManager
	macroMan.Start();
	AttackMacro = new Macro::BotMacro(canAttack);
	LootMacro = new Macro::BotMacro(canLoot);
	CCMacro = new Macro::FunctionalMacro(TimedCC);
	Skill1Macro = new Macro::SkillMacro();
	Skill2Macro = new Macro::SkillMacro();
	Skill3Macro = new Macro::SkillMacro();
	Skill4Macro = new Macro::SkillMacro();

	macroMan.AddMacro(MacroIndex::eAttack, AttackMacro);
	macroMan.AddMacro(MacroIndex::eLoot, LootMacro);
	macroMan.AddMacro(MacroIndex::eCC, CCMacro);
	macroMan.AddMacro(MacroIndex::eAutoSkill1, Skill1Macro);
	macroMan.AddMacro(MacroIndex::eAutoSkill2, Skill2Macro);
	macroMan.AddMacro(MacroIndex::eAutoSkill3, Skill3Macro);
	macroMan.AddMacro(MacroIndex::eAutoSkill4, Skill4Macro);
}

void MainForm::AttackCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->nudAutoAttack->Enabled = !cbAutoAttack->Checked;
	this->nudSAWSIL->Enabled = !cbAutoAttack->Checked;
	this->ddbAutoAttackKey->Enabled = !cbAutoAttack->Checked;

	CMS->SAWSIL = (int) nudSAWSIL->Value;
	AttackMacro->SetValue(KeyCodes[ddbAutoAttackKey->SelectedIndex]);
	AttackMacro->SetDelay((unsigned int) nudAutoAttack->Value);
	AttackMacro->Toggle(cbAutoAttack->Checked);
}
void MainForm::LootCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->nudAutoLoot->Enabled = !this->cbAutoLoot->Checked;
	this->ddbAutoLootKey->Enabled = !this->cbAutoLoot->Checked;
	this->nudSLWIB->Enabled = !this->cbAutoLoot->Checked;
		
	CMS->SLWIB = (int) nudSLWIB->Value;
	LootMacro->SetValue(KeyCodes[ddbAutoLootKey->SelectedIndex]);
	LootMacro->SetDelay((unsigned int) nudAutoLoot->Value);
	LootMacro->Toggle(cbAutoLoot->Checked);
}
void MainForm::AutoSkill1CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->ddbAutoSkill1Key->Enabled = !this->cbAutoSkill1->Checked;
	this->nudAutoSkill1->Enabled = !this->cbAutoSkill1->Checked;
	Skill1Macro->SetDelay((unsigned int) nudAutoSkill1->Value * 1000);
	Skill1Macro->SetKeyIndex(ddbAutoSkill1Key->SelectedIndex);
	Skill1Macro->Toggle(cbAutoSkill1->Checked);
	if(this->cbAutoSkill1->Checked) AutoSkill(ddbAutoSkill1Key->SelectedIndex);
}
void MainForm::AutoSkill2CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->ddbAutoSkill2Key->Enabled = !this->cbAutoSkill2->Checked;
	this->nudAutoSkill2->Enabled = !this->cbAutoSkill2->Checked;
	Skill2Macro->SetDelay((unsigned int) nudAutoSkill2->Value * 1000);
	Skill2Macro->SetKeyIndex(ddbAutoSkill2Key->SelectedIndex);
	Skill2Macro->Toggle(cbAutoSkill2->Checked);
	if(this->cbAutoSkill2->Checked) AutoSkill(ddbAutoSkill2Key->SelectedIndex);
}
void MainForm::AutoSkill3CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->ddbAutoSkill3Key->Enabled = !this->cbAutoSkill3->Checked;
	this->nudAutoSkill3->Enabled = !this->cbAutoSkill3->Checked;
	Skill3Macro->SetDelay((unsigned int) nudAutoSkill3->Value * 1000);
	Skill3Macro->SetKeyIndex(ddbAutoSkill3Key->SelectedIndex);
	Skill3Macro->Toggle(cbAutoSkill3->Checked);
	if(this->cbAutoSkill3->Checked) AutoSkill(ddbAutoSkill3Key->SelectedIndex);
}
void MainForm::AutoSkill4CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->ddbAutoSkill4Key->Enabled = !this->cbAutoSkill4->Checked;
	this->nudAutoSkill4->Enabled = !this->cbAutoSkill4->Checked;
	Skill4Macro->SetDelay((unsigned int) nudAutoSkill4->Value * 1000);
	Skill4Macro->SetKeyIndex(ddbAutoSkill4Key->SelectedIndex);
	Skill4Macro->Toggle(cbAutoSkill4->Checked);
	if(this->cbAutoSkill4->Checked) AutoSkill(ddbAutoSkill4Key->SelectedIndex);
}
void MainForm::CCTimeCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->ddbTimedType->Enabled = !this->cbCCTimed->Checked;
	this->nudCCTimed->Enabled = !this->cbCCTimed->Checked;

	CCMacro->SetDelay((unsigned int) nudCCTimed->Value * 1000);
	CCMacro->SetValue(this->ddbTimedType->SelectedIndex);
	CCMacro->Toggle(cbCCTimed->Checked);
}
void MainForm::CCAttacksCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
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
void MainForm::MainForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	//Create the Waty directory in %appdata%
	if(!Directory::Exists(WatyBotWorkingDirectory))	Directory::CreateDirectory(WatyBotWorkingDirectory);

	//Load all the settings and innitialize all the classes
	CC = gcnew CChangeChannel;
	CMS = gcnew CMapleStory;
	SPControl = gcnew CSPControl;
	CPacket = gcnew CPackets;
	LoadSettings();

	//Start the MacroManager
	InitializeMacros();

	RefreshComboBoxes();
	RefreshSPControlListView();

	// Fix the size of the tabs
	MainForm::Height = TabHeight[MainTabControl->SelectedTab->TabIndex];
	MainTabControl->Height = TabHeight[MainTabControl->SelectedTab->TabIndex] - 30;
}
void MainForm::StatsTimer_Tick(System::Object^  sender, System::EventArgs^  e)
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
	this->lKBCoords->Text =			"KB: (" + CMS->KnockBackX + "," + CMS->KnockBackY + ")";
	
	//AutoHP/MP happens here
	if(cbAutoHP->Checked && CMS->CharHP <= nudAutoHP->Value) CMS->SpamKey(KeyCodes[ddbAutoHPKey->SelectedIndex]);
	if(cbAutoMP->Checked && CMS->CharMP <= nudAutoMP->Value) CMS->SpamKey(KeyCodes[ddbAutoMPKey->SelectedIndex]);

	MainForm::AutoCC();
	MainForm::RedrawStatBars();
	MainForm::HotKeys();

	//Set the correct state of the PacketSpammer Buttons
	if(AttackMacro != nullptr){
	bStopSpamming->Visible = CPacket->IsSpamming;
	bStartSpamming->Visible = !CPacket->IsSpamming;}
}
void MainForm::AutoCC()
{
	if(cbCCPeople->Checked && (CMS->PeopleCount >= (int) nudCCPeople->Value))
		CC->CCSwitch(CCType(ddbPeopleType->SelectedIndex));
	
	if(cbCCAttacks->Checked && (CMS->AttackCount >= (int) nudCCAttacks->Value))
		CC->CCSwitch(CCType(ddbAttacksType->SelectedIndex));
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
void MainForm::MainTabControl_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	MainForm::Height = TabHeight[MainTabControl->SelectedTab->TabIndex];
	MainTabControl->Height = TabHeight[MainTabControl->SelectedTab->TabIndex] - 30;
}
void MainForm::MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	macroMan.ClearMacros();
	macroMan.Stop();
	SPControl->Save();
	CPacket->Save();
	SaveSettings();

	switch(MessageBox::Show("Close MapleStory too?", "Terminate Maple?", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question))
	{
		case ::DialogResult::Yes:
			TerminateProcess(GetCurrentProcess(), 0);
			ExitProcess(0);
			break;
		
		case ::DialogResult::Cancel:
			e->Cancel = true;
			break;
	}
}

//Controls on the PacketSender tab
void MainForm::SendPacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	CPacket->Send();
}
void MainForm::AddPacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	CPacket->Add(tbAddPacketName->Text, tbAddPacketData->Text);
	RefreshComboBoxes();
	ShowInfo("Packet was added!");
}
void MainForm::DeletePacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	//delete packet from List
	switch(MessageBox::Show("Are you sure you want to delete this packet?", "Please Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question))
	{
	case ::DialogResult::Yes:
		CPacket->Delete(ddbDeletePacket->SelectedIndex);
		CPacket->Save();
		RefreshComboBoxes();
		ShowInfo("Packet was deleted succesfully!");
		break;
	}	
}
void MainForm::SelectPacketForEditingComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(ddbEditPacket->SelectedIndex >= 0)
	{
		CPacketData^ p = CPacket->Packets[ddbEditPacket->SelectedIndex];
		this->tbEditPacketName->Text = p->Name;
		this->tbEditPacketData->Text = p->Data;
	}
}
void MainForm::SavePacketEditButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	CPacket->Edit(ddbEditPacket->SelectedIndex, tbEditPacketName->Text, tbEditPacketData->Text);
	CPacket->Save();
	RefreshComboBoxes();
}
void MainForm::SpamsPacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(nudSpamDelay->Value != 0 && nudSpamAmount->Value != 0)
		CPacket->StartSpamming((int) nudSpamAmount->Value, (int) nudSpamDelay->Value);	
}
void MainForm::bStopSpamming_Click(System::Object^  sender, System::EventArgs^  e)
{
	CPacket->StopSpamming();
}
void MainForm::PacketSelectBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	CPacket->SelectedPacket = CPacket->Packets[ddbSelectedPacket->SelectedIndex];
}
void MainForm::RefreshComboBoxes()
{	
	//clear old packets
	this->tbAddPacketName->Text = String::Empty;
	this->tbAddPacketData->Text = String::Empty;
	this->ddbSelectedPacket->Items->Clear();
	this->ddbEditPacket->Items->Clear();
	this->ddbDeletePacket->Items->Clear();

	//refresh comboboxes
	for each(CPacketData^ p in CPacket->Packets) 
	{
		String^ PacketName = p->Name;
		this->ddbSelectedPacket->Items->Add(PacketName);
		this->ddbEditPacket->Items->Add(PacketName);
		this->ddbDeletePacket->Items->Add(PacketName);
	}	
}
void MainForm::AutoSkill1ComboBox_DropDown(System::Object^  sender, System::EventArgs^  e)
{
	this->ddbAutoSkill1Key->Items->Clear();
	this->ddbAutoSkill1Key->Items->AddRange(gcnew cli::array< System::Object^  >(58) {L"Shift", L"Space", L"Ctrl", L"Alt", L"Insert", L"Delete", L"Home", L"End", L"Page Up", L"Page Down", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"F1", L"F2", L"F3", L"F4", L"F5", L"F6", L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"});
	for each(CPacketData^ p in CPacket->Packets) this->ddbAutoSkill1Key->Items->Add(p->Name);
}
void MainForm::AutoSkill2ComboBox_DropDown(System::Object^  sender, System::EventArgs^  e)
{
	this->ddbAutoSkill2Key->Items->Clear();
	this->ddbAutoSkill2Key->Items->AddRange(gcnew cli::array< System::Object^  >(58) {L"Shift", L"Space", L"Ctrl", L"Alt", L"Insert", L"Delete", L"Home", L"End", L"Page Up", L"Page Down", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"F1", L"F2", L"F3", L"F4", L"F5", L"F6", L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"});
	for each(CPacketData^ p in CPacket->Packets) this->ddbAutoSkill2Key->Items->Add(p->Name);
}
void MainForm::AutoSkill3ComboBox_DropDown(System::Object^  sender, System::EventArgs^  e)
{
	this->ddbAutoSkill3Key->Items->Clear();
	this->ddbAutoSkill3Key->Items->AddRange(gcnew cli::array< System::Object^  >(58) {L"Shift", L"Space", L"Ctrl", L"Alt", L"Insert", L"Delete", L"Home", L"End", L"Page Up", L"Page Down", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"F1", L"F2", L"F3", L"F4", L"F5", L"F6", L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"});
	for each(CPacketData^ p in CPacket->Packets) this->ddbAutoSkill3Key->Items->Add(p->Name);
}
void MainForm::AutoSkill4ComboBox_DropDown(System::Object^  sender, System::EventArgs^  e)
{
	this->ddbAutoSkill4Key->Items->Clear();
	this->ddbAutoSkill4Key->Items->AddRange(gcnew cli::array< System::Object^  >(58) {L"Shift", L"Space", L"Ctrl", L"Alt", L"Insert", L"Delete", L"Home", L"End", L"Page Up", L"Page Down", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"F1", L"F2", L"F3", L"F4", L"F5", L"F6", L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"});
	for each(CPacketData^ p in CPacket->Packets) this->ddbAutoSkill4Key->Items->Add(p->Name);
}

//controls on SPControl Tab
void MainForm::cbSPControl_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	SPControl->Enable(cbSPControl->Checked);
}
void MainForm::SPControlAddButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ name = tbSPCName->Text;
	int mapid = (int) nudSPCMapId->Value;
	int x = (int) nudSPCX->Value;
	int y = (int) nudSPCY->Value;

	SPControl->AddLocation(name, mapid, x, y);
	RefreshSPControlListView();
}
void MainForm::SPControlDeleteItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	ListViewItem^ L = lvSPControl->SelectedItems[0];
	if(lvSPControl->SelectedItems->Count > 0)
	{
		switch(MessageBox::Show("Are you sure you want to delete this location?", "Please Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question))
		{
		case ::DialogResult::Yes:
			SPControl->Locations->RemoveAt(lvSPControl->Items->IndexOf(L));
			SPControl->Save();
			RefreshSPControlListView();
			break;
		}
	}
}
void MainForm::GetSPControlCoordsButton_Click(System::Object^  sender, System::EventArgs^  e)
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
	for each(CSPControlLocation^ SP in SPControl->Locations)
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
	ReloadSettings();
	TextWriter^ writer = gcnew StreamWriter(SettingsFileName);
	try
	{
		XmlSerializer^ serializer = gcnew XmlSerializer(List<SettingsEntry^>::typeid);
		serializer->Serialize(writer, Settings);
	}
	catch(System::Exception^ ex)
	{
		ShowError(ex->ToString());
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
	catch(System::Exception^){}	
	reader->Close();
	if(Settings == nullptr) Settings = gcnew List<SettingsEntry^>;
	else if(Settings->Count >= 36)
	{
		try{
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
		//AutoSkill 1
		nudAutoSkill1->Value = (Decimal)			Settings[AutoSkill1]->Value;
		ddbAutoSkill1Key->SelectedIndex = (int)		Settings[AutoSkill1Key]->Value;
		//AutoSkill 2
		nudAutoSkill2->Value = (Decimal)			Settings[AutoSkill2]->Value;
		ddbAutoSkill2Key->SelectedIndex = (int)		Settings[AutoSkill2Key]->Value;
		//AutoSkill 3
		nudAutoSkill3->Value = (Decimal)			Settings[AutoSkill3]->Value;
		ddbAutoSkill3Key->SelectedIndex = (int)		Settings[AutoSkill3Key]->Value;
		//AutoSkill 4
		nudAutoSkill4->Value = (Decimal)			Settings[AutoSkill4]->Value;
		ddbAutoSkill4Key->SelectedIndex = (int)		Settings[AutoSkill4Key]->Value;
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
		ddbSelectedPacket->SelectedIndex = (int)	Settings[SelectedPacket]->Value;
		nudSpamAmount->Value = (Decimal)			Settings[PacketSpamAmount]->Value;
		nudSpamDelay->Value = (Decimal)				Settings[PacketSpamDelay]->Value;
		//Hacks Tab
		nudSkillInjection->Value = (Decimal)		Settings[SkillInjectionDelay]->Value;
		ddbSkillInjection->SelectedIndex = (int)	Settings[SkillInjectionIndex]->Value;
		nudIceGuard->Value = (Decimal)				Settings[IceGuard]->Value;

		Sleep(2500);
		cbPinTyper->Checked = (bool)				Settings[PinTyper]->Value;
		cbLogoSkipper->Checked = (bool)				Settings[LogoSkipper]->Value;
		}catch(...){}
	}
}
Void MainForm::ReloadSettings()
{
		List<SettingsEntry^>^ m = gcnew List<SettingsEntry^>(SettingCount);
		//AutoAttack
		m->Add(gcnew SettingsEntry(nudAutoAttack));
		m->Add(gcnew SettingsEntry(nudSAWSIL));
		m->Add(gcnew SettingsEntry(ddbAutoAttackKey));
		//AutoLoot
		m->Add(gcnew SettingsEntry(nudAutoLoot));
		m->Add(gcnew SettingsEntry(nudSLWIB));
		m->Add(gcnew SettingsEntry(ddbAutoLootKey));
		//AutoHP
		m->Add(gcnew SettingsEntry(nudAutoHP));
		m->Add(gcnew SettingsEntry(ddbAutoHPKey));
		//AutoMP
		m->Add(gcnew SettingsEntry(nudAutoMP));
		m->Add(gcnew SettingsEntry(ddbAutoMPKey));
		//AutoSkill 1
		m->Add(gcnew SettingsEntry(nudAutoSkill1));
		m->Add(gcnew SettingsEntry(ddbAutoSkill1Key));
		//AutoSkill 2
		m->Add(gcnew SettingsEntry(nudAutoSkill2));
		m->Add(gcnew SettingsEntry(ddbAutoSkill2Key));
		//AutoSkill 3
		m->Add(gcnew SettingsEntry(nudAutoSkill3));
		m->Add(gcnew SettingsEntry(ddbAutoSkill3Key));
		//AutoSkill 4
		m->Add(gcnew SettingsEntry(nudAutoSkill4));
		m->Add(gcnew SettingsEntry(ddbAutoSkill4Key));
		//CC People
		m->Add(gcnew SettingsEntry(nudCCPeople));
		m->Add(gcnew SettingsEntry(ddbPeopleType));
		//CC Timed
		m->Add(gcnew SettingsEntry(nudCCTimed));
		m->Add(gcnew SettingsEntry(ddbTimedType));
		//CC Attacks
		m->Add(gcnew SettingsEntry(nudCCAttacks));
		m->Add(gcnew SettingsEntry(ddbAttacksType));
		//HotKeys
		m->Add(gcnew SettingsEntry(ddbHotKeyAttack));
		m->Add(gcnew SettingsEntry(ddbHotKeyLoot));
		m->Add(gcnew SettingsEntry(ddbHotKeyFMA));
		m->Add(gcnew SettingsEntry(ddbHotKeyCCPeople));
		m->Add(gcnew SettingsEntry(ddbHotKeySendPacket));
		//PacketSender
		m->Add(gcnew SettingsEntry(ddbSelectedPacket));
		m->Add(gcnew SettingsEntry(nudSpamAmount));
		m->Add(gcnew SettingsEntry(nudSpamDelay));
		//Hacks Tab
		m->Add(gcnew SettingsEntry(nudSkillInjection));
		m->Add(gcnew SettingsEntry(ddbSkillInjection));
		m->Add(gcnew SettingsEntry(nudIceGuard));
		
		m->Add(gcnew SettingsEntry(cbPinTyper));
		m->Add(gcnew SettingsEntry(cbLogoSkipper));
		Settings = m;
}
Void MainForm::bSaveSettings_Click(System::Object^  sender, System::EventArgs^  e)
{
	SaveSettings();
	SPControl->Save();
	CPacket->Save();
}

//Hot Keys
void MainForm::HotKeys()
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
}
