/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:36:51 by svalente          #+#    #+#             */
/*   Updated: 2023/01/11 14:19:52 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap(t_list **head)
{
	t_list	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return;
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
}

void	op_sa(t_list **stack_a)
{
	op_swap(stack_a);
	ft_printf("sa\n");
}

void	op_sb(t_list **stack_b)
{
	op_swap(stack_b);
	ft_printf("sb\n");
}

void	op_ss(t_list **stack_a, t_list **stack_b)
{
	op_swap(stack_a);
	op_swap(stack_b);
	ft_printf("ss\n");
}



/* void	op_swap_learn(t_list **stack_a)
// stack_a -> double pointer to the head of the linked list
{
	// create temporary pointer to the first node
	t_list	*temp;

	temp = *stack_a;
	// check if linked list has at least two nodes
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	// set the head to point to the second node instead of the first one
	*stack_a = (*stack_a)->next;
	// set the temporary pointer's next pointer to the second node
	temp->next = (*stack_a)->next;
	// set the second node's next pointer to point to the first node
	(*stack_a)->next = temp;
	ft_printf("sa\n");
}
 */