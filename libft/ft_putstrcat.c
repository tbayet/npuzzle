/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 20:07:32 by tbayet            #+#    #+#             */
/*   Updated: 2016/03/06 20:15:07 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstrcat(char *str, int start, int len)
{
	char	*tmp;

	if (str)
	{
		if (start >= 0 && len > 0 && len <= (int)ft_strlen(str))
		{
			tmp = str;
			str += start;
			write(1, str, len);
		}
	}
}
