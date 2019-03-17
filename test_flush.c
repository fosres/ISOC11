#include <stdio.h>

int main(void)
{
	int i = 0;

	while ( i < 100 )
	{	printf("%d\n",i);
		i++;
	}

	fflush(stdout);
	fseek(stdout,0,SEEK_SET);
	
	return 0;

}
	
