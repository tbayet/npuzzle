#include "npuzzle.h"

static int	manhattan(t_puzzle *puzzle, char **table)
{
	int	res;
	t_dim	dim;
	t_dim	goal;
	char	**end;

	dim.i = 0;
	res = 0;
	end = get_end();
	while (dim.i < puzzle->len)
	{
		dim.j = 0;
		while (dim.j < puzzle->len)
		{
			if (table[dim.i][dim.j] != puzzle->len * puzzle->len)
			{
				goal = getdims(end, table[dim.i][dim.j]);
				res += ft_absolute(dim.i - goal.i) + ft_absolute(dim.j - goal.j);
			}
			dim.j++;
		}
		dim.i++;
	}
	return (res);
	
}

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
		if (i == len - 2)
		{
			if (solv[i] != len)
			{
				if (solv[i] + 1 != solv[0])
					res += 2;
			}
		}
		else if (i == len - 3 && solv[i + 1] == len)
		{
			if (solv[i] + 1 != solv[0])
				res += 2;
		}
		else if (solv[i + 1] == len && (i + 2) < len)
		{
			if (solv[i] + 1 != solv[i + 2])
				res += 2;
		}
		else if (solv[i] != len)
		{
			if (solv[i] + 1 != solv[i + 1])
				res += 2;
		}/*
		else if (solv[i + 1] == len)
				res += 2;*/
		i++;
	}
	res *= 3;
	res += manhattan(puzzle, table);
	return (res);
}

void	calcul_value(t_puzzle *puzzle, char **table, int *value)
{
	int		len;
	int		i;
	int		cpt;
	t_dim	pos;
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

static void		movepuzzle(t_puzzle *puzzle, char dir)
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

static t_puzzle	*new_son(char **tab, t_puzzle *daddy, char move, int value)
{
	t_dim		dim;
	t_puzzle	*son;

	if (!(son = (t_puzzle*)malloc(sizeof(t_puzzle))))
		return (NULL);
	son->now = tab;
	dim.i = (move == 'U') ? -1 : 0;
	if (move == 'D')
		dim.i = 1;
	dim.j = (move == 'L') ? -1 : 0;
	if (move == 'R')
		dim.j = 1;
	son->blank = ft_newdim(daddy->blank->i + dim.i, daddy->blank->j + dim.j);
	son->score = value;
	son->len = daddy->len;
	son->id_node = daddy->id_node + 1;
	son->lastmove = move;
	son->parent = (daddy->nextNode) ? NULL : daddy;
	son->nextNode = NULL;
	son->next = NULL;
	son->link = NULL;
	return (son);
}

t_puzzle		*add_son(t_puzzle *daddy, char **tab, char move, int value)
{
	t_puzzle	*tmp;
	t_dim		dim;

	if (!daddy->nextNode)
	{
		daddy->nextNode = new_son(tab, daddy, move, value);
		daddy->nextNode->prev = NULL;
	}
	else
	{
		tmp = daddy->nextNode;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_son(tab, daddy, move, value);
		tmp->next->prev = tmp;
	}
	return (daddy);
}
void	pickone(t_puzzle *puzzle, t_elems *el)
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
	i = 0;
	while (i < 4 && el->moves[i])
	{
		if (el->values[i] == min)
			add_son(puzzle, el->tabs[i], el->moves[i], el->values[i]);
		i++;
	}
}
