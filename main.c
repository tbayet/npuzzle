#include "npuzzle.h"


void	printpuzzle(char **puzzle)
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
		}
	}
	else
		ft_putstr_fd("Function need 1 argument\n", 2);
	return (0);
}
