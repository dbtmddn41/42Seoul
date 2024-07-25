#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	handler(int sign, siginfo_t *info, void *context)
{
	printf("first argument: %d\n", sign);
	printf("info->signo: %d\n", info->si_signo);
	printf("info->value: %d\n", info->si_value);
}

void	set_signal(int sig, void *handler_func)
{
	static struct sigaction	act;

	act.sa_flags = 0;
	act.sa_flags |= SA_SIGINFO;
	sigemptyset(&(act.sa_mask));
	act.__sigaction_u.__sa_sigaction = handler_func;
	sigaction(sig, &act, 0);
}

int	main(void)
{
	pid_t	server_id;

	server_id = getpid();
	printf("server pid: %d\n", server_id);
	while (1)
	{
		set_signal(SIGUSR1, handler);
		pause();
	}
}
