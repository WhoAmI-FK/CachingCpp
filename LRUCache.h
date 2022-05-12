#ifndef CACHE_H
#define CACHE_H
#include <stdlib.h>
#include <stdio.h>


// custom bool
// __attribute__((__packed__)) to reduce size of stored values
typedef __attribute__((__packed__))
enum {
	false=0,
	true=!false
} bool_c;

struct node{
	struct node* _prev;
	struct node* _next;
	unsigned long _pageNum;
};

struct Queue{
	unsigned long _count;
	unsigned long _numOfFrames;
	struct node* _front;
	struct node* _tail;
};

struct Hash{
	unsigned long _capacity;
	node** arrOfNodes;
};

node* allocNode(unsigned long pg){
	node* temp = (node*)malloc(sizeof(node));
	temp->_pageNum = pg;
	temp->_prev = temp->_next = NULL;
	return(temp);
}

Queue* initQueue(unsigned long numOfFrames){
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->_count = 0;
	queue->_front = queue->_tail = NULL;
	queue->_numOfFrames = numOfFrames;
	return(queue);
}

Hast* initHash(unsigned long _capacity){
	// need implementation
	
}

int AreAllFramesFull(Queue* queue){
	
}

int isQueueEmpty(Queue* queue){
	return queue->_tail;
}

void dequeue(Queue* queue)
{
	if(isQueueEmpty(queue)){
		// error
		return;
	}
	if(queue->_front == queue->_tail){
		node* temp = queue->_front;
		queue->_front = queue->_tail = NULL;
		free(temp);
	}
	node* iter;
	// need to finish
}
void enqueue(Queue* queue, Hast* hash, unsigned long pageNumber)
{
	// need implementation
}


#endif
