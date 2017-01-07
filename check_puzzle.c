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

static	char *transform_puzzle(t_puzzle *npuz, char **puzzle)
{
	int	i;
	int	j;
	int	k;
	char	*solv;
	char	**end;

	npuz->len = ft_nbwords(*puzzle);
	if (!(npuz->now = (char**)malloc(sizeof(char*) * (npuz->len + 1))))
		return (NULL);
	if (!(end = (char**)malloc(sizeof(char*) * (npuz->len + 1))))
	{
		free(npuz->now);
		return (NULL);
	}
	if (!(solv = ft_strnew(npuz->len * npuz->len)))
	{
		free(npuz->now);
		free(end);
		return (NULL);
	}
	i = 0;
	while (i <= npuz->len)
	{
		npuz->now[i] = NULL;
		end[i++] = NULL;
	}
	i = 0;
	while (i < npuz->len)
	{
		if (!(npuz->now[i] = ft_strnew(npuz->len)))
		{
			ft_deltab(npuz->now);
			ft_deltab(end);
			return (NULL);
		}
		j = 0;
		k = 0;
		while (puzzle[i][j])
		{
			while (puzzle[i][j] == ' ' || puzzle[i][j] == '	')
				j++;
			if ((npuz->now[i][k] = ft_atoi(puzzle[i] + j)) == 0)
			{
				npuz->now[i][k] = npuz->len * npuz->len;
				if (!(npuz->blank = ft_newdim(i, k)))
					return (NULL);
			}
			k++;
			while (puzzle[i][j] && puzzle[i][j] != ' ' && puzzle[i][j] != '	')
				j++;
		}
		free(puzzle[i]);
		puzzle[i] = NULL;
		if (!(end[i] = ft_strdup(npuz->now[i])))
		{
			ft_deltab(end);
			ft_deltab(npuz->now);
			return (NULL);
		}
		i++;
	}
	set_end(end);
	free(puzzle);
	puzzle = NULL;
	return (solv);
}

t_puzzle	*fill_solv(t_puzzle *puzzle, char *solv, char **end)
{
	int		index;
	char	i;
	char	j;

	index = 0;
	i = 0;
	j = 0;
	while (index < (puzzle->len * puzzle->len))
	{
		while (end[i][j])
		{
			solv[index++] = end[i][j];
			end[i][j++] = '\0';
		}
		j--;
		i++;
		while (i < puzzle->len && end[i][j])
		{
			solv[index++] = end[i][j];
			end[i++][j] = '\0';
		}
		i--;
		j--;
		while (j >= 0 && end[i][j])
		{
			solv[index++] = end[i][j];
			end[i][j--] = '\0';
		}
		j++;
		i--;
		while (i >= 0 && end[i][j])
		{
			solv[index++] = end[i][j];
			end[i--][j] = '\0';
		}
		i++;
		j++;
	}
	return (puzzle);
}

int	is_solvable(t_puzzle *puzzle, char *solv, char **end)
{
	int	nb_invert;
	int	i;
	int	j;

	puzzle = fill_solv(puzzle, solv, end);
	i = 0;
	nb_invert = 0;
	while (solv[i])
	{
		if (solv[i] != (puzzle->len * puzzle->len))
		{
			j = i + 1;
			while (solv[j])
			{
				if (solv[i] > solv[j])
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
		while (solv[i] != (puzzle->len * puzzle->len))
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

static t_puzzle	*get_solved(t_puzzle *puzzle, char **end)
{
	int	i;
	int	j;
	int	value;

	i = 0;
	j = 0;
	value = 1;
	while (value <= puzzle->len * puzzle->len)
	{
		while (j < puzzle->len && !(end[i][j]))
			end[i][j++] = value++;
		j--;
		i++;
		while (i < puzzle->len && !(end[i][j]))
		{
			end[i++][j] = value++;
		}
		i--;
		j--;
		while (j >= 0 && (!end[i][j]))
		{
			end[i][j--] = value++;
		}
		j++;
		i--;
		while (i >= 0 && !(end[i][j]))
		{
			end[i--][j] = value++;
		}
		i++;
		j++;
	}
	return (puzzle);
}

t_puzzle	*check_puzzle(t_puzzle *npuz, char **puzzle)
{
	char	*solv;

	if (!(check_parsing(puzzle)))
	{
		ft_putendl_fd("npuzzle: Error in file format", 2);
		ft_deltab(puzzle);
		return (NULL);
	}
	if (!(solv = transform_puzzle(npuz, puzzle)))
	{
		ft_putendl_fd("npuzzle: Error in memory alllocation", 2);
		ft_deltab(puzzle);
		return (NULL);
	}
	if (!(is_solvable(npuz, solv, get_end())))
	{
		ft_putendl_fd("npuzzle: Impossible to solve this puzzle", 2);
		return (NULL);
	}
	npuz = get_solved(npuz, get_end());
	npuz->id_node = 0;
	npuz->score = -1;
	npuz->parent = NULL;
	npuz->next = NULL;
	npuz->link = NULL;
	npuz->prev = NULL;
	npuz->lastmove = '\0';
	return (npuz);
}
