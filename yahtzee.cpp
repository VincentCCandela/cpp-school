#include<iostream>
#include<iomanip>
using namespace std;

//simpler/lower version of yahtzee


bool three_of_a_kind(int array[]);
bool four_of_a_kind(int array[]);
bool full_house(int array[]);
bool small_straight(int array[], int place, int iteration);
bool large_straight(int array[]);
bool yahtzee(int array[]);
int chance(int array[]);

void inserter (int arrary[]);
void swap(int & a, int & b);

const int size = 5;

int main(){
	srand(time(NULL));
	
	char response = 'y';
	
	while( response == 'y' || response == 'Y'){
		cout << "Do you want to role the dice?" << endl;
		cin >> response;
		
		int dice[size];
		
		cout << " *Rolls dice* " << endl;
		cout << "You have rolled: ";
		
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
			cout << "You have a yahtzee!" << endl;
		}
		else if(four_of_a_kind(dice) == true){
			cout << "You have a four of a kind." << endl; 
		}
		else if (full_house(dice) == true){
			cout << "You have a full house." << endl;
		}
		else if (three_of_a_kind(dice) == true){
			cout << "You have a three of a kind." << endl;
		}
		else if(small_straight(dice, 0, 1) == true || small_straight(dice, 1, 1) == true ){
			cout << "You have a small straight" << endl;
		}
		else{
			cout << "Your chance score is: " << chance(dice) << endl;
		}
		
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

int chance(int array[]){
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

bool small_straight(int array[], int place, int iteration){
	if(iteration == 4){
		return true;
	}
	else if( (array[place + 1] = array[place]) && iteration < 4 ){
		small_straight(array, place + 1, iteration + 1);
	}
	else{
		return false;
	}
	
	
	/*
	if(array[1] == array[0] + 1 && (array[2] == array[1] + 1 && array[3] = array[2] + 1)){
		return true;
	}
	else if(array[2] == array[1] + 1 && (array[3] = array[2] + 1 && array[4] == array[3] + 1))
		return true;
	else{
		return false;
	}
	*/

	//int end1 = 5, end2 = 6;
	//if()



/*	for(int i = 0; i < size - 1; i++){
		if(array[i + 1] == start_int + 1){
		start_int = start_int + 1;
		}
		else if(array[i - 1] == array[i - 2] + 1){
		}
		else{
			return false;
		}
	}
	
	return true;
*/		
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