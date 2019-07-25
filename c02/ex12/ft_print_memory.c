/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:05:02 by rotrojan          #+#    #+#             */
/*   Updated: 2019/07/06 20:31:42 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putstr_not_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] && i < 16)
	{
		if (str[i] >= 32 && str[i] < 127)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	putnbr_hexa(unsigned long int nb)
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

void	putstr_hexa(char *str, unsigned int i, unsigned int size)
{
	unsigned int	j;

	j = 0;
	while (j < 16)
	{
		if (i + j < size)
		{
			if (str[j] < 16)
				ft_putchar('0');
			putnbr_hexa(str[j]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (j % 2)
			ft_putchar(' ');
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long int	addr_int;
	char				*addr_str;
	unsigned int		i;

	addr_str = (char*)addr;
	i = 0;
	while (i < size)
	{
		write(1, "000", 3);
		addr_int = (unsigned long int)addr;
		putnbr_hexa(addr_int);
		ft_putchar(':');
		ft_putchar(' ');
		putstr_hexa(&addr_str[i], i, size);
		putstr_not_printable(&addr_str[i]);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
