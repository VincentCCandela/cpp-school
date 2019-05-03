#include<iostream>
#include<iomanip>
using namespace std;

string encrypt(string message, int change);     //the function prototype for the Caesar Cipher encryption
string decode(string message, int change);      //the function prototype for the Caesar Cipher decryption

int main(){
    char response;  //declares the variable for if the user wants decrypt his encrypted message
    string the_message;     //declares the variable for the message that is encrypted/decrypted by the program
    int cipher;     //declares the shift amount for the cipher

    while(true)  {     //will run the program in perpetuity as shown in the "Example Outputs"
        cout << "What message would you like to encode? " << endl;      //asks the user for a message to encrypt
        getline(cin, the_message);     //inputs the message to encrypt, getline() is used to properly handle spaces

        cout << "What do you want the shift for your cipher to be? " << endl;       //asks for the shift for the cipher
        cin >> cipher;      //inputs the shift for the cipher
        
        cipher = cipher % 26;       //shifts of over 26 are meaningless because there are only 26 letters in the alphabet so cipher % 26 is taken

        the_message = encrypt(the_message, cipher);     //does the caesar cipher encryption scheme as determined by the shift number

        cout << "Your encoded message is" << endl;      //outputs the encoded message
        cout << the_message << endl;        

        cout << "Do you want to decrypt your message? (y/n)";       //asks the user if he wants to decrypt his message
        cin >> response;
        
        if (toupper(response) == 'Y'){      //asks the user if he wants to decrypt his message, toupper() is user to convert lowercase y to uppercase Y
            the_message = decode(the_message, cipher);    //decrypts the message
            cout << the_message << endl;        //outputs the decrypted message
        }
        else if (toupper(response) == 'N') {    //if the user doesn't want to decrypt then...
            cout << "It will always be a secret" << endl;   //...the user is told his message will always be safe
        }
        cin.ignore();
    } 
    return 0;
}

string encrypt(string message, int change){     //the function for caesar-cipher encryption using an inputted message to be encrypted and a shift value for the cipher
    for( int i = 0; i < message.length(); ++i){    //uses a for loop to iterate over all of the letters in the message
        if( message[i] >= 65 && message[i] <= 90 ){    //if the letter is uppercase (ASCII range 65-90)...
            message[i] += change;   //... shift amount is applied to the letter
            if ( message[i] > 90 ){     //if the letter has gone out of bounds, then...
                message[i] -= 26;   //the letter is put back in bounds
            }      
        }
        else if( message[i] >= 97 && message[i] <= 122){    //if the letter is lowercase (ASCII range 97-122)...
            message[i] += change;   //... shift amount is applied to the letter
            if( message[i] > 122 ){     //if the letter has gone out of bounds...
                message[i] -= 26;   //the letter is put back in bounds
            }
        } 
    }
    return message;    //if all of the letters have been shifted, then the message is returned
}

string decode(string message, int change){  //the decryption function for the caesar-cipher using the returned encrypted message and the used shifted amount
    for( int i = 0; i <= message.length(); ++i){    //iterates over each letter of the message 
        if( message[i] >= 65 && message[i] <= 90 ){    //if the letter is uppercase (ASCII range 65-90)...
            message[i] -= change;   //... then the letter is shifted over to the left
            if ( message[i] < 65 ){     //if the letter has been pushed out of bounds...
                message[i] += 26;   //...then the letter is put back in bounds
            }      
        }
        else if( message[i] >= 97 && message[i] <= 122){    //if the letter is uppercase (ASCII range 97-122)...
            message[i] -= change;   //... then the letter is shifted over to the left
            if( message[i] < 97 ){      //if the letter has been pushed out of bounds...
                message[i] += 26;   //...then the letter is put back in bounds
            }
        }
    }
    return message;     //if all of the letters have been shifted back, then the decrypted message is returned
}