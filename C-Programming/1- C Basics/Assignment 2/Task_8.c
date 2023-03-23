#include<stdio.h>
int main()
{
     float A,B;
     unsigned char Option;
     printf("What Do You Want To Do ?\n-1) +\n-2) *\n-3) -\n-4) /\n");
     printf("Option :");Option=getchar();
     printf("Enter First Operand :");scanf("%f",&A);
     printf("Enter Second Operand :");scanf("%f",&B);
     switch (Option)
     {
     case '1':
     case '+':A+=B;
     break;
     case '2':
     case '*':A*=B;
     break;
     case '3':
     case '-':A-=B;
     break;
     case '4':
     case '/':A/=B;
     break;
     default:printf("Wrong Input !\n");
     }
     printf("Answer = %.2f\n",A);
}