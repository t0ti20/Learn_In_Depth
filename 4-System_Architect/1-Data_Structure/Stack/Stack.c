/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Stack.c
 *  Module:  Data Structure/Stack
 *  Description:  Stack Implementation
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "./Stack.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : Stack_traverse(Stack_t *my_stack,void (*function)(storage_type))
* Description     : Make Any Functions On The Stack
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Stack) (Ptr To Function)
* Parameters (out): None
* Return value:   : Stack_error
********************************************************************/
Stack_error Stack_traverse(Stack_t *my_stack,void (*function)(storage_type))
{
     Stack_error flag=Stack_Ok;
#if Memory_Mode == Array
     if(my_stack->top)
     {
          for(u8 counter=(my_stack->top);(counter--)>ZERO;)
          {
               function(my_stack->elements[counter]);
          }
     }
     else flag=Stack_Empty;
#else
     if(my_stack->size)
     {
          Stack_node_t *Node=my_stack->top;
          for(u8 counter=0;counter<my_stack->size;counter++)
          {
               function(Node->data);
               Node=Node->next_node;
          }
     }
     else flag=Stack_Empty;
#endif
     return flag;
}
/********************************************************************
* Syntax          : Stack_error Stack_Initialization(Stack_t *my_stack)
* Description     : Initialize The Stack
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Stack)
* Parameters (out): None
* Return value:   : Stack_error
********************************************************************/
Stack_error Stack_Initialization(Stack_t *my_stack)
{
     Stack_error flag=Stack_Ok;
#if Memory_Mode == Linked_List
     my_stack->size = ZERO;
     my_stack->top = NULL;
#else
     my_stack->top = ZERO;
#endif
     return flag;
}
/********************************************************************
* Syntax          : Stack_error Stack_Push(Stack_t *my_stack,storage_type data)
* Description     : Push Data To The Stack
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Stack) (Copy Of Data)
* Parameters (out): None
* Return value:   : Stack_error
********************************************************************/
Stack_error Stack_Push(Stack_t *my_stack,storage_type data)
{
     Stack_error flag=Stack_Ok;
#if Memory_Mode == Array
     if((my_stack->top)<Stack_size)
     {
          my_stack->elements[my_stack->top]=data;
          my_stack->top++;
     }
     else flag=Stack_Full;
#else
     Stack_node_t *node=(Stack_node_t *)malloc(sizeof(Stack_node_t));
     if(node)
     {
          node->data=data;
          node->next_node=my_stack->top;
          my_stack->top=node;
          my_stack->size++;
     }
     else flag=Stack_Allocation_Error;
#endif
     return flag;
}
/********************************************************************
* Syntax          : Stack_error Stack_Pop(Stack_t *my_stack,storage_type *data)
* Description     : Pop Data From Stack 
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Stack) (Ptr To Data To Be Stored)
* Parameters (out): None
* Return value:   : Stack_error
********************************************************************/
Stack_error Stack_Pop(Stack_t *my_stack,storage_type *data)
{
     Stack_error flag=Stack_Ok;
#if Memory_Mode == Array
     if(my_stack->top)
     {
          *data=my_stack->elements[(my_stack->top)-ONE];
          (my_stack->top)--;
     }
     else flag=Stack_Empty;
#else
     if(my_stack->size)
     {
          Stack_node_t *node=my_stack->top->next_node;
          *data=my_stack->top->data;
          free(my_stack->top);
          my_stack->top=node;
          my_stack->size--;
     }
     else flag=Stack_Empty;
#endif
     return flag;
}
/********************************************************************
* Syntax          : Stack_error Stack_Clear(Stack_t *my_stack)
* Description     : Clear All Elemets From Stack
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Stack)
* Parameters (out): None
* Return value:   : Stack_error
********************************************************************/
Stack_error Stack_Clear(Stack_t *my_stack)
{
     Stack_error flag=Stack_Ok;
#if Memory_Mode == Array
     my_stack->top = ZERO;
#else
     if(my_stack->size)
     {
          Stack_node_t *node;
          while(my_stack->top)
          {
               node=my_stack->top;
               my_stack->top=my_stack->top->next_node;
               free(node);
               my_stack->size--;
          }
     }
     else flag=Stack_Empty;
#endif
     return flag;
}
/********************************************************************
* Syntax          : s8 Stack_Is_Empty(Stack_t *my_stack)
* Description     : Check If Stack Is Empty
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Stack)
* Parameters (out): None
* Return value:   : (True-1) (False-0)
********************************************************************/
s8 Stack_Is_Empty(Stack_t *my_stack)
{
#if Memory_Mode == Array
     return (!my_stack->top);
#else
     return !(my_stack->size);
#endif
}
/********************************************************************
* Syntax          : s8 Stack_Is_Full(Stack_t *my_stack)
* Description     : Check If Stack Is Full
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To Stack)
* Parameters (out): None
* Return value:   : (True-1) (False-0)
********************************************************************/
s8 Stack_Is_Full(Stack_t *my_stack)
{
#if Memory_Mode == Array
     return (my_stack->top==Stack_size);
#else
     return False;
#endif
}
/********************************************************************
 *  END OF FILE: Stack.c
********************************************************************/
