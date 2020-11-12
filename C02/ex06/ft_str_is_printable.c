/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:56:08 by grusso            #+#    #+#             */
/*   Updated: 2020/10/27 10:39:49 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_printable(char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

int	ft_str_is_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (!is_printable(str[i++]))
			return (0);
	return (1);
}
