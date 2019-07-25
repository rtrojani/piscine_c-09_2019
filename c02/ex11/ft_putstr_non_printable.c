/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:22:18 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/05 16:50:20 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr_hexa(int nb)
{
	char	*base_hexa;

	base_hexa = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(base_hexa[nb]);
	else
	{
		putnbr_hexa(nb / 16);
		ft_putchar(base_hexa[nb % 16]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] < 127)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			if (str[i] < 16)
				ft_putchar('0');
			putnbr_hexa(str[i]);
		}
		i++;
	}
}
