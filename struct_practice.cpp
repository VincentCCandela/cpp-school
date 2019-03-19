#include<iostream>
using namespace std;



struct pokemon{
	string name;
	string type;
	int hp;
	int level;
	string attack;
	char is_shaggy;
};

int main (){
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
	cout << "Is your pokemon shaggy? (y/n)" << endl;
	cin >> Jed.is_shaggy;
	
	cout << endl;
	
	cout << Jed.name << "'s type is: " << Jed.type << "and it's hp, level, and attacks are: " << Jed.hp << " " << Jed.level << " " << Jed.attack << endl;

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
	cout << "Is your pokemon shaggy? (y/n)" << endl;
	cin >> Dan.is_shaggy;

	cout << Dan.name << "'s type is: " << Dan.type << "and it's hp, level, and attacks are: " << Dan.hp << " " << Dan.level << " " << Dan.attack << endl;

	return 0;
}