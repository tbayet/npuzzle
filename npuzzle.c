/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:44:25 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/17 18:10:19 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "npuzzle.h"

static t_dim	getdim(char **tab, char c)
{
	t_dim	dim;

	dim.i = 0;
	dim.j = 0;
	while (tab[dim.i])
	{
		dim.j = 0;
		while (tab[dim.i][dim.j])
		{
			if (tab[dim.i][dim.j] == c)
				return (dim);
			dim.j++;
		}
		dim.i++;
	}
	return (dim);
}

t_pathes	*newpath(t_puzzle *puzzle, char c)
{
	t_pathes	*path;
	t_dim		dimA;
	t_dim		dimZ;

	if (!(path = (t_pathes*)malloc(sizeof(t_pathes))))
		return (NULL);
	dimA = getdim(puzzle->now, c);
	dimZ = getdim(puzzle->end, c);
	path->up = (dimA.i - dimZ.i > 0) ? dimA.i - dimZ.i : 0;
	path->down = (dimZ.i - dimA.i > 0) ? dimZ.i - dimA.i : 0;
	path->left = (dimA.j - dimZ.j > 0) ? dimA.j - dimZ.j : 0;
	path->right = (dimZ.j - dimA.j > 0) ? dimZ.j - dimA.j : 0;
	path->total = path->up + path->down + path->left + path->right;
	return (path);
}

void	printpathes(t_pathes **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("[%d]-----\n", i + 1);
		printf("-UP    : %d\n", tab[i]->up); 
		printf("-DOWN  : %d\n", tab[i]->down); 
		printf("-LEFT  : %d\n", tab[i]->left); 
		printf("-RIGHT : %d\n", tab[i]->right);
		i++;
	}
}

t_puzzle	*npuzzle(t_puzzle *puzzle)
{
	t_pathes	**pathes;
	int			len;
	int			i;

	len = puzzle->len * puzzle->len;
	if (!(pathes = (t_pathes**)malloc(sizeof(t_pathes*) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (!(pathes[i] = newpath(puzzle, i + 1)))
			return (NULL); // DELPATHES
		i++;
	}
	pathes[i] = NULL;
	goforit(puzzle, pathes);
	return (puzzle);
}
