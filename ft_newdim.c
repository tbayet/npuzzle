#include "npuzzle.h"


t_dim	*ft_newdim(char i, char j)
{
	t_dim	*new;

	if (!(new = (t_dim*)malloc(sizeof(t_dim))))
		return (NULL);
	new->i = i;
	new->j = j;
	return (new);
}
