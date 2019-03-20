#include<iostream>
using namespace std;

struct os {
	string name;
	double version;
	char fast;
	char common;
};

int main (){
	os windows;
	
	cout << "What is the name of your program" << endl;
	cin >> windows.name;
	
	cout << "What is the version of your OS?" << endl;
	cin >> windows.version;
	
	while (windows.fast != 'y' && windows.fast != 'Y'  &&  windows.fast != 'n' && windows.fast != 'N') {
		cout << "Is your OS fast? (y/n)" << endl;
		cin >> windows.fast;
	}
	
	if (windows.fast == 'y' || windows.fast == 'Y'){
		cout << "Your OS is fast." << endl;
	}
	else {
		cout << "Your OS is not fast." << endl;
	}

	
	while (windows.common != 'y' && windows.common != 'Y'  &&  windows.common != 'n' && windows.common != 'N') {
		cout << "Is your OS common? (y/n)" << endl;
		cin >> windows.common;
	}
	
	if (windows.common == 'y' || windows.common == 'Y'){
		cout << "Your OS is common." << endl;
	}
	else {
		cout << "Your OS is not common." << endl;
	}
	
	os mac;
	
	cout << "What is the name of your program" << endl;
	cin >> mac.name;
	
	cout << "What is the version of your OS?" << endl;
	cin >> mac.version;
	
	while (mac.fast != 'y' && mac.fast != 'Y'  &&  mac.fast != 'n' && mac.fast != 'N') {
		cout << "Is your OS fast? (y/n)" << endl;
		cin >> mac.fast;
	}
	
	if (mac.fast == 'y' || mac.fast == 'Y'){
		cout << "Your OS is fast." << endl;
	}
	else {
		cout << "Your OS is not fast." << endl;
	}

	
	while (mac.common != 'y' && mac.common != 'Y'  &&  mac.common != 'n' && mac.common != 'N') {
		cout << "Is your OS common? (y/n)" << endl;
		cin >> mac.common;
	}
	
	if (mac.common == 'y' || mac.common == 'Y'){
		cout << "Your OS is common." << endl;
	}
	else {
		cout << "Your OS is not common." << endl;
	}
	
	return 0;
}
