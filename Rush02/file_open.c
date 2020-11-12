#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		strlenght(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		arrlenght(char **arr)
{
	int i;

	i = 0;
	while (arr[i][0])
		i++;
	return (i);
}

int		splitcount(char *carr)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (carr[i])
		if (carr[i++] == '\n')
			k++;
	return (k);
}

int		check_line(char *str)
{
	char *ptr;

	ptr = str;
	while (*ptr >= 48 && *ptr <= 57)
		ptr++;
	while (*ptr == 32)
		ptr++;
	if (*ptr == 58)
		ptr++;
	else
		return (0);
	while (*ptr == 32)
		ptr++;
	while (*ptr > 31 && *ptr <= 127)
		ptr++;
	if (*ptr == '\0')
		return (1);
	else
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
}

int		splitter(char **linearr, char *carr)
{
	int		starti;
	int		endi;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	while (carr[i[1]])
	{
		starti = i[1];
		while (carr[i[1]] != '\n')
			i[1]++;
		endi = i[1];
		if (!(linearr[i[0]] = malloc(sizeof(char*) * (endi - starti + 1))))
			return (0);
		i[2] = 0;
		while (starti < endi)
			linearr[i[0]][i[2]++] = carr[starti++];
		linearr[i[0]][i[2]] = '\0';
		if (!(check_line(linearr[i[0]])))
			return (0);
		i[1]++;
		i[0]++;
	}
	linearr[i[0]] = 0;
	return (1);
}

int		divider(char **linearr, char **pairarr, char **letterarr)
{
	int l;
	int i;
	int k;
	int j;
	int starti;
	int endi;
	int colon_switch;

	i = 0;
	while (linearr[i])
	{
		colon_switch = 0;
		k = 0;
		starti = k;
		while (linearr[i][k] >= '0' && linearr[i][k] <= '9')
			k++;
		endi = k;
		l = 0;
		if (!(pairarr[i] = malloc(sizeof(char*) * (endi - starti) + 1)))
			return (0);
		while (starti < endi)
		{
			pairarr[i][l++] = linearr[i][starti++];
		}
		pairarr[i][l] = 0;
		l = 0;
		while ((linearr[i][k] == ':' && !colon_switch) || linearr[i][k] == ' ')
		{
			if (linearr[i][k] == ':')
				colon_switch = 1;
			k++;
		}
		starti = k;
		while (linearr[i][k] >= 32 && linearr[i][k] <= 127)
		{
			k++;
		}
		endi = k;
		if (!(letterarr[i] = malloc(sizeof(char*) * (endi - starti) + 1)))
			return (0);
		while (starti < endi)
		{
			letterarr[i][l++] = linearr[i][starti++];
		}
		letterarr[i++][l] = 0;
	}
	return (1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		size1;
	int		size2;
	int		index;

	index = 0;
	size1 = strlenght(s1) - 1;
	size2 = strlenght(s2) - 1;
	while (s1[index] && s2[index])
	{
		if (s1[index] < s2[index])
			return (-1);
		else if (s1[index] > s2[index])
			return (1);
		else
			index++;
	}
	if (size1 > size2)
		return (1);
	else if (size1 == size2)
		return (0);
	else
		return (-1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	if (!*to_find)
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (!to_find[j + 1])
			{
				return (str + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		monofinder(char **pairarr, char **letterarr, char ch)
{
	int		found;
	int		i;
	char	*str;
	int		l;

	i = 0;
	l = 0;
	found = 0;
	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (0);
	str[0] = ch;
	str[1] = 0;
	while (pairarr[i])
	{
		l = strlenght(pairarr[i]);
		if (ft_strstr(pairarr[i], str) && !ft_strcmp(pairarr[i], str))
		{
			ft_putstr(letterarr[i]);
			found++;
			break ;
		}
		i++;
	}
	if (found == 0)
		write(1, "Dict Error\n", 11);
	return (0);
}

void	pairfinder(char **pairarr, char **letterarr, char *str)
{
	int found;
	int i;

	i = 0;
	found = 0; 
	while (pairarr[i])
	{
		l = strlenght(pairarr[i]);
		if (ft_strstr(pairarr[i], str) && !ft_strcmp(pairarr[i], str))
		{
			ft_putstr(letterarr[i]);
			found++;
			break ;
		}
		i++;
	}
	if (found == 0)
		write(1, "Dict Error\n", 11);
}

int		get_order(char **pairarr, char **letterarr, char **tern, int i)
{
	int		len;
	int		k;
	char	*order;

	k = 1;
	len = arrlenght(tern);
	if (!(order = (char *)malloc(sizeof(char) * (len - i + 1))))
		return (0);
	order[0] = 49;
	while (k <= (((len - i - 1) * 3)))
	{
		order[k] = 48;
		k++;
	}
	order[k] = 0;
	pairfinder(pairarr, letterarr, order);
	return (1);
}

int		check_order(char **pairarr, char **tern)
{
	int		len;
	int		k;
	int		i;
	char	*order;

	k = 1;
	i = 0;
	len = arrlenght(tern);
	if (!(order = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	order[0] = 49;
	while (k <= (((len - 1) * 3)))
	{
		order[k] = 48;
		k++;
	}
	order[k] = 0;
	while (pairarr[i])
	{
		if (ft_strstr(pairarr[i], order) &&
			!ft_strcmp(pairarr[i], order))
			return (1);
		i++;
	}
	return (0);
}

void	ft_print_space(char **tern, int i, int position)
{
	if (i != arrlenght(tern) - 1)
		ft_putstr(" ");
	else if (position == 0 && (tern[i][1] != 48 || tern[i][2] != 48))
		ft_putstr(" ");
	else if (position == 1 && tern[i][2] != 48)
		ft_putstr(" ");
	else if (position == 4)
		ft_putstr(" ");
}

void	and_filler(char **tern, int i)
{
	if (tern[i][0] != 48 && (tern[i][1] != 48 || tern[i][2] != 48))
		ft_putstr("and ");
}

void	hundred_printer(char **pairarr, char **letterarr, char **tern, int i)
{
	monofinder(pairarr, letterarr, tern[i][0]);
	pairfinder(pairarr, letterarr, "100");
	and_filler(tern, i);
}

void	other_cases(char **pairarr, char **letterarr, char **tern, int i)
{
	if ((tern[i][1] != 49 && (tern[i][2] != 48)) ||
		(arrlenght(tern) == 1 && tern[i][0] == 48 && tern[i][1] == 48))
		monofinder(pairarr, letterarr, tern[i][2]);
	if (tern[i][0] != 48 || tern[i][1] != 48 || tern[i][2] != 48)
		if ((arrlenght(tern) - i) > 1)
			get_order(pairarr, letterarr, tern, i);
}

void	houndred_dec(char **pairarr, char **letterarr, char **tern, int i)
{
	if (i != 0 && (tern[i][0] != 48 || tern[i][2] != 48 ||
		tern[i][2] != 48))
	{
		if (!(i == arrlenght(tern) - 1 && arrlenght(tern) != 1) ||
		tern[i][0] != 48)
			ft_putstr(", ");
	}
	if (tern[i][0] != 48)
	{
		monofinder(pairarr, letterarr, tern[i][0]);
		if (tern[i][0] != 48 && tern[i][1] == 48 && tern[i][2] == 48)
			ft_print_space(tern, i, 4);
		else
			ft_print_space(tern, i, 0);
		pairfinder(pairarr, letterarr, "100");
		ft_print_space(tern, i, 0);
	}
}

int		deca_dec(char **pairarr, char **letterarr, char **tern, int i)
{
	char	*prov;

	if (tern[i][1] == 49)
	{
		if (!(prov = (char *)malloc(sizeof(char) * 3)))
			return (0);
		prov[0] = tern[i][1];
		prov[1] = tern[i][2];
		prov[2] = 0;
		and_filler(tern, i);
		pairfinder(pairarr, letterarr, prov);
		if (i != arrlenght(tern) - 1)
			ft_print_space(tern, i, 1);
	}
	else if (tern[i][1] != 49 && tern[i][1] != 48)
	{
		if (!(prov = (char *)malloc(sizeof(char) * 3)))
			return (0);
		prov[0] = tern[i][1];
		prov[1] = 48;
		prov[2] = 0;
		and_filler(tern, i);
		pairfinder(pairarr, letterarr, prov);
		ft_print_space(tern, i, 1);
	}
	return (1);
}

void	and_space_an(char **pairarr, char **letterarr, char **tern, int i)
{
	if ((tern[i][1] != 49 && (tern[i][2] != 48)) ||
		(arrlenght(tern) == 1 && tern[i][0] == 48 && tern[i][1] == 48))
	{
		if (tern[i][1] == 48)
			and_filler(tern, i);
		monofinder(pairarr, letterarr, tern[i][2]);
		ft_print_space(tern, i, 2);
	}
}

void	unit_dec(char **pairarr, char **letterarr, char **tern, int i)
{
	if (tern[i][0] != 48 || tern[i][1] != 48 || tern[i][2] != 48)
		if ((arrlenght(tern) - i) > 1)
			get_order(pairarr, letterarr, tern, i);
}

int		decomposer(char **pairarr, char **letterarr, char **tern, int i)
{
	houndred_dec(pairarr, letterarr, tern, i);
	if (deca_dec(pairarr, letterarr, tern, i) == 0)
		return (0);
	and_space_an(pairarr, letterarr, tern, i);
	unit_dec(pairarr, letterarr, tern, i);
	return (1);
}

int		iterative_decomp(char **pairarr, char **letterarr, char **tern)
{
	int i;

	i = 0;
	if (check_order(pairarr, tern))
	{
		while (tern[i][0])
		{
			decomposer(pairarr, letterarr, tern, i);
			i++;
		}
		return (1);
	}
	else
	{
		ft_putstr("Dict Error \n");
		return (0);
	}
}

char	*first_tern(char *input, int k, char *output, int *i)
{
	if (k == 1)
	{
		output[0] = '0';
		output[1] = '0';
		output[2] = input[i[3]];
		i[3] += 1;
		output[3] = 0;
	}
	else if (k == 2)
	{
		output[0] = '0';
		output[1] = input[i[3]];
		i[3] += 1;
		output[2] = input[i[3]];
		i[3] += 1;
		output[3] = 0;
	}
	return (output);
}

char	*ternizer(char *input, char *output, int *i)
{
	int j;

	j = 0;
	while (j < 3)
	{
		output[j] = input[i[3]];
		i[3] += 1;
		j++;
	}
	output[j] = 0;
	return (output);
}

char	**engine_div(int i[4], char **tern, char *input)
{
	if (!(tern = (char **)malloc(sizeof(char *) * ((i[1] / 3) + 2))))
		return (0);
	if (i[1] % 3 != 0)
	{
		i[0] = 1;
		i[2] = 1;
		if (!(tern[0] = (char *)malloc(sizeof(char) * 4)))
			return (0);
		tern[0] = first_tern(input, (i[1] % 3), tern[0], i);
	}
	while (i[0] < ((i[1] / 3) + i[2]))
	{
		if (!(tern[i[0]] = (char *)malloc(sizeof(char) * 4)))
			return (0);
		tern[i[0]] = ternizer(input, tern[i[0]++], i);
	}
	if (!(tern[i[0]] = (char *)malloc(sizeof(char) * 2)))
		return (0);
	tern[i[0]][0] = 0;
	return (tern);
}

char	**tern_div(char *input)
{
	char	**tern;
	int		i[4];

	tern = NULL;
	i[1] = strlenght(input);
	i[0] = 0;
	i[2] = 0;
	i[3] = 0;
	return (engine_div(i, tern, input));
}

char	*ft_read(int argc, char **argv, char *buff)
{
	int		fd;
	char	c;
	int		i;

	i = 0;
	if (argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else if (argc == 3)
		fd = open(argv[1], O_RDONLY);
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (read(fd, &c, 1))
		buff[i++] = c;
	buff[i] = '\0';
	close(fd);
	return (buff);
}

char	*ft_create_buffer(int argc, char **argv, char *buff)
{
	int		buffer_size;
	int		fd;
	char	c;

	buffer_size = 0;
	if (argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else if (argc == 3)
		fd = open(argv[1], O_RDONLY);
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (read(fd, &c, 1))
		buffer_size++;
	if (!(buff = malloc(sizeof(char*) * buffer_size)))
		return (0);
	close(fd);
	return (ft_read(argc, argv, buff));
}

void	free_all(char *carr, char **linearr, char **pairarr, char **letterarr)
{
	free(carr);
	free(linearr);
	free(pairarr);
	free(letterarr);
}

int		main(int argc, char **argv)
{
	char *carr;
	char **linearr;
	char **pairarr;
	char **letterarr;
	char **tern;

	carr = NULL;
	if (!(carr = ft_create_buffer(argc, argv, carr)))
		return (0);
	if (!(linearr = malloc(sizeof(char**) * splitcount(carr) + 1)))
		return (0);
	if (!(pairarr = malloc(sizeof(char**) * splitcount(carr) + 1)))
		return (0);
	if (!(letterarr = malloc(sizeof(char**) * splitcount(carr) + 1)))
		return (0);
	splitter(linearr, carr);
	if (!(divider(linearr, pairarr, letterarr)))
		return (0);
	if (!(tern = tern_div(argv[1])))
		return (0);
	iterative_decomp(pairarr, letterarr, tern);
	free_all(carr, linearr, pairarr, letterarr);
	free(tern);
	return (0);
}
