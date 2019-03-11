#include <stdio.h>
#include <string.h>

#define MAXSIZE 1024

int main(int argc, char ** argv)
{
	static char s1[MAXSIZE];

	static char s2[MAXSIZE];

	int return_value = 0;

	if ( argc < 2 )
	{ fprintf(stderr,"Error: Less than two arguments given!\n"); }

	printf("Does snprintf_s work on a normal string with no %%s?\n");

	return_value = snprintf_s( s1,MAXSIZE,argv[1] );

	printf("Return Value: %d String s1: %s\n",return_value,s1);
	
	printf("Does snprintf_s work on a string with %%s?\n");
	
	return_value = snprintf_s(s1,MAXSIZE,"%s %s",argv[1],argv[2]);

	printf("Return Value: %d String s1: %s\n",return_value, s1);
	
	printf("Does snprintf_s give an error and return -1 when"
		" a %s argument points to a NULL char *?\n"
	      );
	
	return_value = snprintf_s(s1,MAXSIZE,"%s",argv[3]);

	printf("Return Value: %d String s1: %s\n",return_value, s1);

	return 0;
}
