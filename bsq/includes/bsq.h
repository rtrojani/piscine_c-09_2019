/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 01:11:18 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/24 23:23:38 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "ft_list.h"
# include "ft.h"

typedef struct	s_matrice
{
	int x;
	int y;
	int max;

}				t_matrice;

typedef struct	s_param
{
	int		len;
	int		size;
	char	obst;
	char	empt;
	char	full;
}				t_param;

int				**ft_resolve_matrice(t_matrice *data, t_list **begin_list,
int				**tab, int size);
int				check_error(t_param *param, char *map_path);
int				ft_parsing(t_list **list, t_param param, int fd);
int				ft_std_input(void);
int				get_len_line(char *map_path);
int 			ft_print_map(char *map_path, t_param params, t_matrice data);

#endif
