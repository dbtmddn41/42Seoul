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
	ft_putstr("Transmission complete\n");
}

void	sig_handler(int sign, siginfo_t *info, void *context)
{	
	if (info->si_pid != g_serverinfo.server_pid && info->si_pid != 0)
		error_handler_c("This is not server.");
	(void) sign;
	(void) context;
	g_serverinfo.acknowledge = 1;
}

void	knock(pid_t server_pid)
{
	int	res;

	res = send_signal(SIGUSR1, server_pid, &g_serverinfo.acknowledge);
	if (res == -1)
		error_handler_c("connection FAIL");
	ft_putstr("connection SUCCESS\n");
}

void	send_msg(char *msg)
{
	int		i;
	int		sig;
	int		res;
	pid_t	sid;

	sid = g_serverinfo.server_pid;
	while (*msg != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			sig = (*msg >> i) & 1;
			if (sig == 0)
				res = send_signal(SIGUSR1, sid, &g_serverinfo.acknowledge);
			else
				res = send_signal(SIGUSR2, sid, &g_serverinfo.acknowledge);
			if (res == -1)
				error_handler_c("no response from server");
			i--;
		}
		msg++;
	}
	send_null(sid);
}

void	send_null(pid_t sid)
{
	int	i;
	int	res;

	i = 0;
	while (i < 7)
	{	
		res = send_signal(SIGUSR1, sid, &g_serverinfo.acknowledge);
		if (res == -1)
			error_handler_c("no response from server");
		i++;
	}
	kill(sid, SIGUSR1);
}
