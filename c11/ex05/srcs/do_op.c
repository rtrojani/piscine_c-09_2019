/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:35:29 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/25 01:56:15 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	define_tab(t_operations tab_ops[5])
{
	tab_ops[0].operator = '+';
	tab_ops[0].op = &ft_add;
	tab_ops[1].operator = '-';
	tab_ops[1].op = &ft_sub;
	tab_ops[2].operator = '*';
	tab_ops[2].op = &ft_mul;
	tab_ops[3].operator = '/';
	tab_ops[3].op = &ft_div;
	tab_ops[4].operator = '%';
	tab_ops[4].op = &ft_mod;
}

int		check_impossible_ops(char *operator, int nb)
{
	if (operator[1])
	{
		ft_putnbr(0);
		return (0);
	}
	if (operator[0] == '/' && nb == 0)
	{
		ft_putstr("Stop : division by zero");
		return (0);
	}
	if (operator[0] == '%' && nb == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return (0);
	}
	return (1);
}

void	do_op(char *nb1, char *operator, char *nb2)
{
	t_operations	tab_ops[5];
	int				i;
	int				(*op)(int, int);

	i = 0;
	if (!check_impossible_ops(operator, ft_atoi(nb2)))
		return ;
	define_tab(tab_ops);
	while (i < 5)
	{
		if (operator[0] == tab_ops[i].operator)
		{
			op = tab_ops[i].op;
			ft_putnbr((*op)(ft_atoi(nb1), ft_atoi(nb2)));
			return ;
		}
		else
			i++;
	}
	ft_putnbr(0);
}
