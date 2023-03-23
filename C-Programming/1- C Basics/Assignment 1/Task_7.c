#include<stdio.h>
int main()
{
     printf("Enter Value A :");scanf("%d",&A);
     printf("Enter Value B :");scanf("%d",&B);
     A^=B;B^=A;A^=B;
     printf("Value A : %d\n",A);
     printf("Value B : %d\n",B);
}