#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
int x = 0;

void * stack_bottom;

typedef struct Node
{
	struct Node * link;

	char val;
} Node;

_Bool IS_IN_STACK(void *x) __attribute__((noinline));

_Bool IS_IN_STACK(void *x)
{
	void * stack_top = &stack_top;

	return ( ( x <= stack_bottom ) && ( x >= stack_top ) );

}

_Bool a;

int main(int argc, char ** argv)
{
	stack_bottom = &x;
	
	int * d = (int *)malloc(1*sizeof(int));	

	
	Node * node = (Node *)malloc(1*sizeof(Node));	
	
	Node memset_node;

	memset_s((Node *)&memset_node,sizeof(Node),0,sizeof(Node));

//	stack_bottom = &x;

	int s = 0;	

	int * h = (int *)malloc(1*sizeof(int));
	
	printf("&x = %p &s = %p h = %p d = %p &argc = %p\n"
		"argv = %p *argv = %p node = %p\n"
		"memset_node = %p\n\n",
		&x,&s,h,d,&argc,argv,*argv,node,&memset_node
	      );

	printf("Are above values in stack or heap? 1 means in stack.\n" 
		"0 means heap.\n\n"
	      );

	printf("x: %u s: %u h: %u d: %u argc: %u argv: %u *argv: %u node: %u\n"
		"memset_node: %u\n\n",IS_IN_STACK(&x),IS_IN_STACK(&s),
		IS_IN_STACK(h),IS_IN_STACK(d),IS_IN_STACK(&argc),
		IS_IN_STACK(argv),IS_IN_STACK(*argv),IS_IN_STACK(node),
		IS_IN_STACK(&memset_node)
	      );
	
	return 0;
}
