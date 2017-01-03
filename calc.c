#include "npuzzle.h"

static int	manhattan(t_puzzle *puzzle, char **table)
{
	int	res;
	t_dim	dim;
	t_dim	goal;

	dim.i = 0;
	res = 0;
	while (dim.i < puzzle->len)
	{
		dim.j = 0;
		while (dim.j < puzzle->len)
		{
			if (table[dim.i][dim.j] != puzzle->len * puzzle->len)
			{
				goal = getdims(puzzle->end, table[dim.i][dim.j]);
				res += ft_absolute(dim.i - goal.i) + ft_absolute(dim.j - goal.j);
			}
			dim.j++;
		}
		dim.i++;
	}
	return (res);
	
}
#include <stdio.h>
static int	algo_nilson(t_puzzle *puzzle, char *solv, char **table)
{
	int	res;
	int	len;
	int	i;

	len = puzzle->len * puzzle->len;
	res = (solv[len - 1] != len) ? 1 : 0;
	i = 0;
	while (i < len && i + 1 < len)
	{
		if (solv[i] != len && solv[i + 1] != len)
		{
			if (solv[i] + 1 != solv[i + 1])
				res += 2;
		}
		i++;
	}
	printf("solv: [%d%d%d%d%d%d%d%d%d] Nilson: [%d]\n",solv[0], solv[1], solv[2], solv[3], solv[4], solv[5], solv[6], solv[7], solv[8], res);
	res *= 3;
	printf("Nilson*3: [%d]\n", res);
	res += manhattan(puzzle, table);
	printf(" + manhattan: [%d]\n", res);
	return (res);
}

void	calcul_value(t_puzzle *puzzle, char **table, int *value)
{
	int	len;
	int	i;
	t_dim	pos;
	int	cpt;
	char	*solv;

	len = puzzle->len;
	solv = ft_strnew(len * len); // protect
	pos.i = 0;
	pos.j = -1;
	i = 0;
	while (len > 0)
	{
		cpt = len;
		while (cpt-- > 0)
			solv[i++] = table[pos.i][++pos.j];
		cpt = --len;
		while (cpt-- > 0)
			solv[i++] = table[++pos.i][pos.j];
		cpt = len;
		while (cpt-- > 0)
			solv[i++] = table[pos.i][--pos.j];
		cpt = --len;
		while (cpt-- > 0)
			solv[i++] = table[--pos.i][pos.j];
	}
	*value = algo_nilson(puzzle, solv, table);
}

static void	movepuzzle(t_puzzle *puzzle, char dir)
{
	t_dim	dim;
	t_dim	*b;
	char	**res;
	char	c;

	dim.i = (dir == 'U') ? -1 : 0;
	if (dir == 'D')
		dim.i = 1;
	dim.j = (dir == 'L') ? -1 : 0;
	if (dir == 'R')
		dim.j = 1;
	b = puzzle->blank;
	res = puzzle->now;
	c = res[b->i][b->j];
	res[b->i][b->j] = res[b->i + dim.i][b->j + dim.j];
	res[b->i + dim.i][b->j + dim.j] = c;
	puzzle->blank->i += dim.i;
	puzzle->blank->j += dim.j;
}

t_moves	*pickone(t_puzzle *puzzle, t_elems *el, t_moves *lastmove)
{
	int	i;
	int	min;
	int	mini;

	i = 0;
	min = INT_MAX;
	while (i < 4 && el->moves[i])
	{
		if (el->values[i] < min)
		{
			min = el->values[i];
			mini = i;
		}
		i++;
	}
	movepuzzle(puzzle, el->moves[mini]);
	return (addmove(&lastmove, el->moves[mini]));
}
