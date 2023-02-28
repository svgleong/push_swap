/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:23:31 by svalente          #+#    #+#             */
/*   Updated: 2023/02/25 13:34:08 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (rules_checker(ac, av) == 0)
		return (0);
	create_list(ac, av, &stack_a);
	sort_all_numbers(ac, &stack_a, &stack_b);
	lstclear(&stack_a);
	lstclear(&stack_b);
}

/* void	print_list(t_stack *lst)
{
	t_stack *tmp = lst;

	while (tmp)
	{
		printf("[%d] ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
} */

/* void	print_array(int *array, t_stack **stack)
{
	int i = 0;

	while (i < lstsize(*stack))
	{
		printf("[%d] ", array[i++]);
	}
	printf("\n");
} */