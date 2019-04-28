#include<iostream>
using namespace std;

bool leprosy(char exists);

int main(){
	char e;
	cout << "Does Ethan exist? (y/n)"<< endl;
	cin >> e;
	if (leprosy(e) == true){
		cout << "Ethan is and always will be a leper" << endl;
	}
	else{
		cout << "Ethan is not a leper" << endl;
	}
	
	
	
	return 0;
}

bool leprosy(char exists){
	if (exists == 'y' || exists == 'Y'){
		return true;
	}
	else if (exists == 'n' || exists == 'N'){
		return false;
	}
	else{
		cout << "That is not an input option" << endl;
		return 0;
	}
		
}