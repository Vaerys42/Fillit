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
}
