#pragma once
using namespace System;
using namespace System::IO;

public ref class Log sealed
{
public:
	static void WriteLine(String^ Message);
	static String^ Path = Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData), "Waty", "log.txt");
};
