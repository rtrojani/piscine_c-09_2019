/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:55:00 by gaefourn          #+#    #+#             */
/*   Updated: 2019/07/21 21:20:13 by riblanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_short_spaces(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i + j])
	{
		if (str[i + j] != ' ')
		{
			str[i] = str[i + j];
			i++;
		}
		else if (str[i - 1] != ' ')
		{
			str[i] = str[i + j];
			i++;
		}
		else
			j++;
	}
	str[i] = 0;
}

void	sort_words(char **tab)
{
	int		i;
	int		size;
	int		is_sorted;

	size = 0;
	while (tab[size])
		size++;
	is_sorted = 0;
	while (is_sorted)
	{
		i = 1;
		is_sorted = 1;
		while (i < size - 1)
		{
			if (ft_atoi(tab[i]) > ft_atoi(tab[i + 1]))
			{
				ft_swap(&tab[i], &tab[i + 1]);
				is_sorted = 0;
			}
			i++;
		}
		size--;
	}
}

char	**dict_parsed(char *str)
{
	char	**dico;
	int		i;
	int		j;

	j = 0;
	i = 0;
	ft_short_spaces(str);
	dico = ft_split(str, "\n");
	sort_words(dico);
	return (dico);
}
