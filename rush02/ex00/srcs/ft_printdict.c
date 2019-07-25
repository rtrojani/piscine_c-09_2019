/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riblanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:18:30 by riblanc           #+#    #+#             */
/*   Updated: 2019/07/21 21:26:55 by riblanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char		g_sn[20][100] = { "", "one ", "two ", "three ", "four ", "five ",
	"six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ",
	"thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ",
	"ninteen " };
char		g_tens[10][100] = { "", "", "twenty ", "thirty ", "fourty ",
	"fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
char		g_scall_n[4][100] = { "", "thousand", "million", "billion" };

void		ft_nbrw(long long int n, char *s)
{
	if (n > 19)
	{
		ft_putstr(g_tens[n / 10]);
		ft_putstr(g_sn[n % 10]);
	}
	else
		ft_putstr(g_sn[n]);
	if (n)
		ft_putstr(s);
}

void		ft_itow(long long int n)
{
	ft_nbrw((n / 1000000000) % 100, "billion");
	ft_nbrw((n / 100000000) % 10, "hundred ");
	ft_nbrw((n / 1000000) % 100, "million ");
	ft_nbrw((n / 100000) % 10, "hundred ");
	ft_nbrw((n / 1000) % 100, "thousand ");
	ft_nbrw((n / 100) % 10, "hundred ");
	if (n > 100 && n % 100)
		ft_putstr("and ");
	ft_nbrw((n % 100), "");
}
