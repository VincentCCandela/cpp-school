#include<iostream>
#include<iomanip>
using namespace std;

const int size = 20;

void bubbler (int arrary[]);

int main() {
	srand(time(NULL));
	
	int grades[size]
	
	cout << "The grades of the function are: ";

	for (int i = 0; i < size ; i++){
		grades[i] = rand() % 100 + 1
		cout << grades[i] << endl;
		
	}

	cout << endl;

	return 0;
}