#include<iostream>
#include<iomanip>
using namespace std;

//This program:
//creates an array of size 50,
//fills the array with random numbers from 1-100.
//goes through the array and counts the number of evens and the number of odds
//then outputs the total number of odds and evens.

int main(){
	srand(time(NULL)); //seed for random numbers is set to random

	int grades[50],evens,odds,i; //array of numbers, and variables for the number of even numbers in the array, the number of odd numbers in the array, and a variable for the iteration in a for loop are declared.
	
	
	for (i = 0; i < 50; i++){ //a for loop to generate each of the 50 random numbers of the array and check if each of those numbers is odd or even, and lastly to report the sign of each number for a total count of even and odd numbers
		
		grades[i] = rand()%101; //generator for the random numbers
		cout << grades[i] << endl; // outputs each random number
		
		if((grades[i] % 2) == 0){ //checks and reports the signs of each of the numbers
			evens++; //if the number is even, the the even counter is increased by one
		}
		else{
			odds++; //if the number is odd, the the odd counter is increased by one
		}
	}
	
	cout << "The number of odds is " << odds << endl; //reports the total number of odd numbers
	cout << "The number of evens is " << evens << endl; // reports the total number of even numberes
	
	return 0;
}