/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:20:34 by svalente          #+#    #+#             */
/*   Updated: 2023/01/27 17:18:13 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_array(t_stack **stack)
{
	int i;
	int	value;
	int	*array;

	i = 0;
	value = value_smallest_int(stack);
	array = malloc(sizeof(int) * (lstsize(*stack)));
	while (i < lstsize(*stack))
	{
		array[i++] = value;
		value = find_next_smallest(value, stack);
	}
	return (array);
}
