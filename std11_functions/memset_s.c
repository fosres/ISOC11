#include <stdio.h>
#include <string.h>
#include <stdint.h>

errno_t memset_s(void *s,rsize_t smax, int c, rsize_t n)
{
	errno_t violation_present = 0;	

	volatile unsigned char * v = s;
	
	if ( 	
		s == NULL 
	
		||
		
		n > RSIZE_MAX

		||

		n > smax
		
		||

		smax > RSIZE_MAX		
	   )
	{

		violation_present = 1;
	}


	rsize_t i = 0;

	if ( ( violation_present == 1 ) && ( s != NULL ) && ( smax <= RSIZE_MAX ) )
	{

		i = 0;

		while ( i++ < smax )
		{
			*v++ = (unsigned char)c; 

		}	
		
		
		return violation_present;

	}

	else if ( violation_present )
	{ 	return violation_present; }
		
	
	else // no runtime-constraint violation found		
	{
		i = 0;


		while ( i++ < n )
		{
			*v++ = (unsigned char)c;

		}
		

		return violation_present;

	}


}
