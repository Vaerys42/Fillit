/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 10:57:27 by ybranco           #+#    #+#             */
/*   Updated: 2016/12/29 10:57:35 by ybranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char		**creation_tableau(int tetra)
{
	char	**tab;
	int		i;
	int		o;

	o = -1;
	if (!(tab = malloc(sizeof(char *) * (tetra + 1))))
		return (0);
	while (++o < tetra)
		if (!(tab[o] = malloc(sizeof(char) * (tetra + 1))))
			return (0);
	o = 0;
	while (o < tetra)
	{
		i = -1;
		while (++i < tetra)
			tab[o][i] = '.';
		tab[o][i] = '\0';
		o++;
	}
	return (tab);
}

char		**list(void)
{
	char	**test;
	int		o;

	o = -1;
	if (!(test = malloc(sizeof(char *) * (9))))
		return (0);
	while (++o < 9)
		if (!(test[o] = malloc(sizeof(char) * (21))))
			return (0);
	test[0] = "A...\nA...\nA...\nA...\n\0";
	test[1] = "BBBB\n....\n....\n....\n\0";
	test[2] = "CCC.\n..C.\n....\n....\n\0";
	test[3] = ".DD.\nDD..\n....\n....\n\0";
	test[4] = "EE..\nEE..\n....\n....\n\0";
	test[5] = "FF..\n.FF.\n....\n....\n\0";
	test[6] = "GG..\n.G..\n.G..\n....\n\0";
	test[7] = "HHH.\n.H..\n....\n....\n\0";
	/*test[8] = "I...\nI...\nI...\nI...\n\0";
	test[9] = "JJJJ\n....\n....\n....\n\0";
	test[10] = "KKK.\n..K.\n....\n....\n\0";
	test[11] = ".LL.\nLL..\n....\n....\n\0";
	test[12] = "MM..\nMM..\n....\n....\n\0";
	test[13] = "NN..\n.NN.\n....\n....\n\0";
	test[14] = "OO..\n.O..\n.O..\n....\n\0";
	test[15] = "PPP.\n.P..\n....\n....\n\0";*/
	return (test);
}

int			pose2(char *test, char **tab, int o, int i)
{
	int a;
	int b;
	int c;

	c = 0;
	a = -1;
	b = -1;
	while (++a < 4 && tab[o + a] != '\0')
	{
		while (++b < 4 && tab[o][i + b] != '\0')
		{
			if (test[c] != '.')
				tab[o + a][i + b] = test[c];
			c++;
		}
		c = c + (4 - b) + 1;
		b = -1;
	}
	return (1);
}

int			pose(char *test, char **tab, int o, int i)
{
	int a;
	int b;
	int c;
	int e;

	e = 0;
	c = 0;
	a = -1;
	b = -1;
	while (++a < 4 && tab[o + a] != '\0')
	{
		while (++b < 4 && tab[o][i + b] != '\0')
		{
			if ((tab[o + a][i + b] != '.') && (test[c] != '.'))
				return (0);
			if (test[c] != '.')
				e++;
			c++;
		}
		c = c + (4 - b) + 1;
		b = -1;
	}
	if (e != 4)
		return (0);
	return (pose2(test, tab, o, i));
}

int			result(char **tab)
{
	int i;
	int o;

	o = 0;
	i = 0;
	while (tab[o])
	{
		while (tab[o][i])
		{
			write(1, &tab[o][i], 1);
			i++;
		}
		write(1, "\n", 1);
		i = 0;
		o++;
	}
	return (42);
}

void		saveio(int *save, char **tab, int i, int o)
{
	save[0] = o;
	save[1] = i + 1;
	if (tab[o][i + 1] == '\0')
	{
		save[0] = o + 1;
		save[1] = 0;
	}
}

int			*retraite(char **tab, int a)
{
	int i;
	int o;
	int q;
	int *save;

	if (!(save = malloc(sizeof(int) * (4))))
		return (0);
	q = 0;
	i = -1;
	o = -1;
	while (tab[++o])
	{
		while (tab[o][++i])
			if (tab[o][i] == (a + 64))
			{
				if (q++ == 0)
					saveio(save, tab, i, o);
				tab[o][i] = '.';
			}
		i = -1;
	}
	save[2] = a - 1;
	return (save);
}

int			testons(int a, char **tab, char **test, int *loc)
{
	int i;
	int o;

	o = loc[0];
	i = loc[1];
	while (tab[++o])
	{
		while (tab[o][++i])
		{
			if (pose(test[a], tab, o, i) == 1)
			{
				a++;
				if (test[a][0] == '\0')
					return (result(tab));
				i = -1;
				o = 0;
			}
		}
		i = -1;
	}
	return (a);
}

int			parcour_tableau(char **tab, char **test)
{
	int loc[2];
	int a;
	int *save;

	a = 0;
	loc[0] = -1;
	loc[1] = -1;
	while (test[a])
	{
		a = testons(a, tab, test, loc);
		if (a == 42)
			return (1);
		if (a == 0)
			return (0);
		save = retraite(tab, a);
		loc[0] = save[0] - 1;
		loc[1] = save[1] - 1;
		a = save[2];
	}
	return (0);
}

int			main(void)
{
	char	**tab;
	char	**test;
	int		tetra;

	test = list();
	tetra = 3;
	tab = creation_tableau(tetra);
	while (parcour_tableau(tab, test) == 0)
	{
		tetra++;
		tab = creation_tableau(tetra);
	}
	return (0);
}
