#include<iostream>
#include<iomanip>
using namespace std;

string encrypt(string message, string change);     //the function prototype for the Caesar Cipher encryption
string decode(string message, string change);      //the function prototype for the Caesar Cipher decryption

int main(){
    char response;  //declares the variable for if the user wants decrypt his encrypted message
    string the_message;     //declares the variable for the message that is encrypted/decrypted by the program
    string cipher;     //declares the passcode for the cipher
    
    while(true)  {     //will run the program in perpetuity as shown in the "Example Outputs"
        cout << "What message would you like to encode? " << endl;      //asks the user for a message to encrypt
        getline(cin, the_message);     //inputs the message to encrypt, getline() is used to properly handle spaces

        cout << "What do you want the passcode for your cipher to be? (only a continuous string of uppercase or lowercase alphabetic characters) " << endl;       //asks for the passcode for the cipher
        cin >> cipher;      //inputs the  for the cipher
        
        for(int i = 0; i < the_message.length(); ++i){      //convert the message to uppercase letters
            the_message[i] = toupper(the_message[i]);
        }

        for(int i = 0; i < cipher.length(); ++i){   //convert the cipher to uppercase letters
            cipher[i] = toupper(cipher[i]);
        }
        
        the_message = encrypt(the_message, cipher);     //does the caesar cipher encryption scheme as determined by the passcode

        cout << "Your encoded message is" << endl;      //outputs the encoded message
        cout << the_message << endl;        

        cout << "Do you want to decrypt your message? (y/n) ";       //asks the user if he wants to decrypt his message
        cin >> response;
        
        if (toupper(response) == 'Y'){      //asks the user if he wants to decrypt his message, toupper() is user to convert lowercase y to uppercase Y
            the_message = decode(the_message, cipher);    //decrypts the message
            cout << the_message << endl;        //outputs the decrypted message
        }
        else if (toupper(response) == 'N') {    //if the user doesn't want to decrypt then...
            cout << "It will always be a secret" << endl;   //...the user is told his message will always be safe
        }

        cin.ignore();       //remove \n from iostream in order to use getline()
    } 
    return 0;
}

string encrypt(string message, string change){     //the function for caesar-cipher encryption using an inputted message to be encrypted and a passcode for the cipher
    int place = 0;      //a counter for the place of the passcode
    
    for( int i = 0; i < change.length(); ++i ){     //converts the alphabetic shifts into numberic shifts
        if( change[i] >= 65 && change[i] <= 90 ){      //if the character is a letter, then it is converted
            change[i] -= 64;
        }
    } 

    for( int i = 0; i < message.length(); ++i){    //uses a for loop to iterate over all of the letters in the message      
        if( message[i] >= 65 && message[i] <= 90 ){    //if the character is a letter, then it is encrypted
            if(place > change.length() - 1){        //if the place has gone out of bounds, it is put back in bounds
                place -= change.length();
            }

            message[i] += change[place];        //shift is applied to the letter

            if ( message[i] > 90 ){     //if the letter has gone out of bounds, then...
                message[i] -= 26;   //the letter is put back in bounds
            }

            ++place;      //place is increased by one because the letter has been encrypted
        }
    }
    return message;     //returns the encrypted message
}

string decode(string message, string change){     //the function for caesar-cipher decryption using an inputted message to be decrypted and a passcode for the cipher
    int place = 0;      //a counter for the place of the passcode
    
    for( int i = 0; i < change.length(); ++i ){     //converts the alphabetic shifts into numberic shifts
        if( change[i] >= 65 && change[i] <= 90 ){      //if the character is a letter, then it is converted
            change[i] -= 64;
        }
    } 

    for( int i = 0; i < message.length(); ++i){    //uses a for loop to iterate over all of the letters in the message      
        if( message[i] >= 65 && message[i] <= 90 ){    //if the character is a letter, then it is decrypted
            if(place > change.length() - 1){        //if the place has gone out of bounds, it is put back in bounds
                place -= change.length();
            }

            message[i] -= change[place];        //shift is applied to the letter

            if ( message[i] < 65 ){     //if the letter has gone out of bounds, then...
                message[i] += 26;   //the letter is put back in bounds
            }

            ++place;      //place is increased by one because the letter has been altered
        }
    }
    return message;     //returns the decrypted message
}