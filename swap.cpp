#include<iostream>
using namespace std;

void swapper(double & num1, double & num2, double & temp);

int main ()
{
	double num1, num2, temp = 0;
	cout << "Enter your first number" << endl;
	cin >> num1;
	cout << "Enter your second number" << endl;
	cin >> num2;
	swapper(num1, num2, temp);
	cout << "Your numbers are " << num1 << " " << num2 << endl;
	
	return 0;
}

void swapper(double & num1, double & num2, double & temp) 
{
	temp = num1;
	num1 = num2;
	num2 = temp;
		
}