#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ARRAY_SIZE 8

typedef struct Node
{

	struct Node * link;

	int val;

} Node;

errno_t test_memset_s (char const * msg, unsigned int line, errno_t exp,
			void *s, rsize_t smax, unsigned char c, rsize_t n)	
{
	errno_t test_success = 0;

	test_success = memset_s(s,smax,c,n);

	if ( test_success == exp )
	{
		return test_success;
	}

	else
	{
		fprintf(stderr,"%u: %s",line,msg);	
		return 1;
	}


}



int main (void)
{
	errno_t result = 0;	

	static char test[ARRAY_SIZE];

	result = test_memset_s("memset_s fails to zero all elements in void * s"
			"\n\n",__LINE__,1,(void *)test,sizeof(test),0,
			sizeof(test)
		   );

	
	result = test_memset_s("memset_s fails to return nonzero value when void * s"
			" == NULL.\n\n",__LINE__,1,NULL,sizeof(test),0,
			sizeof(test)
		   );

	result = test_memset_s("memset_s fails to return nonzero value when smax >"
			" RSIZE_MAX\n\n",__LINE__,1,(void *)test,RSIZE_MAX+1,0,
			sizeof(test)
		   );

	
	result = test_memset_s("memset_s fails to set the inputted char value into\n"
				"each of the first smax characters of the object\n"
				"pointed to by void *s only when there is a:\n"
				"runtime-constraint violation and\n" 
				"void * s != NULl and\n" 
				"when rsize_t\n and \n"
				"when smax is less than or equal to RSIZE_MAX\n\n",
			       __LINE__,1,(void *)test,ARRAY_SIZE,84,RSIZE_MAX+1	
			);
										

	memset_s(test,ARRAY_SIZE,0,ARRAY_SIZE);


	result = test_memset_s("memset_s fails to set the unsigned char value 84\n"
		"into each of the first 4 characters of the object\n"
		"pointed to by void *s when there is NO runtime\n"
		"constraint violation.\n\n",__LINE__,1,(void *)test,ARRAY_SIZE,84,
		4*sizeof(char)
	      );


	result = test_memset_s("memset_s fails to set the first smax values when\n"
		"rsize_t n > rsize_t smax.\n\n",__LINE__,1,(void *)test,ARRAY_SIZE,84,
		ARRAY_SIZE+1
	      );
	
	memset_s(test,ARRAY_SIZE,0,ARRAY_SIZE);

	Node * node = malloc(sizeof(Node));
	
	result = test_memset_s("memset_s fails to allocate 0 to objects\n"
		"that in turn, store other objects, like a struct.\n"
		"In the example below, a struct Node of a Linked List\n"
		"is initialized through memset_s\n\n",__LINE__,1,(void *)node,sizeof(Node),
		0,sizeof(Node)
	      );


	printf("node->link == %p\n",node->link);

	printf("node->val == %d\n\n",node->val);
	
	result = test_memset_s("memset_s fails to allocate nonzero unsigned char values to\n"
		"objects that store other objects, like a stuct.\n"
		"It initializes with a nonzero unsigned char value. In the\n"
		"example below, a second struct Node name node_two is\n"
		"initialized with the unsigned char value 84\n\n",__LINE__,1,
		(void *)node,sizeof(Node),84,sizeof(Node)
	      );


	printf("node->link == %p\n",node->link);

	printf("node->val == %d\n\n",node->val);

	printf("node->val in Hexadecimal format == 0x%x\n\n",node->val);
	
	return result;

}
