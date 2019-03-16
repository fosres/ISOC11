#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x = 3;
	char * buf = itoa(x,NULL,10);
	printf("%s\n",buf);
	return 0;
}
