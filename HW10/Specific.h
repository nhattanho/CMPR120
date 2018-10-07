#ifndef SPECIFIC_LOCK
#define SPECIFIC_LOCK

#include <fstream>
using namespace std;

namespace specific
{
	// Initialize the maximum of the length of array
	const int ARRAY_SIZE = 5000;

	void processFile(void);
	void openFileToRead(ifstream &in_stream);
	bool readFile(ifstream &in_stream, string lines[], int &size, int &maxLength);
	void openFileToWrite(ofstream &out_stream);
	void writeFile(ofstream &out_stream, string lines[], int &maxLength, int size);
	bool check_wordAlready(string lines[], string word, int size);
	bool insertWord(string lines[], int &size, string word);
}

#endif
