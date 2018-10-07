// Nhat Ho
// 02/26/2018
// Homework 2
// This program produces a form letter.

#include<iostream>
#include<string>
using namespace std;

int main()
{
    //////////////////////////////////////////////////////////
    // 1 The way to enter the input
    cout << "Please enter the following words" << endl;
    cout << "If more than one word is requested, separate them by spaces" << endl;
    cout << endl;
    
    // 2 Enter input
    
    // Enter your name
    cout << "Your name: ";
    string yourName;
    cin >> yourName;
    cin.ignore(999,'\n'); // clear garbage left by input
    
    // Enter name of the three people - 3 words
    cout << "Name of three people: ";
    string nameFirst, nameSecond, nameThird;
    cin >> nameFirst >> nameSecond >> nameThird;
    cin.ignore(999,'\n'); // clear garbage left by input
    
    // Enter a event
    cout << "A event: ";
    string event;
    cin >> event;
    cin.ignore(999,'\n'); // clear garbage left by input
    
    // Enter a location
    cout << "A location: ";
    string location;
    cin >> location;
    cin.ignore(999,'\n'); // clear garbage left by input
    
    //Enter a holiday
    cout << "A holiday: ";
    string holiday;
    cin >> holiday;
    cin.ignore(999,'\n'); // clear garbage left by input
    
    // Enter a date
    // Example: Fri, 02 Feb 2018 or 2/26/2018
    cout << "A date: ";
    string date;
    getline(cin, date);
    
    //Enter a positive emotion
    cout << "A positive emotion: ";
    string emotion;
    cin >> emotion;
    cin.ignore(999,'\n'); // clear garbage left by input
    
    // 3 Output 
    
    // Output to ask user press ENTER to see the form letter
    cout << "Are you want to see your form letter? Press ENTER to continue ..." << endl;
    cin.ignore(999,'\n'); // pause - wait for ENTER
    
    // Output the form letter
    cout << "Dear " << nameFirst << "," << endl << endl;
    cout << "As we discussed yesterday, we will have a " << event << " at " << location << " for " << holiday << " day"<< endl;
    cout << "on " << date << ". " << "So i have attached a plan for us in this email." << endl;
    cout << "Please also help me forward it to " << nameSecond << " and " << nameThird << ". Hopefully," << endl;
    cout << "you will " << emotion << " with it." << endl;
    cout << "Anyway, do not hesitate to contact me. Have a nice day!" << endl << endl;
    cout << "Thanks and Best Regards," << endl;
    cout << yourName << endl;
    
    // 4 Shutdown the program
    cout << endl;
    cout << "Press ENTER to finish...";
    cin.ignore(999,'\n'); // pause - wait for ENTER
    return 0;
}



