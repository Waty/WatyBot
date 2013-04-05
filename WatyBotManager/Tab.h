#pragma once
#include <Windows.h>
#include "MainForm.h"
using namespace WatyBotManager;

using namespace System::IO;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics;

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
