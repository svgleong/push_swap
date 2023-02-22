/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:23:17 by svalente          #+#    #+#             */
/*   Updated: 2023/02/22 17:54:44 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_smallest(int value, t_stack **stack)
{
	long	nb;
	t_stack	*temp;

	temp = *stack;
	nb = INT_MAX;
	/* printf("value sent: [%d]\n", value); */
	while ((*stack))
	{
/* 		printf("nb1: [%d]\n", nb);
		printf("stack content1: [%d]\n", (*stack)->content); */
		if (nb > (*stack)->content && (*stack)->content > value)
		{
			/* printf("entrei stack content2: [%d]\n", (*stack)->content); */
			nb = (*stack)->content;
			/* printf("nb2: [%d]\n", nb); */
		}
		*stack = (*stack)->next;
	}
	*stack = temp;
	return (nb);
}

int	find_smallest_int(t_stack **stack)
{
	int		nb;
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	nb = (*stack)->content;
	while ((*stack)->next)
	{
		if (nb > (*stack)->next->content)
			nb = (*stack)->next->content;
		*stack = (*stack)->next;
	}
	*stack = temp;
	while ((*stack) && nb != (*stack)->content)
	{
		i++;
		*stack = (*stack)->next;
	}
	*stack = temp;
	return (i);
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

int	find_mid_value(t_stack **stack)
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
