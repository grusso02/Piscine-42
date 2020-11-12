/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 09:58:15 by grusso            #+#    #+#             */
/*   Updated: 2020/11/12 09:58:23 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		ft_get_tab_size(char **tab)
{
	int ret;

	ret = 0;
	while (tab[ret])
		ret++;
	return (ret);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		size;
	char	*tmp;

	i = 1;
	size = ft_get_tab_size(tab);
	while (i < size)
	{
		j = 0;
		while (++j < size)
		{
			if (ft_strcmp(tab[j - 1], tab[j]) > 0)
			{
				tmp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = tmp;
			}
		}
		i++;
	}
}
