/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 03:35:13 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/22 05:10:46 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		i;
	int		*tab_out;

	i = 0;
	if (!(tab_out = (int*)malloc(sizeof(*tab) * length)))
		return (NULL);
	while (i < length)
	{
		tab_out[i] = (*f)(tab[i]);
		i++;
	}
	return (tab_out);
}
