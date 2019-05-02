#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    string original_message = "blah bla";
    string passcode = "code";
    cout << passcode[2] << endl;
    passcode[2] = 70;
    cout << passcode[2] << endl;

    cout << original_message.length() << endl;

    int j = 0, total_places = passcode.length() - 1;
    string the_full_key;
    for(int i = 0; i < original_message.length(); ++i){
        if(original_message[i] == 32){
            the_full_key[i] = 32;
        }
        else if( ( (original_message[i] >= 65 && original_message[i] <= 90 ) || ( original_message[i] >= 97 && original_message[i] <= 122) ) && ( j <= total_places) ) {
            the_full_key[i] = passcode[j];
            j++;
            cout << the_full_key << endl;
        }
        else if ( ( (original_message[i] >= 65 && original_message[i] <= 90 ) || ( original_message[i] >= 97 && original_message[i] <= 122) ) && ( j > total_places) ) {
            j = j % total_places;
            the_full_key[i] = passcode[j];
            j++;
            cout << the_full_key << endl;
        }
    }

    cout << the_full_key << endl;



    return 0;
}