// Nhat Ho
// 03/06/2018
// HomeWork 3 - Calculations
// This program produces a bill for a repair service.

#include <iostream>
using namespace std;

const float TAX_CHARGE = 0.0825f;
const float LABOR_CHARGE_FOR_EACH_MINUTE = 1.5f;

int main(void)
{
	// 1 Input parameters

	// 1.1 Input the parts cost
	float parts_Cost;
	cout << "Enter the parts cost: ";
	cin >> parts_Cost;
	cin.ignore(999, '\n');
	if ( cin.fail() )
	{
		cin.clear();
		cin.ignore(999, '\n');
		cout << "The input is inappropriate, it should be a float format." << endl;
		cout << "Press ENTER to terminate..." << endl;
		cin.ignore(999, '\n');
		return 1;
	}

	// 1.2 Input the minutes of labor
	float minutesOf_Labor;
	cout << "Enter the minutes of labor for the repair: ";
	cin >> minutesOf_Labor;
	cin.ignore(999, '\n');
	if ( cin.fail() )
	{
		cin.clear();
		cin.ignore(999, '\n');
		cout << "The input is inappropriate, it should be a float format." << endl;
		cout << "Press ENTER to terminate..." << endl;
		cin.ignore(999, '\n');
		return 1;
	}

	// 2 Calculate the final bill

	// 2.1 Calculate the total labor charge for the repair service
	float totalLabor_Charge;
	totalLabor_Charge = LABOR_CHARGE_FOR_EACH_MINUTE * minutesOf_Labor;

	// 2.2 Calculate the repair charge
	float repair_Charge;
	repair_Charge = parts_Cost + totalLabor_Charge;

	// 2.3 Get the value of the subtotal charge
	float subtotal_Charge;
	if ( repair_Charge <= 95 )
		subtotal_Charge = 95;
	else
		subtotal_Charge = repair_Charge;

	// 2.4 Calculate the tax charge
	float tax_Charge;
	tax_Charge = TAX_CHARGE * subtotal_Charge;

	// 2.5 Calculate the final bill
	float final_Bill;
	final_Bill = subtotal_Charge + tax_Charge;

	// 3 Output the final bill
	cout << endl;
	cout.setf(ios::fixed); // fixed-point: no exponent
	cout.setf(ios::showpoint); // show a decimal point
	cout.precision(2); // 2 digit to right of decimal point
	cout << "Bill for a repair service: " << final_Bill << "$" << endl;

	// 4 End stuff
	cout << endl;
	cout << "Press ENTER to finish...";
	cin.ignore(999, '\n');
	return 0;

}
