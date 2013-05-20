#pragma once
#ifndef _DEFINES_H
#define _DEFINES_H
#include <Windows.h>

#include "SPControl.h"
#include "Packet.h"
#include "ChangeChannel.h"
#include "Settings.h"
#include "AutoSkill.h"
#include "Memory.h"

#include "Pointers.h"
#include "HackAddys.h"
#include "FunctionalMacro.h"
#include "BotMacro.h"

using namespace Packets;
using namespace SpawnControl;
using namespace ChangeChannel;
using namespace Settings;
using namespace System::IO;

#pragma warning(disable : 4793 4244 4793 4733)

#define WatyBotWorkingDirectory Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData) + "\\Waty\\"
#define SPControlFileName (WatyBotWorkingDirectory + "WatyBotSPControl.xml")
#define SettingsFileName (WatyBotWorkingDirectory + "WatyBotSettings.xml")
#define PacketFileName (WatyBotWorkingDirectory + "WatyBotPackets.xml")

#define ShowInfo(Message)		MessageBox::Show(Message, "Information", MessageBoxButtons::OK, MessageBoxIcon::Information)
#define ShowError(Message)		MessageBox::Show(Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error)
#define ShowWarning(Message)	MessageBox::Show(Message, "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning)

#define CodeCave(name) void __declspec(naked) Cave##name(){_asm
#define EndCodeCave }

//Macro's
extern Macro::MacroManager macroMan;
extern enum MacroIndex;

extern Macro::BotMacro* AttackMacro;
extern Macro::BotMacro* LootMacro;
extern Macro::FunctionalMacro* CCMacro;
extern StopWatch<milliseconds> SkillInjectionStopWatch;

extern gcroot<CMapleStory^> CMS;
extern gcroot<CChangeChannel^> CC;
extern gcroot<CPackets^> CPacket;
extern gcroot<CSPControl^> SPControl;
extern gcroot<NotifyIcon^> notifyIcon;

extern int SkillInjectionSkills[];
extern int TabHeight[];
extern int KeyCodes[];
#define KeyCodesSize 58

extern enum SettingsIndex;
#endif //_DEFINES_H
