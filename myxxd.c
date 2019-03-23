#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ARRSIZE 16

void print_table(FILE * in,unsigned char ASCII[], const rsize_t FILE_SIZE)
{
	rsize_t i = 0;

	unsigned char c = 0;

	while ( i < FILE_SIZE )
	{
		c = fgetc(in);

		if ( (i%ARRSIZE != 0) && (i != 0) ) 
			
		{ 
			isprint(c) ? (ASCII[i%ARRSIZE] = c) : (ASCII[i%ARRSIZE] = 0x2e);
		}

		else
		{
			 printf("%s\n%08x:%c",ASCII,i,0x9); 
			  
			 memset_s(ASCII,ARRSIZE,0x0,16);
		}

		if ( isprint(c) )
		{
			(i%2 == 0) ? ( printf("%02x",c) ) : printf("%c%02x",0x9,c);
		}
		
		else
		{
			(i%2 == 0) ? ( printf("%02x",0x2e) ) : printf("%c%02x",0x9,0x2e);
		}
		

		i++;	
	}

}

int main(int argc, char ** argv)
{

	FILE * in = NULL;

	if ( argc != 2 )
	{
		fprintf(in,"%d: Less than two arguments!\n",__LINE__,argv[1]);

		return 1;
	}

	if ( ( in = fopen(argv[1],"r") ) == NULL )
	{
		fprintf(in,"%d: Failed to open %s!\n",__LINE__,argv[1]);

		return 1;
	}
	
	fseek(in,0L,SEEK_END);

	const rsize_t SIZE = ftell(in);

	static unsigned char ascii_line[17];

	ascii_line[16] = 0x0;

	rewind(in);

	print_table(in,ascii_line,SIZE);

	if ( fclose(in) == EOF )
	{
		fprintf(stdout,"%d: Error! Failed to %s\n",__LINE__,argv[1]);
		
		return 1;
	}
	

	return 0;
}
