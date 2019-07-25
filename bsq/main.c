/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 01:32:44 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/24 23:07:59 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			get_len_line(char *map_path)
{
	int		fd;
	char	buff;
	int		ret;

	ret = 0;
	buff = 0;
	fd = open(map_path, O_RDONLY);
	if (fd != -1)
	{
		while (buff != '\n')
			read(fd, &buff, 1);
		buff = 0;
		while (buff != '\n')
			ret += read(fd, &buff, 1);
		close(fd);
	}
	return (fd == -1 ? -1 : ret - 1);
}

int	**ft_init_tab(int len)
{
	int i;
	int j;
	int **tab;

	i = 0;
	if ((tab = malloc(sizeof(int *) * 2)) == NULL)
		return (NULL);
	while (i < 2)
	{
		j = 0;
		if ((tab[i] = malloc(sizeof(int) * (len + 1))) == NULL)
			return (NULL);
		while (j < len)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

static int	ft_core(char *filename, t_param param, int fd)
{
	int			total;
	int			**tab;
	t_list		*list;
	t_matrice	data;

	total = 0;
	data.max = 0;
	if ((tab = ft_init_tab(param.len)) == NULL)
		return (-2);
	while (!total)
	{
		if ((total = ft_parsing(&list, param, fd)) < 0)
		{
			ft_putstr("map error\n");
			exit(0);
		}
		if (!total)
			tab = ft_resolve_matrice(&data, &list, tab, param.len);
	}
	close(fd);
	ft_print_map(filename, param, data);
	return (0);
}

static int	ft_bsq(char *filename)
{
	int fd;
	char c;
	int check;
	t_param param;

	c = 0;
	check = check_error(&param, filename);
	param.len = get_len_line(filename);
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	while (c != '\n')
		read(fd, &c, 1);
	if (check == 0)
		ft_core(filename, param, fd);
	else if (check == -1)
		ft_putstr("map error\n");
	return (0);
}

int			main(int argc,char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		ft_std_input();
	while (i < argc)
	{
		ft_bsq(argv[i]);
		i++;
	}
}
