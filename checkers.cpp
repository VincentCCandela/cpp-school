#include<iostream>
#include<iomanip>
#include <unistd.h>
using namespace std;

const int row = 8, column = 8; //size of board is declared globally so that all of the variables for the board can use these variables

int counter(string array[][column], string type); // a function to count the number of pieces inputted
void printer(string array[][column]); //a function to print the board
void mover(string array[][column], int the_row_number, int the_column_number, char move); // a function to move the player's pieces based on the selected input

int main(){
    string grid[row][column]; //the grid which is the game board
    srand(time(NULL));

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            //fills board with all of the player's and computer's pieces
            if( ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) && (row != 4 && row != 5) ){
                grid[i][j] = "⬜️ ";
            }
            else{
                grid[i][j] = "⬛️ ";
            }
            if(((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))){
                if(i == 0 || i == 1 || i == 2){
                    grid[i][j] = "🔴 ";                                       
                }
                else if(i == 5 || i == 6 || i == 7){
                    grid[i][j] = "⚫️ ";
                }
            } 
        }
    }
	
    printer(grid); //prints the board

    while( counter(grid, "🔴 ") > 0 && counter(grid, "⚫️ ") > 0 ){ // as long as there are still pieces on the board, the game will continue
        int column_number, row_number; //declaration of the x and y coordinates which the user will want to move

        cout << "Which piece do you want to move?" << endl; //asks the user which piece he will want to move
        do{							//asks the user for the the x-coordinate of the piece that he wants to move. If the x or y coordinates do not exist, the the user will be asked again for the x and y coordinates
	    cout << "row number: ";
            cin >> row_number;          	    

	    cout << "column number: ";	
            cin >> column_number;	    

        }while ( grid[row_number][column_number] != "🔴 ");	
        
        cout << "Do you want to move left or right? (L/R)";	//asks the user if he wants to move left or right
        char the_move;
        
        bool the_response = false;	//a variable for a fucntion which checks if the move is possible. If the move isn't possible, then the user is asked to re-enter what they want their move to be 

        do{
            cin >> the_move;
            the_move = toupper(the_move);

          if( the_move == 'L'){
                if(column_number == 0){
                cout << "Move not possible! Choose again: ";
                }
                else if(row_number == 7){
                cout << "Move not possible! Choose again: ";
                }
                else{
                    the_response = true;
                }
          }
          else if( the_move == 'R' ){
                if(column_number == 7){
                cout << "Move not possible! Choose again: ";
                }
                else if(row_number == 7){
                cout << "Move not possible! Choose again: ";
                }
                else{
                    the_response = true;
                }
          }
        } while ( the_response == false );
        
        the_move = toupper(the_move);	//if the move choice is inputted as lowercase, it is converted to uppercase
        mover(grid, row_number, column_number, the_move);	//the mover function is called which moves the pieces
	sleep(0.25); //slows down the execution of the program so that the mover function can be completed properly before the computer moves

        int counter1 = 0; //a counter for the function which moves the computer's pieces which prevents the computer from moving more than once

        for( int i = 0; i < row; ++i ){
            for( int j = 0; j < column; ++j ){ 
                if( (i > 1) && (j > 1) ){
                    if( (grid[i - 1][j - 1] == "🔴 ") && (grid[i - 2][j - 2] == "⬜️ ") && (grid[i][j] == "⚫️ ") && (counter1 == 0) ){ //if it is possible to jump opposing pieces, opposing pieces are jumped
                        grid[i - 2][j - 2] = "⚫️ ";
                        grid[i - 1][j - 1] = "⬜️ ";
                        grid[i][j] = "⬜️ ";
                        counter1++;
                    }
                }
                else if( (i > 1 ) && (j < 6) ){
                    if( (grid[i - 1][j + 1] == "🔴 ") && (grid[i - 2][j + 2] == "⬜️ ") && (grid[i][j] == "⚫️ ") && (counter1 == 0) ){  //if it is possible to jump opposing pieces, opposing pieces are jumped
                        grid[i - 2][j + 2] = "⚫️ "; 
                        grid[i - 1][j + 1] = "⬜️ ";
                        grid[i][j] = "⬜️ ";
                        counter1++;
                    }
                }
            }
        }

        if( counter1 == 0 ){	//if no opposing pieces are jumped, then another piece is moved forwards
            for ( int i = 0; i < row; i++){
                for (int j = 0; j < column; j++){
                    if( (i > 0) && (j > 0) ){
                        if( (counter1 == 0) && (grid[i - 1][j - 1] == "⬜️ ") && (grid[i][j] == "⚫️ ") ){
                            grid[i - 1][j - 1] = "⚫️ ";
                            grid[i][j] = "⬜️ ";
                            counter1++;
                        }
                    }
                    if( (i > 0) && (j < 7) ){
                        if( (counter1 == 0) && (grid[i - 1][j + 1] == "⬜️ ") && (grid[i][j] == "⚫️ ") ){
                            grid[i - 1][j + 1] = "⚫️ ";
                            grid[i][j] = "⬜️ ";
                            counter1++;
                        }
                    }
                }
            }
        }

        printer(grid);

    }

	if( counter(grid, "🔴 ") == 0 ){
		cout << "You lose!" << endl;
	}
	else{
		cout << "You win! "<< endl;
	}
    return 0;
}

void mover(string array[][column],int the_row_number, int the_column_number, char move){	//function to move the user's pieces
    move = toupper(move); //converts the move into uppercase

    if( (move == 'L') && (array[the_row_number][the_column_number] == "🔴 ") && (array[the_row_number + 1][the_column_number - 1] == "⚫️ ") && (array[the_row_number + 2][the_column_number - 2] == "⬜️ ") ){	//an if statement for the piece to make a left jump
        array[the_row_number][the_column_number] = "⬜️ ";
        array[the_row_number + 1][the_column_number - 1] = "⬜️ ";
        array[the_row_number + 2][the_column_number - 2] = "🔴 ";
        the_row_number = the_row_number + 2;
        the_column_number = the_column_number - 2;
	if( (the_row_number < 6) && (the_column_number < 6) ){	//recursive function of sorts if another jump can be made
		if( (array[the_row_number + 1][the_column_number + 1] == "⚫️ ") && (array[the_row_number + 2][the_column_number + 2] == "⬜️ ") ){
			mover(array, the_row_number, the_column_number, 'R');
		}
	}
	if( (the_row_number < 6) && (the_column_number > 1) ){	//recursive function of sorts if another jump can be made
		if( (array[the_row_number + 1][the_column_number - 1] == "⚫️ ") && (array[the_row_number + 2][the_column_number - 2] == "⬜️ ") ){
			mover(array, the_row_number, the_column_number, 'L');
		}
	}
        cout << "done!" << endl;
    }    
    else if( (move == 'R') && (array[the_row_number][the_column_number] == "🔴 ") && (array[the_row_number + 1][the_column_number + 1] == "⚫️ ") && (array[the_row_number + 2][the_column_number + 2] == "⬜️ ") ){  //an if statement for the piece to make a right jump
        array[the_row_number][the_column_number] = "⬜️ ";
        array[the_row_number + 1][the_column_number + 1] = "⬜️ ";
        array[the_row_number + 2][the_column_number + 2] = "🔴 ";
        the_row_number = the_row_number + 2;
        the_column_number = the_column_number + 2;
	if( (the_row_number < 6) && (the_column_number < 6) ){	//recursive function of sorts if another jump can be made
		if( (array[the_row_number + 1][the_column_number + 1] == "⚫️ ") && (array[the_row_number + 2][the_column_number + 2] == "⬜️ ") ){
			mover(array, the_row_number, the_column_number, 'R');
		}
	}
	if( (the_row_number < 6) && (the_column_number > 1) ){	//recursive function of sorts if another jump can be made
		if( (array[the_row_number + 1][the_column_number - 1] == "⚫️ ") && (array[the_row_number + 1][the_column_number - 1] == "⬜️ ") ){
			mover(array, the_row_number, the_column_number, 'L');
		}
	}
        cout << "done!" << endl;
    }
    else if( (move == 'L') && (array[the_row_number + 1][the_column_number - 1] == "⬜️ ") ){	//if the move is left, and then the piece is moved left
        array[the_row_number][the_column_number] = "⬜️ ";
        array[the_row_number + 1][the_column_number - 1] = "🔴 ";
        cout << "done!" << endl;
    }
    else if( (move == 'R') && (array[the_row_number + 1][the_column_number + 1] == "⬜️ ") ){	//if the move is right, and then the piece is moved right
        array[the_row_number][the_column_number] = "⬜️ ";
        array[the_row_number + 1][the_column_number + 1] = "🔴 ";
        cout << "done!" << endl;
    }
}

int counter(string array[][column], string type){ //a function to count the remaining types of pieces
    int the_counter = 0;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
        if(array[i][j] == type)
            the_counter++;
        }
    }
    
    return the_counter;
}

void printer(string array[][column]){ // a function to print the board
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            cout << array[i][j]; //outputs grid
            if(j == column - 1){  //prints the correct number of columns in the outputed grid
                cout << endl;
            }
        }
    }
}
//test comment
//another test comment