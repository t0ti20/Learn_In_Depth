#ifndef _MAIN_H_
#define _MAIN_H_
/*---------- Include Files -------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./Queue.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Type Defs --------------*/
typedef enum 
{
     Operation_Done      =-1,
     No_Students         =2,
     Repeated_ID         =3,
     Name_Not_Found      =4,
     ID_Not_Found        =5, 
} DataBase_Status; 
/*------------- Variables --------------*/
DataBase_Status Global_Flag;
u32 Global_Match; 
u32 Global_ID;
u8  Global_F_Name[30];  
u8 Global_Course_ID;
/*-------------- Define ----------------*/
#ifndef True
#define True                  (DataBase_Status)1
#endif
#ifndef False
#define False                 (DataBase_Status)0
#endif
/*----------- Functins To Use ---------*/
DataBase_Status Add_Student_From_File(queue_t *Data_Base);
DataBase_Status Serch_By_First_Name(queue_t *Data_Base);
DataBase_Status Search_By_Course_ID(queue_t *Data_Base);
DataBase_Status Add_Student_Manual(queue_t *Data_Base);
DataBase_Status Print_All_Students(queue_t *Data_Base);
DataBase_Status Delete_Student(queue_t *Data_Base);
DataBase_Status Update_Student(queue_t *Data_Base);
DataBase_Status Find_Student(queue_t *Data_Base);
DataBase_Status Search_By_ID(queue_t *Data_Base);
DataBase_Status Check_For_ID(queue_t *Data_Base);
void Check_First_Name(students_t Student_Data);
void Check_Course_ID(students_t Student_Data);
void Print_Student(students_t Student_Data);
void Check_Index(students_t Student_Data);
void Check_Data(students_t *Student_Data);
void Check_ID (students_t Student_Data);
void Get_ID(students_t Student_Data);
#endif
/********************************************************************
 *  END OF FILE: Main.h
********************************************************************/