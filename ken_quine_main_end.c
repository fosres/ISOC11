
//#include <stdio.h>
//#include "src_code.h"

int generate_target_file(char ** argv)
{
#if 0

FILE * target_file = NULL;

static char name[1024];  

snprintf_s(name,1024,"%s\b\b_quine.c\0",1024,argv[1]);


if ( ( target_file = fopen(name,"wb+") ) == NULL )
{
	
	fprintf(stdout,"%d: Error! Can't open %s for rewriting!\n",name);

	return 1;
}



static char * q_p = q;

while ( *q_p != 0x0 )
{
	fputc(*q_p,target_file);

	q_p++;
}


fprintf(target_file,"%s\n",q);

if ( fclose(target_file)  == EOF )
{
	fprintf(stdout,"Error! Failed to close %s!\n",name);

	return 1;

}
#endif

return 0;

}

int main(void)
{

	printf("%s\n",tf);

}
