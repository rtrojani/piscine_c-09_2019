/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:23:35 by lucocozz          #+#    #+#             */
/*   Updated: 2019/07/24 22:58:18 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	ft_intcpy(int *t1, int *t2, int len_line)
{
	int i;

	i = 0;
	while (i < len_line)
	{
		t1[i] = t2[i];
		i++;
	}
	return (t1[i] - t2[i]);
}

static int	**ft_up_matrice(int **tab, int i)
{
	int min;

	min = tab[1][i - 1];
	min = (tab[0][i - 1] < min ? tab[0][i - 1] : min + 0);
	min = (tab[0][i] < min ? tab[0][i] : min + 0);
	tab[1][i] = min + 1;
	return (tab);
}

static int	**ft_set_matrice(t_list **begin_list, int **tab, int len_line)
{
	t_list *tmp;

	tmp = *begin_list;
	ft_intcpy(tab[0], tab[1], len_line);
	ft_intcpy(&tab[1][1], (int *)tmp->data, len_line);
	*begin_list = tmp->next;
	free(tmp->data);
	free(tmp);
	return (tab);
}

int			**ft_resolve_matrice(t_matrice *data, t_list **begin_list,
	int **tab, int len_line)
{
	int			i;
	static int	y;

	i = 1;
	tab = ft_set_matrice(begin_list, tab, len_line);
//	ft_print_tab(&tab[0][0], len_line);
	while (i < len_line)
	{
		if (tab[1][i] != 0)
		{
			tab = ft_up_matrice(tab, i);
			if (tab[1][i] > data->max)
			{
				data->y = y;
				data->x = i - 1;
				data->max = tab[1][i];
			}
		}
		i++;
	}
	y++;
	return (tab);
}
