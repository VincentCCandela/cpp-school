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
	
		
	cout << "How many items should go into the menu?" << endl;
	cin >> num;
	
	const int sise = num;
	
	string menu[sise];
	
	cout << "Enter the items you want on the menu!" << endl;
		
	return 0;
}