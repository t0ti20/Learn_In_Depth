//EX4: Write a program in C to print the elements of an array in reverse order.
#define Max 15
#include<stdio.h>
#include<string.h>
void Scan_String(char Array[])
{
     unsigned char Index;
     printf("- Enter Your String : ");
     scanf("%s",Array);
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
int main()
{
     unsigned char Array[Max];
     Scan_String(Array);
     Reverse_Array(Array,strlen(Array));
     printf("Output = %s\n",Array);
}