/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:12:41 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/08 14:07:29 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_str(char *str, char *base)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_error(char *str, char *base)
{
	int		i;
	int		j;

	if (ft_strlen(base) < 2)
		return (0);
	if (!check_str(str, base))
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
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '
			|| base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int		base_index(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		is_negative;
	int		result;

	i = 0;
	result = 0;
	is_negative = 0;
	if (!check_error(str, base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative++;
		i++;
	}
	is_negative %= 2;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * ft_strlen(base) + base_index(str[i++], base);
	if (is_negative)
		return (-result);
	else
		return (result);
}
