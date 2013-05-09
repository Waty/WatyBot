#pragma once
#pragma warning(disable : 4793 4244)
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include "MainForm.h"
#include "Memory.h"
#include "Defines.h"
#include "Pointers.h"
#include "Packet.h"
#include "SPControl.h"
#include "Hacks.h"
#include "MapleStory.h"
#include "MacroManager/FunctionalMacro.h"
#include "MacroManager/BotMacro.h"
#include "MacroManager/SkillMacro.h"
#include "Settings.h"
using namespace Settings;
using namespace WatyBotRevamp;
using namespace msclr::interop;
using namespace System::IO;
using namespace std;
using namespace Packets;
using namespace SpawnControl;

#define WatyBotWorkingDirectory Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData) + "\\Waty\\"
#define SettingsFileName (WatyBotWorkingDirectory + "WatyBotSettings.xml")

//Macro's
Macro::BotMacro* AttackMacro;
Macro::BotMacro* LootMacro;
Macro::FunctionalMacro* CCMacro;
Macro::SkillMacro* Skill1Macro;
Macro::SkillMacro* Skill2Macro;
Macro::SkillMacro* Skill3Macro;
Macro::SkillMacro* Skill4Macro;
StopWatch<milliseconds> PvPStopWatch;

gcroot<CMapleStory^> CMS;
gcroot<ChangeChannel::CChangeChannel^> CC;
gcroot<SPControl^> CSPControl;
gcroot<CPackets^> CPacket;

//Find Window
void getMSHWND()
{
	while(!CMS->FindProcessWindow());
}

//Hack CheckBoxes
void MainForm::cbFusionAttack_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmFusionAttack.Enable(cbFusionAttack->Checked);
}
void MainForm::cbNoKB_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmNoKB.Enable(cbNoKB->Checked);
}
void MainForm::cbPerfectLoot_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmPerfectLoot.Enable(cbPerfectLoot->Checked);
	Hacks::cmInstantAirLoot.Enable(cbPerfectLoot->Checked);
}
void MainForm::cbVacRight_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmVacRight.Enable(cbVacRight->Checked);
}
void MainForm::cbWalkRight_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmWalkRight.Enable(cbWalkRight->Checked);
}
void MainForm::cbJumpRight_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmJumpRight.Enable(cbJumpRight->Checked);
}
void MainForm::cbMobDisarm_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmMobDisarm.Enable(cbMobDisarm->Checked);
}
void MainForm::cbNoBG_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmNoBG.Enable(cbNoBG->Checked);
}
void MainForm::cbJDA_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmJDA.Enable(cbJDA->Checked);
}
void MainForm::cbPinTyper_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmPinTyper.Enable(cbPinTyper->Checked);
}
void MainForm::cbDojangGodmode_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmDojangGodmode.Enable(cbDojangGodmode->Checked);
}
void MainForm::cbIceGuard_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->nudIceGuard->Enabled = !this->cbIceGuard->Checked;
	Hacks::iIceGuardLimit = (int)nudIceGuard->Value;
	Hacks::cmIceGuard.Enable(cbIceGuard->Checked);
}
void MainForm::cbUnlimitedMorph_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmUnlimitedMorph.Enable(cbUnlimitedMorph->Checked);
}
void MainForm::cbFasterMobs_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmFasterMobs.Enable(cbFasterMobs->Checked);
}
void MainForm::cbNDAllAttacks_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmNDAllAttacks.Enable(cbNDAllAttacks->Checked);
}
void MainForm::cbNoMobs_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmNoMobs.Enable(cbNoMobs->Checked);
}
void MainForm::cbAutoAggro_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmAutoAggro.Enable(cbAutoAggro->Checked);
}
void MainForm::cbSitHack_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmSitHack.Enable(cbSitHack->Checked);
}
void MainForm::cb50SecGM_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cm50SecGM.Enable(cb50SecGM->Checked);
}
void MainForm::cbLogoSkipper_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmLogoSkipper.Enable(cbLogoSkipper->Checked);
}
void MainForm::cbViewSwears_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmNoSwears.Enable(cbViewSwears->Checked);
}
void MainForm::cbItemVac_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::itemvac_x = CMS->CharX;
	Hacks::itemvac_y = CMS->CharY;
	Hacks::cmItemVac.Enable(cbItemVac->Checked);
}
void MainForm::cbFMA_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	cbNFA->Checked = cbFMA->Checked;
	cbItemVac->Checked = cbFMA->Checked;
	cbItemVac->Enabled = !cbFMA->Checked;
	Hacks::cmFMA.Enable(cbFMA->Checked);
}
void MainForm::cbScareMobs_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmScareMobs.Enable(cbScareMobs->Checked);
}
void MainForm::cbFLACC_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmFLACC.Enable(cbFLACC->Checked);
}
void MainForm::cbCPUHack_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmCPUHack.Enable(cbCPUHack->Checked);
}
void MainForm::cbUA_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmUA.Enable(cbUA->Checked);
}
void MainForm::cbNFA_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmDFA.Enable(cbNFA->Checked);
}
void MainForm::cbNDMining_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmNDMining.Enable(cbNDMining->Checked);
}
void MainForm::cbHideDamage_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmHideDamage.Enable(cbHideDamage->Checked);
}
void MainForm::cbMercedesCombo_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmMercedesCombo.Enable(cbMercedesCombo->Checked);
}
void MainForm::cbNoFadeStages_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmNoFadeStages.Enable(cbNoFadeStages->Checked);
}
void MainForm::cbMouseFly_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmMouseFly.Enable(cbMouseFly->Checked);
}
void MainForm::cbPVP_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(ddbPVPSkills->SelectedIndex < 0)
	{
		if(cbPVP->Checked)
		{
			ShowError("Please Select a Skill");
			cbPVP->Checked = false;
		}
	}
	else
	{
		//set variables
		Hacks::iPVPSkillID = PVPSkills[ddbPVPSkills->SelectedIndex];
		PvPStopWatch.SetDelay(milliseconds((int) nudPVPDelay->Value));

		cbNFA->Checked = false;
		Hacks::cmPVP1.Enable(cbPVP->Checked);
		Hacks::cmPVP2.Enable(cbPVP->Checked);
	}
}
void MainForm::nudPVPDelay_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	PvPStopWatch.SetDelay(milliseconds((int) nudPVPDelay->Value));
}
void MainForm::ddbPVPSkills_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::iPVPSkillID = ddbPVPSkills->SelectedIndex;
}
void MainForm::cbNoCCBlueBoxes_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmNoCCBoxes.Enable(this->cbNoCCBlueBoxes->Checked);
}

//AutoHP/MP/CC Checkboxes
void MainForm::HPCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	nudHPValue->Enabled = !HPCheckBox->Checked;
	HPComboBox->Enabled = !HPCheckBox->Checked;
}
void MainForm::MPCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	nudMPValue->Enabled = !MPCheckBox->Checked;
	MPComboBox->Enabled = !MPCheckBox->Checked;
}
void MainForm::CCPeopleCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	nudCCPeople->Enabled = !CCPeopleCheckBox->Checked;
}

//Macro's
Macro::MacroManager macroMan;
enum MacroIndex{eAttack, eLoot, eCC, eAutoSkill1, eAutoSkill2, eAutoSkill3, eAutoSkill4};
void SpamKey(int KeyCode)
{
	PostMessage(CMS->MSHWND, WM_KEYDOWN, KeyCode, (MapVirtualKey(KeyCode, 0) << 16) + 1);
	PostMessage(CMS->MSHWND, WM_KEYUP, KeyCode, (MapVirtualKey(KeyCode, 0) << 16) + 1);
}
bool canAttack()
{
	if(CC->Busy) return false;
	if(CMS->MobCount >= AutoBotVars::iSawsil && CMS->InGame) return true;
	return false;
}
bool canLoot()
{
	if(!CMS->InGame) return false;
	if(CMS->ItemCount < AutoBotVars::iSlwib) return false;
	if(!CMS->WritePointer(ServerBasePtr, TubiOffset, 0)) return false;
	return true;
}
BOOL WINAPI canPvP()
{
	if(CC->Busy || UsingPot || UsingAutoSkill || !PvPStopWatch.IsOver()) return FALSE;
	
	PvPStopWatch.Start();
	return TRUE;
}
void AutoSkill(int KeyCodeIndex)
{
	if(KeyCodeIndex < KeyCodesSize)
	{
		//Send Key
		while(CC->Busy || UsingAutoSkill) Sleep(500);
		UsingAutoSkill = true;
		Sleep(500);
		SendKey(KeyCodes[KeyCodeIndex]);
		Sleep(500);
		UsingAutoSkill = false;		
	}
	else
	{
		//Send Packet
		CPacket->Send(CPacket->Packets[KeyCodeIndex - KeyCodesSize]);
	}
}
void TimedCC()
{
	CC->CCSwitch(ChangeChannel::CChangeChannel::CCType(CCMacro->GetValue()));
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
	this->nudAttackDelay->Enabled = !AttackCheckBox->Checked;
	this->nudSAWSIL->Enabled = !AttackCheckBox->Checked;
	this->AttackComboBox->Enabled = !AttackCheckBox->Checked;

	AutoBotVars::iSawsil = (int) nudSAWSIL->Value;
	AttackMacro->SetValue(KeyCodes[AttackComboBox->SelectedIndex]);
	AttackMacro->SetDelay((unsigned int) nudAttackDelay->Value);
	AttackMacro->Toggle(AttackCheckBox->Checked);
}
void MainForm::LootCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->LootComboBox->Enabled = !this->LootCheckBox->Checked;
	this->nudLootDelay->Enabled = !this->LootCheckBox->Checked;
	this->nudSLWIB->Enabled = !this->LootCheckBox->Checked;
		
	AutoBotVars::iSlwib = (int) nudSLWIB->Value;
	LootMacro->SetValue(KeyCodes[LootComboBox->SelectedIndex]);
	LootMacro->SetDelay((unsigned int) nudLootDelay->Value);
	LootMacro->Toggle(this->LootCheckBox->Checked);
}
void MainForm::AutoSkill1CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill1ComboBox->Enabled = !this->AutoSkill1CheckBox->Checked;
	this->nudSkill1Value->Enabled = !this->AutoSkill1CheckBox->Checked;
	Skill1Macro->SetDelay((unsigned int) nudSkill1Value->Value * 1000);
	Skill1Macro->SetKeyIndex(AutoSkill1ComboBox->SelectedIndex);
	Skill1Macro->Toggle(AutoSkill1CheckBox->Checked);
	if(this->AutoSkill1CheckBox->Checked) AutoSkill(AutoSkill1ComboBox->SelectedIndex);
}
void MainForm::AutoSkill2CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill2ComboBox->Enabled = !this->AutoSkill2CheckBox->Checked;
	this->nudSkill2Value->Enabled = !this->AutoSkill2CheckBox->Checked;
	Skill2Macro->SetDelay((unsigned int) nudSkill2Value->Value * 1000);
	Skill2Macro->SetKeyIndex(AutoSkill2ComboBox->SelectedIndex);
	Skill2Macro->Toggle(AutoSkill2CheckBox->Checked);
	if(this->AutoSkill2CheckBox->Checked) AutoSkill(AutoSkill2ComboBox->SelectedIndex);
}
void MainForm::AutoSkill3CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill3ComboBox->Enabled = !this->AutoSkill3CheckBox->Checked;
	this->nudSkill3Value->Enabled = !this->AutoSkill3CheckBox->Checked;
	Skill3Macro->SetDelay((unsigned int) nudSkill3Value->Value * 1000);
	Skill3Macro->SetKeyIndex(AutoSkill3ComboBox->SelectedIndex);
	Skill3Macro->Toggle(AutoSkill3CheckBox->Checked);
	if(this->AutoSkill3CheckBox->Checked) AutoSkill(AutoSkill3ComboBox->SelectedIndex);
}
void MainForm::AutoSkill4CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill4ComboBox->Enabled = !this->AutoSkill4CheckBox->Checked;
	this->nudSkill4Value->Enabled = !this->AutoSkill4CheckBox->Checked;
	Skill4Macro->SetDelay((unsigned int) nudSkill4Value->Value * 1000);
	Skill4Macro->SetKeyIndex(AutoSkill4ComboBox->SelectedIndex);
	Skill4Macro->Toggle(AutoSkill4CheckBox->Checked);
	if(this->AutoSkill4CheckBox->Checked) AutoSkill(AutoSkill4ComboBox->SelectedIndex);
}
void MainForm::CCTimeCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->TimedComboBox->Enabled = !this->CCTimedCheckBox->Checked;
	this->nudCCTimed->Enabled = !this->CCTimedCheckBox->Checked;

	CCMacro->SetDelay((unsigned int) nudCCTimed->Value * 1000);
	CCMacro->SetValue(this->TimedComboBox->SelectedIndex);
	CCMacro->Toggle(CCTimedCheckBox->Checked);
}
void MainForm::CCAttacksCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	nudCCAttacks->Enabled = !CCAttacksCheckBox->Checked;
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
	//Get the hwnd of maplestory
	NewThread(getMSHWND);

	//Create the Waty directory in %appdata%
	if(!Directory::Exists(WatyBotWorkingDirectory))	Directory::CreateDirectory(WatyBotWorkingDirectory);

	//Loading of all the settings and innitializing th classes
	CC = gcnew ChangeChannel::CChangeChannel;
	CMS = gcnew CMapleStory;
	SPControl^s = gcnew SPControl;
	CSPControl = s->Load();
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
	this->lMapID->Text =			"MapID: "		+ CMS->MapID;
	this->lCharacterpID->Text =		"Char pID: "	+ CMS->CharpID;
	this->lKnockBack->Text =		"KnockBack: "	+ CMS->KnockBack;
	this->lKBCoords->Text =			"KB: (" + CMS->KnockBackX + "," + CMS->KnockBackY + ")";
	
	MainForm::AutoPot();
	MainForm::AutoCC();
	MainForm::RedrawStatBars();
	MainForm::HotKeys();

	//Set the correct state of the PacketSpammer Buttons
	if(AttackMacro != nullptr){
	bStopSpamming->Visible = CPacket->IsSpamming;
	bStartSpamming->Visible = !CPacket->IsSpamming;}
}
void MainForm::AutoPot()
{
	if(HPCheckBox->Checked)
	{
		if(CMS->CharHP <= (int) nudHPValue->Value)
		{
			int HPKey = KeyCodes[HPComboBox->SelectedIndex];
			PostMessage(CMS->MSHWND, WM_KEYDOWN, HPKey, (MapVirtualKey(HPKey, 0) << 16) + 1);
		}
	}
	if(MPCheckBox->Checked)
	{
		if(CMS->CharMP <= (int) nudMPValue->Value)
		{
			int MPKey = KeyCodes[HPComboBox->SelectedIndex];
			PostMessage(CMS->MSHWND, WM_KEYDOWN, MPKey, (MapVirtualKey(MPKey, 0) << 16) + 1);
		}
	}
}
void MainForm::AutoCC()
{
	if(CCPeopleCheckBox->Checked && (CMS->PeopleCount >= (int) nudCCPeople->Value))
		CC->CCSwitch(ChangeChannel::CChangeChannel::CCType(PeopleComboBox->SelectedIndex));
	
	if(CCAttacksCheckBox->Checked && (CMS->AttackCount >= (int) nudCCAttacks->Value))
		CC->CCSwitch(ChangeChannel::CChangeChannel::CCType(AttacksComboBox->SelectedIndex));
}
void MainForm::RedrawStatBars()
{
	if(CMS->CharHP >= MaxHP || CMS->CharHP < 0)	MaxHP = CMS->CharHP;
	if(CMS->CharMP >= MaxMP || CMS->CharMP < 0)	MaxMP = CMS->CharMP;
	
	this->HPLabel->Text = "HP: " + CMS->CharHP + "/" + MaxHP;
	this->MPLabel->Text = "MP: " + CMS->CharMP + "/" + MaxMP;
	this->EXPLabel->Text = "EXP: " + CMS->CharEXP.ToString("f2") +"%";
	

	int lengtOfBars  = 223;

	double HPBarLength = ((double) CMS->CharHP / (double) MaxHP) * lengtOfBars;
	this->HPForeground->Width = HPBarLength;
	double MPBarLength = ((double) CMS->CharMP / (double) MaxMP) * lengtOfBars;
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
	CSPControl->Save();
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
	CPacket->Add(this->AddPacketNameTextBox->Text, this->AddPacketPacketTextBox->Text);
	RefreshComboBoxes();
	ShowInfo("Packet was added!");
}
void MainForm::DeletePacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	//delete packet from List
	switch(MessageBox::Show("Are you sure you want to delete this packet?", "Please Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question))
	{
	case ::DialogResult::Yes:
		CPacket->Delete(DeletePacketComboBox->SelectedIndex);
		ShowInfo("Packet was deleted succesfully!");
		CPacket->Save();
		RefreshComboBoxes();
		break;
	}	
}
void MainForm::SelectPacketForEditingComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(SelectPacketForEditingComboBox->SelectedIndex >= 0)
	{
		CPacketData^ p = CPacket->Packets[SelectPacketForEditingComboBox->SelectedIndex];
		this->EditPacketNameTextBox->Text = p->Name;
		this->EditPacketPacketTextBox->Text = p->Data;
	}
}
void MainForm::SavePacketEditButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	CPacket->Edit(SelectPacketForEditingComboBox->SelectedIndex, EditPacketNameTextBox->Text, EditPacketPacketTextBox->Text);
	CPacket->Save();
	RefreshComboBoxes();
}
void MainForm::SpamsPacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	if(nudSpamDelay->Value != 0 && nudSpamAmount->Value != 0) CPacket->StartSpamming((int) nudSpamAmount->Value, (int) nudSpamDelay->Value);	
}
void MainForm::bStopSpamming_Click(System::Object^  sender, System::EventArgs^  e)
{
	CPacket->StopSpamming();
}
void MainForm::PacketSelectBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	CPacket->SelectedPacket = CPacket->Packets[PacketSelectBox->SelectedIndex];
}
void MainForm::RefreshComboBoxes()
{	
	//clear old packets
	this->AddPacketNameTextBox->Text = String::Empty;
	this->AddPacketPacketTextBox->Text = String::Empty;
	this->PacketSelectBox->Items->Clear();
	this->SelectPacketForEditingComboBox->Items->Clear();
	this->DeletePacketComboBox->Items->Clear();

	//refresh comboboxes
	for each(CPacketData^ p in CPacket->Packets) 
	{
		String^ PacketName = p->Name;
		this->PacketSelectBox->Items->Add(PacketName);
		this->SelectPacketForEditingComboBox->Items->Add(PacketName);
		this->DeletePacketComboBox->Items->Add(PacketName);
	}	
}
void MainForm::AutoSkill1ComboBox_DropDown(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill1ComboBox->Items->Clear();
	this->AutoSkill1ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(58) {L"Shift", L"Space", L"Ctrl", L"Alt", L"Insert", L"Delete", L"Home", L"End", L"Page Up", L"Page Down", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"F1", L"F2", L"F3", L"F4", L"F5", L"F6", L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"});
	for each(CPacketData^ p in CPacket->Packets) this->AutoSkill1ComboBox->Items->Add(p->Name);
}
void MainForm::AutoSkill2ComboBox_DropDown(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill2ComboBox->Items->Clear();
	this->AutoSkill2ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(58) {L"Shift", L"Space", L"Ctrl", L"Alt", L"Insert", L"Delete", L"Home", L"End", L"Page Up", L"Page Down", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"F1", L"F2", L"F3", L"F4", L"F5", L"F6", L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"});
	for each(CPacketData^ p in CPacket->Packets) this->AutoSkill2ComboBox->Items->Add(p->Name);
}
void MainForm::AutoSkill3ComboBox_DropDown(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill3ComboBox->Items->Clear();
	this->AutoSkill3ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(58) {L"Shift", L"Space", L"Ctrl", L"Alt", L"Insert", L"Delete", L"Home", L"End", L"Page Up", L"Page Down", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"F1", L"F2", L"F3", L"F4", L"F5", L"F6", L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"});
	for each(CPacketData^ p in CPacket->Packets) this->AutoSkill3ComboBox->Items->Add(p->Name);
}
void MainForm::AutoSkill4ComboBox_DropDown(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill3ComboBox->Items->Clear();
	this->AutoSkill3ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(58) {L"Shift", L"Space", L"Ctrl", L"Alt", L"Insert", L"Delete", L"Home", L"End", L"Page Up", L"Page Down", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"F1", L"F2", L"F3", L"F4", L"F5", L"F6", L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"});
	for each(CPacketData^ p in CPacket->Packets) this->AutoSkill3ComboBox->Items->Add(p->Name);
}

//controls on SPControl Tab
void MainForm::cbSPControl_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmSPControl.Enable(cbSPControl->Checked);
}
void MainForm::SPControlAddButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ name = SPControlNameTextBox->Text;
	int mapid = (int) nudSPCMapId->Value;
	int x = (int) nudSPCX->Value;
	int y = (int) nudSPCY->Value;
	if(name == "" || !mapid || !x || !y)
	{
		ShowWarning("You forgot to fill in a textbox...");
		return;
	}

	CSPControl->AddLocation(name, mapid, x, y);
	RefreshSPControlListView();
}
void MainForm::SPControlDeleteItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->SPControlListView->SelectedItems;
	ListViewItem^ L = this->SPControlListView->SelectedItems[0];
	if(SPControlListView->SelectedItems->Count > 0)
	{
		switch(MessageBox::Show("Are you sure you want to delete this location?", "Please Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question))
		{
		case ::DialogResult::Yes:
			CSPControl->RemoveAt(SPControlListView->Items->IndexOf(L));
			CSPControl->Save();
			RefreshSPControlListView();
			break;
		}
	}
}
void MainForm::GetSPControlCoordsButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	for(int i = 0; i < 10; i++)
	{
		SendKey(VK_DOWN);
		Sleep(10);
	}
	this->nudSPCMapId->Value = CMS->CharX;
	this->nudSPCX->Value = CMS->CharY;
	this->nudSPCY->Value = CMS->MapID;
}
void MainForm::RefreshSPControlListView()
{
	SPControlListView->Items->Clear();
	this->SPControlNameTextBox->Clear();
	this->nudSPCMapId->ResetText();
	this->nudSPCX->ResetText();
	this->nudSPCY->ResetText();
	auto e = CSPControl->GetEnumerator();
	while(e.MoveNext())
	{
		SPControlLocation^ SP = e.Current;
		ListViewItem^ item = gcnew ListViewItem(SP->Name);
		item->SubItems->Add(SP->MapId.ToString());
		item->SubItems->Add(SP->X.ToString());
		item->SubItems->Add(SP->Y.ToString());
		SPControlListView->Items->Add(item);
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
		ReloadSettings();
		return;
	}

	TextReader^ reader;
	try
	{
		reader = gcnew StreamReader(SettingsFileName);
		XmlSerializer^ serializer = gcnew XmlSerializer(List<SettingsEntry^>::typeid);
		Settings = safe_cast<List<SettingsEntry^>^>(serializer->Deserialize(reader));
		reader->Close();
		
		//AutoAttack
		nudAttackDelay->Value = (Decimal)			Settings[0]->Value;
		nudSAWSIL->Value = (Decimal)				Settings[1]->Value;
		AttackComboBox->SelectedIndex = (int)		Settings[2]->Value;
		//AutoLoot
		nudLootDelay->Value = (Decimal)				Settings[3]->Value;
		nudSLWIB->Value = (Decimal)					Settings[4]->Value;
		LootComboBox->SelectedIndex = (int)			Settings[5]->Value;
		//AutoHP
		nudHPValue->Value = (Decimal)				Settings[6]->Value;
		HPComboBox->SelectedIndex = (int)			Settings[7]->Value;
		//AutoMP
		nudMPValue->Value = (Decimal)				Settings[8]->Value;
		MPComboBox->SelectedIndex = (int)			Settings[9]->Value;
		//AutoSkill 1
		nudSkill1Value->Value = (Decimal)			Settings[10]->Value;
		AutoSkill1ComboBox->SelectedIndex = (int)	Settings[11]->Value;
		//AutoSkill 2
		nudSkill2Value->Value = (Decimal)			Settings[12]->Value;
		AutoSkill2ComboBox->SelectedIndex = (int)	Settings[13]->Value;
		//AutoSkill 3
		nudSkill3Value->Value = (Decimal)			Settings[14]->Value;
		AutoSkill3ComboBox->SelectedIndex = (int)	Settings[15]->Value;
		//AutoSkill 4
		nudSkill4Value->Value = (Decimal)			Settings[16]->Value;
		AutoSkill4ComboBox->SelectedIndex = (int)	Settings[17]->Value;
		//CC People
		nudCCPeople->Value = (Decimal)				Settings[18]->Value;
		PeopleComboBox->SelectedIndex = (int)		Settings[19]->Value;
		//CC Timed
		nudCCTimed->Value = (Decimal)				Settings[20]->Value;
		TimedComboBox->SelectedIndex = (int)		Settings[21]->Value;
		//CC Attacks
		nudCCAttacks->Value = (Decimal)				Settings[22]->Value;
		AttacksComboBox->SelectedIndex = (int)		Settings[23]->Value;
		//HotKeys
		ddbHotKeyAttack->SelectedIndex = (int)		Settings[24]->Value;
		ddbHotKeyLoot->SelectedIndex = (int)		Settings[25]->Value;
		ddbHotKeyFMA->SelectedIndex = (int)			Settings[26]->Value;
		ddbHotKeyCCPeople->SelectedIndex = (int)	Settings[27]->Value;
		ddbHotKeySendPacket->SelectedIndex = (int)	Settings[28]->Value;
		//PacketSender
		PacketSelectBox->SelectedIndex = (int)		Settings[29]->Value;
		nudSpamAmount->Value = (Decimal)			Settings[30]->Value;
		nudSpamDelay->Value = (Decimal)				Settings[31]->Value;
		//Hacks Tab
		nudPVPDelay->Value = (Decimal)				Settings[32]->Value;
		ddbPVPSkills->SelectedIndex = (int)			Settings[33]->Value;
		nudIceGuard->Value = (Decimal)				Settings[34]->Value;
		
		cbPinTyper->Checked = (bool)				Settings[35]->Value;
		cbLogoSkipper->Checked = (bool)				Settings[36]->Value;
		return;
	}
	catch(System::Exception^)
	{
		reader->Close();
		ReloadSettings();
		return;
	}
}
Void MainForm::ReloadSettings()
{
		List<SettingsEntry^>^ m = gcnew List<SettingsEntry^>;
		//AutoAttack
		m->Add(gcnew SettingsEntry(nudAttackDelay));
		m->Add(gcnew SettingsEntry(nudSAWSIL));
		m->Add(gcnew SettingsEntry(AttackComboBox));
		//AutoLoot
		m->Add(gcnew SettingsEntry(nudLootDelay));
		m->Add(gcnew SettingsEntry(nudSLWIB));
		m->Add(gcnew SettingsEntry(LootComboBox));
		//AutoHP
		m->Add(gcnew SettingsEntry(nudHPValue));
		m->Add(gcnew SettingsEntry(HPComboBox));
		//AutoMP
		m->Add(gcnew SettingsEntry(nudMPValue));
		m->Add(gcnew SettingsEntry(MPComboBox));
		//AutoSkill 1
		m->Add(gcnew SettingsEntry(nudSkill1Value));
		m->Add(gcnew SettingsEntry(AutoSkill1ComboBox));
		//AutoSkill 2
		m->Add(gcnew SettingsEntry(nudSkill2Value));
		m->Add(gcnew SettingsEntry(AutoSkill2ComboBox));
		//AutoSkill 3
		m->Add(gcnew SettingsEntry(nudSkill3Value));
		m->Add(gcnew SettingsEntry(AutoSkill3ComboBox));
		//AutoSkill 4
		m->Add(gcnew SettingsEntry(nudSkill4Value));
		m->Add(gcnew SettingsEntry(AutoSkill4ComboBox));
		//CC People
		m->Add(gcnew SettingsEntry(nudCCPeople));
		m->Add(gcnew SettingsEntry(PeopleComboBox));
		//CC Timed
		m->Add(gcnew SettingsEntry(nudCCTimed));
		m->Add(gcnew SettingsEntry(TimedComboBox));
		//CC Attacks
		m->Add(gcnew SettingsEntry(nudCCAttacks));
		m->Add(gcnew SettingsEntry(AttacksComboBox));
		//HotKeys
		m->Add(gcnew SettingsEntry(ddbHotKeyAttack));
		m->Add(gcnew SettingsEntry(ddbHotKeyLoot));
		m->Add(gcnew SettingsEntry(ddbHotKeyFMA));
		m->Add(gcnew SettingsEntry(ddbHotKeyCCPeople));
		m->Add(gcnew SettingsEntry(ddbHotKeySendPacket));
		//PacketSender
		m->Add(gcnew SettingsEntry(PacketSelectBox));
		m->Add(gcnew SettingsEntry(nudSpamAmount));
		m->Add(gcnew SettingsEntry(nudSpamDelay));
		//Hacks Tab
		m->Add(gcnew SettingsEntry(nudPVPDelay));
		m->Add(gcnew SettingsEntry(ddbPVPSkills));
		m->Add(gcnew SettingsEntry(nudIceGuard));
		
		m->Add(gcnew SettingsEntry(cbPinTyper));
		m->Add(gcnew SettingsEntry(cbLogoSkipper));
		Settings = m;
}
void MainForm::bSaveSettings_Click(System::Object^  sender, System::EventArgs^  e)
{
	SaveSettings();
	CSPControl->Save();
	CPacket->Save();
}

//Hot Keys
void MainForm::HotKeys()
{
	if(this->cbHotKeyAttack->Checked)
	{
		if(GetAsyncKeyState(KeyCodes[ddbHotKeyAttack->SelectedIndex]))
		{
			this->AttackCheckBox->Checked = !this->AttackCheckBox->Checked;
			Sleep(250);
		}
	}
	if(this->cbHotKeyLoot->Checked)
	{
		if(GetAsyncKeyState(KeyCodes[ddbHotKeyLoot->SelectedIndex]))
		{
			this->LootCheckBox->Checked = !this->LootCheckBox->Checked;
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
			this->CCPeopleCheckBox->Checked = !this->CCPeopleCheckBox->Checked;
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
