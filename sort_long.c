/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:15:49 by svalente          #+#    #+#             */
/*   Updated: 2023/01/26 22:19:53 by svalente         ###   ########.fr       */
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
	printf("finished stack a\n\n");
	printf("chunk sizes:\t");
	print_list(chunk_sizes);

	
	while (chunk_sizes)
	{
		counter = 0;
		printf("chunk size int: [%d]\n", chunk_sizes->content);
		while (chunk_sizes && counter < chunk_sizes->content)
		{
			printf("chunk_size: [%d]\n", chunk_sizes->content);
			printf("counteeeeer [%d]\n", counter);
			if (counter < chunk_sizes->content && chunk_sizes->content == 1)
			{
				op_pa(stack_a, stack_b);
				printf("entrei e counter [%d]\n", counter);
				counter++;
			}
			else if (counter < chunk_sizes->content && chunk_sizes->content == 2)
			{
				if ((*stack_b)->content < (*stack_b)->next->content)
					op_sb(stack_b);
				op_pa(stack_a, stack_b);
				op_pa(stack_a, stack_b);
				counter++;
			}
		
			else if (counter < chunk_sizes->content && chunk_sizes->content > 2 && lstsize(*stack_b) > 2)
			{
				printf("entrei1 e counter [%d]\n", counter);
				while (counter < chunk_sizes->content)
				{
					printf("entrei2 e counter [%d]\n", counter);
					printf("counteeer: [%d]\n", counter);
					counter = send_until_mid_b(stack_a, stack_b, chunk_sizes->content, counter); 
					printf("counteeer2: [%d]\n", counter);
				}	
			}
			else
				break ;
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
