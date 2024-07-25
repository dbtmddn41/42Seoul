/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 02:32:23 by slyu              #+#    #+#             */
/*   Updated: 2021/09/12 13:21:33 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	char	alpha;
	int		i;

	alpha = 'a';
	i = 0;
	while (i < 26)
	{
		write(1, &alpha, 1);
		i++;
		alpha++;
	}
}
