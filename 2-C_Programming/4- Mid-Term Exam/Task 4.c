#include <stdio.h>
int Reverse_Digit(int Number)
{
     static float Base=0.1;
     if(Number) return (Reverse_Digit(Number/10)+(Number%10)*(Base*=10));
     else Base=0.1;
}
int main ()
{
     printf("%d\n",Reverse_Digit(2457));
     printf("%d\n",Reverse_Digit(1057));
}