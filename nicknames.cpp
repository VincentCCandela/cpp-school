#include<iostream>
#include<string.h>

using namespace std;

int main(){
	string name,first_part,second_part,nickname;
	
	cout << "Enter your name to create a nickname: ";
	getline(cin,name);
	
	first_part = name.substr( 0 , 3 );
	second_part = name.substr( 3 , name.length() );
	
	nickname = second_part + first_part;
	
	
	
	
	
	
	cout << "Your new nickname is: " << nickname << endl;

	return 0;
}