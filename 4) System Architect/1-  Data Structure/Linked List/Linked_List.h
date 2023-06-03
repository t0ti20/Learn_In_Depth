/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Linked_List.h
 *  Module:  Data Structure/Linked List
 *  Description:  Linked List Implementation
*******************************************************************/
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
/*---------- Include Files -------------*/
#include "../../Library/Standard_Types.h"
#include "../../Library/Macros.h"
#include <stdio.h>
/*****************************************
----------   Configuration    ------------
*****************************************/
#define storage_type u8
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Type Defs --------------*/
typedef enum list_error 
{
     List_Empty               =0,
     List_Ok                  =1,
     List_Wrong_Size          =2,
     List_Wrong_Memory        =3,
}list_error;
typedef struct list_node_t {struct list_node_t *next_ptr;storage_type data;}list_node_t;
typedef struct list_t {list_node_t *head;s16 size;}list_t;
/*----------- Functins To Use ---------*/
list_error Linked_List_Initialization(list_t *my_list);
list_error Linked_List_Append(list_t *my_list,storage_type data);
list_error Linked_List_Insert(list_t *my_list,u8 node_number,storage_type data);
list_error Linked_List_Get_Node(list_t *my_list,u8 node_number,storage_type *data);
list_error Linked_List_Delete_Node(list_t *my_list,u8 node_number);
list_error Linked_List_Clear(list_t *my_list,u8 node_number);
list_error Linked_List_Traverse(list_t *my_list,void (*function)(storage_type));
s8 List_Is_Empty(list_t *my_list);
void *malloc(size_t size);
void free(void *ptr);
#endif
/********************************************************************
 *  END OF FILE: Linked_List.h
********************************************************************/