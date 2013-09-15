#pragma once
#include <Windows.h>
#include <vector>
#include <initializer_list>


class CMemory
{
public:
	enum class ASM{ Nop = 0x90, Call = 0xE8, Jump = 0xE9 };
	//--constructor--//
	CMemory(DWORD ulAddress, BYTE *bMem, int size);
	CMemory(DWORD ulAddress, int nops);
	CMemory(DWORD ulAddress, void* ulDestination, int ulNops = 0, ASM Type = ASM::Jump);
	//--destructor--//
	~CMemory();

	void Enable(bool enable);

private:
	void WriteMem();
	void RestoreMem();

	enum class HackType{ Bytes, Nops, Cave };

	//Both Types
	DWORD ulAddress;
	BYTE* oldMem;
	int bCount;

	HackType Type;
	ASM ASMType;

	//Bytes
	BYTE* bMem;

	//Cave
	void* ulDestination;
	int iNops;
};

class Hack
{
public:
	Hack(std::initializer_list<CMemory*> list) : hacks(list) {}

	bool Enable(bool state);
	bool Enabled;

private:
	std::vector<CMemory*> hacks;
};
