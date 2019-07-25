/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:40:42 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/22 01:50:49 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int		i;
	int		nb_words;

	if (!*str)
		return (0);
	nb_words = 0;
	if (!is_separator(str[0], charset))
		nb_words++;
	i = 1;
	while (str[i])
	{
		if (!is_separator(str[i], charset) && is_separator(str[i - 1], charset))
			nb_words++;
		i++;
	}
	return (nb_words);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*duplicate;

	if (!(duplicate = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		duplicate[i] = str[i];
		i++;
	}
	duplicate[i] = 0;
	return (duplicate);
}

char	**ft_split(char *str, char *charset)
{
	char	**words;
	int		i;
	int		j;
	int		k;
	int		nb_words;

	i = 0;
	k = 0;
	nb_words = count_words(str, charset);
	if (!(words = (char**)malloc(sizeof(*words) * (nb_words + 1))))
		return (NULL);
	words[nb_words] = 0;
	while (str[k] && i < nb_words)
	{
		j = 0;
		while (str[k] && is_separator(str[k], charset))
			k++;
		while (str[k + j] && !is_separator(str[k + j], charset))
			j++;
		words[i] = ft_strndup(&str[k], j);
		k += j;
		i++;
	}
	return (words);
}
