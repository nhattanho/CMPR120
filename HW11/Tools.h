// Tools.h

#ifndef TOOLS_LOCK
#define TOOLS_LOCK

#include<string>
using namespace std;

namespace tools
{
	string getLine(string prompt);
	char getChar(string prompt);
	bool getBool(string prompt);
	void flush(void);
}

#endif