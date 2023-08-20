//EX4: Write a program in C to print the elements of an array in reverse order.
#define Max 15
#include<stdio.h>
unsigned char Scan_Array(unsigned char Array[])
{
     unsigned char Index;
     printf("- Enter Number Of Elements : ");
     scanf("%hhd",&Index);
     for(unsigned char Counter=0;Counter<Index;Counter++)
     {
          printf("- Enter [%d] Element : ",Counter+1);
          scanf("%hhd",&Array[Counter]);
     }
     return Index;
}
void Reverse_Array(unsigned char Array[],unsigned char Index)
{
     for(unsigned char Counter=0;Counter<(Index>>1);Counter++)
     {
          Array[Counter]^=Array[Index-Counter-1];
          Array[Index-Counter-1]^=Array[Counter];
          Array[Counter]^=Array[Index-Counter-1];
     }
}
void Print_Array(unsigned char Array[],unsigned char Index)
{
     for(unsigned char Counter=0;Counter<Index;Counter++)
     {
          printf("- Element [%hhd] : %hhd\n",Counter+1,Array[Counter]);
     }
}
int main()
{
     unsigned char Array[Max],Index=Scan_Array(Array);
     Reverse_Array(Array,Index);
     Print_Array(Array,Index);
}