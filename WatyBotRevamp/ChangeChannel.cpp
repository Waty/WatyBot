#include "ChangeChannel.h"
#include "Packet.h"
#include <Windows.h>
using namespace CC;
using namespace System;

CChangeChannel::CChangeChannel()
{
	bw = gcnew System::ComponentModel::BackgroundWorker;
}

void CChangeChannel::CCSwitch(CCType type)
{
	String^ strError = String::Empty;
	switch(type)
	{
	case CCType::CC:
		bw->DoWork += gcnew ComponentModel::DoWorkEventHandler(this, &CChangeChannel::CC);
		bw->RunWorkerAsync();
		break;

	case CCType::CS:
		bw->DoWork += gcnew ComponentModel::DoWorkEventHandler(this, &CChangeChannel::CS);
		bw->RunWorkerAsync();
		break;

	case CCType::DC:
		bw->DoWork += gcnew ComponentModel::DoWorkEventHandler(this, &CChangeChannel::DC);
		bw->RunWorkerAsync();
		break;
	}
}

void CChangeChannel::CC(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	if(!InGame()) e->Cancel;
	if(UsingPvP) Sleep(5500);
	while(getBreathValue() != 0) Sleep(100);
	CurrentChannel = getChannel();
	
	srand (GetCurrentTime());
	int channel = rand()%14;
	while(channel == CurrentChannel){srand (GetCurrentTime()); channel = rand()%14;}
	DestinationChannel = channel;
	CField_SendTransferChannelRequest(DestinationChannel);
	while(!InGame()) Sleep(100);
}

void CChangeChannel::CS(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	if(!InGame()) e->Cancel;
	if(UsingPvP) Sleep(5500);
	while(getBreathValue() != 0) Sleep(100);
	String^ strError = String::Empty;
	Send(EnterhCasShop, strError);
	while(InGame()) Sleep(100);
	Sleep(1000);
	while(!InGame())
		Send(LeaveCashShop, strError);
	Sleep(1000);
}

void CChangeChannel::DC(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	while(InGame())
	{
		Packets::CPackets^ p = gcnew Packets::CPackets;
		String^ strError = String::Empty;
		p->Send(ChangeCharacter, strError);
		Sleep(1000);
	}
}

/*
enum class CCReturns {Succes, Breath, Death};
CCReturns CCReturn;
#define CCSuccesAddy 0x005688ED
#define CCBreathAddy 0x00568955
#define CCDeathAddy 0x005689CF

VOID WINAPI SetCCSucces(){ CCReturn = CCReturns::Succes; ShowInfo("Succes!"); };
CodeCave(CCHookSucces)
{
	call SetCCSucces
	add esp,0x20
	ret 0004
}
EndCodeCave
CMemory cmCCHookSucces(CCSuccesAddy - 3, CaveCCHookSucces, 1, true);

VOID WINAPI SetCCBreath(){ CCReturn = CCReturns::Breath; ShowInfo("No Breath!"); };
CodeCave(CCHookBreath)
{
	call SetCCBreath
	add esp,0x20
	ret 0004
}
EndCodeCave
CMemory cmCCHookBreath(CCBreathAddy - 3, CaveCCHookBreath, 1, true);

VOID WINAPI SetCCDeath(){ CCReturn = CCReturns::Death; ShowInfo("You're dead...."); };
CodeCave(CCHookDeath)
{
	call SetCCDeath
	add esp,0x20
	ret 0004
}
EndCodeCave
CMemory cmCCHookDeath(CCDeathAddy - 3, CaveCCHookDeath, 1, true);
*/
