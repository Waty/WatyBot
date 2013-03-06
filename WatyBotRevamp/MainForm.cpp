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

string WatyBotWorkingDirectory = "WatyBot\\";
string SettingsFileName = WatyBotWorkingDirectory + "settings.ini";
string PacketFileName = WatyBotWorkingDirectory + "packets.xml";
string SPControlFileName = WatyBotWorkingDirectory + "spcontrol.xml";

#pragma region Pointers Reading
	int getMobCount()
	{
		if(*(int*)WallBasePtr)	return (int) ReadPointer(MobBasePtr, MobCountOffset);
		else return 0;
	}
	int getItemCount()
	{
		if(*(int*)WallBasePtr)	return (int) ReadPointer(ItemBasePtr, ItemCountOffset);
		else return 0;
	}
	int getPeopleCount()
	{
		if(*(int*)WallBasePtr)	return (int) ReadPointer(PeopleBasePtr, PeopleCountOffset);
		else return 0;
	}
	int getCharX()
	{
		if(*(int*)WallBasePtr)	return (int) ReadPointer(CharBasePtr,XOffset);
		else return 0;
	}
	int getCharY()
	{
		if(*(int*)WallBasePtr)	return (int) ReadPointer(CharBasePtr,XOffset + 4);
		else return 0;
	}
	int getCharHP()
	{
		if(*(int*)WallBasePtr)
		{
			WritePointer(SettingsBasePtr, HPAlertOffset, 20);
			return (int) ReadPointer(StatsBasePtr, HPOffset);
		}
		else return 0;
	}
	int getCharMP()
	{
		if(*(int*)WallBasePtr)
		{
			WritePointer(SettingsBasePtr, MPAlertOffset, 20);
			return (int) ReadPointer(StatsBasePtr, MPOffset);
		}
		else return 0;
	}
	double getCharEXP()
	{
		if(*(int*)WallBasePtr)	return ReadDoublePointer(StatsBasePtr, EXPOffset);
		else return 0;
	}
	int getMapID()
	{
		if(*(int*)WallBasePtr)	return (int) ReadPointer(InfoBasePtr, MapIDOffset);
		else return 0;
	}
	int getAttackCount()
	{
		if(*(int*)WallBasePtr)	return (int) ReadPointer(CharBasePtr, AttackCountOffset);
		else return 0;
	}
	int getTubiValue()
	{
		if(*(int*)WallBasePtr)	return (int) ReadPointer(ServerBasePtr, TubiOffset);
		else return 0;
	}
	int getBreathValue()
	{
		if(*(int*)WallBasePtr)	return (int) ReadPointer(CharBasePtr, BreathOffset);
		else return 0;
	}
	int getChannel()
	{
		if(*(int*)WallBasePtr)	return (int) ReadPointer(ServerBasePtr, ChannelOffset);
		else return 0;
	}
	int getCharpID()
	{
		if(*(int*)WallBasePtr)	return (int) ReadPointer(CharBasePtr, pIDOffset);
		else return 0;
	}
#pragma endregion
	
bool InGame()
{
	if(getMapID() != 0)
		return true;

	else
		return false;
}
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
 
        strError = "Invalid character detected in packet" + strPacket[i];
   
        return false;
    }
    return true;
}
bool SendPacketFunction(String^ packet, String^&strError){	
	String^strPacket = packet->Replace(" ", "");

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
	int channel = getChannel() + 1;
	if(channel == 14) channel = 0;

	while(getChannel() != channel)
	{
		CCing = true;
		while(getBreathValue() > 0)	Sleep(250);
		Sleep(500);
		try 
		{
			if(WallBasePtr) CField_SendTransferChannelRequest(channel);
		}
		catch (...){}
		Sleep(1000);
	}
	Sleep(2000);
	CCing = false;
}

void MainForm::CashShop()
{
	CCing = true;
	while(getBreathValue() > 0)	Sleep(250);
	Sleep(500);
	String^ strError = String::Empty;
	if(SendPacketFunction(marshal_as<String^>(Packets::EnterCashShop), strError))
	{
		Sleep(2000);
		if(!SendPacketFunction(marshal_as<String^>(Packets::LeaveCashShop), strError))
			ShowError("Failed to leave the CashShop: " + strError);
	}
	else ShowError("Failed Entering the CashShop: " + strError);
	Sleep(250);

	CCing = false;
}

#pragma endregion

#pragma region Threads
void getMSHWND()
{
	while(MapleStoryHWND == NULL)
	{
		MapleStoryHWND = FindProcessWindow();
		Sleep(1500);
	}
}
void AutoSkill1()
{
	while(AutoSkill1Bool)
	{
		while(UsingAutoSkill) Sleep(1000);
		if(!CCing)
		{
			LPARAM lParam = (MapVirtualKey(UserSetSkill1Key, 0) << 16) + 1;
			UsingAutoSkill = true;
			Sleep(1000);
			PostMessage(MapleStoryHWND, WM_KEYDOWN, UserSetSkill1Key, lParam);
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
			LPARAM lParam = (MapVirtualKey(UserSetSkill2Key, 0) << 16) + 1;
			UsingAutoSkill = true;
			Sleep(1000);
			PostMessage(MapleStoryHWND, WM_KEYDOWN, UserSetSkill2Key, lParam);
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
			LPARAM lParam = (MapVirtualKey(UserSetSkill3Key, 0) << 16) + 1;
			UsingAutoSkill = true;
			Sleep(1000);
			PostMessage(MapleStoryHWND, WM_KEYDOWN, UserSetSkill3Key, lParam);
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
			LPARAM lParam = (MapVirtualKey(UserSetSkill4Key, 0) << 16) + 1;
			UsingAutoSkill = true;
			Sleep(1000);
			PostMessage(MapleStoryHWND, WM_KEYDOWN, UserSetSkill4Key, lParam);
			Sleep(50);
			UsingAutoSkill = false;
			Sleep(UserSetSkill4Delay);
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
	cbNFA->Enabled = !cbFMA->Checked;
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
#pragma endregion
#pragma region AutoHP/MP/Attack/Loot/CC GuiEvents
void MainForm::HPCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(HPCheckBox->Checked)
	{
		try
		{
			iHPKey = KeyCodes[HPComboBox->SelectedIndex];
			HPlParam = (MapVirtualKey(iHPKey, 0) << 16) + 1;
			iHPValue = Convert::ToInt32(nudHPValue->Value);
			nudHPValue->Enabled = false;
			HPComboBox->Enabled = false;
		}
		catch(Exception^ exception)
		{
			ShowError(exception->ToString());
			HPCheckBox->Checked = false;
			nudHPValue->Enabled = true;
			HPComboBox->Enabled = true;
		}
	}
	else
	{
		nudHPValue->Enabled = true;
		HPComboBox->Enabled = true;
	}

}
void MainForm::MPCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(MPCheckBox->Checked)
	{
		try
		{
			iMPKey = KeyCodes[MPComboBox->SelectedIndex];
			MPlParam = (MapVirtualKey(iMPKey, 0) << 16) + 1;
			iMPValue = Convert::ToInt32(nudMPValue->Value);
			nudMPValue->Enabled = false;
			MPComboBox->Enabled = false;
		}
		catch(Exception^ exception)
		{
			ShowError(exception->ToString());
			MPCheckBox->Checked = false;
			nudMPValue->Enabled = true;
			MPComboBox->Enabled = true;
		}
	}
	else
	{
		nudMPValue->Enabled = true;
		MPComboBox->Enabled = true;
	}
}
void MainForm::AttackCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	try
	{
		AutoBotVars::AttackKey = KeyCodes[AttackComboBox->SelectedIndex];
		AutoBotVars::AttacklParam = (MapVirtualKey(AutoBotVars::AttackKey, 0) << 16) + 1;

		this->AttackTimer->Interval = Convert::ToInt32(this->nudAttackDelay->Value);
		this->AttackComboBox->Enabled = !this->AttackCheckBox->Checked;
		this->nudAttackDelay->Enabled = !this->AttackCheckBox->Checked;
		this->nudSAWSIL->Enabled = !this->AttackCheckBox->Checked;
		this->AttackTimer->Enabled = this->AttackCheckBox->Checked;
	}
	catch(Exception^ ex)
	{
		ShowError("The following error occurred:\n " + ex->ToString());
	}
}
void MainForm::LootCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	try
	{
		AutoBotVars::LootKey = KeyCodes[LootComboBox->SelectedIndex];
		AutoBotVars::LootlParam = (MapVirtualKey(AutoBotVars::LootKey, 0) << 16) + 1;

		this->LootTimer->Interval = Convert::ToInt32(this->nudLootDelay->Value);
		this->LootComboBox->Enabled = !this->LootCheckBox->Checked;
		this->nudLootDelay->Enabled = !this->LootCheckBox->Checked;
		this->nudSLWIB->Enabled = !this->LootCheckBox->Checked;
		this->LootTimer->Enabled = this->LootCheckBox->Checked;
	}
	catch(Exception^ ex)
	{
		ShowError("Please Report the following error: " + ex->ToString());
	}
}
void MainForm::AttackTimer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	if(getMobCount() > Convert::ToInt32(nudSAWSIL->Value) && !UsingAutoSkill && !UsingPot && !CCing && InGame())
	{
		PostMessage(MapleStoryHWND, WM_KEYDOWN, AutoBotVars::AttackKey, AutoBotVars::AttacklParam);
		Sleep(50);
		PostMessage(MapleStoryHWND, WM_KEYUP, AutoBotVars::AttackKey, AutoBotVars::AttacklParam);
	}
}
void MainForm::LootTimer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	
	if(getItemCount() > Convert::ToInt32(nudSLWIB->Value) && !UsingAutoSkill && !UsingPot && !CCing && InGame())
	{
		WritePointer(ServerBasePtr, TubiOffset, 0);
		PostMessage(MapleStoryHWND, WM_KEYDOWN, AutoBotVars::LootKey, AutoBotVars::LootlParam);
	}
}
void MainForm::AutoSkill1CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill1ComboBox->Enabled = !this->AutoSkill1CheckBox->Checked;
	this->nudSkill1Value->Enabled = !this->AutoSkill1CheckBox->Checked;
	AutoSkill1Bool = this->AutoSkill1CheckBox->Checked;
	UserSetSkill1Key = KeyCodes[this->AutoSkill1ComboBox->SelectedIndex];
	UserSetSkill1Delay = Convert::ToInt32(this->nudSkill1Value->Value) * 1000;
	if(this->AutoSkill1CheckBox->Checked) NewThread(AutoSkill1);
}
void MainForm::AutoSkill2CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill2ComboBox->Enabled = !this->AutoSkill2CheckBox->Checked;
	this->nudSkill2Value->Enabled = !this->AutoSkill2CheckBox->Checked;
	AutoSkill2Bool = this->AutoSkill2CheckBox->Checked;
	UserSetSkill2Key = KeyCodes[this->AutoSkill2ComboBox->SelectedIndex];
	UserSetSkill2Delay = Convert::ToInt32(this->nudSkill2Value->Value) * 1000;
	if(this->AutoSkill2CheckBox->Checked) NewThread(AutoSkill2);
}
void MainForm::AutoSkill3CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill3ComboBox->Enabled = !this->AutoSkill3CheckBox->Checked;
	this->nudSkill3Value->Enabled = !this->AutoSkill3CheckBox->Checked;
	AutoSkill3Bool = this->AutoSkill3CheckBox->Checked;
	UserSetSkill3Key = KeyCodes[this->AutoSkill3ComboBox->SelectedIndex];
	UserSetSkill3Delay = Convert::ToInt32(this->nudSkill3Value->Value) * 1000;
	if(this->AutoSkill3CheckBox->Checked) NewThread(AutoSkill3);
}
void MainForm::AutoSkill4CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	this->AutoSkill4ComboBox->Enabled = !this->AutoSkill4CheckBox->Checked;
	this->nudSkill4Value->Enabled = !this->AutoSkill4CheckBox->Checked;
	AutoSkill4Bool = this->AutoSkill4CheckBox->Checked;
	UserSetSkill4Key = KeyCodes[this->AutoSkill4ComboBox->SelectedIndex];
	UserSetSkill4Delay = Convert::ToInt32(this->nudSkill4Value->Value) * 1000;
	if(this->AutoSkill4CheckBox->Checked) NewThread(AutoSkill4);
}
void MainForm::CCPeopleCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(CCPeopleCheckBox->Checked)
	{
		try
		{
			iCCPeople = Convert::ToInt32(nudCCPeople->Value);
			nudCCPeople->Enabled = false;
		}
		catch(...)
		{
			CCPeopleCheckBox->Checked = false;
			CCPeopleCheckBox->Enabled = true;
		}
	}
	else
	{
		nudCCPeople->Enabled = true;
	}
}
void MainForm::CCTimeCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(CCTimedCheckBox->Checked)
	{
		CCTimedTimer->Interval = Convert::ToInt32(nudCCTimed->Value * 1000);
		nudCCTimed->Enabled = false;
		CCTimedTimer->Enabled = true;
	}
	else
	{
		nudCCTimed->Enabled = true;
		CCTimedTimer->Enabled = false;
	}
}
void MainForm::CCTimedTimer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	String^ strError = String::Empty;
	switch(TimedComboBox->SelectedIndex)
	{
	case ID_CC:
		NewThread(NextChannel);
		break;

	case ID_CS:
		MainForm::CashShop();
		break;

	case ID_DC:
		CCTimedCheckBox->Checked = false;
		while(!SendPacketFunction(marshal_as<String^>(Packets::ChangeCharacter), strError));
		ShowInfo("DC'd because the time is over");
		break;
	}	
}
void MainForm::CCAttacksCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(CCAttacksCheckBox->Checked)
	{
		try
		{
			iCCAttacks = Convert::ToInt32(nudCCAttacks->Value);
			nudCCAttacks->Enabled = false;
		}
		catch(...)
		{
			CCAttacksCheckBox->Checked = false;
			CCAttacksCheckBox->Enabled = true;
		}
	}
	else
	{
		nudCCAttacks->Enabled = true;
	}
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
	//Get the hwnd of maplestory
	NewThread(getMSHWND);

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
	this->TubiPointerLabel->Text =	"Tubi: "	+ getTubiValue();
	this->BreathLabel->Text =		"Breath: "	+ getBreathValue();
	this->lMapID->Text =			"MapID: "	+ getMapID();
	this->lCharacterpID->Text =		"Char pID: "+ getCharpID();
	
	MainForm::AutoPot();
	MainForm::AutoCC();
	MainForm::RedrawStatBars();
	MainForm::HotKeys();
}
void MainForm::AutoPot()
{
	if(HPCheckBox->Checked)
	{
		if(getCharHP() <= iHPValue)
		{
			PostMessage(MapleStoryHWND, WM_KEYDOWN, iHPKey, HPlParam);
		}
	}
	if(MPCheckBox->Checked)
	{
		if(getCharMP() <= iMPValue)
		{
			PostMessage(MapleStoryHWND, WM_KEYDOWN, iMPKey, MPlParam);
		}
	}
}
void MainForm::AutoCC()
{
	if(CCPeopleCheckBox->Checked)
	{
		if(getPeopleCount() >= iCCPeople)
		{
			String^ strError = String::Empty;
			switch(PeopleComboBox->SelectedIndex)
			{
			case ID_CC:
				NewThread(NextChannel);
				break;

			case ID_CS:
				MainForm::CashShop();
				break;

			case ID_DC:
				CCTimedCheckBox->Checked = false;
				while(!SendPacketFunction(marshal_as<String^>(Packets::ChangeCharacter), strError));
				ShowInfo("DC'd because someone entered the map");
				break;
			}
		}
	}
	if(CCAttacksCheckBox->Checked)
	{
		if(getAttackCount() >= iCCAttacks)
		{
			String^ strError = String::Empty;
			switch(AttacksComboBox->SelectedIndex)
			{
			case ID_CC:
				NewThread(NextChannel);
				break;

			case ID_CS:
				MainForm::CashShop();
				break;

			case ID_DC:
				CCTimedCheckBox->Checked = false;
				while(!SendPacketFunction(marshal_as<String^>(Packets::ChangeCharacter), strError));
				ShowInfo("DC'd because you attacked " + iCCAttacks + " times");
				break;
			}
		}
	}
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
	//MainForm::Height = TabHeight[MainTabControl->SelectedTab->TabIndex];
}
void MainForm::MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	SPControl::WriteXML(SPControlFileName);
	WritePacketXML(PacketFileName);
	SaveSettings();

	::DialogResult dlResult = MessageBox::Show("Close MapleStory too?", "Terminate Maple?", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
	switch(dlResult)
	{
		case ::DialogResult::Yes:
			TerminateProcess(GetCurrentProcess(), 0);
			ExitProcess(0);
			break;
		
		case ::DialogResult::Cancel:
		{
			e->Cancel = true;
		}
	}
}

//Controls on the PacketSender tab
void MainForm::SendPacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ strError = String::Empty;
	if(PacketSelectBox->SelectedIndex < 0)	ShowError("Please select a packet before sending");
	else if(!SendPacketFunction(marshal_as<String^>(vPacket.at(PacketSelectBox->SelectedIndex).data),strError)) ShowError(strError);
}
void MainForm::AddPacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	AddPacket(marshal_as<string>(this->AddPacketNameTextBox->Text), marshal_as<string>(this->AddPacketPacketTextBox->Text));
	ShowInfo("Packet was added!");

	RefreshComboBoxes();
}
void MainForm::DeletePacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	//delete packet from vector
	switch(MessageBox::Show("Are you sure you want to delete this packet?", "Please Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question))
	{
	case ::DialogResult::Yes:
		DeletePacket(DeletePacketComboBox->SelectedIndex);
		ShowInfo("Packet was deleted succesfully!");
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
	if(SpamPacketsDelayTextBox->Text != String::Empty && SpamPacketTimesTextBox->Text != String::Empty && PacketSelectBox->SelectedIndex >-1)
	{
		this->SpamPacketsTimer->Interval = Convert::ToInt32(this->SpamPacketsDelayTextBox->Text);
		SpammedPackets = 0;
		this->SpamPacketsTimer->Enabled = true;
		this->bStopSpamming->Visible = true;
		this->bStartSpamming->Visible = false;
	}
}
void MainForm::bStopSpamming_Click(System::Object^  sender, System::EventArgs^  e)
{
	SpamPacketsTimer->Enabled = false;
	this->bStopSpamming->Visible = false;
	this->bStartSpamming->Visible = true;
}
void MainForm::SpamPacketsTimer_Tick(System::Object^  sender, System::EventArgs^  e)
{	
	String^ strError = String::Empty;
	if(PacketSelectBox->SelectedIndex < 0)
	{
		this->SpamPacketsTimer->Enabled = false;
		ShowWarning("Please select a packet before sending");
	}
	else if(!SendPacketFunction(marshal_as<String^>(vPacket.at(PacketSelectBox->SelectedIndex).data),strError))
	{
		this->SpamPacketsTimer->Enabled = false;
		ShowError(strError);
	}

	SpammedPackets++;
	if(SpammedPackets >= Convert::ToInt32(this->SpamPacketTimesTextBox->Text))
	{	
		SpamPacketsTimer->Enabled = false;
		this->bStopSpamming->Visible = false;
		this->bStartSpamming->Visible = true;
		ShowInfo("Finished Spamming packets!");	
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
void MainForm::cbSPControl_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	Hacks::cmSPControl.Enable(cbSPControl->Checked);
}
void MainForm::SPControlAddButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	string name = marshal_as<string>(SPControlNameTextBox->Text);
	int mapid = Convert::ToInt32(SPControlMapIDTextBox->Text);
	int x = Convert::ToInt32(SPControlXTextBox->Text);
	int y = Convert::ToInt32(SPControlYTextBox->Text);
	if(name == "" || !mapid || !x || !y)
		ShowWarning("You forgot to fill in a textbox...");
	else
	{
		SPControl::AddSPControl(name, mapid, x, y);
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
			SPControlv.erase(SPControlv.begin() + SPControlListView->Items->IndexOf(L));
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

	//Info Tab
	pt.add("AttackHotKey", this->ddbHotKeyAttack->SelectedIndex);
	pt.add("LootHotKey", this->ddbHotKeyLoot->SelectedIndex);
	pt.add("FMAHotKey", this->ddbHotKeyFMA->SelectedIndex);
	pt.add("CCPeopleHotKey", this->ddbHotKeyCCPeople->SelectedIndex);

	//Hacks Tab
	pt.add("PinTyper", this->cbPinTyper->Checked);
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

		//Info Tab
		this->ddbHotKeyAttack->SelectedIndex = pt.get<int>("AttackHotKey");
		this->ddbHotKeyLoot->SelectedIndex = pt.get<int>("LootHotKey");
		this->ddbHotKeyFMA->SelectedIndex = pt.get<int>("FMAHotKey");
		this->ddbHotKeyCCPeople->SelectedIndex = pt.get<int>("CCPeopleHotKey");

		//Hacks Tab
		this->cbPinTyper->Checked = pt.get<bool>("PinTyper", false);
	}catch(...){};
}
void MainForm::bSaveSettings_Click(System::Object^  sender, System::EventArgs^  e)
{
	MainForm::SaveSettings();
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
			String^ strError = String::Empty;
			if(PacketSelectBox->SelectedIndex < 0)	ShowError("Please select a packet before sending");
			else if(!SendPacketFunction(marshal_as<String^>(vPacket.at(PacketSelectBox->SelectedIndex).data),strError)) ShowError(strError);
			Sleep(250);
		}
	}
}
