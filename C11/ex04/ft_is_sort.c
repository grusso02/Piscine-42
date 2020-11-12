/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:24:17 by grusso            #+#    #+#             */
/*   Updated: 2020/11/11 18:37:51 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int k;
	int tmp;

	k = 0;
	while (length-- > 1)
	{
		tmp = f(tab[length], tab[length - 1]);
		if (tmp == 0)
			continue;
		if (k == 0)
			k = tmp;
		else if ((k < 0 && tmp > 0) || (k > 0 && tmp < 0))
			return (0);
	}
	return (1);
}
