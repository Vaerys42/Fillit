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

char	**toletters(char **tetri)
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

char	**to_opti(char **tetri)
{
	int		i;

	i = 0;
	while (tetri[i] != '\0')
	{
		while (tetri[i][0] == '.' && tetri[i][5] == '.' && tetri[i][10] == '.' && tetri[i][15] == '.')
			tetri[i] = ft_decal_left(tetri[i]);
		/*while (tetri[i][0] == '.' && tetri[i][1] == '.' && tetri[i][2] == '.' && tetri[i][3] == '.')
			tetri[i] = ft_decal_top(tetri[i]);*/
		i++;
	}
	return (tetri);
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

int			main(void)
{
	char	**str;

	str = (char**)malloc(sizeof(char*) * 3);
	str[0] = ft_strdup("....\n.##.\n..##\n....\n");
	str[1] = ft_strdup("...#\n...#\n...#\n...#\n");
	str = to_opti(str);
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	return (0);
}