/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-m <carlos-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:50:07 by carlos-m          #+#    #+#             */
/*   Updated: 2023/12/13 12:50:09 by carlos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_three(t_list **stackA)
{
	if ((*stackA)->ideal_pos > ((*stackA)->next)->ideal_pos && \
		((*stackA)->next)->ideal_pos > (ft_lstlast(*stackA))->ideal_pos)
	{
		sa(&*stackA);
		rra(&*stackA);
	}
	else if ((*stackA)->ideal_pos > (ft_lstlast(*stackA))->ideal_pos && \
		(ft_lstlast(*stackA))->ideal_pos > ((*stackA)->next)->ideal_pos)
		ra(&*stackA);
	else if (((*stackA)->next)->ideal_pos > (*stackA)->ideal_pos && \
		(*stackA)->ideal_pos > (ft_lstlast(*stackA))->ideal_pos)
		rra(&*stackA);
	else if ((ft_lstlast(*stackA))->ideal_pos > (*stackA)->ideal_pos && \
		(*stackA)->ideal_pos > ((*stackA)->next)->ideal_pos)
		sa(&*stackA);
	else if (((*stackA)->next)->ideal_pos > (ft_lstlast(*stackA))->ideal_pos && \
		(ft_lstlast(*stackA))->ideal_pos > (*stackA)->ideal_pos)
	{
		rra(&*stackA);
		sa(&*stackA);
	}
}

void	last_part(t_list **stackA, t_list **stackB)
{
	int	ordered;

	ordered = 0;
	while (check(*stackA, *stackB) != 1 && (*stackB) != NULL)
	{
		if ((ft_lstlast(*stackA))->ideal_pos > (*stackB)->ideal_pos && \
			ordered < 3)
		{
			ordered++;
			rra(&*stackA);
		}
		else
			pa(&(*stackA), &*stackB);
	}
	while ((ft_lstlast(*stackA))->ideal_pos < (*stackA)->ideal_pos)
		rra(&*stackA);
}

void	principal(t_list **stacka)
{
	t_list	*stackb;

	if (ft_lstsize(*stacka) == 3)
		return (order_three(&*stacka));
	stackb = ft_lstnew(0, 0);
	pb(&stackb, &*stacka);
	free(ft_lstlast(stackb));
	stackb->next = NULL;
	while (ft_lstsize(*stacka) != 3)
	{
		pick_cheap_a(&*stacka, &stackb);
		push_b((*stacka)->ideal_pos, &(*stacka), &stackb);
	}
	order_three(&*stacka);
	push_higher_up(&stackb);
	last_part(&*stacka, &stackb);
}

int	higher_sb(t_list *stackB)
{
	int		nb;
	t_list	*aux;

	aux = stackB;
	nb = 0;
	while (aux != NULL)
	{
		if (aux->ideal_pos > nb)
			nb = aux->ideal_pos;
		aux = aux->next;
	}
	return (nb);
}
