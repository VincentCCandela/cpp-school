#include<iostream>
#include<iomanip>

using namespace std;

int main(){
	srand(time(NULL));

	const int size = 20;
	int grades[size];
	
	for (int i = 0; i < size; i++){
		grades[i] = rand()%101;
		cout << grades[i] << endl;
	}
	
	//double gpas[size] = {3.4,34,456,235,4357,1234,3546,4321335};
	//cout << "gpas[1] is: " << gpas[1] << endl;
	//
	//for (int i = 0; i < size ;i++){
	//	cout << "Student " << i + 1 << " has the grade of: " << gpas[i] << endl;
	//}
	
	
	
	return 0;
}