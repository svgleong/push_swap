/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:23:31 by svalente          #+#    #+#             */
/*   Updated: 2023/01/18 14:55:37 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *lst)
{
	t_stack *tmp = lst;
	
	while(tmp)
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
	printf("smallest:\t[%d]\n", find_smallest_int(&stack_a));
}
