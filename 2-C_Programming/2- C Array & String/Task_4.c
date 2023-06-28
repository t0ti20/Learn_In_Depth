//EX4: C Program to Insert an element in an Array
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
     printf("Enter Location : ");scanf("%hhd",&Index);
     for(;Count>=Index;Count--)Array[Count]=Array[Count-1];
     printf("Enter Number To Insert : ");scanf("%d",&Number);
     Array[Count]=Number;
     for(Index=0;Array[Index];Index++)printf("- Element [%d] = %d\n",Index+1,Array[Index]);
}