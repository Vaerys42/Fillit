/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:26:28 by kboucaud          #+#    #+#             */
/*   Updated: 2016/12/06 13:27:08 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	**tetri;
	int		i;

	i = 0;
	if (argc != 2)
		return (0);
	if (ft_check(argv[1]) == NULL)
		write (1, "Erreur", 6);
	tetri = ft_check(argv[1]);
	//tetri = to_opti(tetri);
	//tetri = to_letters(tetri);
	/*while (tetri[i] != 0)
	{
		printf("%s\n", tetri[i]);
		i++;
	}*/
	return (0);
}
