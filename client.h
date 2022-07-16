/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:55:55 by slyu              #+#    #+#             */
/*   Updated: 2022/07/16 16:13:43 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include "./ft_printf/includes/ft_printf.h"
# define WAIT_TIME 1000

typedef struct s_server
{
	pid_t				server_pid;
	char				acknowledge;
}t_server;

void	sig_handler(int sign, siginfo_t *info, void *context);
void	knock(pid_t server_pid);
void	send_msg(char *msg);
void	error_handler(char *msg);
void	set_signal(int sig, void *handler_func);
#endif
