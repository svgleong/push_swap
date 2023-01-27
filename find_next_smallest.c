/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_smallest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:23:17 by svalente          #+#    #+#             */
/*   Updated: 2023/01/27 17:11:15 by svalente         ###   ########.fr       */
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
