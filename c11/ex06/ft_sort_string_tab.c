/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:00:17 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/22 20:15:09 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char *tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		size;
	int		is_sorted;

	size = 0;
	while (tab[size])
		size++;
	is_sorted = 0;
	while (!is_sorted)
	{
		i = 1;
		is_sorted = 1;
		while (i < size)
		{
			if (ft_strcmp(tab[i - 1], tab[i]) > 0)
			{
				ft_swap(&tab[i - 1], &tab[i]);
				is_sorted = 0;
			}
			i++;
		}
		size--;
	}
}
