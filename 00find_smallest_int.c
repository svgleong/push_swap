/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:16:53 by svalente          #+#    #+#             */
/*   Updated: 2023/01/24 23:49:19 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* int	find_biggest_int(t_stack **stack)
{
	int		nb;
	t_stack	*temp;

	temp = *stack;
	nb = (*stack)->content;
	while ((*stack)->next)
	{
		if (nb < (*stack)->next->content)
			nb = (*stack)->next->content;
		*stack = (*stack)->next;
	}
	*stack = temp;
	return (nb);
} */

