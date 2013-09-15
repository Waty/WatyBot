#include "Memory.h"
#include "MapleStory.h"

extern void ShowError(System::String^ Message);

//Constructors
CMemory::CMemory(DWORD Address, BYTE *Mem, int size) : Type(HackType::Bytes), ulAddress(Address), bMem(Mem), bCount(size) {}
CMemory::CMemory(DWORD Address, int nops) : Type(HackType::Nops), ulAddress(Address), iNops(nops), bCount(nops) {}
CMemory::CMemory(DWORD ulAddress, void* ulDestination, int Nops, ASM type) : Type(HackType::Cave), ulAddress(ulAddress), iNops(Nops), ulDestination(ulDestination), ASMType(type), bCount(5 + Nops) {}
//Destructor
CMemory::~CMemory(void)
{
	this->RestoreMem();
}

void CMemory::Enable(bool enable)
{
	enable ? this->WriteMem() : this->RestoreMem();
}
void CMemory::WriteMem()
{
	//Start VirtualProtect
	DWORD dwOldProtect;
	VirtualProtect((void*) ulAddress, bCount, PAGE_EXECUTE_READWRITE, &dwOldProtect);

	//Back-up old memory
	oldMem = new BYTE[bCount];
	memcpy(oldMem, (void*) ulAddress, bCount);

	//Write Hack
	if (this->Type == HackType::Cave)
	{
		__try
		{
			*(BYTE*) ulAddress = (int) ASMType;
			*(DWORD*) (ulAddress + 1) = (int) (((int) ulDestination - (int) ulAddress) - 5);
			if (iNops) memset((void*) (ulAddress + 5), (int) ASM::Nop, iNops);
		}
		__except (EXCEPTION_EXECUTE_HANDLER){};
	}
	else if (this->Type == HackType::Nops) memset((void*) ulAddress, (int) ASM::Nop, iNops);
	else memcpy_s((void*) this->ulAddress, bCount, (void*) this->bMem, bCount);

	//Stop VirtualProtect
	VirtualProtect((void*) ulAddress, bCount, dwOldProtect, &dwOldProtect);
}
void CMemory::RestoreMem()
{
	//Start VirtualProtect
	DWORD dwOldProtect;
	VirtualProtect((void*) ulAddress, bCount, PAGE_EXECUTE_READWRITE, &dwOldProtect);

	//Restore Memory
	memcpy_s((void*) this->ulAddress, bCount, (void*) this->oldMem, bCount);
	delete [] this->oldMem;

	//Stop VirtualProtect
	VirtualProtect((void*) ulAddress, bCount, dwOldProtect, &dwOldProtect);
}

bool Hack::Enable(bool state)
{
	if (!CMS::gotMSCRC)
	{
		ShowError("Couldn't enable the hack because there was no CRC bypass enabled");
		return false;
	}
	for (CMemory* cm : hacks) cm->Enable(state);
	Enabled = state;
	return state;
}
