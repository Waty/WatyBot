extern int getMapID();
extern int getCharX();
extern int getCharY();
namespace Hacks
{
	//Updated to V88.2
	/////Dojang Godmode
	DWORD DojangAddy = 0x00B60DF4;
	DWORD DojangRet = DojangAddy + 5;
	DWORD DojangCall = 0x00C228B0;
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
 
	/////Auto Aggro
	DWORD dwAggroAddy = 0x00C2FA3F;
	DWORD dwAggroRet = dwAggroAddy + 5;
	DWORD dwAggroCall = 0x00C26470;
	CodeCave(Aggro)
	{
		call dwAggroCall
		mov edx,dword ptr ds:[0x011DC904]
		mov edx,[edx+0x29D8]
		mov edx,[edx+0x0C]
		mov [esi+0x2B0],edx
		jmp dwAggroRet
	}
	EndCodeCave
	CMemory cmAutoAggro(dwAggroAddy, CaveAggro, 0, true);
 
	/////Pin Typer
	DWORD dwPinTyper1 = 0x00690426;
	DWORD dwPinTyper2 = 0x00691AF7;
	BYTE bPinTyper[] = {0x0F, 0x84};
	CMemory cmPinTyper(dwPinTyper1, bPinTyper, 2, dwPinTyper2, bPinTyper, 2);
 
	/////FusionAttack
	DWORD dwFusionAddy = 0x00709002;
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
 
	/////Perfect Loot
	DWORD dwPerfectLoot1 = 0x004B5367;// 89 86 ?? ?? ?? ?? E8 ?? ?? ?? ?? 89 ?? ?? ?? ?? ?? 5E C2
	DWORD dwPerfectLoot2 = 0x00542805;// 0D ?? ?? ?? ?? 83 C4 ?? E9 ?? ?? ?? ?? DD 05 ?? ?? ?? ?? DC C9
	DWORD dwPerfectLoot3 = 0x004440D9;// 81 FE ?? ?? ?? ?? 0F 8D ?? ?? ?? ?? 85 ED 0F 84 ?? ?? ?? ?? 81 FE ?? ?? ?? ?? BF ?? ?? ?? ?? 7E ?? B8 ?? ?? ?? ?? 2B C6
	BYTE bPerfectLoot1[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
	BYTE bPerfectLoot2[] = {0x25};
	BYTE bPerfectLoot3[] = {0x81, 0xFE, 0x00, 0x00, 0x00, 0x00};
	CMemory cmPerfectLoot(dwPerfectLoot1, bPerfectLoot1, sizeof(bPerfectLoot1), dwPerfectLoot2, bPerfectLoot2, sizeof(bPerfectLoot2), dwPerfectLoot3, bPerfectLoot3, sizeof(bPerfectLoot3));
 
	/////No Background + Clouds
	DWORD dwNoBG1 = 0x006B826C;
	DWORD dwNoBG2 = 0x006B6B7B;
	BYTE bNoBG[] = {0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmNoBG(dwNoBG1, bNoBG, 5, dwNoBG2, bNoBG, 5);
 
	/////Faster Mobs
	DWORD dwFasterMobs = 0x0071E5D3;
	BYTE bFasterMobs[] = {0x90, 0x90};
	CMemory cmFasterMobs(dwFasterMobs, bFasterMobs, 2);
 
	/////Unlimited Morp
	DWORD dwMorph1 = 0x00BC91A8;
	DWORD dwMorph2 = 0x00BC9926;
	BYTE bMorph1[] = {0xEB, 0x2E};
	BYTE bMorph2[] = {0xEB};
	CMemory cmUnlimitedMorph(dwMorph1, bMorph1, 2, dwMorph2, bMorph1, 1);
 
	/////ND - All Attacks
	DWORD dwNDAllAttacks = 0x00BA2926;
	BYTE bNDAllAttacks[] = {0x74};
	CMemory cmNDAllAttacks(dwNDAllAttacks, bNDAllAttacks, 1);
 
	/////Jump Down Anywhere
	DWORD dwJDA1 = 0x00B6F6E9;
	DWORD dwJDA2 = 0x00B6F726;
	DWORD dwJDA3 = 0x00B76ED4;
	BYTE bJDA1[] = {0xEB};
	BYTE bJDA2[] = {0xEB};
	BYTE bJDA3[] = {0x90, 0x90};
	CMemory cmJDA(dwJDA1, bJDA1, 1, dwJDA2, bJDA2, 1, dwJDA3, bJDA3, 2);
 
	/////Full Mob Disarm
	DWORD dwDisarm = 0x0000706D02;
	BYTE bDisarm[] = {0xE9, 0x9B, 0x02, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90};
	CMemory cmMobDisarm(dwDisarm, bDisarm, sizeof(bDisarm));
 
	/////No Mobs
	DWORD dwNoMobs = 0x0070B2FD;// 77 ? 0F B6 80 ? ? ? 00 FF 24 85 ? ? ? 00 8B 54 24 ? 52 E8 ? ? ? FF C2 08 00 - 2nd result
	BYTE bNoMobs[] = {0xEB};
	CMemory cmNoMobs(dwNoMobs, bNoMobs, 1);
 
	/////Instant Air Loot
	DWORD dwAirLoot = 0x00543999;// 75 68 2B 56 ** 81 FA ** ** ** ** 7C ** 8B ** ** 3D
	BYTE bAirLoot[] = {0x74};
	CMemory cmInstantAirLoot(dwAirLoot, bAirLoot, 1);
 
	/////Vac Right
	DWORD dwVacRight = 0x00C226A0;
	BYTE bVacRight[] = {0x75, 0x48};
	CMemory cmVacRight(dwVacRight, bVacRight, 2);// 75 ?? DC 11 DF E0 F6 C4 41 75 ?? D9 C9 DC 74 24 10 DC 4C 24 20 DC 01 DD 11 D8 D9 DF E0 F6 C4 41
 
	/////Walk Unrandom Right
	DWORD dwWalkRight = 0x00C2C98B;
	BYTE bWalkRight[] = {0xE9, 0x95, 0x00, 0x00, 0x00, 0x90};
	CMemory cmWalkRight(dwWalkRight, bWalkRight, 6);
 
	/////Jump Unrandom Right
	DWORD dwJumpRight = 0x00C2CE8F;
	BYTE bJumpRight[] = {0xE9, 0x7A, 0x02, 0x00, 0x00, 0x90};
	CMemory cmJumpRight(dwJumpRight, bJumpRight, 6);
 
	/////NoKB
	DWORD dwNoKB = 0x00887DFB;
	BYTE bNoKB[] = {0x00};
	CMemory cmNoKB(dwNoKB, bNoKB, 1);
 
	/////Sit Everywhere
	DWORD dwSit = 0x00B65EE1;
	BYTE bSit[] = {0x75};
	CMemory cmSitHack(dwSit, bSit, 1);
 
	/////Spawn Control
	DWORD dwSPControl = 0x00B8A17A;
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
 
		//Spawn on controlled location
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
 
	/////50 Seconds Godmode
	DWORD dw50SecGM1 = 0x00BA138E;
	DWORD dw50SecGM2 = 0x00BA13A9;
	BYTE b50SecGM1[] = {0x7E};
	BYTE b50SecGM2[] = {0xD4, 0x36};
	CMemory cm50SecGM(dw50SecGM1, b50SecGM1, 1, dw50SecGM2, b50SecGM2, 2);
 
	/////Logo Skipper *NOT UPDATED STILL V88.2 or???
	DWORD dwLogoSkipper = 0x0069F2F0;
	BYTE bLogoSkipper[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xE9, 0xA5, 0xE2, 0xFF, 0xFF, 0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmLogoSkipper(dwLogoSkipper, bLogoSkipper, sizeof(bLogoSkipper));
 
	/////(semi) Item Vac
	DWORD dwItemVac = 0x006D2FD4; // E8 ? ? ? ? 8B C8 8B 44 24 ? 89 38 5F 89 48 ? 5E C2 04 00 CC CC CC CC CC CC CC 56 - 4th result
	DWORD dwItemVacCall = 0x006E7FE0;
	int itemvac_x = 0;
	int itemvac_y = 0;
	VOID WINAPI getItemVacCoords()
	{
		itemvac_x = getCharX();
		itemvac_y = getCharY();
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
	CMemory cmItemVac(dwItemVac, CaveItemVac, 0, true);
 
	/////View Swears
	DWORD NoSwearsAddy = 0x00884B4B;//74 ? 80 3e 00 75 ? 0f b6 13
	BYTE bNoSwears[] = {0x90, 0x90};
	CMemory cmNoSwears(NoSwearsAddy, bNoSwears, 2);
 
	/////FMA
	DWORD FMAAddy = 0x00708ff0;
	BYTE bFMA[] = {0xEB};
	CMemory cmFMA(FMAAddy, bFMA, 1);
 
	/////Ghoul's Scare Mob Lagg
	DWORD dwScareMobs = 0x0070766F;
	BYTE bScareMobs[] = {0x75};
	CMemory cmScareMobs(dwScareMobs, bScareMobs, 1);
 
	/////Always Face Left
	DWORD dwFLACC = 0x00C2281A;
	BYTE bFLACC[] = {0xB8, 0x05, 0x00, 0x00, 0x00, 0x90};
	CMemory cmFLACC(dwFLACC, bFLACC, 6);
 
	/////CPU Hack
	DWORD dwCPU1 = 0x006B33EB;
	DWORD dwCPU2 = 0x006B826C;
	DWORD dwCPU3 = 0x006BCC19;
	BYTE bCPU[] = {0x90, 0x90, 0x90, 0x90, 0x90};
	CMemory cmCPUHack(dwCPU1, bCPU, 5, dwCPU2, bCPU, 5, dwCPU3, bCPU, 5);
 
	/////Unlimited Attack
	DWORD dwUA = 0x004DAFEF;
	DWORD dwUARet = 0x004DAFEF + 6;
	CodeCave(UA)
	{
		mov [eax],edi //orig code
 
		push ebx
		mov ebx, dword ptr [0x011D8228] // Char Base Pointer
		mov ebx,[ebx]
		cmp dword ptr [ebx+0x7034], 0x5A // Attack Count offset
		jl UAexit
		add dword ptr [eax],0x08
 
		UAexit:
		pop ebx
		pop edi
		mov [eax+0x04],ecx
		jmp dwUARet
	}
	EndCodeCave
	CMemory cmUA(dwUA, CaveUA, 1, true);
 
	/////Disable Final Attack Luna NOT UPDATED
	DWORD dwDFA = 0x00BC6E80;
	BYTE bDFA[] = {0xC3};
	CMemory cmDFA(dwDFA, bDFA, 1);
 
	/////ND Mining
	DWORD dwNDMining1 = 0x00B6D282;
	BYTE bNDMining1[] = {0x90, 0x90};
	DWORD dwNDMining2 = 0x00B6D35B;
	BYTE bNDMining2[] = {0xEB};
	DWORD dwNDMining3 = 0x00B7D947;
	BYTE bNDMining3[] = {0x90, 0x90};
	CMemory cmNDMining(dwNDMining1, bNDMining1, 2, dwNDMining2, bNDMining2, 1, dwNDMining3, bNDMining3, 2);
 
	/////Hide Damage
	DWORD dwHideDamage = 0x006E41C7;
	BYTE bHideDamage[] = {0x7F};
	CMemory cmHideDamage(dwHideDamage, bHideDamage, 1);
 
	/////Mercedes Combos without comboing
	DWORD dwMercedesCombo = 0x00BB1B4B;
	BYTE bMercedesCombo[] = {0xEB};
	CMemory cmMercedesCombo(dwMercedesCombo, bMercedesCombo, 1);
 
	/////PvP Disable Checks
	DWORD dwPVP1 = 0x00BBF4E4; //GMS: 00D33CA4: // Skip Check // 0F 84 ?? ?? ?? ?? 2B AE ?? ?? ?? ?? 0F 88 ?? ?? ?? ?? 8B 86 ?? ?? ?? ?? 50 E8 ?? ?? ?? ?? 83 C4 ?? 3B 86 ?? ?? ?? ?? 0F 85 ?? ?? ?? ?? 8B 96
	BYTE bPVP1[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
	DWORD dwPVP2 = 0x00BBF50B; //GMS: 00D33CCB: // Bypass Weapon Check // 0F 85 ?? ?? ?? ?? 8B 96 ?? ?? ?? ?? 8B 44 24 ?? 6A ?? 6A ?? 6A ?? 8D 4C 24 ?? 51 8B 0D ?? ?? ?? ?? 52 50 C7 44 ?? ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B F8 85 FF 0F 8E
	BYTE bPVP2[] = {0x90, 0x90, 0x90, 0x90, 0x90, 0x90};
	DWORD dwPVP3 = 0x00BBF5AC; //GMS: 00D33D6C: // Switch Jump // 77 ?? 0F B6 88 ?? ?? ?? ?? FF 24 8D ?? ?? ?? ?? 8B 54 24 ?? 6A ?? 6A ?? 6A ?? 6A ?? 6A ?? 6A ?? 6A ?? 6A ?? 6A ?? 6A ?? 57 52 8B CE E8 ?? ?? ?? ?? 5F
	BYTE bPVP3[] = {0xEB, 0x0E};//GMS: 00D33D7C // Melee // 8B 54 24 ?? 6A ?? 6A ?? 6A ?? 6A ?? 6A ?? 6A ?? 6A ?? 6A ?? 6A ?? 6A ?? 57 52 8B CE E8 ?? ?? ?? ?? 5F C7 86 ?? ?? ?? ?? ?? ?? ?? ?? 5E 5D 5B 83 C4 ?? C3 8B 44 24 ?? 6A ?? 6A ?? 6A ?? 6A ?? 6A ?? 57 50 8B CE E8 ?? ?? ?? ?? 5F C7 86 ?? ?? ?? ?? ?? ?? ?? ?? 5E 5D 5B 83 C4
	CMemory cmPVP1(dwPVP1, bPVP1, 6, dwPVP2, bPVP2, 6, dwPVP3, bPVP3, 2);
 
	/////PvP Set Skill ID
	DWORD dwPVPAddy = 0x00BBF511; //GMS: 00D33CD1: // Set Skill Id // 8B 96 ?? ?? ?? ?? 8B 44 24 ?? 6A ?? 6A ?? 6A ?? 8D 4C 24 ?? 51 8B 0D ?? ?? ?? ?? 52 50 C7 44 24 ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B F8 85 FF 0F 8E ?? ?? ?? ?? 8B 1D ?? ?? ?? ??
	DWORD dwPVPRet = dwPVPAddy + 6;
	int iPVPSkillID;
	int iPVPDelay;
	int count;
	CodeCave(PVP)
	{
		push eax
		mov eax, dword ptr [count]
		cmp eax, dword ptr [iPVPDelay]
		//call Delay
		//cmp eax, TRUE //increase this till it works for you
		pop eax
		jge InjectPvP
		inc [count]
		mov edx,[esi+0x00006DAC]
		jmp dword ptr [dwPVPRet]
 
		InjectPvP:
		mov [count],0
		mov edx,[iPVPSkillID] // Change this to the skill you want to use ~~
		jmp dword ptr [dwPVPRet]
	}
	EndCodeCave
	CMemory cmPVP2(dwPVPAddy, CavePVP, 1, true);
}
