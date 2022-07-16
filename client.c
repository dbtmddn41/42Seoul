/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:56:11 by slyu              #+#    #+#             */
/*   Updated: 2022/07/16 13:56:13 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_server	g_serverinfo;

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_putendl_fd("Usage: ./client <server PID> <string>", 2);
		return (0);
	}
	ft_printf("my PID: %d\n", getpid());
	g_serverinfo.server_pid = ft_atoi(argv[1]);
	g_serverinfo.acknowledge = 0;
	set_signal(SIGUSR1, sig_handler);
	knock(g_serverinfo.server_pid);
	send_msg(argv[2]);
}

void	sig_handler(int sign, siginfo_t *info, void *context)
{
	if (sign != SIGUSR1)
	{
		error_handler("Invalid signal");
	}
	(void) info;
	(void) context;
	g_serverinfo.acknowledge = 1;
}

void	knock(pid_t server_pid)
{
	kill(server_pid, SIGUSR1);
	pause();//usleep(WAIT_TIME);
	sleep(1);
	if (!g_serverinfo.acknowledge)
		error_handler("connection failed");
	else
		ft_putstr("connection SUCCESS\n");
	g_serverinfo.acknowledge = 0;
}

void	send_msg(char *msg)
{
	int		i;
	int		sig;
	pid_t	server_id;

	server_id = g_serverinfo.server_pid;
	while (*msg != '\0')
	{
		i = 8;
		while (--i >= 0)
		{
			sig = (*msg >> i) & 1;
			if (sig == 0)
				kill(server_id, SIGUSR1);
			else
				kill(server_id, SIGUSR2);
			pause();
			sleep(1);
			if (!g_serverinfo.acknowledge)
				error_handler("no confirm from server.");
			g_serverinfo.acknowledge = 0;
		}
		msg++;
	}
	while (i++ < 7)
	{
		kill(server_id, SIGUSR1);
		pause();
		sleep(1);
	}
	ft_putstr("Transmission complete\n");
}

void	error_handler(char *msg)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(msg, 2);
	exit(-1);
}
