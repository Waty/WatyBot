#pragma once
using namespace System;
using namespace System::IO;

public ref class Log sealed
{
public:
	static Void WriteLine(String^ Message);
	static Void WriteLine();
	static String^ Path = Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData), "Waty", "log.txt");
};
