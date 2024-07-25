/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:45:03 by slyu              #+#    #+#             */
/*   Updated: 2022/01/06 15:45:06 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set);

static void	set_init(char *chr, char const *set)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		chr[i] = 0;
		i++;
	}
	i = 0;
	while (*(set + i) != '\0')
	{
		chr[(int)set[i]] = 1;
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	chr[256];
	char	*str;
	int		start;
	int		size;

	if (!s1 || !set)
		return (0);
	set_init(chr, set);
	start = 0;
	while (chr[(unsigned int)*(s1 + start)])
		start++;
	size = 0;
	while (s1[start + size] != '\0')
		size++;
	while (chr[(unsigned int)*(s1 + start + size - 1)] && size > 0)
		size--;
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + start, size + 1);
	return (str);
}
