#pragma once
#include <Windows.h>

using namespace System::IO;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Diagnostics;

ref class Tab
{
public:
	Tab(HWND hPanelMS, HWND hPanelWatyBot);
	void Stop();
	~Tab(void);

private:
	void Embed(HWND child, HWND newParent);
	bool inject(DWORD pID);
	HWND FindProcessWindow(int pID);
	HWND FindWatyBotHWND(int pID);

	Process^ procMS;
};

