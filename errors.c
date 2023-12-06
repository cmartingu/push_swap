/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-m <carlos-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:23:03 by carlos-m          #+#    #+#             */
/*   Updated: 2023/12/06 12:23:04 by carlos-m         ###   ########.fr       */
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

int	has_repeat(t_list *list)
{
	t_list	*aux;

	while (list->next)
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

t_list	*parse_args(int argc, char *argv[])
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
