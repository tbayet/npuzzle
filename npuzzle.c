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

/** void	applythread(t_puzzle *puzzle, char **res, char dir)
{
	pid_t	*pid;

	pid = fork();
	
} **/

t_puzzle	*npuzzle(t_puzzle *puzzle)
{	
	char	**tabs[4];
	char	moves[4];
	int		i;
	t_moves	*lastmove;

	if (!(init_tabs(tabs, puzzle->len, 1)))
		return (NULL);
	lastmove = puzzle->moves;
	while (!ended(puzzle))
	{
		see_valid_moves(puzzle, moves, lastmove);
		i = 0;
		while (moves[i])
		{
		//	applythread(puzzle, tabs[i], moves[i]);
			i++;
		}
		init_tabs(tabs, puzzle->len, 0);
		break;
	}
	exit(0);
	return (puzzle);
}
