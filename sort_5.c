/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:45:35 by svalente          #+#    #+#             */
/*   Updated: 2023/01/19 17:31:30 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_pa_pa(t_stack **stack_a, t_stack **stack_b);

/* void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if (lstsize(&stack_a) % 5 == 0)
	{
		i = find_smallest_int(stack_a);
		if (i == 0)
			op_pb(stack_a, stack_b);
		if (i == 1)
			op_sa_pb(stack_a, stack_b);
		if (i == 2)
			op_ra_ra_pb(stack_a, stack_b);
		if (i == 3)
			op_rra_rra_pb(stack_a, stack_b);
		if (i == 4)
			op_rra_pb(stack_a, stack_b);
	}
	i = find_smallest_int(stack_a);
	if (lstsize(&stack_a) % 2 == 0)
	{
		if (i == 0)
			op_pb(stack_a, stack_b);
		if (i == 1)
			op_sa_pb(stack_a, stack_b);
		if (i == 2)
			op_rra_rra_pb(stack_a, stack_b);
		if (i == 3)
			op_rra_pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	op_pa(stack_a, stack_b);
	op_pa(stack_a, stack_b);
} */

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if (lstsize(*stack_a) == 5)
	{
		i = find_smallest_int(stack_a);
		if (i <= 2)
			while (i-- > 0)
				op_ra(stack_a);
		else
			while (i++ <= 4)
				op_rra(stack_a);
		op_pb(stack_a, stack_b);
	}
	if (lstsize(*stack_a) == 4)
	{
		i = find_smallest_int(stack_a);
		if (i == 1)
			op_ra(stack_a);
		else
			while (i++ <= 3)
				op_rra(stack_a);
		op_pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	op_pa_pa(stack_a, stack_b);
}

static void	op_pa_pa(t_stack **stack_a, t_stack **stack_b)
{
	op_pa(stack_a, stack_b);
	op_pa(stack_a, stack_b);
}
