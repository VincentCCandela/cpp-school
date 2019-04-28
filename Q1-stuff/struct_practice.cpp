#include<iostream>
using namespace std;



struct pokemon {
	string name;
	string type;
	int hp;
	int level;
	string attack;
	char is_shaggy;
};

struct program {
	string name;
	char fast;
	char common;
};

int main (){
	program one;
	
	cout << "What is the name of your program" << endl;
	cin >> one.name;
	cout << "Is your language fast? (y/n)" << endl;
	cin >> one.fast;
	cout << "Is it a common language? (y/n)" << endl;
	cin >> one.common;
	
	pokemon Jed;
	pokemon Dan;
	
	cout << "What is your pokemon's name?" << endl;
	cin >> Jed.name;
	cout << "What is your pokemon's type?" << endl;
	cin >> Jed.type;
	cout << "What is your pokemon's hp?" << endl;
	cin >> Jed.hp;
	cout << "What is your pokemon's level?" << endl;
	cin >> Jed.level;
	cout << "What is your pokemon's attack?" << endl;
	cin >> Jed.attack;
	
	while (Jed.is_shaggy != 'y' && Jed.is_shaggy != 'Y'  &&  Jed.is_shaggy != 'n' && Jed.is_shaggy != 'N') {
		cout << "Is your pokemon shaggy? (y/n)" << endl;
		cin >> Jed.is_shaggy;
	}
	
	cout << endl;
	
	cout << Jed.name << "'s type is: " << Jed.type << "and it's hp, level, and attacks are: " << Jed.hp << " " << Jed.level << " " << Jed.attack << endl;

	if (Jed.is_shaggy == 'y' || Jed.is_shaggy == 'Y'){
		cout << "Your pokemon is a shaggy." << endl;
	}
	else {
		cout << "Your pokemon is not a shaggy." << endl;
	}

	cout << "What is your pokemon's name?" << endl;
	cin >> Dan.name;
	cout << "What is your pokemon's type?" << endl;
	cin >> Dan.type;
	cout << "What is your pokemon's hp?" << endl;
	cin >> Dan.hp;
	cout << "What is your pokemon's level?" << endl;
	cin >> Dan.level;
	cout << "What is your pokemon's attack?" << endl;
	cin >> Dan.attack;

	while (Dan.is_shaggy != 'y' && Dan.is_shaggy != 'Y'  &&  Dan.is_shaggy != 'n' && Dan.is_shaggy != 'N') {
		cout << "Is your pokemon shaggy? (y/n)" << endl;
		cin >> Dan.is_shaggy;
	}

	cout << endl;
	
	cout << Dan.name << "'s type is: " << Dan.type << "and it's hp, level, and attacks are: " << Dan.hp << " " << Dan.level << " " << Dan.attack << endl;

	if (Dan.is_shaggy == 'y' || Dan.is_shaggy == 'Y'){
		cout << "Your pokemon is a shaggy." << endl;
	}
	else {
		cout << "Your pokemon is not a shaggy." << endl;
	}


	cout << Dan.name << "'s type is: " << Dan.type << "and it's hp, level, and attacks are: " << Dan.hp << " " << Dan.level << " " << Dan.attack << endl;

	return 0;
}