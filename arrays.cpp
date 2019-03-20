#include<iostream>
using namespace std;
int main(){
	const int size = 20;

	double gpas[size] = {3.4,34,456,235,4357,1234,3546,4321335};
	cout << "gpas[1] is: " << gpas[1] << endl;
	
	for (int i = 0; i < size ;i++){
		cout << "Student " << i + 1 << " has the grade of: " << gpas[i] << endl;
	}
	
	
	
	return 0;
}