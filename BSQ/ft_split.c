/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:45:28 by grusso            #+#    #+#             */
/*   Updated: 2020/11/12 11:45:33 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int		ft_is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == 0)
		return (1);
	return (0);
}

int		ft_nb_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i + 1], charset) == 1
				&& ft_is_sep(str[i], charset) == 0)
			words++;
		i++;
	}
	return (words);
}

void	ft_word_in_tab(char *dest, char *from, char *charset)
{
	int i;

	i = 0;
	while (ft_is_sep(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = 0;
}

void	ft_do_res(char **res, char *str, char *charset)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		if (ft_is_sep(str[i], charset) == 1)
			i++;
		else
		{
			while (ft_is_sep(str[i + j], charset) == 0)
				j++;
			res[k] = malloc(sizeof(char) * (j + 1));
			ft_word_in_tab(res[k], str + i, charset);
			i += j;
			k++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		count;

	count = ft_nb_words(str, charset);
	res = malloc(sizeof(char *) * (count + 1));
	res[count] = 0;
	ft_do_res(res, str, charset);
	return (res);
}