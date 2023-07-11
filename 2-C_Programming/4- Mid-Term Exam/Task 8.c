#include <stdio.h>
void Reverse_Array(char Array[],unsigned char Size)
{
     int Counter;
     for(Counter=0;Counter<(Size>>1);Counter++)
     {
          Array[Counter]^=Array[Size-Counter-1];
          Array[Size-Counter-1]^=Array[Counter];
          Array[Counter]^=Array[Size-Counter-1];
     }
}
int main ()
{
     int Counter;
     char Array[]={1,2,3,4,5};
     Reverse_Array(Array,5);
     for(Counter=0;Counter<5;Counter++)printf("%d ",Array[Counter]);
}