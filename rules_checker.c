/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:33:29 by svalente          #+#    #+#             */
/*   Updated: 2023/01/08 11:43:19 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_num(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == '-')
				j++;
			else
				return (false);
		}
		i++;
	}
	return (true);
}

bool	check_dup(int ac, char **av)
{
	int	i;
	int	j;
	int	temp;
	int	*array;

	i = 0;
	array = create_array(ac, av);

	int a = 0;
	printf("total array -> ");
	while (array[a])
	{
		printf("%d ", array[a]);
		a++;
	}
	printf("\n");
	
	while (array[i])
	{
		temp = array[i];
		printf("array[i]: %d, temp: %d\n", array[i], temp);
		j = 0;
		while (array[j])
		{
			printf("->array[j]: %d, temp: %d\n", array[i], temp);
			if (temp == array[j] && j != i)
			{
				free(array);
				return (false);				
			}
			j++;
		}
		i++;
	}
	free(array);
	return (true);
}

/* bool	rules_checker(int ac, char **av)
{
	if (check_num == false)
		return (false);
	if (check_dup == false)
		return (false);
} */

/* int	main(int ac, char **av)
{
	if (check_dup(ac, av) == false)
		printf("There are duplicates");
	else
		printf("No duplicates found");
} */