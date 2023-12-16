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

void	free_struct(t_list *list)
{
	t_list	*aux;

	while (list)
	{
		aux = list->next;
		free(list);
		list = aux;
	}
}

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

int	has_repeat(t_list *list)
{
	t_list	*aux;

	while (list->next)
	{
		aux = list->next;
		while (aux)
		{
			if (list->num == aux->num)
				return (-1);
			aux = aux->next;
		}
		list = list->next;
	}
	return (1);
}

int	check(t_list *stackA, t_list *stackB)
{
	t_list	*aux;
	int		prev;

	if (stackB != NULL)
		return (-1);
	aux = stackA;
	prev = aux->num;
	while (aux)
	{
		if (aux->num < prev)
			return (-1);
		prev = aux->num;
		aux = aux->next;
	}
	return (1);
}

t_list	*new_num(char *argv[], int *i, int *j, t_list	**list)
{
	int		negativo;
	long	num;

	negativo = 0;
	if (*(argv[*i] + (*j)) == '-')
	{
		negativo = 1;
		(*j)++;
	}
	num = 0 + (long){(*(argv[*i] + (*j))) - '0'};
	(*j)++;
	while (*(argv[*i] + (*j)) && *(argv[*i] + (*j)) >= '0' && \
		*(argv[*i] + (*j)) <= '9')
	{
		num = (num * 10) + (long){(*(argv[*i] + (*j))) - '0'};
		(*j)++;
	}
	if ((*(argv[*i] + (*j)) != ' ' && *(argv[*i] + (*j)) != '\0') || \
		(num > 2147483647))
		return (free_struct(*list), write (2, "Error\n", 6), NULL);
	if (negativo == 1)
		num *= -1;
	if (num < -2147483648)
		return (free_struct(*list), write (2, "Error\n", 6), NULL);
	return (ft_lstadd_back(&*list, ft_lstnew(num, 0)), *list);
}
