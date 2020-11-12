/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:21:35 by grusso            #+#    #+#             */
/*   Updated: 2020/11/03 12:51:07 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dst, char *src)
{
	while (*src)
		*(dst++) = *(src++);
	return (dst);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		lenght;
	int		i;
	char	*t;

	i = 0;
	lenght = 0;
	if (!size)
	{
		ret = ((char *)malloc(sizeof(char *) * 1));
		ret[0] = 0;
		return (ret);
	}
	while (i < size)
		lenght += ft_strlen(strs[i++]);
	ret = ((char *)malloc((lenght + (size - 1)) * ft_strlen(sep) + 1));
	t = ft_strcat(ret, strs[0]);
	i = 1;
	while (i < size)
	{
		t = ft_strcat(t, sep);
		t = ft_strcat(t, strs[i++]);
	}
	*t = 0;
	return (ret);
}
