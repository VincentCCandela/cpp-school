#include<iostream>
using namespace std;

int main(){
    
    char answer;

    cout << "Do you want ice cream? (y/n)";
    cin >> answer;

    if(toupper(answer) == 'Y'){     //toupper() forces a char into it's uppercase value
        cout << "Donate monies to SJP" << endl;
    }      
    else if (toupper(answer) == 'N'){
        cout << "How dare u!" << endl;
    }
    
    char symbol;
    int amount;

    cout << "Enter a symbol you wish to add: ";
    cin >> symbol;

    cout << "Enter the amount you wish to add: ";
    cin >> amound;

    cout << endl;

    cout << symbol << " + " << amount << " = " << symbol + amount << endl;

    return 0;
}