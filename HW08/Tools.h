#include<string>

#ifndef TOOLS_LOCK
#define TOOLS_LOCK

using namespace std;

namespace tools {
	void introductionPrint(void);
	int getInt(string prompt);
	int getOption(string prompt);
	int getSize(string prompt);
	bool getBool(string prompt);
	char getChar(string prompt);
	void clearGarbage(void);
}
#endif
