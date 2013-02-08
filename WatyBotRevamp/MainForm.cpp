#pragma once
#pragma warning(disable : 4793 4244)
#include "MainForm.h"
#include "Memory.h"
#include <Windows.h>
#include "Defines.h"
#include "Pointers.h"
#include "SendPacket.h"
#include <msclr/marshal_cppstd.h>
#include "Packet.h"
#include "SPControl.h"
#include "Hacks.h"
using namespace std;
using namespace WatyBotRevamp;
using namespace msclr::interop;
using namespace System::IO;

//Fill the list of packets
string WatyBotWorkingDirectory = "WatyBot\\";
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
	int MobsCount(){		return (int) ReadPointer(MobBasePtr, MobCountOffset);}
	int ItemCount(){		return (int) ReadPointer(ItemBasePtr, ItemCountOffset);}
	int PeopleCount(){		return (int) ReadPointer(PeopleBasePtr, PeopleCountOffset);}
	int CharX(){			return (int) ReadPointer(CharBasePtr,XOffset);}
	int CharY(){			return (int) ReadPointer(CharBasePtr,XOffset + 4);}
	int CharHP(){			WritePointer(SettingsBasePtr, HPAlertOffset, 20);return (int) ReadPointer(StatsBasePtr, HPOffset);}
	int CharMP(){			WritePointer(SettingsBasePtr, MPAlertOffset, 20);return (int) ReadPointer(StatsBasePtr, MPOffset);}
	double CharEXP(){		return ReadDoublePointer(StatsBasePtr, EXPOffset);}
	int MapID(){			return (int) ReadPointer(InfoBasePtr, MapIDOffset);}
	int AttackCount(){		return (int) ReadPointer(CharBasePtr, AttackCountOffset);}
	int Tubi(){				return (int) ReadPointer(ServerBasePtr, TubiOffset);}
	int Breath(){			return (int) ReadPointer(CharBasePtr, BreathOffset);}
#pragma endregion
#pragma region AutoHP/MP/Attack/Loot/Skill/CC/UnlimitedAttack Voids
void AutoHP()
{
	while(AutoHPBool)
	{
		if(CharHP() < UserSetHP)
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
		if(CharMP() < UserSetMP)
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
		if(ItemCount() > 0 && !UsingPot && !UsingAutoSkill)
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
		if(MobsCount() > 0 && !UsingPot && !UsingAutoSkill && !CCing){
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
	while(Breath() > 0)
	{
		Sleep(100);
	}
}
void AutoCCPeople()
{
	while(CCPeopleBool)
	{
		if(PeopleCount() >= CCPeopleInt)
		{
			CCing = true;
			while(Breath() > 0)
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
		while(Breath() > 0)
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
		if(AttackCount() >= CCAttacksInt)
		{
			CCing = true;
			while(Breath() > 0)
				CatchABreath();
				Sleep(100);
			NextChannel();
			Sleep(500);
			CCing = false;
		}
	}
}
void UnlimitedAttack()
{
	while(UnlimitedAttackBool)
	{
		if(AttackCount() > 90)
		{
			MessageBoxA(0,"Bigger then 90",0,0);
			UsingPot = true;
			MapleHWND = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(VK_LEFT, 0) << 16) + 1;
			PostMessage(MapleHWND, WM_KEYDOWN, VK_LEFT, lParam);
			Sleep(100);			
			PostMessage(MapleHWND, WM_KEYUP, VK_LEFT, lParam);
			lParam = (MapVirtualKey(VK_RIGHT, 0) << 16) + 1;
			PostMessage(MapleHWND, WM_KEYDOWN, VK_RIGHT, lParam);
			Sleep(100);			
			PostMessage(MapleHWND, WM_KEYUP, VK_RIGHT, lParam);
			UsingPot = false;
		}
		Sleep(100);
	}
}
#pragma endregion
#pragma region HackCheckBoxes
void MainForm::FullMobDisarmCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	FullMobDisarm.Enable(this->FullMobDisarmCheckBox->Checked);
}
void MainForm::PinTyperCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	PinTyper.Enable(this->PinTyperCheckBox->Checked);
}
void MainForm::NoCharKBCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	NoCharKB.Enable(this->NoCharKBCheckBox->Checked);
}
void MainForm::JumpDownAnywhereCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	JDA.Enable(this->JumpDownAnywhereCheckBox->Checked);
}
void MainForm::FastMobsCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	FastMobs.Enable(this->FastMobsCheckBox->Checked);
}
void MainForm::PerfectLootCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	PerfectLoot.Enable(this->PerfectLootCheckBox->Checked);
}
void MainForm::NDAllAttacksCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	NDAllAttacks.Enable(this->NDAllAttacksCheckBox->Checked);
}
void MainForm::UnlimitedMorphCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	UnlimitedMorph.Enable(this->UnlimitedMorphCheckBox->Checked);
}
void MainForm::HideDamageCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	HideDamage.Enable(this->HideDamageCheckBox->Checked);
}
void MainForm::CPUHackCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	CPUHack.Enable(this->CPUHackCheckBox->Checked);
}
void MainForm::NoAttackLimitCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	UnlimitedAttackBool = NoAttackLimitCheckBox->Checked;
	NewThread(UnlimitedAttack);
	MessageBoxA(0,"Started", 0,0);
}
void MainForm::NDMiningCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	NDMining.Enable(this->NDMiningCheckBox->Checked);
}
void MainForm::UncensorCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Uncensor.Enable(this->UncensorCheckBox->Checked);
}
void MainForm::SevenMissCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Miss7GodMode.Enable(this->SevenMissCheckBox->Checked);
}
void MainForm::NoSkillMovementCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	NoSkillMovement.Enable(this->NoSkillMovementCheckBox->Checked);
}
void MainForm::NoSwearsCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	NoSwears.Enable(this->NoSwearsCheckBox->Checked);
}
void MainForm::VacRightCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	VacRight.Enable(this->VacRightCheckBox->Checked);
}
void MainForm::FusionAttackCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	FusionAttack.Enable(this->FusionAttackCheckBox->Checked);
}	
void MainForm::NoBackGroundCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	NoBackground.Enable(this->NoBackGroundCheckBox->Checked);
}
void MainForm::NoMobsCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	NoMobs.Enable(this->NoMobsCheckBox->Checked);
}
void MainForm::MobLagCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	MobLag.Enable(this->MobLagCheckBox->Checked);
}
void MainForm::InstantAirLootCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	InstantAirLoot.Enable(this->InstantAirLootCheckBox->Checked);
}
void MainForm::RainingMobsCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	RainingMobs.Enable(this->RainingMobsCheckBox->Checked);
}
void MainForm::NDMilleCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	NDMille.Enable(this->NDMilleCheckBox->Checked);
}
void MainForm::FLACCCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	FLACC.Enable(this->FLACCCheckBox->Checked);
}
void MainForm::FMACheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	FMA.Enable(this->FMACheckBox->Checked);
}
void MainForm::AutoAggroCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	FMA.Enable(this->AutoAggroCheckBox->Checked);
}
void MainForm::SPControlCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	SPControl.Enable(this->SPControlCheckBox->Checked);
	SPControlXCoord = CharX();
	SPControlYCoord = CharY();
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
	this->HPComboBox->SelectedIndex = 8;
	this->HPTextBox->Text = Convert::ToString(9000);
	this->MPComboBox->Items->AddRange(Globals::KeyNames);
	this->MPComboBox->SelectedIndex = 9;
	this->MPTextBox->Text = Convert::ToString(100);
    this->AttackComboBox->Items->AddRange(Globals::KeyNames);
	this->AttackComboBox->SelectedIndex = 2;
	this->AttackTrackBar->Value = 25;
	this->AutoLootComboBox->Items->AddRange(Globals::KeyNames);
	this->AutoLootComboBox->SelectedIndex = 35;
	this->AutoSkill1ComboBox->Items->AddRange(Globals::KeyNames);
	this->AutoSkill2ComboBox->Items->AddRange(Globals::KeyNames);
	this->AutoSkill3ComboBox->Items->AddRange(Globals::KeyNames);
	this->AutoSkill4ComboBox->Items->AddRange(Globals::KeyNames);

	if(File::Exists(marshal_as<String^>(PacketFileName))) ReadPacketXML(PacketFileName);
	RefreshComboBoxes();
	if(File::Exists(marshal_as<String^>(SPControlFileName))) ReadSPControlXML(SPControlFileName);
	RefreshSPControlListView();

}
void MainForm::StatsTimer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	this->MobCountLabel->Text =		"Mobs: "	+ MobsCount();
	this->PeopleCountLabel->Text =	"People: "	+ PeopleCount();
	this->CharPosLabel->Text =		"CharPos: ("+ CharX() +","+ CharY()+")";
	this->ItemCountLabel->Text =	"Items: "	+ ItemCount();
	this->AttackCountLabel->Text =	"Attacks: " + AttackCount();
	this->AttackDelayLabel->Text =	this->AttackTrackBar->Value + " ms";
	this->TubiPointerLabel->Text =	"Tubi: "	+Tubi();
	this->BreathLabel->Text =		"Breath: "	+ Breath();
	
#pragma region HP/MP/EXP Bars Drawing
	CharHP();
	if(CharHP() >= MaxHP)	MaxHP = CharHP();
	CharMP();
	if(CharMP() >= MaxMP)	MaxMP = CharMP();
	CharEXP();
	
	this->HPLabel->Text = "HP: " + CharHP() + "/" + MaxHP;
	this->MPLabel->Text = "MP: " + CharMP() + "/" + MaxMP;
	this->EXPLabel->Text = "EXP: " + CharEXP().ToString("f2") +"%";
	

	int lengtOfBars  = 223;

	double HPBarLength = ((double)CharHP()/(double)MaxHP) * lengtOfBars;
	this->HPForeground->Width = HPBarLength;
	double MPBarLength = ((double)CharMP()/(double)MaxMP) * lengtOfBars;
	this->MPForeground->Width = MPBarLength;
	double EXPBarLength = (CharEXP()/100) * lengtOfBars;
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
	WriteSPControlXML(SPControlFileName);
	WritePacketXML(PacketFileName);
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
	AddSPControl(marshal_as<string>(SPControlNameTextBox->Text), Convert::ToInt32(SPControlMapIDTextBox->Text), Convert::ToInt32(SPControlXTextBox->Text), Convert::ToInt32(SPControlYTextBox->Text));
	RefreshSPControlListView();
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