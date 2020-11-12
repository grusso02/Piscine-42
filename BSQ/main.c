/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:45:53 by grusso            #+#    #+#             */
/*   Updated: 2020/11/12 11:48:08 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_process_file(t_gridinfo mygrid, char *filename)
{
	char	*charptr;

	if (!(mygrid.map =
				ft_check_map(ft_get_lines_from_grid(filename), mygrid.height)))
	{
		ft_error("map error\n");
		return ;
	}
	charptr = mygrid.map[0];
	while (*charptr)
		charptr++;
	mygrid.sqrchr = *(charptr - 1);
	mygrid.empty = *(charptr - 3);
	ft_do_square(mygrid);
}

void	ft_calculate_dims(int file, char *filename)
{
	t_gridinfo	mygrid;
	char		c;
	char		temp;
	char		prev_c;

	c = 0;
	prev_c = 0;
	while (c != '\n' && read(file, &c, 1))
		;
	mygrid.width = 0;
	mygrid.height = 1;
	while (read(file, &c, 1))
	{
		if (mygrid.height == 1 && c != '\n')
			mygrid.width++;
		if (c == '\n')
			mygrid.height++;
		prev_c = temp;
		temp = c;
	}
	close(file);
	(c == '\n' && prev_c != '\n' && prev_c != '\0') ?
	ft_process_file(mygrid, filename)
	: ft_error("map error\n");
}

void	ft_parse_file(char *filename)
{
	int			file;

	if ((file = open(filename, O_RDONLY)) < 0)
		ft_error("map error\n");
	else
		ft_calculate_dims(file, filename);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 1)
		ft_parse_file(ft_file_missing());
	while (i < ac)
	{
		ft_parse_file(av[i]);
		if (i < ac - 1)
			ft_putchar('\n');
		i++;
	}
	return (0);
}
