//EX5: C Program to Search an element in Array
#include<stdio.h>
#define pi 3.14f 
#define Circle_Area(_Radius_)     pi*((_Radius_)*(_Radius_))

int main()
{
     float Radius;
     printf("Enter Radius :");
     scanf("%f",&Radius);
     printf("Area = %.2f",Circle_Area(Radius));
     return 1;
}