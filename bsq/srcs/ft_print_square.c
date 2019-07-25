/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:01:16 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/24 23:41:41 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int		before_square(int fd, t_matrice data, t_param params)
{
	char	c;
	char	*buff;
	int		y;

	y = 0;
	c = 0;
	if (!(buff = (char*)malloc(sizeof(*buff) * (params.len))))
		return (-1);
	while (c != '\n')
		read(fd, &c, 1);
	while (y < data.y - data.max)
	{
		read(fd, buff, params.len);
		write(1, buff, params.len);
		y++;
	}
	free(buff);
	return (y);
}

int		print_square(int fd, t_matrice data, t_param param, int y)
{
	int		i;
	char	*buff;

	i = 0;
	printf("min=%d\n", (data.y - data.max));
	printf("max=%d\n", param.len - data.y);
	if (!(buff = (char*)malloc(sizeof(*buff) * (param.len + 1))))
		return (-1);
	while (y < data.y)
	{
		read(fd, buff, param.len);
		while (buff[i])
		{
			if (i >= (data.y - data.max) && i <= data.y)
				ft_putchar(param.full);
			else
				ft_putchar(buff[i]);
			i++;
		}
		y++;
	}
	free(buff);
	return (y);
}

int		after_square(int fd, t_param params, int y)
{
	char	*buff;

	if (!(buff = (char*)malloc(sizeof(*buff) * (params.len + 1))))
		return (-1);
	while (y < params.size)
	{
		read(fd, buff, params.len);
		write(1, buff, params.len);
		y++;
	}
	free(buff);
	return (y);
}

int 	ft_print_map(char *map_path, t_param params, t_matrice data)
{
	int	fd;
	int	y;

	y = 0;
	printf("y=%d\n", data.y);
	printf("len=%d\n", params.len);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	y = y + before_square(fd, data, params);
	y = y + print_square(fd, data, params, y);
	printf("y=%d\n", y);
	after_square(fd, params, y);
	return (0);
}
