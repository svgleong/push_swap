/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mid_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:12:38 by svalente          #+#    #+#             */
/*   Updated: 2023/02/15 11:15:20 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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