#includ "queue.h"

void InitQueue(Queue * queue) {
	queue->front = queue->rear = NULL;
	queue->items = 0;
} 

bool QueueIsFull(Queue * queue) {
	return queue->items == maxQueue;
}

bool QueueIsEmpty(Queue * queue) {
	return queue->items == 0;	
}

int QueueItemCount(Queue * queue) {
	return queue->items
}

static void CopyToNode(Item item,Node *node) {
	node->item=item;
}

bool InsertQueue(Item item,Queue *queue) {
	Node * pNew;
	
	if (QueueIsFull(queue))
		return false;
	pNew = (Node*)malloc(sizeof(Node));
	if (pNew == NULL) {
		printf(stderr,"error!");
		exit(1);
	}
	CopyToNode(item,pNew);
	pNew->next=NULL;
	if (QueueIsEmpty(queue))//empty queue so,it's first node
		queue->front = pNew;
	else
		queue->rear->next = pNew;
	queue->items ++;
	queue->rear = pNew;
	return true;
}

bool DelQueue(Item * pItem,Queue *queue) {
	Node *pTemp;

	if (QueueIsEmpty(queue)) 
		return false;
	CopyToNode (queue->front,pItem);
	pTemp = queue->front;//record a node will be delete
	queue->front = queue->front->next;
	free(pTemp);//free the node has been delete!
	queue->items--;
	if (queue->items == 0)
		queue->rear == NULL;
	return true;
}

void EmptyTheQueue(Queue * queue) {
	Item dum;
	while (!QueueIsEmpty(queue)) {
		DelQueue(&dum,queue);
	}
}
	
		

 

