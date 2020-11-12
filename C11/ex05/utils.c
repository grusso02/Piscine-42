/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:28:07 by grusso            #+#    #+#             */
/*   Updated: 2020/11/12 15:55:54 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	rec(int nb)
{
	char ch;

	if (nb == 0)
		return ;
	rec(nb / 10);
	ch = '0' + nb % 10;
	write(1, &ch, 1);
}

void	ft_putnbr(int nb)
{
	char ch;

	if (nb < 0)
	{
		write(1, "-", 1);
		rec(-(nb / 10));
		ch = '0' - nb % 10;
	}
	else
	{
		rec(nb / 10);
		ch = '0' + nb % 10;
	}
	write(1, &ch, 1);
	write(1, "\n", 1);
}

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int ret;

	ret = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret *= 10;
		ret += sign * (str[i] - '0');
		i++;
	}
	return (ret);
}
