/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:52:47 by slyu              #+#    #+#             */
/*   Updated: 2022/01/06 18:52:48 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	**ft_split(char const *s, char c);

static int	count_word(char const *s, char c)
{
	int		count;
	int		i;
	char	check;

	i = 0;
	count = 0;
	while (*(s + i) != '\0')
	{
		check = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			check = 1;
		}
		if (check)
			count++;
	}
	return (count);
}

static int	search_word_index(char const *s, char c, int turn)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (count == turn)
			return (i);
		while (s[i] != c)
		{
			if (s[i] == '\0')
				return (-1);
			i++;
		}
		while (s[i] == c)
			i++;
		count++;
	}
	return (-1);
}

static int	count_letter(char const *s, char c, int turn)
{
	int	i;
	int	len;

	i = search_word_index(s, c, turn);
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static void	wordcpy(char *word, char const *s, char c, int turn)
{
	int	i;

	i = search_word_index(s, c, turn);
	while (s[i] != c && s[i] != '\0')
	{
		*word = s[i];
		word++;
		i++;
	}
	*word = '\0';
}

char	**ft_split(char const *s, char c)
{
	int		num;
	char	**sen;
	int		i;

	if (!s)
		return (0);
	num = count_word(s, c);
	sen = (char **) malloc(sizeof(char *) * (num + 1));
	if (!sen)
		return (0);
	i = -1;
	while (++i < num)
	{
		sen[i] = (char *) malloc(sizeof(char) * (count_letter(s, c, i) + 1));
		if (!sen[i])
		{
			while (--i >= 0)
				free(sen[i]);
			free(sen);
			return (0);
		}
		wordcpy(sen[i], s, c, i);
	}
	sen[i] = 0;
	return (sen);
}
