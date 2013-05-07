#pragma once
#include <Windows.h>
#include "MainForm.h"

using namespace WatyBotManager;

public ref class Tab : MainForm
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
