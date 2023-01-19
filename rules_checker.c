/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:33:29 by svalente          #+#    #+#             */
/*   Updated: 2023/01/19 14:37:43 by svalente         ###   ########.fr       */
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
	int	j;

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
	if (ac != 1)
		if (check_num(ac, av))
			if (check_limits(ac, av))
				if (check_dup(ac, av))
					return (true);
	ft_printf("Error\n");
	return (false);
}
