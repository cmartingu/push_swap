/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-m <carlos-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:29:15 by carlos-m          #+#    #+#             */
/*   Updated: 2023/12/06 12:29:17 by carlos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stackA)
{
	int	aux;
	int	aux_pos;

	aux = (*stackA)->num;
	aux_pos = (*stackA)->ideal_pos;
	(*stackA)->num = ((*stackA)->next)->num;
	(*stackA)->ideal_pos = ((*stackA)->next)->ideal_pos;
	((*stackA)->next)->num = aux;
	((*stackA)->next)->ideal_pos = aux_pos;
	write(1, "sa\n", 3);
}

void	sb(t_list *stackB)
{
	int	aux;

	aux = stackB->num;
	stackB->num = (stackB->next)->num;
	(stackB->next)->num = aux;
	write(1, "sb\n", 3);
}

void	ss(t_list *stackA, t_list *stackB)
{
	int	aux;

	aux = stackA->num;
	stackA->num = (stackA->next)->num;
	(stackA->next)->num = aux;
	aux = stackB->num;
	stackB->num = (stackB->next)->num;
	(stackB->next)->num = aux;
	write(1, "ss\n", 3);
}

void	pa(t_list **stackA, t_list **stackB)
{
	t_list	*aux;

	aux = ft_lstnew((*stackB)->num, (*stackB)->ideal_pos);
	ft_lstadd_front(&(*stackA), aux);
	if ((*stackB)->next)
	{
		aux = (*stackB)->next;
		free(*stackB);
		*stackB = aux;
	}
	else
	{
		free(*stackB);
		*stackB = NULL;
	}
	write(1, "pa\n", 3);
}

void	pb(t_list **stackB, t_list **stackA)
{
	t_list	*aux;

	aux = ft_lstnew((*stackA)->num, (*stackA)->ideal_pos);
	ft_lstadd_front(&(*stackB), aux);
	if ((*stackA)->next)
	{
		aux = (*stackA)->next;
		free(*stackA);
		*stackA = aux;
	}
	else
	{
		free(*stackA);
		*stackA = NULL;
	}
	write(1, "pb\n", 3);
}
