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

t_list	*save_args(char *argv[], int *i, t_list *list)
{
	int	j;

	j = 0;
	while (*(argv[*i] + j))
	{
		if (*(argv[*i] + j) == '-' && (*(argv[*i] + j + 1) <= '0' || \
			*(argv[*i] + j + 1) >= '9'))
			return (free_struct(list), write (2, "Error\n", 6), NULL);
		if ((*(argv[*i] + j) >= '0' && *(argv[*i] + j) <= '9') || \
			*(argv[*i] + j) == '-')
		{
			list = new_num(argv, &*i, &j, &list);
			if (!list)
				return (NULL);
		}
		else if (*(argv[*i] + j) == ' ')
			j++;
		else
			return (free_struct(list), write (2, "Error\n", 6), NULL);
	}
	return (list);
}

t_list	*parse_args(int argc, char *argv[])
{
	t_list	*list;
	t_list	*aux;
	int		i;

	i = 1;
	argc = 0;
	list = ft_lstnew(0, 0);
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (write (2, "Error\n", 6), free_struct(list), NULL);
		list = save_args(argv, &i, list);
		if (!list)
			return (NULL);
		i++;
	}
	aux = list->next;
	free(list);
	if (has_repeat(aux) == -1)
		return (write (2, "Error\n", 6), free_struct(aux), NULL);
	return (aux);
}

int	main(int argc, char *argv[])
{
	t_list	*stacka;

	if (argc <= 1)
		return (0);
	if (argv[1][0] == '\0')
		return (write (2, "Error\n", 6), 0);
	stacka = parse_args(argc, argv);
	if (!stacka)
		return (0);
	if (check(stacka, NULL) == 1)
		return (0);
	if (ft_lstsize(stacka) == 2)
		return (ra(&stacka), 0);
	pick_positions(&stacka);
	principal(&stacka);
	free_struct(stacka);
	return (0);
}
