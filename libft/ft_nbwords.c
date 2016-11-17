#include "libft.h"

int	ft_nbwords(char *str)
{
	int	nb;
	char	*ptr;

	nb = 0;
	ptr = str;
	if (ptr)
	{
		while (*ptr)
		{
			while (*ptr && (*ptr == ' ' || *ptr == '	'))
				ptr++;
			if (*ptr)
				nb++;
			while (*ptr && *ptr != ' ' && *ptr != '	')
				ptr++;
		}
	}
	return (nb);
}
