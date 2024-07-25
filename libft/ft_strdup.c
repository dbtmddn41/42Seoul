/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:49:04 by slyu              #+#    #+#             */
/*   Updated: 2022/01/05 20:49:06 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		str_len;
	char	*str;

	str_len = 0;
	while (*(s1 + str_len) != '\0')
		str_len++;
	str = (char *)malloc(str_len + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1, str_len + 1);
	return (str);
}
