#include<iostream>
#include<iomanip>
using namespace std;

//This program:
//1 Creates an array of size 10 and fills it with random numbers from 0-100 and outputs the array.
//2 Asks the user to input a multiplier.
//3 Uses a function that takes the existing array and changes the entire array using the multiplier.
//4 Outputs the new multiplied array

void multiplicationer(int the_multiplier,int the_array[]); // the function that multiplies the multiple to each of the numbers in the array

int main(){
	srand(time(NULL)); //sets the seed for the random number generator to random
	int the_array[10], multiplier; //declares the array and the multiplier
	
	for(int i = 0; i < 10; i++){	//sets and outputs each of the ten numbers in the array
		the_array[i] = rand() % 101;	//sets a random 0-100 number in the array
		cout << "Place " << i << " of the old array is: " << the_array[i] << endl; //outputs one of the numbers
	}

	cout << "Input a multiplier: "; //asks to input a multiplier
	cin >> multiplier;	//inputs the multiplier

	multiplicationer(multiplier, the_array);	//calls the function that multiplies the multiplier to each of the numbers in the array

 return 0;
 }
 
void multiplicationer(int the_multiplier,int the_array[]){	//the function that multiplies the multiplier to each of the numbers in the array
	for(int i = 0; i < 10; i++){	//multiples the multiplier to each of the numbers in the array and outputs each of those numbers
		the_array[i] = the_array[i] * the_multiplier;
		cout << "Place " << i << " of the new array is: " << the_array[i] << endl;
	}
}
