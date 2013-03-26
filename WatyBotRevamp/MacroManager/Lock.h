#pragma once

#include <Windows.h>

#include "noncopyable.h"

class Lock : boost::noncopyable
{
public:
	Lock()
	{
		InitializeCriticalSection(&this->m_criticalSection);
	}
	~Lock()
	{
		DeleteCriticalSection(&this->m_criticalSection);
	}

	void LockSection()
	{
		EnterCriticalSection(&this->m_criticalSection);
	}
	void UnlockSection()
	{
		LeaveCriticalSection(&this->m_criticalSection);
	}

private:
	CRITICAL_SECTION m_criticalSection;
};

class Scoped_Lock : boost::noncopyable
{
public:
	Scoped_Lock(Lock &lock)
	{
		this->m_pLock = &lock;
		lock.LockSection();
	}
	~Scoped_Lock()
	{
		this->m_pLock->UnlockSection();
	}
private:
	Lock* m_pLock;
};