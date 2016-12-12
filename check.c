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
	int		j;
	int		k;
	char 	**tetri;

	i = 0;
	j = 0;
	k = 0;
	if (!(tetri = (char**)malloc(sizeof(char*) * 4)))
		return (0);
	if (!(file = (char*)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	if ((read(fd, file, BUFF_SIZE) == -1))
		return (0);
	while (file[i] != '\0')
	{
		tetri[j][k] = file[i];
		k++;
		if (file[i] == '\n' && file[i - 1] == '\n')
		{
			tetri[j][k] = '\0';
			j++;
			k = 0;
		}
		i++;
	}
	tetri[j][k] = '\0';
	file[j + 1] = '\0';
	//if (ft_chartabcheck(tetri) == 0)
		//return (0);
	return (1);
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

int			ft_chartabcheck(char **tetri)
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

int			main()
{
	char 		**tetriminos;

	tetriminos = (char**)malloc(sizeof(char*) * 4);
	tetriminos[0] = ft_strdup("....\n....\n....\n####\n");
	tetriminos[1] = ft_strdup("....\n##..\n.##.\n....\n");
	tetriminos[2] = ft_strdup("#.#.\n#.#.\n....\n....\n");
	tetriminos[3] = 0;
	printf("%d\n", ft_chartabcheck(tetriminos));
	return (0);	
}
