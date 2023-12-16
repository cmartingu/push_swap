/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-m <carlos-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:17:15 by carlos-m          #+#    #+#             */
/*   Updated: 2023/12/16 11:17:16 by carlos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	help_pb(int pos, t_list **stacka, t_list **stackb)
{
	if (pos > (ft_lstsize(*stackb) - pos))
	{
		pos = ft_lstsize(*stackb) - pos;
		while (pos--)
			rrb(&*stackb);
	}
	else
		while (pos--)
			rb(&*stackb);
	pb(&*stackb, &*stacka);
}

void	push_b_aux(t_list **stacka, t_list **stackb)
{
	int		nb;
	t_list	*aux;
	int		pos;

	aux = *stackb;
	nb = 0;
	while (aux != NULL)
	{
		if (aux->ideal_pos > nb)
			nb = aux->ideal_pos;
		aux = aux->next;
	}
	aux = *stackb;
	pos = 0;
	while (aux != NULL)
	{
		if (aux->ideal_pos == nb)
			break ;
		pos++;
		aux = aux->next;
	}
	help_pb(pos, &*stacka, &*stackb);
}

int	cost_movs_aux(t_list **stackB)
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

int	found_aux(int pos, t_list *aux, int nb_aux, int nb)
{
	int	found;

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
		return (cost_movs_aux(&(*stackB)));
	pos = found_aux(pos, aux, nb_aux, nb);
	if (pos > (ft_lstsize(*stackB) - pos))
		pos = ft_lstsize(*stackB) - pos;
	return (pos);
}
