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
    
    
    return 0;
}