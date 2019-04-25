#include<iostream>
#include<iomanip>
using namespace std;

string encrypt(string input, int change, string output);
string decode();

int main(){
    string message, encoded_message;

    cout << "What message do you want to encode?" << endl;
    cin >> message;

    cout << "What do you want the shift for your cipher to be?" << endl;
    cin >> cipher;

    encrypt(message, cipher, encoded_message);

    cout << "Your encoded message is" << endl;
    cout << encoded_message;





    return 0;
}

string encrypt(string message, string output){
    for(int i = )
    
    return output;
}
