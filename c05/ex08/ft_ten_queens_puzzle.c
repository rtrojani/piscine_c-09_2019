/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:36:44 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/09 23:12:31 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_tab(int tab[10])
{
	int		i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	write(1, "\n", 1);
}

int		check_position(int tab[10], int col, int row)
{
	int		i;

	i = 0;
	while (i < col)
	{
		if (tab[i] == row)
			return (0);
		if (tab[i] + i == row + col)
			return (0);
		if (tab[i] - i == row - col)
			return (0);
		i++;
	}
	return (1);
}

void	backtrack(int tab[10], int col, int *res)
{
	int		row;

	if (col == 10)
	{
		print_tab(tab);
		*res += 1;
	}
	else
	{
		row = 0;
		while (row < 10)
		{
			if (check_position(tab, col, row))
			{
				tab[col] = row;
				backtrack(tab, col + 1, res);
			}
			row++;
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		tab[10];
	int		res;

	res = 0;
	backtrack(tab, 0, &res);
	return (res);
}
