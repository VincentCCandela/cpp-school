#include<iostream>
#include<iomanip>
using namespace std;

const int row = 8, column = 8; //size of board is declared globally so that all of the variables for the board can use these variables

int counter(string array[][column], string type);
void printer(string array[][column]);
void mover(string array[][column], int the_row, int the_column, char move, int iteration);

int main(){
    string response, response2, grid[row][column]; //the grid, a temporary grid for cell updates, and the response for continuing the program and adding in new cells
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

        do{
            cin >> the_move;
            the_move = toupper(the_move);

          if( the_move == 'L'){
                if(x_coordinate == 7){
                cout << "1 Move not possible! Choose again: ";
                }
                else if(y_coordinate == 0){
                cout << "2 Move not possible! Choose again: ";
                }
                else{
                    the_response = true;
                }
            }
            else if( the_move == 'R' ){
                if(x_coordinate == 7){
                cout << "3 Move not possible! Choose again: ";
                }
                else if(y_coordinate == 7){
                cout << "4 Move not possible! Choose again: ";
                }
                else{
                    the_response = true;
                }
            }
        } while ( the_response == false );
        
        //the_move = toupper(the_move);
        while( (grid[x_coordinate + 1][y_coordinate + 1] == "⚫️ " && grid[x_coordinate + 2][y_coordinate + 2] == "⬜️ ") || (grid[x_coordinate + 1][y_coordinate - 1] == "⚫️ " && grid[x_coordinate + 2][y_coordinate - 2] == "⬜️ ") ){
            mover(grid, x_coordinate, y_coordinate, the_move, 0);
        }
        

        /*cout << endl;
        cout << "print 1" << endl;
        printer(grid);*/

        int counter1 = 0;

        for( int i = 0; i < row; ++i ){
            for( int j = 0; j < column; ++j ){ 
                if( (grid[i - 1][j - 1] == "🔴 ") && (grid[i - 2][j - 2] == "⬜️ ") && (grid[i][j] == "⚫️ ") && (counter1 == 0) ){
                    grid[i - 2][j - 2] = "⚫️ ";
                    grid[i - 1][j - 1] = "⬜️ ";
                    grid[i][j] = "⬜️ ";
                    counter1++;
                }
                else if( (grid[i - 1][j + 1] == "🔴 ") && (grid[i - 2][j + 2] == "⬜️ ") && (grid[i][j] == "⚫️ ") && (counter1 == 0) ){
                    grid[i - 2][j + 2] = "⚫️ "; 
                    grid[i - 1][j + 1] = "⬜️ ";
                    grid[i][j] = "⬜️ ";
                    counter1++;
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

        cout << endl;
        cout << "print 2" << endl;
        printer(grid);

    }
    return 0;
}

void mover(string array[][column], int the_row, int the_column, char move, int iteration){
    if( (toupper(move) == 'L') && (array[the_row + 1][the_column - 1] == "⬜️ ") ){
        array[the_row][the_column] = "⬜️ ";
        array[the_row + 1][the_column - 1] = "🔴 ";
        the_row = the_row + 1;
        the_column = the_column - 1;
        cout << "done!" << endl;
    }
    else if( (toupper(move) == 'R') && (array[the_row + 1][the_column + 1] == "⬜️ ") ){
        array[the_row][the_column] = "⬜️ ";
        array[the_row + 1][the_column + 1] = "🔴 ";
        the_row = the_row + 1;
        the_column = the_column + 1;
        cout << "done!" << endl;
    }
    else if( (toupper(move) == 'L') && (array[the_row + 1][the_column - 1] == "⚫️ ") && (array[the_row + 2][column - 2] == "⬜️ ") ){
        array[the_row][the_column] = "⬜️ ";
        array[the_row + 1][the_column - 1] = "⬜️ ";
        array[the_row + 2][the_column - 2] = "🔴 ";
        the_row = the_row + 2;
        the_column = the_column - 2;
        mover(array, the_row, the_column, move, 1);
        cout << "done!" << endl;
    }    
    else if( (toupper(move) == 'R') && (array[the_row + 1][the_column + 1] == "⚫️ ") && (array[the_row + 2][column + 2] == "⬜️ ") ){
        array[the_row][the_column] = "⬜️ ";
        array[the_row + 1][the_column + 1] = "⬜️ ";
        array[the_row + 2][the_column + 2] = "🔴 ";
        the_row = the_row + 2;
        the_column = the_column +2;
        mover(array, the_row, the_column, move, 1);
        cout << "done!" << endl;
    }
    
    if( (array[the_row + 1][the_column - 1] == "⚫️ ") && (array[the_row + 2][column - 2] == "⬜️ ") ){
        array[the_row][the_column] = "⬜️ ";
        array[the_row + 1][the_column - 1] = "⬜️ ";
        array[the_row + 2][the_column - 2] = "🔴 ";
        the_row = the_row + 2;
        the_column = the_column - 2;
        mover(array, the_row, the_column, move, 1);
        cout << "done!" << endl;
    }    
    else if( (array[the_row + 1][the_column + 1] == "⚫️ ") && (array[the_row + 2][column + 2] == "⬜️ ") ){
        array[the_row][the_column] = "⬜️ ";
        array[the_row + 1][the_column + 1] = "⬜️ ";
        array[the_row + 2][the_column + 2] = "🔴 ";
        the_row = the_row + 2;
        the_column = the_column +2;
        mover(array, the_row, the_column, move, 1);
        cout << "done!" << endl;
    }

    else if( (toupper(move) == 'R') && (iteration == 1) ){
         if( (array[the_row + 1][the_column - 1] == "⚫️ ") && (array[the_row + 2][column - 2] == "⬜️ ") ){
            array[the_row][the_column] = "⬜️ ";
            array[the_row + 1][the_column - 1] = "⬜️ ";
            array[the_row + 2][the_column - 2] = "🔴 ";
            the_row = the_row + 2;
            the_column = the_column - 2;
            mover(array, the_row, the_column, move, 1);
            cout << "done!" << endl;
        }
        else if( (array[the_row + 1][the_column + 1] == "⚫️ ") && (array[the_row + 2][column + 2] == "⬜️ ") ){
            array[the_row][the_column] = "⬜️ ";
            array[the_row + 1][the_column + 1] = "⬜️ ";
            array[the_row + 2][the_column + 2] = "🔴 ";
            the_row = the_row + 2;
            the_column = the_column + 2;
            mover(array, the_row, the_column, move, 1);
            cout << "done!" << endl;
        }
        else{
            cout << "done!" << endl;
        }
    }
    else{
    
    }

    iteration++;

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
