//EX2: C Program to Find the Length ofa String
#include<stdio.h>
extern int gets(char arr[]);
int main()
{
     char String[20];
     char Index=0;
     printf("Enter Any String : ");
     gets(String);
     while(String[Index])Index++;
     printf("Length = %d\n",Index);
}