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
	{
		sol = sol->next;
	}
	return (sol);
}

t_list	*ft_lstnew(int content)
{
	t_list	*sol;

	sol = malloc(sizeof(t_list));
	if (!sol)
		return (NULL);
	sol->content = content;
	sol->next = NULL;
	return (sol);
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
	int 	i;
	t_list	*list_num;
	t_list	*aux;
	t_list	*stackB;

	if (argc <= 1)
		return (error_list(1), 0);
	list_num = parse_args(argc, argv);
	stackB = ft_lstnew(4);
	ft_lstadd_back(&stackB, ft_lstnew(5));
	ft_lstadd_back(&stackB, ft_lstnew(6));
	//ft_lstadd_back(&stackB, ft_lstnew(8));
	//ft_lstadd_back(&stackB, ft_lstnew(9));
	//ft_lstadd_back(&stackB, ft_lstnew(10));
	pa(&list_num, &stackB);
	printf("Stack A:\n");
	while (list_num)
	{
		printf("%d\n", list_num->content);
		if (list_num->next)
		{
			aux = list_num->next;
			free(list_num);
			list_num = aux;
		}
		else
			list_num = NULL;
	}
	printf("\nStack B:\n");
	while (stackB)
	{
		printf("%d\n", stackB->content);
		if (stackB->next)
		{
			aux = stackB->next;
			free(stackB);
			stackB = aux;
		}
		else
			stackB = NULL;
	}
	return (0);
}
