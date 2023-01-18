/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:45:35 by svalente          #+#    #+#             */
/*   Updated: 2023/01/18 15:33:03 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_sa_pb(t_stack **stack_a, t_stack **stack_b);
static void	op_rra_rra_pb(t_stack **stack_a, t_stack **stack_b);

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int nb;
	
	nb = find_smallest_int(stack_a);
	if (lstsize(&stack_a) == 4)
	{
		if ((*stack_a)->content == nb)
			op_pb(stack_a, stack_b);
		else if ((*stack_a)->next->content == nb)
			op_sa_pb(stack_a, stack_b);
		else if ((*stack_a)->next->next->content == nb)
			op_rra_rra_pb(stack_a, stack_b);
		else if ((*stack_a)->next->next->next->content == nb)
			op_rra_pb(stack_a, stack_b);
	}
}

static void	op_sa_pb(t_stack **stack_a, t_stack **stack_b)
{
	op_sa(stack_a);
	op_pb(stack_a, stack_b);
}

static void	op_rra_rra_pb(t_stack **stack_a, t_stack **stack_b)
{
	op_rra(stack_a);
	op_rra(stack_a);
	op_pb(stack_a, stack_b);
}

static void	op_rra_pb(t_stack **stack_a, t_stack **stack_b)
{
	op_rra(stack_a);
	op_pb(stack_a, stack_b);
}