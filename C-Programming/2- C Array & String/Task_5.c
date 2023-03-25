//EX5: C Program to Search an element in Array
#include<stdio.h>
int main()
{
     int Number,Array[20];
     char Count,Index;
     printf("Enter Number Of Elemets : ");
     scanf("%hhd",&Count);
     for(Index=0;Index<Count;Index++)
     {
          printf("Enter [%d] Element : ",Index+1);
          scanf("%d",(Array+Index));
     }
     printf("Enter Number To Search : ");
     scanf("%d",&Number);
     for(Index=0;Index<Count;Index++)if(Array[Index]==Number)break;
     printf("%s%d\n",Index==Count?"Can't Find The Item":"Item Index = ",Index+1);
}