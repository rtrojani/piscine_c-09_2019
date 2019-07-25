/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 01:42:37 by lucocozz          #+#    #+#             */
/*   Updated: 2019/07/21 08:56:01 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(char *str);
char	*ft_calloc(int size);
void	ft_fd_putstr(char *str, int fd);
int		ft_isdigit(char *str);
int		ft_isspace(char c);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
char	**ft_split(char *str, char *charset);
int		ft_str_is_numeric(char *str);
char	*ft_strcat(char *dest, char *src);
int		ft_strchr(char c, char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);
void	ft_swap(int *a, int *b);

#endif
