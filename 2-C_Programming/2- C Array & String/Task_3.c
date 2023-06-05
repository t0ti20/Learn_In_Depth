//EX3: C Program to Reverse String Without Using Library Function
#include<stdio.h>
int main()
{
     char String[]="123456789";
     char Index=-1;
     while(String[Index+1])Index++;
     for(char Count=0;Count<(Index/2);Count++)
     {
          String[Count]^=String[Index-Count];
          String[Index-Count]^=String[Count];
          String[Count]^=String[Index-Count];
     }
     puts(String);
}