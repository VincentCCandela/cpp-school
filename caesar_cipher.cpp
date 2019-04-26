#include<iostream>
#include<iomanip>
using namespace std;

string encrypt(int i, string message, int change, int temp_change);
string decode();

int main(){
    char response;
    int length;

    cout << "Do you want to encrypt a message? (y/n): ";
    cin >> response;
    
    while ( toupper(response) == 'Y'){
        
        string message, encoded_message;

        cout << "What message do you want to encode?" << endl;
        cin >> message;

        length = message.length();

        cout << "What do you want the shift for your cipher to be?" << endl;
        cin >> cipher;
        
        cipher = cipher % 26;

        encoded_message = encrypt(0 ,message, cipher, );

        cout << "Your encoded message is" << endl;
        cout << encoded_message;

        cout << "Do you want to decrypt your message? (y/n)"
        cin >> response;
    }




    return 0;
}

string encrypt(int i, string message, int change, int tempchange){
    for( int i = 0; i <= message.length(); ++i){
    
    if(i == message.length() ){
        return message;
    else if( message[i] >= 65 && message[i] <= 90 ){
        message[i] = message[i] + change;
        if ( message[i] > 90 ){
            message[i] = message[i] - 26;
        }      
    }
    else if( message[i] >= 97 && message[i] <= 122){
        message[i] = message[i] + change;
        if( message[i] > 122 ){
            message[i] = message[i] - 26;
        }
    }
        
    }
}
