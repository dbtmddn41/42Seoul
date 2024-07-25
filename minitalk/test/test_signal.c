#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	sig_handler(int sign)
{
	printf("SIGINT RECEIVED %d", sign);
}

int	main(void)
{
	int	i;

	i = 0;
	signal(SIGINT, (void *)sig_handler);
	while (i < 30)
	{
		printf("%d\n", i);
		sleep(1);
		i++;
	}
}