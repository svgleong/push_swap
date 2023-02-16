/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:15:49 by svalente          #+#    #+#             */
/*   Updated: 2023/02/16 16:12:32 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	sort_long(t_stack **stack_a, t_stack **stack_b)
{
	send_to_b(stack_a, stack_b);
}
 */

void	send_to_b(t_stack **stack_a, t_stack **stack_b)
{
	while (lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->content < find_mid_value(stack_a))
			op_pb(stack_a, stack_b);
		else
			op_ra(stack_a);
/* 		printf("stack_a:\t");
		print_list(*stack_a);
		printf("stack_b:\t");
		print_list(*stack_b); */
	}
	sort_3(stack_a);
}

t_stack	*best_neigh(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack *neighbour;
	double diff;
	
	temp = *stack_a;
	neighbour = *stack_a;
	diff = 3737373737;
	while (*stack_a)
	{
		if (subtract(stack_a, stack_b) < diff && subtract(stack_a, stack_b) > 0)
		{
			diff = subtract(stack_a, stack_b);
			neighbour = *stack_a;
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = temp;
	return (neighbour);
}

double	subtract(t_stack **stack_a, t_stack **stack_b)
{
	double value;
	
	if ((*stack_a)->content >= (*stack_b)->content)
		value = (*stack_a)->content - (*stack_b)->content;
	else
		value = (*stack_b)->content - (*stack_a)->content;
	return (value);
}