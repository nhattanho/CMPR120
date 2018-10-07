// Nhat Ho
// 03/24/2018
// HomeWork 05
// This program calculates the charge for babysitting.

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

const int TIME_STARTED = 1800;
const int TIME_ENDED = 2400;
const int TIME_CHANGE_SHIFT = 2130;
const int HOURS_OF_TIME_CHANGE = 21;
const int MINUTES_OF_TIME_CHANGE = 30;
const int MINUTES_PER_HOUR = 60;
const int CHARGE_FOR_FIRST_SHIFT = 2;
const int CHARGE_FOR_SECOND_SHIFT = 4;
const float CHARGE_TO_ROUND = 0.3f;

// when comparing floating point values whether
// they equal or not, we need a small epsilon
// value that defines a tolerance.
const float epsilon = 0.0000001f;

int main(void)
{
	// 1 Enter the input

	// 1.1 Enter the started time
	int startTime;
	int minutesStart;
	int hoursStart;
	while (true)
	{
		cout << "Enter military time when the service started: ";
		cin >> startTime;
		cin.ignore(999, '\n');
		if ( cin.fail() )
		{
			cin.clear();
			cin.ignore(999, '\n');
			cout << "Error: Non-numeric input. Try Again." << endl;
			continue;
		}
		else if ( startTime < TIME_STARTED )
		{
			cout << "Start time out of range. Try Again." << endl;
			continue;
		}
		else if ( startTime >= TIME_ENDED )
		{
			cout << "Start time out of range. Try Again." << endl;
			continue;
		}
		else
		{
			minutesStart = startTime % 100;
			if ( minutesStart >= MINUTES_PER_HOUR )
			{
				cout << "Minutes out of range. Try Again." << endl;
				continue;
			}
			hoursStart = startTime / 100;
			break;
		}
	}

	// 1.2 Enter the ended time
	int endTime;
	int minutesEnd;
	int hoursEnd;
	while (true)
	{
		cout << "Enter military time when the service ended: ";
		cin >> endTime;
		cin.ignore(999, '\n');
		if ( cin.fail() )
		{
			cin.clear();
			cin.ignore(999, '\n');
			cout << "Error: Non-numeric input. Try Again." << endl;
			continue;
		}
		else if ( endTime <= TIME_STARTED )
		{
			cout << "End time out of range. Try Again." << endl;
			continue;
		}
		else if ( endTime > TIME_ENDED )
		{
			cout << "End time out of range. Try Again." << endl;
			continue;
		}
		else if ( endTime <= startTime )
		{
			cout << "End time out of range. Try Again." << endl;
			continue;
		}
		else
		{
			minutesEnd = endTime % 100;
			if ( minutesEnd >= MINUTES_PER_HOUR )
			{
				cout << "Minutes out of range. Try Again." << endl;
				continue;
			}
			hoursEnd = endTime / 100;
			break;
		}
	}

	// 2 Calculate charge

	// These varible were used for two cases: whole time for work
	// which are in [1800 - 2130] or [2130 - 2400].
	float hoursWork = (float)(hoursEnd - hoursStart);
	float minutesWork = (float)(minutesEnd - minutesStart);
	float total_hoursWork = hoursWork + (minutesWork / MINUTES_PER_HOUR);
	float totalCharge;

	if ( endTime <= TIME_CHANGE_SHIFT )
	{	
		totalCharge = total_hoursWork * CHARGE_FOR_FIRST_SHIFT;
	}
	else if ( startTime >= TIME_CHANGE_SHIFT )
	{
		totalCharge = total_hoursWork * CHARGE_FOR_SECOND_SHIFT;
	}
	else
	{
		// This part used in case the whole time for work are
		// in both [1800 - 2130] and [2130 - 2400].

		// Calculating the charge for the time in [1800 - 2130]. 
		float hours_firstShift
			= (float)(HOURS_OF_TIME_CHANGE - hoursStart);
		float minutes_firstShift
			= (float)(MINUTES_OF_TIME_CHANGE - minutesStart);
		float totalHours_firstShift
			= hours_firstShift + (minutes_firstShift / MINUTES_PER_HOUR);
		float charge_firstShift
			= totalHours_firstShift * CHARGE_FOR_FIRST_SHIFT;

		// Calculating the charge for the time in [2130 - 2400].
		float hours_secondShift
			= (float)(hoursEnd - HOURS_OF_TIME_CHANGE);
		float minutes_secondShift
			= (float)(minutesEnd - MINUTES_OF_TIME_CHANGE);
		float totalHours_secondShift
			= hours_secondShift + (minutes_secondShift / MINUTES_PER_HOUR);
		float charge_secondShift
			= totalHours_secondShift * CHARGE_FOR_SECOND_SHIFT;

		// Get the total charge for this case.
		totalCharge = charge_firstShift + charge_secondShift;
	}

	// 3 Make totalCharge round
	int intPart_totalCharge
		= (int)totalCharge; // get integer part of total charge
	float decimaPart_totalCharge
		= totalCharge - intPart_totalCharge; // get decimal part of total charge
	
	// Using fabs function to get absolute float number.
	// It is defined in <cmath> header file.
	if ( fabs(decimaPart_totalCharge - CHARGE_TO_ROUND) <= epsilon )
	{
		// when 2 float numbers are equal, the total charge is rounded 
		// up to the next whole dollar.
		totalCharge = (float)(intPart_totalCharge + 1);
	}
	else if ( decimaPart_totalCharge > CHARGE_TO_ROUND )
	{
		totalCharge = (float)(intPart_totalCharge + 1);
	}
	else
	{
		totalCharge = (float)intPart_totalCharge;
	}

	// 4 Out put the total charge
	cout << endl;
	cout << "The total charge is: $" << totalCharge << "." << endl;

	// 5 End program
	cout << endl;
	cout << "Press ENTER to finish..." << endl;
	cin.ignore(999, '\n');
	return 0;
}