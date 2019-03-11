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
		fprintf(stderr,"Error: s is NULL!\n");

		return -1;
	
	}


	if ( format == NULL )
	{
		fprintf(stderr,"Error: format is NULL!\n");

		violation_present = -1;

	}

	if ( n == 0 )
	{
		fprintf(stderr,"Error: n is less than zero!\n");
		
		return -1;
	}	

	if ( n > RSIZE_MAX )
	{
		fprintf(stderr,"Error: n is larger than RSIZE_MAX!\n");

		return -1;
	}

	if ( strstr(format,"%n") != NULL )
	{
		fprintf(stderr,"Error: Cannot use a \%n symbol in"
			       " the format string!\n"
		       );	      

		violation_present = -1;	
	}
	
	size_t num_var_string_args = 0;

	const char * string_flag = format;

	while ( ( string_flag = ( strstr( string_flag,"%s" ) ) ) != NULL )
	{
		num_var_string_args++;

		string_flag += strnlen_s("%s",2);	
	}

	va_list var_arg;

	va_start(var_arg,num_var_string_args);

	for ( size_t i = 0; i < num_var_string_args ; i++ )
	{
		if ( va_arg( var_arg, char * ) == NULL )
		{ violation_present = 1; }
	}
	
	va_end(var_arg);	
	
	if ( ( violation_present == -1 )

		&&

		( s != NULL )

		&&

		( n > 0 )

		&&

		( n < RSIZE_MAX )

	   )
	
	{
		s[0] = '\0';
		
		return violation_present;

	}

	else if ( violation_present == -1 )
	{ 	return violation_present; }

	else // No runtime-constraint violations found
	{
			

		va_start(var_arg,num_var_string_args);
		
		const rsize_t count = 0;

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
				
				current_var_arg = va_arg( var_arg, char * ); 	
				
				count = n - strnlen_s(s,n) - 1;	
				
				strncat_s( s,n,current_var_arg,count );

				s_p += count;	

				format_p += strnlen_s("%s",2);
				
				i++;

				continue;
			}
			
			*s_p++ = *format_p++;

		}	

		va_end(var_arg);	

		return 0;	
	}


}

