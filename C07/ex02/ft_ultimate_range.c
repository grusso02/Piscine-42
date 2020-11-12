/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:49:38 by grusso            #+#    #+#             */
/*   Updated: 2020/11/11 17:34:27 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	bound;
	int	i;
	int	*buffer;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	bound = max - min - 1;
	if ((buffer = malloc(bound * sizeof(int))) == NULL)
	{
		*range = 0;
		return (-1);
	}
	*range = buffer;
	i = 0;
	while (i <= bound)
	{
		buffer[i] = min + i;
		i++;
	}
	return (bound + 1);
}
