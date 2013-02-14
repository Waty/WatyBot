namespace Hacks
{
	/////	FusionAttack
	DWORD dwFusionAddy = 0x00707552;
	DWORD dwFusionRet = dwFusionAddy + 8;
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
	CMemory cmFusionAttack(dwFusionAddy, CaveFusionAttack, 3, true);

	/////	Perfect Loot
	DWORD dwPerfectLoot1 = 0x004B46B7;
	DWORD dwPerfectLoot2 = 0x00542375;
	DWORD dwPerfectLoot3 = 0x004442D9;
	BYTE bPerfectLoot1[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
	BYTE bPerfectLoot2[] = {0x25};
	BYTE bPerfectLoot3[] = {0x81, 0xFE, 0x00, 0x00, 0x00, 0x00};
	CMemory cmPerfectLoot(dwPerfectLoot1, bPerfectLoot1, sizeof(bPerfectLoot1), dwPerfectLoot2, bPerfectLoot2, sizeof(bPerfectLoot2), dwPerfectLoot3, bPerfectLoot3, sizeof(bPerfectLoot3));

	/////	Instant Air Loot
	DWORD dwAirLoot = 0x00543529;
	BYTE bAirLoot[] = {0x74};
	CMemory cmInstantAirLoot(dwAirLoot, bAirLoot, 1);

	/////	No Background + Clouds
	DWORD dwNoBG1 = 0x006B73DC;
	DWORD dwNoBG2 = 0x006B5CEB;
	BYTE bNoBG[] = {0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmNoBG(dwNoBG1, bNoBG, 5, dwNoBG2, bNoBG, 5);

	/////	Jump Down Anywhere
	DWORD dwJDA1 = 0x00B76479;
	DWORD dwJDA2 = 0x00B764B6;
	DWORD dwJDA3 = 0x00B764D2;
	BYTE bJDA1[] = {0xEB};
	BYTE bJDA2[] = {0xEB};
	BYTE bJDA3[] = {0x90, 0x90};
	CMemory cmJDA(dwJDA1, bJDA1, 1, dwJDA2, bJDA2, 1, dwJDA3, bJDA3, 2);

	/////	Vac Right
	DWORD dwVacRight = 0x00C296A0;
	BYTE bVacRight[] = {0x75, 0x48};
	CMemory cmVacRight(dwVacRight, bVacRight, 2);

	/////	Walk Unrandom Right
	DWORD dwWalkRight = 0x00C338EB;
	BYTE bWalkRight[] = {0xE9, 0x95, 0x00, 0x00, 0x00, 0x90};
	CMemory cmWalkRight(dwWalkRight, bWalkRight, 6);

	/////	Jump Unrandom Right
	DWORD dwJumpRight = 0x00C33DEF;
	BYTE bJumpRight[] = {0xE9, 0x7A, 0x02, 0x00, 0x00, 0x90};
	CMemory cmJumpRight(dwJumpRight, bJumpRight, 6);

	/////	Pin Typer
	DWORD dwPinTyper1 = 0x0068F766;
	DWORD dwPinTyper2 = 0x00690E37;
	BYTE bPinTyper[] = {0x0F, 0x84};
	CMemory cmPinTyper(dwPinTyper1, bPinTyper, 2, dwPinTyper2, bPinTyper, 2);

	/////	NoKB
	DWORD dwNoKB = 0x00885ECB;
	BYTE bNoKB[] = {0x00};
	CMemory cmNoKB(dwNoKB, bNoKB, 1);

	/////	Full Mob Disarm
	DWORD dwDisarm = 0x00705122;
	BYTE bDisarm[] = {0xE9, 0x9B, 0x02, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90};
	CMemory cmMobDisarm(dwDisarm, bDisarm, sizeof(bDisarm));

	/////	Dojang Godmode
	DWORD DojangAddy = 0x00B67CB4;
	DWORD DojangRet = DojangAddy + 5;
	DWORD DojangCall = 0x00C298B0;
	unsigned long DojangMissCount = 0;
	CodeCave(Dojang)
	{
		inc [DojangMissCount]
		cmp [DojangMissCount] , 07 //amount of misses as its under 10 no need for a 0x
		jbe DojangExit
		mov [DojangMissCount] , 00
		call [DojangCall]
 
		DojangExit:
		jmp [DojangRet]
	}
	EndCodeCave
	CMemory cmDojangGodmode(DojangAddy, CaveDojang, 0, true);

	/////	Unlimited Morp
	DWORD dwMorph1 = 0x00BD00A8;
	DWORD dwMorph2 = 0x00BD0826;
	BYTE bMorph1[] = {0xEB, 0x2E};
	BYTE bMorph2[] = {0xEB};
	CMemory cmUnlimitedMorph(dwMorph1, bMorph1, 2, dwMorph2, bMorph1, 1); 
}