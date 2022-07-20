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

t_client	*g_clninfo;

int	main(void)
{
	pid_t				my_pid;

	g_clninfo = malloc(sizeof(t_client));
	if (!g_clninfo)
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
		write(1, "\n", 1);
	}
	free(g_clninfo);
}

void	waiting_handler(int sign, siginfo_t *info, void *context)
{
	if (sign != SIGUSR1)
	{
		pause();
		return ;
	}
	(void) context;
	g_clninfo->client_pid = info->si_pid;
	g_clninfo->error_flag = 0;
	ft_printf("conneted to PID: %d\n", g_clninfo->client_pid);
	set_signal(SIGUSR1, recieve_handler);
	set_signal(SIGUSR2, recieve_handler);
}

void	recieve_handler(int sign, siginfo_t *info, void *context)
{
	if (info->si_pid != g_clninfo->client_pid && info->si_pid != 0)
	{
		error_handler_s("other client interruped", &(g_clninfo->error_flag));
		return ;
	}
	(void) info;
	(void) context;
	g_clninfo->recieve_flag = 1;
	g_clninfo->buf[g_clninfo->buf_idx] <<= 1;
	if (sign == SIGUSR1)
		g_clninfo->buf[g_clninfo->buf_idx] &= 0xfe;
	else if (sign == SIGUSR2)
		g_clninfo->buf[g_clninfo->buf_idx] |= 0x1;
}

void	recieve_msg(void)
{
	int		i;
	char	*buf;
	int		res;
	pid_t	cid;

	cid = g_clninfo->client_pid;
	buf = g_clninfo->buf;
	i = 0;
	while (1)
	{
		g_clninfo->buf_idx = 0;
		res = recieving_proc(cid, buf);
		if (res == -1)
			return ;
		write(1, buf, g_clninfo->buf_idx);
		if (buf[g_clninfo->buf_idx] == '\0' && g_clninfo->buf_idx < BUFFER_SIZE)
			break ;
	}
}

int	recieving_proc(pid_t cid, char *buf)
{
	int	res;
	int	i;

	i = 0;
	while (g_clninfo->buf_idx < BUFFER_SIZE)
	{
		res = send_signal(SIGUSR1, cid, &(g_clninfo->recieve_flag));
		if (res == -1)
			error_handler_s("no signal from client", &(g_clninfo->error_flag));
		if (g_clninfo->error_flag)
			return (-1);
		i++;
		if (i >= 8)
		{
			if (buf[g_clninfo->buf_idx] == '\0')
				return (0);
			g_clninfo->buf_idx++;
			i = 0;
		}
	}
	return (0);
}
