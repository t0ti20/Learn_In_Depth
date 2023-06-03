/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Queue.h
 *  Module:  Data Structure/Queue
 *  Description:  Queue Implementation
*******************************************************************/
#ifndef _QUEUE_H_
#define _QUEUE_H_
/*---------- Include Files -------------*/
#include "./Standard_Types.h"
#include "./Macros.h"
#include <stdio.h>
/*****************************************
----------   Configuration    ------------
*****************************************/
#define Memory_Mode           Array                                 /*(Linked_List) (Array)*/
#define storage_type          u8                                    /*(u8) (u16) (u32) (s8) (...)*/
#define Queue_size            3                                     /*When Chosing (Array) Max Number Of Stack*/
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Type Defs --------------*/
typedef enum Queue_error 
{
     Queue_Full                =0,
     Queue_Ok                  =1,
     Queue_Empty               =2,
     Queue_Allocation_Error    =3,
}Queue_error;
#define Array                1
#define Linked_List          2
#if Memory_Mode == Array
typedef struct Queue_t {s8 front;storage_type elements[Queue_size];s8 rear;u8 size;}Queue_t;
#else
typedef struct Queue_node_t {struct Queue_node_t *next_node;storage_type data;}Queue_node_t;
typedef struct Queue_t {Queue_node_t *rear;Queue_node_t *front;u8 size;}Queue_t;
#endif
/*----------- Functins To Use ---------*/
Queue_error Queue_Initialization(Queue_t *my_queue);
Queue_error Queue_Clear(Queue_t *my_queue);
Queue_error Queue_Enqueue(Queue_t *my_queue,storage_type data);
Queue_error Queue_Dequeue(Queue_t *my_queue,storage_type *data);
Queue_error Queue_Traverse(Queue_t *my_queue,void (*function)(storage_type));
s8 Queue_Is_Empty(Queue_t *my_queue);
s8 Queue_Is_Full(Queue_t *my_queue);
void *malloc(size_t size);
void free(void *ptr);
/********************************************************************
 *  END OF FILE: Queue.h
********************************************************************/
#endif
