#include <stdio.h>

int main(int argc, char * argv[])
{
	if ( argc != 2 )
	{ 
		fprintf(stderr,"%d: Error: Less than two arguments!\n",__LINE__);

		return 1;
	}	
	
	FILE * in = NULL;

	if ( 
		( ( in = fopen(argv[1],"r+") )  == NULL )
	   )
	{
		fprintf(stderr,"%d: Error: Failed to open file!\n",__LINE__);

		return 1;	
	}
	
	remove(argv[1]);

	if ( fclose(in) == EOF )
	{
		fprintf(stderr,"%d: Error: Failed to open file!\n",__LINE__);

		return 1;
	}
	
	return 0;	
}
