//pseudocode for the factorial function

/*
integer function taking one unsigned integer parameter {
	if the inputed parameter is equal to zero or one{
		return one
	}
	else{
		return multiply the number by a call to the function and input into the the function the number minus one
	} 
}
*/

//actual code for the factorial program:

#include<iostream>
using namespace std;

int factorial(int number);

int main(){
	int num;
	
	cout << "Input a number to factorialize" << endl;
	cin >> num;
	cout << "Your number is: " << factorial(num) << endl;

return 0;
}

int factorial(int number){
	if(number == 0 || number == 1){
		return 1;
	}
	else {
		return number * factorial(number - 1);
	}
}
