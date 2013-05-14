#pragma once
#include "MacroManager.h"
extern void AutoSkill(int KeyCodeIndex);

namespace Macro
{
	class SkillMacro : public AbstractMacro
	{
	public:
		SkillMacro(unsigned int uDelay, unsigned int uCoolDown, int KeyIndex) : AbstractMacro(uDelay,0,0,uCoolDown)
		{
			iKeyIndex = KeyIndex;	
		}
		SkillMacro() : AbstractMacro()
		{
		
		}
		~SkillMacro()
		{

		}

		void SetKeyIndex(int index)
		{
			iKeyIndex = index;
		}

		bool CheckCondition()
		{
			return this->CheckTime() && this->fMacroStatus;
		}
		void ProcessMacro()
		{
			AutoSkill(iKeyIndex);
			this->UpdateTime();
		}
	private:
		int iKeyIndex;
	};
}
