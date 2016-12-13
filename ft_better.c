/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:26:50 by kboucaud          #+#    #+#             */
/*   Updated: 2016/12/13 12:26:52 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_size(char *tab1, char *tab2)
{
	int		larg1;
	int		larg2;

	larg1 = 0;
	larg2 = 0;
	while (tab1[long1] != '\n')
		long1++;
	while (tab2[long2] != '\n')
		long2++;
	if (long1 > long2)
		return (tab2)
	return (tab1);
}

int			ft_is_edge(char	*tab)
{
	int		lon;
	int		lar;

	lon = 0;
	lar = 0;
	while (tab[lon] != '\n')
		lon++;
	while (tab[lar] != '\n' && tab[lar - 1] != '\n')
		lar++;
	if (lon == (lar - 1))
		return (1);
	return (0);
}

char		*ft_letters(char *tab1, char *tab2)
{
	
}