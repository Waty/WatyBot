#include "MyForm.h"
#include "Memory.h"
#include <Windows.h>

using namespace CCPLZBirthday;

#define CodeCave(name) void __declspec(naked) Cave##name(){_asm
#define EndCodeCave }

int keys[] = {VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6, VK_F7, VK_F8, VK_F9, VK_F10, VK_F11, VK_F12};

BYTE bSit[] = {0x75};
CMemory cmSitHack(0xC84331, bSit, 1);

DWORD dwMouseFlyRet = 0xCD1B39 + 5;
DWORD dwMouseFlyCall1 = 0xD115D0;
DWORD dwMouseFlyCall2 = 0x407920;

CodeCave(MouseFly)
{
	call dwMouseFlyCall1
	pushad
	//looking for the mouse click
	mov ebx, [0x1402540]
	mov ebx, [ebx]
	//MouseClick fly, but mouseanioffset is wrong :(
	cmp dword ptr[ebx+0x9DC], 0x0C
	jne FlyExit

	//get mouselocation
	mov ebx,[ebx+0x978]
	mov eax,[ebx+0x8C]
	mov ebx,[ebx+0x90]

	//encrypt and set teleoffsets
	lea ecx,[esi+0x7B28]
	push eax
	call dwMouseFlyCall2
	lea ecx, [esi+0x7B1C]
	push ebx
	call dwMouseFlyCall2
	lea ecx, [esi+0x7B04]
	push 00000001 //Probably dont need all the proceeding 0's but wthell
	call dwMouseFlyCall2

	FlyExit:
	popad
	jmp dwMouseFlyRet

}
EndCodeCave
CMemory cmMouseFly(0xCD1B39, CaveMouseFly, 0, true);

void Main(void)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	Application::Exit();
}

Void MyForm::bHack_Click(System::Object^  sender, System::EventArgs^  e)
{
	Toggle();
}

Void MyForm::sithackTimer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	static int timer = 0;
	timer++;
	if(Enabled && timer >= 5)
	{
		timer = 0;
		cmSitHack.Enable(!cmSitHack.Enabled);
	}
	if(ddbHotkey->SelectedIndex > -1)
	{
		if(GetAsyncKeyState(keys[ddbHotkey->SelectedIndex])) Toggle();
	}
}

Void MyForm::Toggle()
{
	Enabled = !Enabled;
	this->bHack->Text = Enabled ? "Turn off Hacks" : "Turn on Hacks";
	cmSitHack.Enable(Enabled);
	cmMouseFly.Enable(Enabled);
}
