/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:56:29 by svalente          #+#    #+#             */
/*   Updated: 2023/01/11 15:55:47 by svalente         ###   ########.fr       */
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

void	op_swap(t_list **head);
void	op_sa(t_list **stack_a);
void	op_sb(t_list **stack_b);
void	op_ss(t_list **stack_a, t_list **stack_b);
void	op_push(t_list **head1, t_list **head2);
void	op_pa(t_list **stack_a, t_list **stack_b);
void	op_pb(t_list **stack_a, t_list **stack_b);
void	op_rotate(t_list **head);
void	op_ra(t_list **stack_a);
void	op_rb(t_list **stack_b);
void	op_rr(t_list **stack_a, t_list **stack_b);
void	op_rev_rotate(t_list **head);
void	op_rra(t_list **stack_a);
void	op_rrb(t_list **stack_b);
void	op_rrr(t_list **stack_a, t_list **stack_b);

void	create_list(int ac, char **av, t_list *list);
long	ft_atol(const char *str);
bool	check_num(int ac, char **av);
bool	check_limits(int ac, char **av);
bool	check_dup(int ac, char **av);
bool	rules_checker(int ac, char **av);

#endif