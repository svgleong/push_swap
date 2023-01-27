/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:20:34 by svalente          #+#    #+#             */
/*   Updated: 2023/01/27 14:53:20 by svalente         ###   ########.fr       */
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
		array[i] = value;
		printf("array[%d]: [%d]\n", i, array[i]);
		value = find_next_smallest(value, stack);
		printf("array[%d]: [%d]\n", i, array[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}