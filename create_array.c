/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:20:34 by svalente          #+#    #+#             */
/*   Updated: 2023/01/27 15:06:27 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_array(t_stack **stack)
{
	int i;
	int	value;
	int	*array;

	i = 0;
	value = value_at_i(stack);
	printf("smallest value: [%d]\n", value);
	array = malloc(sizeof(int) * (lstsize(*stack)));
	while (i < lstsize(*stack) - 1)
	{
		array[i++] = value;
		value = find_next_smallest(value, stack);
		printf("array[%d]: [%d]\n", i, array[i]);
	}
	array[i] = '\0';
	return (array);
}