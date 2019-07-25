/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:07:11 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/10 10:55:21 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

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

void	bubble_sort(int ac, char **av)
{
	int		i;
	int		is_sorted;

	is_sorted = 0;
	while (!is_sorted)
	{
		i = 1;
		is_sorted = 1;
		while (i < ac)
		{
			if (ft_strcmp(av[i - 1], av[i]) > 0)
			{
				ft_swap(&av[i - 1], &av[i]);
				is_sorted = 0;
			}
			i++;
		}
		ac--;
	}
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	bubble_sort(argc - 1, &argv[1]);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
