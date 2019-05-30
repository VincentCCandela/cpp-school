#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;


const int row = 8, column = 8; //size of board is declared globally so that all of the variables for the board can use these variables

int counter(string array[][column], string type);
void printer(string array[][column]);

int main(){
    string response, response2, grid[row][column], temp_grid[row][column]; //the grid, a temporary grid for cell updates, and the response for continuing the program and adding in new cells
    int x_coordinate = 0, y_coordinate = 0, to_x_coordinate, to_y_coordinate, i, j;

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

    //while(counter(grid, "🔴 ") > 0){
    while(true){

        cout << "Which piece do you want to move?" << endl;
        do{
            cout << "enter the x-value: ";
            cin >> x_coordinate;
        
        } while ( x_coordinate < 0 || x_coordinate > 7 );
        do{
            cout << "enter the y-value: ";
            cin >> y_coordinate;

        }while ( y_coordinate < 0 || y_coordinate > 7 );
        
        cout << "Where do you want to move?" << endl;
        
        do{
            cout << "enter the x-value: ";
            cin >> to_x_coordinate;

        } while ( to_x_coordinate < 0 || to_x_coordinate > 7 );
        do{
            cout << "enter the y-value: ";
            cin >> to_y_coordinate;

        }while ( to_y_coordinate < 0 || to_y_coordinate > 7 );

        grid[ abs(to_y_coordinate) ][to_x_coordinate] = "🔴 ";
        grid[y_coordinate][x_coordinate] = "⬜️ ";

        cout << "print 1" << endl;
        printer(grid);

        int enemy_counter = 0;

        for( int i = 0; i < row; ++i ){
            for( int j = 0; j < column; ++j ){ 
                if( (enemy_counter == 0) && (grid[i][j] == "⚫️ ") && (grid[i - 1][j - 1] == "🔴 ") && (grid[i - 2][j - 2] == "⬜️ ") ){
                    grid[i - 2][j - 2] = "⚫️ ";
                    grid[i - 1][j - 1] = "⬜️ ";
                    grid[i][j] = "⬜️ ";
                    enemy_counter++;
                }
                else if( (enemy_counter == 0) && (grid[i][j] == "⚫️ ") && (grid[i - 1][j + 1] == "🔴 ") && (grid[i - 2][j + 2] == "⬜️ ")){
                    grid[i - 2][j + 2] = "⚫️ "; 
                    grid[i - 1][j + 1] = "⬜️ ";
                    grid[i][j] = "⬜️ ";
                    enemy_counter++;
                }
                else{
                    /*if( (rand() % 1 == 1) && (grid[i + 1][j - 1] == "⬜️ ") ){

                    }
                    else{

                    }*/
                }
            }
        }

        printer(grid);
        cout << "print 2" << endl;
        
    }
    return 0;
}

/*int counter(string array[][column], string type){
    int counter = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(array[i][j] == type){
                counter++;
            }
        }
    }
    
    return counter;
}*/

void printer(string array[][column]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cout << array[i][j]; //outputs grid
            if(j == column - 1){  //prints the correct number of columns in the outputed grid
                cout << endl;
            }
        }
    }
}
