/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcusuman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:33:56 by gcusuman          #+#    #+#             */
/*   Updated: 2020/10/25 14:35:45 by gcusuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_line(int x, char extremity, char body)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0 || i == x - 1)
			ft_putchar(extremity);
		else if (i + 1 < x)
			ft_putchar(body);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	char	chars[4];
	int		i;

	i = 0;
	chars[0] = 'A';
	chars[1] = 'B';
	chars[2] = 'C';
	chars[3] = ' ';
	if (!(x <= 0 || y <= 0))
	{
		print_line(x, chars[0], chars[1]);
		while (i < y - 2)
		{
			print_line(x, chars[1], chars[3]);
			i++;
		}
		if (y != 1)
		{
			print_line(x, chars[2], chars[1]);
		}
	}
	else
		write(1, "!Error!\nPlease enter an int > 0\n", 33);
}
