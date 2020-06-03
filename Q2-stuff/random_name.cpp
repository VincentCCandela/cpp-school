#include<iostream>
using namespace std;

string concat(string s1, string s2);

int main(){
	srand(time(NULL));
	
	string fname[4] = {"asdfasd","asdfasdf","asdfasdf","asdfasdf"};
	string lname[4] = {"asdfasdf","asdf","asdfasdf","asdfsadf"};
	
	int first = rand()%4;
	int last = rand()%4;
	
	cout << "adsfasf" << concat(fname[first], lname[last]) << endl;
	
	return 0;
}

string concat(string s1, string s2){
	return s1 + " " + s2;
}