/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 15:08:33 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/21 21:10:14 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft.h"
#define BUFF_SIZE 4096

int		my_big_buffer(void)
{
	int		fd;
	int		ret;
	int		count;
	char	buf[BUFF_SIZE + 1];

	count = 0;
	fd = open("./srcs/numbers.dict", O_RDONLY);
	if (fd != -1)
	{
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
			count += ret;
		close(fd);
		return (count);
	}
	return (-1);
}

char	*extract_dict(void)
{
	int		fd;
	char	*dico;
	int		size;

	size = my_big_buffer();
	if (!(dico = (char*)malloc(sizeof(*dico) * (size + 1))))
		return (NULL);
	fd = open("./srcs/numbers.dict", O_RDONLY);
	if (fd != -1)
	{
		read(fd, dico, size);
		dico[size] = 0;
		close(fd);
	}
	return (dico);
}
