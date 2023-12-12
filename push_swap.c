/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-m <carlos-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:49:14 by carlos-m          #+#    #+#             */
/*   Updated: 2023/12/05 18:49:22 by carlos-m         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_list	*stackA;
	//t_list	*aux;

	if (argc <= 1)
		return (error_list(1), 0);
	stackA = parse_args(argc, argv);
	if (check(stackA, NULL) == 1)
		return (0);
	pick_positions(&stackA);
	try_check(&stackA);
	/*printf("\n\nStack A:\n");
	while (stackA)
	{
		printf("%d\n", stackA->num);
		if (stackA->next)
		{
			aux = stackA->next;
			free(stackA);
			stackA = aux;
		}
		else
			stackA = NULL;
	}*/
	return (0);
}
