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

void	push_higher_up(t_list **stackB)
{
	int		nb;
	t_list	*aux;
	int		pos;

	aux = *stackB;
	nb = 0;
	while (aux != NULL)
	{
		if (aux->ideal_pos > nb)
			nb = aux->ideal_pos;
		aux = aux->next;
	}
	aux = *stackB;
	pos = 0;
	while (aux != NULL && aux->ideal_pos != nb)
	{
		pos++;
		aux = aux->next;
	}
	if (pos > (ft_lstsize(*stackB) - pos))
		while ((*stackB)->ideal_pos != higher_sb(*stackB))
			rrb(&*stackB);
	else
		while ((*stackB)->ideal_pos != higher_sb(*stackB))
			rb(&*stackB);
}

void	order_sb(t_list **aux, t_list **stackB, int pos, int nb)
{
	int	nb_aux;

	nb_aux = (*aux)->ideal_pos;
	(*aux) = (*aux)->next;
	while ((*aux) != NULL && ((*aux)->ideal_pos > nb && \
		(*aux)->ideal_pos < nb_aux))
	{
		pos++;
		nb_aux = (*aux)->ideal_pos;
		(*aux) = (*aux)->next;
	}
	if (pos > (ft_lstsize(*stackB) - pos))
	{
		pos = ft_lstsize(*stackB) - pos;
		while (pos--)
			rrb(&*stackB);
	}
	else
		while (pos--)
			rb(&*stackB);
}

void	push_b(int nb, t_list **stackA, t_list **stackB)
{
	t_list	*aux;
	int		pos;
	int		nb_aux;
	int		found;

	aux = *stackB;
	pos = 0;
	nb_aux = 0;
	found = 0;
	while (aux != NULL && found == 0)
	{
		if (aux->ideal_pos > nb)
		{
			nb_aux = aux->ideal_pos;
			found = 1;
		}
		pos++;
		if (found == 0)
			aux = aux->next;
	}
	if (nb_aux == 0)
		return (push_b_aux(&(*stackA), &(*stackB)));
	order_sb(&aux, &*stackB, pos, nb);
	pb(&*stackB, &*stackA);
}

int	find_cheap(t_list *aux, int cost, t_list **stacka, t_list **stackb)
{
	int	final_pos;
	int	pos;

	pos = 1;
	final_pos = 0;
	while (aux)
	{
		if (pos > (ft_lstsize(*stacka) - pos) && \
		((cost_movs(aux->ideal_pos, &*stackb) + \
		(ft_lstsize(*stacka) - pos)) < cost))
		{
			final_pos = pos;
			cost = (cost_movs(aux->ideal_pos, &*stackb) + \
			(ft_lstsize(*stacka) - pos));
		}
		else if ((cost_movs(aux->ideal_pos, &*stackb) + pos) < cost)
		{
			final_pos = pos;
			cost = (cost_movs(aux->ideal_pos, &*stackb) + pos);
		}
		pos++;
		aux = aux->next;
	}
	return (final_pos);
}

void	pick_cheap_a(t_list **stacka, t_list **stackb)
{
	t_list	*aux;
	int		final_pos;
	int		cost;

	aux = (*stacka);
	cost = cost_movs(aux->ideal_pos, &*stackb);
	aux = aux->next;
	final_pos = find_cheap(aux, cost, &*stacka, &*stackb);
	if (final_pos > (ft_lstsize(*stacka) - final_pos))
	{
		final_pos = ft_lstsize(*stacka) - final_pos;
		while (final_pos--)
			rra(&*stacka);
	}
	else
		while (final_pos--)
			ra(&*stacka);
}
