#include<iostream>
#include<iomanip>
#include <algorithm>
using namespace std;

//This is a simpler/lower version of yahtzee


bool three_of_a_kind(int array[]); //a function to determine if a three of a kind has been rolled
bool four_of_a_kind(int array[]);	//a function to determine if a four of a kind has been rolled
bool full_house(int array[]);	//a function to determine if a full house has been rolled
int small_straight(int array[], int place, int iteration);	//a function to determine if a small straight has been rolled
int large_straight(int array[], int place, int iteration);	//a function to determine if a large straight has been rolled
bool yahtzee(int array[]);	//a function to determine if a yahtzee has been rolled
int totaller(int array[]);	//adds up all the numbers in the dice

void inserter(int arrary[]);	//makes the dice go in ascending order
//void cleaner(int array[]);		//removes double integers in an array
void swap(int & a, int & b);	//swaps two integers

const int size = 5; //sets the number of the array of the dice to five

int main(){
	srand(time(NULL));	//sets the seed for the random number generator to random
	
	char response = 'y';	//declares the response variable to whether the player wants to play and intializes it to 'y' so that the player may play
	
	while( response == 'y' || response == 'Y'){	//while the response variable is 'Y' or 'y', which the indicates the player wants to play, the main loop of the program will run 
		cout << "Do you want to role the dice? (y/n)" << endl;	//asks if the player wants to play
		cin >> response;	//inputs the player's response to whether or not they want to play
		
		int dice[size],total_points; //declares the array for the dice and the variable for the total number of points the player has amassed
		
		cout << " *Rolls dice* " << endl;	//mentions that the dice have been rolled
		cout << "You have rolled: ";	//The first part of the statement of the number's of the dice rolled, the actual nubmers are outputted in a later for loop
		
		for (int i = 0; i < size ; i++){	//a for loop which creates each of the random numbers of the array of dice and outputs each of them
			dice[i] = rand() % 6 + 1;	
			cout << dice[i];		
		}
		
		cout << endl;	//skips a line for clarity of each play
		
		inserter(dice);	//uses the inserter program to realign the dice from least to greatest
		
		cout << "Your sorted dice are: ";	//the first part of the statement of what the realigned dice are
		
		for (int i = 0; i < size ; i++){	//outputs each of the realigned dice
			cout << dice[i];		
		}
		
		cout << endl;	//skips a line 

		if(yahtzee(dice) == true){	//checks if the player has rolled a yahtzee, if they have, the player is informed of their roll and the points they've earned
			cout << "You have rolled a yahtzee! +50 points!" << endl;
			total_points = total_points + 50;
		}
		else if(four_of_a_kind(dice) == true){	//checks if the player has rolled a four of a kind, if they have, the player is informed of their roll and the points they've earned
			cout << "You have rolled a four of a kind. +30 points!" << endl; 
			total_points = total_points + 30;
		}
		else if (full_house(dice) == true){	//checks if the player has rolled a full house, if they have, the player if informed of their roll and the points they've earned
			cout << "You have rolled a full house. +25 points!" << endl;
			total_points = total_points + 25;
		}
		else if (three_of_a_kind(dice) == true){	//checks if the player has rolled a three of a kind, if they have, the player is informed of their roll and the points they've earned
			cout << "You have rolled a three of a kind. +20 points!" << endl;
			total_points = total_points + 20;
		}
		
		//array<int,5> dice1 = dice;
		//int dice1[size];
		
		//for(int i = 0; i < size; i++){
		
		//cleaner(dice1);
		
		else if(large_straight(dice, 0, 0) == 1){	//checks if the player has rolled a large straight, if they have, the player is informed of their roll and the points they've earned
			cout << "You have rolled a large straight. +40 points!" << endl;
			total_points = total_points + 40;
		}
		else if(small_straight(dice, 0, 0) == 1 || small_straight(dice, 1, 0) == 1 ){	//checks if the player has rolled a small straight, if they have, the player is informed of their roll and the points they've earned
			cout << "You have rolled a small straight. + 30 points!" << endl;
			total_points = total_points + 30;
		}
		else {	//if the player hasn't rolled anything useful, the player is informed of their roll and their score is the sum of the numbers that they've rolled
			cout << "You have rolled nothing." << endl;
			cout << "Chance for " << totaller(dice) << " points." << endl;
			total_points = total_points + totaller(dice);
		}
		
		cout << "You have: " << total_points << " points in total." << endl;	//outputs the player's total points 		
		cout << endl;	//and skips a line before restarting the while loop
	}
	
	cout << "Thanks for playing!" << endl;	//if the player has exited the while loop by responding with a 'n' in the while loop, the player is thanked for playing
	return 0;
}

bool three_of_a_kind(int array[]){	//a function to check if the dice array is a three of a kind
	if (array[0] == array[2] || array[1] == array[3] || array[2] == array[4]){	//if the first and third numbers are the same, then the second number must be the same since the array is in ascending order.
		return true;
	}
	else{
		return false;
	}
}

bool four_of_a_kind(int array[]){	//checks if the player has rolled a four of a kind
	if (array[0] == array[3] || array[1] == array[4]){	//if the first and fourth numbers are the same, then the second and third numbers must be the same since the array is in ascending order.
		return true;
	}
	else{
		return false;
	}
}

bool yahtzee(int array[]){	//checks if the player has rolled a yahtzee
	if (array[0] == array[4]){	//if the first and last numbers are the same, because the numbers are in asceind order, then all the numbers in between will be equal to the checked endpoints
		return true;
	}
	else{
		return false;
	}
}

int totaller(int array[]){	//adds up all the numbers in the array
	return array[0] + array[1] + array[2] + array[3] + array[4];
}

bool full_house(int array[]){	//checks if the player has scored a full house: if the first two and second three numbers or the first three and second two numbers are the same, then the player has scored a full house
	if((array[0] == array[1] && array[2] == array[4]) || ( array[0] == array[2] && array[3] == array[4]) ){
		return true;
	}
	else{
		return false;
	}
}

int large_straight(int array[], int place, int iteration){	// checks if the player has score a large straight using a recursive algorithm
	if( iteration == 4 ){	//if the array has passed all four iterations, then the player has scored a large straight
		return 1;
	}
	else if ( array[place + 1] == array[place] + 1 ){	//if place n2 = n1 + 1, then the function is called recursively
		large_straight(array, place + 1, iteration + 1);	//when this function is called, the place number and iteration number are increased 
	}
	else{
		return 0;
	}
}

int small_straight(int array[], int place, int iteration){	//checks if the player has rolled a small straight using a recursive algorithm 
	if(iteration == 3){	//the algorithm needs to pass three iterations in order to be true
		return 1;
	}
	else if( array[place + 1] == array[place] + 1 ){	//if n2 = n1 + 1, then the function is recursively called
		small_straight(array, place + 1, iteration + 1);	//when the function is called again with place + 1 and iteration + 1
	}
	else if( array[place + 1] == array[place]){
		small_straight(array, place + 1, iteration);
	}
	else{
		return 0;	//if the array fails either test, then the array is not a small straight
	}
}

void inserter (int array[]){	//the insertion sorting algorthm which sorts the integers in the array from least to greatest
	for(int i = 0; i < size; i++){
		int j = i;
		while((j > 0) && (array[j - 1] > array[j])){
			swap(array[j],array[j - 1]);
			j = j - 1;
		}
	}
}

void cleaner (int array[]){
	
	for( int i = 0; i < size; i++ ){
		if( array[i + 1] == array[i] ){
			array[i + 1] = 10;
		}
	}
}

void swap(int & a, int & b){	//a function that swaps two variables
	int tempvar = a;
	a = b;
	b = tempvar;
}