#include<iostream>
using namespace std;

int exponent(int num, int pow);

int main(){
	
	int number, power;
	
	cout << "Input a number and then input a power to raise the number" << endl;
	cin >> number;
	cin >> power;
	
	cout << "The result is: " << exponent(number, power) << endl;
	
	return 0;
}

int exponent(int num, int pow){
	
	if (pow == 1)
		return num;
	else{
	return num * exponent(num, pow - 1);	
	}
}
