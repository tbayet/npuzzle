#include "npuzzle.h"

t_puzzle		*tpuzzle_del(t_puzzle **puzzle)
{
	if (*puzzle)
	{
		ft_deltab((*puzzle)->now);
		if ((*puzzle)->blank)
			free((*puzzle)->blank);
		free(*puzzle);
		*puzzle = NULL;
	}
	return (NULL);
}

static t_puzzle	*tpuzzle_delnode(t_puzzle **node)
{
	t_puzzle	*tmp;
	t_puzzle	*next;

	tmp = *node;
	while (tmp)
	{
		next = (tmp->next) ? tmp->next : tmp->link;
		tpuzzle_del(&tmp);
		tmp = next;
	}
	*node = NULL;
	return (NULL);
}

t_puzzle		*tpuzzle_delall(t_puzzle **first)
{
	t_puzzle	*tmp;
	t_puzzle	*next;

	tmp = *first;
	while (tmp)
	{
		next = tmp->nextNode;
		tpuzzle_delnode(&tmp);
		tmp = next;
	}
	*first = NULL;
	return (NULL);
}
void		printpuzzle(char **puzzle)
{
	int	i;
	int	j;
	int	blank;

	i = 0;
	blank = ft_strlen(*puzzle) * ft_strlen(*puzzle);
	while (puzzle[i])
	{
		j = 0;
		while (puzzle[i][j])
		{
			if (puzzle[i][j] == blank)
				ft_putchar('*');
			else
				ft_putnbr(puzzle[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_puzzle	*puzzle;

	if (argc == 2)
	{
		if ((puzzle = get_puzzle(argv[1])))
		{
			printpuzzle(puzzle->now);
			ft_putstr("\n");
			npuzzle(puzzle);
			tpuzzle_delall(&puzzle);
		}
	}
	else
		ft_putstr_fd("Function need 1 argument\n", 2);
	return (0);
}
