#include <stdio.h>
#include <string.h>
#include <stdint.h>

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

	printf("Does snprintf_s return -1 when s == NULL?\n");

	return_value = snprintf_s(NULL,MAXSIZE,argv[1]);
	
	printf("Return Value: %d String s1: %s\n",return_value, s1);
	
	printf("Does snprintf_s return -1 and leave s1 empty when format == NULL?\n");

	return_value = snprintf_s(s1,MAXSIZE,NULL);

	printf("Return Value: %d String s1: %s\n",return_value, s1);

	printf("Does snprintf_s return -1 when input for n == 0?\n");

	return_value = snprintf_s(s1,0,"%s %s",argv[1],argv[2]);	

	printf("Return Value: %d String s1: %s\n",return_value, s1);
	
	printf("Does snprintf_s return -1 when n > RSIZE_MAX?\n");

	return_value = snprintf_s(s1,RSIZE_MAX+1,"%s %s",argv[1],argv[2]);

	printf("Does snprintf_s return -1 and leave s1 empty"
		" when %%n is present in format?\n"
	      );

	return_value = snprintf_s(s1,MAXSIZE,"%s %s %n",argv[1],argv[2]);	

	printf("Return Value: %d String s1: %s\n",return_value, s1);

	printf("Does snprintf_s return -1 and leave s1 empty when"
		" a %s argument points to a NULL char *?\n"
	      );
	
	return_value = snprintf_s(s1,MAXSIZE,"%s %s %s",argv[1],argv[2],argv[3]);

	printf("Return Value: %d String s1: %s\n",return_value, s1);

	return 0;
}
