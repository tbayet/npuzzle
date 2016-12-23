/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goforit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:10:31 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/22 17:45:35 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"
#include "limits.h"

static t_dim	*find_blank(char **puzzle, char c)
{
	t_dim	*blank;

	if (!(blank = (t_dim*)malloc(sizeof(t_dim))))
		return (NULL);
	blank->i = 0;
	while (puzzle[blank->i])
	{
		blank->j = 0;
		while (puzzle[blank->i][blank->j])
		{
			if (puzzle[blank->i][blank->j] == c)
				return (blank);
			(blank->j)++;
		}
		(blank->i)++;
	}
	free(blank);
	return (NULL);
}

static t_choice	find_min(t_choice choices, t_pathes **pathes, t_puzzle *puzzle, int max)
{
	int min;

	min = INT_MAX;

	if (choices.up == max)
	{
		if (pathes[puzzle->now[puzzle->blank->i - 1][puzzle->blank->j] - 1]->total < min)
			min = pathes[puzzle->now[puzzle->blank->i - 1][puzzle->blank->j] - 1]->total;
	}
	if (choices.down == max)
	{
		if (pathes[puzzle->now[puzzle->blank->i + 1][puzzle->blank->j] - 1]->total < min)
			min = pathes[puzzle->now[puzzle->blank->i + 1][puzzle->blank->j] - 1]->total;
	}
	if (choices.left == max)
	{
		if (pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j - 1] - 1]->total < min)
			min = pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j - 1] - 1]->total;
	}
	if (choices.right == max)
	{
		if (pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j + 1] - 1]->total < min)
			min = pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j + 1] - 1]->total;
	}

	if (choices.up == max)
	{
		if (pathes[puzzle->now[puzzle->blank->i - 1][puzzle->blank->j] - 1]->total == min)
			choices.up += 1;
	}
	if (choices.down == max)
	{
		if (pathes[puzzle->now[puzzle->blank->i + 1][puzzle->blank->j] - 1]->total == min)
			choices.down += 1;
	}
	if (choices.left == max)
	{
		if (pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j - 1] - 1]->total == min)
			choices.left += 1;
	}
	if (choices.right == max)
	{
		if (pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j + 1] - 1]->total == min)
			choices.right += 1;
	}
	return (choices);
}

static int	find_max(t_choice choices, char *eg)
{
	int max;

	max = -1;
	*eg = 0;
	*eg = (choices.up == max) ? *eg + 1: *eg;
	if (choices.up > max && (*eg = 1))
		max = choices.up;
	*eg = (choices.down == max) ? *eg + 1: *eg;
	if (choices.down > max && (*eg = 1))
		max = choices.down;
	*eg = (choices.left == max) ? *eg + 1: *eg;
	if (choices.left > max && (*eg = 1))
		max = choices.left;
	*eg = (choices.right == max) ? *eg + 1: *eg;
	if (choices.right > max && (*eg = 1))
		max = choices.right;
	return (max);
}

static t_dim	find_best_path(t_pathes **pathes, t_choice choices, t_dim moved, t_puzzle *puzzle)
{
	char	eg;
	int		max;
	int		blank;

	max = find_max(choices, &eg);
	blank = puzzle->len * puzzle->len - 1;
	if (eg > 1)
	{
		choices = find_min(choices, pathes, puzzle, max);
		max = find_max(choices, &eg);
		if (eg > 1)
		{
			choices.up += (choices.up == max && pathes[blank]->up) ? pathes[blank]->total : 0;
			choices.down += (choices.down == max && pathes[blank]->down) ? pathes[blank]->total : 0;
			choices.left += (choices.left == max && pathes[blank]->left) ? pathes[blank]->total : 0;
			choices.right += (choices.right == max && pathes[blank]->right) ? pathes[blank]->total : 0;
			max = find_max(choices, &eg);
		}
	}
	printf("EGALITE: %d | U[%d] D[%d] L[%d] R[%d]\n", eg, choices.up, choices.down, choices.left, choices.right);
	printf("BLANK *     | U[%d] D[%d] L[%d] R[%d]\n", pathes[blank]->up, pathes[blank]->down, pathes[blank]->left, pathes[blank]->right);
	moved.i = puzzle->blank->i;
	moved.j = puzzle->blank->j;
	if (choices.up == max)
	{
		(puzzle->blank->i)--;
		if (--(pathes[blank]->up) < 0)
		{
			pathes[blank]->up = 0;
			(pathes[blank]->down)++;
			(pathes[blank]->total)++;
		}
		else
			(pathes[blank]->total)--;
		if (--(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->down) < 0)
		{
			pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->down = 0;
			(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->up)++;
			(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->total)++;
		}
		else
			(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->total)--;
	}
	else if (choices.down == max)
	{
		(puzzle->blank->i)++;
		if (--(pathes[blank]->down) < 0)
		{
			pathes[blank]->down = 0;
			(pathes[blank]->up)++;
			(pathes[blank]->total)++;
		}
		else
			(pathes[blank]->total)--;
		if (--(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->up) < 0)
		{
			pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->up = 0;
			(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->down)++;
			(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->total)++;
		}
		else
			(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->total)--;
	}
	else if (choices.left == max)
	{
		(puzzle->blank->j)--;
		if (--(pathes[blank]->left) < 0)
		{
			pathes[blank]->left = 0;
			(pathes[blank]->right)++;
			(pathes[blank]->total)++;
		}
		else
			(pathes[blank]->total)--;
		if (--(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->right) < 0)
		{
			pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->right = 0;
			(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->left)++;
			(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->total)++;
		}
		else
			(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->total)--;
	}
	else if (choices.right == max)
	{
		(puzzle->blank->j)++;
		if (--(pathes[blank]->right) < 0)
		{
			pathes[blank]->right = 0;
			(pathes[blank]->left)++;
			(pathes[blank]->total)++;
		}
		else
			(pathes[blank]->total)--;
		if (--(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->left) < 0)
		{
			pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->left = 0;
			(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->right)++;
			(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->total)++;
		}
		else
			(pathes[puzzle->now[puzzle->blank->i][puzzle->blank->j] - 1]->total)--;
	}
	puzzle->now[moved.i][moved.j] = puzzle->now[puzzle->blank->i][puzzle->blank->j];
	puzzle->now[puzzle->blank->i][puzzle->blank->j] = blank + 1;
	return (moved);
}

static t_dim	move(t_puzzle *puzzle, t_pathes **pathes, t_dim moved)
{
	t_choice	choices;
	t_pathes	*path;
	char		**grid;
	t_dim		*bk;

	grid = puzzle->now;
	bk = puzzle->blank;
	choices.up = -1;
	choices.down = -1;
	choices.left = -1;
	choices.right = -1;
	if ((bk->i - 1) >= 0 && (bk->i - 1) != moved.i)
	{
		path = pathes[grid[bk->i - 1][bk->j] - 1];
		choices.up = (path->down) ? path->total : 0;
	}
	if ((bk->i + 1) < puzzle->len && (bk->i + 1) != moved.i)
	{
		path = pathes[grid[bk->i + 1][bk->j] - 1];
		choices.down = (path->up) ? path->total : 0;
	}
	if ((bk->j - 1) >= 0 && (bk->j - 1) != moved.j)
	{
		path = pathes[grid[bk->i][bk->j - 1] - 1];
		choices.left = (path->right) ? path->total : 0;
	}
	if ((bk->j + 1) < puzzle->len && (bk->j + 1) != moved.j)
	{
		path = pathes[grid[bk->i][bk->j + 1] - 1];
		choices.right = (path->left) ? path->total : 0;
	}
	moved = find_best_path(pathes, choices, moved, puzzle);
	return (moved);
}

char	ended(t_puzzle *puzzle)
{
	char	i;
	char	j;

	i = 0;
	while (puzzle->now[i])
	{
		j = 0;
		while (puzzle->now[i][j])
		{
			if (puzzle->now[i][j] != puzzle->end[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		goforit(t_puzzle *puzzle, t_pathes **pathes)
{
	int		turns;
	char	end;
	t_dim	moved;

	puzzle->blank = find_blank(puzzle->now, puzzle->len * puzzle->len);
	turns = 0;
	end = 0;
	while (!end)
	{
		if (!(end = ended(puzzle)))
		{
			printpuzzle(puzzle->now);
			moved = move(puzzle, pathes, moved);
			turns++;
			ft_putchar('\n');
		}
	}
	ft_putnbr(turns);
	ft_putendl(" tours.");
}
