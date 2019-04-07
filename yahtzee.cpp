#include<iostream>
#include<iomanip>
using namespace std;

//This is a simpler/lower version of yahtzee


bool three_of_a_kind(int array[]); //a function to determine if a three of a kind has been rolled
bool four_of_a_kind(int array[]);	//a function to determine if a four of a kind has been rolled
bool full_house(int array[]);	//a function to determine if a full house has been rolled
bool small_straight(int array[], int place, int iteration);	//a function to determine if a small straight has been rolled
bool large_straight(int array[], int place, int iteration);	//a function to determine if a large straight has been rolled
bool yahtzee(int array[]);	//a function to determine if a yahtzee has been rolled
int totaller(int array[]);	//adds up all the numbers in the dice

void inserter (int arrary[]);	//makes the dice go in ascending order
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
		
		for (int i = 0; i < size ; i++){
			dice[i] = rand() % 6 + 1;
			cout << dice[i];		
		}
		
		cout << endl;
		
		inserter(dice);
		
		cout << "Your sorted dice are: ";
		
		for (int i = 0; i < size ; i++){
			cout << dice[i];		
		}
		
		cout << endl;

		if(yahtzee(dice) == true){
			cout << "You have rolled a yahtzee! +50 points!" << endl;
			total_points = total_points + 50;
		}
		else if(four_of_a_kind(dice) == true){
			cout << "You have rolled a four of a kind. +" << totaller(dice) << " points!" << endl; 
			total_points = total_points + totaller(dice);
		}
		else if (full_house(dice) == true){
			cout << "You have rolled a full house. +25 points!" << endl;
			total_points = total_points + 25;
		}
		else if (three_of_a_kind(dice) == true){
			cout << "You have rolled a three of a kind. +" << totaller(dice) << " points!" << endl;
			total_points = total_points + totaller(dice);
		}
		else if(large_straight(dice,0,0) == true){
			cout << "You have rolled a large straight. +40 points!" << endl;
			total_points = total_points + 40;
		}
		else if(small_straight(dice, 0, 0) == true || small_straight(dice, 1, 0) == true ){
			cout << "You have rolled a small straight. + 30 points!" << endl;
			total_points = total_points + 30;
		}
		else{
			cout << "You have rolled nothing." << endl;
			cout << "Chance for " << totaller(dice) << " points." << endl;
			total_points = total_points + totaller(dice);
		}
		
		cout << "You have: " << total_points << " points in total." << endl;			
		cout << " " << endl;
	}
	
	cout << "Thanks for playing!" << endl;
	return 0;
}

bool three_of_a_kind(int array[]){
	if (array[0] == array[2] || array[1] == array[3] || array[2] == array[4]){
		return true;
	}
	else{
		return false;
	}
}

bool four_of_a_kind(int array[]){
	if (array[0] == array[3] || array[1] == array[4]){
		return true;
	}
	else{
		return false;
	}
}

bool yahtzee(int array[]){
	if (array[0] == array[4]){
		return true;
	}
	else{
		return false;
	}
}

int totaller(int array[]){
	return array[0] + array[1] + array[2] + array[3] + array[4];
}

bool full_house(int array[]){
	if((array[0] == array[1] && array[2] == array[4]) || ( array[0] == array[2] && array[3] == array[4]) ){
		return true;
	}
	else{
		return false;
	}
}

bool large_straight(int array[], int place, int iteration){
	if(iteration == 4){
		return true;
	}
	else if( array[place + 1] == array[place] + 1 ){
		large_straight(array, place + 1, iteration + 1);
	}
	else{
		return false;
	}
	
}

bool small_straight(int array[], int place, int iteration){
	if(iteration == 3){
		return true;
	}
	else if( array[place + 1] == array[place] +1 ){
		small_straight(array, place + 1, iteration + 1);
	}
	else{
		return false;
	}

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