#include <stdio.h>

int main(void)
{
	fprintf(stderr,"\033[1;31m\n\0");	
	
	fprintf(stderr,"%d: Error! Column argument"
			" is not an integer!\n",
			__LINE__
		);
	
	fprintf(stderr,"\033[0m\0");
	
	return 0;
}
