/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzanot <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:24:37 by lmarzanot         #+#    #+#             */
/*   Updated: 2020/10/25 14:35:39 by gcusuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_line(int x, char lcorner, char body, char rcorner);

void	rush(int x, int y)
{
	char	chars[4];
	int		i;

	chars[0] = '\\';
	chars[1] = '*';
	chars[2] = '/';
	chars[3] = ' ';
	i = 0;
	if (!(x <= 0 || y <=	 0))
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

void	print_line(int x, char lcorner, char body, char rcorner)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(rcorner);
		else if (i + 1 < x)
			ft_putchar(body);
		else if (i == x - 1)
			ft_putchar(lcorner);
		i++;
	}
	ft_putchar('\n');
}
