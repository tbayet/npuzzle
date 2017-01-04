#include "npuzzle.h"

static char	**finalstate = NULL;

void	set_end(char **end)
{
	if (finalstate)
		ft_deltab(finalstate);
	finalstate = end;
}

char	**get_end(void)
{
	return (finalstate);
}

char		ended(t_puzzle *puzzle)
{
	char	i;
	char	j;

	if (finalstate)
	{
		i = 0;
		while (puzzle->now[i])
		{
			j = 0;
			while (puzzle->now[i][j])
			{
				if (puzzle->now[i][j] != finalstate[i][j])
					return (0);
				j++;
			}
			i++;
		}
	}
	return ((finalstate) ? 1 : 0);
}
