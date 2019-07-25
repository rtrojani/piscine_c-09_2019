/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:39:35 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/25 10:26:44 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		is_ascending;

	i = 1;
	if (length <= 2)
		return (1);
	is_ascending = (*f)(tab[i - 1], tab[i]) < 0 ? 1 : 0;
	while (i < length)
	{
		if (is_ascending && (*f)(tab[i - 1], tab[i]) > 0)
			return (0);
		if (!is_ascending && (*f)(tab[i - 1], tab[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}
