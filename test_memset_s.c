#include <stdio.h>
#include <string.h>


int main(void)
{
	printf("This program only checks for runtime-constraint\n"
		"violations in an invocation of memset_s.\n\n"
	      );

	struct addrinfo test;

	printf("Does memset_s return nonzero value when void * s"
		" == NULL?\n\n?"
	      );

	memset_s(NULL,sizeof(test),0,sizeof(test));

	printf("Return Value: %llu\n\n");

	printf("Does memset_s return nonzero value when smax >"
		" RSIZE_MAX?\n\n"
	      );

	memset_s(test,RSIZE_MAX+1,0,sizeof(test));

		
	return 0;
}
