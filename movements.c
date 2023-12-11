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

	aux = ft_lstnew((*stackA)->content);
	ft_lstadd_front(&(*stackB), aux);
	aux = (*stackA)->next;
	free(*stackA);
	*stackA = aux;
	write(1, "pb\n", 3);
}

void	ra(t_list **stackA)
{
	t_list	*aux;

	ft_lstadd_back(&(*stackA), ft_lstnew((*stackA)->content));
	aux = (*stackA)->next;
	free(*stackA);
	*stackA = aux;
	write(1, "ra\n", 3);
}

void	rb(t_list **stackB)
{
	t_list	*aux;

	ft_lstadd_back(&(*stackB), ft_lstnew((*stackB)->content));
	aux = (*stackB)->next;
	free(*stackB);
	*stackB = aux;
	write(1, "rb\n", 3);
}

void	rr(t_list **stackA, t_list **stackB)
{
	t_list	*aux;

	ft_lstadd_back(&(*stackA), ft_lstnew((*stackA)->content));
	aux = (*stackA)->next;
	free(*stackA);
	*stackA = aux;
	ft_lstadd_back(&(*stackB), ft_lstnew((*stackB)->content));
	aux = (*stackB)->next;
	free(*stackB);
	*stackB = aux;
	write(1, "rr\n", 3);
}

void	rra(t_list **stackA)
{
	t_list	*aux;

	aux = ft_lstnew(ft_lstlast(*stackA)->content);
	ft_lstadd_front(&(*stackA), aux);
	free(ft_lstlast(*stackA));
	write(1, "rra\n", 4);
}

void	rrb(t_list **stackB)
{
	t_list	*aux;

	aux = ft_lstnew(ft_lstlast(*stackB)->content);
	ft_lstadd_front(&(*stackB), aux);
	free(ft_lstlast(*stackB));
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stackA, t_list **stackB)
{
	t_list	*aux;

	aux = ft_lstnew(ft_lstlast(*stackA)->content);
	ft_lstadd_front(&(*stackA), aux);
	free(ft_lstlast(*stackA));
	aux = ft_lstnew(ft_lstlast(*stackB)->content);
	ft_lstadd_front(&(*stackB), aux);
	free(ft_lstlast(*stackB));
	write(1, "rrr\n", 4);
}
