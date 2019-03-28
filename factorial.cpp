#include<iostream>
using namespace std;

void factorial(int num);

int main(){
	int number;
	
	cout << "Input a number to factorialize" << endl;
	cin >> number;
	cout << "Your number is: :" << factorial(number);

return 0;
}

void factorial(int num){
	if(num == 0 || num == 1){
		cout << "1";
	}
	else {
		cout << num << "*";
		num = num - 1;
		cout << factorial(num);
	}
}
