#pragma once

#include <functional>
#include <map>
#include <vector>
#include <Windows.h>

#include "StopWatch.h"
#include "Lock.h"
#include "noncopyable.h"

namespace Macro
{
	class AbstractMacro : boost::noncopyable
	{
	public:
		AbstractMacro();
		AbstractMacro(unsigned int uDelay,int nValue,int nValueSecond,unsigned int uCoolDown);
		virtual ~AbstractMacro();

		virtual bool CheckCondition() = 0;
		virtual void ProcessMacro() = 0;

		bool Toggle(bool fStatus);
		bool Running();
		void SetDelay(unsigned int uDelay);
		void SetValue(int nValue);
		int GetValue();
		void SetSecondValue(int nValue);
		void SetCoolDown(unsigned int uCoolDown);
		void SetPriority(int nPriority);
		
		unsigned int GetCoolDown();

	protected:
		bool CheckTime();
		void UpdateTime();

		bool fMacroStatus;
		unsigned int uOldTicks,uDelay,uCoolDown;
		int nValue,nValueSecond,m_nPriority;
		
		StopWatch<milliseconds> m_stopWatch;
		
		friend class MacroManager;

	};

	class MacroManager : boost::noncopyable
	{
	public:
		MacroManager();
		~MacroManager();

		void AddMacro(int nIndex,AbstractMacro* macro);
		void RemoveMacro(int nIndex);
		void ClearMacros();
		void UpdateMacros();

		bool Start();//Async for Multi Thread
		bool Stop();//Async for Multi Thread

		void DoSome();//Synced for Single Thread
	private:

		static DWORD WINAPI MacroThread(LPVOID lpvParameter);

		std::map<int,AbstractMacro*> m_mMacro;
		std::vector<AbstractMacro*> m_vMacro;
		Lock m_lock;
		bool m_fRunning,m_fRun;
		unsigned int m_uCoolDown;
		StopWatch<milliseconds> m_stopWatch;
	};

}