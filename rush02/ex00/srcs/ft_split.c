/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riblanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:14:23 by riblanc           #+#    #+#             */
/*   Updated: 2019/07/16 01:36:54 by riblanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_in_charset(char c, char *charset)
{
	int		i;

	i = -1;
	while (*(charset + ++i))
		if (c == *(charset + i))
			return (1);
	return (0);
}

int		count_words(char *str, char *charset)
{
	int		c;

	c = 0;
	while (*str)
	{
		while (*str && is_in_charset(*str, charset))
			str++;
		while (*str && !is_in_charset(*str, charset))
		{
			c++;
			while (*str && !is_in_charset(*str, charset))
				str++;
		}
	}
	return (c);
}

char	*ft_strdup(char *src, char *charset)
{
	int		i;
	char	*tmp;

	i = 0;
	while (*(src + i) && !is_in_charset(*(src + i), charset))
		i++;
	if (!(tmp = malloc(sizeof(*tmp) * (i + 1))))
		return (NULL);
	i = 0;
	while (*(src + i) && !is_in_charset(*(src + i), charset))
	{
		*(tmp + i) = *(src + i);
		i++;
	}
	*(tmp + i) = '\0';
	return (tmp);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		size;
	int		i;

	if (!str || !charset)
		return (NULL);
	size = count_words(str, charset);
	if (!(strs = malloc(sizeof(*strs) * (size + 1))))
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && is_in_charset(*str, charset))
			str++;
		while (*str && !is_in_charset(*str, charset))
		{
			strs[i] = ft_strdup(str, charset);
			i++;
			while (*str && !is_in_charset(*str, charset))
				str++;
		}
	}
	strs[size] = 0;
	return (strs);
}
