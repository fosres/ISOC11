#include <stdio.h>
static char *msg = "The car
";static char *s =      "#include <stdio.h>%cstatic char *msg = %c%s%c;static char *s =      %c%s%c; int main(void)      {      	printf(msg,34,msg,34);	printf(s,34,s,34);		return 0;}      "; int main(void)      {      	printf(msg,34,msg,34);	printf(s,34,s,34);		return 0;}      