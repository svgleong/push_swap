/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:23:31 by svalente          #+#    #+#             */
/*   Updated: 2023/01/26 22:23:09 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *lst)
{
	t_stack *tmp = lst;

	while (tmp)
	{
		printf("[%d] ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (rules_checker(ac, av) == false)
		return (0);
	create_list(ac, av, &stack_a);
	printf("stack_a:\t");
	print_list(stack_a);
	printf("stack_b:\t");
	print_list(stack_b);
/* 	printf("lst size: [%d]\n", lstsize(stack_a));
	printf("lst size/2: [%d]\n", lstsize(stack_a)/2);
	printf("midpoint value: [%d]\n", find_midpoint_value(&stack_a)); */
	printf("smallest index: [%d]\n", find_smallest_int(&stack_a));
	printf("smallest value: [%d]\n", value_at_i(&stack_a));
	/* find_midpoint_value(&stack_a); */
	/* printf("midpoint value: [%d]\n", find_midpoint_value(&stack_a)); */
	/* int value = value_at_i(&stack_a);
	printf("next smallest value: [%d]\n", find_next_smallest(value, &stack_a)); */
	/* value = 3;
	printf("next smallest value: [%d]\n", find_next_smallest(value, &stack_a)); */
	sort_all_numbers(ac, &stack_a, &stack_b);
	/* sort_long(&stack_a, &stack_b); */
	/* op_pb(&stack_a, &stack_b);
	printf("temp value now: [%d]\n", stack_a->content); */
	printf("stack_a:\t");
	print_list(stack_a);
	printf("stack_b:\t");
	print_list(stack_b);
}
