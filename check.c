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

int		ft_check(const char *path)
{
	int		fd;
	char	*file;

	if ((file = (char*)malloc(sizeof(char) * BUFF_SIZE)) == NULL)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	if ((read(fd, file, BUFF_SIZE) == -1))
		return (0);
	if (ft_charcheck(file) == 0)
		return (0);
	return (1);
}

int		ft_charcheck(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] == '.' || str[i] == '#')
		{
			printf("%c", str[i]);
			i++;
			j++;
		}
		printf("\n");
		if (str[i] == '\n' && j == 4)
			i++;
		else
			return (0);
	}
	if (i == 0)
		return (-1);
	if (ft_valid_tetri(str) == 1)
		return (1);
	return (0);
}

int			ft_valid_tetri(char *str)
{
	if (str != NULL)
		return (1);
	return (0);
}

int		ft_chartabcheck(char **tetri)
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
	return (1);
}