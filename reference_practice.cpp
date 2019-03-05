#include<iostream>
#include<cmath>
using namespace std;

void change(double & num);

int main (){

	double a;
	
	cout << "Enter a number you wish to change." << endl;
	cin >> a;
	change(a);
	
	cout << "Your number is now: " << a << endl;


	return 0;
}

void change(double & num){
	num = (fmod(num,13)+74)/60*17;
}