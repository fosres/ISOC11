#include <stdio.h>

int main(void)
{
	rsize_t i = 0;
	rsize_t opening = 7;
	char * q[] = 
	{
"#include <stdio.h>",
"",
"int main(void)",
"{",
"	rsize_t i = 0;",
"	rsize_t opening = 7;",
"	char * q[] = ",
"	{",
"	};",
"	while ( i <= opening )",
"	{",
"		puts(q[i]);",
"		",
"		i++;",
"	}",
"	i = 0;",
"	while ( q[i] != NULL )",
"	{",
"		putchar(34);",
"		printf(q[i]);",
"		putchar(34);",
"		putchar(44);",
"		putchar(10);",
"		i++;",
"	}",
"	i = opening+1;",
"	while ( q[i] != NULL )",
"	{",
"		puts(q[i]);",
"",
"		i++;",
"	}",
"	",
"	return 0;",
"}",
NULL
	};
	while ( i <= opening )
	{
		puts(q[i]);
		
		i++;
	}
	i = 0;
	while ( q[i] != NULL )
	{
		putchar(34);
		printf(q[i]);
		putchar(34);
		putchar(44);
		putchar(10);
		i++;
	}
	i = opening+1;
	while ( q[i] != NULL )
	{
		puts(q[i]);

		i++;
	}
	
	return 0;
}
