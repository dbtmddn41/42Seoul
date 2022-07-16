#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char buf[30];
	printf("%lu %lu", sizeof(argv[1]), sizeof(buf));
}