#include<iostream>
#include<iomanip>

using namespace std;
int main(){
    const int row = 10, col = 10;
    int grades[row][col];
    
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            grades[i][j] = rand() % 101;
        }
    }

    cout << setw(15) << "Student #: " << endl;

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            cout << setw(4) << grades[i][j];
        }
        cout << endl;
    }



}