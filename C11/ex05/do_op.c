/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:36:38 by grusso            #+#    #+#             */
/*   Updated: 2020/11/12 16:36:29 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include <stdio.h>

void	calc(int a, char *op, int b)
{
	static char	operator[5] = {'+', '-', '/', '%', '*'};
	static int	(*ope[5])(int, int) =
	{&ft_add, &ft_minus, &ft_divide, &ft_modulo, &ft_multiply};

	if (*op == operator[0])
		ft_putnbr((ope[0])(a, b));
	else if (*op == operator[1])
		ft_putnbr((ope[1])(a, b));
	else if (*op == operator[4])
		ft_putnbr((ope[4])(a, b));
	else if (*op == operator[2])
		ft_putnbr((ope[2])(a, b));
	else if (*op == operator[3])
		ft_putnbr((ope[3])(a, b));
	else
		ft_putnbr(0);
}

int		check_op(char op)
{
	if (op == '+' || op == '-' ||
			op == '*' || op == '/' ||
			op == '%')
		return (1);
	else
		ft_putnbr(0);
	return (0);
}

int		main(int argc, char **argv)
{
	int val1;
	int val2;

	if (argc == 4)
	{
		val1 = ft_atoi(argv[1]);
		val2 = ft_atoi(argv[3]);
		if (check_op(*argv[2]))
		{
			if (*argv[2] == '/' && *argv[3] == '0')
				write(1, "Stop : division by zero", 23);
			else if (*argv[2] == '%' && *argv[3] == '0')
				write(1, "Stop : modulo by zero", 21);
			else
				calc(val1, argv[2], val2);
		}
		else
			return (0);
	}
	return (0);
}
