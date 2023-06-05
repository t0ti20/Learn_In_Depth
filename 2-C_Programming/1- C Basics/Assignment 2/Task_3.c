#include<stdio.h>
#define Max_Num          3
int main()
{
     int Number,Max;
     printf("Enter Any Numbers :\n");
     for(int Count=0;Count<Max_Num;Count++)
     {
          scanf("%d",&Number);
          Max=Number>Max?Number:Max;
     }
     printf("Maximum Number : %d\n",Max);
}