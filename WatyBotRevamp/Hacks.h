#define CodeCave(name) void __declspec(naked) Cave##name(){_asm
#define EndCodeCave }

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
{
		inc [Miss7Counter]
		cmp dword ptr [Miss7Counter],0x07																									
		jg Reset
		mov dword ptr [esp+0x00000118],0x00
		jmp dword ptr [Miss7ReturnNoKB]

Reset:
		mov [Miss7Counter],00
		mov esi,[esp+0x0000011C]
		jmp dword ptr [Miss7Return]
}
EndCodeCave
CMemory Miss7GodMode(Miss7Addy, CaveSevenMiss, 2, true);

///////////////////////////////////////////////////////////Fusion Attack/////////////////////////////////////////////////////////////////////
DWORD FusionAttackAddy = 0x006FFBB2;
DWORD FusionAttackReturn = FusionAttackAddy + 8;
CodeCave(FusionAttack)
{
	Hook:
	mov dword ptr [ecx+eax*4],esi
	inc eax
	cmp eax,[esp+0x64]
	jl Hook
	mov [esp+0x18],eax
	jmp [FusionAttackReturn]
}
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
{
	call AutoAggroCal
	mov edx,[0x011ADD04]
	mov edx,[edx+0x29D0]
	mov edx,[edx+0x0C]
	mov [esi+0x2B0],edx
	jmp AutoAggroRet
}
EndCodeCave
CMemory AutoAggro(AutoAggroAddy, CaveAutoAggro, 0, true);

///////////////////////////////////////////////////////////Spawn Control/////////////////////////////////////////////////////////////////////
DWORD SPControlAddy = 0x00B8420A;
DWORD SPControlRet = SPControlAddy + 6;
CodeCave(SPControl)
{
	push eax
	call SPControlGetCoords
	cmp eax,FALSE
	pop eax
	je SpawnNormal

SpawnControl:
	mov ebx, [SPControlXCoord]
	mov ebp, [SPControlYCoord]
	jmp dword ptr SPControlRet

SpawnNormal:
	//mov edi
}
EndCodeCave
CMemory SPControl(SPControlAddy, CaveSPControl, 1, true);
#pragma endregion 
