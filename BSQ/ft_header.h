/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:45:16 by grusso            #+#    #+#             */
/*   Updated: 2020/11/12 11:45:18 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_gridinfo {
	int		height;
	int		width;
	char	empty;
	char	obstacle;
	char	sqrchr;
	char	**map;
	int		x_bsq;
	int		y_bsq;
}				t_gridinfo;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
void			ft_error(char *err);
int				ft_atoi(char *str);

char			**ft_check_map(char **map, int height);

char			**ft_get_lines_from_grid(char *path_to_dict);
int				ft_get_number_of_lines(char **lines);
char			*ft_file_missing(void);

void			ft_do_square(t_gridinfo mygrid);

char			**ft_split(char *str, char *charset);

#endif
