#include<iostream>
#include<iomanip>
using namespace std;

//simpler/lower version of yahtzee


bool three_of_a_kind(int array[]);
bool four_of_a_kind(int array[]);
bool full_house(int array[]);
bool small_straight(int array[]);
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
		
		if (three_of_a_kind(dice) == true){
			cout << "You have a three of a kind." << endl;
		}
		else if(four_of_a_kind(dice) == true){
			cout << "You have a four of a kind." << endl
		}
		
	}
	
	cout << "Thanks for playing!" << endl;
	return 0;
}

bool three_of_a_kind(int array[]){
	if (array[0] == array[2] || array[1] == array[3] || array[2] == array[4] || array[3] == array[5]){
		return true;
	}
	else{
		return false;
	}
}

bool four_of_a_kind(int array[]){
	if (array[0] == array[3] || array[1] == array[4] || array[2] == array[5]){
		return true;
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