extern int getMapID();
namespace Hacks
{
	//Updated to V87.2
	/////	Dojang Godmode
	DWORD DojangAddy = 0x00B67D14;
	DWORD DojangRet = DojangAddy + 5;
	DWORD DojangCall = 0x00441A60;
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

	/////	Auto Aggro
	DWORD dwAggroAddy = 0x00C36AFF;
	DWORD dwAggroRet = dwAggroAddy + 5;
	DWORD dwAggroCall = 0x00C2D5E0;
	CodeCave(Aggro)
	{
		call dwAggroCall
		mov edx,[0x11E1148]
		mov edx,[edx+0x29D8]
		mov edx,[edx+0x0C]
		mov [esi+0x2B0],edx
		jmp dwAggroRet
	}
	EndCodeCave
	CMemory cmAutoAggro(dwAggroAddy, CaveAggro, 0, true);

	/////	Pin Typer
	DWORD dwPinTyper1 = 0x0068FD86;
	DWORD dwPinTyper2 = 0x00691457;
	BYTE bPinTyper[] = {0x0F, 0x84};
	CMemory cmPinTyper(dwPinTyper1, bPinTyper, 2, dwPinTyper2, bPinTyper, 2);

	/////	FusionAttack
	DWORD dwFusionAddy = 0x00707842;
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
	DWORD dwPerfectLoot1 = 0x004B5237;								// 89 86 ?? ?? ?? ?? E8 ?? ?? ?? ?? 89 ?? ?? ?? ?? ?? 5E C2
	DWORD dwPerfectLoot2 = 0x00542C05;								// 0D ?? ?? ?? ?? 83 C4 ?? E9 ?? ?? ?? ?? DD 05 ?? ?? ?? ?? DC C9
	DWORD dwPerfectLoot3 = 0x00444789;								// 81 FE ?? ?? ?? ?? 0F 8D ?? ?? ?? ?? 85 ED 0F 84 ?? ?? ?? ?? 81 FE ?? ?? ?? ?? BF ?? ?? ?? ?? 7E ?? B8 ?? ?? ?? ?? 2B C6
	BYTE bPerfectLoot1[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
	BYTE bPerfectLoot2[] = {0x25};
	BYTE bPerfectLoot3[] = {0x81, 0xFE, 0x00, 0x00, 0x00, 0x00};
	CMemory cmPerfectLoot(dwPerfectLoot1, bPerfectLoot1, sizeof(bPerfectLoot1), dwPerfectLoot2, bPerfectLoot2, sizeof(bPerfectLoot2), dwPerfectLoot3, bPerfectLoot3, sizeof(bPerfectLoot3));

	/////	No Background + Clouds
	DWORD dwNoBG1 = 0x006B7ABC;
	DWORD dwNoBG2 = 0x006B5CEB;
	BYTE bNoBG[] = {0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmNoBG(dwNoBG1, bNoBG, 5, dwNoBG2, bNoBG, 5);

	/////Faster Mobs
	DWORD dwFasterMobs = 0x0071CDA3;
	BYTE bFasterMobs[] = {0x90, 0x90};
	CMemory cmFasterMobs(dwFasterMobs, bFasterMobs, 2);

	/////	Unlimited Morp
	DWORD dwMorph1 = 0x00BD0258;
	DWORD dwMorph2 = 0x00BD09D6;
	BYTE bMorph1[] = {0xEB, 0x2E};
	BYTE bMorph2[] = {0xEB};
	CMemory cmUnlimitedMorph(dwMorph1, bMorph1, 2, dwMorph2, bMorph1, 1);

	/////	ND - All Attacks
	DWORD dwNDAllAttacks = 0x00B415F0;
	BYTE bNDAllAttacks[] = {0xB8, 0x01, 0x00, 0x00, 0x00, 0xC3, 0x90};
	CMemory cmNDAllAttacks(dwNDAllAttacks, bNDAllAttacks, sizeof(bNDAllAttacks));

	/////	Jump Down Anywhere
	DWORD dwJDA1 = 0x00B76639;
	DWORD dwJDA2 = 0x00B76676;
	DWORD dwJDA3 = 0x00B76694;
	BYTE bJDA1[] = {0xEB};
	BYTE bJDA2[] = {0xEB};
	BYTE bJDA3[] = {0x90, 0x90};
	CMemory cmJDA(dwJDA1, bJDA1, 1, dwJDA2, bJDA2, 1, dwJDA3, bJDA3, 2);

	/////	Full Mob Disarm
	DWORD dwDisarm = 0x00705462;
	BYTE bDisarm[] = {0xE9, 0x9B, 0x02, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90};
	CMemory cmMobDisarm(dwDisarm, bDisarm, sizeof(bDisarm));

	/////	No Mobs
	DWORD dwNoMobs = 0x00709B3D;									// 77 ? 0F B6 80 ? ? ? 00 FF 24 85 ? ? ? 00 8B 54 24 ? 52 E8 ? ? ? FF C2 08 00 - 2nd result
	BYTE bNoMobs[] = {0xEB};
	CMemory cmNoMobs(dwNoMobs, bNoMobs, 1);
	
	/////	Instant Air Loot
	DWORD dwAirLoot = 0x00544029;									// 75 68 2B 56 ** 81 FA ** ** ** ** 7C ** 8B ** ** 3D
	BYTE bAirLoot[] = {0x74};
	CMemory cmInstantAirLoot(dwAirLoot, bAirLoot, 1);

	/////	Vac Right
	DWORD dwVacRight = 0x00C29860;
	BYTE bVacRight[] = {0x75, 0x48};
	CMemory cmVacRight(dwVacRight, bVacRight, 2);					// 75 ?? DC 11 DF E0 F6 C4 41 75 ?? D9 C9 DC 74 24 10 DC 4C 24 20 DC 01 DD 11 D8 D9 DF E0 F6 C4 41

	/////	Walk Unrandom Right
	DWORD dwWalkRight = 0x00C33A4B;
	BYTE bWalkRight[] = {0xE9, 0x95, 0x00, 0x00, 0x00, 0x90};
	CMemory cmWalkRight(dwWalkRight, bWalkRight, 6);

	/////	Jump Unrandom Right
	DWORD dwJumpRight = 0x00C33F4F;
	BYTE bJumpRight[] = {0xE9, 0x7A, 0x02, 0x00, 0x00, 0x90};
	CMemory cmJumpRight(dwJumpRight, bJumpRight, 6);

	/////	NoKB
	DWORD dwNoKB = 0x008864BB;
	BYTE bNoKB[] = {0x00};
	CMemory cmNoKB(dwNoKB, bNoKB, 1);

	/////	Sit Everywhere
	DWORD dwSit = 0x00B6CE11;
	BYTE bSit[] = {0x75};
	CMemory cmSitHack(dwSit, bSit, 1);

	/////	Spawn Control
	DWORD dwSPControl = 0x00B9107A;
	DWORD dwSPControlRet = dwSPControl + 6;
	int spawn_x, spawn_y;

	BOOL WINAPI GetCoords()
	{
		int iMapID = getMapID();
		for(unsigned int i = 0; i < SPControlv.size(); i++)
		{
			if( iMapID == SPControlv.at(i).mapID )
			{
				spawn_x = SPControlv.at(i).x;
				spawn_y = SPControlv.at(i).y;
				return TRUE;
			}
		}
		return FALSE;
	}
	CodeCave(SPControl)
	{
		push eax
		call GetCoords
		cmp eax,FALSE
		pop eax
		je SpawnNormal //if eax == false, jump to SpawnNormal
		mov ebx,[spawn_x]
		mov ebp,[spawn_y]
        jmp [dwSPControlRet]
 
		SpawnNormal:
        mov ebx,[eax+0x0C]
        mov ebp,[eax+0x10]
        jmp [dwSPControlRet]
	}
	EndCodeCave
	CMemory cmSPControl(dwSPControl, CaveSPControl, 1, true);
}