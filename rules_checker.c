/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:33:29 by svalente          #+#    #+#             */
/*   Updated: 2023/01/11 16:07:48 by svalente         ###   ########.fr       */
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
			if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
				j++;
			if ((av[i][j] >= '0' && av[i][j] <= '9'))
				j++;
			else
				return (false);
		}
		i++;
	}
	return (true);
}

bool	check_limits(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) == 3737373737)
			return (false);
		i++;
	}
	return (true);
}

bool	check_dup(int ac, char **av)
{
	int	i;
	int j;

	i = 1;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	rules_checker(int ac, char **av)
{
	if (ac == 1)
		return (false);
	if (check_num(ac, av))
		if (check_limits(ac, av))
			if (check_dup(ac, av))
				return (true);
	return (false);
}

int	main(int ac, char **av)
{
	if (rules_checker(ac, av) == true)
		printf("Works");
	else
		printf("Not working for sure");
}

/* int	main(int ac, char **av)
{
	if (check_num(ac, av) == false)
	{
		printf("check_num:\t There arguments that are not numbers!!\n");
		return (0);
	}
	else
		printf("check_num:\t All numbers eheh\n");
	if (check_limits(ac, av) == false)
	{
		printf("check_limits:\t Numbers exceeds int limits\n");
		return (0);
	}
	else
		printf("check_limits:\t Numbers are within int limits :)\n");
	if (check_dup(ac, av) == true)
		printf("check_dup:\t No dupes found\n");
	else
		printf("check_dup:\t Dupes where found... :(\n");
} */

/* int	main(int ac, char **av)
{
	if (check_limits(ac, av) == false)
		printf("Numbers exceeds int limits\n");
	else
		printf("Numbers are within int limits :)\n");
} */
/* int	main(int ac, char **av)
{
	if (check_dup(ac, av) == true)
		printf("No dupes found\n");
	else
		printf("Dupes where found... :(\n");
} */
/* bool	check_dup(int ac, char **av)
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
} */
/* int	main(int ac, char **av)
{
	if (check_dup(ac, av) == false)
		printf("There are duplicates");
	else
		printf("No duplicates found");
} */