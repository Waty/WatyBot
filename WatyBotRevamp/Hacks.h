#include "Defines.h"

namespace Hacks
{
	/////Dojang Godmode
	DWORD DojangRet = DojangAddy + 5;
	DWORD dwDojangCall = DojangCall;
	int DojangMissCount = 0;
	CodeCave(Dojang)
	{
		inc [DojangMissCount]
		cmp [DojangMissCount] , 07 //amount of misses as its under 10 no need for a 0x
		jbe DojangExit
		mov [DojangMissCount] , 00
		call dword ptr [dwDojangCall]
 
		DojangExit:
		jmp [DojangRet]
	}
	EndCodeCave
	CMemory cmDojangGodmode(DojangAddy, CaveDojang, 0, true);

	/////Ice GuardGM
	DWORD IceGuardRet = IceGuardAddy + 7;
	DWORD dwIceGuardPush = IceGuardPush;
	int iIceGuardCounter = 0, iIceGuardLimit;
	CodeCave(IceGuard)
	{
		pushad
		mov eax, iIceGuardLimit
		cmp [iIceGuardCounter], eax
		popad
		jle blockDMG

		mov [iIceGuardCounter], 0
		push 0xFF
		push dwIceGuardPush
		jmp IceGuardRet

		blockDMG:
		add [iIceGuardCounter], 1
		ret 0x002C
	}
	EndCodeCave
	CMemory cmIceGuard(IceGuardAddy, CaveIceGuard, 2, true);

	/////Auto Aggro
	DWORD dwAggroRet = AggroAddy + 5;
	DWORD dwAggroCall = AggroCall;
	CodeCave(Aggro)
	{
		call dwAggroCall
		mov edx,dword ptr ds:[CharBasePtr]
		mov edx,[edx+0x0C]
		mov edx,[edx+0x0C]
		mov [esi+0x2B0],edx
		jmp dwAggroRet
	}
	EndCodeCave
	CMemory cmAutoAggro(AggroAddy, CaveAggro, 0, true);
 
	/////Pin Typer
	BYTE bPinTyper[] = {0x0F, 0x84};
	CMemory cmPinTyper(PinTyperAddy1, bPinTyper, 2, PinTyperAddy2, bPinTyper, 2);

	/////PIC Typer
	BYTE bPicTyper1[] = {0x90, 0xE9};
	BYTE bPicTyper2[] = {0x00};
	BYTE bPictyper3[] = {0xE8, 0x4D, 0xB2, 0xC5, 0xFF};
	CMemory cmPicTyper(/*PicTyperAddy1, bPicTyper1, 2, PicTyperAddy2, bPicTyper2, 1, PicTyperAddy3, bPictyper3, 5*/);

	/////FusionAttack
	DWORD dwFusionRet = FusionAddy + 8;
	CodeCave(FusionAttack)
	{
		Hook:
		mov [ecx+eax*4],esi
		inc eax
		cmp eax,[esp+0x64]
		jl Hook
		mov [esp+0x18],eax
		jmp dwFusionRet
	}
	EndCodeCave
	CMemory cmFusionAttack(FusionAddy, CaveFusionAttack, 3, true);
 
	/////Perfect Loot
	BYTE bPerfectLoot1[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
	BYTE bPerfectLoot2[] = {0x25};
	BYTE bPerfectLoot3[] = {0x81, 0xFE, 0x00, 0x00, 0x00, 0x00};
	CMemory cmPerfectLoot(PerfectLootAddy1, bPerfectLoot1, sizeof(bPerfectLoot1), PerfectLootAddy2, bPerfectLoot2, sizeof(bPerfectLoot2), PerfectLootAddy3, bPerfectLoot3, sizeof(bPerfectLoot3));
 
	/////No Background + Clouds
	BYTE bNoBG[] = {0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmNoBG(/*NoBGAddy1, bNoBG, 5, */NoBGAddy2, bNoBG, 5);
 
	/////Faster Mobs
	BYTE bFasterMobs[] = {0x90, 0x90};
	CMemory cmFasterMobs(FasterMobsAddy, bFasterMobs, 2);
 
	/////Unlimited Morp
	BYTE bMorph1[] = {0xEB, 0x2E};
	BYTE bMorph2[] = {0xEB};
	CMemory cmUnlimitedMorph(UnlimitedMorphAddy1, bMorph1, 2, UnlimitedMorphAddy2, bMorph2, 1);
 
	/////ND - All Attacks
	BYTE bgND1[] = {0x74};
	BYTE bgND2[] = {0x00};
	CMemory cmNDAllAttacks(gNDAddy1, bgND1, 1/*, gNDAddy2, bgND2, 1*/);
 
	/////Jump Down Anywhere
	BYTE bJDA1[] = {0xEB};
	BYTE bJDA2[] = {0xEB};
	BYTE bJDA3[] = {0x90, 0x90};
	CMemory cmJDA(JDAAddy1, bJDA1, 1, JDAAddy2, bJDA2, 1, JDAAddy3, bJDA3, 2);
 
	/////Full Mob Disarm
	BYTE bDisarm[] = {0xE9, 0x24, 0x04, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90}; //jmp 00772493 + 4 nops
	CMemory cmMobDisarm(MobDisarmAddy, bDisarm, sizeof(bDisarm));
 
	/////No Mobs
	BYTE bNoMobs[] = {0xEB};
	CMemory cmNoMobs(NoMobsAddy, bNoMobs, 1);
 
	/////Instant Air Loot
	BYTE bAirLoot[] = {0x90, 0x90};
	CMemory cmInstantAirLoot(AirLootAddy, bAirLoot, 2);
 
	/////Vac Right
	BYTE bVacRight[] = {0x75, 0x48};
	CMemory cmVacRight(VacRightAddy, bVacRight, 2);// 75 ?? DC 11 DF E0 F6 C4 41 75 ?? D9 C9 DC 74 24 10 DC 4C 24 20 DC 01 DD 11 D8 D9 DF E0 F6 C4 41
 
	/////Walk Unrandom Right
	BYTE bWalkRight[] = {0xE9, 0x95, 0x00, 0x00, 0x00, 0x90};
	CMemory cmWalkRight(WalkRightAddy, bWalkRight, 6);
 
	/////Jump Unrandom Right
	BYTE bJumpRight[] = {0xE9, 0x7A, 0x02, 0x00, 0x00, 0x90};
	CMemory cmJumpRight(JumpRightAddy, bJumpRight, 6);
 
	/////NoKB
	BYTE bNoKB[] = {0x00};
	CMemory cmNoKB(NoKBAddy, bNoKB, 1);
 
	/////Sit Hack
	BYTE bSit[] = {0x75};
	CMemory cmSitHack(SitHackAddy, bSit, 1);
 
	/////50 Seconds Godmode
	BYTE b50SecGM1[] = {0x7E};
	BYTE b50SecGM2[] = {0xD4, 0x36};
	CMemory cm50SecGM(Godmode50SecAddy1, b50SecGM1, 1, Godmode50SecAddy2, b50SecGM2, 2);
 
	/////Logo Skipper
	BYTE bLogoSkipper[] = {0x50, 0xD2};
	CMemory cmLogoSkipper(/*LogoSkipperAddy, bLogoSkipper, 2*/);
 
	/////(semi) Item Vac
	DWORD dwItemVacCall = ItemVacCall;
	int itemvac_x = 0;
	int itemvac_y = 0;
	VOID WINAPI getItemVacCoords()
	{
		itemvac_x = CMS::CharX();
		itemvac_y = CMS::CharY();
	}
	CodeCave(ItemVac)
	{
		call dwItemVacCall //Original Opcode
		call getItemVacCoords
		mov ecx,eax
		mov eax,[esp+0x0C]
		mov edi,[itemvac_x]
		mov [eax],edi //X
		pop edi
		mov esi,[itemvac_y]
		mov [eax+04],esi //Y
		pop esi
		ret 0004
	}
	EndCodeCave 
	CMemory cmItemVac(ItemVacAddy, CaveItemVac, 0, true); // E8 ? ? ? ? 8B C8 8B 44 24 ? 89 38 5F 89 48 ? 5E C2 04 00 CC CC CC CC CC CC CC 56 - 4th result
 
	/////View Swears
	BYTE bNoSwears[] = {0x90, 0x90};
	CMemory cmNoSwears(ViewSwearsAddy, bNoSwears, 2);
 
	/////FMA
	BYTE bFMA[] = {0xEB};
	CMemory cmFMA(FMAAddy, bFMA, 1);
 
	/////Ghoul's Scare Mob Lagg
	BYTE bScareMobs[] = {0x75};
	CMemory cmScareMobs(ScareMobsAddy, bScareMobs, 1);
 
	/////Always Face Left
	BYTE bFLACC[] = {0xB8, 0x05, 0x00, 0x00, 0x00, 0x90};
	CMemory cmFLACC(FLACC, bFLACC, 6);
 
	/////CPU Hack
	BYTE bCPU[] = {0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmCPUHack(CPUAddy1, bCPU, 5/*, CPUAddy2, bCPU, 5, CPUAddy3, bCPU, 5*/);
 
	/////Unlimited Attack
	DWORD dwUARet = UAAddy + 6;
	BOOL WINAPI UA()
	{
		if(CMS::AttackCount() > 90) return TRUE;
		return FALSE;
	}
	CodeCave(UA)
	{
		mov [eax],edi //orig code
 
		pushad
		call UA
		cmp eax, TRUE // Attack Count offset
		popad
		jne UAexit
		add dword ptr [eax],0x08
 
		UAexit:
		pop edi
		mov [eax+0x04],ecx
		jmp dwUARet
	}
	EndCodeCave
	CMemory cmUA(UAAddy, CaveUA, 1, true);
 
	/////Disable Final Attack Luna
	BYTE bDFA[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmDFA(DFAAddy, bDFA, 7);
 
	/////ND Mining
	BYTE bNDMining1[] = {0x90, 0x90};
	BYTE bNDMining2[] = {0xEB};
	BYTE bNDMining3[] = {0x90, 0x90};
	CMemory cmNDMining(NDMiningAddy1, bNDMining1, 2, NDMiningAddy2, bNDMining2, 1, NDMiningAddy3, bNDMining3, 2);
 
	/////Hide Damage
	BYTE bHideDamage1[] = {0x00};
	BYTE bHideDamage2[] = {0x90, 0xE9};
	BYTE bHideDamage3[] = {0xEB};
	BYTE bHideDamage4[] = {0xEB};
	BYTE bHideDamage5[] = {0xEB};
	CMemory cmHideDamage1(HideDamageAddy1, bHideDamage1, 1, HideDamageAddy2, bHideDamage2, 2/*, HideDamageAddy3, bHideDamage3, 1, HideDamageAddy4, bHideDamage4, 1*/);
	CMemory cmHideDamage2(HideDamageAddy5, bHideDamage5, 1);
 
	/////Mercedes Combos without comboing
	BYTE bMercedesCombo[] = {0xEB};
	CMemory cmMercedesCombo(MercedesComboAddy, bMercedesCombo, 1);
 
	/* Patched ?
	/////SkillInjection Disable Checks
	BYTE bSkillInjection1[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
	BYTE bSkillInjection3[] = {0xEB, 0x12};
	//CMemory cmSkillInjectionChecks(SkillInjectionChecksAddy1, bSkillInjection1, 6, SkillInjectionChecksAddy2, bSkillInjection1, 6, SkillInjectionChecksAddy3, bSkillInjection3, 2);
 
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
	CMemory cmSkillInjectionCave(SkillInjectionInjectAddy, CaveSkillInjection, 1, true);
	*/

	/////No Fadestarge
	BYTE bNoFadeStages[] = {0xc2, 0x04, 0x00};
	CMemory cmNoFadeStages(FadeAddy1, bNoFadeStages, 3, FadeAddy2, bNoFadeStages, 3);

	///No CC BLue Boxes
	//TODO: Fix this:
	BYTE bNoCCBoxes[] = {0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmNoCCBoxes(NoCCBoxesAddy1, bNoCCBoxes, 5/*, NoCCBoxesAddy2, bNoCCBoxes, 5*/);
	
	////SS Mouse Fly
	DWORD dwMouseFlyRet = MouseFlyAddy + 5;
	DWORD dwMouseFlyCall1 = MouseFlyCall1;
	DWORD dwMouseFlyCall2 = MouseFlyCall2;

	CodeCave(MouseFly)
	{
		call dwMouseFlyCall1
		pushad
		//looking for the mouse click
		mov ebx, [MouseBasePtr]
		mov ebx, [ebx]
		//MouseClick fly, but mouseanioffset is wrong :(
		//cmp dword ptr[ebx+MouseAniOffset], 0x0C
		//jne FlyExit

		//get mouselocation
		mov ebx,[ebx+MouseLocOffset]
		mov eax,[ebx+MouseXOffset]
		mov ebx,[ebx+(MouseXOffset + 4)]

		//encrypt and set teleoffsets
		lea ecx,[esi+0x7AF0]
		push eax
		call dwMouseFlyCall2
		lea ecx, [esi+0x7AE4]
		push ebx
		call dwMouseFlyCall2
		lea ecx, [esi+0x7ACC]
		push 00000001 //Probably dont need all the proceeding 0's but wthell
		call dwMouseFlyCall2

		//FlyExit:
		popad
		jmp dwMouseFlyRet

	}
	EndCodeCave
	CMemory cmMouseFly(MouseFlyAddy, CaveMouseFly, 0, true);

	////Auto ExitCS Script
	DWORD dwExitCSRet = ExitCSAddy + 9;
	DWORD dwExitCSCall = ExitCSCall;
	CodeCave(ExitCS)
	{
		mov fs:[00000000],ecx
		pushad
		call dwExitCSCall
		popad

		jmp dwExitCSRet
	}
	EndCodeCave
	CMemory cmExitCS(ExitCSAddy, CaveExitCS, 2, true);
	
	//PacketSender Fix
	DWORD dwMainThreadID = 0;
	DWORD SendPacketRet = SendPacketAddy + 5;
	CodeCave(FixPacketSender)
	{
		cmp [dwMainThreadID],0
		jnz alreadyKnowMainThreadID
		push eax
		mov eax,  fs:[0x18]
		mov eax, [eax+0x6B8]
		mov [dwMainThreadID], eax
		pop eax

		alreadyKnowMainThreadID:
		push eax
		mov eax,  fs:[0x18]
		mov eax, [eax+0x6B8]
		cmp [dwMainThreadID], eax
		jz  Continue
		mov eax, [dwMainThreadID]
		mov fs:[0x6B8], eax
		Continue: //Do the original shit
		pop eax

		push ebp
		mov ebp,esp
		push 0xFF
		jmp SendPacketRet
	}
	EndCodeCave
	CMemory cmPacketSenderFix(SendPacketAddy, CaveFixPacketSender, 0, true);
}
