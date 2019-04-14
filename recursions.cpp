#include<iostream>
using namespace std;

int exponent(int base, int pow);

int main(){
	
	int the_base, power;
	
	cout << "Input a number and then input a power to raise the number" << endl;
	cin >> the_base;
	cin >> power;
	
	cout << "The result is: " << exponent(the_base, power) << endl;
	
	return 0;
}

int exponent(int base, int pow){
	
	if (pow == 1)
		return base;
	else{
		return base * exponent(base, pow - 1);	
	}
}
