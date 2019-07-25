/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 02:33:23 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/14 20:44:43 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_grid(int pos, int n, int grid[8][8]);
void	print_grid(int n, int grid[8][8]);

int		backtrack(int pos, int n, int grid[8][8])
{
	int		row;
	int		col;
	int		val;

	col = pos % n ? pos % n : n;
	row = pos % n ? pos / n + 1 : pos / n;
	val = 0;
	if (pos == n * n + 1)
	{
		print_grid(n, grid);
		return (1);
	}
	else
	{
		val = 0;
		while (++val <= n)
		{
			grid[row][col] = val;
			if (check_grid(pos, n, grid))
				if (backtrack(pos + 1, n, grid))
					return (1);
		}
		grid[row][col] = 0;
		return (0);
	}
}
