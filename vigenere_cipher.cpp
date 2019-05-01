#include<iostream>
#include<iomanip>
using namespace std;

string encrypt(string message, string key_code, string);
string decrypt(string message, string key_code, string);
string key_coder(string message);
void swap(int & a, int & b);

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

string key_coder(string message){
    for(int i = 0; i < size; i++){
		int j = i;
		while((j > 0) && (array[j - 1] > array[j])){
			swap(array[j],array[j - 1]);
			j = j - 1;
		}
	}



}

void swap(int & a, int & b){
	int tempvar = a;
	a = b;
	b = tempvar;
}