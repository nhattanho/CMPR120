// Nhat Ho
// 04/08/2018
// HomeWork 06
// This program keeps track of the longest consecutive
// sequence of the same letter within those inputted.

#include<iostream>
#include<string>
using namespace std;

int main(void) 
{
	// To save the same letter which has a longest consecutive sequence
	// has been seen so far
	char oldInput = '\0';

	// To save the next letter which is different with the oldInput letter
	// has been seen so far
	char newInput = '\0';

	// A count of how many times the letter is repeated
	int countOld = 0; // for oldInput
	int countNew = 0; // for newInput

	while (true)
	{
		// 1 Handle the input

		// 1.1 Enter the input
		char userInput; // to save the current input
		cout << endl;
		cout << "Enter a letter, or '.' to quit: ";
		cin >> userInput;
		cin.ignore(999, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(999, '\n');
			cout << "Improper input value, try again." << endl;
			continue;
		}

		// 1.2 To check the input wheather it is letter or not
		bool checkLetter = (userInput >= 'a' && userInput <= 'z')
							|| (userInput >= 'A' && userInput <= 'Z');
		if (userInput == '.') // break the loop to go to end program
			break;
		if (checkLetter == false) // the input is not a letter
		{
			cout << "Improper input value, try again." << endl;
			continue;
		}

		// 2 Find the letter having the longest consecutive sequence
		if (checkLetter) // the input is a letter
		{
			// 2.1 Tracking the the same letter by counting the consecutive sequence of them
			if (oldInput == NULL)
			{
				oldInput = userInput; // for the first time when we enter the input
				countOld++;
			}
			else
			{
				if (newInput == userInput)
				{
					// In that case, we got a letter which have the same character as letter
					// that is different from the letter having a longest consecutive
					// sequence so far
					countNew++;
				}
				else if (oldInput == userInput)
				{
					// At this time, those inputs what we got are the same letter, so
					// we have just increase the count of this letter
					if (countNew == 0)
						countOld++;

					// Before we got current input, we had got the letter that is different
					// from the having a longest consecutive sequence so far (oldInput)
					// That's why we have to replace the newInput by adding current input
					// and counting again though it is equal the oldInput
					else
					{
						newInput = userInput;
						countNew = 1;
					}
				}
				// When the current input is different with the oldInput and current
				// newInput is empty, we set newInput by current input, and count again also
				else
				{
					newInput = userInput;
					countNew = 1;
				}
			}

			// 2.2 Get the letter having the longest consecutive consequence

			// countOld larger or equal than countNew, that means the letter which has
			// longest consecutive sequence is oldInput. If not, it will be newInput
			// So, we have to replace newInput for oldInput and reset newInput also
			if (countOld < countNew)
			{

				oldInput = newInput;
				countOld = countNew;
				newInput = '\0';
				countNew = 0;
			}

			// 2.3 Output the letter having the longest consecutive sequence
			if (countOld == 1)
				cout << "Longest sequence is " << countOld << ' ' << oldInput << '.' << endl;
			else
				cout << "Longest sequence is " << countOld << ' ' << oldInput << "'s." 
					 << endl;
			continue;
		}
	}

	// 3 End program
	return 0;

}