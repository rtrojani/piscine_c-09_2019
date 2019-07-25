/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 22:46:28 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/09 00:23:07 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		i;
	int		result;

	if (nb < 0)
		return (0);
	i = 0;
	result = 1;
	while (i++ < nb)
		result = result * i;
	return (result);
}
