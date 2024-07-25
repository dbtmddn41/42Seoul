#include <stdlib.h>
#include <signal.h>

int	main(int argc, char *argv[])
{
	kill(atoi(argv[1]), atoi(argv[2]));
}
