/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdims.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:44:25 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/18 17:34:51 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "npuzzle.h"

t_dim	getdims(char **tab, char c)
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
