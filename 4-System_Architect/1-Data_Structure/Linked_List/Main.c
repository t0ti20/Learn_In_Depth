#include <stdio.h>
#include "./Linked_List.h"
Linked_List_t my_list;
int Global_ID,Global_Index,Index;
void Print_Student (storage_type *data)
{
     printf("- Name: %s\n",data->Name);
     printf("- ID: %d\n",data->Student_ID);
     printf("- Height: %d\n",data->Height);
     printf("----------------------------------\n");
}
void Add_Student ()
{
     fflush(stdin);
     fflush(stdout);
     printf("----------------------------------\n");
     student_t data;
     printf("-Enter Name : ");
     scanf("%s",data.Name);
     printf("-Enter ID : ");
     scanf(" %d",&data.Student_ID);
     printf("-Enter Height : ");
     scanf(" %d",&data.Height);
     Linked_List_Append(&my_list,data);
     printf("----------------------------------\n");
}
void Delete(storage_type *Data)
{
     if(Data->Student_ID==Global_ID)
     {
          Global_Index=Index;
     }
     else Index++;
}
void Delete_Student()
{
     printf("- Enter ID :");
     scanf("%d",&Global_ID);
     Global_Index=-1;
     Index=0;
     Linked_List_Traverse(&my_list,Delete);
     Index=0;
     if(Global_Index>=0&&Global_Index<=my_list.size)
     {
          Linked_List_Delete_Node(&my_list,Global_Index);
     }
     else printf("- Invalid ID -\n");
}
int main(void)
{
     char x;
     Linked_List_Initialization(&my_list);
     while(1)
     {
          printf("----------------------------------\n");
          printf("1) Add Student.\n");
          printf("2) Delete Student.\n");
          printf("3) View Student.\n");
          printf("2) Delete ALL.\n");
          printf("Choose Option : ");
          scanf(" %c",&x);
          switch (x)
          {
               case '1':Add_Student();break;
               case '2':Delete_Student();break;
               case '3':Linked_List_Traverse(&my_list,Print_Student);break;
               case '4':break;
               default:break;
          }
     }
}
