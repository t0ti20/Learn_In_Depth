//EX3: EX3: C Program to Add Two Complex Numbers by Passing Structure to a Function
#include<stdio.h>
typedef struct Data
{
     float Real;
     float Imaginary;
}Data;
int main()
{
     Data Variable_1,Variable_2;
     printf("Enter Real And Imaginary Respectively:\n");
     printf("Number One :");scanf("%f %f",&Variable_1.Real,&Variable_1.Imaginary);
     printf("Number Two :");scanf("%f %f",&Variable_2.Real,&Variable_2.Imaginary);
     printf("(%.2f + %.2fi) + (%.2f + %.2fi) = %.2f + %.2fi\n",Variable_1.Real,Variable_1.Imaginary,Variable_2.Real,Variable_2.Imaginary,Variable_1.Real+Variable_2.Real,Variable_1.Imaginary+Variable_2.Imaginary);
}