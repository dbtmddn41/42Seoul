/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:14:18 by slyu              #+#    #+#             */
/*   Updated: 2022/07/16 16:14:20 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "./ft_printf/includes/ft_printf.h"
# define BUFFER_SIZE 1000

typedef struct s_client
{
	char			buf[BUFFER_SIZE];
	pid_t			client_pid;
	unsigned int	buf_idx;
	char			error_flag;
	char			recieve_flag;
}t_client;

void	waiting_handler(int sign, siginfo_t *info, void *context);
void	recieve_handler(int sign, siginfo_t *info, void *context);
void	recieve_msg(void);
void	error_handler_s(char *msg, char *flag);
void	set_signal(int sig, void *handler_func);
int		send_signal(int sign, pid_t to, char *flag);
int		recieving_proc(pid_t cid, char *buf);
#endif