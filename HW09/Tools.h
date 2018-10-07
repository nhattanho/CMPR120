#include <string>

#ifndef TOOLS_LOCK
#define TOOLS_LOCK

using namespace std;

namespace tools
{
	string getString(string prompt);
	char getChar(string prompt);
	bool getBool(string prompt);
	void clearGarbage(void);
}

#endif