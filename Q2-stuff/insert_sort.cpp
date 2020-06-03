#include<iostream>
#include<iomanip>
using namespace std;

const int size = 20;

void inserter (int arrary[]);
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
	
	
	inserter(grades);
	
	cout << "Our sorted array is: " << endl;

	for (int i = 0; i < size ; i++){
		cout << grades[i] << endl;
		
	}


	return 0;
}

void inserter (int array[]){
	for(int i = 0; i < size; i++){
		int j = i;
		while((j > 0) && (array[j - 1] > array[j])){
			swap(array[j],array[j - 1]);
			j = j - 1;
		}
	}
}

void swap(int & a, int & b){
	int tempvar = a;
	a = b;
	b = tempvar;
}