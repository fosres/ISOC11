#include <stdio.h>
#include <string.h>

int main(void)
{
	rsize_t i = 0;

	
	printf("static char q[] =\n");
	
	printf("{\n");
	
	while ( q[i] != 0x0 )
	{ printf("0x%02x, ",q[i]); i++; }

	printf("};\n");

	printf("%s\n",q);
	return 0;
}
