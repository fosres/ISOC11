#include <stdio.h>
#include <ctype.h>
#include <string.h>

static unsigned char ascii_line[17];

static unsigned char * buf;

int print_table(unsigned char * s,unsigned char ASCII[], const rsize_t ASCII_SIZE)
{
	rsize_t i = 0;	
	
	while ( *s != 0x0 )
	{
		
		if ( i%16 == 0  )
		{
			printf("%s\n%08x",ASCII,i);
		}	
		else if ( isprint(*s) != 0 )
		{
			(i%2 == 0) ? ( printf("%x",*s) ) : printf("%u%x",0x9,*s);
		}

		else
		{
			
		}

		(i%16 != 0) 
			
			? 
			
			( ASCII[i%16] = *s ) 
			
			: 
				
			( printf("%s\n%08x",ASCII,i), memset_s(ASCII,ASCII_SIZE,0x0,16) );
		
		s++;
		i++;	
	}

}

int main(int argc, char ** argv)
{
	FILE * in = NULL;

	if ( argc != 2 )
	{
		fprintf("%d: Less than two arguments!\n",__LINE__,argv[1]);

		return 1;
	}

	if ( ( in = fopen(argv[1],"r") ) == NULL )
	{
		fprintf("%d: Failed to open %s!\n",__LINE__,argv[1]);

		return 1;
	}
	
	fseek(in,0L,SEEK_END);

	const rsize_t SIZE = ftell(in);

	fflush(in);

	rewind(in);
	

	buf = (unsigned char *)calloc(SIZE+1,sizeof(char));

	buf[SIZE] = 0x0;
	
	fread(buf,SIZE+1,sizeof(char),in);
	
	
	
	free(buf);

	return 0;
}
