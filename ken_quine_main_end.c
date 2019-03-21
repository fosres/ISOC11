
void generate_target_file(void)
{

FILE * target_file = NULL;

static char name[1024];  

snprintf(name,"%s\b\b_quine.c\0",argv[1]);


if ( ( target_file = fopen(name,"wb+") ) == NULL )
{
	
	fprintf(stdout,"%d: Error! Can't open %s for rewriting!\n",name);

	return 1;
}



static char * q_p = q;

while ( *q_p != 0x0 )
{
	fputc(target_file,*q_p);

	q_p++;
}


fprintf(target_file,"%s\n",q);

if ( fclose(target_file)  == EOF )
{
	fprintf(stdout,"Error! Failed to close %s!\n",name);

	return 1;

}

}
