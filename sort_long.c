/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:15:49 by svalente          #+#    #+#             */
/*   Updated: 2023/02/22 18:16:02 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_long(t_stack **stack_a, t_stack **stack_b)
{
	int size;

	send_to_b(stack_a, stack_b);
	size = lstsize(*stack_b);
	while (size-- > 0)
		send_to_a(stack_a, stack_b);	
	/* printf("send_to_a\t stack_a:\t\n");
	print_list(*stack_a);
	printf("send_to_a\t stack_b:\t\n");
	print_list(*stack_b); */
	printf("find smallest: [%d]\n", find_smallest_int(stack_a));
	move_lowest_to_top(stack_a);
}


void	send_to_b(t_stack **stack_a, t_stack **stack_b)
{
	while (lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->content < find_mid_value(stack_a))
			op_pb(stack_a, stack_b);
		else
			op_ra(stack_a);
		printf("send_to_b\t stack_a:\t");
		print_list(*stack_a);
		printf("send_to_b\t stack_b:\t");
		print_list(*stack_b);
	}
	if (check_order(stack_a) == 0)
		sort_3(stack_a);
	printf("send_to_b\t stack_a:\t");
	print_list(*stack_a);
	printf("send_to_b\t stack_b:\t");
	print_list(*stack_b);
}

t_stack	*best_neigh(t_stack *stack_a, t_stack *stack_b)
{
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

	cost_a = moves_cost(&st_a, neigh);
	cost_b = moves_cost(&st_b, elem);
	if (half(&st_a, neigh) == 0  && half(&st_b, elem) == 0)
		return (bigger(cost_a, cost_b));
	if (half(&st_a, neigh) == 1  && half(&st_b, elem) == 1)
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

void	send_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *elem;
	t_stack *best;
	
	elem = min_cost(*stack_a, *stack_b);
	best = best_neigh(*stack_a, *stack_b);
	printf("elem: [%d]\n", elem->content);
	printf("best: [%d]\n", best->content);
	if (half(stack_a, best) == 0 && half(stack_b, elem) == 0)
		all_upper_half(stack_a, stack_b);
	else if (half(stack_a, best) == 1 && half(stack_b, elem) == 1)
		all_lower_half(stack_a, stack_b);
	else if (half(stack_a, best) == 1 && half(stack_b, elem) == 0)
	{
		lower_half(stack_a, stack_b, 'a');
		upper_half(stack_a, stack_b, 'b');
	}
	else if (half(stack_a, best) == 0 && half(stack_b, elem) == 1)
	{
		upper_half(stack_a, stack_a, 'a');
		lower_half(stack_a, stack_a, 'b');
	}
	op_pa(stack_a, stack_b);
}

void	all_upper_half(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *elem;
	t_stack *best;
	int cost_a;
	int cost_b;
	
	elem = min_cost(*stack_a, *stack_b);
	best = best_neigh(*stack_a, *stack_b);
	cost_a = moves_cost(stack_a, best);
	cost_b = moves_cost(stack_b, elem);
	while (cost_a-- > 0 && cost_b-- > 0)
		op_rr(stack_a, stack_b);
	if (cost_a > 0)
	{
		while (cost_a-- > 0)
			op_ra(stack_a);
	}
	else if (cost_b > 0)
	{
		while (cost_b-- > 0)
			op_rb(stack_b);
	}
	printf("send_to_a\t stack_a:\t");
	print_list(*stack_a);
	printf("send_to_a\t stack_b:\t");
	print_list(*stack_b);
}

void	all_lower_half(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *elem;
	t_stack *best;
	int cost_a;
	int cost_b;
	
	elem = min_cost(*stack_a, *stack_b);
	best = best_neigh(*stack_a, *stack_b);
	cost_a = moves_cost(stack_a, best);
	cost_b = moves_cost(stack_b, elem);
	while (cost_a-- > 0 && cost_b-- > 0)
		op_rrr(stack_a, stack_b);
	if (cost_a > 0)
	{
		while (cost_a-- > 0)
			op_rra(stack_a);
	}
	else if (cost_b > 0)
	{
		while (cost_b-- > 0)
			op_rrb(stack_b);
	}
	printf("send_to_a\t stack_a:\t");
	print_list(*stack_a);
	printf("send_to_a\t stack_b:\t");
	print_list(*stack_b);
}

void	upper_half(t_stack **stack_a, t_stack **stack_b, char stack)
{
	t_stack *elem;
	t_stack *best;
	int cost_a;
	int cost_b;
	
	elem = min_cost(*stack_a, *stack_b);
	best = best_neigh(*stack_a, *stack_b);
	cost_a = moves_cost(stack_a, best);
	cost_b = moves_cost(stack_b, elem);
	if (stack == 'a')
	{
		while (cost_a-- > 0)
			op_ra(stack_a);
	}
	if (stack == 'b')
	{
		while (cost_b-- > 0)
			op_rb(stack_b);
	}
	printf("send_to_a\t stack_a:\t");
	print_list(*stack_a);
	printf("send_to_a\t stack_b:\t");
	print_list(*stack_b);
}

void	lower_half(t_stack **stack_a, t_stack **stack_b, char stack)
{
	t_stack *elem;
	t_stack *best;
	int cost_a;
	int cost_b;
	
	elem = min_cost(*stack_a, *stack_b);
	best = best_neigh(*stack_a, *stack_b);
	cost_a = moves_cost(stack_a, best);
	cost_b = moves_cost(stack_b, elem);
	if (stack == 'a')
	{
		while (cost_a-- > 0)
			op_rra(stack_a);
	}
	if (stack == 'b')
	{
		while (cost_b-- > 0)
			op_rrb(stack_b);
	}
	printf("send_to_a\t stack_a:\t");
	print_list(*stack_a);
	printf("send_to_a\t stack_b:\t");
	print_list(*stack_b);
}

void	move_lowest_to_top(t_stack **stack_a)
{
	int	i;
	t_stack *temp;

	i = value_smallest_int(stack_a);
	temp = *stack_a;
	while (temp)
	{
		if (temp->content == i)
			break ;
		temp = temp->next;
	}
	if (half(stack_a, temp) == 0) // && i != stack_a
	{
		while ((*stack_a)->content != i)
			op_ra(stack_a);
	}
	else if (half(stack_a, temp) == 1)
	{
		while ((*stack_a)->content != i)
			op_rra(stack_a);
	}
}