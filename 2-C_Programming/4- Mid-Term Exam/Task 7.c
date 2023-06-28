#include <stdio.h>
int Sum(int Number)
{
     return (Number?Sum(--Number)+Number:0);
}
int main ()
{
     printf("%d\n",Sum(101));
}