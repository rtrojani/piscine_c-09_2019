/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:14:17 by gaefourn          #+#    #+#             */
/*   Updated: 2019/07/21 19:11:09 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_error(int ac, char **av)
{
	if (ac > 3)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ac == 2 && (int)ft_atoi(av[1]) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ac == 3 && (int)ft_atoi(av[2]) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
