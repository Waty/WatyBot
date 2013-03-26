#pragma once
#include "MacroManager.h"

namespace Macro
{
	class FunctionalMacro : public AbstractMacro
	{
	public:
		FunctionalMacro(unsigned int uDelay,unsigned int uCoolDown,std::function<bool()> fCondition,std::function<void()> fProcess) : AbstractMacro(uDelay,0,0,uCoolDown)
		{
			this->m_fCondition = fCondition;
			this->m_fProcess = fProcess;
		}
		~FunctionalMacro()
		{

		}

		bool CheckCondition()
		{
			return this->CheckTime() && this->fMacroStatus && m_fCondition();
		}
		void ProcessMacro()
		{
			m_fProcess();
			this->UpdateTime();
		}
	private:
		std::function<bool()> m_fCondition;
		std::function<void()> m_fProcess;
	};
}