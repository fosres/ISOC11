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
	

//#if 0


		va_list var_arg;

		va_list var_arg_copy;

		va_start(var_arg,format);

		va_copy(var_arg_copy,var_arg);

		const char * restrict format_p = format;

		const char * restrict s_flag = format;

		while ( ( *s_flag != '\0' ) && ( ( s_flag = strstr(s_flag,"%s") ) != NULL ) )
		{
			if ( va_arg(var_arg,char *) == NULL )
			{ violation_present = -1; break; }

			s_flag += strnlen_s("%s",2);
		}

		va_end(var_arg);
//#endif
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
#if 0			
		va_list var_arg;

		va_list var_arg_copy;

		va_start(var_arg,format);

		va_copy(var_arg_copy,var_arg);

		const char * restrict format_p = format;

		const char * restrict s_flag = format;

		while ( ( s_flag = strstr(s_flag,"%s") ) != NULL )
		{
			if ( va_arg(var_arg,char *) == NULL )
			{ s[0] = '\0'; return -1; }

			s_flag += strnlen_s("%s",2);
		}

		va_end(var_arg);

#endif

#if 0
 Check if any of the variable args is a NULL pointer here
#endif

		va_start(var_arg_copy,format);	
	 
	 	violation_present = vsnprintf(s,n,format,var_arg_copy);
#if 0
		va_start(var_arg_copy,num_var_string_args);
		
		rsize_t count = 0;

		rsize_t i = 0;

		char * restrict s_p = &s[0];

		char const * restrict s_end = s + n;

		const char * restrict format_p = format;

		const char * restrict format_zero = &format[0];

		char const * restrict format_end = format + count;


		char * current_var_arg = NULL;

		while ( 
			
			( s_p < s_end )

			&&

			( format_p < format_end )

			&&

			( *format_p != '\0' )

		     
		      )
		{
			
			if (  	( i < num_var_string_args ) 
					
				&& 
				
				( abs( strstr(format_p,"%s") - format_p ) == 0  )
			   )

			{
				
				current_var_arg = va_arg( var_arg_copy, char * ); 	
				
				count = n - strnlen_s(s,n) - 1;	
				
				strncat_s( s,n,current_var_arg,count );

				s_p += count;	

				format_p += strnlen_s("%s",2);
				
				i++;

				continue;
			}
			
			*s_p++ = *format_p++;

		}	

		va_end(var_arg_copy);	
#endif
		return violation_present;	
	}


}

