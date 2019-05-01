#include<iostream>
#include<iomanip>
using namespace std;

string encrypt(string message, string key_code, string);
string decrypt(string message, string key_code, string);
string key_coder(string message);
void swap(int & a, int & b);

//watchcartonsonline.com , watchcartons.com
//

int main(){
    string text, keyphrase;

    cout << "Input a message to encrypt: ";
    getline(cin, text);

    cout << "Enter a key phrase: ";
    getline(cin, keyphrase);

    encrypt(text, keyphrase)






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
    for(int i = 0; i < original_message.length() ; ++i){
        int j = i;
        if(original_message[i] == 0){

        }
        else{

        }
    }

    /*
    for(int i = 0; i < message.length(); ++i){
		int j = i;
		while(message[j] == 32 && ( array[j + 1] != 0 || array[j + 2] != 0)  ){
			swap(message[j], message[j + 1]);
			j = j + 1;
		}
	}
    */
    for(int i = 0; i < the_length; ++i){
        
    }

}

void swap(int & a, int & b){
	int tempvar = a;
	a = b;
	b = tempvar;
}