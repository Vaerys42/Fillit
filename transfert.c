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
