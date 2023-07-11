#include<stdio.h>
int main()
{
     int A;
     printf("Enter Any Number :");scanf("%d",&A);
     printf("Your Number Is %s\n",(A>>(sizeof(A)<<2))?"Negative":"Positive");
}