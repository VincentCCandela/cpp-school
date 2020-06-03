#include<iostream>
#include<random>
#include<iomanip>
using namespace std;

int main(){
    /*
    const int column = 6, row = 10000;
    int the_array[row][column];

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            the_array[i][j] = rand() % 101;
            cout << the_array[i][j] << endl;
        }  
    }
    */

    const int row = 10, col = 10;

    int generic[row][col];

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            generic[i][j] = rand() % 101;
            //cout << "Row: " << i << " and column: " << j << " is: " << generic[i][j] << setw(3) << endl;
            cout << setw(4) << generic[i][j];       //setw() is used to create the spaces between the numbers
        }
        cout << endl;
    }

    return 0;
}