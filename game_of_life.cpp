#include<iostream>
#include<iomanip>

using namespace std;

const int row = 20, column = 20; //size of grid
int checker(int r, int c, char orginial[row][column]); //creates function to check cell is if alive or dead (true or false)
void changer(int r, int c, char array[][column], char temp_array[][column]);

int main(){
    int x_coordinate, y_coordinate; //input for desired coordinates of cells
    char response, response2, grid[row][column], temp_grid[row][column]; //creates grid, response1, and reponse2

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            grid[i][j] = 'O'; //fills grid with '0's
            cout << setw(4) << grid[i][j]; //outputs grid
            if(j == 19){
                cout << endl;
            }
        }
    }

    do{
        cout << "Do you want to enter a live cell into the grid? (y/n) ";
        cin >> response;

        while (toupper(response) == 'Y'){ //when response is yes, will let you selct where you want new cell
            cout << "Enter the x coordinate of the cell: "; //input for y coordinate
            cin >> y_coordinate;

            cout << "Enter the inverted y coordinate of the cell: ";
            cin >> x_coordinate;

            x_coordinate = x_coordinate % 20;
            y_coordinate = y_coordinate % 20;

            grid[x_coordinate][y_coordinate] = 'X'; //marks where new cell is

            for(int i = 0; i < row; ++i){
                for(int j = 0; j < column; ++j){
                    cout << setw(4) << grid[i][j]; //outputs updated grid
                    temp_grid[i][j] = grid[i][j];
                    if(j == 19){
                        cout << endl;
                    }
                }
            }

            cout << "Do you want to enter another live cell into the grid? (y/n) ";
            cin >> response;
        }

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < column; ++j){
                changer(i,j,grid,temp_grid); //calls changer function for grid
            }
        }

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < column; ++j){
                grid[i][j] = temp_grid[i][j];            
            }
        }

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < column; ++j){
                cout << setw(4) << grid[i][j]; //outputs updated grid
                if(j == 19){
                    cout << endl;
                }
            }
        }

        cout << "Do you want to go to the next day? (y/n)";
        cin >> response2;
        
    } while(toupper(response2) == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}

int checker(int r, int c, char original[][column]){
    int counter = 0;
    if(r == 0 && c == 0){
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
    else if(r == 19 && c == 0){
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
    else if(r == 19 && c == 19){
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
    else if(r == 0 && c == 19){
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
    else if(r == 0){
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
    else if(r == 19){
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
    else if(c == 0){
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
    else if(c == 19){
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
    else{    
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
    if(counter == 3){
        return 3;
    }
    else if(counter == 2){
        return 2;
    }
    else{
        return 1;
    }
}

void changer(int r, int c, char array[][column], char temp_array[][column]){
    if(array[r][c] == 'O' && checker(r,c,array) == 3 ){
        temp_array[r][c] = 'X';
    }
    else if(array[r][c] == 'X' && (checker(r,c,array) == 2 || checker(r,c,array) == 3) ){
        temp_array[r][c] = 'X';
    }
    else if( array[r][c] == 'X' && checker(r,c,array) == 1 ){
        temp_array[r][c] = 'O';
    }
} 