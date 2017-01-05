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
	char	**tetri;

	i = 0;
	if (!(tetri = (char**)malloc(sizeof(char*) * 27)))
		return (NULL);
	if (!(file = (char*)malloc(sizeof(char) * 600)))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if ((read(fd, file, 599) == -1))
		return (NULL);
	if (ft_check_char(file) == 0)
		return (NULL);
	write(1, "", 0);
	tetri = ft_to_tab(file);
	if (tetri == NULL)
		return (NULL);
	free(file);
	if (ft_tab_check(tetri) == 0)
		return (NULL);
	return (tetri);
}

char		**ft_to_tab(char *file)
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
			tetri[j++] = ft_strndup(file, size, start);
			size = 0;
			start = ++i;
		}
		size++;
		i++;
	}
	tetri[j++] = ft_strndup(file, size, start);
	while (j <= 26)
		tetri[j++] = 0;
	return (tetri);
}

int			check_diese(char **tetri, int i, int j)
{
	int		l;

	l = 0;
	if (tetri[j][i - 1] == '#' && i >= 1)
		l++;
	if (tetri[j][i + 1] == '#')
		l++;
	if (tetri[j][i - 5] == '#' && i >= 5)
		l++;
	if (tetri[j][i + 5] == '#' && i <= 16)
		l++;
	return (l);
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
				l = l + check_diese(tetri, i, j);
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
