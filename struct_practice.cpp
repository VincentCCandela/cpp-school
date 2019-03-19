#include<iostream>
using namespace std;



struct pokemon{
	string name;
	string type;
	int hp;
	int level;
	string attack;
	char is_shaggy;
}

int main (){
	pokemon Jed;
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


	return 0;
}