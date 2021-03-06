#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//A calculator of complex numbers
//A test of my ability to utilize functions
//this calculator can:Add, subtract, divide, multiply, find the length, and get new inputs
//Seven functions: Addition, subtraction, division, multiplications, length, inputs, and outputs


// prototypes go here

void input(double & real1, double & imag1);					//the prototypes of the all the functions used to calculate the numbers for this program
void output(double & real1, double & imag1);
void addition(double & real1, double & imag1, double real2, double imag2);
void subtraction(double & real1, double & imag1, double real2, double imag2);
void multiplication(double & real1, double & imag1, double real2, double imag2);
void division(double & real1, double & imag1, double real2, double imag2);
double length(double & rea1l, double & imag1);

int main(void){

	char choice;
	double A = 0;
	double B = 0;
	double C = 0;
	double D = 0;
	
	cout << "Welcome to the Complex Number Calculator!" << endl;	//the startup printout the lists the available operations to the user
	cout << "Here are your options: " << endl;
	cout << "+ (addition)" << endl;
	cout << "- (subtraction)" << endl;
	cout << "* (multiplication)" << endl;
	cout << "/ (division)" << endl;
	cout << "l (length)" << endl;
	cout << "i (new input)" << endl;
	cout << "q (quit)" << endl;
	
	while(choice != 'q'){				//switch statements that let the user decide which operations they want to employ
		cout << "Enter what you want to do: ";
		cin >> choice;
		
		switch(choice){
		
			case 'i':			//the input operation
				input(A,B);
				output(A,B);
				break;
				
			case '+':			//the addition operation
				input(C,D);
				addition(A,B,C,D);
				output(A,B);
				break;
			case '-':			//the subtraction operation
				input(C,D);
				subtraction(A,B,C,D);
				output(A,B);
				break;
			case '*':			//the multiplication operation
				input(C,D);
				multiplication(A,B,C,D);
				output(A,B);
				break;
			case '/':			//the division operation
				input(C,D);
				division(A,B,C,D);
				output(A,B);
				break;
			case 'l':			//the length operation
				cout << fixed << setprecision(2) << "The length is: " << length(A,B) << endl;
				output(A,B);
				break;
			case 'q':			//lets the user exit the calculator
				cout << "Thanks for using our calculator!" << endl;
				break;
				
			default:			//tells the user to input a valid operation choice
				cout << "Not a valid choice!" << endl;
				break;
		}
	}
return 0;
}
// function definitions

void input(double & real1, double & imag1){				//the input function
	cout << "Enter the real part" << endl;
	cin >> real1;
	cout << "Enter the imaginary part" << endl;
	cin >> imag1;
}

void output(double & real1, double & imag1){			//the output function
		
	if (imag1 < 0){
		cout << fixed << setprecision(2) << "Current value: " << real1 << " "<< imag1 << "i" << endl;			//outputs the number with a minus sign
	}
	else if (imag1 >= 0){
		cout << fixed << setprecision(2) << "Current value: " << real1 << " + " << imag1 << "i" << endl; //outputs the number with a plus sign
	}
	
}
void addition(double & real1, double & imag1, double real2, double imag2){		//the addition function
	real1 = real1 + real2;
	imag1 = imag1 + imag2;
}
void subtraction(double & real1, double & imag1, double real2, double imag2){		//the subtraction function
	real1 = real1 - real2;
	imag1 = imag1 - imag2;

}

void multiplication(double & real1, double & imag1, double real2, double imag2){	//the multiplication function
	double swapvar = real1;			//a new swapvariable is created and is set to real1 because the real1 variable is changed when the new real1 is recalculated
	real1 = (swapvar * real2) - (imag1 * imag2);
	imag1 = (swapvar * imag2) + (imag1 * real2);
}

void division(double & real1, double & imag1, double real2, double imag2){			//the division function
	double swapvar = real1;			//a new swapvariable is created and is set to real1 because the real1 variable is changed when the new real1 is recalculated
	real1 = (swapvar * real2 + imag1 * imag2) / (real2 * real2 + imag2 * imag2);
	imag1 = (imag1 * real2 - swapvar *  imag2) / (real2 * real2 + imag2 * imag2);
}

double length(double & real1, double & imag1){		//the length function
	return sqrt(real1 * real1 + imag1 * imag1);
}