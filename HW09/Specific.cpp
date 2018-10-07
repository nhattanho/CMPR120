#include "Tools.h"
#include "Specific.h"
#include <fstream>
#include <iostream>
using namespace std;

namespace specific
{
	void processFile(void)
	{
		do
		{
			// Initialize the count of vowels
			int countA = 0, countE = 0, countI = 0, countO = 0, countU = 0;

			ifstream in_stream;
			get_OpenFile(in_stream);
			bool read = readFile(in_stream, countA, countE, countI, countO, countU);
			if (read == true)
			{
				in_stream.close();
				printChart(countA, countE, countI, countO, countU);
			}
		} while (tools::getBool("Do you want to process another round of text? "));
	}

	void get_OpenFile(ifstream &in_stream)
	{
		while (true)
		{
			string fileName = tools::getString("Enter the file to read: ");
			in_stream.open(fileName);
			if (in_stream.fail())
			{
				cout << "Error Opening file, please try again." << endl;
				continue;
			}
			break;
		}
	}

	bool readFile(ifstream &in_stream, int &countA, int &countE, int &countI, int &countO, int &countU)
	{
		char s;
		// Assume in the first time file can be read successfully
		bool read = true;

		while (true)
		{
			in_stream >> s;
			if (in_stream.fail())
			{
				// Reading file completely
				if (in_stream.eof()) break;

				// Having problem when read file
				read = false;
				cout << "Read failed." << endl;
				in_stream.clear();
				in_stream.ignore(999, '\n');
				break;
			}
			checkVowels(s, countA, countE, countI, countO, countU);
		}
		return read;
	}

	void checkVowels(char s, int &countA, int &countE, int &countI, int &countO, int &countU)
	{
		switch (s)
		{
		case 'a':
		case 'A':
			countA++;
			break;
		case 'e':
		case 'E':
			countE++;
			break;
		case 'i':
		case 'I':
			countI++;
			break;
		case 'o':
		case 'O':
			countO++;
			break;
		case 'u':
		case 'U':
			countU++;
			break;
		}
	}

	void printChart(int countA, int countE, int countI, int countO, int countU)
	{
		cout << endl;
		cout << "Vowel statistics:" << endl;
		cout << "a - ";
		for (int i = 0; i < countA; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "e - ";
		for (int i = 0; i < countE; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "i - ";
		for (int i = 0; i < countI; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "o - ";
		for (int i = 0; i < countO; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << "u - ";
		for (int i = 0; i < countU; i++)
		{
			cout << "*";
		}
		cout << endl;
		cout << endl;
	}
}