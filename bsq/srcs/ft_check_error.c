/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:05:12 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/24 22:48:21 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	check_params(char *buff, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size - 3)
	{
		if (!(buff[i] >= '0' && buff[i] <= '9'))
			return (-1);
		i++;
	}
	while (buff[i])
	{
		j = i + 1;
		while (buff[j])
		{
			if (buff[i] == buff[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void		fill_params(char first_line[10], t_param *params, int size)
{
	params->full = first_line[size - 1];
	params->obst = first_line[size - 2];
	params->empt = first_line[size - 3];
	params->size = 0;
}

void		get_params(int fd, t_param *params)
{
	int			i;
	char		c;
	int			size;
	char		first_line[10];

	i = 0;
	c = 0;
	size = -1;
	while (c != '\n' && size < 10)
	{
		size++;
		read(fd, &c, 1);
		if (c != '\n')
			first_line[size] = c;
	}
	if (check_params(first_line, size) == -1)
		params->size = -1;
	else
	{
		fill_params(first_line, params, size);
		while (i < size - 3)
			params->size = params->size * 10 + first_line[i++] - '0';
	}
}

int			check_error(t_param *param, char *map_path)
{
	int			fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	get_params(fd, param);
	close(fd);
	return (0);
}
