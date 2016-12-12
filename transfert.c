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

char	**to_letters(char **tetri)
{
	int		j;
	int		i;
	char	letter;

	j = 0;
	letter = 65;
	while (tetri[j] != '\0')
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
	while (s[i] != '\0')
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

int		main(void)
{
	char	**str;

	str = (char**)malloc(sizeof(char*) * 3);
	str[0] = ft_strdup("....\n....\n..##\n..##\n");
	str[1] = ft_strdup("....\n..#.\n..##\n...#\n");
	str[2] = 0;
	str = to_opti(str);
	str = to_letters(str);
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	return (0);
}
