// Nhat Ho
// 04/18/2018
// HomeWork 07
// This program tests integer to see if they are rising number
// and output the value of the next-larger rising number.

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

// Program-specific function prototypes
void getNextRisingNumberMultipleTimes(void);
void outputResults(bool risingStatus, int number, int nextRising);
bool risingNumber(int number); // Check the number if it is a rising number
int getNextRising(int number); // Get the rising number

// Tool function prototypes
int getInt(string prompt);
int width(int number); // Get the length of the number
bool getBool(string prompt);
char getChar(string prompt);

//////////////////// main /////////////////////

int main()
{
	getNextRisingNumberMultipleTimes();
	return 0;
}

//////////////////// program-specific functions /////////////////////

void getNextRisingNumberMultipleTimes(void)
{
	do
	{
		int number = getInt("Enter a value to be tested: ");
		bool risingStatus = risingNumber(number);
		int nextRising = getNextRising(number);
		outputResults(risingStatus, number, nextRising);
	} while (getBool("Do you want to test another number? "));
}

bool risingNumber(int number)
{
	bool firstGet = false; // There is no rightmost digit got from the number
	int previousDigit, rightmostDigit;
	if (number < 0) 
		number *= -1;
	while (number > 0)
	{
		rightmostDigit = number % 10;
		number /= 10;
		if ( !firstGet )
		{
			// Set up for the first rightmost digit 
			previousDigit = rightmostDigit;
			firstGet = true;
		}
		else
		{
			if ( rightmostDigit > previousDigit )
				return false;
			previousDigit = rightmostDigit;
		}
	}
	return true;
}

int getNextRising(int number)
{
	// Initialize neccesarry variable 
	int temp;
	int previous;
	int rightmost;
	bool rising;
	int sum;

	int widthNumber = width(number);
	//int length = widthNumber;
	while (widthNumber >= 1)
	{
		// Get the part of the number from the left to the right
		temp = number / (int)pow(10, widthNumber - 1);

		rising = risingNumber(temp);
		if ( rising == true )
		{
			previous = temp;
			widthNumber--;
			if ( widthNumber == 0 )
			{
				number += 1;
				rising = risingNumber(number);
				if ( rising == true )
					break;
				widthNumber = width(number); // widthNumber = length;
			}
			continue;
		}
		if ( number > 0 )
		{
			rightmost = previous % 10;
			sum = previous * (int)pow(10, widthNumber);
			for (int i = 0; i < widthNumber; i++)
			{
				sum += (rightmost * (int)pow(10, i));
			}
			number = sum;
		}
		else
		{
			do
			{
				previous++;
				rising = risingNumber(previous);
				if ( rising == true )
				{
					sum = previous * (int)pow(10, widthNumber);
					for (int i = 0; i < widthNumber; i++)
					{
						sum -= 9 * (int)pow(10, i);
					}
					number = sum;
					break;
				}
				else
				{
					previous = previous / 10;
					widthNumber++;
				}
			} while (true);
		}
		break;
	}
	return number;
}

///////////////////// tools /////////////////////////////////////

int getInt(string prompt)
{
	while (true)
	{
		int userAnswer;
		cout << prompt;
		cin >> userAnswer;
		cin.ignore(999, '\n');
		if ( !cin.fail() ) return userAnswer;
		cin.clear();
		cin.ignore(999, '\n');
		cout << "Input data format error. Try again." << endl;
	}
}

int width(int number)
{
	int digitCount = 0;
	do
	{
		number = number / 10;
		digitCount++;
	} while (number != 0);
	return digitCount;
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
		cout << "Please enter y or n!" << endl;
	}
}

char getChar(string prompt)
{
	while (true)
	{
		char userAnswer;
		cout << prompt;
		cin >> userAnswer;
		cin.ignore(999, '\n');
		if ( !cin.fail() ) return userAnswer;
		cin.clear();
		cin.ignore();
		cout << "Input failed, try again!" << endl;
	}
}

void outputResults(bool risingStatus, int number, int nextRising)
{
	cout << number << " is ";
	if ( risingStatus == false ) cout << "not ";
	cout << "rising." << endl;
	cout << "The next rising is " << nextRising << endl;
	cout << endl;
}

