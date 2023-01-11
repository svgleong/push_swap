/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:11:09 by svalente          #+#    #+#             */
/*   Updated: 2023/01/07 11:20:13 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rev_rotate(t_list **head)
{
	t_list	*temp;

	temp = *head;
	while ((*head)->next)
		*head = (*head)->next;
	(*head)->next = temp;
	while (temp->next != *head)
		temp = temp->next;
	temp->next = NULL;
}

void	op_rra(t_list **stack_a)
{
	op_rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	op_rrb(t_list **stack_b)
{
	op_rev_rotate(stack_b);
	ft_printf("rrb\n");
}

void	op_rrr(t_list **stack_a, t_list **stack_b)
{
	op_rev_rotate(stack_a);
	op_rev_rotate(stack_b);
	ft_printf("rrr\n");
}
