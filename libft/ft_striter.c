/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:55:01 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/04 11:05:40 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int cpt;

	if (s && f)
	{
		cpt = 0;
		while (s[cpt] != '\0')
		{
			f(&s[cpt]);
			cpt++;
		}
	}
}
