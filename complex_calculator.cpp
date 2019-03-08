#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//A calculator of complex numbers
//A test of my ability to utilize functions
//this calculator can:Add, subtract, divide, multiply, find the length, and get new inputs
//Seven functions: Addition, subtraction, division, multiplications, length, inputs, and outputs


// prototypes go here
int main(void){
	char choice;
	double A = 0;
	double B = 0;
	double C = 0;
	double D = 0;
	cout << "Welcome to the Complex Number Calculator!" << endl;
	cout << "Here are your options: " << endl;
	cout << "+ (addition)" << endl;
	cout << "- (subtraction)" << endl;
	cout << "* (multiplication)" << endl;
	cout << "/ (division)" << endl;
	cout << "l (length)" << endl;
	cout << "i (new input)" << endl;
	cout << "q (quit)" << endl;
	while(choice != 'q'){
		cout << "Enter what you want to do: ";
		cin >> choice;
		switch(choice){
			case 'i':
			break;
			case '+':
			break;
	// complete rest of cases here
			case 'q':
			cout << "Thanks for using our 
			calculator!" << endl;
			break;
			default:
			cout << "Not a valid choice!" << endl;
			break;
		}
	}
return 0;
}
// function definitions