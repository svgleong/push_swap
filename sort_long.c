/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:15:49 by svalente          #+#    #+#             */
/*   Updated: 2023/02/17 17:28:21 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_long(t_stack **stack_a, t_stack **stack_b)
{
	send_to_b(stack_a, stack_b);
}


void	send_to_b(t_stack **stack_a, t_stack **stack_b)
{
	while (lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->content < find_mid_value(stack_a))
			op_pb(stack_a, stack_b);
		else
			op_ra(stack_a);
/* 		printf("stack_a:\t");
		print_list(*stack_a);
		printf("stack_b:\t");
		print_list(*stack_b); */
	}
	sort_3(stack_a);
}

t_stack	*best_neigh(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;
	t_stack *neigh;
	double diff;
	
	neigh = stack_a;
	diff = 99999999999;
	while (stack_a)
	{
		if (subtract(stack_a, stack_b) < diff && subtract(stack_a, stack_b) > 0)
		{
			diff = subtract(stack_a, stack_b);
			neigh = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (neigh);
}

double	subtract(t_stack *stack_a, t_stack *stack_b)
{
	double value;
	
	if (stack_a->content > stack_b->content)
		value = stack_a->content - stack_b->content;
	else
		value = stack_b->content - stack_a->content;
	return (value);
}

int	moves_cost(t_stack **stack, t_stack *elem)
{
	if (lstsize(elem) > lstsize(*stack) / 2)
		return (lstsize(*stack) - lstsize(elem));
	else
		return (lstsize(elem));
}

int	best_path(t_stack *st_a, t_stack *st_b, t_stack *elem, t_stack *neigh)
{
	int cost_a;
	int cost_b;

	cost_a = moves_cost(st_a, neigh);
	cost_b = moves_cost(st_b, elem);
	if (half(st_a, neigh) == 0  && half(st_b, elem) == 0)
		return (bigger(cost_a, cost_b));
	if (half(st_a, neigh) == 1  && half(st_b, elem) == 1)
		return (bigger(cost_a, cost_b));
	else
		return (cost_a + cost_b);
}

int	half(t_stack **stack, t_stack *elem)
{
	if (lstsize(elem) > lstsize(*stack) / 2)
		return (0);
	else
		return (1);
}

int	bigger(int cost_a, int cost_b)
{
	if (cost_a >= cost_b)
		return (cost_a);
	else
		return (cost_b);
}

t_stack *min_cost(t_stack *stack_a, t_stack *stack_b)
{
	int 	min_cost;
	int		cost;
	t_stack *neigh;
	t_stack	*elem;

	min_cost = INT_MAX;
	elem = stack_b;
	while (stack_b)
	{
		neigh = best_neigh(stack_a, stack_b);
		cost = best_path(stack_a, stack_b, stack_b, neigh);
		if (cost < min_cost)
		{
			min_cost = cost;
			elem = stack_b;
		}
		stack_b = (stack_b)->next;
	}
	return (elem);
}