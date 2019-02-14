#include<iostream>
#include<cmath>
using namespace std;

char grader(double grade);
string addendum(double a);

int main(){

double grade1, average, total;                                                                                  
int round = 1;                                                                                                 
                                                                                                               
average = 0;                                                                                                   
cout << "Enter your grade: " << endl;                                                                          
cin >> grade1;                                                                                                  
                                                                                                               
average = grade1;                                                                                               
total = grade1;                                                                                                 
                                                                                                               
while(grade1 != 101) {                                                                                          
        if (grade1 == 101 ){                                                                                    
                                                                                                               
                }                                                                                              
        else if(grade1 != 101){                                                                                 
                round++;                                                                                       
                cout << "Enter your grade: " << endl;                                                          
                cin >> grade1;                                                                                  
                total = total + grade1;                                                                         
                average = (total) / round;                                                                     
                if(grade1 != 101){                                                                              
                        cout << fixed << setprecision(3) << "Your average is: " << average << endl;            
                        }                                                                                      
                else{                                                                                          
                                                                                                               
                        }                                                                                      
                }                                                                                              
}                           
	
string letter_grade;
double Grade;
cout << "What is your grade: " << endl;
cin >> Grade;
letter_grade = grader(Grade);
string the_addendum = addendum(Grade);
cout << "Your final grade is: " << letter_grade << the_addendum << endl;

return 0;
}

string addendum(double a){
double b = fmod(a,10);
if (b >= 0 && b <=3){
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
//return 'z';
}
