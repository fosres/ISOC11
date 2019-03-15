#include <stdio.h>
#include <string.h>
int main(void)
{
	char * quine[] =
	{
	"#include <stdio.h>",
	"#include <string.h>",
	"int main(void)",
	"{", 	
	"	char * quine[] =",
	"{",
	"};",
	"	int i = 0;",
	"	while ( i < 6 )", 	
	"	{",
	"		printf(quine[i]);",
	"		putchar(10);",
	"		i++;",
	"	}",	
	"	i = 0;",
	"	while ( quine[i] != NULL )",
	"	{",
	"		putchar(34);",
	"		printf(quine[i]);",
	"		putchar(34);",
	"		putchar(44);",
	"		putchar(10);",
	"		i++;",
	"	}",
	"	i = 6;",
	"	while ( quine[i] != NULL )",
	"	{",
	"		puts(quine[i]);",
	"		i++;",
	"	}",
	"	return 0;",
	"}"	
	};

		int i = 0;
		while ( i < 6 ) 
		{
			printf(quine[i]);
			putchar(10);
			i++;
		}	
		i = 0;
		while ( quine[i] != NULL )
		{
			putchar(34);	
			printf(quine[i]);
			putchar(34);
			putchar(44);
			putchar(10);
			i++;
		}
		i = 6;
		while ( quine[i] != NULL )
		{
			puts(quine[i]);	
			i++;
		}
		return 0;

}
