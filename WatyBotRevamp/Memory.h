#pragma once
#include <Windows.h>


class CMemory
{
public:
	enum class ASM{ Nop = 0x90, Call = 0xE8, Jump = 0xE9 };
	//--constructor--//
	CMemory(DWORD ulAddress1, BYTE *bMem1, int size1);
	CMemory(DWORD ulAddress1, BYTE* bMem1, int size1, DWORD ulAddres2, BYTE* bMem2, int size2);
	CMemory(DWORD ulAddress1, BYTE* bMem1, int size1, DWORD ulAddres2, BYTE* bMem2, int size2, DWORD ulAddres3, BYTE* bMem3, int size3);
	CMemory(DWORD ulAddress1, BYTE* bMem1, int size1, DWORD ulAddres2, BYTE* bMem2, int size2, DWORD ulAddres3, BYTE* bMem3, int size3, DWORD ulAddres4, BYTE* bMem4, int size4);
	CMemory(DWORD ulAddress1, void* ulDestination, int ulNops = 0, ASM Type = ASM::Jump);
	//--destructor--//
	~CMemory();

	bool Enable(bool enable);
	bool Enabled;

private:
	void WriteMem();
	void RestoreMem();

	enum cType{ asmtype, singleaddy, twoaddys, threeaddys, fouraddys };

	DWORD ulAddress;
	BYTE* bMem;
	BYTE* oldMem;
	int bCount;

	DWORD ulAddress2;
	BYTE* bMem2;
	BYTE* oldMem2;
	int bCount2;

	DWORD ulAddress3;
	BYTE* bMem3;
	BYTE* oldMem3;
	int bCount3;

	DWORD ulAddress4;
	BYTE* bMem4;
	BYTE* oldMem4;
	int bCount4;

	void* ulDestination;
	int iNops;
	cType Type;
	ASM ASMType;
};
