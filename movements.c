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

void	sa(t_list *stackA)
{
	int	aux;

	aux = stackA->content;
	stackA->content = (stackA->next)->content;
	(stackA->next)->content = aux;
	write(1, "sa\n", 3);
}

void	sb(t_list *stackB)
{
	int	aux;

	aux = stackB->content;
	stackB->content = (stackB->next)->content;
	(stackB->next)->content = aux;
	write(1, "sb\n", 3);
}

void	ss(t_list *stackA, t_list *stackB)
{
	sa(stackA);
	sb(stackB);
}

void	pa(t_list **stackA, t_list **stackB)
{
	t_list	*aux;

	aux = ft_lstnew((*stackB)->content);
	ft_lstadd_front(&(*stackA), aux);
	aux = (*stackB)->next;
	free(*stackB);
	*stackB = aux;
}
