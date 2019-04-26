#include<iostream>
#include<iomanip>
using namespace std;

string encrypt(string message, int change);
string decode(string message, int change);

int main(){
    char response;

    cout << "Do you want to encrypt a message? (y/n): ";
    cin >> response;
    
    for(; ;)  {
        
        string the_message;
        int cipher;

        cout << "What message do you want to encode?" << endl;
        cin >> the_message;

        cout << "What do you want the shift for your cipher to be?" << endl;
        cin >> cipher;
        
        cipher = cipher % 26;

        the_message = encrypt(the_message, cipher);

        cout << "Your encoded message is" << endl;
        cout << the_message << endl;

        cout << "Do you want to decrypt your message? (y/n)";
        cin >> response;
        
        if (toupper(response) == 'Y'){
            //decode(the_message);
        }
        else{
            cout << "It will always be a secret" << endl;
        }
    } 




    return 0;
}

string encrypt(string message, int change){
    for( int i = 0; i <= message.length(); ++i){
        if(i == message.length() ){
            return message;
        }
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
