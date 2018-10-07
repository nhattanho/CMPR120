// Nhat Ho
// 03/08/2018
// HomeWork 4
// This program prints out the status of student's grade.

#include<iostream>
#include<string>
using namespace std;

const int MIN_RANGE = 0;
const int MAX_RANGE = 100;
const int MIN_FOR_PASS = 50;
const int MIN_AVERAGE_FOR_PASS = 60;
const int MIN_FOR_PASS_RESERVATION = 20;
const int MIN_AVERAGE_FOR_PASS_RESERVATION = 45;

int main(void)
{
	// 1 General instruction
	cout << "Please enter three test scores in the range [0..100]." << endl;
	cout << "Separate them by spaces." << endl;
	cout << endl;

	// 2 Enter input

	// 2.1 Enter input three scores
	int firstScore, secondScore, thirdScore;
	cout << "Enter three scores: ";
	cin >> firstScore >> secondScore >> thirdScore;
	cin.ignore(999, '\n');

	// 2.2 Check if the input are not numeric format
	if ( cin.fail() )
	{
		cin.clear();
		cin.ignore(999, '\n');
		cout << endl;
		cout << "Error: Improper numeric format." << endl;
		cout << "Press Enter to terminate..." << endl;
		cin.ignore(999, '\n');
		return 1;
	}

	// 2.3 Check if the input out of range 
	if ( firstScore < MIN_RANGE || firstScore > MAX_RANGE || secondScore < MIN_RANGE
		|| secondScore > MAX_RANGE || thirdScore < MIN_RANGE || thirdScore > MAX_RANGE )
	{
		cout << endl;
		cout << "Error: Data value out of range." << endl;
		cout << "Press Enter to terminate..." << endl;
		cin.ignore(999, '\n');
		return 1;
	}

	// 3 Caculate the avarage score
	int averageScore;
	averageScore = (firstScore + secondScore + thirdScore) / 3;

	// 4 Get result of grade
	string grade;
	grade = "Fail";
	if ( firstScore >= MIN_FOR_PASS && secondScore >= MIN_FOR_PASS
		&& thirdScore >= MIN_FOR_PASS && averageScore >= MIN_AVERAGE_FOR_PASS )
	{
		grade = "Pass";
	}
	else if ( firstScore >= MIN_FOR_PASS_RESERVATION
			 && secondScore >= MIN_FOR_PASS_RESERVATION
			 && thirdScore >= MIN_FOR_PASS_RESERVATION
			 && averageScore >= MIN_AVERAGE_FOR_PASS_RESERVATION )
	{
		if ( firstScore >= MIN_FOR_PASS || secondScore >= MIN_FOR_PASS
			|| thirdScore >= MIN_FOR_PASS )
		{
			grade = "Pass With Reservations";
		}
	}

	// 5 Output the result of grade
	cout << "The result of Grade: " << grade << endl;

	// 6 End stuff
	cout << endl;
	cout << "Press ENTER to finish...";
	cin.ignore(999, '\n');
	return 0;
}