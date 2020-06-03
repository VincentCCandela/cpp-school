#include<iostream>
#include<iomanip>

using namespace std;
int main(){
    srand(time(NULL));
    const int row = 10, col = 10;
    int grades[row][col], averages[row] = {0}, sum, multiplier;

    
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            grades[i][j] = rand() % 101;
        }
    } //h

    cout << setw(15) << "Student #: " << endl;

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            cout << setw(4) << grades[i][j];
        }
        cout << endl;
    }

    for(int i = 0; i < row; ++i){
        sum = 0;
        for(int j = 0; j < col; ++j){
            sum += grades[i][j];
        }
        averages[i] = sum / row;
    }

    cout << "The class averages are: "<<   endl;
    for(int i = 0; i < row; ++i){
        cout << "Student #" << i + 1 << ") " << averages[i] << endl;
    }

    cout << "Enter a multiplier: ";
    cin >> multiplier;

    cout << "The new class averages are: "<<   endl;
    for(int i = 0; i < row; ++i){
        cout << "Student #" << i + 1 << ") " << multiplier * averages[i] << endl;
    }
    
}