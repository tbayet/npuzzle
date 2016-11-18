#include "npuzzle.h"

int	check_parsing(char **puzzle)
{
	int		len;
	char	**ptr;
	int		j;

	len = ft_nbwords(*puzzle);
	if (ft_tablen(puzzle) != len)
		return (0);
	ptr = puzzle;
	while (*ptr)
	{
		if (ft_nbwords(*ptr) != len)
			return (0);
		j = 0;
		while ((*ptr)[j])
		{
			while ((*ptr)[j] && ((*ptr)[j] == ' ' || (*ptr)[j] == '	'))
				j++;
			while ((*ptr)[j] && (*ptr)[j] != ' ' && (*ptr)[j] != '	')
			{
				if (!ft_isdigit((*ptr)[j]))
					return (0);
				j++;
			}
		}
		ptr++;
	}
	return (1);
}

static	t_puzzle *transform_puzzle(t_puzzle *npuz, char **puzzle)
{
	int	i;
	int	j;
	int	k;

	npuz->len = ft_nbwords(*puzzle);
	if (!(npuz->now = (char**)malloc(sizeof(char*) * (npuz->len + 1))))
		return (NULL);
	if (!(npuz->end = (char**)malloc(sizeof(char*) * (npuz->len + 1))))
	{
		free(npuz->now);
		return (NULL);
	}
	if (!(npuz->solv = ft_strnew(npuz->len * npuz->len)))
	{
		free(npuz->now);
		free(npuz->end);
		return (NULL);
	}
	i = 0;
	while (i <= npuz->len)
	{
		npuz->now[i] = NULL;
		npuz->end[i++] = NULL;
	}
	i = 0;
	while (i < npuz->len)
	{
		if (!(npuz->now[i] = ft_strnew(npuz->len)))
		{
			ft_deltab(npuz->now);
			ft_deltab(npuz->end);
			return (NULL);
		}
		j = 0;
		k = 0;
		while (puzzle[i][j])
		{
			while (puzzle[i][j] == ' ' || puzzle[i][j] == '	')
				j++;
			if ((npuz->now[i][k] = ft_atoi(puzzle[i] + j)) == 0)
				npuz->now[i][k] = npuz->len * npuz->len;
			k++;
			while (puzzle[i][j] && puzzle[i][j] != ' ' && puzzle[i][j] != '	')
				j++;
		}
		free(puzzle[i]);
		puzzle[i] = NULL;
		if (!(npuz->end[i] = ft_strdup(npuz->now[i])))
		{
			ft_deltab(npuz->end);
			ft_deltab(npuz->now);
			return (NULL);
		}
		i++;
	}
	free(puzzle);
	puzzle = NULL;
	return (npuz);
}

t_puzzle	*fill_solv(t_puzzle *puzzle, t_dim dim, char dir, int index)
{
	puzzle->solv[index] = puzzle->end[dim.i][dim.j];
	if (dir == 0)
	{
		if (puzzle->end[dim.i][dim.j + 1])
		{
			(dim.j)++;
			puzzle->end[dim.i][dim.j] = '\0';
			puzzle = fill_solv(puzzle, dim, dir, index + 1);
		}
		else
			dir++;
	}
	if (dir == 1)
	{
		if (dim.i + 1 < puzzle->len && puzzle->end[dim.i + 1][dim.j])
		{
			(dim.i)++;
			puzzle->end[dim.i][dim.j] = '\0';
			puzzle = fill_solv(puzzle, dim, dir, index + 1);
		}
		else
			dir++;
	}
	if (dir == 2)
	{
		if (dim.j - 1 >= 0 && puzzle->end[dim.i][dim.j - 1])
		{
			(dim.j)--;
			puzzle->end[dim.i][dim.j] = '\0';
			puzzle = fill_solv(puzzle, dim, dir, index + 1);
		}
		else
			dir++;
	}
	if (dir == 3)
	{
		if (dim.i - 1 >= 0 && puzzle->end[dim.i - 1][dim.j])
		{
			(dim.i)--;
			puzzle->end[dim.i][dim.j] = '\0';
			puzzle = fill_solv(puzzle, dim, dir, index + 1);
		}
		else
			puzzle = fill_solv(puzzle, dim, 0, index);
	}
	return (puzzle);
}

int	is_solvable(t_puzzle *puzzle)
{
	int	nb_invert;
	int	i;
	int	j;
	t_dim	dim;

	dim.i = 0;
	dim.j = 0;
	puzzle = fill_solv(puzzle, dim, 0, 0);
	i = 0;
	nb_invert = 0;
	while (puzzle->solv[i])
	{
		if (puzzle->solv[i] != (puzzle->len * puzzle->len))
		{
			j = i + 1;
			while (puzzle->solv[j])
			{
				if (puzzle->solv[i] > puzzle->solv[j])
					nb_invert++;
				j++;
			}
		}
		i++;
	}
	if (puzzle->len % 2 == 1)
	{
		if (nb_invert % 2 == 0)
			return (1);
	}
	else
	{
		i = 0;
		while (puzzle->solv[i] != (puzzle->len * puzzle->len))
			i++;
		if ((i / puzzle->len) % 2 == 0)
		{
			if (nb_invert % 2 == 1)
				return (1);
		}
		else
		{
			if (nb_invert % 2 == 0)
				return (1);
		}
	}
	return (0);
}

static t_puzzle	*get_solved(t_puzzle *puzzle, t_dim dim, char dir, int value)
{
	(puzzle->end)[dim.i][dim.j] = value;

	if (dir == 0)
	{
		if (dim.j + 1 < puzzle->len && puzzle->end[dim.i][dim.j + 1] == '\0')
		{
			(dim.j)++;
			puzzle = get_solved(puzzle, dim, dir, value + 1);
		}
		else
			dir++;
	}
	if (dir == 1)
	{
		if (dim.i + 1 < puzzle->len && puzzle->end[dim.i + 1][dim.j] == '\0')
		{
			(dim.i)++;
			puzzle = get_solved(puzzle, dim, dir, value + 1);
		}
		else
			dir++;
	}
	if (dir == 2)
	{
		if (dim.j - 1 >= 0 && puzzle->end[dim.i][dim.j - 1] == '\0')
		{
			(dim.j)--;
			puzzle = get_solved(puzzle, dim, dir, value + 1);
		}
		else
			dir++;
	}
	if (dir == 3)
	{
		if (dim.i - 1 >= 0 && puzzle->end[dim.i - 1][dim.j] == '\0')
		{
			(dim.i)--;
			puzzle = get_solved(puzzle, dim, dir, value + 1);
		}
		else
			puzzle = get_solved(puzzle, dim, 0, value);
	}
	return (puzzle);
}

t_puzzle	*check_puzzle(t_puzzle *npuz, char **puzzle)
{
	t_dim	dim;
	if (!(check_parsing(puzzle)))
	{
		ft_putendl_fd("npuzzle: Error in file format", 2);
		ft_deltab(puzzle);
		return (NULL);
	}
	if (!(npuz = transform_puzzle(npuz, puzzle)))
	{
		ft_putendl_fd("npuzzle: Error in memory alllocation", 2);
		ft_deltab(puzzle);
		return (NULL);
	}
	if (!(is_solvable(npuz)))
	{
		ft_putendl_fd("npuzzle: Impossible to solve this puzzle", 2);
	//	return (NULL);
	}
	dim.i = 0;
	dim.j = 0;
	npuz = get_solved(npuz, dim, 0, 1);
	return (npuz);
}
