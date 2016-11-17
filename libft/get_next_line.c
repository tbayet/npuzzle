/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:35:29 by tbayet            #+#    #+#             */
/*   Updated: 2016/04/06 19:40:41 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static t_save	*init_newsave(int const fd)
{
	t_save	*new;

	if (!(new = (t_save*)malloc(sizeof(t_save))))
		return (NULL);
	new->content = NULL;
	if (!(new->content = ft_strrealloc(new->content, BUFF_SIZE)))
	{
		free(new);
		return (NULL);
	}
	new->fd = fd;
	new->next = NULL;
	new->eof = 0;
	return (new);
}

static t_save	*get_save(t_save **lstsave, int const fd)
{
	t_save	*tmp;
	t_save	*new;

	if (!(new = init_newsave(fd)))
		return (NULL);
	if (*lstsave)
	{
		tmp = *lstsave;
		while (tmp)
		{
			if (tmp->fd == fd)
			{
				free(new->content);
				free(new);
				return (tmp);
			}
			tmp = tmp->next;
		}
		new->next = *lstsave;
	}
	*lstsave = new;
	return (new);
}

static int		ft_transfer(t_save **save, char **line)
{
	int	i;

	if ((*save)->content[0])
	{
		i = 0;
		while ((*save)->content[i] != '\0' && (*save)->content[i] != '\n')
			i++;
		if (!(*line = ft_strrealloc(*line, i)))
			return (-1);
		*line = ft_strncat(*line, (*save)->content, i);
		if ((*save)->content[i] == '\n')
		{
			(*save)->content = ft_strcut((*save)->content, i + 1);
			return (1);
		}
		(*save)->content = ft_strcut((*save)->content, i + 1);
	}
	return (0);
}

static int		gnl_read(t_save **save, char **line)
{
	int	ret;
	int	readerr;

	ret = 1;
	while ((*save)->eof < 1 && ret > 0
			&& ((ret = read((*save)->fd, (*save)->content, BUFF_SIZE)) > 0))
	{
		(*save)->content[ret] = '\0';
		if (ret < BUFF_SIZE)
			(*save)->eof = 1;
		if ((readerr = ft_transfer(save, line)) > 0)
			ret = -42;
		else if (readerr == -1)
			ret = -1;
	}
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static t_save	*lstsave = NULL;
	t_save			*save;
	int				ret;

	if (!line)
		return (-1);
	*line = NULL;
	if (!(save = get_save(&lstsave, fd)))
		return (-1);
	if (((ret = ft_transfer(&save, line)) + 1) < 1)
		return (-1);
	if (ret < 1 && save->eof < 1)
	{
		ret = gnl_read(&save, line);
		if (ret == -1 || ret == 0)
		{
			if (ret == 0 && *line)
				ret = 1;
			ft_lstdelthis(&lstsave, save);
			return (ret);
		}
	}
	if (!save->content[0] && save->eof > 0)
		ft_lstdelthis(&lstsave, save);
	return (1);
}
