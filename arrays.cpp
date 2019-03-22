#include<iostream>
#include<iomanip>

using namespace std;

int main(){
	srand(time(NULL));

	int array_size;
	cout << "Enter the array size" << endl;
	cin >> array_size;
	
	const int size = array_size;
	int grades[size];
	
	for (int i = 0; i < size; i++){
		grades[i] = rand()%101;
		cout << grades[i] << endl;
	}
	
	int num, order;
	char choice;
	
	cout << "How many items should go into the menu?" << endl;
	cin >> num;
	
	const int sise = num;
	
	string menu[sise];
	
	cout << "Enter the items you want on the menu!" << endl;
	
	for (int i = 0; i < sise; i++){
		cin >> menu[i];
	}
	
	cout << "Here is your newly created menu" << endl;
	
	for (int i = 0; i < sise; i++){
		cout << i+1 << ")" << menu[i] << endl;
	}
		
	cout << "Would you like to order something off your menu? (y/n)" << endl;
	cin >> choice;
	
	if (choice == 'n' || choice == 'N'){
		cout << "No more food for you!" << endl;
	}
	else{
		cout << "Which item will you like to get? (1-" << sise << ")" << endl;
		cin >> order;
		
		cout << endl;
		cout << "I hope you enjoy your " << menu[order - 1] << "!" << endl;
	}
	
	cout << "Thank you and come again!" << endl;
		
	return 0;
}