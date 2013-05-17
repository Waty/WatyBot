#pragma once
#ifndef _DEFINES_H
#define _DEFINES_H
#include <Windows.h>
#include "SPControl.h"
#include "Pointers.h"
#include "HackAddys.h"
#include "FunctionalMacro.h"
#include "BotMacro.h"
#include "SkillMacro.h"

using namespace Packets;
using namespace SpawnControl;
using namespace ChangeChannel;

#define WatyBotWorkingDirectory Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData) + "\\Waty\\"
#define SettingsFileName (WatyBotWorkingDirectory + "WatyBotSettings.xml")

#define ShowInfo(Message)		MessageBox::Show(Message, "Information", MessageBoxButtons::OK, MessageBoxIcon::Information)
#define ShowError(Message)		MessageBox::Show(Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error)
#define ShowWarning(Message)	MessageBox::Show(Message, "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning)

#define CodeCave(name) void __declspec(naked) Cave##name(){_asm
#define EndCodeCave }

//Macro's
Macro::MacroManager macroMan;
enum MacroIndex{eAttack, eLoot, eCC, eAutoSkill1, eAutoSkill2, eAutoSkill3, eAutoSkill4};

Macro::BotMacro* AttackMacro;
Macro::BotMacro* LootMacro;
Macro::FunctionalMacro* CCMacro;
Macro::SkillMacro* Skill1Macro;
Macro::SkillMacro* Skill2Macro;
Macro::SkillMacro* Skill3Macro;
Macro::SkillMacro* Skill4Macro;
StopWatch<milliseconds> SkillInjectionStopWatch;

gcroot<CMapleStory^> CMS;
gcroot<CChangeChannel^> CC;
gcroot<CPackets^> CPacket;
gcroot<CSPControl^> SPControl;

static int SkillInjectionSkills[] = {97, 99, 100, 103, 61001005, 4001334, 4201005, 4211011, 4221001, 1001004, 1221009, 1311005, 2201004, 2211003};
static int TabHeight[] = {431, 461, 386, 431, 266};
static int KeyCodes[] = {VK_SHIFT, VK_SPACE, VK_CONTROL, VK_MENU, VK_INSERT, VK_DELETE, VK_HOME, VK_END, VK_PRIOR, VK_NEXT, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6, VK_F7, VK_F8, VK_F9, VK_F10, VK_F11, VK_F12};
#define KeyCodesSize 58
enum SettingsIndex{
	AutoAttackDelay, SAWSIL, AutoAttackKey, AutoLootDelay, SLWIB, AutoLootKey, AutoHPValue, AutoHPKey, AutoMPValue, AutoMPKey, AutoSkill1, AutoSkill1Key, AutoSkill2, AutoSkill2Key,
	AutoSkill3, AutoSkill3Key, AutoSkill4, AutoSkill4Key, CCPeople, CCPeopleType, CCTimed, CCTimedType, CCAttacks, CCAttacksType, HotKeyAttack, HotKeyLoot, HotKeyFMA,
	HotKeyCCPeople, HotKeySendPacket, SelectedPacket, PacketSpamAmount, PacketSpamDelay, SkillInjectionDelay, SkillInjectionIndex, IceGuard, PinTyper, LogoSkipper, SettingCount
};
#endif //_DEFINES_H
