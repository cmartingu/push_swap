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

int	check(t_list *stackA, t_list *stackB)
{
	t_list	*aux;
	int		nb;

	if (stackB != NULL)
		return (-1);
	aux = stackA;
	nb = aux->content;
	if (aux->next)
		aux = aux->next;
	while (aux != NULL)
	{
		if (aux->content < nb)
			return (-1);
		nb = aux->content;
		aux = aux->next;
	}
	return (1);
}

void	pick_lower_high(int nb, t_list **stackA, t_list **stackB)
{
	t_list	*aux;
	int		pos;
	int		nb_aux;

	aux = *stackB;
	pos = 0;
	nb_aux = 0;
	while (aux != NULL)
	{
		if (aux->content < nb && aux->content > nb_aux)
		{
			pos++;
			nb_aux = aux->content;
		}
		aux = aux->next;
	}
	while (pos--)
		rb(&*stackB);
	pb(&*stackB, &*stackA);
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
		if (aux->content > nb)
		{
			nb_aux = aux->content;
			found = 1;
		}
		if (found == 0)
		{
			pos++;
			aux = aux->next;
		}
	}
	if (nb_aux == 0)
	{
		pick_lower_high(nb, &(*stackA), &(*stackB));
		return ;
	}
	while (aux != NULL)
	{
		if (aux->content > nb && aux->content < nb_aux)
		{
			pos++;
			nb_aux = aux->content;
		}
		aux = aux->next;
	}
	while (pos--)
		rb(&*stackB);
	pb(&*stackB, &*stackA);
}

void    try_check(t_list **stackA)// stack numerado en posición ideal
{
	t_list	*stackB;
	int		ordered;

	stackB = ft_lstnew(0);
	ordered = 1;
	while ((*stackA)->content == ordered)
	{
		ra(&*stackA);
		ordered++;
	} // Aqui ya he bajado todos los que de primeras estén ordenados, el siguiente, si queda, si o si  está desordenado
	if (check(*stackA, stackB) == 1)
		return ;
	pb(&stackB, &*stackA);
	free(ft_lstlast(stackB));//Tengo el primer número que no iba ordenado del stackA en el B
	stackB->next = NULL;
	while (check(*stackA, stackB) != 1 && ordered <= (*stackA)->content)
	{
		if ((*stackA)->content == ordered)
		{
			ra(&*stackA);
			ordered++;
		}
		else
			pick_place((*stackA)->content, &(*stackA), &stackB);
	}//una vez salga de aquí o se ha ordenado de una o se han quedado unos ordenados en A y unos ordenados en B
	//2 opciones: 1-> Buscar el ordered en el stackB e ir haciendo pa() ra() 
	//			  2-> Buscar el máximo e ir empujándolo en orden(9, 8, 7...) hasta que no haya en el stackB y ya solo quedaría hacer
	//				  ra() o rra() hasta tener el stackA ordenado
	while (stackB->content != ordered)
		rb(&stackB);
	while (check(*stackA, stackB) != 1 && stackB != NULL)
	{
		pa(&(*stackA), &stackB);
		ra(&(*stackA));
	}
}
