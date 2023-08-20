#include <stdio.h>
int Sum_Digits(int Number)
{
     return Number?(Sum_Digits(Number/10)+(Number%10)):0;
}
int main ( )
{
     printf("%d\n",Sum_Digits(123));
     printf("%d\n",Sum_Digits(4565));
}