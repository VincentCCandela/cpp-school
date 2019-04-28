#include<iostream>
using namespace std;

int add(int num1, int num2, int num3);
double add(double num1, double num2);

int main (){
	//functions that have the same return type and name but with different parameters (can have different numbers of parameters and (or) different types of variables in the parameters)
	//cout << "Input three integers or 2 double floating point numbers" << endl;

	cout << add(10,2,11) << endl; // The one with two parameters will be called because of two parameters are supplied
	
	return 0;
}

int add(int num1, int num2, int num3){
	//int return_value = num1 + num2 + num3;
	return num1 + num2 + num3;

}
double add(double num1, double num2){

	return num1 + num2;

}
