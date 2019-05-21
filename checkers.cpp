#include<iostream>
#include<iomanip>
using namespace std;


const int row = 8, column = 8; //size of board is declared globally so that all of the variables for the board can use these variables

int main(){
    string response, response2, grid[row][column], temp_grid[row][column]; //the grid, a temporary grid for cell updates, and the response for continuing the program and adding in new cells

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            //fills board with '0's and 'X's
            if( ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) && (row != 4 && row != 5) ){
                grid[i][j] = "⬜️";
            }
            else{
                grid[i][j] = "⬛️";
            }
        }
    }

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            cout << setw(7) << grid[7 - i][j]; //outputs grid
            if(j == column - 1){  //prints the correct number of columns in the outputed grid
                cout << endl;
            }
        }
    }


    return 0;
}