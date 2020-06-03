#include<iostream>
#include <string.h> 

using namespace std;

int main (){
	//an array of characters
	string fname,lname;
	
	cout << "What is your first name?" << endl;
	getline(cin,fname);
	
	cout << "Your normal name is: " << fname << endl;
	cout << "Your long name is: " << endl;
	
	for (int i = 0; i < fname.length(); ++i){
		cout << fname[i] << endl;
	}
	cout << endl;
	
	cout << "Your backwards name is: ";

	for(int i = fname.length() - 1; i >= 0; --i){
		cout << fname[i];
	} 
	
	cout << endl;
	
	//name.substr(3,3);

	cout << "What is your last last name?" << endl;
	getline(cin,lname);

	string full_name = fname + " " + lname;
	
	cout << full_name;
	
	cout << endl;

	return 0;
}