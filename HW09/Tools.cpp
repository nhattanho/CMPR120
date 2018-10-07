#include "Tools.h"
#include <string>
#include <iostream>
using namespace std;

namespace tools
{
	string getString(string prompt)
	{
		while (true)
		{
			string userAnswer;
			cout << prompt;
			cin >> userAnswer;
			clearGarbage();
			if (!cin.fail()) return userAnswer;
			cin.clear();
			clearGarbage();
			cout << "Input failed, try again" << endl;
			clearGarbage();
		}
	}

	char getChar(string prompt)
	{
		while (true)
		{
			char userAnswer;
			cout << prompt;
			cin >> userAnswer;
			clearGarbage();
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
			cout << "Please enter y or n" << endl;
		}
	}

	void clearGarbage(void)
	{
		cin.ignore(999, '\n');
	}
}