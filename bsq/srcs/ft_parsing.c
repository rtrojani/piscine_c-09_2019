/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:11:24 by lucocozz          #+#    #+#             */
/*   Updated: 2019/07/24 23:21:00 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	ft_send_list(t_list **list, t_param param, char *buff)
{
	int i;
	int *tab;

	i = 0;
	if ((tab = malloc(sizeof(int) * param.len)) == NULL)
		return (-2);
	while (i < param.len)
	{
		if (buff[i] != param.obst && buff[i] != param.empt)
			return (-1);
		tab[i] = (buff[i] == param.obst ? 0 : 1);
		i++;
	}
	if (buff[i] != '\n')
		return (-1);
	ft_list_push_front(list, (void *)tab);
	return (0);
}

int			ft_parsing(t_list **list, t_param param, int fd)
{
	int			rd;
	int			ret;
	char		*buff;
	static int	total;

	if ((buff = malloc(sizeof(char) * param.len + 1)) == NULL)
		return (-2);
	if ((rd = read(fd, buff, param.len + 1)) > 0)
	{
		total += rd;
		if ((ret = ft_send_list(list, param, buff)) < 0)
			return (ret);
	}
	free(buff);
	return (rd ? 0 : total);
}
