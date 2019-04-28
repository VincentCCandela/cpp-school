/*
This program tells you how many hours or minutes are in x many days.

Errors Types:
1 type of addition
2 changes 
2 deletions 

10 points total

NO MAJOR CHANGES (only ONE line should be completely changed, otherwise, just tweak the code)
*/


#include<iostream>

using namespace std;

void DaystoHrsMin(int days, int & hours, int & min); //made hours and min passed by reference 

int main()
{
	int h = 0;
	int m = 0;
	for(int d = 1; d <= 10; d++) //removed a semicolon
	{
		DaystoHrsMin(d,h,m); //moved d to be the first variable, h the second variablem and then m the third variable
		cout << d << " day(s) is " << h << " hours or " << m << " minutes." << endl;
	}
	
	return 0;
}

void DaystoHrsMin(int days, int & hours, int & min) //made the variables hours and min passed by reference //changed days from double to int
{
	hours = 24 * days;
	min = 1440 * days;
	
	// removed the return statement "return hours, min;"
}