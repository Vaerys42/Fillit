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

# define BUFF_SIZE 12500

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		ft_tab_check(char **tetri);
char	**ft_check(const char *path);
int		valid_tetri(char **tetri);
char	*ft_decal_top(char *tetri);
char	*ft_decal_left(char *tetri);
char	*ft_strdup(const char *src);
char	*ft_strndup(char *str, int size, int start);
char 	**ft_to_tab(char *file);
char	**to_opti(char **s);
char	**to_letters(char **tetri);

#endif
