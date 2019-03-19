#include <stdio.h>

int main(int argc, char ** argv)
{
	if ( argc != 2 )
	{ 
		fprintf(stderr,"%d: Error! Less than two arguments!\n",__LINE__);	
		return 1;
	}

	FILE * in = NULL;

	if ( 
		( ( in = fopen(argv[1],"rb") ) == NULL )
	   )	
	{
		fprintf(stderr,"%d: Error! Failed to read file!\n");

		return 1;
	}

	char c = 0;

	while ( ( c = fgetc(in) ) != EOF )
	{
		putchar(c);
	}

	if ( fclose(in)  == EOF )
	{
		fprintf(stderr,"%d: Error! Failed to close file!\n");

		return 1;
	}

	return 0;

}
