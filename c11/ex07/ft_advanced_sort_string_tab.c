/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:19:23 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/25 13:20:34 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char *tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char*, char *))
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
			if ((*cmp)(tab[i - 1], tab[i]) > 0)
			{
				ft_swap(&tab[i - 1], &tab[i]);
				is_sorted = 0;
			}
			i++;
		}
		size--;
	}
}
