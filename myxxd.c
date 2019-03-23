#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#if 0

Bug: Number of columns == Number of bytes per row!

ARRSIZE == (desired number of columns)/2

default number of columns: 16 to make 16 bytes total per row

for 8 columns

So:

ARRSIZE == Number of desired columns

Simple! :D
#endif
//#define ARRSIZE_ORIGINAL 16
#define ARRSIZE(x)  (x)

void print_table(FILE * in,unsigned char ASCII[], const rsize_t FILE_SIZE)
{
	rsize_t i = 0;

	unsigned char c = 0;

	while ( i < FILE_SIZE )
	{
		c = fgetc(in);

		if ( (i%ARRSIZE != 0) ) 
			
		{ 
			isprint(c) ? (ASCII[i%ARRSIZE] = c) : (ASCII[i%ARRSIZE] = 0x2e);
		}

		else
		{
			 printf("%s\n%08x:%c",ASCII,i,0x9); 

			 memset_s(ASCII,ARRSIZE,0x0,ARRSIZE);
		}
#if 0
When printing the actual hexadecimal table, 

do not replace the actual hexadecimal with

0x2e!
#endif
			(i%2 == 0) ? ( printf("%02x",c) ) : printf("%02x%c",c,0x9);
		

		i++;	
	}

}

#if 0
Last argument, argument index

argc-1, must have filename
#endif

int main(int argc, char ** argv)
{
	ARRSIZE(16);

	FILE * in = NULL;

	if ( argc < 2 )
	{
		fprintf(in,"%d: Less than two arguments!\n",__LINE__);

		return 1;
	}


	if ( ( in = fopen(argv[argc-1],"r") ) == NULL )
	{
		fprintf(in,"%d: Failed to open %s!\n",__LINE__,argv[argc-1]);

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
		fprintf(stdout,"%d: Error! Failed to %s\n",__LINE__,argv[argc-1]);
		
		return 1;
	}
	

	return 0;
}
