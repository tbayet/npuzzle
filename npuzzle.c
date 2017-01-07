#include "npuzzle.h"

t_moves		*addmove(t_moves **moves, char dir)
{
	t_moves	*new;

	if (!(new = (t_moves*)malloc(sizeof(t_moves))))
		return (NULL);
	new->dir = dir;
	new->next = NULL;
	if (!(*moves))
		*moves = new;
	else
		(*moves)->next = new;
	return (new);
}

static void	see_valid_moves(t_puzzle *puzzle, char moves[4], t_moves *lastmove)
{
	int	i;
	int	j;
	int	index;

	index = 0;
	i = puzzle->blank->i;
	j = puzzle->blank->j;
	if ((!lastmove || lastmove->dir != 'D') && (i - 1 >= 0) && puzzle->now[i - 1][j])
		moves[index++] = 'U';
	if ((!lastmove || lastmove->dir != 'U') && (i + 1 < puzzle->len) && puzzle->now[i + 1][j])
		moves[index++] = 'D';
	if ((!lastmove || lastmove->dir != 'R') && (j - 1 >= 0) && puzzle->now[i][j - 1])
		moves[index++] = 'L';
	if ((!lastmove || lastmove->dir != 'L') && puzzle->now[i][j + 1])
		moves[index++] = 'R';
	while (index < 4)
		moves[index++] = '\0';
}


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

pthread_t	*start_thread(t_puzzle	*puzzle, void (*f))
{
	pthread_t *id_thread;

	id_thread = NULL;
	if (pthread_create(id_thread, NULL, f, puzzle) != 0)
		return (id_thread);
	return (NULL);
}


void		close_element(t_puzzle	*node)
{
	t_puzzle	*elem;
	
	printf("CLOSING ONE in %d...\n", node->id_node);
	elem = node;
	if (elem->id_node != 0)
	{
		if (elem->parent)
		{
			if (elem->next)
			{
				//Refaire le lien Parent->fils
				elem->parent->nextNode = elem->next;
				elem->next->parent = elem->parent;
				//refaire le lien freres
				elem->next->prev = elem->prev;
				if (elem->prev)
					elem->prev->link = elem->next;
			}
			else
			{
				if (elem->link)
					elem->link->prev = elem->prev;
				if (elem->prev)
					elem->prev->link = elem->link;
				close_element(elem->parent);
			}
		}
		else
		{
			if (elem->prev)
			{
				if (elem->next)
					elem->prev->next = elem->next;
				else
				{
					elem->prev->next = NULL;
					elem->prev->link = elem->link;
				}
			}
			if (elem->next)
				elem->next->prev = elem->prev;
			else if (elem->link)
				elem->link->prev = elem->prev;
		}
	}
//	tpuzzle_del(&elem);
}

t_puzzle	*find_and_close(t_puzzle *puzzle, t_puzzle *node)
{
	t_puzzle	*tmp;
	t_puzzle	*next;
	int			id_node;
	int			min;

	id_node = node->id_node;
	min = node->score;
	tmp = (node->next) ? node->next : node->link;
	while (tmp)
	{
		if (tmp->score < min)
			min = tmp->score;
		tmp = (tmp->next) ? tmp->next : tmp->link;
	}
	tmp = node;
	while (tmp)
	{
		next = (tmp->next) ? tmp->next : tmp->link;
		if (tmp->score > min)
			close_element(tmp);
		tmp = next;
	}
	tmp = puzzle;
	while (tmp->id_node != id_node)
	{
		printf("SEG - id_node[%d / %d]\n", tmp->id_node, id_node);
		tmp = tmp->nextNode;
	}
	return (tmp);
}

void		makelinks(t_puzzle *first)
{
	t_puzzle	*tmp;
	t_puzzle	*son1;
	t_puzzle	*son2;
	

	tmp = first;
	while (tmp->next || tmp->link)
	{
		son1 = tmp->nextNode;
		while (son1->next)
			son1 = son1->next;
		son2 = (tmp->next) ? tmp->next->nextNode : tmp->link->nextNode;
		son1->link = son2;
		son2->prev = son1;
		tmp = (tmp->next) ? tmp->next : tmp->link;
	}
}

void	printnode(t_puzzle *node)
{
	t_puzzle	*tmp;

	tmp = node;
	while (tmp)
	{
		printf("\nNODE ---%d---\n", tmp->id_node);
		printpuzzle(tmp->now);
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
	while (first->score)
	{
		tmp = first;
		printnode(first);
		len = get_node_len(first);
		if (!(threads = (pthread_t*)malloc(sizeof(pthread_t) * len)))
			return (NULL);
		i = 0;
		while (i < len)
		{
			pthread_create(&threads[i++], NULL, create_sons, tmp);
		//	threads[i++] = start_thread(tmp, create_sons);//pointeur fonction
			tmp = (tmp->next) ? tmp->next : tmp->link;
		}
		while (--i >= 0)
		{
			pthread_join(threads[i], NULL);
		}
		free(threads);
		sleep(1);
		//printf("len:[%d] \n", len, 
		makelinks(first);
		printf("=================beforeclose\n");
		printnode(first->nextNode);
		printf("=================before//===\n");
		first = find_and_close(puzzle, first->nextNode);
		printall(puzzle);
		//first = first->nextNode;
	}
	return (puzzle);
}
