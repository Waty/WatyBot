#pragma once
#include <Windows.h>
#include <vcclr.h>

#include "SPControl.h"
#include "MapleStory.h"
#include "Packet.h"
#include "ChangeChannel.h"
#include "Settings.h"
#include "AutoSkill.h"
#include "Memory.h"
#include "StopWatch.h"

#include "HackAddys.h"

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
#define AutoSkillFileName (WatyBotWorkingDirectory + "WatyBotAutoSkill.xml")
#define CMapleStoryFileName (WatyBotWorkingDirectory + "WatyBotCMapleStory.xml")

#define ShowInfo(Message)		MessageBox::Show(Message, "Information", MessageBoxButtons::OK, MessageBoxIcon::Information)
#define ShowError(Message)		MessageBox::Show(Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error)
#define ShowWarning(Message)	MessageBox::Show(Message, "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning)
#define ShowNotifyIcon(Message)	notifyIcon->ShowBalloonTip(1000, "WatyBot Error:", Message, ToolTipIcon::Error);

#define CodeCave(name) void __declspec(naked) Cave##name(){_asm
#define EndCodeCave }

extern StopWatch<milliseconds> SkillInjectionStopWatch;
extern StopWatch<milliseconds> BreathCounter;
extern gcroot<CChangeChannel^> CC;
extern gcroot<CSPControl^> SPControl;
extern gcroot<NotifyIcon^> notifyIcon;

extern int SkillInjectionSkills[];
extern int TabHeight[];
extern int KeyCodes[];
#define KeyCodesSize 58

extern enum SettingsIndex;
