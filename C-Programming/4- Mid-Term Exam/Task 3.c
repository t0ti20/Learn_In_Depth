#include <stdio.h>
void Prime_Numbers(int Start_Number,int End_Number) 
{
     int Count;
     for(;Start_Number<=End_Number;Start_Number++)
     {
          for(Count=2;Count<=(Start_Number>>1);Count++) if(!(Start_Number%Count))break;
          if(--Count==(Start_Number>>1))printf("%d ",Start_Number);
     }
}
int main ()
{
     Prime_Numbers(1,20);
}