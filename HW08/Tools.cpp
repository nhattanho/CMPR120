#include"Tools.h"
#include<iostream>
#include<string>
using namespace std;
namespace tools
{
	int getOption(string prompt)
	{
		int option;
		while (true)
		{
			cout << endl;
			option = getInt(prompt);
			if (option < 0 || option > 10)
			{
				cout << "Value must be in [0..10]. Try again." << endl;
			}
			else if (option == 0)
			{
				introductionPrint();
			}
			else
				return option;
		}
	}

	int getSize(string prompt)
	{
		int size;
		while (true)
		{
			size = getInt(prompt);
			if (size <= 0 || size > 75)
			{
				cout << "Value must be in [1..75]. Try again." << endl;
				continue;
			}
			return size;

		}
	}

	void introductionPrint(void)
	{
		cout << endl;
		cout << "Choices are:" << endl;
		cout << "1 Square" << endl;
		cout << "2 Triangle with right angle pointing southwest" << endl;
		cout << "3 Triangle with right angle pointing southeast" << endl;
		cout << "4 Triangle with right angle pointing northwest" << endl;
		cout << "5 Triangle with right angle pointing northeast" << endl;
		cout << "6 Triangle with right angle pointing north" << endl;
		cout << "7 Triangle with right angle pointing east" << endl;
		cout << "8 Triangle with right angle pointing west" << endl;
		cout << "9 Triangle with right angle pointing south" << endl;
		cout << "10 Circle" << endl;
	}

	int getInt(string prompt)
	{
		int option;
		while (true)
		{
			cout << prompt;
			cin >> option;
			clearGarbage();
			if (!cin.fail())
				return option;
			cin.clear();
			clearGarbage();
			cout << "Input data format error. Try again." << endl;
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
			cout << "Input failed. Try again." << endl;
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
			cout << "please enter y or n. Try again." << endl;
		}
	}

	void clearGarbage(void)
	{
		cin.ignore(999, '\n');
	}
}