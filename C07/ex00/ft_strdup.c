/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:33:01 by grusso            #+#    #+#             */
/*   Updated: 2020/11/05 15:12:24 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	long long	l;
	char		*str;

	l = 0;
	while (src[l])
		l++;
	if (!(str = (char *)malloc(sizeof(char) * (l + 1))))
		return (0);
	str[l] = 0;
	while (l >= 0)
	{
		str[l] = src[l];
		l--;
	}
	return (str);
}
