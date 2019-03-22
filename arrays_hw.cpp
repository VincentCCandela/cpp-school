#include<iostream>
#include<iomanip>
using namespace std;

//array of size 50
//fill array with random numbers from 1-100
//go through array and count the number of evens and the number of odds
//output the total number of each
int evens(a);
int odds(a);

int main(){
	srand(time(NULL));

	int grades[50];
	
	
	for (int i = 0; i < 50; i++){
		grades[i] = rand()%101;
		
		if((grades[i] % 2) == 0){
			evens++;
		}
		else{
			odds++
		}
	}
	cout << grades[i] << endl;
	cout << "The number of odds is
	/*for (int i = 0; i < 50; i++){
		if((grades[i] % 2) == 0){
			evens++;
		}
		
		else{
			odds++;
		}
	}*/


	return 0;
}


int evens(int & evens,int i){
	if((grades[i] % 2) == 0){
		evens++;
	}

}

int odds(int & odds, int i){

}
