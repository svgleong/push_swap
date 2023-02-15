/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:15:49 by svalente          #+#    #+#             */
/*   Updated: 2023/02/15 14:31:48 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	sort_long(t_stack **stack_a, t_stack **stack_b)
{
	
}
 */
void	send_to_b(t_stack **stack_a, t_stack **stack_b)
{
	while (lstsize(*stack_a) > 1)
	{
		if ((*stack_a)->content < find_mid_value(stack_a))
			op_pb(stack_a, stack_b);
		else
			op_ra(stack_a);
		printf("midvalue : [%d]\n", find_mid_value(stack_a));
		printf("stack_a:\t");
		print_list(*stack_a);
		printf("stack_b:\t");
		print_list(*stack_b);
	}
}
