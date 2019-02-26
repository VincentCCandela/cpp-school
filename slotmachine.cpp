#include<iostream>
using namespace std;
int main() {
	srand(time(null));
	int tokens = 100; //the player starts with 100 tokens
	char response;

	int 1n1 = rand()%3 + 1, 1n2 = rand()%3 + 1, 1n3 = rand()%3 + 1, 3n1 = rand()%3 + 1, 3n2 = rand()%3 + 1, 3n3 = rand()%3 + 1; // presets the random numbers for the first and third rows
	while (tokens > 0){
		cout << "You have " << tokens << ". Pull? (y/n)" << endl;
		cin >> response;

		if ((response == y || response == Y) && tokens > 0){ //outputs the numbers after the wheel is "pulled"

			int 2n1 = rand()%3 + 1; //generates the new numbers for second row
			int 2n2 = rand()%3 + 1;
			int 2n3 = rand()%3 + 1;
			
			cout << "[" << 1n1 << "] " << 1n2 << "] [" << 1n3 << endl;
			cout << "[" << 2n1 << "] [" << 2n2 << "] [" << 2n3 << endl;
			cout << "[" << 3n1 << "] " << 3n2 << "] [" << 3n3 << endl;

			if ( 2n1 == 1 && 2n2 == 1 && 2n3 ==1){ //Gives the player 4 tokens for winnnig 1 in a row
				cout << "You won 4 tokens!" << endl;
				tokens = tokens + 4;
			}
			else if ( 2n1 == 2 && 2n2 == 2 && 2n3 == 2){ // Gives the player 8 tokens for winning 2 in a row
				cout << "You won 8 tokens!" << endl;
				tokens = tokens + 8;

			}
			else if ( 2n1 == 3 && 2n2 == 3 && 2n3 == 3){ //Gives the player 12 tokens for getting three in a row
				cout << "You won 12 tokens!" << endl;
				tokens = tokens + 12;

			}

		}

		else{    //  ends the while loop which is the last and only running part of the program thereby ending the program.
			cout << "Thanks for playing!" << endl;
			tokens = 0;
		}

		1n1 = 2n1; //moves the numbers from the second row to the first row
		1n2 = 2n2;
		1n3 = 2n3;
	}
return 0;
}

