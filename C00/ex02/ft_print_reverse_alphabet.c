/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse__alphabet.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 02:32:23 by slyu              #+#    #+#             */
/*   Updated: 2021/09/12 20:50:09 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void);

void	ft_print_reverse_alphabet(void)
{
	char	alpha;
	int		i;

	alpha = 'z';
	i = 0;
	while (i < 26)
	{
		write(1, &alpha, 1);
		i++;
		alpha--;
	}
}
