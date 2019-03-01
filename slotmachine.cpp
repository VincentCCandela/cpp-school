#include<iostream>
using namespace std;
int main() {
	srand(time(NULL)); //sets the seed for the random numbers to random
	int tokens = 100; //the player starts with 100 tokens
	char response;
	
	cout << "You have " << tokens << ". Pull? (y/n)" << endl; //displays tokens and asks user to play
	cin >> response;	//receives the input if the user wants to play

	while ((response == 'y' || response == 'Y') && tokens > 0){ //checks whether or not the user wants to play and checks if the user can play
		
		int secondone = rand()%3+1, secondtwo = rand()%3+1, secondthree = rand()%3+1; //declares, initializes, and assignes the values for the second row
		
		cout << "[" << (secondone+1)%3+1 << "] [" << (secondtwo+1)%3+1 << "] [" << (secondthree+1)%3+1 << "]" << endl;	//outputs the numbers
		cout << "[" << secondone << "] [" << secondtwo << "] [" << secondthree << "]" << endl;	//outputs the numbers
		cout << "[" << (((secondone+1)%3+1)+1)%3+1 << "] [" << (((secondtwo+1)%3+1)+1)%3+1 << "] [" << (((secondthree+1)%3+1)+1)%3+1 << "]" << endl; 	//outputs random numbers for the third row
		
		tokens = tokens - 1; //subtracts a token from playing
		
		if ( secondone == 1 && secondtwo == 1 && secondthree ==1){ //Gives the player 4 tokens for winnnig 1 in a row
			cout << "You won 4 tokens!" << endl;
				tokens = tokens + 5;
		}
		else if ( secondone == 2 && secondtwo == 2 && secondthree == 2){ // Gives the player 8 tokens for winning 2 in a row
			cout << "You won 8 tokens!" << endl;
			tokens = tokens + 9;
		}
		else if ( secondone == 3 && secondtwo == 3 && secondthree == 3){ //Gives the player 12 tokens for getting three in a row
			cout << "You won 12 tokens!" << endl;
			tokens = tokens + 13;
		}

		cout << "You have " << tokens << ". Pull? (y/n)" << endl; //displays tokens and asks user to play
		cin >> response;
		
	}
	cout << "Thanks for playing!" << endl; // thanks the user for playing after user exits the program
	return 0;
}