#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    string original_message = "blah blabbety blah";
    string passcode = "code";
    cout << passcode[2] << endl;
    passcode[2] = 70;
    cout << passcode[2] << endl;

    int j = 0, total_places = passcode.length() - 1;
    string the_full_key;
    for(int i = 0; i < original_message.length(); ++i){
        if(original_message[i] == 32){
            the_full_key = 32;
        }
        else if( ( (original_message[i] >= 65 && original_message[i] <= 90 ) || ( original_message[i] >= 97 && original_message[i] <= 122) ) && ( j <= total_places) ) {
            the_full_key[i] = passcode[j];
            j += 1;
        }
        else if( ( (original_message[i] >= 65 && original_message[i] <= 90 ) || ( original_message[i] >= 97 && original_message[i] <= 122) ) && ( j > total_places) ) {
            j = j % total_places;
            the_full_key[i] = 's';
            j += 1;
        }
        else {

        }
    }

    cout << the_full_key << endl;



    return 0;
}