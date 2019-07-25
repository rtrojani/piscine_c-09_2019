/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:22:39 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/03 15:23:01 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_tab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	if (tab[0] != (10 - size))
		write(1, ", ", 2);
}

void	init_tab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		tab[i] = i;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int		tab[n];
	int		i;

	i = 0;
	init_tab(tab, n);
	while (tab[0] < (10 - n))
	{
		i = 1;
		print_tab(tab, n);
		tab[n - i]++;
		while (tab[n - i] == (10 - i + 1))
		{
			tab[n - i - 1]++;
			i++;
		}
		while (i > 1)
		{
			tab[n - i + 1] = tab[n - i] + 1;
			i--;
		}
	}
	print_tab(tab, n);
}
