#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

string encrypt(string message, string key_code);
string decrypt(string message, string key_code);
string key_coder(string passcode, string original_message);
void swap(int & a, int & b);

//watchcartonsonline.com , watchcartons.com
//

int main(){
    string text, keyphrase;

    cout << "Input a message to encrypt: ";
    getline(cin, text);

    cout << "Enter a key phrase: ";
    getline(cin, keyphrase);

    encrypt(text, keyphrase);


    return 0;
}


string encrypt(string message, string key_code){
	string full_key = key_coder(key_code, message);
    


    for(int i = 0; i <= message.length(); ++i){
        if(i == message.length() ){     //if all of the letters have been adjusted, then the message is returned
            return message;
        }
        else if (message[i] == 32){     //if the letter is a space...
            message[i] = 32;     //... then the letter is kept as a space
        }

    }
}

string decrypt(string message, string key_code){

}

string key_coder(string passcode, string original_message){
    int j = 0, total_places = passcode.length() - 1;
    string the_full_key;
    for(int i = 0; i < original_message.length(); ++i){
        if(original_message[i] == 32){
            the_full_key = 32;
        }
        else if( ( (original_message[i] >= 65 && original_message[i] <= 90 ) || ( original_message[i] >= 97 && original_message[i] <= 122) )&& ( j <= total_places) ) {
            the_full_key[i] = passcode[j];
            j += 1;
        }
        else if( ( (original_message[i] >= 65 && original_message[i] <= 90 ) || ( original_message[i] >= 97 && original_message[i] <= 122) ) && ( j > total_places) ) {
            j = j % total_places;
            the_full_key[i] = passcode[j];
            j += 1;
        }
        else {

        }
    }

    cout << the_full_key << endl;

}

void swap(int & a, int & b){
	int tempvar = a;
	a = b;
	b = tempvar;
}