#ifndef NPUZZLE_H
# define NPUZZLE_H

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <pthread.h>
# include <limits.h>

typedef struct		s_dim
{
	int				i;
	int				j;
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
	char			dir;
	struct s_moves	*next;
}					t_moves;

/*
typedef struct		s_puzzle
{
	char			**now;
	char			**end;
	int				len;
	char			*solv;
	t_dim			*blank;
}					t_puzzle;
*/
typedef struct		s_puzzle
{
	char			**now;
	t_dim			*blank;
	int				score;
	int				len;
	int				id_node;
	char			lastmove;
	struct s_puzzle	*parent;
	struct s_puzzle	*nextNode;
	struct s_puzzle	*next;
	struct s_puzzle	*link;
	struct s_puzzle	*prev;

}					t_puzzle;

typedef struct		s_tdargs
{
	t_puzzle		*puzzle;
	int				*value;
	char			move;
	char			**tab;
}					t_tdargs;

typedef struct		s_elems
{
	int				values[4];
	char			moves[4];
	char			**tabs[4];
	pthread_t		pthread[4];
	t_tdargs		*ass[4];
	int				i;
}					t_elems;

typedef struct		s_grid
{
	char			*line;
	struct s_grid	*next;
}					t_grid;

t_puzzle			*npuzzle(t_puzzle *puzzle);
t_puzzle			*get_puzzle(char *file);
t_puzzle			*check_puzzle(t_puzzle *npuz, char **puzzle);
void				set_end(char **end);
char				**get_end(void);
char				ended(t_puzzle *puzzle);
//void				printpathes(t_pathes **tab);
void				printpuzzle(char **puzzle);
t_dim				*ft_newdim(char i, char j);
t_dim				getdims(char **tab, char c);
t_elems				*create_as(t_elems *el, t_puzzle *puzzle);
t_tdargs			*init_as(t_tdargs *as,  char **tab, char move, int *value);
void				*applythread(void *args);
char				**init_tabs(char **tabs[4], int len, char c);
void				pickone(t_puzzle *puzzle, t_elems *el);
void				calcul_value(t_puzzle *puzzle, char **table, int *value);
t_puzzle			*find_and_close(t_puzzle *puzzle, t_puzzle *node);
void				makelinks(t_puzzle *first);
void				*create_sons(void *voidpuz);
//t_moves				*addmove(t_moves **moves, char dir);
t_puzzle			*tpuzzle_del(t_puzzle **puzzle);
t_puzzle			*tpuzzle_delall(t_puzzle **first);
#endif
