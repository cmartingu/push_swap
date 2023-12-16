/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-m <carlos-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:14:41 by carlos-m          #+#    #+#             */
/*   Updated: 2023/12/15 16:14:42 by carlos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stackA)
{
	t_list	*aux;

	ft_lstadd_back(&(*stackA), ft_lstnew((*stackA)->num, (*stackA)->ideal_pos));
	aux = (*stackA)->next;
	free(*stackA);
	*stackA = aux;
	write(1, "ra\n", 3);
}

void	rb(t_list **stackB)
{
	t_list	*aux;

	ft_lstadd_back(&(*stackB), ft_lstnew((*stackB)->num, (*stackB)->ideal_pos));
	aux = (*stackB)->next;
	free(*stackB);
	*stackB = aux;
	write(1, "rb\n", 3);
}

void	rr(t_list **stackA, t_list **stackB)
{
	t_list	*aux;

	ft_lstadd_back(&(*stackA), ft_lstnew((*stackA)->num, (*stackA)->ideal_pos));
	aux = (*stackA)->next;
	free(*stackA);
	*stackA = aux;
	ft_lstadd_back(&(*stackB), ft_lstnew((*stackB)->num, (*stackB)->ideal_pos));
	aux = (*stackB)->next;
	free(*stackB);
	*stackB = aux;
	write(1, "rr\n", 3);
}

void	rra(t_list **stackA)
{
	t_list	*aux;
	t_list	*aux2;

	aux2 = ft_lstlast(*stackA);
	aux = ft_lstnew(aux2->num, aux2->ideal_pos);
	ft_lstadd_front(&(*stackA), aux);
	while (aux->next != aux2)
		aux = aux->next;
	free(aux2);
	aux->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stackB)
{
	t_list	*aux;
	t_list	*aux2;

	aux2 = ft_lstlast(*stackB);
	aux = ft_lstnew(aux2->num, aux2->ideal_pos);
	ft_lstadd_front(&(*stackB), aux);
	while (aux->next != aux2)
		aux = aux->next;
	free(aux2);
	aux->next = NULL;
	write(1, "rrb\n", 4);
}
