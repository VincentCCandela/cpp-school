#include<iostream>
#include<iomanip>
using namespace std;

const int row = 8, column = 8; //size of board is declared globally so that all of the variables for the board can use these variables

int counter(string array[][column], string type);
void printer(string array[][column]);

int main(){
    string response, response2, grid[row][column], temp_grid[row][column]; //the grid, a temporary grid for cell updates, and the response for continuing the program and adding in new cells
    int x_coordinate = 0, y_coordinate = 0, to_x_coordinate, to_y_coordinate, i = 0, j = 0;

    srand(time(NULL));

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            //fills board with '0's and 'X's
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
    
    printer(grid);

    while( counter(grid, "🔴 ") > 0 && counter(grid, "⚫️ ") > 0 ){
        
        cout << "Which piece do you want to move?" << endl;
        do{
            cout << "enter the x-value: ";
            cin >> x_coordinate;
        
        } while ( x_coordinate < 0 || x_coordinate > 7 );
        do{
            cout << "enter the y-value: ";
            cin >> y_coordinate;

        }while ( y_coordinate < 0 || y_coordinate > 7 );
        
        cout << "Do you want to move left or right? (L/R)";
        char the_move;
        
        bool the_response = false;

        while ( the_response == false ){
            cin >> the_move;
            the_move = toupper(the_move);

            /*if( the_move != 'L' || the_move != 'R' ){
                the_response = false;
                cout << "Not a correct response! Enter the correct response: ";
            }
            else*/ if( the_move == 'L'){
                if(i == 7){
                cout << "1 Move not possible! Choose again: ";
                }
                else if(j == 0){
                cout << "2 Move not possible! Choose again: ";
                }
                else{
                    the_response = true;
                }
            }
            else if( the_move == 'R' ){
                if(i == 7){
                cout << "3 Move not possible! Choose again: ";
                }
                else if(j == 7){
                cout << "4 Move not possible! Choose again: ";
                }
                else{
                    the_response = true;
                }
            }
        }

        cout << endl;
        cout << "print 1" << endl;
        printer(grid);

        int counter1 = 0;

        for( int i = 0; i < row; ++i ){
            for( int j = 0; j < column; ++j ){ 
                if( (grid[i - 1][j - 1] == "🔴 ") && (grid[i - 2][j - 2] == "⬜️ ") && (grid[i][j] == "⚫️ ") ){
                    grid[i - 2][j - 2] = "⚫️ ";
                    grid[i - 1][j - 1] = "⬜️ ";
                    grid[i][j] = "⬜️ ";
                    counter1++;
                }
                else if( (grid[i - 1][j + 1] == "🔴 ") && (grid[i - 2][j + 2] == "⬜️ ") && (grid[i][j] == "⚫️ ") ){
                    grid[i - 2][j + 2] = "⚫️ "; 
                    grid[i - 1][j + 1] = "⬜️ ";
                    grid[i][j] = "⬜️ ";
                    counter1++;
                }
                else{
                    if( (rand() % 1 == 1) && (grid[i - 1][j - 1] == "⬜️ ") ){

                    }
                    else{

                    }
                }
            }
        }

        if( counter1 == 0 ){
            for ( int i = 0; i < row; i++){
                for (int j = 0; j < column; j++){
                    if( (counter1 == 0) && (grid[i - 1][j - 1] == "⬜️ ") && (grid[i][j] == "⚫️ ") ){
                        grid[i - 1][j - 1] = "⚫️ ";
                        grid[i][j] = "⬜️ ";
                        counter1++;
                    }
                    else if( (counter1 == 0) && (grid[i - 1][j + 1] == "⬜️ ") && (grid[i][j] == "⚫️ ") ){
                        grid[i - 1][j + 1] = "⚫️ ";
                        grid[i][j] = "⬜️ ";
                        counter1++;
                    }
                }
            }
        }

    }
    return 0;
}

int counter(string array[][column], string type){
    int the_counter = 0;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
        if(array[i][j] == type)
            the_counter++;
        }
    }
    
    return the_counter;
}

void printer(string array[][column]){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            cout << array[i][j]; //outputs grid
            if(j == column - 1){  //prints the correct number of columns in the outputed grid
                cout << endl;
            }
        }
    }
}
