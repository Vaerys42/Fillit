/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:25:29 by kboucaud          #+#    #+#             */
/*   Updated: 2016/12/13 16:25:33 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strndup(char *str, int size, int start)
{
	char	*new;
	int		i;

	i = 0;
	new = (char*)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	while (i < size)
	{
		new[i] = str[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
