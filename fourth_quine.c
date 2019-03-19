#include <stdio.h>
static char * s = 
"#include <stdio.h>  \n \\ \
static char * s =   \n \\ \
%c  \n\
%s  \n\
%c;  \n\	
int main(void)   \n\
{  \n\
	static char * f = \\\"swag\\\";  \
  \n\
	printf(f,10);  \n\
	printf(s,34,s,34);   \n\
	return 0;	  \n\
}  \
";
int main(int argc, char ** argv)
{
	static char * f = "swag\0";
	printf("%s\n",f);
	fprintf(stdout,s,34,s,34);
	return 0;
}
