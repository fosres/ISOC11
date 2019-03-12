#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	struct Node * link;

	int val;
} Node;

int main(void)
{
	Node a;

	void * s = &a;
	
	(Node)*s = {0};


	return 0;
}
