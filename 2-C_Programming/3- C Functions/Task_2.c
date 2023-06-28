//EX2:Calculate Factorial of a Number Usin Recursion
#include<stdio.h>
int Factorial(int Number)
{
     return Number?(Factorial(Number-1)*Number):1;
}
int main()
{
     int Number;
     printf("Enter Any Number : ");
     scanf("%d",&Number);
     printf("Output = %d\n",Factorial(Number));
}