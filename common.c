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

void	set_signal(int sig, void *handler_func)
{
	static struct sigaction	act;

	act.sa_flags = 0;
	act.sa_flags |= SA_SIGINFO;
	sigemptyset(&(act.sa_mask));
	act.__sigaction_u.__sa_sigaction = handler_func;
	sigaction(sig, &act, 0);
}
