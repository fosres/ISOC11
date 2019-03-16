#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print(int x)
{
	char * buf = itoa(x,NULL,10);
	puts(buf);
}

int main(void)
{
	rsize_t opening = 15;
	rsize_t i = 0;
	char  * q[] = 
	{
"#include <stdio.h>",
"#include <stdlib.h>",
"#include <stdint.h>",
"",
"void printf(int x)",
"{",
"	char * buf = itoa(x,NULL,10);",
"	puts(buf);",
"}",
"",
"int main(void)",
"{",
"	rsize_t opening = 15",
"	rsize_t i = 0;",
"	char  * q[] =",
"	{",
"	};",
"	while (i <= opening)",
"	{",
"		printf(q[i]);putchar(10);i++;",
"	}",
"	i = 0;",
"	while (q[i] != NULL)",
"	{",
"		putchar(34);printf(q[i]);putchar(34);putchar(44);putchar(10);i++;",
"	}",
"	i = opening+1;",
"	while (q[i] != NULL)",
"	{",
"		printf(q[i]);putchar(10);i++;",
"	}",
"	return 0;",
"}",
NULL
	};
	while (i <= opening)
	{
		printf(q[i]);putchar(10);i++;
	}
	i = 0;
	while (q[i] != NULL)
	{
		putchar(34);printf(q[i]);putchar(34);putchar(44);putchar(10);i++;
	}

	i = opening+1;
	while ( q[i] != NULL )
	{
		printf(q[i]);putchar(10);i++;
	}
	return 0;
}
