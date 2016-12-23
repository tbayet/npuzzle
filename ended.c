#include "npuzzle.h"

char	ended(t_puzzle *puzzle)
{
	char	i;
	char	j;

	i = 0;
	while (puzzle->now[i])
	{
		j = 0;
		while (puzzle->now[i][j])
		{
			if (puzzle->now[i][j] != puzzle->end[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
