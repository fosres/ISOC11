#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main(int argc, char ** argv)
{
	
	FILE * in = NULL;

	if ( argc != 2 )
	{ 
		fprintf(stderr,"Error! Less than two arguments.\n");	
		return 1;
	}

	if ( ( in = fopen(argv[1],"rb") ) == NULL )
	{
		fprintf(stderr,"Error! Failed to open file!\n");

		return 1;
	}



	const rsize_t SIZE = fseek(in,0L,SEEK_END);

	rewind(in);
#if 0
	static char * str; 
	
	str = (char *)calloc(sizeof(char),SIZE);

	static char * s_p; 
	
	s_p = &str[0];
	
	fread(str,SIZE,sizeof(char),in);
#endif
	char c = 0;

// stores the contents of the source code in hexadecmial
// Ken Thompson thought of this simple, brilliant idea

	printf("char q[] = \n{\n");
	while ( ( c = fgetc(in) ) != EOF )
	{
		printf("0x%x, ",c);	
	}
	printf("0x0",stdout);
	printf("};\n");

// prints the contents of the source code in ASCII text:

	rewind(in);

	printf("Printing contents of source in ASCII text:\n\n");

	while ( ( c = fgetc(in) ) != EOF )
	{
		fputc(c,stdout);
	}

	if ( fclose(in) == EOF )
	{
		fprintf(stderr,"Error! Failed to open file!\n");

		return 1;
	}
	
	return 0;
}
