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

void	error_list(int error)
{
	if (error == 0)
		write(1, "Error, invalid arguments", 24);
	else if (error == 1)
		write(1, "Error, no arguments entered", 27);
	else if (error == 2)
		write(1, "Error, repeated arguments", 25);
}

void	free_struct(t_list *list)
{
	t_list *aux;

	while (list)
	{
		aux = list->next;
		free(list);
		list = aux;
	}
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

int	has_repeat(t_list *list)//Comprobar de uno en uno si la lista tiene números repetidos
{
	t_list	*aux;

	while (list->next)// Comparar list->content con todos los aux hasta llegar al final y liego pasar a list->next y asi lo mismo
	{
		aux = list->next;
		while (aux)
		{
			if (list->content == aux->content)
				return (-1);
			aux = aux->next;
		}
		list = list->next;
	}
	return (1);
}

t_list *parse_args(int argc, char *argv[])
{
	t_list	*list;
	t_list	*aux;
	int		num;
	int		i;
	int		j;

	i = 1;
	list = ft_lstnew(0);
	while (argv[i])
	{
		j = 0;
		while (*(argv[i] + j))
		{
			if (*(argv[i] + j) >= '0' && *(argv[i] + j) <= '9')
			{
				num = 0 + (int){(*(argv[i] + j)) - '0'};
				j++;
				while (*(argv[i] + j) && *(argv[i] + j) >= '0' && *(argv[i] + j) <= '9')
				{
					num = (num * 10) + (int){(*(argv[i] + j)) - '0'};
					j++;
				}
				ft_lstadd_back(&list, ft_lstnew(num));
			}
			else if (*(argv[i] + j) == ' ')
				j++;
			else
				return (free_struct(list),error_list(0), NULL);
		}
		i++;
	}
	aux = list->next;
	free(list);
	if (has_repeat(aux) == -1)
		return (error_list(2), free_struct(aux), NULL);
	return (aux);
}

int	main(int argc, char *argv[])
{
	int 	i;
	t_list	*list_num;
	t_list	*aux;

	if (argc <= 1)
		return (error_list(1), 0);
	list_num = parse_args(argc, argv);
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
	return (0);
}
