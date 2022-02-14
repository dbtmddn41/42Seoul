/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:31:03 by slyu              #+#    #+#             */
/*   Updated: 2022/02/01 15:31:07 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fstr, ...)
{
	va_list		ap;
	t_partial	*part;
	int			printed;

	if (fstr[0] == '\0')
		return (0);
	part = malloc(sizeof(t_partial));
	if (!part)
		return (-1);
	if (cut_str(fstr, &part) == -1)
	{
		ft_lst_clear(&part);
		return (-1);
	}
	va_start(ap, fstr);
	printed = write_fstr(ap, part);
	ft_lst_clear(&part);
	va_end(ap);
	return (printed);
}

int	cut_str(const char *fstr, t_partial **part)
{
	int			i;
	t_partial	*curr;

	curr = *part;
	i = 0;
	while (fstr[i] != '\0')
	{
		ft_memset(curr, 0, sizeof(t_partial));
		i += split_str(curr, fstr + i);
		if (i == -1)
			return (-1);
		if (fstr[i] == '\0')
			break ;
		curr->next = malloc(sizeof(t_partial));
		if (!(curr->next))
			return (-1);
		curr = curr->next;
	}
	curr->next = NULL;
	return (1);
}

int	split_str(t_partial *part, const char *fstr)
{
	int	i;

	part->isformat = fstr[0] == '%';
	if (part->isformat)
		i = format_fstr(part, fstr + 1);
	else
		i = ft_strnchr(fstr, '%');
	part->str = malloc(i + 1);
	if (!part->str)
		return (-1);
	if (part->isformat == 0)
		ft_strlcpy(part->str, fstr, i + 1);
	return (i);
}

int	format_fstr(t_partial *part, const char *fstr)
{
	int	i;

	i = 0;
	part->width[1] = -1;
	while (1)
	{
		if (!check_flag(&i, part, fstr))
			break ;
		i++;
	}
	if (istype(fstr[i]))
	{
		part->type = fstr[i];
		if (part->width[1] != -1 || part->flag[minus])
			part->flag[zero] = 0;
	}
	else
		part->isformat = 0;
	return (i + 2);
}
