#include "./Queue.h"
void print(unsigned char Data)
{
	printf("- %d\n",Data);
}
int main()
{
	Queue_t My_Queue;
	u8 data;
	Queue_Initialization(&My_Queue);
	printf("%d\n",Queue_Dequeue(&My_Queue,&data));
	Queue_Enqueue(&My_Queue,10);
	Queue_Dequeue(&My_Queue,&data);
	Queue_Enqueue(&My_Queue,20);
	Queue_Dequeue(&My_Queue,&data);
	Queue_Enqueue(&My_Queue,30);
	Queue_Enqueue(&My_Queue,40);
	printf("%d\n",Queue_Is_Full(&My_Queue));
	Queue_Enqueue(&My_Queue,50);
	printf("%d\n",Queue_Is_Full(&My_Queue));
	printf("%d\n",Queue_Enqueue(&My_Queue,60));
	Queue_Traverse(&My_Queue,print);
	printf("Done\n");
	return 0;
}
