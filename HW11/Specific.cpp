//Specific.cpp

#include "Specific.h"
#include "Tools.h"
#include <iostream>
#include <string>
#include<vector>
using namespace std;

namespace specific
{
	void processLine(void)
	{
		vector<string> wordComplete;
		do
		{
			string line = tools::getLine("Enter words on a line: ");
			getWords(line, wordComplete);
			printWords(wordComplete);
		} while (tools::getBool("Do you want to process another line? "));
	}

	void getWords(string line, vector<string> &wordComplete)
	{
		// Initialize the variable 
		string word = " ";
		for (int i = 0; i < (int)line.length(); i++)
		{
			if (line[i] != ' ')
			{
				word += line[i];
				if (i == line.length() - 1) 
					wordComplete.push_back(word);
			}
			else
			{
				if (word != " ")
				{
					wordComplete.push_back(word);
					// Reset variable to save new word for the next time
					word = " ";
				}
			}
		}
	}

	void printWords(vector<string> &wordComplete)
	{
		for (vector<string>::size_type index = 0; index < wordComplete.size(); ++index)
			cout << wordComplete[index] << endl;
		wordComplete.clear();
		cout << endl;
	}
}