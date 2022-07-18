/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:50:07 by slyu              #+#    #+#             */
/*   Updated: 2022/07/16 17:50:08 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./ft_printf/includes/ft_printf.h"

void	set_signal(int sig, void *handler_func)
{
	static struct sigaction	act;

	act.sa_flags = 0;
	act.sa_flags |= SA_SIGINFO;
	sigemptyset(&(act.sa_mask));
	act.__sigaction_u.__sa_sigaction = handler_func;
	sigaction(sig, &act, 0);
}

int	send_signal(int sign, pid_t to, char *flag)
{
	int	i;

	i = 0;
	kill(to, sign);
	while (!(*flag))
	{
		i++;
		if (i > 1000000000)
			return (-1);
	}
	*flag = 0;
	return (0);
}

void	error_handler_c(char *msg)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(msg, 2);
	exit(-1);
}

void	error_handler_s(char *msg, char *flag)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putendl_fd(msg, 2);
	*flag = 1;
}
