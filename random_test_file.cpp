#include<iostream>


//#include <stdio.h>
//#include <ctype.h>
 
int main(void)
{
   int ch;
 
   for (ch = 0; ch <= 0x7f; ch++)
   {
      printf("toupper=%#04x\n", toupper(ch));
      printf("tolower=%#04x\n", tolower(ch));
      putchar('\n');
      }
}