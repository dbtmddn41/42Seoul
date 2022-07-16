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
# define WAIT_TIME 1000000

typedef struct s_client
{
	char			buf[BUFFER_SIZE];
	pid_t			client_pid;
	unsigned int	buffer_index;
	int				error_flag;
}t_client;

void	waiting_handler(int sign, siginfo_t *info, void *context);
void	recieve_handler(int sign, siginfo_t *info, void *context);
void	recieve_msg(void);
void	error_handler(char *msg);
void	set_signal(int sig, void *handler_func);
#endif