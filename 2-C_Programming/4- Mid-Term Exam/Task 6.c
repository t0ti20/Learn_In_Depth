#include <stdio.h>
char Unique_Number(char Array[])
{
     unsigned char Index,Count,Flag;
     for(Index=0;Array[Index];Index++)
     {
          for(Count=0,Flag=0;Array[Count];Count++)
          {
               if (Array[Index]==Array[Count])Flag++;
          }
          if(Flag==1)return Array[Index];
     }
     return -1;
}
int main ()
{
     char a[8]={4,2,5,2,5,7,4,'\0'};
     char b[4]={4,2,4,'\0'};
     printf("%hhd\n",Unique_Number(a));
     printf("%hhd\n",Unique_Number(b));
}