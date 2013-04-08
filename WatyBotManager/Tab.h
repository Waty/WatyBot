#pragma once
#include <Windows.h>
#include "MainForm.h"

using namespace WatyBotManager;

extern string dllloc;
extern string msloc;

public ref class Tab
{
public:
	Tab(TabPage^ , Panel^, Panel^);
	void Stop();
	~Tab(void);

private:
	void Embed(HWND child, HWND newParent);
	bool inject(DWORD pID);
	HWND FindProcessWindow(int pID);
	HWND FindWatyBotHWND(int pID);

	Process^ procMS;
	TabPage^ tabPage;
	Panel^ pMS;
	Panel^ pWatyBot;
};
