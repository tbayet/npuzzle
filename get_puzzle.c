#include "npuzzle.h"

static int	grid_len(t_grid *grid)
{
	int		len;
	t_grid	*tmp;

	len = 0;
	tmp = grid;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

static t_grid	*add_grid(t_grid **grid, char *line)
{
	t_grid	*new;
	t_grid	*tmp;

	if (!line)
		return (NULL);
	if (!(new = (t_grid*)malloc(sizeof(t_grid))))
	{
		free(line);
		return (NULL);
	}
	new->line = ft_strdup(line);
	new->next = NULL;
	if (!(*grid))
	{
		*grid = new;
		return (new);
	}
	tmp = *grid;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (*grid);
}

static char	**readfile(int fd)
{
	char	**now;
	t_grid	*grid;
	char	*line;
	int		gnl;
	t_grid	*tmp;
	int		len;

	gnl = 1;
	grid = NULL;
	while (gnl)
	{
		if ((gnl = get_next_line(fd, &line)))
		{
			if (gnl == -1 || !(add_grid(&grid, line)))
				return (NULL);//(del_grid(&grid));
			free(line);
		}
	}
	len = grid_len(grid);
	if (!(now = (char**)malloc(sizeof(char*) * (len + 1))))
	       return (NULL);
	now[len] = NULL;
	len = 0;
	tmp = grid;
	while (tmp)
	{
		now[len++] = tmp->line;
		tmp = tmp->next;
		free(grid);
		grid = tmp;
	}
	return (now);
}

t_puzzle	*get_puzzle(char *file)
{
	int			fd;
	t_puzzle	*puzzle;
	char		**filedc;

	if (!(fd = open(file, O_RDONLY)))
	{
		ft_putendl_fd("Error: can't open file", 2);
		return (NULL);
	}
	if (!(puzzle = (t_puzzle*)malloc(sizeof(t_puzzle))))
	{
		close(fd);
		ft_putendl_fd("Error: no space for memory allocation", 2);
		return (NULL);
	}
	filedc = readfile(fd);
	puzzle = check_puzzle(puzzle, filedc);
	close(fd);
	
	return (puzzle);
}
