/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 19:31:36 by tbayet            #+#    #+#             */
/*   Updated: 2016/03/22 19:49:18 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_putcolor_fd(char *str, char *color, int fd)
{
	if (ft_strcmp(color, "RED") == 0)
		ft_putstr_fd("\033[1;31m", fd);
	else if (ft_strcmp(color, "GREEN") == 0)
		ft_putstr_fd("\033[1;32m", fd);
	else if (ft_strcmp(color, "YELLOW") == 0)
		ft_putstr_fd("\033[1;33m", fd);
	else if (ft_strcmp(color, "BLUE") == 0)
		ft_putstr_fd("\033[1;34m", fd);
	else if (ft_strcmp(color, "MAGENTA") == 0)
		ft_putstr_fd("\033[1;35m", fd);
	else if (ft_strcmp(color, "CYAN") == 0)
		ft_putstr_fd("\033[1;36m", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\x1b[0m", fd);
}
