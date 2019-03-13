#if 0

According to Secure Coding in C and C++, 2nd ed, "realloc is

the most problematic (dynamic)[sic] memory ,oaagement function"

If the realloc function fails to allocate memory for the

extended object, the old object is not deallocated, and the

old object's value remains unchanged.

The worst problem with realloc:

realloc(p,0) is implementation defined

This is against the purpose of portability and standardization.

realloc_s here prevents these dynamic memory problems

Returns:

Memory Address of First Object in a dynamic array of objects Upon Success

NULL if realloc_s fails to allocate enough memory for extended array of

objects.

#endif

#include <stdio.h>

void * realloc_s(void * s,size_t size)
