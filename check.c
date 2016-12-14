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

int			ft_check(const char *path)
{
	int		fd;
	char	*file;
	int		i;
	char 	**tetri;

	i = 0;
	if (!(file = (char*)malloc(sizeof(char) * 85)))
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	if ((read(fd, file, 84) == -1))
		return (0);
	tetri = ft_to_tab(file);
	//if (ft_tab_check(tetri) == 0)
		//return (0);
	printf("%s\n", tetri[3]);
	return (1);
}

char 		**ft_to_tab(char *file)
{
	int		i;
	int		j;
	int		size;
	char	**tetri;

	i = 0;
	j = 0;
	tetri = (char**)malloc(sizeof(char*) * 27);
	while ((file[i] != '\0' || file[i] != EOF) && i < 12500)
	{
		size = i;
		while (file[size] != '\n' && file[size - 1] != '\n' && file[size] != '\0')
		{
			size++;
		}
		tetri[j] = ft_strndup(file, size, i);
		while (file[i] != '\n' && file[i - 1] != '\n' && file[i] != '\0')
			i++;
		i++;
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
