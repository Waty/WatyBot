#pragma once
#pragma warning(disable : 4793 4244)
#include <Windows.h>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include "MainForm.h"
#include "Memory.h"
#include "Defines.h"
#include "Pointers.h"
#include "Packet.h"
#include "SPControl.h"
#include "Hacks.h"

#include "MacroManager/FunctionalMacro.h"
#include "MacroManager/BotMacro.h"
#include "MacroManager/SkillMacro.h"
using namespace WatyBotRevamp;
using namespace msclr::interop;
using namespace System::IO;
using namespace std;

#define WatyBotWorkingDirectory "WatyBot\\"
#define SettingsFileName (WatyBotWorkingDirectory + "settings.ini")
#define PacketFileName (WatyBotWorkingDirectory + "packets.xml")
#define SPControlFileName (WatyBotWorkingDirectory + "spcontrol.xml")

//Macro's
Macro::AbstractMacro* AttackMacro;
Macro::AbstractMacro* LootMacro;
Macro::AbstractMacro* CCMacro;
Macro::SkillMacro* Skill1Macro;
Macro::SkillMacro* Skill2Macro;
Macro::SkillMacro* Skill3Macro;
Macro::SkillMacro* Skill4Macro;
StopWatch<milliseconds> PvPStopWatch;

gcroot<ChangeChannel::CChangeChannel^> CC;
gcroot<SpawnControl::SPControl^> SPControl;
gcroot<Packets::CPackets^> CPacket;

extern vector<gcroot<SpawnControl::SPControlLocation^>> vSPControl;
extern vector<gcroot<Packets::CPacketData^>> vPacket;

int getMobCount()
{
	return (int) ReadPointer(MobBasePtr, MobCountOffset);
}
int getItemCount()
{
	return (int) ReadPointer(ItemBasePtr, ItemCountOffset);
}
int getPeopleCount()
{
	return (int) ReadPointer(PeopleBasePtr, PeopleCountOffset);
}
int getCharX()
{
	return (int) ReadPointer(CharBasePtr,XOffset);
}
int getCharY()
{
	return (int) ReadPointer(CharBasePtr,XOffset + 4);
}
int getCharHP()
{
	WritePointer(SettingsBasePtr, HPAlertOffset, 20);
	return (int) ReadPointer(StatsBasePtr, HPOffset);
}
int getCharMP()
{
	WritePointer(SettingsBasePtr, MPAlertOffset, 20);
	return (int) ReadPointer(StatsBasePtr, MPOffset);
}
double getCharEXP()
{
	return ReadDoublePointer(StatsBasePtr, EXPOffset);
}
int getMapID()
{
	return (int) ReadPointer(InfoBasePtr, MapIDOffset);
}
int getAttackCount()
{
	return (int) ReadPointer(CharBasePtr, AttackCountOffset);
}
int getTubiValue()
{
	return (int) ReadPointer(ServerBasePtr, TubiOffset);
}
int getBreathValue()
{
	return (int) ReadPointer(CharBasePtr, BreathOffset);
}
int getChannel()
{
	return (int) ReadPointer(ServerBasePtr, ChannelOffset);
}
int getCharpID()
{
	if(*(int*)WallBasePtr)	return (int) ReadPointer(CharBasePtr, pIDOffset);
	else return 0;
}
int getKnockBack()
{
	if(*(int*)WallBasePtr)	return (int) ReadPointer(getCharpID(), KBOffset);
	else return 0;
}
int getKnockBackX()
{
	if(*(int*)WallBasePtr)	return (int) ReadPointer(getCharpID(), KBXOffset);
	else return 0;
}
int getKnockBackY()
{
	if(*(int*)WallBasePtr)	return (int) ReadPointer(getCharpID(), KBYOffset);
	else return 0;
}
	
bool InGame()
{
	if(getMapID() != 0)
		return true;

	else
		return false;
}

//Find Window
void getMSHWND()
{
	while(MapleStoryHWND == NULL)
	{
		MapleStoryHWND = FindProcessWindow();
		Sleep(1500);
	}
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
}
void MainForm::cbInstantAirLoot_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmInstantAirLoot.Enable(cbInstantAirLoot->Checked);
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
	Hacks::itemvac_x = getCharX();
	Hacks::itemvac_y = getCharY();
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
bool canAttack()
{
	if(CC->Busy) return false;
	if(getMobCount() >= AutoBotVars::iSawsil && InGame()) return true;
	return false;
}
bool canLoot()
{
	if(CC->Busy) return false;
	if(getItemCount() < AutoBotVars::iSlwib || !InGame()) return false;
	if(!WritePointer(ServerBasePtr, TubiOffset, 0)) return false;
	return true;
}
BOOL WINAPI canPvP()
{
	if(CC->Busy || UsingPot || UsingAutoSkill)
		return FALSE;

	if(PvPStopWatch.IsOver())
	{
		PvPStopWatch.Start();
		return TRUE;
	}
	return FALSE;
}
void AutoSkill(int KeyCodeIndex)
{
	if(KeyCodeIndex < KeyCodesSize)
	{
		//Send Key
		while(CC->Busy || UsingAutoSkill) Sleep(500);
		UsingAutoSkill = true;
		Sleep(250);
		SendKey(KeyCodes[KeyCodeIndex]);
		Sleep(50);
		UsingAutoSkill = false;		
	}
	else
	{
		//Send Packet
		String^ strError;
		if(!CPacket->Send(vPacket.at(KeyCodeIndex - KeyCodesSize)->Data, strError))
			ShowError(strError);
	}
}
void TimedCC()
{
	if(!CC->Busy) CC->CCSwitch(ChangeChannel::CChangeChannel::CCType::CC);
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
	AutoSkill(AutoSkill1ComboBox->SelectedIndex);
}
void MainForm::AutoSkill2CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill2ComboBox->Enabled = !this->AutoSkill2CheckBox->Checked;
	this->nudSkill2Value->Enabled = !this->AutoSkill2CheckBox->Checked;
	Skill2Macro->SetDelay((unsigned int) nudSkill2Value->Value * 1000);
	Skill2Macro->SetKeyIndex(AutoSkill2ComboBox->SelectedIndex);
	Skill2Macro->Toggle(AutoSkill2CheckBox->Checked);
	AutoSkill(AutoSkill2ComboBox->SelectedIndex);
}
void MainForm::AutoSkill3CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill3ComboBox->Enabled = !this->AutoSkill3CheckBox->Checked;
	this->nudSkill3Value->Enabled = !this->AutoSkill3CheckBox->Checked;
	Skill3Macro->SetDelay((unsigned int) nudSkill3Value->Value * 1000);
	Skill3Macro->SetKeyIndex(AutoSkill3ComboBox->SelectedIndex);
	Skill3Macro->Toggle(AutoSkill3CheckBox->Checked);
	AutoSkill(AutoSkill3ComboBox->SelectedIndex);
}
void MainForm::AutoSkill4CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill4ComboBox->Enabled = !this->AutoSkill4CheckBox->Checked;
	this->nudSkill4Value->Enabled = !this->AutoSkill4CheckBox->Checked;
	Skill4Macro->SetDelay((unsigned int) nudSkill4Value->Value * 1000);
	Skill4Macro->SetKeyIndex(AutoSkill4ComboBox->SelectedIndex);
	Skill4Macro->Toggle(AutoSkill4CheckBox->Checked);
	AutoSkill(AutoSkill4ComboBox->SelectedIndex);
}
void MainForm::CCTimeCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	CCMacro->SetDelay((unsigned int) nudCCTimed->Value);
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

	CC = gcnew ChangeChannel::CChangeChannel;
	SPControl= gcnew SpawnControl::SPControl;
	CPacket = gcnew Packets::CPackets;

	//Start the MacroManager
	InitializeMacros();

	if(!Directory::Exists("WatyBot"))	Directory::CreateDirectory("WatyBot");
	if(File::Exists(PacketFileName))	CPacket->Load(PacketFileName);
	if(File::Exists(SPControlFileName))	SPControl->Load(SPControlFileName);
	if(File::Exists(SettingsFileName))	LoadSettings();
	RefreshComboBoxes();
	RefreshSPControlListView();

	// Fix the size of the tabs
	MainForm::Height = TabHeight[MainTabControl->SelectedTab->TabIndex];
	MainTabControl->Height = TabHeight[MainTabControl->SelectedTab->TabIndex] - 30;
}
void MainForm::StatsTimer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	this->MobCountLabel->Text =		"Mobs: "		+ getMobCount();
	this->PeopleCountLabel->Text =	"People: "		+ getPeopleCount();
	this->CharPosLabel->Text =		"CharPos: ("	+ getCharX() +","+ getCharY()+")";
	this->ItemCountLabel->Text =	"Items: "		+ getItemCount();
	this->AttackCountLabel->Text =	"Attacks: "		+ getAttackCount();
	this->TubiPointerLabel->Text =	"Tubi: "		+ getTubiValue();
	this->BreathLabel->Text =		"Breath: "		+ getBreathValue();
	this->lMapID->Text =			"MapID: "		+ getMapID();
	this->lCharacterpID->Text =		"Char pID: "	+ getCharpID();
	this->lKnockBack->Text =		"KnockBack: "	+ getKnockBack();
	this->lKBCoords->Text =			"KB: (" + getKnockBackX() + "," + getKnockBackY() + ")";
	
	MainForm::AutoPot();
	MainForm::AutoCC();
	MainForm::RedrawStatBars();
	MainForm::HotKeys();

	//Set the correct state of the PacketSpammer Buttons
	bStopSpamming->Visible = CPacket->IsSpamming;
	bStartSpamming->Visible = !CPacket->IsSpamming;
}
void MainForm::AutoPot()
{
	if(HPCheckBox->Checked)
	{
		if(getCharHP() <= (int) nudHPValue->Value)
		{
			int HPKey = KeyCodes[HPComboBox->SelectedIndex];
			PostMessage(MapleStoryHWND, WM_KEYDOWN, HPKey, (MapVirtualKey(HPKey, 0) << 16) + 1);
		}
	}
	if(MPCheckBox->Checked)
	{
		if(getCharMP() <= (int) nudMPValue->Value)
		{
			int MPKey = KeyCodes[HPComboBox->SelectedIndex];
			PostMessage(MapleStoryHWND, WM_KEYDOWN, MPKey, (MapVirtualKey(MPKey, 0) << 16) + 1);
		}
	}
}
void MainForm::AutoCC()
{
	if(CCPeopleCheckBox->Checked && !CC->Busy && (getPeopleCount() >= (int) nudCCPeople->Value))
		CC->CCSwitch(ChangeChannel::CChangeChannel::CCType(PeopleComboBox->SelectedIndex));
	
	if(CCAttacksCheckBox->Checked && !CC->Busy && (getAttackCount() >= (int) nudCCAttacks->Value))
		CC->CCSwitch(ChangeChannel::CChangeChannel::CCType(AttacksComboBox->SelectedIndex));
}
void MainForm::RedrawStatBars()
{
	if(getCharHP() >= MaxHP || getCharHP() < 0)	MaxHP = getCharHP();
	if(getCharMP() >= MaxMP || getCharMP() < 0)	MaxMP = getCharMP();
	
	this->HPLabel->Text = "HP: " + getCharHP() + "/" + MaxHP;
	this->MPLabel->Text = "MP: " + getCharMP() + "/" + MaxMP;
	this->EXPLabel->Text = "EXP: " + getCharEXP().ToString("f2") +"%";
	

	int lengtOfBars  = 223;

	double HPBarLength = ((double)getCharHP()/(double)MaxHP) * lengtOfBars;
	this->HPForeground->Width = HPBarLength;
	double MPBarLength = ((double)getCharMP()/(double)MaxMP) * lengtOfBars;
	this->MPForeground->Width = MPBarLength;
	double EXPBarLength = (getCharEXP()/100) * lengtOfBars;
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
	SPControl->Save(SPControlFileName);
	CPacket->Save(PacketFileName);
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
	ShowInfo("Packet was added!");
	CPacket->Save(PacketFileName);
	RefreshComboBoxes();
}
void MainForm::DeletePacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	//delete packet from vector
	switch(MessageBox::Show("Are you sure you want to delete this packet?", "Please Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question))
	{
	case ::DialogResult::Yes:
		CPacket->Delete(DeletePacketComboBox->SelectedIndex);
		ShowInfo("Packet was deleted succesfully!");
		CPacket->Save(PacketFileName);
		RefreshComboBoxes();
		break;
	}	
}
void MainForm::SelectPacketForEditingComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(SelectPacketForEditingComboBox->SelectedIndex >= 0)
	{
		Packets::CPacketData^ p = vPacket.at(SelectPacketForEditingComboBox->SelectedIndex);
		this->EditPacketNameTextBox->Text = p->Name;
		this->EditPacketPacketTextBox->Text = p->Data;
	}
}
void MainForm::SavePacketEditButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	CPacket->Edit(SelectPacketForEditingComboBox->SelectedIndex, EditPacketNameTextBox->Text, EditPacketPacketTextBox->Text);
	CPacket->Save(PacketFileName);
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
	CPacket->SelectedPacket = vPacket.at(PacketSelectBox->SelectedIndex);
}
void MainForm::RefreshComboBoxes()
{	
	//clear old packets
	this->AddPacketNameTextBox->Text = String::Empty;
	this->AddPacketPacketTextBox->Text = String::Empty;
	this->PacketSelectBox->Items->Clear();
	this->SelectPacketForEditingComboBox->Items->Clear();
	this->DeletePacketComboBox->Items->Clear();
	this->AutoSkill1ComboBox->Items->Clear();
	this->AutoSkill2ComboBox->Items->Clear();
	this->AutoSkill3ComboBox->Items->Clear();
	this->AutoSkill4ComboBox->Items->Clear();

	//Add Keys to the autoskillcomboboxes
	this->AutoSkill1ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(58) {L"Shift", L"Space", L"Ctrl", L"Alt", L"Insert", L"Delete", L"Home", L"End", L"Page Up", L"Page Down", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"F1", L"F2", L"F3", L"F4", L"F5", L"F6", L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"});
	this->AutoSkill2ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(58) {L"Shift", L"Space", L"Ctrl", L"Alt", L"Insert", L"Delete", L"Home", L"End", L"Page Up", L"Page Down", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"F1", L"F2", L"F3", L"F4", L"F5", L"F6", L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"});
	this->AutoSkill3ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(58) {L"Shift", L"Space", L"Ctrl", L"Alt", L"Insert", L"Delete", L"Home", L"End", L"Page Up", L"Page Down", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"F1", L"F2", L"F3", L"F4", L"F5", L"F6", L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"});
	this->AutoSkill4ComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(58) {L"Shift", L"Space", L"Ctrl", L"Alt", L"Insert", L"Delete", L"Home", L"End", L"Page Up", L"Page Down", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"F1", L"F2", L"F3", L"F4", L"F5", L"F6", L"F7", L"F8", L"F9", L"F10", L"F11", L"F12"});

	//refresh comboboxes
	for(Packets::CPacketData^ p : vPacket)
	{
		try
		{
			String^ PacketName = p->Name;
			this->PacketSelectBox->Items->Add(PacketName);
			this->SelectPacketForEditingComboBox->Items->Add(PacketName);
			this->DeletePacketComboBox->Items->Add(PacketName);
			this->AutoSkill1ComboBox->Items->Add(PacketName);
			this->AutoSkill2ComboBox->Items->Add(PacketName);
			this->AutoSkill3ComboBox->Items->Add(PacketName);
			this->AutoSkill4ComboBox->Items->Add(PacketName);
		}
		catch(...){};
	}	
}

//controls on SPControl Tab
void MainForm::cbSPControl_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmSPControl.Enable(cbSPControl->Checked);
}
void MainForm::SPControlAddButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ name = SPControlNameTextBox->Text;
	int mapid = Convert::ToInt32(SPControlMapIDTextBox->Text);
	int x = Convert::ToInt32(SPControlXTextBox->Text);
	int y = Convert::ToInt32(SPControlYTextBox->Text);
	if(name == "" || !mapid || !x || !y)
		ShowWarning("You forgot to fill in a textbox...");
	else
	{
		SPControl->AddLocation(name, mapid, x, y);
		SPControl->Save(SPControlFileName);
		RefreshSPControlListView();
	}
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
			SPControl->DeleteLocation(SPControlListView->Items->IndexOf(L));
			SPControl->Save(SPControlFileName);
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
	this->SPControlXTextBox->Text = Convert::ToString(getCharX());
	this->SPControlYTextBox->Text = Convert::ToString(getCharY());
	this->SPControlMapIDTextBox->Text = Convert::ToString(getMapID());
}
void MainForm::RefreshSPControlListView()
{
	SPControlListView->Items->Clear();
	this->SPControlNameTextBox->Clear();
	this->SPControlMapIDTextBox->Clear();
	this->SPControlXTextBox->Clear();
	this->SPControlYTextBox->Clear();
	for(SpawnControl::SPControlLocation^ SP : vSPControl)
	{
		ListViewItem^ item = gcnew ListViewItem(SP->Name);
		item->SubItems->Add(Convert::ToString(SP->MapId));
		item->SubItems->Add(Convert::ToString(SP->X));
		item->SubItems->Add(Convert::ToString(SP->Y));
		SPControlListView->Items->Add(item);
	}
}

//Loading/Saving AutoBot settings
void MainForm::SaveSettings()
{
	File::Delete(SettingsFileName);
	ofstream file(marshal_as<string>(SettingsFileName));
	using boost::property_tree::ptree;
	ptree pt;

	//Auto Bot Tab
	pt.add("AutoAttackDelay", Convert::ToInt32(this->nudAttackDelay->Value));
	pt.add("SAWSIL", Convert::ToInt32(this->nudSAWSIL->Value));
	pt.add("AutoAttackKey", this->AttackComboBox->SelectedIndex);

	pt.add("LootDelay", Convert::ToInt32(this->nudLootDelay->Value));
	pt.add("SLWIB", Convert::ToInt32(this->nudSLWIB->Value));
	pt.add("LootKey", this->LootComboBox->SelectedIndex);

	pt.add("AutoHPValue", Convert::ToInt32(this->nudHPValue->Value));
	pt.add("AutoHPKey", this->HPComboBox->SelectedIndex);

	pt.add("AutoMPValue", Convert::ToInt32(this->nudMPValue->Value));
	pt.add("AutoMPKey", this->MPComboBox->SelectedIndex);

	pt.add("AutoSkill1Value", Convert::ToInt32(this->nudSkill1Value->Value));
	pt.add("AutoSkill1Key", this->AutoSkill1ComboBox->SelectedIndex);

	pt.add("AutoSkill2Value", Convert::ToInt32(this->nudSkill2Value->Value));
	pt.add("AutoSkill2Key", this->AutoSkill2ComboBox->SelectedIndex);

	pt.add("AutoSkill3Value", Convert::ToInt32(this->nudSkill3Value->Value));
	pt.add("AutoSkill3Key", this->AutoSkill3ComboBox->SelectedIndex);

	pt.add("AutoSkill4Value", Convert::ToInt32(this->nudSkill4Value->Value));
	pt.add("AutoSkill4Key", this->AutoSkill4ComboBox->SelectedIndex);

	pt.add("AutoCCPeople", Convert::ToInt32(nudCCPeople->Value));
	pt.add("CC_CS_People", this->PeopleComboBox->SelectedIndex);

	pt.add("AutoCCTimed", Convert::ToInt32(nudCCTimed->Value));
	pt.add("CC_CS_Timed", this->TimedComboBox->SelectedIndex);

	pt.add("AutoCCAttacks", Convert::ToInt32(nudCCAttacks->Value));
	pt.add("CC_CS_Attacks", this->AttacksComboBox->SelectedIndex);

	//Hot Keys
	pt.add("AttackHotKey", this->ddbHotKeyAttack->SelectedIndex);
	pt.add("LootHotKey", this->ddbHotKeyLoot->SelectedIndex);
	pt.add("FMAHotKey", this->ddbHotKeyFMA->SelectedIndex);
	pt.add("CCPeopleHotKey", this->ddbHotKeyCCPeople->SelectedIndex);
	pt.add("SendPacketHotKey", this->ddbHotKeySendPacket->SelectedIndex);

	//PacketSender Tab
	pt.add("PacketSenderIndex", this->PacketSelectBox->SelectedIndex);
	pt.add("PacketSpamTimes", (int) nudSpamAmount->Value);
	pt.add("PacketSpamDelay", (int) nudSpamDelay->Value);

	//Info Tab
	pt.add("LoadSettingsDelay", Convert::ToInt32(this->nudLoadDelay->Value));
	pt.add("PvPCCDelay", Convert::ToInt32(this->nudPvPCCDelay->Value));

	//Hacks Tab
	pt.add("PvPDelay", Convert::ToInt32(this->nudPVPDelay->Value));
	pt.add("PvPSkill", this->ddbPVPSkills->SelectedIndex);

	pt.add("PinTyper", this->cbPinTyper->Checked);
	pt.add("LogoSkipper", this->cbLogoSkipper->Checked);

	write_ini(file, pt);
}
void MainForm::LoadSettings()
{
	ifstream file(marshal_as<string>(SettingsFileName));
	using boost::property_tree::ptree;
	ptree pt;

	read_ini(file,pt);
	try
	{
		//Auto Bot Tab
		this->nudAttackDelay->Text = pt.get<int>("AutoAttackDelay", 50).ToString();
		this->nudSAWSIL->Text = pt.get<int>("SAWSIL", 1).ToString();
		this->AttackComboBox->SelectedIndex = pt.get<int>("AutoAttackKey");
		
		this->nudLootDelay->Text = pt.get<int>("LootDelay", 50).ToString();
		this->nudSLWIB->Text = pt.get<int>("SLWIB", 1).ToString();
		this->LootComboBox->SelectedIndex = pt.get<int>("LootKey");

		this->nudHPValue->Text = pt.get<int>("AutoHPValue", 9000).ToString();
		this->HPComboBox->SelectedIndex = pt.get<int>("AutoHPKey");

		this->nudMPValue->Text = pt.get<int>("AutoMPValue", 100).ToString();
		this->MPComboBox->SelectedIndex = pt.get<int>("AutoMPKey");

		this->AutoSkill1ComboBox->SelectedIndex = pt.get<int>("AutoSkill1Key");
		this->nudSkill1Value->Text = pt.get<int>("AutoSkill1Value", 0).ToString();

		this->AutoSkill2ComboBox->SelectedIndex = pt.get<int>("AutoSkill2Key");
		this->nudSkill2Value->Text = pt.get<int>("AutoSkill2Value", 0).ToString();

		this->AutoSkill3ComboBox->SelectedIndex = pt.get<int>("AutoSkill3Key");
		this->nudSkill3Value->Text = pt.get<int>("AutoSkill3Value", 0).ToString();

		this->AutoSkill4ComboBox->SelectedIndex = pt.get<int>("AutoSkill4Key");
		this->nudSkill4Value->Text = pt.get<int>("AutoSkill4Value", 0).ToString();

		this->nudCCPeople->Text = pt.get<int>("AutoCCPeople", 0).ToString();
		this->PeopleComboBox->SelectedIndex = pt.get<int>("CC_CS_People");

		this->nudCCTimed->Text = pt.get<int>("AutoCCTimed", 0).ToString();
		this->TimedComboBox->SelectedIndex = pt.get<int>("CC_CS_Timed");

		this->nudCCAttacks->Text = pt.get<int>("AutoCCAttacks", 0).ToString();
		this->AttacksComboBox->SelectedIndex = pt.get<int>("CC_CS_Attacks");

		//Hot Keys
		this->ddbHotKeyAttack->SelectedIndex = pt.get<int>("AttackHotKey");
		this->ddbHotKeyLoot->SelectedIndex = pt.get<int>("LootHotKey");
		this->ddbHotKeyFMA->SelectedIndex = pt.get<int>("FMAHotKey");
		this->ddbHotKeyCCPeople->SelectedIndex = pt.get<int>("CCPeopleHotKey");
		this->ddbHotKeySendPacket->SelectedIndex = pt.get<int>("SendPacketHotKey");

		//Info Tab
		this->nudLoadDelay->Text = pt.get<int>("LoadSettingsDelay", 1000).ToString();
		this->nudPvPCCDelay->Text = pt.get<int>("PvPCCDelay", 2000).ToString();

		//PacketSender Tab
		this->PacketSelectBox->SelectedIndex =  pt.get<int>("PacketSenderIndex");
		this->nudSpamAmount->Text = pt.get<int>("PacketSpamTimes").ToString();
		this->nudSpamDelay->Text = pt.get<int>("PacketSpamDelay").ToString();

		//Hacks Tab
		this->nudPVPDelay->Text = pt.get<int>("PvPDelay").ToString();
		this->ddbPVPSkills->SelectedIndex = pt.get<int>("PvPSkill");

		Sleep(Convert::ToInt32(nudLoadDelay->Value));
		this->cbPinTyper->Checked = pt.get<bool>("PinTyper", false);
		this->cbLogoSkipper->Checked = pt.get<bool>("LogoSkipper", false);
	}catch(...){};
}
void MainForm::bSaveSettings_Click(System::Object^  sender, System::EventArgs^  e)
{
	MainForm::SaveSettings();
	SPControl->Save(SPControlFileName);
	CPacket->Save(PacketFileName);
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
