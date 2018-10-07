// Tools.h

#ifndef TOOLS_LOCK
#define TOOLS_LOCK

#include<string>
using namespace std;

namespace tools
{
	string getString(string prompt);
	void flush(void);
	bool getBool(string prompt);
	char getChar(string prompt);
	bool fexists(const string filename);
}

#endif