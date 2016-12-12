/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:58:12 by kboucaud          #+#    #+#             */
/*   Updated: 2016/12/05 13:00:42 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 64

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		ft_chartabcheck(char **tetri);
int		ft_check(const char *path);
int		valid_tetri(char **tetri);
char	*ft_decal_top(char *tetri);
char	*ft_decal_left(char *tetri);

#endif
