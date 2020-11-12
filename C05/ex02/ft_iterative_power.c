/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:49:07 by grusso            #+#    #+#             */
/*   Updated: 2020/10/29 11:19:01 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int c;

	c = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power--)
	{
		c *= nb;
	}
	return (c);
}
