#include "npuzzle.h"

t_moves		*addmove(t_moves **moves, char dir)
{
	t_moves	*new;

	if (!(new = (t_moves*)malloc(sizeof(t_moves))))
		return (NULL);
	new->dir = dir;
	new->next = NULL;
	if (!(moves))
		moves = &new;
	else
		(*moves)->next = new;
	return (new);
}

static void	see_valid_moves(t_puzzle *puzzle, char moves[4], t_moves *lastmove)
{
	int	i;
	int	j;
	int	index;

	index = 0;
	i = puzzle->blank->i;
	j = puzzle->blank->j;
	if ((!lastmove || lastmove->dir != 'D') && (i - 1 >= 0) && puzzle->now[i - 1][j])
		moves[index++] = 'U';
	if ((!lastmove || lastmove->dir != 'U') && (i + 1 < puzzle->len) && puzzle->now[i + 1][j])
		moves[index++] = 'D';
	if ((!lastmove || lastmove->dir != 'R') && (j - 1 >= 0) && puzzle->now[i][j - 1])
		moves[index++] = 'L';
	if ((!lastmove || lastmove->dir != 'L') && puzzle->now[i][j + 1])
		moves[index++] = 'R';
	while (index < 4)
		moves[index++] = '\0';
}

static char	**init_tabs(char **tabs[4], int len, char c)
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

char	**applydir(t_puzzle *puzzle, char **res, t_dim dim)
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

int	manhattan(t_puzzle *puzzle, char **table)
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

int	algo_nilson(t_puzzle *puzzle, char *solv, char **table)
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
			if (solv[i] + 1 == solv[i + 1])
				res += 2;
		}
		i++;
	}
	res *= 3;
	res += manhattan(puzzle, table);
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
	while (len > 0)
	{
		cpt = len;
		while (cpt-- > 0 && printf("0[%d][%d]\n", pos.i, pos.j))
			solv[i++] = table[pos.i][++pos.j];
		cpt = --len;
		while (cpt-- > 0 && printf("1[%d][%d]\n", pos.i, pos.j))
			solv[i++] = table[++pos.i][pos.j];
		cpt = len;
		while (cpt-- > 0 && printf("2[%d][%d]\n", pos.i, pos.j))
			solv[i++] = table[pos.i][--pos.j];
		cpt = --len;
		while (cpt-- > 0 && printf("3[%d][%d]\n", pos.i, pos.j))
			solv[i++] = table[--pos.i][pos.j];
	}
	*value = algo_nilson(puzzle, solv, table);
	printf("TRUEvalue= [%d]\n", *value);
}

void	*applythread(void *args)
{
	t_dim	dim;
	t_tdargs	*as;

	as = (t_tdargs*)args;
	printf("OKforked\n");
	dim.i = (as->move == 'U') ? -1 : 0;
	if (as->move == 'D')
		dim.i = 1;
	dim.j = (as->move == 'L') ? -1 : 0;
	if (as->move == 'R')
		dim.j = 1;
	printf("OK\n");
	applydir(as->puzzle, as->tab, dim);
	calcul_value(as->puzzle, as->tab, as->value);
	printf("THENvalue= [%d]\n", *as->value);

	pthread_exit(NULL);
}

void	pickone(t_puzzle *puzzle, int values[4], char moves[4], t_moves *lastmove, char **tabs[4])
{
	int	i;

	i = 0;
	while (i < 4 && moves[i])
	{
		printf("-----DBRIEF-----\n");
		printpuzzle(tabs[i]);
		printf("--------------\n");
		printf("value: [%d], move [%c]\n\n", values[i], moves[i]);
		i++;
	}
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

t_puzzle	*npuzzle(t_puzzle *puzzle)
{
	t_tdargs	**as;
	t_elems		*el;
	t_moves		*lastmove;

	el = (t_elems*)malloc(sizeof(t_elems));
	if (!(init_tabs(el->tabs, puzzle->len, 1)))
		return (NULL);
	lastmove = puzzle->moves;
	create_as(el, puzzle);
	while (!ended(puzzle))
	{
		ft_bzero(el->values, 4);
		see_valid_moves(puzzle, el->moves, lastmove);
		el->i = 0;
		while (el->i < 4 && el->moves[el->i])
		{
	printf("SWAG\n");
			init_as(el->ass[el->i], el->tabs[el->i], el->moves[el->i], &el->values[el->i]);
	printf("SWAG\n");
			el->ass[el->i]->puzzle = puzzle;
	printf("--------SWAG\n");
			pthread_create(&(el->pthread[el->i]), NULL, applythread, el->ass[el->i]);
	printf("SfdggdfgWAG\n");
			el->ass[el->i]->puzzle = puzzle;
			el->i++;
		}
		while (--(el->i) >= 0)
		{
			pthread_join(el->pthread[el->i], NULL);
			printf("proc finished...\n");
		}
		pickone(puzzle, el->values, el->moves, lastmove, el->tabs);
		exit(0);
	}
	return (puzzle);
}
