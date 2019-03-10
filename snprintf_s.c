#include <stdio.h>
#include <string.h>
#include <stdarg.h>

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

	char * string_flag = format;

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
		snprintf( s, n, format, ...);

		return 0;	
	}


}

