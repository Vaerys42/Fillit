/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:38:05 by kboucaud          #+#    #+#             */
/*   Updated: 2016/11/09 14:34:09 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
	{
		write(2, "ENOMEM", 6);
		return (NULL);
	}
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
