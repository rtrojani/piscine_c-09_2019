/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:17:20 by gaefourn          #+#    #+#             */
/*   Updated: 2019/07/21 20:48:17 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_atoi(char *str)
{
	int				i;
	int				j;
	long long int	nb;
	int				neg;

	neg = 0;
	nb = 0;
	i = 0;
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ')
		return (-1);
	if (str[i] == '+' || str[i] == '-')
		return (-1);
	j = i - 1;
	while (str[++j])
		if (!(str[j] >= '0' && str[j] <= '9'))
			return (-1);
	i--;
	while (str[++i] >= '0' && str[i] <= '9')
		nb = ((nb * 10) + str[i] - '0');
	return (nb);
}
