#include "LRUCache.h"

int main(){
	struct DeQueue* deq = initDeQueue(4);
	
	struct Hash* hash = initHash(10);
	
	refer(deq, hash, 1);
	refer(deq, hash, 2);
	refer(deq, hash, 3);
	refer(deq, hash, 1);
	refer(deq, hash, 4);
	refer(deq, hash, 5);
	
	printDeq(deq);
	return 0;
}
