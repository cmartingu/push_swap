/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-m <carlos-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:54:31 by carlos-m          #+#    #+#             */
/*   Updated: 2023/12/15 12:54:33 by carlos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*sol;

	sol = lst;
	if (sol == NULL)
		return (NULL);
	while (sol->next != NULL)
		sol = sol->next;
	return (sol);
}

t_list	*ft_lstnew(int nb, int position)
{
	t_list	*sol;

	sol = malloc(sizeof(t_list));
	if (!sol)
		return (NULL);
	sol->num = nb;
	sol->ideal_pos = position;
	sol->next = NULL;
	return (sol);
}

int	ft_lstsize(t_list *lst)
{
	int	cont;

	cont = 0;
	while (lst)
	{
		cont++;
		lst = lst->next;
	}
	return (cont);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!*lst)
		*lst = new;
	else
	{
		aux = *lst;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
