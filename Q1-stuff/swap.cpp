#include<iostream>
using namespace std;

void swapper(double & num1, double & num2);

int main (){
	double a, b;
	cout << "Enter your first number" << endl;
	cin >> a;
	cout << "Enter your second number" << endl;
	cin >> b;
	swapper(a, b);
	cout << "Your numbers are " << a << " " << b << endl;
	
	return 0;
}

void swapper(double & num1, double & num2) {
	double temp = num1;
	num1 = num2;
	num2 = temp;
		
}