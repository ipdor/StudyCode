#include <unistd.h>
#include <stdio.h>
int main()
{
	char *encrypt = crypt("toor","$6$WQJmEIbE");
	printf("encrpyt: %s\n",encrypt);
	return 0;
}
