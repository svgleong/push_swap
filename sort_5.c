/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:45:35 by svalente          #+#    #+#             */
/*   Updated: 2023/01/13 16:53:32 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	op_pb(stack_a, stack_b);
	op_pb(stack_a, stack_b);
	sort_3(stack_a);
	if ()
		op_pa(stack_a, stack_b);
	
}