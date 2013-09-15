#include "Hacks.h"
#include "HackAddys.h"
#include "MapleStory.h"
#include "SPControl.h"
#include "StopWatch.h"
#include "Log.h"

using namespace WatyBotRevamp;

extern bool Teleport(int x, int y);

#define CodeCave(name) void __declspec(naked) Cave##name(){_asm
#define EndCodeCave }

/////Dojang Godmode
DWORD DojangRet = DojangAddy + 5;
DWORD dwDojangCall = DojangCall;
int DojangMissCount = 0;
CodeCave(Dojang)
{
	inc[DojangMissCount]
	cmp[DojangMissCount], 07 //amount of misses as its under 10 no need for a 0x
	jbe DojangExit
	mov[DojangMissCount], 00
	call dword ptr[dwDojangCall]

DojangExit:
	jmp[DojangRet]
}
EndCodeCave
Hack Hacks::DojangGodmode = { new CMemory(DojangAddy, CaveDojang) };

/////Ice GuardGM
DWORD IceGuardRet = IceGuardAddy + 7;
DWORD dwIceGuardPush = IceGuardPush;
int iIceGuardCounter = 0, iIceGuardLimit;
CodeCave(IceGuard)
{
	pushad
		mov eax, iIceGuardLimit
		cmp[iIceGuardCounter], eax
	popad
	jle blockDMG

	mov[iIceGuardCounter], 0
	push 0xFF
	push dwIceGuardPush
	jmp IceGuardRet

blockDMG :
	add[iIceGuardCounter], 1
	ret 0x002C
}
EndCodeCave
Hack Hacks::IceGuard = { new CMemory(IceGuardAddy, CaveIceGuard, 2) };

void Hacks::SetIceGuardLimit(int limit)
{
	iIceGuardLimit = limit;
}

/////Auto Aggro
DWORD dwAggroRet = AggroAddy + 5;
DWORD dwAggroCall = AggroCall;
CodeCave(Aggro)
{
	call dwAggroCall
	mov edx, dword ptr ds : [CharBasePtr]
	mov edx, [edx + 0x0C]
	mov edx, [edx + 0x0C]
	mov[esi + 0x2B0], edx
	jmp dwAggroRet
}
EndCodeCave
Hack Hacks::AutoAggro = { new CMemory(AggroAddy, CaveAggro) };

/////Pin Typer
BYTE bPinTyper [] = { 0x0F, 0x84 };
//Pic Typer
BYTE bPicTyper1 [] = { 0x90, 0xE9 }; //Makes the je a jmp
BYTE bPicTyper2 [] = { 0xC7, 0x45, 0x88, 0x00 };
Hack Hacks::PinPicTyper = {
	new CMemory(PinTyperAddy1, bPinTyper, 2),
	new CMemory(PinTyperAddy2, bPinTyper, 2),
	new CMemory(PicTyperAddy1, bPicTyper1, 2),
	new CMemory(PicTyperAddy2, bPicTyper2, 4),
	new CMemory(PicTyperAddy3, (void*) PicTyperCall, 0, CMemory::ASM::Call)
};

/////FusionAttack
DWORD dwFusionRet = FusionAddy + 8;
CodeCave(FusionAttack)
{
Hook:
	mov[ecx + eax * 4], esi
	inc eax
	cmp eax, [esp + 0x64]
	jl Hook
	mov[esp + 0x18], eax
	jmp dwFusionRet
}
EndCodeCave
Hack Hacks::FusionAttack = { new CMemory(FusionAddy, CaveFusionAttack, 3) };

/////Perfect Loot
BYTE bPerfectLoot2 [] = { 0x25 };
BYTE bPerfectLoot3 [] = { 0x81, 0xFE, 0x00, 0x00, 0x00, 0x00 };
Hack Hacks::PerfectLoot = {
	new CMemory(PerfectLootAddy1, 6),
	new CMemory(PerfectLootAddy2, bPerfectLoot2, sizeof(bPerfectLoot2)),
	new CMemory(PerfectLootAddy3, bPerfectLoot3, sizeof(bPerfectLoot3)),
	new CMemory(AirLootAddy, 2)
};

/////No Background + Clouds
Hack Hacks::NoBackground = {
	new CMemory(NoBGAddy1, 5),
	new CMemory(NoBGAddy2, 5)
};

/////Faster Mobs
Hack Hacks::FasterMobs = { new CMemory(FasterMobsAddy, 2) };

/////Unlimited Morp
BYTE bMorph1 [] = { 0xEB, 0x2E };
BYTE bMorph2 [] = { 0xEB };
Hack Hacks::UnlimitedMorph = {
	new CMemory(UnlimitedMorphAddy1, bMorph1, 2),
	new CMemory(UnlimitedMorphAddy2, bMorph2, 1)
};

/////ND - All Attacks
BYTE bgND1 [] = { 0x74 };
BYTE bgND2 [] = { 0x00 };
Hack Hacks::NDAllAttacks = {
	new CMemory(gNDAddy1, bgND1, 1),
	new CMemory(gNDAddy2, bgND2, 1)
};

/////Jump Down Anywhere
BYTE bJDA [] = { 0xEB };
Hack Hacks::JDA = {
	new CMemory(JDAAddy1, bJDA, 1),
	new CMemory(JDAAddy2, bJDA, 1),
	new CMemory(JDAAddy3, 2)
};

/////Full Mob Disarm
BYTE bDisarm [] = { 0xE9, 0x24, 0x04, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90 }; //jmp 00772493 + 4 nops
Hack Hacks::MobDisarm = { new CMemory(MobDisarmAddy, bDisarm, sizeof(bDisarm)) };

/////No Mobs
BYTE bNoMobs [] = { 0xEB };
Hack Hacks::NoMobs = { new CMemory(NoMobsAddy, bNoMobs, 1) };

/////Vac Right
BYTE bVacRight [] = { 0x75, 0x48 };
Hack Hacks::VacRight = { new CMemory(VacRightAddy, bVacRight, 2) };

/////Walk Unrandom Right
Hack Hacks::WalkRight = { new CMemory(WalkRightAddy, (void*)(WalkRightAddy + 154), 1) };

/////Jump Unrandom Right
BYTE bJumpRight [] = { 0xE9, 0x7A, 0x02, 0x00, 0x00, 0x90 };
Hack Hacks::JumpRight = { new CMemory(JumpRightAddy, bJumpRight, 6) };

/////NoKB
BYTE bNoKB [] = { 0x00 };
Hack Hacks::NoKB = { new CMemory(NoKBAddy, bNoKB, 1) };

/////Sit Hack
BYTE bSit [] = { 0x75 };
Hack Hacks::SitHack = { new CMemory(SitHackAddy, bSit, 1) };

/////50 Seconds Godmode
BYTE bSecondGodmode1 [] = { 0x7E };
BYTE bSecondGodmode2 [] = { 0xD4, 0x36 };
Hack Hacks::SecondGodmode = {
	new CMemory(Godmode50SecAddy1, bSecondGodmode1, 1),
	new CMemory(Godmode50SecAddy2, bSecondGodmode2, 2)
};

/////Logo Skipper
BYTE bLogoSkipper [] = { 0x50, 0x42 };
Hack Hacks::LogoSkipper = { new CMemory(LogoSkipperAddy, bLogoSkipper, 2) };

/////(semi) Item Vac
DWORD dwItemVacCall = ItemVacCall;
int itemvac_x = 0;
int itemvac_y = 0;
bool itemvaclock = false;
VOID WINAPI getItemVacCoords()
{
	if (itemvaclock) return;

	itemvac_x = CMS::CharX;
	itemvac_y = CMS::CharY;
}
CodeCave(ItemVac)
{
	call dwItemVacCall //Original Opcode
	call getItemVacCoords
	mov ecx, eax
	mov eax, [esp + 0x0C]
	mov edi, [itemvac_x]
	mov[eax], edi //X
	pop edi
	mov esi, [itemvac_y]
	mov[eax + 04], esi //Y
	pop esi
	ret 0004
}
EndCodeCave
Hack Hacks::ItemVac = { new CMemory(ItemVacAddy, CaveItemVac) };
void Hacks::LockItemVac(bool state)
{
	if (state) getItemVacCoords();
	itemvaclock = state;
}

/////View Swears
Hack Hacks::NoSwears = { new CMemory(ViewSwearsAddy, 2) };

/////FMA
BYTE bFMA [] = { 0xEB };
Hack Hacks::FMA = { new CMemory(FMAAddy, bFMA, 1) };

/////Ghoul's Scare Mob Lagg
BYTE bScareMobs [] = { 0x75 };
Hack Hacks::ScareMobs = { new CMemory(ScareMobsAddy, bScareMobs, 1) };

/////Always Face Left
BYTE bFaceLeftAfterCC [] = { 0xB8, 0x05, 0x00, 0x00, 0x00, 0x90 };
Hack Hacks::FaceLeftAfterCC = { new CMemory(FLACC, bFaceLeftAfterCC, 6) };

/////CPU Hack
Hack Hacks::CPUHack = {
	new CMemory(CPUAddy1, 5)/*,
	new CMemory(CPUAddy2, 5),
	new CMemory(CPUAddy3, 5)*/
};

/////Unlimited Attack
DWORD dwUARet = UAAddy + 6;
BOOL WINAPI UA()
{
	if (CMS::AttackCount > 90) return TRUE;
	return FALSE;
}
CodeCave(UA)
{
	mov[eax], edi //orig code
	pushad
		call UA
		cmp eax, TRUE // Attack Count offset
	popad
	jne UAexit
	add dword ptr[eax], 0x08

	UAexit:
	pop edi
	mov[eax + 0x04], ecx
	jmp dwUARet
}
EndCodeCave
Hack Hacks::UnlimitedAttack = { new CMemory(UAAddy, CaveUA, 1) };

/////Disable Final Attack Luna
Hack Hacks::DisableFinalAttack = { new CMemory(DFAAddy, 7) };

/////ND Mining
BYTE bNDMining [] = { 0xEB };
Hack Hacks::NDMining = {
	new CMemory(NDMiningAddy1, 2),
	new CMemory(NDMiningAddy2, bNDMining, 1),
	new CMemory(NDMiningAddy3, 2)
};

/////Hide Damage
BYTE bHideDamage1 [] = { 0x00 };
BYTE bHideDamage2 [] = { 0x90, 0xE9 };
BYTE bHideDamage3 [] = { 0xEB };
Hack Hacks::HideDamage = {
	new  CMemory(HideDamageAddy1, bHideDamage1, 1),
	new  CMemory(HideDamageAddy2, bHideDamage2, 2),
	new  CMemory(HideDamageAddy3, bHideDamage3, 1),
	new  CMemory(HideDamageAddy4, bHideDamage3, 1),
	new  CMemory(HideDamageAddy5, bHideDamage3, 1)
};

/////Mercedes Combos without comboing
BYTE bMercedesCombo [] = { 0xEB };
Hack Hacks::MercedesCombo = {
	new CMemory(MercedesComboAddy1, bMercedesCombo, 1),
	new CMemory(MercedesComboAddy2, bMercedesCombo, 1)
};

/* Patched ?
int SkillInjectionSkills[] = {97, 99, 100, 103, 61001005, 4001334, 4201005, 4211011, 4221001, 1001004, 1221009, 1311005, 2201004, 2211003};

/////SkillInjection Disable Checks
BYTE bSkillInjection1[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
BYTE bSkillInjection3[] = {0xEB, 0x12};
//new CMemory cmSkillInjectionChecks(SkillInjectionChecksAddy1, bSkillInjection1, 6, SkillInjectionChecksAddy2, bSkillInjection1, 6, SkillInjectionChecksAddy3, bSkillInjection3, 2);

/////SkillInjection Set Skill ID
DWORD dwSkillInjectionRet = SkillInjectionInjectAddy + 6;
int iSkillInjectionSkillID;
BOOL WINAPI canSkillInjection()
{
if(CC->Busy || CMS::UsingPots || CMS::UsingAutoSkill || !SkillInjectionStopWatch.IsOver()) return FALSE;
SkillInjectionStopWatch.Start();
return TRUE;
}
CodeCave(SkillInjection)
{
push eax
call canSkillInjection
cmp eax, TRUE
pop eax
//If it returns TRUE, jump to InjectSkillInjection
je InjectSkill

//Else
mov edx,[esi+0x00006DAC]
jmp dword ptr [dwSkillInjectionRet]

InjectSkill:
mov edx,[iSkillInjectionSkillID]
jmp dword ptr [dwSkillInjectionRet]
}
EndCodeCave
new CMemory cmSkillInjectionCave(SkillInjectionInjectAddy, CaveSkillInjection, 1, true);
StopWatch<milliseconds> SkillInjectionStopWatch;
*/

/////No Fadestarge
BYTE bNoFadeStages [] = { 0xc2, 0x04, 0x00 };
Hack Hacks::NoFadeStages = {
	new CMemory(FadeAddy1, bNoFadeStages, 3),
	new CMemory(FadeAddy2, bNoFadeStages, 3)
};

///No CC BLue Boxes
Hack Hacks::NoCCBoxes = {
	new CMemory(NoCCBoxesAddy1, 5),
	new CMemory(NoCCBoxesAddy2, 5)
};

////Auto ExitCS Script
DWORD dwExitCSRet = ExitCSAddy + 9;
DWORD dwExitCSCall = ExitCSCall;
CodeCave(ExitCS)
{
	mov fs : [00000000], ecx
	pushad
	call dwExitCSCall
	popad
	jmp dwExitCSRet
}
EndCodeCave
Hack Hacks::ExitCS = { new CMemory(ExitCSAddy, CaveExitCS, 2) };

//PacketSender Fix
DWORD dwMainThreadID = 0;
DWORD SendPacketRet = SendPacketAddy + 5;
CodeCave(FixPacketSender)
{
	cmp[dwMainThreadID], 0
	jnz alreadyKnowMainThreadID
	push eax
	mov eax, fs:[0x18]
	mov eax, [eax + 0x6B8]
	mov[dwMainThreadID], eax
	pop eax

alreadyKnowMainThreadID :
	push eax
	mov eax, fs : [0x18]
	mov eax, [eax + 0x6B8]
	cmp[dwMainThreadID], eax
	jz  Continue
	mov eax, [dwMainThreadID]
	mov fs : [0x6B8], eax

Continue : //Do the original shit
	pop eax
	push ebp
	mov ebp, esp
	push 0xFF
	jmp SendPacketRet
}
EndCodeCave
Hack Hacks::ThreadIdFix = { new CMemory(SendPacketAddy, CaveFixPacketSender) };

DWORD dwSPControlRet = SPControlAddy + 6;
int spawn_x, spawn_y;
BOOL WINAPI GetCoords()
{
	int iMapID = CMS::MapId;
	for each(SPControlLocation^ location in SPControl::Locations)
	{
		if (iMapID == location->MapId)
		{
			spawn_x = location->X;
			spawn_y = location->Y;
			return TRUE;
		}
	}
	return FALSE;
}

CodeCave(SPControl)
{
	push eax
	call GetCoords
	cmp eax, FALSE
	pop eax
	je SpawnNormal //if eax == false, jump to SpawnNormal

	//Spawn on controlled location
	mov edi, [spawn_x]
	mov ebx, [spawn_y]
	jmp[dwSPControlRet]

SpawnNormal:
	mov edi, [eax + 0x0C]
	mov ebx, [eax + 0x10]
	jmp[dwSPControlRet]
}
EndCodeCave
BYTE SPCCheck [] = { 0xEB };
Hack Hacks::SpawnControl = {
	new CMemory(SPCChecksAddy, SPCCheck, 1),
	new CMemory(SPControlAddy, CaveSPControl, 1)
};

DWORD IFSJump = IFSCall; //55 8B EC 83 E4 ?? 6A ?? 68 ?? ?? ?? ?? 64 A1 ?? ?? ?? ?? 50 83 EC ?? 53 56 57 A1 ?? ?? ?? ?? 33 C4 50 8D 44 24 ?? 64 A3 ?? ?? ?? ?? 8B D9 8B 75 ?? 8B 7D ?? 85 F6
DWORD Skill1 = 61001000, Skill2 = 61001005;
CodeCave(IFS)
{
	mov eax, [Skill1]
	cmp [esp + 8], eax
	jne IFSEnd

	mov eax,[Skill2]
	mov[esp + 8], eax

IFSEnd:
	jmp IFSJump
}
EndCodeCave
Hack Hacks::InstantFinalSlash = {
	new CMemory(IFSAddy1, CaveIFS, 0, CMemory::ASM::Call), //E8 ?? ?? ?? ?? 85 C0 0F 8E ?? ?? ?? ?? 8B 7C 24 ?? 85 FF 74 ?? 81 C7 ?? ?? ?? ?? 83 3F ?? 74 ?? 8B 6C 24 ?? 8B 5F ?? 8B CD
	new CMemory(IFSAddy2, CaveIFS, 0, CMemory::ASM::Call) //E8 ?? ?? ?? ?? 8B E8 89 6C 24 ?? 81 FE ?? ?? ?? ?? 75 ?? 8B 4C 24 ?? E8 ?? ?? ?? ?? 85 C0
};
void Hacks::SetIFSClass(int index)
{
	switch (index)
	{
	case 0: //Kaiser
		Skill1 = 61001000;
		Skill2 = 61001005;
		break;
	case 1: //DemonSlayer
		Skill1 = 31000004;
		Skill2 = 31001008;
		break;
	}
}

StopWatch<milliseconds> TeleportWatch(milliseconds(2500));
void TryTeleport(int X, int Y)
{
	if (!TeleportWatch.IsOver() || CMS::ShouldAttack()) return;
	if (GetCoords() == TRUE && CMS::ItemCount == 0)
	{
		X = spawn_x;
		Y = spawn_y;
	}
	if (!X || !Y || (X == CMS::CharX && Y == CMS::CharY)) return;
	TeleportWatch.Start();
	Log::WriteLine("Teleporting to (" + X + ";" + Y + ")");
	Teleport(X, Y);
}

void LogTeleport(DWORD Address, DWORD Value)
{
	Log::WriteLine(Address.ToString("X") + "=" + Value.ToString("X"));
}