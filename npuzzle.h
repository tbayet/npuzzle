#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_dim
{
	char			i;
	char			j;
}					t_dim;

typedef struct		s_choice
{
	char			up;
	char			right;
	char			left;
	char			down;
}					t_choice;

typedef struct		s_pathes
{
	char			up;
	char			right;
	char			left;
	char			down;
	int				total;
}					t_pathes;

typedef struct		s_puzzle
{
	char			**now;
	char			**end;
	int				len;
	char			*solv;
	t_dim			*blank;
}					t_puzzle;

typedef struct		s_grid
{
	char			*line;
	struct s_grid	*next;
}					t_grid;

t_puzzle			*npuzzle(t_puzzle *puzzle);
void				goforit(t_puzzle *puzzle, t_pathes **pathes);
t_puzzle			*get_puzzle(char *file);
t_puzzle			*check_puzzle(t_puzzle *npuz, char **puzzle);

void	printpuzzle(char **puzzle);

#endif
