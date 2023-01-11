/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:30:08 by svalente          #+#    #+#             */
/*   Updated: 2023/01/11 11:49:03 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list(int ac, char **av, t_list *stack)
{
	int	i;

	i = 1;
	while(i < ac)
	{
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
}

/* int	*create_array(int ac, char **av)
{
	int	*array;
	int	i;
	int	j;

	array = (int *)malloc(sizeof(int) * (ac - 1));
	if (!array)
		return (0);
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (av[i] == )
			array[j] = 0;
		else		
			array[j] = ft_atoi(av[i]);
		j++;
		i++;
	}
	array[j] = '\0';
	return (array);
}

int	main(int ac, char **av)
{
	int i = 0;
	int *array = create_array(ac, av);
	
	while (array[i])
	{
		printf("%d ", array[i]);
		i++;
	}
} */

/* int	*create_array2(t_list *stack)
{
	int	size;
	int	i;
	int	*array;

	size = ft_lstsize(stack);
	i = 0;
	array = malloc(sizeof(int) * size);
	while (i < size)
	{
		array[i] = stack->content;
		stack = stack->next;
		i++;
	}
	return (array);
} */