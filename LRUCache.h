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

struct DeQueue{
	unsigned long _count;
	unsigned long _numOfFrames;
	struct node* _front;
	struct node* _tail;
};

struct Hash{
	unsigned long _capacity;
	struct node** _arrOfNodes;
};

struct node* allocNode(unsigned long pg){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->_pageNum = pg;
	temp->_prev = temp->_next = NULL;
	return(temp);
}

struct DeQueue* initDeQueue(unsigned long numOfFrames){
	struct DeQueue* queue = (struct DeQueue*)malloc(sizeof(struct DeQueue));
	queue->_count = 0;
	queue->_front = queue->_tail = NULL;
	queue->_numOfFrames = numOfFrames;
	return(queue);
}

struct Hast* initHash(unsigned long _capacity){
	// need implementation
	int i;
	struct Hash* hash = (struct Hash*)malloc(sizeof(struct Hash));
	hash->_capacity = capacity;
	hash->arrOfNodes = (struct node**)malloc(hash->_capacity*sizeof(struct node*));
	for(i = 0;i<hash->_capacity;++i){
		hash->_arrOfNodes[i] = NULL;
	}
	return hash;
}

int AreAllFramesFull(struct DeQueue* queue){
	return queue->_count == queue->_numOfFrames;
}

int isDeQueueEmpty(struct DeQueue* queue){
	return queue->_tail==NULL;
}

void pop_back(struct DeQueue* queue)
{
	if(isQueueEmpty(queue)){
		// error
		return;
	}
	if(queue->_front == queue->_tail){
		struct node* temp = queue->_front;
		queue->_front = queue->_tail = NULL;
		free(temp);
		return;
	}
	struct node* iterator = queue->_tail;
	queue->_tail = queue->_tail->_prev;
	if(queue->tail) queue->_tail->_next = NULL;
	free(temp);
	queue->_count--;
	// need to finish
}

// push to que and hash
void pushToQH(struct DeQueue* queue, struct Hash* hash, unsigned long pageNumber)
{
	if(AreAllFramesFull(queue)){
		hash->_arrOfNodes[queue->_tail->_pageNum]=NULL;
		pop_back(queue);
	}
	node* temp =  allocNode(pageNumber);
	temp->_next = queue->_front;
	if(isDeQueueEmpty(queue))
	{
		queue->_front = queue->_tail = temp;
	}else{
		queue->_front->_prev=temp;
		queue->_front = temp;
	}
	hash->_arrOfNodes[pageNumber] = temp;
	queue->_count++;
}



#endif
