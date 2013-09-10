#include "Log.h"

Void Log::WriteLine(String^ Message)
{
	StreamWriter^ sw;
	try
	{
		sw = gcnew StreamWriter(Path, true);
		if (Message == String::Empty) sw->WriteLine();
		else sw->WriteLine(DateTime::Now.ToString() + ": " + Message);
	}
	catch (Exception^)
	{
		// Can't log here :(
	}
	finally
	{
		if (sw) delete (IDisposable^) sw;
	}
}

Void Log::WriteLine()
{
	WriteLine(String::Empty);
}
