/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:35:12 by svalente          #+#    #+#             */
/*   Updated: 2023/01/07 11:02:05 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rotate(t_list **head)
{
	t_list	*temp1;
	t_list	*temp2;
	
	temp1 = *head;
	*head = (*head)->next;
	temp2 = *head;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp1;
	temp1->next = NULL;
}

void	op_ra(t_list **stack_a)
{
	op_rotate(stack_a);
	ft_printf("ra\n");
}

void	op_rb(t_list **stack_b)
{
	op_rotate(stack_b);
	ft_printf("rb\n");
}

void	op_rr(t_list **stack_a, t_list **stack_b)
{
	op_rotate(stack_a);
	op_rotate(stack_b);
	ft_printf("rr\n");
}
