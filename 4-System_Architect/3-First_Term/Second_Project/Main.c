/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Main.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
queue_t Data_Base;
int main()
{
     u8 Flag=True;
     u8 Option;
     Queue_Initialization(&Data_Base);
     /*TEMP*/
     students_t Student_1={"ahm","qwe",1,3.1,"132"};
     students_t Student_2={"asd","gfd",2,4,"12"};
     students_t Student_3={"zxc","bvc",3,3.6,"232"};
     Queue_Enqueue(&Data_Base,Student_1);
     Queue_Enqueue(&Data_Base,Student_2);
     Queue_Enqueue(&Data_Base,Student_3);
     /*TEMP*/
     printf("-------------------------------------------------\n");
     printf("-------------------------------------------------\n");
     printf("-------------------- Welcome --------------------\n");
     while(Flag)
     {
          printf("-------------------------------------------------\n");
          printf("-------------------------------------------------\n");
          printf("Please Chose What To Do :\n");
          printf("- 1) Add Student From File.\n- 2) Add Student Manually.\n- 3) Find Student.\n- 4) Delete Student.\n- 5) Update Student.\n- 6) Print All Students.\n- 7) Exit The Program.\n");
          printf("Option : ");
          scanf(" %c",&Option);
          fflush(stdin);fflush(stdout);
          switch (Option)
          {
               case '1':Add_Student_From_File(&Data_Base);break;
               case '2':Add_Student_Manual(&Data_Base);break;
               case '3':Find_Student(&Data_Base);break;
               case '4':Delete_Student(&Data_Base);break;
               case '5':Update_Student(&Data_Base);break;
               case '6':Print_All_Students(&Data_Base);break;
               case '7':Flag=False;break;
               default:printf("xx Enter Valid Option xx\n");break;
          }
     }
     return 0 ;
}
/********************************************************************
* Syntax          : DataBase_Status Update_Student(queue_t *Data_Base)
* Description     : Update Data For Specific Student By ID 
* Parameters (in) : (Copy Of Data_Base)
********************************************************************/
DataBase_Status Update_Student(queue_t *Data_Base)
{
     DataBase_Status Flag=ID_Not_Found;
     printf("Enter Student ID: ");
     scanf("%ld",&Global_ID);
     Global_Flag=ID_Not_Found;
     Queue_Traverse_Origin(Data_Base,Check_Data);
     if(Global_Flag==ID_Not_Found)printf("xx You Have Entered Invalid ID xx\n");
     return Flag;
}
void Check_Data(students_t *Student_Data)
{
     if(Student_Data->ID==Global_ID)
     {
          u8 Option,Courses=0;
          printf("Choose What To Update\n- 1) First Name\n- 2) Last Name\n- 3) GPA\n- 4) Courses\n");
          printf("Option : ");
          scanf(" %c",&Option);
          switch (Option)
          {
               case '1':
                    printf("Enter First Name: ");
                    scanf(" %s",Student_Data->F_Name);
                    fflush(stdin);fflush(stdout);
                    break;
               case '2':
                    printf("Enter Last Name: ");
                    scanf(" %s",Student_Data->L_Name);
                    fflush(stdin);fflush(stdout);
                    break;
               case '3':
                    printf("Enter GPA: ");
                    scanf(" %f",&Student_Data->GPA);
                    fflush(stdin);fflush(stdout);
                    break;
               case '4':
                    printf("Number Of Courses Assigned : ");
                    scanf(" %hhd",&Courses);
                    fflush(stdin);fflush(stdout);
                    for(u8 Count=0;Count<Courses;Count++)
                    {
                         printf("Course [%d] = ",(Count+ONE));
                         scanf("%hhd",&Student_Data->Courses_ID[Count]);
                    }
                    Student_Data->Courses_ID[Courses]=ZERO;
                    break;
               default:printf("xx Enter Valid Option xx\n");break;
          }
          Global_Flag=Operation_Done;
     }
}
/********************************************************************
* Syntax          : DataBase_Status Add_Student_From_File(queue_t *Data_Base)
* Description     : Add Studen From DataBase File
* Parameters (in) : (Copy Of Data_Base)
********************************************************************/
DataBase_Status Add_Student_From_File(queue_t *Data_Base)
{
     DataBase_Status Flag=Operation_Done;
     students_t Student_Data;
     FILE *fptr;
     fptr = fopen("DataBase.txt", "r");// Open a file in read mode
     char Line[100],Word[10]={ZERO};// Store the content of the file
     while(fgets(Line, 100, fptr))
     {
          u8 Line_Counter=0,Word_Conter=0,Counter=0;
          for(Word_Conter=0;Line[Line_Counter]!=' ';Word_Conter++,Line_Counter++)Word[Word_Conter]=Line[Line_Counter];
          Word[Word_Conter]=ZERO;Line_Counter++;      /*ID*/
          Student_Data.ID=atoi(Word);
          for(Word_Conter=0;Line[Line_Counter]!=' ';Word_Conter++,Line_Counter++)Word[Word_Conter]=Line[Line_Counter];
          Word[Word_Conter]=ZERO;Line_Counter++;      /*FIRST NAME*/             
          strcpy(Student_Data.F_Name,Word);
          for(Word_Conter=0;Line[Line_Counter]!=' ';Word_Conter++,Line_Counter++)Word[Word_Conter]=Line[Line_Counter];
          Word[Word_Conter]=ZERO;Line_Counter++;      /*LAST NAME*/
          strcpy(Student_Data.L_Name,Word);
          for(Word_Conter=0;Line[Line_Counter]!=' ';Word_Conter++,Line_Counter++)Word[Word_Conter]=Line[Line_Counter];
          Word[Word_Conter]=ZERO;Line_Counter++;      /*GPA*/
          Student_Data.GPA=atof(Word);
          for(Counter=0,Word_Conter=0;Line[Line_Counter];Line_Counter++)
          {
               if(Line[Line_Counter]==' ')            /*COURSES*/
               {
                    Word[Word_Conter]=ZERO;
                    Student_Data.Courses_ID[Counter++]=(char)atoi(Word);
                    Word_Conter=ZERO;
                    continue;
               }
               Word[Word_Conter]=Line[Line_Counter];Word_Conter++;
          }
          Word[Word_Conter]=ZERO;
          Student_Data.Courses_ID[Counter]=ZERO;
          Global_ID=Student_Data.ID;
          if(Check_For_ID(Data_Base)==Operation_Done)Queue_Enqueue(Data_Base,Student_Data);
          else  printf("xx Rebeated ID Is Found And Ignored xx\n");
     }
     fclose(fptr);// Close the file
     return Flag;
}
/********************************************************************
* Syntax          : DataBase_Status Delete_Student(queue_t *Data_Base)
* Description     : Delete Specific Student From Data Base
* Parameters (in) : (Copy Of Data_Base)
********************************************************************/
DataBase_Status Delete_Student(queue_t *Data_Base)
{
     DataBase_Status Flag=ID_Not_Found;
     printf("Enter Student ID: ");
     scanf("%ld",&Global_ID);
     Global_Flag=ID_Not_Found;
     Global_Match=ZERO;
     Global_Course_ID=ZERO;//Used To Store Index
     Queue_Traverse(Data_Base,Check_Index);
     if(Global_Flag==Operation_Done)
     {
          Flag=Operation_Done;
          Queue_Dequeue_Node(Data_Base,Global_Course_ID);
     }
     else printf("xx You Have Entered Invalid ID xx\n");
     return Flag;
}
void Check_Index(students_t Student_Data)
{
     Global_Match++;
     if(Student_Data.ID==Global_ID)
     {
          Global_Flag=Operation_Done;
          Global_Course_ID=Global_Match;
     }
}
/********************************************************************
* Syntax          : DataBase_Status Find_Student(queue_t *Data_Base)
* Description     : All Methods To Find Student
* Parameters (in) : (Ptr To Data_Base)
********************************************************************/
DataBase_Status Find_Student(queue_t *Data_Base)
{
     DataBase_Status Flag=True;
     u8 Option;
     while(Flag)
     {
          printf("-------------------------------------------------\n");
          printf("-------------------------------------------------\n");
          printf("Want To Search By :\n");
          printf("- 1) Student ID.\n- 2) Student First Name.\n- 3) Course ID.\n- 4) Back.\n");
          printf("Option : ");
          scanf(" %c",&Option);
          switch (Option)
               {
                    case '1':Search_By_ID(Data_Base);Flag=False;break;
                    case '2':Serch_By_First_Name(Data_Base);Flag=False;break;
                    case '3':Search_By_Course_ID(Data_Base);Flag=False;break;
                    case '4':Flag=False;break;
                    default:printf("xx Enter Valid Option xx\n");break;
               }
     }
     return Flag;
}
/********************************************************************
* Syntax          : DataBase_Status Search_By_Course_ID(queue_t *Data_Base)
* Description     : Search By Course ID Function
* Parameters (in) : (Copy Of Data_Base)
********************************************************************/
DataBase_Status Search_By_Course_ID(queue_t *Data_Base)
{
     DataBase_Status Flag=Operation_Done;
     printf("-------------------------------------------------\n");
     printf("Enter Course ID : ");
     scanf(" %hhd",&Global_Course_ID);
     Global_Flag=ID_Not_Found;
     Queue_Traverse(Data_Base,Check_Course_ID);
     if(Global_Flag==ID_Not_Found)printf("xx Course ID Not Found xx\n");
     return Flag;
}
void Check_Course_ID(students_t Student_Data)
{
     for(u8 Counter=0;Student_Data.Courses_ID[Counter];Counter++)
     {
          if(Student_Data.Courses_ID[Counter]==Global_Course_ID)
          {
               Global_Flag=Operation_Done;
               Print_Student(Student_Data);
               break;
          }
     }
}
/********************************************************************
* Syntax          : void Print_Student(students_t Student_Data)
* Description     : Print One Student Function
* Parameters (in) : (Copy Of Student Data)
********************************************************************/
void Print_Student(students_t Student_Data)
{
     printf("--------------------------------\n");
     printf("Student ID: %ld\n",Student_Data.ID); 
     printf("Fisrt Name: %s\n",Student_Data.F_Name) ;
     printf("Last Name: %s\n",Student_Data.L_Name);
     printf("GPA: %.2f\n",Student_Data.GPA);
     printf("Courses Assigned: ");
     for(u8 Counter=0;Student_Data.Courses_ID[Counter];Counter++)printf("%d ",Student_Data.Courses_ID[Counter]);
     printf("\n--------------------------------\n");
}
/********************************************************************
* Syntax          : DataBase_Status Print_All_Students(queue_t *Data_Base) 
* Description     : Print All Student In Data Base
* Parameters (in) : (Ptr Of Data_Base)
********************************************************************/
DataBase_Status Print_All_Students(queue_t *Data_Base) 
{
     DataBase_Status Flag=Operation_Done;
     printf("-------------------------------------------------\n");
     printf("-> Students Count = %d\n",Data_Base->size);
     printf("-------------------------------------------------\n");
     Queue_Traverse(Data_Base,Print_Student);
     return Flag;
}
/********************************************************************
* Syntax          : DataBase_Status Check_For_ID(queue_t *Data_Base)
* Description     : Check For Rebeated ID In Database
* Parameters (in) : (Ptr Of Data_Base)
********************************************************************/
DataBase_Status Check_For_ID(queue_t *Data_Base)
{
     Global_Flag = Operation_Done;
     Queue_Traverse(Data_Base,Get_ID);
     return Global_Flag;
}
void Get_ID(students_t Student_Data)
{
     if(Student_Data.ID==Global_ID)Global_Flag=Repeated_ID;
}
/********************************************************************
* Syntax          : DataBase_Status Add_Student(queue_t *Data_Base)
* Description     : Add Student To Data Base
* Parameters (in) : (Ptr Of Data_Base)
********************************************************************/
DataBase_Status Add_Student_Manual(queue_t *Data_Base)
{
     DataBase_Status Flag=Operation_Done;
     students_t Student_Data;
     u8 Courses;
     printf("-------------------------------------------------\n");
     printf("Enter Student ID: ");
     scanf(" %ld",&Student_Data.ID);
     Global_ID=Student_Data.ID;
     if(Check_For_ID(Data_Base)==Operation_Done)
     {
          printf("Enter First Name: ");
          scanf(" %s",Student_Data.F_Name);
          fflush(stdin);fflush(stdout);
          printf("Enter Last Name: ");
          scanf(" %s",Student_Data.L_Name);
          fflush(stdin);fflush(stdout);
          printf("Enter GPA: ");
          scanf(" %f",&Student_Data.GPA);
          fflush(stdin);fflush(stdout);
          printf("Number Of Courses Assigned : ");
          scanf(" %hhd",&Courses);
          fflush(stdin);fflush(stdout);
          for(u8 Count=0;Count<Courses;Count++)
          {
               printf("Course [%d] = ",(Count+ONE));
               scanf("%hhd",&Student_Data.Courses_ID[Count]);
          }
          Student_Data.Courses_ID[Courses]=ZERO;
          Queue_Enqueue(Data_Base,Student_Data);
     }
     else
     {
          printf("xx You Have Entered Rebeated ID xx\n");
          Flag=Repeated_ID;
     }
     return Flag;
}
/********************************************************************
* Syntax          : Serch_By_First_Name(students_t Student_Data) && void Check_First_Name(students_t Student_Data)
* Description     : Print One Student Function
* Parameters (in) : (Pointer to Student Data)
********************************************************************/
DataBase_Status Serch_By_First_Name(queue_t *Data_Base)
{
     Global_Flag=Operation_Done;
     printf("-------------------------------------------------\n");
     printf("Enter First Name :");
     scanf("%s",Global_F_Name); 
     Global_Flag=Name_Not_Found;
     Queue_Traverse(Data_Base,Check_First_Name);
     if(Global_Flag==Name_Not_Found)printf("xx Name Not Found xx\n");
     return Global_Flag ;    
}
void Check_First_Name(students_t Student_Data)
{
     if(!strcmp(Student_Data.F_Name,Global_F_Name))
     {
          Print_Student(Student_Data);
          Global_Flag = Operation_Done ;
     }
}
/********************************************************************
* Syntax          : DataBase_Status Search_By_ID(queue_t *Data_Base)
* Description     : Search for Student By ID
* Parameters (in) : (Ptr Of Data_Base)
********************************************************************/
DataBase_Status Search_By_ID(queue_t *Data_Base)
{
     Global_Match=0;
     Global_Flag=Operation_Done;
     printf("-------------------------------------------------\n");
     printf("Enter ID :");
     scanf("%ld",&Global_ID); 
     Queue_Traverse(Data_Base,Check_ID);
     if(Global_Match == 0)
     {
          printf("xx ID Not Found xx\n");
          Global_Flag = ID_Not_Found; 
     }
     return Global_Flag ; 
}
void Check_ID (students_t Student_Data)
{
     Global_Flag = Operation_Done ;
     if(Global_ID == Student_Data.ID)
     {
          printf("ID found ....\n");
          Print_Student(Student_Data);
          Global_Match = 1 ;
     }
}