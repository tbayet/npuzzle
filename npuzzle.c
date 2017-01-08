#include "npuzzle.h"

int			get_node_len(t_puzzle *node)
{
	int			len;
	t_puzzle	*tmp;

	tmp = node;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = (tmp->next) ? tmp->next : tmp->link;
	}
	return (len);
}

void	printnode(t_puzzle *node)
{
	t_puzzle	*tmp;

	tmp = node;
	while (tmp)
	{
		printf("\nNODE ---%d---\n", tmp->id_node);
		printpuzzle(tmp->now);
		printf("**[%d]**\n", tmp->score);
		if (tmp->next)
			printf("<-NEXT->\n");
		else if (tmp->link)
			printf("<-LINK->\n");
		tmp = (tmp->next) ? tmp->next : tmp->link;
	}
}

void	printall(t_puzzle *puzzle)
{
	t_puzzle	*node;

	node = puzzle;
	printf("############## ALL ###################\n");
	while (node)
	{
	printf("########\n");
		printnode(node);
	printf("########\n");
		node = node->nextNode;
	}
	printf("############## ENDALL ###################\n");
}

t_puzzle	*npuzzle(t_puzzle *puzzle)
{
	t_puzzle	*tmp;
	t_puzzle	*first;
	pthread_t	*threads;
	int			len;
	int			i;

	first = puzzle;
	while (first->score != 6)
	{
		tmp = first;
		len = get_node_len(first);
		if (!(threads = (pthread_t*)malloc(sizeof(pthread_t) * len)))
			return (NULL);
		i = 0;
		while (i < len)
		{
			if (pthread_create(&threads[i++], NULL, create_sons, tmp))
			{
				i--;
				len--;
				create_sons(tmp);
			}
			tmp = (tmp->next) ? tmp->next : tmp->link;
		}
		while (--i >= 0)
			pthread_join(threads[i], NULL);
		free(threads);
		makelinks(first);
		first = find_and_close(puzzle, first->nextNode);
		printall(puzzle);
	}
	return (puzzle);
}
