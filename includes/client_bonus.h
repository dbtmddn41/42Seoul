/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:55:55 by slyu              #+#    #+#             */
/*   Updated: 2022/07/20 12:07:52 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <unistd.h>
# include <signal.h>
# include "../ft_printf/includes/ft_printf.h"

typedef struct s_server
{
	pid_t				server_pid;
	char				acknowledge;
}t_server;

void	sig_handler(int sign, siginfo_t *info, void *context);
void	knock(pid_t server_pid);
void	send_msg(char *msg);
void	error_handler_c(char *msg);
void	set_signal(int sig, void *handler_func);
int		send_signal(int sign, pid_t to, char *flag);
void	send_null(pid_t sid);
#endif
