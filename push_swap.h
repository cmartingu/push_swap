/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-m <carlos-m@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:53:37 by carlos-m          #+#    #+#             */
/*   Updated: 2023/12/06 09:53:40 by carlos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct s_list
{
	int				num;
	int				ideal_pos;
	struct s_list	*next;
}					t_list;

t_list	*parse_args(int argc, char *argv[]);
t_list	*ft_lstnew(int nb, int position);
t_list	*ft_lstlast(t_list *lst);
int	has_repeat(t_list *list);
int	check(t_list *stackA, t_list *stackB);
int	ft_lstsize(t_list *lst);
void	free_struct(t_list *list);
void	error_list(int error);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	sa(t_list **stackA);
void	sb(t_list *stackB);
void	ss(t_list *stackA, t_list *stackB);
void	pa(t_list **stackA, t_list **stackB);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	pb(t_list **stackB, t_list **stackA);
void	ra(t_list **stackA);
void	rb(t_list **stackB);
void	rr(t_list **stackA, t_list **stackB);
void	rra(t_list **stackA);
void	rrb(t_list **stackB);
void	rrr(t_list **stackA, t_list **stackB);
void	pick_positions(t_list **stackA);
int		check(t_list *stackA, t_list *stackB);
void	pick_place(int nb, t_list **stackA, t_list **stackB);
void    try_check(t_list **stackA);
void	higher_in_stack(t_list **stackA, t_list **stackB);
int		less_movs(t_list **stackB);

#endif
