#include<iostream>
using namespace std;
int main (){
	//functions that have the same return type and name but with different parameters (can have different numbers of parameters and (or) different types of variables in the parameters)
	
	int add(int num1, int num2, int num3);
	int add(double num1, double num2);
	
	cout << add(10.2,2.5) << endl; // The one with two parameters will be called because of two parameters are supplied
	
	return 0;
	
}