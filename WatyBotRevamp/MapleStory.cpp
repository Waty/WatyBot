#include "MapleStory.h"
#include "Pointers.h"


CMapleStory::CMapleStory(void)
{
}

CMapleStory::~CMapleStory(void)
{
}

unsigned long CMapleStory::ReadPointer(unsigned long ulBase, int iOffset)
{
	if(*(int*)WallBasePtr)
	{
		__try { return *(unsigned long*)(*(unsigned long*)ulBase + iOffset); }
		__except (EXCEPTION_EXECUTE_HANDLER) { return -1; }
	}
	else return -1;
}

double CMapleStory::ReadDoublePointer(DWORD ulBase, INT iOffset)
{
      __try { return (*(DOUBLE*)(*(DWORD*)ulBase + iOffset)); }
      __except (EXCEPTION_EXECUTE_HANDLER) { return 0.0; }
}

bool CMapleStory::WritePointer(unsigned long ulBase, int iOffset, int iValue)
{
	__try
	{
		*(int*)(*(unsigned long*)ulBase + iOffset) = iValue;
		return true;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return false;
	}
}

bool CMapleStory::FindProcessWindow()
{
   TCHAR szBuffer[200];
   DWORD dwTemp;

   for (HWND hWnd = GetTopWindow(NULL); hWnd != NULL; hWnd = GetNextWindow(hWnd, GW_HWNDNEXT))
   {
      GetWindowThreadProcessId(hWnd, &dwTemp);

      if (dwTemp != GetCurrentProcessId())
      {
         continue;
      }

      if (!GetClassName(hWnd, szBuffer, sizeof(szBuffer) / sizeof(TCHAR)))
      {
         continue;
      }

      if (!wcscmp(szBuffer, L"MapleStoryClass"))
      {
		  MSHWND = hWnd;
         return true;
      }
   }

   return false;
}

int CMapleStory::getMobCount()
{
	return (int) ReadPointer(MobBasePtr, MobCountOffset);
}

int CMapleStory::getItemCount()
{
	return (int) ReadPointer(ItemBasePtr, ItemCountOffset);
}

int CMapleStory::getPeopleCount()
{
	return (int) ReadPointer(PeopleBasePtr, PeopleCountOffset);
}

int CMapleStory::getCharX()
{
	return (int) ReadPointer(CharBasePtr,XOffset);
}

int CMapleStory::getCharY()
{
	return (int) ReadPointer(CharBasePtr,XOffset + 4);
}

int CMapleStory::getCharHP()
{
	WritePointer(SettingsBasePtr, HPAlertOffset, 20);
	return (int) ReadPointer(StatsBasePtr, HPOffset);
}

int CMapleStory::getCharMP()
{
	WritePointer(SettingsBasePtr, MPAlertOffset, 20);
	return (int) ReadPointer(StatsBasePtr, MPOffset);
}

double CMapleStory::getCharEXP()
{
	return ReadDoublePointer(StatsBasePtr, EXPOffset);
}

int CMapleStory::getMapID()
{
	return (int) ReadPointer(InfoBasePtr, MapIDOffset);
}

int CMapleStory::getAttackCount()
{
	return (int) ReadPointer(CharBasePtr, AttackCountOffset);
}

int CMapleStory::getTubiValue()
{
	return (int) ReadPointer(ServerBasePtr, TubiOffset);
}

int CMapleStory::getBreathValue()
{
	return (int) ReadPointer(CharBasePtr, BreathOffset);
}

int CMapleStory::getChannel()
{
	return (int) ReadPointer(ServerBasePtr, ChannelOffset);
}

int CMapleStory::getCharpID()
{
	if(*(int*)WallBasePtr)	return (int) ReadPointer(CharBasePtr, pIDOffset);
	else return 0;
}

int CMapleStory::getKnockBack()
{
	if(*(int*)WallBasePtr)	return (int) ReadPointer(getCharpID(), KBOffset);
	else return 0;
}

int CMapleStory::getKnockBackX()
{
	if(*(int*)WallBasePtr)	return (int) ReadPointer(getCharpID(), KBXOffset);
	else return 0;
}

int CMapleStory::getKnockBackY()
{
	if(*(int*)WallBasePtr)	return (int) ReadPointer(getCharpID(), KBYOffset);
	else return 0;
}	

bool CMapleStory::isInGame()
{
	if(getMapID() > 0)	return true;
	return false;
}
