#include"Tools.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

namespace tools
{
	bool fexists(const string filename)
	{
		ifstream ifile(filename);
		return ifile.good();
	}

	string getString(string prompt)
	{
		while (true)
		{
			string userAnswer;
			cout << prompt;
			cin >> userAnswer;
			flush();
			if (!cin.fail()) return userAnswer;
			cin.clear();
			cin.ignore();
			cout << "Input failed, try again" << endl;
		}
	}

	char getChar(string prompt)
	{
		while (true)
		{
			char userAnswer;
			cout << prompt;
			cin >> userAnswer;
			flush();
			if (!cin.fail()) return userAnswer;
			cin.clear();
			cin.ignore();
			cout << "Input failed, try again" << endl;
		}
	}

	bool getBool(string prompt)
	{
		while (true)
		{
			switch (getChar(prompt))
			{
			case 'Y': case 'y': return true;
			case 'N': case 'n': return false;
			}
			cout << "please enter y or n" << endl;
		}
	}

	void flush(void)
	{
		cin.ignore(999, '\n');
	}
}