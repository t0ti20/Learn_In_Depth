//EX5:Write a program in C to show a pointer to an array which contents are pointer to structure.
#include<stdio.h>
typedef struct Data_type
{
     char Name[20];
     int ID;
}Data_type;

int Function(Data_type*(Data_Base[]));

int main()
{
     Data_type *(Data_Base[5]);
     Data_type Data={"AHMED",1234};
     Data_Base[0]=&Data;
     Function(Data_Base);
     return 1;
}
int Function(Data_type*(Data_Base[]))
{
     printf("- Name : %s\n",Data_Base[0]->Name);
     printf("- ID : %d\n",Data_Base[0]->ID);
}