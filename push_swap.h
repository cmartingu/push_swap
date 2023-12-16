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

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				num;
	int				ideal_pos;
	struct s_list	*next;
}					t_list;

t_list	*parse_args(int argc, char *argv[]);
t_list	*ft_lstnew(int nb, int position);
t_list	*ft_lstlast(t_list *lst);
int		has_repeat(t_list *list);
int		check(t_list *stackA, t_list *stackB);
int		ft_lstsize(t_list *lst);
void	free_struct(t_list *list);
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
void	pick_positions(t_list **stackA);
int		check(t_list *stackA, t_list *stackB);
void	push_B(int nb, t_list **stackA, t_list **stackB);
void	principal(t_list **stackA);
int		cost_movs_aux(t_list **stackB);
int		cost_movs(int nb, t_list **stackB);
void	push_higher_up(t_list **stackB);
void	pick_cheap_a(t_list **stackA, t_list **stackB);
void	order_three(t_list **stackA);
int		higher_sb(t_list *stackB);
void	push_b_aux(t_list **stacka, t_list **stackb);
t_list	*new_num(char *argv[], int *i, int *j, t_list	**list);
t_list	*save_args(char *argv[], int *i, t_list *list);
void	last_part(t_list **stackA, t_list **stackB);
void	help_pb(int pos, t_list **stacka, t_list **stackb);
int		found_aux(int pos, t_list *aux, int nb_aux, int nb);
void	order_sb(t_list **aux, t_list **stackB, int pos, int nb);
void	push_b(int nb, t_list **stackA, t_list **stackB);

#endif
