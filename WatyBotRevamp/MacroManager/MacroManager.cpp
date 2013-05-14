#include "MacroManager.h"

#include "BotMacro.h"
#include "FunctionalMacro.h"

#include <algorithm>

using namespace Macro;


//AbstractMacro

AbstractMacro::AbstractMacro()
{
	this->nValue = 0;
	this->nValueSecond = 0;
	this->uCoolDown = 0;
	this->fMacroStatus = false;
	this->m_stopWatch.SetDelay(milliseconds(0));
}
AbstractMacro::AbstractMacro(unsigned int uDelay,int nValue,int nValueSecond,unsigned int uCoolDown)
{
	this->nValue = nValue;
	this->nValueSecond = nValueSecond;
	this->uCoolDown = uCoolDown;
	this->fMacroStatus = false;
	this->m_stopWatch.SetDelay(milliseconds(uDelay));
}
AbstractMacro::~AbstractMacro()
{

}

bool AbstractMacro::Toggle(bool fStatus)
{
	this->m_stopWatch.Start();
	this->fMacroStatus = fStatus;
	return true;
}
bool AbstractMacro::Running()
{
	return this->fMacroStatus;
}
void AbstractMacro::SetDelay(unsigned int uDelay)
{
	this->m_stopWatch.SetDelay(milliseconds(uDelay));
}
int AbstractMacro::GetValue()
{
	return nValue;
}
void AbstractMacro::SetValue(int nValue)
{
	this->nValue = nValue;
}
void AbstractMacro::SetSecondValue(int nValue)
{
	this->nValueSecond = nValue;
}
void AbstractMacro::SetCoolDown(unsigned int uCoolDown)
{
	this->uCoolDown = uCoolDown;
}
void AbstractMacro::SetPriority(int nPriority)
{
	this->m_nPriority = nPriority;
}
unsigned int AbstractMacro::GetCoolDown()
{
	return this->uCoolDown;
}

bool AbstractMacro::CheckTime()
{
	return this->m_stopWatch.IsOver();
}

void AbstractMacro::UpdateTime()
{
	this->m_stopWatch.Start();
}

MacroManager::MacroManager()
{
	this->m_fRun = false;
	this->m_fRunning = false;
}
MacroManager::~MacroManager()
{
	this->Stop();
}

void MacroManager::AddMacro(int nIndex,AbstractMacro* macro)
{
	Scoped_Lock(this->m_lock);
	this->m_mMacro[nIndex] = macro;
	this->m_vMacro.push_back(macro);
	std::sort(this->m_vMacro.begin(),this->m_vMacro.end(),
		[&](AbstractMacro* mFirst,AbstractMacro* mSecond){ return mFirst->m_nPriority < mSecond->m_nPriority; });
}
void MacroManager::RemoveMacro(int nIndex)
{
	Scoped_Lock scopedLock(this->m_lock);

	AbstractMacro* pMacro = this->m_mMacro[nIndex];

	if(pMacro == NULL)
		return;//Macro doesn't exist invalid index or something different

	this->m_mMacro.erase(nIndex);

	int nCounter = 0;
	bool fFound = false;
	std::vector<AbstractMacro*>::iterator it = std::find(this->m_vMacro.begin(),this->m_vMacro.end(),pMacro);

	if(it != this->m_vMacro.end())//If Vector contains the macro
		this->m_vMacro.erase(it);

	delete pMacro;//Memory managment is done here
}
void MacroManager::ClearMacros()
{
	Scoped_Lock scopedLock(this->m_lock);
	for(AbstractMacro* m : this->m_vMacro)
		delete m;

	this->m_vMacro.clear();
	this->m_mMacro.clear();
}
void MacroManager::UpdateMacros()
{
	Scoped_Lock scopedLock(this->m_lock);
	for(AbstractMacro* m : this->m_vMacro)
		m->UpdateTime();
}

bool MacroManager::Start()
{
	if(this->m_fRunning)
		return false;

	this->m_fRun = true;

	return CreateThread(NULL,0,
		reinterpret_cast<LPTHREAD_START_ROUTINE>(MacroManager::MacroThread),
		this,0,NULL) != NULL;
}
bool MacroManager::Stop()
{
	if(!this->m_fRunning)
		return false;

	this->m_fRun = false;

	return true;
}

DWORD MacroManager::MacroThread(LPVOID lpvParameter)
{
	if(!lpvParameter)
		return 0;

	MacroManager* pManager = reinterpret_cast<MacroManager*>(lpvParameter);

	pManager->m_fRunning = true;


	pManager->m_lock.LockSection();

	for(AbstractMacro* m : pManager->m_vMacro)
	{
		m->UpdateTime();
	}

	pManager->m_lock.UnlockSection();

	while(pManager->m_fRun)
	{
		pManager->m_lock.LockSection();

		for(AbstractMacro* m : pManager->m_vMacro)
		{
			if(!pManager->m_stopWatch.IsOver())
			{
				if(m->m_nPriority != 3)
					continue;
			}

			if(m->CheckCondition())
			{
				m->ProcessMacro();
				pManager->m_stopWatch.SetDelay(milliseconds(m->GetCoolDown()));
			    pManager->m_stopWatch.Start();
				break;
			}
		}
		pManager->m_lock.UnlockSection();
		Sleep(10);
	}

	pManager->m_fRunning = false;

	return 1;
}

void MacroManager::DoSome()
{
	for(AbstractMacro* m : this->m_vMacro)
	{
		if(!this->m_stopWatch.IsOver())
		{
			if(m->m_nPriority != 3)
				continue;
		}

		if(m->CheckCondition())
		{
			m->ProcessMacro();
			this->m_stopWatch.SetDelay(milliseconds(m->GetCoolDown()));
			this->m_stopWatch.Start();
			break;
		}
	}
}
