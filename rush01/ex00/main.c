/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:05:36 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/14 20:48:25 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init_grid(char *str, int n, int grid[8][8]);
int		backtrack(int pos, int n, int grid[8][8]);

int		main(int argc, char **argv)
{
	int		grid[8][8];
	int		n;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	n = 6;
	init_grid(argv[1], n, grid);
	if (!backtrack(1, n, grid))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}
