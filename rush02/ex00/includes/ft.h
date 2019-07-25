/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 12:06:21 by gaefourn          #+#    #+#             */
/*   Updated: 2019/07/21 21:00:32 by riblanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

void			ft_putstr(char *str);
long long int	ft_atoi(char *str);
int				ft_open(char *str);
char			**ft_split(char *str, char *charset);
char			*ft_strdup(char *src, char *charset);
int				count_words(char *str, char *charset);
int				is_in_charset(char c, char *charset);
int				ft_strcmp(char *s1, char *s2);
void			ft_sort_string_tab(char **tab);
int				ft_error(int ac, char **av);
char			*extract_dict(void);
int				my_big_buffer(void);
char			**dict_parsed(char *str);
void			ft_short_spaces(char *str);
char			*ft_strjoin(int size, char **strs, char *sep);
int				ft_strlen(char *str);
void			ft_swap(char **a, char **b);
void			sort_words(char **tab);
char			**finished_dict(char **str);
void			ft_itow(long long int n);

typedef struct	s_dict
{
	long long int		val;
	char				*word;
}				t_dict;

#endif
