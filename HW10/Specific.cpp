#include "Specific.h"
#include "Tools.h"
#include <fstream>
#include <iostream>
using namespace std;

namespace specific
{
	void processFile(void)
	{
		//Initialize variable
		int size = 0;
		int maxLength = 0;

		ifstream in_stream;
		ofstream out_stream;
		string lines[ARRAY_SIZE];
		do
		{
			cout << endl;
			openFileToRead(in_stream);
			bool read = readFile(in_stream, lines, size, maxLength);
			if (read)
			{
				openFileToWrite(out_stream);
				writeFile(out_stream, lines, maxLength, size);
			}
		} while (tools::getBool("Do you want to process another file? "));
	}

	void openFileToRead(ifstream &in_stream)
	{
		while (true)
		{
			string fileName = tools::getString("Enter name of text file to read: ");
			in_stream.open(fileName);
			if (!in_stream.fail()) break;
			cout << "Error Opening file, please try again." << endl;
		}
	}

	bool readFile(ifstream &in_stream, string lines[], int &size, int &maxLength)
	{
		string word;
		// Initialize variable
		bool read = true;
		while (true)
		{
			in_stream >> word;
			if (!in_stream.fail())
			{
				bool sameWord = check_wordAlready(lines, word, size);
				if (!sameWord)
				{
					read = insertWord(lines, size, word);
					if (!read) break;
					if ((int)word.length() > maxLength)
						maxLength = word.length();
				}
				continue;
			}
			// Reading file completely
			if (in_stream.eof())
			{
				in_stream.close();
				break;
			}
			// Having problem when read file
			cout << "Read failed." << endl;
			in_stream.clear();
			in_stream.ignore(999, '\n');
			in_stream.close();
			read = false;
			break;
		}
		return read;
	}

	void openFileToWrite(ofstream &out_stream)
	{
		while (true)
		{
			string fileName = tools::getString("Enter name of file for word information: ");
			if (tools::fexists(fileName))
			{
				cout << "You are trying to modify the exist file! " << endl;
				if (!(tools::getBool("Do you want to continue? (y or n) "))) continue;
			}
			out_stream.open(fileName);
			if (!out_stream.fail()) break;
			cout << "Error Opening file, please try again." << endl;
		}
	}

	void writeFile(ofstream &out_stream, string lines[], int &maxLength, int size)
	{
		for (int i = 1; i <= maxLength; i++)
		{
			out_stream << "Words of length " << i << ":" << endl;
			for (int j = 0; j < size; j++)
			{
				if (lines[j].length() == i) out_stream << lines[j] << " ";
			}
			out_stream << endl;
		}
		out_stream.close();
	}

	bool insertWord(string lines[], int &size, string word)
	{
		if (size == ARRAY_SIZE)
		{
			cout << "Don't have enough space to store words read from file!" << endl;
			cout << endl;
			return false;
		}
		lines[size++] = word;
		return true;
	}

	bool check_wordAlready(string lines[], string word, int size)
	{
		for (int i = 0; i < size; i++)
		{
			if (word == lines[i]) return true;
		}
		return false;
	}
}