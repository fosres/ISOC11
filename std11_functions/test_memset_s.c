#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define ARRAY_SIZE 8

typedef struct Node
{

	struct Node * link;

	int val;

} Node;


int main(void)
{
	errno_t result = 0;	
	
	printf("This program only checks for runtime-constraint\n"
		"violations in an invocation of memset_s.\n\n"
	      );

	static char test[ARRAY_SIZE];

	printf("Does memset_s return nonzero value when void * s"
		" == NULL?\n\n"
	      );

	result = memset_s(NULL,sizeof(test),0,sizeof(test));

	printf("Return Value: %llu\n\n",result);

	printf("Does memset_s return nonzero value when smax >"
		" RSIZE_MAX?\n\n"
	      );

	result = memset_s(test,RSIZE_MAX+1,0,sizeof(test));

	printf("Return Value: %llu\n\n",result);
	
	printf("Does memset_s set the inputted char value into\n"
		"each of the first smax characters of the object\n"
		"pointed to by void *s only when there is a\n"
		"violation and void * s != NULl and when rsize_t\n"
		"smax is less than or equal to RSIZE_MAX and return\n"
		"nonzero value?\n\n"
	      );

	result = memset_s(test,8*sizeof(char),84,RSIZE_MAX+1);

	printf("Return Value: %llu\n\n",result);

	printf("test string set with memset_s:\n%s\n",test);

	for ( rsize_t i = 0; i < ARRAY_SIZE; i++)
	{
		test[i] = '\0';

	}
	
	printf("Does memset_s correctly set the inputted char value\n"
		"into each of the first n characters of the object\n"
		"pointed to by void *s when there is NO runtime\n"
		"constraint violation?\n\n"
	      );

	result = memset_s(test,8*sizeof(char),84,4*sizeof(char));

	printf("Return Value: %llu\n\n",result);

	printf("test string set with memset_s for first four char\n" 
		"elements in a char array of 8 elements:\n%s\n\n",
		test
	      );

	printf("Does memset_s only set the first smax values when\n"
		"rsize_t n > rsize_t smax?\n\n"
	      );

	for ( rsize_t i = 0; i < ARRAY_SIZE; i++)
	{
		test[i] = '\0';

	}
	
	result = memset_s(test,8*sizeof(char),84,8*sizeof(char)+1);

	printf("Return Value: %llu\n\n",result);

	printf("test string below:\n%s\n\n", 
		test
	      );
	
	printf("Does memset_s correctly allocate unsigned chars to objects\n"
		"that in turn, store other objects, like a struct?\n"
		"In the example below, a struct Node of a Linked List\n"
		"is initialized through memset_s\n\n"
	      );

	
	Node * node;

	result = memset_s(node,sizeof(Node),0,sizeof(Node));

	printf("Return Value: %llu\n\n",result);

	printf("node->link == %p\n",node->link);

	printf("node->val == %d\n\n",node->val);

	printf("Does memset_s do what was tested previously except that\n"
		"it initializes with a nonzero unsigned char value? In the\n"
		"example below, a second struct Node name node_two is\n"
		"initialized with the unsigned char value 84\n\n"
	      );

	Node * node_two;

	Node * node_three;

	result = memset_s(node_two,sizeof(Node),84,sizeof(Node));
		
	printf("Return Value: %llu\n\n",result);

	printf("node_two->link == %p\n",node_two->link);

	printf("node_two->val == %d\n\n",node_two->val);

	printf("node_two->val in Hexadecimal format == 0x%x\n\n",node_two->val);

	printf("Does memset_s properly overwrite data for any object that was"
		"already initialized? The test case attempts to overwrite\n"
		"node_two's data fields by zeroing it.\n"
	      );

	result = memset_s(node_two,sizeof(Node),0,sizeof(Node));

	printf("Return Value: %llu\n\n",result);

	printf("node_two->link == %p\n",node_two->link);

	printf("node_two->val == %d\n\n",node_two->val);

	printf("node_two->val in Hexadecimal format == 0x%x\n\n",node_two->val);
		
	return 0;

}
