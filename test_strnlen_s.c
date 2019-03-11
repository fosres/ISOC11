#include <stdio.h>
#include <string.h>

#define MAXSIZE 1024

#define TEST_MAX 5

int main(int argc, char ** argv)
{
	size_t len = 0;	
	
	printf("Does strnlen_s return 0 when s is a NULL pointer?\n");

	len = strnlen_s(NULL,MAXSIZE);

	printf("Length of s: %llu\n",len);

	printf("Does strnlen_s return number of characters preceding"
		" NUL character?\n");

	len = strnlen_s("I like pie.\n\0",MAXSIZE);

	printf("Length of s: %llu\n",len);
		
	printf("Does strnlen_s return MAXSIZE as length when"
		" actual string is at least as large as"
		" MAXSIZE?\n"
	      );

	len = strnlen_s("Lies.\0",TEST_MAX);

	printf("Length of s: %llu\n",len);

	printf("Does strnlen_s return MAXSIZE as length when"
		" actual string is larger than MAXSIZE?\n"
	      );

	len = strnlen_s("I like pie.\n\0",TEST_MAX);

	printf("Length of s: %llu\n",len);
	
	return 0;
}
