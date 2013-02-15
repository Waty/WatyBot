#pragma once
#pragma warning(disable : 4793 4244)
#include "MainForm.h"
#include "Memory.h"
#include <Windows.h>
#include "Defines.h"
#include "Pointers.h"
#include "SendPacket.h"
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include "Packet.h"
#include "SPControl.h"
#include "Hacks.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
using namespace std;
using namespace WatyBotRevamp;
using namespace msclr::interop;
using namespace System::IO;

//Fill the list of packets
string WatyBotWorkingDirectory = "WatyBot\\";
string SettingsFileName = WatyBotWorkingDirectory + "settings.ini";
string PacketFileName = WatyBotWorkingDirectory + "packets.xml";
string SPControlFileName = WatyBotWorkingDirectory + "spcontrol.xml";

public ref class Globals
{
public:
	static array <System::Object^> ^KeyNames;
};

#pragma region Packetsending stuff
bool isGoodPacket(String^ strPacket, String^&strError)
{
    if(strPacket == String::Empty)
	{
        strError = "Packet is Empty";
        return false;
    }
 
    if((strPacket->Length)%2 == 1)
	{
        strError = "Packet size is not a multiple of 2";
        return false;
    }
 
    for (int i = 0; i < strPacket->Length; i++)
    {
        if (strPacket[i] >= '0' && strPacket[i] <= '9') continue;
        if (strPacket[i] >= 'A' && strPacket[i] <= 'F') continue;
        if (strPacket[i] == '*') continue;
 
        strError = "Invalid character detected in packet";
   
        return false;
    }
    return true;
}
bool SendPacketFunction(String^ strPacket, String^&strError){
    if(!isGoodPacket(strPacket, strError))
        return false;
 
    Random^ randObj = gcnew Random();
    String^ rawBytes = String::Empty;
 
    for(int i = 0; i < strPacket->Length; i++)
	{
        if(strPacket[i] == '*')	rawBytes += randObj->Next(16).ToString("X");
        else	rawBytes += strPacket[i];
    }
 
    ::DWORD dwOffset = 0;
    ::DWORD dwLength = ( rawBytes->Length / 2 );
    ::LPBYTE lpBytes = new ::BYTE [ dwLength ];
 
    for ( int i = 0; ( dwOffset < dwLength ) && ( ( i + 1 ) < rawBytes->Length ); dwOffset++, i += 2 )
        lpBytes[dwOffset] = Byte::Parse(rawBytes->Substring(i, 2), Globalization::NumberStyles::HexNumber, Globalization::CultureInfo::InvariantCulture);
 
    try
	{
		SendPacket(lpBytes, dwLength);
	} 
	catch ( Exception^ ){} 
	finally {delete [] lpBytes;}
    return true;
}
void NextChannel()
{
	String^ CCString = "3E 00 0* ** ** 5B 00 ";
    String^ strError = String::Empty;
	if(!SendPacketFunction(CCString->Replace(" ", ""),strError))
        MessageBox::Show(strError);
}
#pragma endregion

#pragma region Pointers Reading
	int getMobCount(){			return (int) ReadPointer(MobBasePtr, MobCountOffset);}
	int getItemCount(){			return (int) ReadPointer(ItemBasePtr, ItemCountOffset);}
	int getPeopleCount(){		return (int) ReadPointer(PeopleBasePtr, PeopleCountOffset);}
	int getCharX(){				return (int) ReadPointer(CharBasePtr,XOffset);}
	int getCharY(){				return (int) ReadPointer(CharBasePtr,XOffset + 4);}
	int getCharHP(){			WritePointer(SettingsBasePtr, HPAlertOffset, 20);return (int) ReadPointer(StatsBasePtr, HPOffset);}
	int getCharMP(){			WritePointer(SettingsBasePtr, MPAlertOffset, 20);return (int) ReadPointer(StatsBasePtr, MPOffset);}
	double getCharEXP(){		return ReadDoublePointer(StatsBasePtr, EXPOffset);}
	int getMapID(){				return (int) 0;}//ReadPointer(InfoBasePtr, MapIDOffset);}
	int getAttackCount(){		return (int) ReadPointer(CharBasePtr, AttackCountOffset);}
	int getTubiValue(){			return (int) ReadPointer(ServerBasePtr, TubiOffset);}
	int getBreathValue(){		return (int) ReadPointer(CharBasePtr, BreathOffset);}
#pragma endregion
#pragma region AutoHP/MP/Attack/Loot/Skill/CC/UnlimitedAttack Voids
void AutoHP()
{
	while(AutoHPBool)
	{
		if(getCharHP() < UserSetHP)
		{
			MapleHWND = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(UserSetHPKey, 0) << 16) + 1;
			UsingPot = true;
			Sleep(50);
			PostMessage(MapleHWND, WM_KEYDOWN, UserSetHPKey, lParam);
			Sleep(50);
			PostMessage(MapleHWND, WM_KEYUP, UserSetHPKey, lParam);
			UsingPot = false;
			Sleep(10);
		}
	}
}
void AutoMP()
{
	while(AutoMPBool)
	{
		if(getCharMP() < UserSetMP)
		{
			MapleHWND = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(UserSetMPKey, 0) << 16) + 1;
			UsingPot = true;
			Sleep(50);
			PostMessage(MapleHWND, WM_KEYDOWN, UserSetMPKey, lParam);
			Sleep(50);
			PostMessage(MapleHWND, WM_KEYUP, UserSetMPKey, lParam);
			UsingPot = false;
			Sleep(10);
		}
	}
}
void AutoLoot()
{
	while(AutoLootBool)
	{
		if(getItemCount() > 0 && !UsingPot && !UsingAutoSkill)
		{
			MapleHWND = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(UserSetLootKey, 0) << 16) + 1;
			if(PointerTubiBool)WritePointer(ServerBasePtr, TubiOffset, 0);
			PostMessage(MapleHWND, WM_KEYDOWN, UserSetLootKey, lParam);
			Sleep(50);
		}
		else(Sleep(500));
	}
}
void AutoAttack()
{
	while(AutoAttackBool)
	{
		if(getMobCount() > 0 && !UsingPot && !UsingAutoSkill && !CCing){
			MapleHWND = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(UserSetAttackKey, 0) << 16) + 1;
			PostMessage(MapleHWND, WM_KEYDOWN, UserSetAttackKey, lParam);
			Sleep(50);			
			PostMessage(MapleHWND, WM_KEYUP, UserSetAttackKey, lParam);
			Sleep(UserSetAttackDelay);
		}
		else(Sleep(500));
	}
}
void AutoSkill1()
{
	while(AutoSkill1Bool)
	{
		while(UsingAutoSkill) Sleep(1000);
		if(!CCing)
		{
			MapleHWND = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(UserSetSkill1Key, 0) << 16) + 1;
			UsingAutoSkill = true;
			Sleep(1000);
			PostMessage(MapleHWND, WM_KEYDOWN, UserSetSkill1Key, lParam);
			Sleep(50);			
			UsingAutoSkill = false;
			Sleep(UserSetSkill1Delay);
		}
	}
}
void AutoSkill2()
{
	while(AutoSkill2Bool)
	{
		while(UsingAutoSkill) Sleep(1000);
		if(!CCing)
		{
			MapleHWND = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(UserSetSkill2Key, 0) << 16) + 1;
			UsingAutoSkill = true;
			Sleep(1000);
			PostMessage(MapleHWND, WM_KEYDOWN, UserSetSkill2Key, lParam);
			Sleep(50);
			UsingAutoSkill = false;
			Sleep(UserSetSkill2Delay);
		}
	}
}
void AutoSkill3()
{
	while(AutoSkill3Bool)
	{
		if(!CCing)
		{
			while(UsingAutoSkill) Sleep(1000);
			MapleHWND = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(UserSetSkill3Key, 0) << 16) + 1;
			UsingAutoSkill = true;
			Sleep(1000);
			PostMessage(MapleHWND, WM_KEYDOWN, UserSetSkill3Key, lParam);
			Sleep(50);
			UsingAutoSkill = false;
			Sleep(UserSetSkill3Delay);
		}
	}
}
void AutoSkill4()
{
	while(AutoSkill4Bool)
	{
		
		if(!CCing)
		{
			while(UsingAutoSkill) Sleep(1000);
			MapleHWND = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(UserSetSkill4Key, 0) << 16) + 1;
			UsingAutoSkill = true;
			Sleep(1000);
			PostMessage(MapleHWND, WM_KEYDOWN, UserSetSkill4Key, lParam);
			Sleep(50);
			UsingAutoSkill = false;
			Sleep(UserSetSkill4Delay);
		}
	}
}
void CatchABreath()
{
	while(getBreathValue() > 0)
	{
		Sleep(100);
	}
}
void AutoCCPeople()
{
	while(CCPeopleBool)
	{
		if(getPeopleCount() >= CCPeopleInt)
		{
			CCing = true;
			while(getBreathValue() > 0)
				CatchABreath();
				Sleep(100);
			NextChannel();
			Sleep(500);
			CCing = false;
		}
	}
}
void AutoCCTimed()
{
	while(CCTimedBool)
	{
		Sleep(CCTimedInt * 1000);
		CCing = true;
		while(getBreathValue() > 0)
			CatchABreath();
		Sleep(100);
		NextChannel();
		Sleep(500);
		CCing = false;
	}
}
void AutoCCAttacks()
{
	while(CCAttacksBool)
	{
		if(getAttackCount() >= CCAttacksInt)
		{
			CCing = true;
			while(getBreathValue() > 0)
				CatchABreath();
				Sleep(100);
			NextChannel();
			Sleep(500);
			CCing = false;
		}
	}
}
#pragma endregion
#pragma region HackCheckBoxes
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
#pragma endregion
#pragma region AutoHP/MP/Attack/Loot/CC GuiEvents
void MainForm::HPCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->HPComboBox->Enabled = !this->HPCheckBox->Checked;
	this->HPTextBox->Enabled = !this->HPCheckBox->Checked;
	AutoHPBool = this->HPCheckBox->Checked;
	UserSetHPKey = KeyCodes[this->HPComboBox->SelectedIndex];
	if(this->HPTextBox->Text != "")UserSetHP = Convert::ToInt32(this->HPTextBox->Text);
	if(this->HPCheckBox->Checked) NewThread(AutoHP);		
}
void MainForm::MPCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{		
	this->MPComboBox->Enabled = !this->MPCheckBox->Checked;
	this->MPTextBox->Enabled = !this->MPCheckBox->Checked;
	AutoMPBool = this->MPCheckBox->Checked;
	UserSetMPKey = KeyCodes[this->MPComboBox->SelectedIndex];
	if(this->MPTextBox->Text != "")UserSetMP = Convert::ToInt32(this->MPTextBox->Text);
	if(this->MPCheckBox->Checked) NewThread(AutoMP);
}
void MainForm::AttackCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AttackComboBox->Enabled = !this->AttackCheckBox->Checked;
	this->AttackTrackBar->Enabled = !this->AttackCheckBox->Checked;
	this->AttackDelayLabel->Enabled = !this->AttackCheckBox->Checked;
	AutoAttackBool = this->AttackCheckBox->Checked;
	UserSetAttackKey = KeyCodes[this->AttackComboBox->SelectedIndex];
	UserSetAttackDelay = this->AttackTrackBar->Value;
	if(this->AttackCheckBox->Checked) NewThread(AutoAttack);
}
void MainForm::AutoLootCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoLootComboBox->Enabled = !this->AutoLootCheckBox->Checked;
	this->PointerTubiCheckBox->Enabled = !this->AutoLootCheckBox->Checked;
	AutoLootBool = this->AutoLootCheckBox->Checked;
	UserSetLootKey = KeyCodes[this->AutoLootComboBox->SelectedIndex];
	if(this->AutoLootCheckBox->Checked) NewThread(AutoLoot);
}
void MainForm::PointerTubiCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	PointerTubiBool = this->PointerTubiCheckBox->Checked;
}
void MainForm::AutoSkill1CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill1ComboBox->Enabled = !this->AutoSkill1CheckBox->Checked;
	this->AutoSkill1TextBox->Enabled = !this->AutoSkill1CheckBox->Checked;
	AutoSkill1Bool = this->AutoSkill1CheckBox->Checked;
	if(this->AutoSkill1CheckBox->Checked) NewThread(AutoSkill1);
	UserSetSkill1Key = KeyCodes[this->AutoSkill1ComboBox->SelectedIndex];
	if(this->AutoSkill1TextBox->Text != "")UserSetSkill1Delay = Convert::ToInt32(this->AutoSkill1TextBox->Text) * 1000;
}
void MainForm::AutoSkill2CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill2ComboBox->Enabled = !this->AutoSkill2CheckBox->Checked;
	this->AutoSkill2TextBox->Enabled = !this->AutoSkill2CheckBox->Checked;
	AutoSkill2Bool = this->AutoSkill2CheckBox->Checked;
	UserSetSkill2Key = KeyCodes[this->AutoSkill2ComboBox->SelectedIndex];
	if(this->AutoSkill2TextBox->Text != "")UserSetSkill2Delay = Convert::ToInt32(this->AutoSkill2TextBox->Text) * 1000;
	if(this->AutoSkill2CheckBox->Checked) NewThread(AutoSkill2);
}
void MainForm::AutoSkill3CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill3ComboBox->Enabled = !this->AutoSkill3CheckBox->Checked;
	this->AutoSkill3TextBox->Enabled = !this->AutoSkill3CheckBox->Checked;
	AutoSkill3Bool = this->AutoSkill3CheckBox->Checked;
	UserSetSkill3Key = KeyCodes[this->AutoSkill3ComboBox->SelectedIndex];
	if(this->AutoSkill3TextBox->Text != "")UserSetSkill3Delay = Convert::ToInt32(this->AutoSkill3TextBox->Text) * 1000;
	if(this->AutoSkill3CheckBox->Checked) NewThread(AutoSkill3);
}
void MainForm::AutoSkill4CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill4ComboBox->Enabled = !this->AutoSkill4CheckBox->Checked;
	this->AutoSkill4TextBox->Enabled = !this->AutoSkill4CheckBox->Checked;
	AutoSkill4Bool = this->AutoSkill4CheckBox->Checked;
	UserSetSkill4Key = KeyCodes[this->AutoSkill4ComboBox->SelectedIndex];
	if(this->AutoSkill4TextBox->Text != "")UserSetSkill4Delay = Convert::ToInt32(this->AutoSkill4TextBox->Text) * 1000;
	if(this->AutoSkill4CheckBox->Checked) NewThread(AutoSkill4);
}
void MainForm::CCPeopleCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->CCPeopleTextBox->Enabled = !this->CCPeopleCheckBox->Checked;
	this->CCPeopleLabel->Enabled = !this->CCPeopleCheckBox->Checked;
	if(this->CCPeopleTextBox->Text != "") CCPeopleInt = Convert::ToInt32(CCPeopleTextBox->Text);
	CCPeopleBool = this->CCPeopleCheckBox->Checked;
	NewThread(AutoCCPeople);
}
void MainForm::CCTimeCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->CCTimedTextBox->Enabled = !this->CCTimedCheckBox->Checked;
	this->CCTimedLabel->Enabled = !this->CCTimedCheckBox->Checked;
	if(this->CCTimedTextBox->Text != "") CCTimedInt = Convert::ToInt32(CCTimedTextBox->Text);
	CCTimedBool = this->CCTimedCheckBox->Checked;
	NewThread(AutoCCTimed);
}
void MainForm::CCAttacksCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->CCAttacksTextBox->Enabled = !this->CCAttacksCheckBox->Checked;
	this->CCAttacksLabel->Enabled = !this->CCAttacksCheckBox->Checked;
	if(this->CCAttacksTextBox->Text != "") CCAttacksInt = Convert::ToInt32(CCAttacksTextBox->Text);
	CCAttacksBool = this->CCAttacksCheckBox->Checked;
	NewThread(AutoCCAttacks);
}
#pragma endregion
void Main(void)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm);
	Application::Exit();
}
void MainForm::MainForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	//Initialize all Comboboxes and textboxes
	Globals::KeyNames = gcnew cli::array< System::Object^  >(46) {L"Shift", L"Space", L"Ctrl", L"Alt", L"Insert", L"Delete", L"Home", L"End", L"Page Up", L"Page Down", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9"};
	this->HPComboBox->Items->AddRange(Globals::KeyNames);
	this->MPComboBox->Items->AddRange(Globals::KeyNames);
    this->AttackComboBox->Items->AddRange(Globals::KeyNames);
	this->AutoLootComboBox->Items->AddRange(Globals::KeyNames);
	this->AutoSkill1ComboBox->Items->AddRange(Globals::KeyNames);
	this->AutoSkill2ComboBox->Items->AddRange(Globals::KeyNames);
	this->AutoSkill3ComboBox->Items->AddRange(Globals::KeyNames);
	this->AutoSkill4ComboBox->Items->AddRange(Globals::KeyNames);

	if(!Directory::Exists("WatyBot"))Directory::CreateDirectory("WatyBot");
	if(File::Exists(marshal_as<String^>(PacketFileName)))
		ReadPacketXML(PacketFileName);
	RefreshComboBoxes();
	if(File::Exists(marshal_as<String^>(SPControlFileName)))
		SPControl::ReadXML(SPControlFileName);
	RefreshSPControlListView();
	if(File::Exists(marshal_as<String^>(SettingsFileName)))
		LoadSettings();

}
void MainForm::StatsTimer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	this->MobCountLabel->Text =		"Mobs: "	+ getMobCount();
	this->PeopleCountLabel->Text =	"People: "	+ getPeopleCount();
	this->CharPosLabel->Text =		"CharPos: ("+ getCharX() +","+ getCharY()+")";
	this->ItemCountLabel->Text =	"Items: "	+ getItemCount();
	this->AttackCountLabel->Text =	"Attacks: " + getAttackCount();
	this->AttackDelayLabel->Text =	this->AttackTrackBar->Value + " ms";
	this->TubiPointerLabel->Text =	"Tubi: "	+getTubiValue();
	this->BreathLabel->Text =		"Breath: "	+ getBreathValue();
	
#pragma region HP/MP/EXP Bars Drawing
	if(getCharHP() >= MaxHP)	MaxHP = getCharHP();
	if(getCharMP() >= MaxMP)	MaxMP = getCharMP();
	
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
#pragma endregion
}
void MainForm::FixStatsButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	MaxHP = 0, MaxMP = 0;
}
void MainForm::MainTabControl_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	//MainForm::Height = TabHeight[MainTabControl->SelectedTab->TabIndex];
}
void MainForm::MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	SPControl::WriteXML(SPControlFileName);
	WritePacketXML(PacketFileName);
	SaveSettings();
	switch(MessageBoxA(NULL, "Close MapleStory too?", "Terminate Maple?", MB_ICONQUESTION | MB_YESNO))
	{
	case IDYES:
		{
			TerminateProcess(GetCurrentProcess(), 0);
			ExitProcess(0);
		}
		break;
	}
}

//Controls on the PacketSender tab
void MainForm::SendPacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ strError = String::Empty;
	if(PacketSelectBox->SelectedIndex < 0)	MessageBoxA(0,"Please select a packet before sending", 0, MB_OK | MB_ICONERROR);
	else if(!SendPacketFunction(marshal_as<String^>(vPacket.at(PacketSelectBox->SelectedIndex).data)->Replace(" ", ""),strError)) MessageBox::Show(strError);
}
void MainForm::AddPacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	AddPacket(marshal_as<string>(this->AddPacketNameTextBox->Text), marshal_as<string>(this->AddPacketPacketTextBox->Text));
	MessageBox::Show("Packet was added!");

	RefreshComboBoxes();
}
void MainForm::DeletePacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	//delete packet from vector
	switch (MessageBoxA(0, "Are you sure you want to delete this packet???", "Sure?", MB_ICONQUESTION | MB_YESNO))
		case IDYES:
	{
		DeletePacket(DeletePacketComboBox->SelectedIndex);
		MessageBox::Show("Packet was deleted succesfully!");
		RefreshComboBoxes();
		break;
	}	
}
void MainForm::SelectPacketForEditingComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(SelectPacketForEditingComboBox->SelectedIndex >= 0)
	{
		this->EditPacketNameTextBox->Text = marshal_as<String^>(vPacket.at(SelectPacketForEditingComboBox->SelectedIndex).name);
		this->EditPacketPacketTextBox->Text = marshal_as<String^>(vPacket.at(SelectPacketForEditingComboBox->SelectedIndex).data);
	}
}
void MainForm::SavePacketEditButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	EditPacket(SelectPacketForEditingComboBox->SelectedIndex, marshal_as<string>(EditPacketNameTextBox->Text), marshal_as<string>(EditPacketPacketTextBox->Text));

	RefreshComboBoxes();
}
void MainForm::SpamsPacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->SpamPacketsTimer->Interval = Convert::ToInt32(this->SpamPacketsDelayTextBox->Text);
	this->SendPacketGroupBox->Enabled = false;
	SpammedPackets = 0;
	this->SpamPacketsTimer->Enabled = true;
}
void MainForm::SpamPacketsTimer_Tick(System::Object^  sender, System::EventArgs^  e)
{	
	String^ strError = String::Empty;
	if(PacketSelectBox->SelectedIndex < 0)
	{
		this->SpamPacketsTimer->Enabled = false;
		MessageBoxA(0,"Please select a packet before sending", 0, MB_OK | MB_ICONERROR);
	}
	else if(!SendPacketFunction(marshal_as<String^>(vPacket.at(PacketSelectBox->SelectedIndex).data)->Replace(" ", ""),strError))
	{
		this->SpamPacketsTimer->Enabled = false;
		MessageBox::Show(strError);
	}

	SpammedPackets++;
	if(SpammedPackets >= Convert::ToInt32(this->SpamPacketTimesTextBox->Text))
	{
		this->SpamPacketsTimer->Enabled = false;
		MessageBox::Show("Finished Spamming packets!");
		this->SendPacketGroupBox->Enabled = true;
	}
}
void MainForm::SavePacketsButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	WritePacketXML(PacketFileName);
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
	for(unsigned int i=0; i < vPacket.size(); i++)
	{
		try
		{
			String^ PacketName = marshal_as<String^>(vPacket.at(i).name);
			this->PacketSelectBox->Items->Add(PacketName);
			this->SelectPacketForEditingComboBox->Items->Add(PacketName);
			this->DeletePacketComboBox->Items->Add(PacketName);
		}
		catch(...){};
	}
}

//controls on SPControl Tab
void MainForm::SPControlAddButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	SPControl::AddSPControl(marshal_as<string>(SPControlNameTextBox->Text), Convert::ToInt32(SPControlMapIDTextBox->Text), Convert::ToInt32(SPControlXTextBox->Text), Convert::ToInt32(SPControlYTextBox->Text));
	RefreshSPControlListView();
}
void MainForm::SPControlDeleteItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->SPControlListView->SelectedItems;
	ListViewItem^ L = this->SPControlListView->SelectedItems[0];
	if(SPControlListView->SelectedItems->Count > 0)
	{
		switch( MessageBoxA(NULL, "Are you sure you want to delete this???", "Are you sure?", MB_ICONQUESTION | MB_YESNO))
		case IDYES:
		{
			SPControlv.erase(SPControlv.begin() + SPControlListView->Items->IndexOf(L));
			RefreshSPControlListView();
			break;
		}
	}
}
void MainForm::GetSPControlCoordsButton_Click(System::Object^  sender, System::EventArgs^  e)
{
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
	for(unsigned int i = 0; i < SPControlv.size(); i++)
	{
		ListViewItem^ item = gcnew ListViewItem(marshal_as<String^>(SPControlv.at(i).mapName));
		item->SubItems->Add(Convert::ToString(SPControlv.at(i).mapID));
		item->SubItems->Add(Convert::ToString(SPControlv.at(i).x));
		item->SubItems->Add(Convert::ToString(SPControlv.at(i).y));
		SPControlListView->Items->Add(item);
	}
}

//Loading/Saving AutoBot settings
void MainForm::SaveSettings()
{
	File::Delete(marshal_as<String^>(SettingsFileName));
	ofstream file(SettingsFileName);
	using boost::property_tree::ptree;
	ptree pt;


	pt.add("AutoAttackDelay", this->AttackTrackBar->Value);
	pt.add("AutoAttackKey", this->AttackComboBox->SelectedIndex);

	pt.add("AutoLootKey", this->AutoLootComboBox->SelectedIndex);

	if(this->HPTextBox->Text != String::Empty)
		pt.add("AutoHPValue", Convert::ToInt32(this->HPTextBox->Text));
	pt.add("AutoHPKey", this->HPComboBox->SelectedIndex);
	if(this->MPTextBox->Text != String::Empty)
		pt.add("AutoMPValue", Convert::ToInt32(this->MPTextBox->Text));
	pt.add("AutoMPKey", this->MPComboBox->SelectedIndex);

	if(this->AutoSkill1TextBox->Text != String::Empty)
		pt.add("AutoSkill1Value", Convert::ToInt32(this->AutoSkill1TextBox->Text));
	pt.add("AutoSkill1Key", this->AutoSkill1ComboBox->SelectedIndex);
	if(this->AutoSkill2TextBox->Text != String::Empty)
		pt.add("AutoSkill2Value", Convert::ToInt32(this->AutoSkill2TextBox->Text));
	pt.add("AutoSkill2Key", this->AutoSkill2ComboBox->SelectedIndex);
	if(this->AutoSkill3TextBox->Text != String::Empty)
		pt.add("AutoSkill3Value", Convert::ToInt32(this->AutoSkill3TextBox->Text));
	pt.add("AutoSkill3Key", this->AutoSkill3ComboBox->SelectedIndex);
	if(this->AutoSkill4TextBox->Text != String::Empty)
		pt.add("AutoSkill4Value", Convert::ToInt32(this->AutoSkill4TextBox->Text));
	pt.add("AutoSkill4Key", this->AutoSkill4ComboBox->SelectedIndex);

	if(this->CCPeopleTextBox->Text != String::Empty)
		pt.add("AutoCCPeople", Convert::ToInt32(CCPeopleTextBox->Text));
	if(this->CCTimedTextBox->Text != String::Empty)
		pt.add("AutoCCTimed", Convert::ToInt32(CCTimedTextBox->Text));
	if(this->CCAttacksTextBox->Text != String::Empty)
		pt.add("AutoCCAttacks", Convert::ToInt32(CCAttacksTextBox->Text));

	write_ini(file, pt);

}
void MainForm::LoadSettings()
{
	ifstream file(SettingsFileName);
	using boost::property_tree::ptree;
	ptree pt;

	read_ini(file,pt);

	try
	{
		this->AttackTrackBar->Value = pt.get<int>("AutoAttackDelay");
		this->AttackComboBox->SelectedIndex = pt.get<int>("AutoAttackKey");
		this->AutoLootComboBox->SelectedIndex = pt.get<int>("AutoLootKey");
		this->HPTextBox->Text = marshal_as<String^>(pt.get<string>("AutoHPValue"));
		this->HPComboBox->SelectedIndex = pt.get<int>("AutoHPKey");
		this->MPTextBox->Text = marshal_as<String^>(pt.get<string>("AutoMPValue"));
		this->MPComboBox->SelectedIndex = pt.get<int>("AutoMPKey");
	}
	catch(...){}

	try
	{		
		this->AutoSkill1ComboBox->SelectedIndex = pt.get<int>("AutoSkill1Key");
		this->AutoSkill2ComboBox->SelectedIndex = pt.get<int>("AutoSkill2Key");
		this->AutoSkill3ComboBox->SelectedIndex = pt.get<int>("AutoSkill3Key");
		this->AutoSkill4ComboBox->SelectedIndex = pt.get<int>("AutoSkill4Key");
		this->AutoSkill1TextBox->Text = marshal_as<String^>(pt.get<string>("AutoSkill1Value"));
		this->AutoSkill2TextBox->Text = marshal_as<String^>(pt.get<string>("AutoSkill2Value"));
		this->AutoSkill3TextBox->Text = marshal_as<String^>(pt.get<string>("AutoSkill3Value"));
		this->AutoSkill4TextBox->Text = marshal_as<String^>(pt.get<string>("AutoSkill4Value"));
	}
	catch(...){}

	try
	{
		this->CCPeopleTextBox->Text = marshal_as<String^>(pt.get<string>("AutoCCPeople"));
		this->CCTimedTextBox->Text = marshal_as<String^>(pt.get<string>("AutoCCTimed"));
		this->CCAttacksTextBox->Text = marshal_as<String^>(pt.get<string>("AutoCCAttacks"));
	}
	catch(...){}
}
