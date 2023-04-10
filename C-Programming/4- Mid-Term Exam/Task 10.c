#include <stdio.h>
char Maximum_Zeros(int Number)
{
     char Flag=0,Ones=0,Counter_1,Counter_2;
     for(Counter_1=0;Counter_1<(sizeof(Number)<<2);Counter_1++)
     {
          if(!(Number>>Counter_1&1))for(Counter_2=Counter_1+1,Flag=0;Number>>Counter_2&1;Counter_2++)Flag++;
          Ones=Flag>Ones?Flag:Ones;
     }
     return Ones;
}

int main ()
{
     printf("%d\n",Maximum_Zeros(14));
     printf("%d\n",Maximum_Zeros(110));
     return 0;
}