#include <fstream>

#ifndef SPECIFIC_LOCK
#define SPECIFIC_LOCK

using namespace std;

namespace specific
{
	void processFile(void);
	void get_OpenFile(ifstream &in_stream);
	bool readFile(ifstream &in_stream, int &countA, int &countE,
				 int &countI, int &countO, int &countU);
	void checkVowels(char s, int &countA, int &countE, int &countI,
					int &countO, int &countU);
	void printChart(int countA, int countE, int countI, int countO, int countU);
}

#endif