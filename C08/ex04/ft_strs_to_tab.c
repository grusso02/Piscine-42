/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:37:56 by grusso            #+#    #+#             */
/*   Updated: 2020/11/05 18:37:57 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_strlen(char *av)
{
	int	lenght;

	lenght = 0;
	while (av[lenght])
		lenght++;
	return (lenght);
}

char					*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char))))
		return (0);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct		s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s_conv;
	int			i;

	i = 0;
	if (!(s_conv = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str))))
		return (0);
	while (i < ac)
	{
		s_conv[i].size = ft_strlen(av[i]);
		s_conv[i].str = av[i];
		s_conv[i].copy = ft_strdup(s_conv[i].str);
		i++;
	}
	s_conv[i].str = 0;
	return (s_conv);
}
