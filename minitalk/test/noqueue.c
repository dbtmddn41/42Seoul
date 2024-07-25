#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void sig_handler(int signo);

int main(int argc, char **argv)
{
  int i = 0;
  signal(SIGINT, (void *)sig_handler);
  signal(SIGTSTP, (void *)sig_handler);
  while(1)
  {
    printf("%d\n", i);
    sleep(2);
    i++;
  }
}

void sig_handler(int signo)
{
	int	i;
	printf("I Received signal(%d)\n", signo);
	i = 0;
	while (i < 3)
	{
		printf("%c", 'a' + i);
		sleep(1);
		i++;
	}
}