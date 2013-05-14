#pragma once
#include "MacroManager.h"
#include "MapleStory.h"
#include <vcclr.h>

namespace Macro
{
	class BotMacro : public AbstractMacro
	{
	public:
		BotMacro(int nKey,unsigned int uDelay,unsigned int uCoolDown,std::function<bool()> fCondition) : AbstractMacro(uDelay,nKey,0,uCoolDown)
		{
			this->m_fCondition = fCondition;
			CMS = gcnew CMapleStory;
		}
		BotMacro(std::function<bool()> fCondition) : AbstractMacro()
		{
			this->m_fCondition = fCondition;
			this->fMacroStatus = false;
			CMS = gcnew CMapleStory;
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
			CMS->SpamKey(this->nValue);
			this->UpdateTime();
		}
	private:
		std::function<bool()> m_fCondition;
		gcroot<CMapleStory^> CMS;
	};
}
