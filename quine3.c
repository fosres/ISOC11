#include <stdio.h>
#include <string.h>
#include <stdint.h>
int main(void)
{
	rsize_t i = 0;
	const rsize_t opening = __LINE__ + 1;	
	char * q [] =
{
"#include <stdio.h>",
"#include <string.h>",
"#include <stdint.h>",
"int main(void)",
"{",
"	rsize_t i = 0;",
"	const rsize_t opening = __LINE__ + 1;",
"	char * q [] =",
"	{",
"	};",
"	while ( i < opening )",
"	{",
"		puts(q[i]);",
"		i++;",
"	}",
"	i = 0;",
"	while ( q[i] != NULL )",
"	{",
"		printf(\"%c%s%c%c%c\",34,q[i],34,44,10);",
"		i++;",
"	}",
"	i = opening;",
"	while ( q[i] != NULL )",
"	{",
"		puts(q[i]);",
"		i++;",
"	}",
"	return 0;",
"}",
};
	while ( i < opening )
	{
		puts(q[i]);
		i++;
	}
	i = 0;
	while ( q[i] != NULL )
	{
		printf("%c%s%c%c%c",34,q[i],34,44,10);
		i++;
	}
	i = opening;
	while ( q[i] != NULL )
	{
		puts(q[i]);
		i++;
	}
	return 0;
}

