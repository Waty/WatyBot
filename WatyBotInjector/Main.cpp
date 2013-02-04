#include "MyForm.h"
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <msclr\marshal_cppstd.h>

using namespace WatyBotInjector;
using namespace System;
using namespace System::IO;
using namespace System::Diagnostics;

void StartMapleStory()
{
	if(!File::Exists("MapleStory.exe"))
	{
		::MessageBox::Show("You haven't placed this program in you're minecraft folder!!!");
		exit(1);
	}

	ProcessStartInfo^ startInfo = gcnew ProcessStartInfo("MapleStory.exe");
	Process::Start(startInfo);
}

void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	StartMapleStory();
}


int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
	Application::Exit();
}