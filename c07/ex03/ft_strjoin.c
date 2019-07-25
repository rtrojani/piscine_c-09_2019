/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:48:13 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/22 11:42:10 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int		get_len_str_join(int size, char **strs, char *sep)
{
	int		i;
	int		len_strs;

	if (size <= 0)
		return (0);
	i = 0;
	len_strs = 0;
	while (i < size)
		len_strs += ft_strlen(strs[i++]);
	return (len_strs + (size - 1) * ft_strlen(sep));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str_join;

	i = 0;
	str_join = NULL;
	if (!(str_join = (char*)malloc(sizeof(*str_join) *
		(get_len_str_join(size, strs, sep) + 1))))
		return (NULL);
	while (i < get_len_str_join(size, strs, sep))
		str_join[i++] = 0;
	str_join[get_len_str_join(size, strs, sep)] = '\0';
	if (!size)
		return (str_join);
	i = 0;
	while (i < size)
	{
		ft_strcat(str_join, strs[i]);
		if (i < size - 1)
			ft_strcat(str_join, sep);
		i++;
	}
	return (str_join);
}
