#include "LRUCacheCpp.h"
 

int main()
{
	Cache::LRUCache<int> c(4);
	c.refer(1);
	c.refer(2);
	c.refer(3);
	c.refer(1);
	c.refer(4);
	c.refer(5);
	c.display();
	return 0;
}