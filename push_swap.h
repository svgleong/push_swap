/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:56:29 by svalente          #+#    #+#             */
/*   Updated: 2023/01/19 16:27:19 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

void	print_list(t_stack *lst);

void	op_swap(t_stack **head);
void	op_sa(t_stack **stack_a);
void	op_sb(t_stack **stack_b);
void	op_ss(t_stack **stack_a, t_stack **stack_b);
void	op_push(t_stack **head1, t_stack **head2);
void	op_pa(t_stack **stack_a, t_stack **stack_b);
void	op_pb(t_stack **stack_a, t_stack **stack_b);
void	op_rotate(t_stack **head);
void	op_ra(t_stack **stack_a);
void	op_rb(t_stack **stack_b);
void	op_rr(t_stack **stack_a, t_stack **stack_b);
void	op_rev_rotate(t_stack **head);
void	op_rra(t_stack **stack_a);
void	op_rrb(t_stack **stack_b);
void	op_rrr(t_stack **stack_a, t_stack **stack_b);

void	create_list(int ac, char **av, t_stack **list);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
bool	check_num(int ac, char **av);
bool	check_limits(int ac, char **av);
bool	check_dup(int ac, char **av);
bool	rules_checker(int ac, char **av);

int		lstsize(t_stack *lst);
int		find_smallest_int(t_stack **stack);
void	sort_3(t_stack **stack_a);
void	sort_5(t_stack **stack_a, t_stack **stack_b);

#endif