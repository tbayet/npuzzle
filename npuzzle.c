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
	solv = ft_strnew(len); // protect
	cpt = len;
	pos.i = 0;
	pos.j = 0;
	while (len)
	{
		while (cpt--)
			solv[i++] = table[pos.i][pos.j++];
		cpt = --len;
		while (cpt--)
			solv[i++] = table[pos.i++][pos.j];
		while (cpt--)
			solv[i++] = table[pos.i][pos.j--];
		cpt = --len;
		while (cpt--)
			solv[i++] = table[pos.i--][pos.j];
	}
	*value = algo_nilson(puzzle, solv, table);
}

int	applythread(t_puzzle *puzzle, char **res, int *value, char dir)
{
	pid_t	pid;
	t_dim	dim;

	pid = fork();
	sleep(3);
	printf("[%d]\n", pid);
	if (pid == 0)
	{
		printf("FILS\n");
		dim.i = (dir == 'U') ? -1 : 0;
		if (dir == 'D')
			dim.i = 1;
		dim.j = (dir == 'L') ? -1 : 0;
		if (dir == 'R')
			dim.j = 1;
		res = applydir(puzzle, res, dim);
		calcul_value(puzzle, res, value);
		exit(2);
	}
	else
		printf("PERE\n");
	return (pid);
}

t_puzzle	*npuzzle(t_puzzle *puzzle)
{	
	char	**tabs[4];
	char	moves[4];
	int	values[4];
	int		i;
	t_moves	*lastmove;

	if (!(init_tabs(tabs, puzzle->len, 1)))
		return (NULL);
	lastmove = puzzle->moves;
	while (!ended(puzzle))
	{
		ft_bzero(values, 4);
		see_valid_moves(puzzle, moves, lastmove);
		i = 0;
		while (i < 4 && moves[i])
		{
			if (applythread(puzzle, tabs[i], &values[i],  moves[i]) == 0)
				printf("WTFDUDE\n");
			printf("i = [%d]\n", i);
			i++;
		}
		printf("YOLO\n");
		while (i-- > 0)
			wait(0);
		printf("O_O WOW\n");
	}
	exit(0);
	return (puzzle);
}
