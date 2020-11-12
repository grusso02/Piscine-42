/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:13:58 by grusso            #+#    #+#             */
/*   Updated: 2020/10/27 10:39:00 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_numeric(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (!is_numeric(str[i++]))
			return (0);
	return (1);
}
