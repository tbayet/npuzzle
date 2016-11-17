/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goforit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:10:31 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/17 19:28:42 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static t_dim	move(char **puzzle, t_pathes **pathes)
{
	
	return ();
}

void		goforit(t_puzzle *puzzle, t_pathes **pathes)
{
	int		turns;
	char	end;
	t_dim	moved;

	puzzle->blank = find_blank(puzzle->now);
	turns = 0;
	end = 0;
	while (!end)
	{
		moved = move(puzzle->now, pathes);
		turns++;
	}
}
