#include <signal.h> 
#include <unistd.h>
#include <stdio.h> 

void	USR1_handler(int sign, siginfo_t *info, void *context)
{
	printf("신호 준 새끼 pid: %d", info->si_pid);
}

int	main(void)
{
	struct sigaction	act;
	pid_t	my_pid;
	
	act.sa_flags = 0;
	act.sa_flags |= SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	act.__sigaction_u.__sa_sigaction = USR1_handler;
	sigaction(SIGUSR1, &act, NULL);

	my_pid = getpid();
	printf("my pid: %d", my_pid);
	pause();
}