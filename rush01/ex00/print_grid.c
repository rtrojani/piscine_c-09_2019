/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 02:35:22 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/14 20:43:45 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_grid(int n, int grid[8][8])
{
	int		i;
	int		j;

	j = 1;
	while (j <= n)
	{
		i = 1;
		while (i <= n)
		{
			ft_putchar(grid[j][i] + '0');
			if (i != n)
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
