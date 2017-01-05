/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:09:39 by kboucaud          #+#    #+#             */
/*   Updated: 2016/12/08 12:09:40 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_char(char *file)
{
	int		i;

	i = 0;
	while (file[i] != '\0')
	{
		if (file[i] != '.' && file[i] != '#' && file[i] != '\n' && file[i] != 0)
			return (0);
		i++;
	}
	if (file[i - 1] != '\n' || i > 545)
		return (0);
	return (1);
}

char	**to_letters(char **tetri)
{
	int		j;
	int		i;
	char	letter;

	j = 0;
	letter = 65;
	while (tetri[j] != 0)
	{
		i = 0;
		while (tetri[j][i] != '\0')
		{
			if (tetri[j][i] == '#')
				tetri[j][i] = letter;
			i++;
		}
		j++;
		letter++;
	}
	return (tetri);
}

char	**to_opti(char **s)
{
	int		i;

	i = 0;
	while (s[i] != 0)
	{
		while (s[i][0] == '.' && s[i][5] == '.' \
			&& s[i][10] == '.' && s[i][15] == '.')
			s[i] = ft_decal_left(s[i]);
		while (s[i][0] == '.' && s[i][1] == '.' \
			&& s[i][2] == '.' && s[i][3] == '.')
			s[i] = ft_decal_top(s[i]);
		i++;
	}
	return (s);
}

char	*ft_decal_top(char *tetri)
{
	int		i;

	i = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] == '#' && i >= 5)
		{
			tetri[i - 5] = '#';
			tetri[i] = '.';
		}
		i++;
	}
	return (tetri);
}

char	*ft_decal_left(char *tetri)
{
	int		i;

	i = 0;
	while (tetri[i] != '\0')
	{
		if (tetri[i] == '#' && i >= 1)
		{
			tetri[i - 1] = '#';
			tetri[i] = '.';
		}
		i++;
	}
	return (tetri);
}
