#include<iostream>
#include<iomanip>

using namespace std;

const int row = 20, column = 20; //size of grid; is declared globally so that all of the grids used can use these variables
int checker(int r, int c, char orginial[row][column]); //creates function to check the number of live cells around a cell
void changer(int r, int c, char array[][column], char temp_array[][column]);  //function that calls the checker and changes cells based on the output of the checker

int main(){
    int x_coordinate, y_coordinate; //input for desired coordinates of a cell
    char response, response2, grid[row][column], temp_grid[row][column]; //the grid, a temporary grid for cell updates, and the response for continuing the program and adding in new cells

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            grid[i][j] = 'O'; //fills grid with '0's
            cout << setw(4) << grid[i][j]; //outputs grid
            if(j == 19){  //prints the correct number of columns in the outputed grid
                cout << endl;
            }
        }
    }

    do{
        cout << "Do you want to enter a live cell into the grid? (y/n) "; //asks the user if they want to put another cell into the grid
        cin >> response;

        while (toupper(response) == 'Y'){ //when response is yes, will let you select where you want new cell
            cout << "Enter the x coordinate of the cell: "; //input for x and y coordinates coordinate
            cin >> y_coordinate;

            cout << "Enter the y coordinate of the cell: ";
            cin >> x_coordinate;

            x_coordinate = x_coordinate % 20;   //if either of the coordinates is too large, then it is put back in bounds
            y_coordinate = y_coordinate % 20;

            grid[x_coordinate][y_coordinate] = 'X'; //marks where new cell is

            cout << endl;

            for(int i = 0; i < row; ++i){
                for(int j = 0; j < column; ++j){
                    cout << setw(4) << grid[19 - i][j]; //outputs updated grid
                    temp_grid[i][j] = grid[i][j];  //and sets the temporary grid to the real grid
                    if(j == 19){
                        cout << endl;
                    }
                }
            }            

            cout << "Do you want to enter another live cell into the grid? (y/n) ";    //asks the user if he wants to add another cell
            cin >> response;
        }

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < column; ++j){
                changer(i,j,grid,temp_grid); //calls changer function for grid
            }
        }

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < column; ++j){
                grid[i][j] = temp_grid[i][j];    //after the changer is finished, updates the real grid to the fake grid        
            }
        }

        cout << endl;

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < column; ++j){
                cout << setw(4) << grid[19 - i][j]; //outputs updated grid
                if(j == 19){
                    cout << endl;
                }
            }
        }

        cout << "Do you want to go to the next day? (y/n)"; //asks the user if he wants to continue to a new day
        cin >> response2;
        
    } while(toupper(response2) == 'Y');   //if the user wants to continue, then the program continues, otherwise it exits

    cout << "Thanks for playing!" << endl;

    return 0;
}

int checker(int r, int c, char original[][column]){ //the original function is passed in by reference with the row and column of the the array
    int counter = 0; //counter of for the number of surrounding live cells is created and set to zero
    if(r == 0 && c == 0){ // checks for the cell of the bottom left corner of the array
        if(original[r][c + 1] == 'X'){
            counter++;
        }
        if(original[r + 1][c] == 'X'){
            counter++;
        }
        if(original[r + 1][c + 1] == 'X'){
            counter++;
        }
    }
    else if(r == 19 && c == 0){ //checks for the cell of the top left corner of the array
        if(original[r - 1][c] == 'X'){
            counter++;
        }
        if(original[r - 1][c + 1] == 'X'){
            counter++;
        }
        if(original[r][c + 1] == 'X'){
            counter++;
        }
    }
    else if(r == 19 && c == 19){ //checks for the cell of the top right corner of the array
        if(original[r][c - 1] == 'X'){
            counter++;
        }
        if(original[r - 1][c - 1] == 'X'){
            counter++;
        }
        if(original[r - 1][c] == 'X'){
            counter++;
        }
    }
    else if(r == 0 && c == 19){ //checks for the bottom right corner of the array
        if(original[r][c - 1] == 'X'){
            counter++;
        }
        if(original[r + 1][c - 1] == 'X'){
            counter++;
        }
        if(original[r + 1][c] == 'X'){
            counter++;
        }
    }
    else if(r == 0){ //checks for the bottom row of the array
        if(original[r + 1][c] == 'X'){
            counter++;
        }
        if(original[r + 1][c - 1] == 'X'){
            counter++;
        }
        if(original[r + 1][c + 1] == 'X'){
            counter++;
        }
        if(original[r][c + 1] == 'X'){
            counter++;
        }
        if(original[r][c - 1] == 'X'){
            counter++;
        }
    }
    else if(r == 19){ //checks for the top row of the array
        if(original[r - 1][c] == 'X'){
            counter++;
        }
        if(original[r - 1][c + 1] == 'X'){
            counter++;
        }
        if(original[r - 1][c - 1] == 'X'){
            counter++;
        }
        if(original[r][c + 1] == 'X'){
            counter++;
        }
        if(original[r][c - 1] == 'X'){
            counter++;
        }
    }
    else if(c == 0){ //checks for the left column of the array
        if(original[r][c + 1] == 'X'){
            counter++;
        }
        if(original[r - 1][c + 1] == 'X'){
            counter++;
        }
        if(original[r + 1][c + 1] == 'X'){
            counter++;
        }
        if(original[r - 1][c] == 'X'){
            counter++;
        }
        if(original[r + 1][c] == 'X'){
            counter++;
        }
    }
    else if(c == 19){ //checks for the right column of the array
        if(original[r][c - 1] == 'X'){
            counter++;
        }
        if(original[r - 1][c - 1] == 'X'){
            counter++;
        }
        if(original[r + 1][c - 1] == 'X'){
            counter++;
        }
        if(original[r - 1][c] == 'X'){
            counter++;
        }
        if(original[r + 1][c] == 'X'){
            counter++;
        }
    }
    else{    //if the cell is not on any of the sides, then all of the surrounding cells are checked
        if(original[r - 1][c - 1] == 'X'){
            counter++;
        }
        if(original[r - 1][c] == 'X'){
            counter++;
        }
        if(original[r - 1][c + 1] == 'X'){
            counter++;
        }
        if(original[r][c - 1] == 'X'){
            counter++;
        }
        if(original[r][c + 1] == 'X'){
            counter++;
        }
        if(original[r + 1][c - 1] == 'X'){
            counter++;
        }
        if(original[r + 1][c] == 'X'){
            counter++;
        }
        if(original[r + 1][c + 1] == 'X'){
            counter++;
        }
    }
    if(counter == 3){ //if there are 3 surrounding living cells, then 3 is returned
        return 3;
    }
    else if(counter == 2){ //if there are 2 surrounding living cells, then 2 is returned
        return 2;
    }
    else{ //else, an exit code of 1 is returned
        return 1;
    }
}

void changer(int r, int c, char array[][column], char temp_array[][column]){ //both the array and the temporary array are passed in by reference with the row and column of the arrays
    if(array[r][c] == 'O' && checker(r,c,array) == 3 ){ //if the cell in the original array is dead and there are exactly three surrounding living cells, then the dead cell is transformed into a living cell
        temp_array[r][c] = 'X';
    }
    else if(array[r][c] == 'X' && (checker(r,c,array) == 2 || checker(r,c,array) == 3) ){ //if the living cell is surrounded by 2 or three living cells, then the cell remains living
        temp_array[r][c] = 'X';
    }
    else if( array[r][c] == 'X' && checker(r,c,array) == 1 ){ //if a living cell is surround by 0,1, or more then three living cells, then the living cell dies
        temp_array[r][c] = 'O';
    }
} 