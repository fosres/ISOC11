#include <stdio.h>
#include <string.h>
#include <stdint.h>

errno_t memset_s(void *s,rsize_t smax, int c, rsize_t n)
{
	errno_t violation_present = 0;	

	volatile unsigned char * v = s;
	
	if ( s == NULL )
	{
		fprintf(stderr,"memset_s: Error: void * s == NULL!\n");

		return 1;
	}

	if ( n > RSIZE_MAX )
	{
		fprintf(stderr,"memset_s: Warning: rsize_t n > RSIZE_MAX!\n");	

		violation_present = 1;
	}

	if ( n > smax )
	{
		fprintf(stderr,"memset_s: Warning: rsize_t n > rsize_t smax!\n");	

		violation_present = 1;


	}

	if ( smax > RSIZE_MAX )
	{
		fprintf(stderr,"memset_s: Error: rsize_t smax > RSIZE_MAX!\n");

		return 1;
	}

	volatile unsigned char * v_p = &v[0];

	rsize_t i = 0;

	if ( violation_present == 1 ) // && (s != NULL) && (smax <= RSIZE_MAX) )
	{

		i = 0;

		while ( i < smax )
		{
			*v_p++ = (unsigned char)c; 

			i++;
		}	
		
//		memset(s,(unsigned char)c,smax);	
		
		return violation_present;

	}
		
	
	else // no runtime-constraint violation found		
	{
		i = 0;


		while ( i < n )
		{
			*v_p++ = (unsigned char)c;

			i++;
		}
		
//		memset(s,(unsigned char)c,n);	

		return violation_present;

	}


}
