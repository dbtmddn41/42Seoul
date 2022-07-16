/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:27:16 by slyu              #+#    #+#             */
/*   Updated: 2022/07/16 15:27:18 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_client	*g_clientinfo;

int	main(void)
{
	pid_t				my_pid;

	g_clientinfo = malloc(sizeof(t_client));
	if (!g_clientinfo)
	{
		ft_putendl_fd("malloc error", 2);
		return (0);
	}
	my_pid = getpid();
	ft_printf("server PID: %d\n", my_pid);
	while (1)
	{
		set_signal(SIGUSR1, waiting_handler);
		pause();
		recieve_msg();
	}
	free(g_clientinfo);
}

void	waiting_handler(int sign, siginfo_t *info, void *context)
{
	if (sign != SIGUSR1)
	{
		pause();
		return ;
	}
	(void) context;
	g_clientinfo->client_pid = info->si_pid;
	g_clientinfo->buffer_index = 0;
	g_clientinfo->error_flag = 0;
	kill(SIGUSR1, g_clientinfo->client_pid);
	ft_printf("conneted to PID: %d\n", g_clientinfo->client_pid);
	set_signal(SIGUSR1, recieve_handler);
	set_signal(SIGUSR2, recieve_handler);
}

void	recieve_handler(int sign, siginfo_t *info, void *context)
{
	if (g_clientinfo->client_pid != info->si_pid)
	{
		error_handler("other client inturrupted");
		return ;
	}
	(void) context;
	g_clientinfo->buf[g_clientinfo->buffer_index] <<= 1;
	if (sign == SIGUSR1)
		g_clientinfo->buf[g_clientinfo->buffer_index] &= 0xfe;
	else if (sign == SIGUSR2)
		g_clientinfo->buf[g_clientinfo->buffer_index] |= 0x1;
	kill(g_clientinfo->client_pid, SIGUSR1);
}

void	recieve_msg(void)
{
	int		i;

	i = 0;
	while (1)
	{
		while (g_clientinfo->buffer_index < BUFFER_SIZE)
		{
			pause();
			if (g_clientinfo->error_flag)
				return ;
			i++;
			if (i >= 7)
			{
				if (g_clientinfo->buf[g_clientinfo->buffer_index] == '\0')
					break ;
				(g_clientinfo->buffer_index)++;
				i = 0;
			}
		}
		write(1, g_clientinfo->buf, g_clientinfo->buffer_index + 1);
		if (g_clientinfo->buf[g_clientinfo->buffer_index] == '\0')
			break ;
	}
}

void	error_handler(char *msg)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(msg, 2);
	g_clientinfo->error_flag = 1;
}
