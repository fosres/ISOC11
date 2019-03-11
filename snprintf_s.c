#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>

int snprintf_s(char * restrict s, rsize_t n, 
		const char * restrict format,
		... 
	      )
{

	int violation_present = 0;	
	
	if ( s == NULL )
	{ 
		fprintf(stderr,"snprintf_s: Error: s is NULL!\n");

		return -1;
	
	}


	if ( format == NULL )
	{
		fprintf(stderr,"snprintf_s: Error: format is NULL!\n");

		s[0] = '\0';

		return -1;

	}

	if ( n == 0 )
	{
		fprintf(stderr,"snprintf_s: Error: n is equal to zero!\n");
		
		return -1;
	}	

	if ( n > RSIZE_MAX )
	{
		fprintf(stderr,"snprintf_s: Error: n is larger than RSIZE_MAX!\n");
		
		return -1;
	}

	if ( strstr(format,"%n") != NULL )
	{
		fprintf(stderr,"snprintf_s: Error: Cannot use a %%n symbol in"
			       " the format string!\n"
		       );	      

		violation_present = -1;	
	}
	

		va_list var_arg;

		va_list var_arg_copy;

		va_start(var_arg,format);

		va_copy(var_arg_copy,var_arg);

		const char * restrict format_p = format;

		const char * restrict s_flag = format;

		while ( ( *s_flag != '\0' ) && ( ( s_flag = strstr(s_flag,"%s") ) != NULL ) )
		{
			if ( va_arg(var_arg,char *) == NULL )
			{ 
				violation_present = -1; 
				
				fprintf(stderr,"Error: %%s argument points"
						
						" to NULL char *!\n");

				break; 
			
			}

			s_flag += strnlen_s("%s",2);
		}

		va_end(var_arg);
	
	if ( ( violation_present == -1 )

		&&

		( s != NULL )

		&&

		( n > 0 )

		&&

		( n <= RSIZE_MAX )

	   )
	
	{
		s[0] = '\0';
		
		return violation_present;

	}

	else if ( violation_present == -1 )
	{ 	return violation_present; }

	else // No runtime-constraint violations found so far
	{


		va_start(var_arg_copy,format);	
	 
	 	violation_present = vsnprintf(s,n,format,var_arg_copy);
		
		return violation_present;	
	}


}

