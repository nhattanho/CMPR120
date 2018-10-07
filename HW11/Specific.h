//Specific.h

#ifndef SPECIFIC_LOCK
#define SPECIFIC_LOCK

#include <vector>
#include <string>
using namespace std;

namespace specific
{
	void processLine(void);
	void getWords(string line, vector<string> &wordComplete);
	void printWords(vector<string> &wordComplete);
}

#endif 