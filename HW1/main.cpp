//===============================================================
// Nhat Ho
// CMPR 120
// Example 01 - My First Program
// This program outputs an excerpt from poem
//===============================================================

#include <iostream>
using namespace std;

int main() {
	// READ THIS!!!!!!!!
	// input and process below should not actually be in this
	// program
	// output would be #1
	// no boxes for input/process in the structure chart

	// 1 Input
	// nothing to do here yet...

	// 2 process
	// nothing to do here yet...

	// 3.1 output the poem's title and author
	cout << "An excerpt from The 'Farewell'" << endl;
	cout << "by Aleksandr Pushkin" << endl;
	cout << endl;

	// 3.2 output an excerpt
	cout << endl;
	cout << "It’s the last time, when I dare" << endl;
	cout << endl;
	cout << "To cradle your image in my mind," << endl;
	cout << endl;
	cout << "To wake a dream by my heart, bare," << endl;
	cout << endl;
	cout << "With exultation, shy and air," << endl;
	cout << endl;
	cout << "To cue your love that's left behind." << endl;
	cout << endl;

	// 3.3 output my name
	cout << endl;
	cout << "Programmed by Nhat Ho." << endl;

	// 4 shut down
	cout << endl;
	cout << "Press ENTER to finish...";
	cout << endl;
	cout << "> ";
	cin.ignore(999,'\n');
	return 0;
}
