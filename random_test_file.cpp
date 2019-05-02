#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    string change = "lowercase aNd ;/,./ UPPERCASE";
    transform(change.begin(), change.end(), change.begin(), ::toupper);
    cout << change << endl;

    /*
    for( int i = 0; i < change.length(); ++i ){
        change[i] = change[i] - 64;
    } 
    */
    
    //cout << change << endl;


    return 0;
}