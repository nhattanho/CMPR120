// Tools.cpp

#include "Tools.h"
#include <string>
#include <iostream>
using namespace std;

namespace tools
{
	string getLine(string prompt)
	{
		while (true)
		{
			string userAnswer;
			cout << prompt;
			getline(cin, userAnswer);
			if (!cin.fail()) return userAnswer;
			cin.clear();
			cin.ignore(); // get rid of what killed it
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