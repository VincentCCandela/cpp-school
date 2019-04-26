#include<iostream>
#include<iomanip>
using namespace std;

string encrypt(int i, string message, int change);
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

        encoded_message = encrypt(0 ,message, cipher, outpute);

        cout << "Your encoded message is" << endl;
        cout << encoded_message;

        cout << "Do you want to decrypt your message? (y/n)"
        cin >> response;
    }




    return 0;
}

string encrypt(int i, string message, int change){
    if(i == (message.length() - 1) ){
        return message;
    else if( ( message[i] >= 65 && message[i] <= 90) ){
        int temp_change = change;
        //temp_change = temp_change % 26;
        if ( (message[i] + temp_change ) > 90 ){
           message[i] == 65;
           return message
        }

        message[i] = message[i] + (change % 26)

    }
    else if( (message[i] + change) >= 122 ){

    }
    }

    
    return output;
}
