#pragma once
#include "MacroManager.h"
extern HWND MapleStoryHWND;
#define SpamKey(KeyPress) PostMessage(MapleStoryHWND, WM_KEYDOWN, KeyPress, (MapVirtualKey(KeyPress, 0) << 16) + 1); PostMessage(MapleStoryHWND, WM_KEYUP, KeyPress, (MapVirtualKey(KeyPress, 0) << 16) + 1);

namespace Macro
{
	class BotMacro : public AbstractMacro
	{
	public:
		BotMacro(int nKey,unsigned int uDelay,unsigned int uCoolDown,std::function<bool()> fCondition) : AbstractMacro(uDelay,nKey,0,uCoolDown)
		{
			this->m_fCondition = fCondition;
		}
		BotMacro(std::function<bool()> fCondition) : AbstractMacro()
		{
			this->m_fCondition = fCondition;
			this->fMacroStatus = false;
		}
		~BotMacro()
		{

		}

		bool CheckCondition()
		{
			return this->CheckTime() && this->fMacroStatus && m_fCondition();
		}
		void ProcessMacro()
		{
			SpamKey(this->nValue);
			this->UpdateTime();
		}
	private:
		std::function<bool()> m_fCondition;
	};
}