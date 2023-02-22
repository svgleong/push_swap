/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:23:31 by svalente          #+#    #+#             */
/*   Updated: 2023/02/22 17:51:03 by svalente         ###   ########.fr       */
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

void	print_array(int *array, t_stack **stack)
{
	int i = 0;

	while (i < lstsize(*stack))
	{
		printf("[%d] ", array[i++]);
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

	/* printf("find smallest: [%d]\n", find_smallest_int(&stack_a)); */

	sort_all_numbers(ac, &stack_a, &stack_b);
	/* send_to_b(&stack_a, &stack_b);
	move_lowest_to_top(&stack_a); */
	
	printf("stack_a:\t");
	print_list(stack_a);
	printf("stack_b:\t");
	print_list(stack_b);

	
}

/* int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (rules_checker(ac, av) == false)
		return (0);
	create_list(ac, av, stack_a);
	printf("stack_a:\t");
	print_list(*stack_a);
	printf("stack_b:\t");
	print_list(*stack_b);

	send_to_b(stack_a, stack_b);

	printf("stack_a:\t");
	print_list(*stack_a);
	printf("stack_b:\t");
	print_list(*stack_b);
	
	min_cost(*stack_a, *stack_b);

	printf("stack_a:\t");
	print_list(*stack_a);
	printf("stack_b:\t");
	print_list(*stack_b);
}
 */