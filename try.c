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

void	pick_positions(t_list **stackA)
{
	t_list	*aux;
	t_list	*min_pos;
	int		pos;

	pos = 1;
	while (pos <= ft_lstsize(*stackA))
	{
		aux = *stackA;
		min_pos = *stackA;
		while (min_pos->ideal_pos != 0)
			min_pos = min_pos->next;
		while (aux != NULL)
		{
			if (aux->ideal_pos == 0 && aux->num < min_pos->num)
				min_pos = aux;
			aux = aux->next;
		}
		min_pos->ideal_pos = pos;
		pos++;
	}
}
void	higher_in_stack(t_list **stackA, t_list **stackB)
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
	while (aux != NULL)
	{
		if (aux->ideal_pos == nb)
			break ;
		pos++;
		aux = aux->next;
	}
	if (pos > (ft_lstsize(*stackB) - pos))
	{
		pos = ft_lstsize(*stackB) - pos;
		while (pos--)
			rrb(&*stackB);
	}
	else
	{
		while (pos--)
			rb(&*stackB);
	}
	pb(&*stackB, &*stackA);
}

int	higher_in_stack_aux(t_list **stackB)
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
	while (aux != NULL)
	{
		if (aux->ideal_pos == nb)
			break ;
		pos++;
		aux = aux->next;
	}
	if (pos > (ft_lstsize(*stackB) - pos))
		pos = ft_lstsize(*stackB) - pos;
	return (pos);
}

int	cost_movs(int nb, t_list **stackB)
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
		aux = aux->next;
	}
	if (nb_aux == 0)
		return (higher_in_stack_aux(&(*stackB)));
	found = 0;
	while (aux != NULL && found == 0)
	{
		if (aux->ideal_pos > nb && aux->ideal_pos < nb_aux)
		{
			pos++;
			nb_aux = aux->ideal_pos;
			aux = aux->next;
		}
		else
			found = 1;
	}
	if (pos > (ft_lstsize(*stackB) - pos))
		pos = ft_lstsize(*stackB) - pos;
	return (pos);
}

int	less_movs(t_list **stackB)
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
	while (aux != NULL)
	{
		if (aux->ideal_pos == nb)
			break ;
		pos++;
		aux = aux->next;
	}
	if (pos > (ft_lstsize(*stackB) - pos)) // hacerr rrb
		return (1);
	return (2); // hacer rb
}

void	pick_place(int nb, t_list **stackA, t_list **stackB)
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
		aux = aux->next;
	}
	if (nb_aux == 0)
	{
		higher_in_stack(&(*stackA), &(*stackB));
		return ;
	}
	found = 0;
	while (aux != NULL && found == 0)
	{
		if (aux->ideal_pos > nb && aux->ideal_pos < nb_aux)
		{
			pos++;
			nb_aux = aux->ideal_pos;
			aux = aux->next;
		}
		else
			found = 1;
	}
	if (pos > (ft_lstsize(*stackB) - pos))
	{
		pos = ft_lstsize(*stackB) - pos;
		while (pos--)
			rrb(&*stackB);
	}
	else
	{
		while (pos--)
			rb(&*stackB);
	}
	pb(&*stackB, &*stackA);
}

void    try_check(t_list **stackA)
{
	t_list	*stackB;

	stackB = ft_lstnew(0, 0);
	pb(&stackB, &*stackA);
	free(ft_lstlast(stackB));
	stackB->next = NULL;
	while (*stackA)
	{
		if ((*stackA)->next)
		{
			if (cost_movs(((*stackA)->next)->ideal_pos, &stackB) < cost_movs((*stackA)->ideal_pos, &stackB) && cost_movs(((*stackA)->next)->ideal_pos, &stackB) < cost_movs((ft_lstlast(*stackA))->ideal_pos, &stackB))
				sa(&*stackA);
			else  if (cost_movs((ft_lstlast(*stackA))->ideal_pos, &stackB) < cost_movs((*stackA)->ideal_pos, &stackB) && cost_movs((ft_lstlast(*stackA))->ideal_pos, &stackB) < cost_movs(((*stackA)->next)->ideal_pos, &stackB))
				rra(&*stackA);
		}
		pick_place((*stackA)->ideal_pos, &(*stackA), &stackB);
	}
	if (less_movs(&stackB) == 1)
	{
		while (stackB->ideal_pos != ft_lstsize(stackB))
			rrb(&stackB);
	}
	else
	{
		while (stackB->ideal_pos != ft_lstsize(stackB))
			rb(&stackB);
	}
	while (check(*stackA, stackB) != 1 && stackB != NULL)
		pa(&(*stackA), &stackB);
}
