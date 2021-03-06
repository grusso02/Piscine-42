/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_to_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:45:42 by grusso            #+#    #+#             */
/*   Updated: 2020/11/12 11:45:44 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char			*ft_file_missing(void)
{
	char	buf;
	int		file;

	if ((file = open("tempgrid", O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
		return (NULL);
	while (read(STDIN_FILENO, &buf, 1))
	{
		write(file, &buf, 1);
	}
	close(file);
	return ("tempgrid");
}

char			*ft_filetostr(char *path)
{
	int				grid;
	unsigned int	nbchars;
	char			currchar;
	char			*filestr;
	int				i;

	if ((grid = open(path, O_RDONLY)) < 0)
		return (NULL);
	nbchars = 0;
	while (read(grid, &currchar, 1))
		nbchars++;
	if (!(filestr = malloc(sizeof(char) * (nbchars + 1))))
		return (NULL);
	close(grid);
	grid = open(path, O_RDONLY);
	i = 0;
	while (read(grid, filestr + i, 1))
		i++;
	close(grid);
	filestr[nbchars] = '\0';
	return (filestr);
}

char			**ft_get_lines_from_grid(char *path_to_dict)
{
	char **lines;
	char *filestr;

	if (!(filestr = ft_filetostr(path_to_dict)))
		return (NULL);
	lines = ft_split(filestr, "\n");
	free(filestr);
	return (lines);
}

int				ft_get_number_of_lines(char **lines)
{
	int i;

	i = 0;
	while (lines[i])
		i++;
	return (i);
}
