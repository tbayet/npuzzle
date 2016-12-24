#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct		s_dim
{
	char			i;
	char			j;
}					t_dim;

/*typedef struct		s_choice
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
}					t_pathes; */

typedef struct		s_moves
{
	char		dir;
	struct s_moves	*next;
}			t_moves;

typedef struct		s_puzzle
{
	char			**now;
	char			**end;
	int				len;
	char			*solv;
	t_dim			*blank;
	t_moves			*moves;
}					t_puzzle;

typedef struct		s_grid
{
	char			*line;
	struct s_grid	*next;
}					t_grid;

t_puzzle			*npuzzle(t_puzzle *puzzle);
t_puzzle			*get_puzzle(char *file);
t_puzzle			*check_puzzle(t_puzzle *npuz, char **puzzle);
char			ended(t_puzzle *puzzle);
//void			printpathes(t_pathes **tab);
void			printpuzzle(char **puzzle);
t_dim				*ft_newdim(char i, char j);
t_dim				getdims(char **tab, char c);

#endif
