#include "npuzzle.h"

static void	see_valid_moves(t_puzzle *puzzle, char moves[4])
{
	int	i;
	int	j;
	int	index;

	index = 0;
	i = puzzle->blank->i;
	j = puzzle->blank->j;
	if (puzzle->lastmove != 'D' && (i - 1 >= 0) && puzzle->now[i - 1][j])
		moves[index++] = 'U';
	if (puzzle->lastmove != 'U' && (i + 1 < puzzle->len) && puzzle->now[i + 1][j])
		moves[index++] = 'D';
	if (puzzle->lastmove != 'R' && (j - 1 >= 0) && puzzle->now[i][j - 1])
		moves[index++] = 'L';
	if (puzzle->lastmove != 'L' && puzzle->now[i][j + 1])
		moves[index++] = 'R';
	while (index < 4)
		moves[index++] = '\0';
}

void	*create_sons(void *voidpuz)
{
	t_elems		*el;
	t_puzzle	*puzzle;

	puzzle = (t_puzzle*)voidpuz;
	el = (t_elems*)malloc(sizeof(t_elems));
	if (!(init_tabs(el->tabs, puzzle->len, 1)))
		return (NULL);
	create_as(el, puzzle);
	ft_bzero(el->values, 4);
	see_valid_moves(puzzle, el->moves);
	el->i = 0;
	while (el->i < 4 && el->moves[el->i])
	{
		init_as(el->ass[el->i], el->tabs[el->i], el->moves[el->i], &el->values[el->i]);
		el->ass[el->i]->puzzle = puzzle;
		if (pthread_create(&(el->pthread[el->i]), NULL, applythread, el->ass[el->i]))
			applythread(el->ass[el->i]);
		el->ass[el->i]->puzzle = puzzle;
		el->i++;
	}
	while (--(el->i) >= 0)
		pthread_join(el->pthread[el->i], NULL);
	pickone(puzzle, el);
	pthread_exit(NULL);
	return (puzzle);
}
