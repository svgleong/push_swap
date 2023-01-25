/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_midpoint_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:45:36 by svalente          #+#    #+#             */
/*   Updated: 2023/01/25 00:07:41 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_in_chunk(t_stack **stack, int chunk_size)
{
	int counter;
	int nb;
	t_stack	*temp;

	counter = 0;
	nb = (*stack)->content;
	while((*stack)->next && counter < chunk_size)
	{
		if (nb > (*stack)->next->content)
			nb = (*stack)->next->content;
		counter++;
		*stack = (*stack)->next;
	}
	*stack = temp;
	return (nb);
}

int	find_midpoint_value_b(t_stack **stack, int chunk_size)
{
	int counter;
	int value;

	counter = 0;
	value = find_smallest_in_chunk(stack, chunk_size);
	while (counter < chunk_size / 2)
	{
		value = find_next_smallest(value, stack);
/* 		printf("next smallest value: [%d]\n", value); */
		counter++;
/* 		printf("counter: [%d]\n", counter); */
	}
	return (value);
}


void	send_until_mid_b(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int	midpoint;
	int	value;

	midpoint = find_midpoint_value_b(stack_b, chunk_size);
	value = 0;
	while (*stack_b && value <= chunk_size)
	{
		if ((*stack_b)->content > midpoint)
		{
			op_pa(stack_a, stack_b);
			value++;
			printf("counter: [%d]\n", value);
		}
		if ((*stack_b)->content >= midpoint)
		{
			if (value_at_last(stack_b) < midpoint)
				op_rrb(stack_b);
			/* if (*stack_b && (*stack_b)->content >= midpoint)
				op_rb(stack_b); */
		}
	}
}