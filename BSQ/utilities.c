/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:46:18 by grusso            #+#    #+#             */
/*   Updated: 2020/11/12 11:46:20 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putchar_err(char a)
{
	write(2, &a, 1);
}

void	ft_error(char *err)
{
	int i;

	i = 0;
	while (err[i])
	{
		ft_putchar_err(err[i]);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		ft_atoi(char *str)
{
	int num;
	int n;

	num = 0;
	n = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num * n);
}
