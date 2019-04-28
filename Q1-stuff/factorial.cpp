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
