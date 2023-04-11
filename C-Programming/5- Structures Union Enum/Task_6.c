//EX5: C Program to Search an element in Array
#include<stdio.h>
union job
{
     char name[32]; //32
     float salary;
     int workerno;
}u;
struct jobl 
{                   //32+4+4=40
     char name[32];
     float salary;
     int workerno;
}s;
int main()
{
     printf("size of union = %ld\n",sizeof(u));
     printf("size of structure = %ld\n", sizeof(s) );
     return 0;
}
