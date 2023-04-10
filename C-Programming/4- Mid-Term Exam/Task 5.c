#include <stdio.h>
int Count_Ones(int Number)
{
     int Count,Ones=0;
     for(Count=0;Count<sizeof(Number)*4;Count++)Ones=Number>>Count&1?Ones+1:Ones;
     return Ones;
}
int main ()
{
     printf("%d\n",Count_Ones(5));
     printf("%d\n",Count_Ones(15));
}