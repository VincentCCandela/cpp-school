#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//A calculator of complex numbers
//A test of my ability to utilize functions
//this calculator can:Add, subtract, divide, multiply, find the length, and get new inputs
//Seven functions: Addition, subtraction, division, multiplications, length, inputs, and outputs


// prototypes go here

void input(double & real, double & imag);
void output(double & real, double & imag);
void addition(double & real1, double & imag1, double real2, double imag2);
void subtraction(double & real1, double & imag1, double real2, double imag2);

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
				input(A,B);
				output(A,B);
				break;
				
			case '+':
				input(C,D);
				addition(A,B,C,D);
				output(A,B);
				break;
			case '-':
				input(C,D);
				subtraction(A,B,C,D);
				output(A,B);
				break;
				
	// complete rest of cases here
	
			case 'q':
				cout << "Thanks for using our calculator!" << endl;
				break;
				
			default:
				cout << "Not a valid choice!" << endl;
				break;
		}
	}
return 0;
}
// function definitions

void input(double & real, double & imag){
	cout << "Enter the real number" << endl;
	cin >> real;
	cout << "Enter the imaginary number" << endl;
	cin >> imag;
}

void output(double & real, double & imag){
	cout << real << " + " << imag << "i" << endl;	
	
}
void addition(double & real1, double & imag1, double real2, double imag2){
	real1 = real1 + real2;
	imag1 = imag1 + imag2;
}
void subtraction(double & real1, double & imag1, double real2, double imag2){
	real1 = real1 - real2;
	imag1 = imag1 - imag2;

}










