/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_midpoint_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:18:22 by svalente          #+#    #+#             */
/*   Updated: 2023/01/27 17:15:50 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_midpoint_value_a(t_stack **stack)
{
	int mid;
	int counter;
	int value;

	mid = lstsize(*stack) / 2;
	counter = 0;
	value = value_smallest_int(stack);
/* 	printf("smallest value: [%d]\n", value); */
	while (counter < mid)
	{
		value = find_next_smallest(value, stack);
/* 		printf("next smallest value: [%d]\n", value); */
		counter++;
/* 		printf("counter: [%d]\n", counter); */
	}
	return (value);
}

int	send_until_mid_a(t_stack **stack_a, t_stack **stack_b)
{
	int	midpoint;
	int	chunk_size;
	int	value;

	midpoint = find_midpoint_value_a(stack_a);
	chunk_size = lstsize(*stack_a) / 2;
	value = 0;
	while (*stack_a && value < chunk_size)
	{
		if ((*stack_a)->content < midpoint)
		{
			op_pb(stack_a, stack_b);
			value++;
		}
		if ((*stack_a)->content >= midpoint)
		{
			if (value_at_last(stack_a) < midpoint)
				op_rra(stack_a);
			if (*stack_a && (*stack_a)->content >= midpoint)
				op_ra(stack_a);
		}
	}
	return (value);
}

int	value_smallest_int(t_stack **stack)
{
	int 	i;
	int 	j;
	int 	nb;
	t_stack *temp;

	i = find_smallest_int(stack);
	j = 0;
	nb = 0;
	temp = *stack;
	while (temp->next && j < i)
	{
		temp = temp->next;
		j++;
	}
	nb = temp->content;
	return (nb);
}

int	value_at_last(t_stack **stack)
{
	int 	value;
	t_stack	*temp;

	value = 0;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	value = temp->content;
	return (value);
}