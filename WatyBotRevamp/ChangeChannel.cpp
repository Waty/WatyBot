#include "ChangeChannel.h"
#include "PacketSender.h"
#include "Hacks.h"
#include "StopWatch.h"

using namespace WatyBotRevamp;
using namespace System;

void TryCC(int channel);
extern StopWatch<milliseconds> BreathCounter;

Void CC::CCSwitch(CCType type)
{
	if(IsBusy) return;
	String^ strError = String::Empty;
	switch(type)
	{
	case CCType::CC:
		Hacks::ThreadIdFix.Enable(true);
		bw->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(&CC::doCC);
		bw->RunWorkerAsync();
		break;

	case CCType::CS:
		bw->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(&CC::doCS);
		bw->RunWorkerAsync();
		break;

	case CCType::DC:
		bw->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(&CC::doDC);
		bw->RunWorkerAsync();
		break;
	}
}

//Generate a random int to CC to + check if it is a different channel
Void CC::GenerateRandomChannel()
{
	do
	{
		srand (GetCurrentTime());
		TargetChannel = rand() %14;
	}		
	while(TargetChannel == StartChannel);
}

Void CC::doCC(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	if(!CMS::InGame)
	{
		e->Cancel;
		return;
	}
	
	//Store the currrent Channel
	StartChannel = CMS::Channel;

	GenerateRandomChannel();

	//Sleep while breath > 0
	while(!BreathCounter.IsOver()) Sleep(100);
	CMS::Breath = 0;
	
	int i = 0;
	while(CMS::Channel != TargetChannel && CMS::Channel != -1)
	{
		//if the CC didn't happen after trying 10 times, Generate new random channel
		if(i > 10) GenerateRandomChannel();

		//Send the CC request
		TryCC(TargetChannel);
		Sleep(1000);
		i++;
	}
}

Void CC::doCS(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	if(!CMS::InGame) e->Cancel;
	while(!BreathCounter.IsOver()) Sleep(100);
	Sleep(500);
	CMS::Breath = 0;
	String^ strError = String::Empty;
	PacketSender::Send(EnterCashShop, strError);
	Sleep(2500);
	PacketSender::Send(LeaveCashShop, strError);
	Sleep(3000);
}

Void CC::doDC(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	while(CMS::InGame)
	{
		String^ strError = String::Empty;
		PacketSender::Send(ChangeCharacter, strError);
		Sleep(2500);
	}
}
