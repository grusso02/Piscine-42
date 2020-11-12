/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:20:58 by grusso            #+#    #+#             */
/*   Updated: 2020/11/12 09:56:08 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int lenght, int (*f)(int))
{
	int i;
	int *arr;

	i = 0;
	if (!(arr = (int *)malloc(sizeof(int) * lenght)))
		return (0);
	while (i < lenght)
	{
		arr[i] = f(tab[i]);
		i++;
	}
	return (arr);
}
