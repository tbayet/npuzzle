#include "npuzzle.h"

int	misplaced(t_puzzle *puzzle, char **end)
{
	int		i;
	int		j;
	int		nb;
	char	**now;

	nb = 0;
	now = puzzle->now;
	i = 0;
	while (i < puzzle->len)
	{
		j = 0;
		while (j < puzzle->len)
		{
			if (now[i][j] != end[i][j])
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
}

int permutations(char *sort)
{
	int	nb;
	int	len;
	int	i;
	int	j;

	len = ft_strlen(sort);
	nb = 0;
	i = 0;
	while (i < len)
	{
		if (sort[i] != len)
		{
			j = i + 1;
			while (j < len)
			{
				if (sort[j] != len && sort[i] > sort[j])
					nb++;
				j++;
			}
		}
		i++;
	}
	return (nb);
}

int	tilesout(t_puzzle *puzzle, char **end)
{
	int		nb;
	char	**now;
	t_dim	n;
	t_dim	e;

	nb = 0;
	now = puzzle->now;
	n.i = 0;
	while (n.i < puzzle->len)
	{
		n.j = 0;
		while (n.j < puzzle->len)
		{
			if (now[n.i][n.j] != puzzle->len)
			{
				e = n;
				nb -= (puzzle->len - 1);
				e.i = 0;
				while (e.i < puzzle->len)
				{
					if (now[n.i][n.j] != end[e.i++][e.j])
						nb++;
				}
				e = n;
				nb -= (puzzle->len - 1);
				e.j = 0;
				while (e.j < puzzle->len)
				{
					if (now[n.i][n.j] != end[e.i][e.j++])
						nb++;
				}
			}
			n.j++;
		}
		n.i++;
	}
	return (nb);
}
