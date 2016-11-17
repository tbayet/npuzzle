/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabasep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:13:10 by tbayet            #+#    #+#             */
/*   Updated: 2016/03/06 15:53:47 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	ft_replacehex(char c)
{
	if (c >= 10 && c <= 15)
		return (c + 87);
	return (c + 48);
}

static int	get_itoalen(int nb, int base)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

static char	*itoastr(int nb, int *retsigne, int precision, int base)
{
	int		len;
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (precision + 1))))
		return (NULL);
	len = precision - (get_itoalen(nb, base) + retsigne[1]);
	while (precision > retsigne[1])
	{
		precision--;
		if (precision < len)
			res[precision] = '0';
		else
		{
			res[precision] = nb % base;
			if (retsigne[0])
			{
				res[precision] += 1;
				retsigne[0] = res[precision] / base;
				res[precision] %= base;
			}
			res[precision] = ft_replacehex(res[precision]);
			nb /= base;
		}
	}
	return (res);
}

char		*ft_itoabasep(int nb, unsigned int base, int precision)
{
	char	*res;
	int		retsigne[2];

	if (nb == 0)
		return (ft_strdup("0"));
	retsigne[0] = (nb == -2147483648) ? 1 : 0;
	if (retsigne[0])
		nb++;
	retsigne[1] = (nb >= 0) ? 0 : 1;
	if (retsigne[1])
		nb = -nb;
	if (!precision)
		precision = get_itoalen(nb, base) + retsigne[1];
	else if (precision < get_itoalen(nb, base) + retsigne[1])
		return (NULL);
	if (!(res = itoastr(nb, retsigne, precision, base)))
		return (NULL);
	res[precision] = '\0';
	if (retsigne[1])
		res[precision - (get_itoalen(nb, base) + retsigne[1])] = '-';
	return (res);
}
