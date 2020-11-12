/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:14:07 by grusso            #+#    #+#             */
/*   Updated: 2020/10/29 17:28:05 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_next_prime(int nb)
{
	int div;
	int conta;

	conta = 0;
	div = 1;
	if (nb <= 0)
		return (0);
	while (conta < 3 && div <= nb / 2)
	{
		if (nb % div == 0)
			conta++;
		div++;
	}
	if (conta == 1)
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}
