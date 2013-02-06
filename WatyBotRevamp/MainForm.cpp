#pragma once
#pragma warning(disable : 4793 4244)
#include "MainForm.h"
#include "Memory.h"
#include <Windows.h>
#include "Defines.h"
#include "Pointers.h"
#include "SendPacket.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <msclr/marshal_cppstd.h>
#include <boost/foreach.hpp>
#include "Packet.h"
using namespace std;
using namespace WatyBotRevamp;
using namespace msclr::interop;

CPacket* Packets = new CPacket();

#pragma region vars
public ref class Globals
{
public:
	static array <System::Object^> ^KeyNames;
};

int SpamTimes, SpamDelay;
#pragma endregion

#pragma region Packetsending stuff
bool isGoodPacket(String^ strPacket, String^&strError){
    if(strPacket == String::Empty){
        strError = "Packet is Empty";
        return false;
    }
 
    if((strPacket->Length)%2 == 1){
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
bool fSendPacket(String^ strPacket, String^&strError){
    if(!isGoodPacket(strPacket, strError))
        return false;
 
    Random^ randObj = gcnew Random();
    String^ rawBytes = String::Empty;
 
    for(int i = 0; i < strPacket->Length; i++){
        if(strPacket[i] == '*'){
            rawBytes += randObj->Next(16).ToString("X");
        }
        else
            rawBytes += strPacket[i];
    }
 
    //SRC ZPE
    using namespace System::Globalization;
 
    ::DWORD    dwOffset = 0;
    ::DWORD  dwLength = ( rawBytes->Length / 2 );
    ::LPBYTE lpBytes  = new ::BYTE [ dwLength ];
 
    for ( int i = 0; ( dwOffset < dwLength ) && ( ( i + 1 ) < rawBytes->Length ); dwOffset++, i += 2 )
        lpBytes[dwOffset] = Byte::Parse(rawBytes->Substring(i, 2), NumberStyles::HexNumber, CultureInfo::InvariantCulture);
 
    try {
        SendPacket(lpBytes, dwLength);
    } catch ( Exception^ ) {
    } finally {
        delete [] lpBytes;
    }
    return true;
}
void NextChannel()
{
	String^ CCString = "3E 00 0* ** ** 5B 00 ";
    String^ strError = String::Empty;
	if(!fSendPacket(CCString->Replace(" ", ""),strError))
        MessageBox::Show(strError);
}
#pragma endregion
#pragma region Hacks
////////////////////////////////////////////////////////////Jump Down Anywhere///////////////////////////////////////////////////////////////
BYTE bJDA1[] = {0xEB};
BYTE bJDA2[] = {0xEB};
BYTE bJDA3[] = {0x90, 0x90};
DWORD JDAAddy1 = 0x00B64C89;
DWORD JDAAddy2 = 0x00B64CC6;
DWORD JDAAddy3 = 0x00B64CE4;
CMemory JDA(JDAAddy1, bJDA1, 1, JDAAddy2, bJDA2, 1, JDAAddy3, bJDA3, 2);

////////////////////////////////////////////////////////////Fast Mobs////////////////////////////////////////////////////////////////////////
BYTE bFastMobs[] = {0x90, 0x90};
DWORD FastMobsAddy = 0x00714F43;																										
CMemory FastMobs(FastMobsAddy, bFastMobs, 2);																							
 
////////////////////////////////////////////////////////////Perfect Loot/////////////////////////////////////////////////////////////////////
BYTE bPerfectLoot1[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};																		
BYTE bPerfectLoot2[] = {0x25};																									
BYTE bPerfectLoot3[] = {0x81, 0xFE, 0x00, 0x00, 0x00, 0x00};																			
DWORD PerfectLootAddy1 = 0x004B42A7;																								
DWORD PerfectLootAddy2 = 0x005410C5;																								
DWORD PerfectLootAddy3 = 0x00443869;																								
CMemory PerfectLoot(PerfectLootAddy1, bPerfectLoot1, 6, PerfectLootAddy2, bPerfectLoot2, 1, PerfectLootAddy3, bPerfectLoot3, 6);	
 
////////////////////////////////////////////////////////////No Delay - All Attacks///////////////////////////////////////////////////////////
BYTE bNDAllAttacks[] = {0xB8, 0x01, 0x00, 0x00, 0x00, 0xC3, 0x90};																	
DWORD NDAllAttacksAddy = 0x00B35220;																								
CMemory NDAllAttacks(NDAllAttacksAddy, bNDAllAttacks, 7);																			
 
///////////////////////////////////////////////////////////Unlimited Morph Kaizer////////////////////////////////////////////////////////////
BYTE bUnlMorph1[] = {0xEB, 0x2E};																										
BYTE bUnlMorph2[] = {0xEB};																												
DWORD UnlMorphAddy1 = 0x00BC3172;																									
DWORD UnlMorphAddy2 = 0x00BC38F0;																									
CMemory UnlimitedMorph(UnlMorphAddy1, bUnlMorph1, 2, UnlMorphAddy2, bUnlMorph2, 1);													
 
///////////////////////////////////////////////////////////Hide Damage///////////////////////////////////////////////////////////////////////
BYTE bHideDamage[] = {0x7F};																											
DWORD HideDamageAddy = 0x006D9A77;																										
CMemory HideDamage(HideDamageAddy, bHideDamage, 1);																						
 
///////////////////////////////////////////////////////////CPU Hack//////////////////////////////////////////////////////////////////////////
BYTE bCPUHack[] = {0x90, 0x90, 0x90, 0x90, 0x90};																					
DWORD CPUHackAddy1 = 0x006AC1CB;																									
DWORD CPUHackAddy2 = 0x006AF52D;																									
DWORD CPUHackAddy3 = 0x006B3D59;																										
CMemory CPUHack(CPUHackAddy1, bCPUHack, 5, CPUHackAddy2, bCPUHack, 5, CPUHackAddy3, bCPUHack, 5);										
 
///////////////////////////////////////////////////////////Pin Typer/////////////////////////////////////////////////////////////////////////
BYTE bPinTyper[] = {0x0F, 0x84};																										
DWORD PinTyperAddy1 = 0x0068A956;																										
DWORD PinTyperAddy2 = 0x0068C027;																										
CMemory PinTyper(PinTyperAddy1, bPinTyper, 2, PinTyperAddy2, bPinTyper, 2);																
 
///////////////////////////////////////////////////////////No Char Knockback/////////////////////////////////////////////////////////////////
BYTE bNoCharKB[] = {0x00};																												
DWORD NoCharKBAddy = 0x0087BA5B;																									
CMemory NoCharKB(NoCharKBAddy, bNoCharKB, 1);																							
 
///////////////////////////////////////////////////////////Vac Right/////////////////////////////////////////////////////////////////////////
BYTE bVacRight[] = {0x75, 0x48};
DWORD VacRightAddy = 0x00C1A300;
CMemory VacRight(VacRightAddy, bVacRight, 2);

///////////////////////////////////////////////////////////Full Mob Disarm///////////////////////////////////////////////////////////////////
BYTE bFullMobDisarm[] = {0xE9, 0x9B, 0x02, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90};
DWORD FullMobDisarmAddy = 0x006FC332;
CMemory FullMobDisarm(FullMobDisarmAddy, bFullMobDisarm, sizeof(bFullMobDisarm));
 
///////////////////////////////////////////////////////////No Delay Minig////////////////////////////////////////////////////////////////////
DWORD NDMiningAddy1 = 0x00B687A2;
DWORD NDMiningAddy2 = 0x00B6887B;
DWORD NDMiningAddy3 = 0x00B77527;																									
BYTE bNDMining1[] = {0x90, 0x90};																									
BYTE bNDMining2[] = {0xEB};																												
BYTE bNDMining3[] = {0x90, 0x90};																									
CMemory NDMining(NDMiningAddy1, bNDMining1, 2, NDMiningAddy2, bNDMining2, 1, NDMiningAddy3, bNDMining3, 2);								

///////////////////////////////////////////////////////////Uncensored////////////////////////////////////////////////////////////////////////
DWORD UncensorAddy1 = 0x00443869;																										
DWORD UncensorAddy2 = 0x004FFB84;																										
BYTE bUncensor1[] = {0x75};																												
BYTE bUncensor2[] = {0x85};																												
CMemory Uncensor(UncensorAddy1, bUncensor1, 1, UncensorAddy2, bUncensor2, 1);															
///////////////////////////////////////////////////////////Uncensored////////////////////////////////////////////////////////////////////////
 
///////////////////////////////////////////////////////////No Skill Movement/////////////////////////////////////////////////////////////////
DWORD NoSkillMovementAddy1 = 0x00B5DD4F;																								
DWORD NoSkillMovementAddy2 = 0x0087BA5F;																								
BYTE bNoSkillMovement1[] = {0x00};																										
BYTE bNoSkillMovement2[] = {0xD8, 0xD2};																								
CMemory NoSkillMovement(NoSkillMovementAddy1, bNoSkillMovement1, 1, NoSkillMovementAddy2, bNoSkillMovement2, 2);						
 
///////////////////////////////////////////////////////////No Swear//////////////////////////////////////////////////////////////////////////
DWORD NoSwearsAddy = 0x0087888B;																										
BYTE bNoSwears[] = {0x90, 0x90};																										
CMemory NoSwears(NoSwearsAddy, bNoSwears, 2);																							
 
///////////////////////////////////////////////////////////No Background + Clouds////////////////////////////////////////////////////////////
DWORD NoBackgroundAddy1 = 0x006AF52D;
DWORD NoBackgroundAddy2 = 0x006ADE4B;
BYTE bNoBackground[] = {0x90, 0x90, 0x90, 0x90, 0x90};																					
CMemory NoBackground(NoBackgroundAddy1, bNoBackground, 5, NoBackgroundAddy2, bNoBackground, 5);											
 
///////////////////////////////////////////////////////////No Mobs///////////////////////////////////////////////////////////////////////////
DWORD NoMobsAddy = 0x00701EAD;																											
BYTE bNoMobs[] = {0xEB};																												
CMemory NoMobs(NoMobsAddy, bNoMobs, 1);																									
 
///////////////////////////////////////////////////////////Mob Lag///////////////////////////////////////////////////////////////////////////
DWORD MonLagAddy = 0x00701EFA;																											
BYTE bMobLag[] = {0xEB};																												
CMemory MobLag(NoMobsAddy, bNoMobs, 1);																									
 
///////////////////////////////////////////////////////////Instant air Loot//////////////////////////////////////////////////////////////////
DWORD InstantAirLootAddy = 0x005422B9;																									
BYTE bInstantAirLoot[] = {0x74};																										
CMemory InstantAirLoot(InstantAirLootAddy, bInstantAirLoot, 1);																			
 
///////////////////////////////////////////////////////////Raining Mobs//////////////////////////////////////////////////////////////////////
DWORD RainingMobsAddy = 0x00713576;																										
BYTE bRainingMobs[] = {0xD9, 0xC1};																										
CMemory RainingMobs(RainingMobsAddy, bRainingMobs, 2);																					
 
///////////////////////////////////////////////////////////Raining Mobs//////////////////////////////////////////////////////////////////////
DWORD NDMilleAddy = 0x00BB0AD5;																											
BYTE bNDMille[] = {0xEB};																												
CMemory NDMille(NDMilleAddy, bNDMille, 1);																								
 
///////////////////////////////////////////////////////////FLACC/////////////////////////////////////////////////////////////////////////////
DWORD FLACCAddy = 0x004747F9;																											
BYTE bFLACC[] = {0xB9, 0x07, 0x00, 0x00, 0x00, 0x90};																					
CMemory FLACC(FLACCAddy, bFLACC, sizeof(bFLACC));																						
 
///////////////////////////////////////////////////////////7 Miss////////////////////////////////////////////////////////////////////////////
int Miss7Counter = 0;																													
DWORD Miss7Addy = 0x00B9B365;																											
DWORD Miss7Return = Miss7Addy + 7;																										
DWORD Miss7ReturnNoKB = Miss7Return + 0x30;																								
CodeCave(SevenMiss)																														
   inc [Miss7Counter]																													
   cmp dword ptr [Miss7Counter],0x07																									
   jg Reset                            //jump if greater																				
   mov dword ptr [esp+0x00000118],00																									
   jmp dword ptr [Miss7ReturnNoKB]																										
																																		
   Reset:																																
   mov [Miss7Counter],00																												
   mov esi,[esp+0x0000011C]																												
   jmp dword ptr [Miss7Return]																											
EndCodeCave																																
CMemory Miss7GodMode(Miss7Addy, CaveSevenMiss, 2, true);																				
 
///////////////////////////////////////////////////////////Fusion Attack/////////////////////////////////////////////////////////////////////
DWORD FusionAttackAddy = 0x006FFBB2;																									
DWORD FusionAttackReturn = FusionAttackAddy + 8;																						
CodeCave(FusionAttack)																													
Hook:																																	
mov dword ptr [ecx+eax*4],esi																											
inc eax																																	
cmp eax,[esp+0x64]																														
jl Hook																																	
mov [esp+0x18],eax																														
jmp [FusionAttackReturn]																												
EndCodeCave																																
CMemory FusionAttack(FusionAttackAddy, CaveFusionAttack, 3, true);																		
 
///////////////////////////////////////////////////////////FMA///////////////////////////////////////////////////////////////////////////////
DWORD FMAAddy = 0x006FFBA2;																												
BYTE bFMA[] = {0x74};																													
CMemory FMA(FMAAddy, bFMA, 1);																											
 
///////////////////////////////////////////////////////////Auto Aggro////////////////////////////////////////////////////////////////////////
DWORD AutoAggroAddy = 0x00C2761f;
DWORD AutoAggroRet = AutoAggroAddy + 5;
DWORD AutoAggroCal = 0x00c1e110;
CodeCave(AutoAggro)
	call AutoAggroCal
	mov edx,[0x011ADD04]
	mov edx,[edx+0x29D0]
	mov edx,[edx+0x0C]
	mov [esi+0x2B0],edx
	jmp AutoAggroRet																													
EndCodeCave
CMemory AutoAggro(AutoAggroAddy, CaveAutoAggro, 0, true);

///////////////////////////////////////////////////////////Spawn Control/////////////////////////////////////////////////////////////////////
DWORD SPControlAddy = 0x00B8420A;
DWORD SPControlRet = SPControlAddy + 6;
DWORD spawn_x = 0x0;
DWORD spawn_y = 0x0;
CodeCave(SPControl)
	mov ebx, [spawn_x]
	mov ebp, [spawn_y]
	jmp dword ptr SPControlRet
EndCodeCave
CMemory SPControl(SPControlAddy, CaveSPControl, 1, true);

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
	spawn_x = CharX();
	spawn_y = CharY();
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

	if(!IO::File::Exists("WatyBotConfig\\Packets.xml"))	IO::Directory::CreateDirectory("C:\\WatyBot");

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

#pragma region Create Packets
	for(unsigned int i=0; i < Packets->Packetv.size(); i++)
	{
		try
		{
			String^ PacketName = marshal_as<String^>(Packets->Packetv.at(i).Name);
			this->PacketSelectBox->Items->Add(PacketName);
			this->SelectPacketForEditingComboBox->Items->Add(PacketName);
			this->DeletePacketComboBox->Items->Add(PacketName);
		}
		catch(...){};
	}
#pragma endregion

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
#pragma region PacketSender
void MainForm::SendPacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ strError = String::Empty;
	if(PacketSelectBox->SelectedIndex < 0)	MessageBoxA(0,"Please select a packet before sending", 0, MB_OK | MB_ICONERROR);
	else if(!fSendPacket(marshal_as<String^>(Packets->Packetv.at(PacketSelectBox->SelectedIndex).Data)->Replace(" ", ""),strError)) MessageBox::Show(strError);
}
void MainForm::AddPacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	packetStruct p;
	p.Name = marshal_as<string>(this->AddPacketNameTextBox->Text);
	p.Data = marshal_as<string>(this->AddPacketPacketTextBox->Text);
	Packets->Packetv.push_back(p);
	MessageBox::Show("Packet was added succesfully!");

	//clear old packets
	this->AddPacketNameTextBox->Text = String::Empty;
	this->AddPacketPacketTextBox->Text = String::Empty;
	this->PacketSelectBox->Items->Clear();
	this->SelectPacketForEditingComboBox->Items->Clear();
	this->DeletePacketComboBox->Items->Clear();

	//refresh comboboxes
	for(unsigned int i=0; i < Packets->Packetv.size(); i++)
	{
		try
		{
			String^ PacketName = marshal_as<String^>(Packets->Packetv.at(i).Name);
			this->PacketSelectBox->Items->Add(PacketName);
			this->SelectPacketForEditingComboBox->Items->Add(PacketName);
			this->DeletePacketComboBox->Items->Add(PacketName);
		}
		catch(...){};
	}
}
void MainForm::DeletePacketButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	//delete packet from vector
	Packets->Packetv.erase(Packets->Packetv.begin() + DeletePacketComboBox->SelectedIndex);
	MessageBox::Show("Packet was deleted succesfully!");
	
	//clear old packets
	this->PacketSelectBox->Items->Clear();
	this->SelectPacketForEditingComboBox->Items->Clear();
	this->DeletePacketComboBox->Items->Clear();

	//refresh comboboxes
	for(unsigned int i=0; i < Packets->Packetv.size(); i++)
	{
		try
		{
			String^ PacketName = marshal_as<String^>(Packets->Packetv.at(i).Name);
			this->PacketSelectBox->Items->Add(PacketName);
			this->SelectPacketForEditingComboBox->Items->Add(PacketName);
			this->DeletePacketComboBox->Items->Add(PacketName);
		}
		catch(...){};
	}
}
void MainForm::SelectPacketForEditingComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	if(SelectPacketForEditingComboBox->SelectedIndex >= 0)
	{
		this->EditPacketNameTextBox->Text = marshal_as<String^>(Packets->Packetv.at(SelectPacketForEditingComboBox->SelectedIndex).Name);
		this->EditPacketPacketTextBox->Text = marshal_as<String^>(Packets->Packetv.at(SelectPacketForEditingComboBox->SelectedIndex).Data);
	}
}
void MainForm::SavePacketEditButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	Packets->Packetv.at(SelectPacketForEditingComboBox->SelectedIndex).Name = marshal_as<string>(EditPacketNameTextBox->Text);
	Packets->Packetv.at(SelectPacketForEditingComboBox->SelectedIndex).Data = marshal_as<string>(EditPacketPacketTextBox->Text);

	//clear old packets
	this->EditPacketNameTextBox->Text = String::Empty;
	this->EditPacketPacketTextBox->Text = String::Empty;
	this->PacketSelectBox->Items->Clear();
	this->SelectPacketForEditingComboBox->Items->Clear();
	this->DeletePacketComboBox->Items->Clear();

	//refresh comboboxes
	for(unsigned int i=0; i < Packets->Packetv.size(); i++)
	{
		try
		{
			String^ PacketName = marshal_as<String^>(Packets->Packetv.at(i).Name);
			this->PacketSelectBox->Items->Add(PacketName);
			this->SelectPacketForEditingComboBox->Items->Add(PacketName);
			this->DeletePacketComboBox->Items->Add(PacketName);
		}
		catch(...){};
	}
}
int SpammedPackets;
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
	else if(!fSendPacket(marshal_as<String^>(Packets->Packetv.at(PacketSelectBox->SelectedIndex).Data)->Replace(" ", ""),strError))
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

#pragma endregion