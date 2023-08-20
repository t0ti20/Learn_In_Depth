#include <stdio.h>
double Square_Root(double Number) 
{
     //Accuracy
     int Flag=10;
     double Count=0,Result=(Number/2);
     while ((Result-Count)&&Flag--)
     {
          Count=Result;
          Result=(Number+(Count*Count))/(2*Count);
     }
     return Result;
}
int main ()
{
     printf("%f\n",Square_Root(4));
     printf("%f\n",Square_Root(10));
}