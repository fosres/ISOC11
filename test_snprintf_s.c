#include <stdio.h>
#include <string.h>

#define MAXSIZE 1024

int main(int argc, char ** argv)
{
	static char s1[MAXSIZE];

	static char s2[MAXSIZE];

	if ( argc < 2 )
	{ fprintf(stderr,"Error: Less than two arguments given!\n"); }

	printf("Does snprintf_s work on a normal string with no %%s\n");

	snprintf_s( s1,MAXSIZE,argv[1] );

	printf("String s1: %s\n",s1);
	
	printf("Does snprintf_s work on a string with %%s\n");
	
	snprintf_s(s1,MAXSIZE,"I like %s and %s\n",argv[1],argv[2]);

	printf("String s1: %s\n",s1);

	return 0;
}
