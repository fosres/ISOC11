#include <stdio.h>
#include <string.h>

typedef struct Node
{



} Node;

int main(void)
{
	int a[10];

	memset(a,0,sizeof(int)*10);

	rsize_t i = 0;

	while ( i < 10 )
	{
		printf("%d ",a[i]);
		
		i++;
	}

	return 0;
}
