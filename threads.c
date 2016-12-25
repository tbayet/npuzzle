#include "npuzzle.h"

char	**init_tabs(char **tabs[4], int len, char c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (c)
		{
			if (!(tabs[i++] = ft_tabnew(len, len)))
				return (NULL);
		}
		else
			ft_tabzero(tabs[i++], len, len);
	}
	return (tabs[0]);
}

static char	**applydir(t_puzzle *puzzle, char **res, t_dim dim)
{
	int	i;
	char	c;
	t_dim	*b;

	i = 0;
	while (i < puzzle->len)
	{
		res[i] = ft_strcpy(res[i], puzzle->now[i]);
		i++;
	}
	b = puzzle->blank;
	c = res[b->i][b->j];
	res[b->i][b->j] = res[b->i + dim.i][b->j + dim.j];
	res[b->i + dim.i][b->j + dim.j] = c;
	return (res);
}

void		*applythread(void *args)
{
	t_dim	dim;
	t_tdargs	*as;

	as = (t_tdargs*)args;
	dim.i = (as->move == 'U') ? -1 : 0;
	if (as->move == 'D')
		dim.i = 1;
	dim.j = (as->move == 'L') ? -1 : 0;
	if (as->move == 'R')
		dim.j = 1;
	applydir(as->puzzle, as->tab, dim);
	calcul_value(as->puzzle, as->tab, as->value);
	pthread_exit(NULL);
}

t_elems		*create_as(t_elems *el, t_puzzle *puzzle)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!(el->ass[i] = (t_tdargs*)malloc(sizeof(t_tdargs))))
			return (NULL);
		el->ass[i]->puzzle = puzzle;
		i++;
	}
	return (el);
}

t_tdargs	*init_as(t_tdargs *as,  char **tab, char move, int *value)
{
	as->tab = tab;
	as->move = move;
	as->value = value;
	return (as);
}
