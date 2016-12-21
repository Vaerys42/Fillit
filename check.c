/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:55:40 by kboucaud          #+#    #+#             */
/*   Updated: 2016/12/05 13:02:59 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_check(const char *path)
{
	int		fd;
	char	*file;
	int		i;
	char 	**tetri;
	int		test;

	i = 0;
	test = 0;
	tetri = (char**)malloc(sizeof(char*) * 27);
	if (!(file = (char*)malloc(sizeof(char) * 125000)))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if ((read(fd, file, 124999) == -1))
		return (NULL);
	test = ft_check_char(file);
	if (test == 0)
		return (NULL);
	write (1, "", 0);
	tetri = ft_to_tab(file);
	free(file);
	if (ft_tab_check(tetri) == 0)
		return (NULL);
	return (tetri);
}

int			ft_check_char(char *file)
{
	int		i;

	i = 0;
	while (file[i] != '\0')
	{
		if (file[i] != '.' && file[i] != '#' && file[i] != '\n' && file[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

char 		**ft_to_tab(char *file)
{
	int		i;
	int		j;
	int		size;
	char	**tetri;
	int		start;

	i = 0;
	j = 0;
	start = 0;
	tetri = (char**)malloc(sizeof(char*) * 27);
	while ((file[i] != '\0' || file[i] != EOF) && i < 12500)
	{
		if (file[i] == '\n' && file[i - 1] == '\n')
		{
			tetri[j] = ft_strndup(file, size, start);
			size = 0;
			j++;
			i++;
			start = i;
		}
		size++;
		i++;
	}
	tetri[j] = ft_strndup(file, size, start);
	j++;
	while (j <= 26)
	{
		tetri[j] = 0;
		j++;
	}
	return (tetri);
}

int			valid_tetri(char **tetri)
{
	int		j;
	int		i;
	int		k;
	int		l;

	j = 0;
	while (tetri[j] != '\0')
	{
		k = 0;
		i = 0;
		l = 0;
		while (tetri[j][i] != '\0')
		{
			if (tetri[j][i] == '#')
			{
				if (tetri[j][i - 1] == '#' && i >= 1)
					l++;
				if (tetri[j][i + 1] == '#')
					l++;
				if (tetri[j][i - 5] == '#' && i >= 5)
					l++;
				if (tetri[j][i + 5] == '#' && i <= 16)
					l++;
				k++;
			}
			i++;
		}
		if (k != 4 || (l != 6 && l != 8))
			return (0);
		j++;
	}
	return (1);
}

int			ft_tab_check(char **tetri)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	while (tetri[j] != '\0')
	{
		i = 0;
		k = 0;
		while (tetri[j][i] == '.' || tetri[j][i] == '#')
		{
			i++;
			k++;
		}
		if (tetri[j][i] == '\n' && k == 4)
			i++;
		else
			return (0);
		j++;
	}
	if (valid_tetri(tetri))
		return (1);
	return (0);
}
