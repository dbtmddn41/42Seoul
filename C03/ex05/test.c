#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	str[30] = "happy";
	printf("%lu\n", strlcat(str, "lifehahha", atoi(argv[1])));
	printf("%s", str);
}
