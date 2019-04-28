#include<iostream>
#include<cmath>
using namespace std;

void change(double & num);
void changer(double num,double & dub, double & half); 

int main (){

	double a;
	double d,h;
	
	cout << "Enter a number you wish to change." << endl;
	cin >> a;
	change(a);
	cout << "Your number is now: " << a << endl;
	changer(a)
	cout << "Your number is now: " << dub << half << endl;


	return 0;
}

void change(double & num){
	num = (fmod(num,13)+74)/60*17;
}

void changer(double num){
	dub = num*2;
	half = num/2;
} 
