/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:15:49 by svalente          #+#    #+#             */
/*   Updated: 2023/01/24 23:51:41 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_front(t_stack **lst, t_stack *new);

void	sort_long(t_stack **stack_a, t_stack **stack_b)
{	
	t_stack	*chunk_sizes;
	int		counter;

	chunk_sizes = NULL;
	counter = 0;
	while (lstsize(*stack_a) > 2)
	{
		add_front(&chunk_sizes, new_node(send_until_mid_a(stack_a, stack_b)));
		printf("stack_a:\t");
		print_list(*stack_a);
		printf("stack_b:\t");
		print_list(*stack_b);
	}
	
	if ((*stack_a)->content > (*stack_a)->next->content)
		op_sa(stack_a);
	printf("stack_a:\t");
	print_list(*stack_a);
	printf("stack_b:\t");
	print_list(*stack_b);
	while (chunk_sizes)
	{
		counter = 0;
		while (counter++ < chunk_sizes->content)
		{
			printf("chunk_size: [%d]\n", chunk_sizes->content);
			if (chunk_sizes->content == 1)
				op_pa(stack_a, stack_b);
			else
				send_until_mid_b(stack_a, stack_b, chunk_sizes->content) ;
			printf("stack_a:\t");
			print_list(*stack_a);
			printf("stack_b:\t");
			print_list(*stack_b);
			
		}
		chunk_sizes = chunk_sizes->next;
	}
}

static void	add_front(t_stack **lst, t_stack *new)
{
	if (*lst)
		new->next = *lst;
	*lst = new;
}


