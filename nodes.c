#include "npuzzle.h"

static void	close_element(t_puzzle	*node)
{
	t_puzzle	*elem;
	
	printf("CLOSING ONE in %d...\n", node->id_node);
	elem = node;
	if (elem->id_node != 0)
	{
		if (elem->parent)
		{
			if (elem->prev)
				elem->prev->link = (elem->next) ? elem->next : elem->link;
			if (elem->next)
			{
				elem->parent->nextNode = elem->next;
				elem->next->parent = elem->parent;
				elem->next->prev = elem->prev;
			}
			else
			{
				if (elem->link)
					elem->link->prev = elem->prev;
				close_element(elem->parent);
			}
		}
		else
		{
			if (elem->prev)
			{
				elem->prev->next = elem->next;
				elem->prev->link = elem->link;
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
		min = (tmp->score < min) ? tmp->score : min;
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
		tmp = tmp->nextNode;
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
