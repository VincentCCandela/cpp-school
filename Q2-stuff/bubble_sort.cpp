#include<iostream>
#include<iomanip>
using namespace std;

const int size = 20;

void bubbler (int arrary[]);
void swap(int & a, int & b);

int main() {
	srand(time(NULL));
	
	int grades[size];
	
	cout << "The grades of the function are: " << endl;

	for (int i = 0; i < size ; i++){
		grades[i] = rand() % 100 + 1;
		cout << grades[i] << endl;
		
	}
	
	cout << endl;
	
	
	bubbler(grades);
	
	cout << "Our sorted array is: " << endl;

	for (int i = 0; i < size ; i++){
		cout << grades[i] << endl;
		
	}


	return 0;
}

void bubbler (int array[]){
	bool swapped = true;
	
	while (swapped == true){
		swapped = false;
		
		for (int i = 0; i < size - 1; i++){
			if (array[i] > array[i + 1]){
				swap(array[i], array[i + 1]);
				swapped = true;
			}
		}
	}

}

void swap(int & a, int & b){
	int tempvar = a;
	a = b;
	b = tempvar;
}