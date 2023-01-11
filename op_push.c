/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:29:57 by svalente          #+#    #+#             */
/*   Updated: 2023/01/07 10:39:24 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_push(t_list **head1, t_list **head2)
{
	t_list	*temp;

	if(*head2 == NULL)
		return;
	temp = *head2;
	*head2 = (*head2)->next;
	temp->next = *head1;
	*head1 = temp;
}

void	op_pa(t_list **stack_a, t_list **stack_b)
{
	op_push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	op_pb(t_list **stack_a, t_list **stack_b)
{
	op_push(stack_b, stack_a);
	ft_printf("pb\n");
}
