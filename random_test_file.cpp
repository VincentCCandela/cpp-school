#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    string one,two,output;

    cin >> one;
    cin >> two;
    cin >> output;

    output[1] = output[1] + 5;

    cout << output << "done " << endl;

    return 0;
}