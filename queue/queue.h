#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define maxQueue 10 
typedef int Item;

typedef struct node {
	Item item;
	struct node * next;
}Node;

typed
f struct queue {
	Node * front;
	Node * rear;
	int items;
}Queue;

void InitQueue (Queue *queue);

bool QueueIsFull(const Queue * queue);//check queue is full,just check items >= maxQueue

bool QueueIsEmpty(const Queue * queue);

int QueueItemCount(const Queue * queue);

bool EnQueue(Item item,Queue * queue);

void EmptyQueue(Queue * queue);
