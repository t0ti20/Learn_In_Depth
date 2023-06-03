//EX4: C Program to Store Information ofStudents Using Structure
#define Max 2
#include<stdio.h>
struct Data
{
     int Roll_Number;
     int Grade;
     char Name[20];
}Database[Max];
int main()
{
     int Count;
     for(Count=0;Count<Max;Count++)
     {
          printf("Enter Name :");
          scanf("%s",Database[Count].Name);
          printf("Enter Roll Nember :");
          scanf("%d",&Database[Count].Roll_Number);
          printf("Enter Marks :");
          scanf("%d",&Database[Count].Grade);
          printf("-------------------------\n");
     }
     for(Count=0;Count<Max;Count++)
     {
          printf("Name :%s\n",Database[Count].Name);
          printf("Roll Nember :%d\n",Database[Count].Roll_Number);
          printf("Marks :%d\n",Database[Count].Grade);
          printf("-------------------------\n");
     }
}