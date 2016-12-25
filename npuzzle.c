#include "npuzzle.h"

t_moves		*addmove(t_moves **moves, char dir)
{
	t_moves	*new;

	if (!(new = (t_moves*)malloc(sizeof(t_moves))))
		return (NULL);
	new->dir = dir;
	new->next = NULL;
	if (!(*moves))
		*moves = new;
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
			init_as(el->ass[el->i], el->tabs[el->i], el->moves[el->i], &el->values[el->i]);
			el->ass[el->i]->puzzle = puzzle;
			pthread_create(&(el->pthread[el->i]), NULL, applythread, el->ass[el->i]);
			el->ass[el->i]->puzzle = puzzle;
			el->i++;
		}
		while (--(el->i) >= 0)
			pthread_join(el->pthread[el->i], NULL);
		lastmove = pickone(puzzle, el->values, el->moves, lastmove, el->tabs);
		printf("---[%d][%d][%d][%d]---\n", el->values[0], el->values[1], el->values[2], el->values[3]);
		printpuzzle(puzzle->now);
		printf("\n");
		sleep(1);
	}
	return (puzzle);
}
