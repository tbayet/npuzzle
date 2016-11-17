#include "npuzzle.h"


void	printpuzzle(char **puzzle)
{
	int	i;
	int	j;

	i = 0;
	while (puzzle[i])
	{
		j = 0;
		while (puzzle[i][j])
		{
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
			printpuzzle(puzzle->end);
			ft_putstr("\n");
			npuzzle(puzzle);
		}
	}
	else
		ft_putstr_fd("Function need 1 argument\n", 2);
	return (0);
}
