/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzanot <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:39:13 by lmarzanot         #+#    #+#             */
/*   Updated: 2020/10/25 14:36:04 by gcusuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_line(int x, char l_corner, char body, char r_corner);

void	rush(int x, int y)
{
	char	chars[4];
	int		i;

	i = 0;
	chars[0] = 'C';
	chars[1] = 'B';
	chars[2] = 'A';
	chars[3] = ' ';
	if (!(x <= 0 || y <= 0))
	{
		print_line(x, chars[0], chars[1], chars[2]);
		while (i < y - 2)
		{
			print_line(x, chars[1], chars[3], chars[1]);
			i++;
		}
		if (y != 1)
		{
			print_line(x, chars[2], chars[1], chars[0]);
		}
	}
	else
		write(1, "!Error!\nPlease enter an int > 0\n", 33);
}

void	print_line(int x, char l_corner, char body, char r_corner)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(r_corner);
		else if (i + 1 < x)
			ft_putchar(body);
		else if (i == x - 1)
			ft_putchar(l_corner);
		i++;
	}
	ft_putchar('\n');
}
