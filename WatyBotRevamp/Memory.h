#pragma once
#include <Windows.h>

enum cType{asmtype, singleaddy, twoaddys, threeaddys, fouraddys}; 
enum jumpType{jump, call};

class CMemory
{
public:
	//--constructor--//
	CMemory(unsigned long ulAddress, unsigned char* bMem, int size); //One Addy
	CMemory(unsigned long ulAddress1, unsigned char* bMem1, int size, unsigned long ulAddres2, unsigned char* bMem2, int size2); //Two Addy's
	CMemory(unsigned long ulAddress1, unsigned char* bMem1, int size, unsigned long ulAddres2, unsigned char* bMem2, int size2, unsigned long ulAddres3, unsigned char* bMem3, int size3);
	CMemory(unsigned long ulAddress1, unsigned char* bMem1, int size, unsigned long ulAddres2, unsigned char* bMem2, int size2, unsigned long ulAddres3, unsigned char* bMem3, int size3, unsigned long ulAddres4, unsigned char* bMem4, int size4);
	CMemory(unsigned long ulAddress, void* ulDestination, SIZE_T ulNops = 0, bool jump = true);
	//--destructor--//
	~CMemory();

	bool Enable(bool enable);
	bool Enabled;

private:	
	unsigned long ulAddress;
	unsigned char* bMem;
	unsigned char* oldMem;
	SIZE_T bCount;
	
	unsigned long ulAddress2;
	unsigned char* bMem2;
	unsigned char* oldMem2;
	SIZE_T bCount2;

	unsigned long ulAddress3;
	unsigned char* bMem3;
	unsigned char* oldMem3;
	SIZE_T bCount3;

	unsigned long ulAddress4;
	unsigned char* bMem4;
	unsigned char* oldMem4;
	SIZE_T bCount4;

	void* ulDestination;
	SIZE_T iNops;
	cType Type;
	jumpType jump;
	
	int jmp(unsigned long ulSource, void* ulDestination) ;
	void JumpCall(void* destination, SIZE_T ulNops);

	void WriteMem();
	void RestoreMem();
};
