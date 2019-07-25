/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelmahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:23:09 by lbelmahd          #+#    #+#             */
/*   Updated: 2019/07/06 18:36:09 by lbelmahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_line(int x)
{
	int		i;

	if (x != 0)
	{
		i = 0;
		ft_putchar('/');
		while (i < x - 2)
		{
			ft_putchar('*');
			i++;
		}
		if (x != 1)
			ft_putchar('\\');
		ft_putchar('\n');
	}
}

void	middle_lines(int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < y - 2)
	{
		j = 0;
		ft_putchar('*');
		if (x != 1)
		{
			while (j < x - 2)
			{
				ft_putchar(' ');
				j++;
			}
			ft_putchar('*');
		}
		ft_putchar('\n');
		i++;
	}
}

void	last_line(int x)
{
	int		i;

	if (x != 0)
	{
		i = 0;
		ft_putchar('\\');
		while (i < x - 2)
		{
			ft_putchar('*');
			i++;
		}
		if (x != 1)
			ft_putchar('/');
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	if (!(x <= 0 || y <= 0))
	{
		first_line(x);
		middle_lines(x, y);
		if (y != 1)
			last_line(x);
	}
}
