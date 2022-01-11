/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:36:57 by slyu              #+#    #+#             */
/*   Updated: 2022/01/07 14:37:00 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	s_len;
	char			*mapped;
	char			temp;

	if (!s || !f)
		return (0);
	i = 0;
	s_len = ft_strlen(s);
	mapped = (char *) malloc(s_len + 1);
	if (!mapped)
		return (0);
	while (i < s_len)
	{
		temp = f(i, s[i]);
		mapped[i] = temp;
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}
