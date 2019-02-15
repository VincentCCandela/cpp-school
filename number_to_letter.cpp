#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

char grader(double grade);
string addendum(double a);

int main(){

double Grade, average, total;                                                                                  
int round = 1;                                                                                                 
                                                                                                               
average = 0;                                                                                                   
cout << "Enter your grade: " << endl;                                                                          
cin >> Grade;                                                                                                  
                                                                                                               
average = Grade;                                                                                               
total = Grade;                                                                                                 
                                                                                                               
while(Grade != 101) {                                                                                          
        if (Grade == 101 ){                                                                                    
                                                                                                               
                }                                                                                              
        else if(Grade != 101){                                                                                 
                round++;                                                                                       
                cout << "Enter your grade: " << endl;                                                          
                cin >> Grade;                                                                     
                if(Grade != 101){
			total = total + Grade;
			average = (total) / round;
                        cout << fixed << setprecision(3) << "Your average is: " << average << endl;
			cout << "Which is a: " << grader(average) << addendum(average) << endl;
                        }                                                                                      
                else{                                                                                          
                                                                                                               
                        }                                                                                      
                }                                                                                              
}                           
	
/*double Grade;
cout << "What is your grade: " << endl;
cin >> Grade; */
char letter_grade = grader(average);
string the_addendum = addendum(average);
cout << "Your final grade is: " << average <<letter_grade << the_addendum << endl;

return 0;
}

string addendum(double a){
double b = fmod(a,10);
if ( a >= 97){
	return " + ";
	}
else if (b >= 0 && b <=3){
	return " - ";
	}
else if (b > 3 && b < 7){
	return " ";
	}
else{
	return " + ";
	}
}

char grader(double grade){
if (grade >= 90){
	return 'A';
	}
else if (grade >= 80 && grade < 90){
	return 'B';
	}
else if (grade >= 70 && grade < 80){
	return 'C';
	}
else if (grade >= 60 && grade <70){                                        
        return 'D'; 
	}
else if (grade >= 50 && grade <60){                                        
        return 'E'; 
	}
else if (grade >= 40 && grade <50) {                                       
        return 'F'; 
	}
else if (grade >= 30 && grade <40){                                        
        return 'G';
	}
else if (grade >= 20 && grade <30){                                        
        return 'H';
	}
else if (grade >= 10 && grade <20){                                        
        return 'I';
	}
else if (grade >= 0 && grade <10){                                        
	return 'J';
	}
}
