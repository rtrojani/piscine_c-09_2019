/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 22:50:35 by lucocozz          #+#    #+#             */
/*   Updated: 2019/07/24 22:31:09 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_std_input(void)
{
	int		fd;
	int		rd;
	char	buff[100000];

	if ((fd = open(".input.map", O_WRONLY | O_CREAT, 0644)) == -1)
		return (-1);
	while ((rd = read(STDIN_FILENO, buff, 100000)))
		write(fd, buff, rd);
	close(fd);
	return (0);
}
