/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:30:08 by svalente          #+#    #+#             */
/*   Updated: 2023/01/13 12:49:06 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		add_back(t_stack **lst, t_stack *new);
static t_stack	*last_node(t_stack *lst);
static t_stack	*new_node(int content);

void	create_list(int ac, char **av, t_stack **stack)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		add_back(stack, new_node(ft_atoi(av[i])));
		i++;
	}
}

static t_stack	*new_node(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

static t_stack	*last_node(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static void	add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = last_node(*lst);
	last->next = new;
}
