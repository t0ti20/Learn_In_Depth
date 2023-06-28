//EXI: Prime Numbers Between two Intervals by Making User-defined Function
#include<stdio.h>
unsigned char Prime(int Number)
{
     unsigned char Flag=1,Count;
     for(Count=2;Count<=(Number>>1);Count++)
     {
          if(!(Number%Count))
          {
               Flag=0;break;
          }
     }
     return Flag;
}
int main()
{
     int Number;
     printf("Enter Any Number : ");
     scanf("%d",&Number);
     printf("Output = %s\n",Prime(Number)?"Is Prime":"Is Not Prime");
}