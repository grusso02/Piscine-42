/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:10:02 by grusso            #+#    #+#             */
/*   Updated: 2020/10/29 10:48:12 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int ret;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	ret = 1;
	while (nb)
		ret *= (nb--);
	return (ret);
}
