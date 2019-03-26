#include<iostream>
using namespace std;

const int size = 5;

void array_add(int array1[], int array2[], int total[]);

int main(){

	
	int a1[size] = {212, 12312, 234234, 234234, 234234};
	int a2[size] = {12341234,12341234,12341234,12341234,12343};
	int t[size] = {0}; //fills entire array with zeroes
	
	array_add(a1, a2, t);
	
	cout << "The total number in the arrays is: " << endl;
	
	for (int i = 0; i < size; i++){
		cout << t[i] << endl;
	}
	
	return 0;
}

void array_add(int array1[], int array2[], int total[]){
	for(int i = 0; i < size; i++){
		total[i] = array1[i] + array2[i];
		cout <<  total[i] << endl;
	}
}
	