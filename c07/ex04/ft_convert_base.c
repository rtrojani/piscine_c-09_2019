/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:59:40 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/25 14:15:47 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_atoi_base(char *str, char *base);
int				check_error(char *str, char *base);
unsigned int	ft_strlen(char *str);

int				get_len_out(char *base_to, int nb_init)
{
	unsigned int	nb;
	int				len_out;

	len_out = 1;
	if (nb_init < 0)
	{
		len_out++;
		nb = -nb_init;
	}
	else
		nb = nb_init;
	while (nb >= ft_strlen(base_to) && ft_strlen(base_to))
	{
		nb /= ft_strlen(base_to);
		len_out++;
	}
	return (len_out);
}

int				check_error_base_to(char *base)
{
	int		i;
	int		j;

	if (!base || !*base)
		return (0);
	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' '
			|| base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	nb;
	int				nb_init;
	int				len_out;
	char			*str_out;

	nb_init = ft_atoi_base(nbr, base_from);
	len_out = get_len_out(base_to, nb_init);
	if (!check_error_base_to(base_to) || !(check_error(nbr, base_from)))
		return (NULL);
	if (!(str_out = (char*)malloc(sizeof(*str_out) * (len_out + 1))))
		return (NULL);
	str_out[len_out] = '\0';
	if (nb_init < 0)
		str_out[0] = '-';
	if (!nb_init)
		str_out[0] = base_to[0];
	nb = nb_init < 0 ? -nb_init : nb_init;
	while (nb && ft_strlen(base_to))
	{
		len_out--;
		str_out[len_out] = base_to[nb % ft_strlen(base_to)];
		nb /= ft_strlen(base_to);
	}
	return (str_out);
}
