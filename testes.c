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
/* int	main(int ac, char **av)
{
	if (rules_checker(ac, av) == true)
		printf("Works");
	else
		printf("Not working for sure");
}
 */
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
/* void	op_swap_learn(t_list **stack_a)
// stack_a -> double pointer to the head of the linked list
{
	// create temporary pointer to the first node
	t_list	*temp;

	temp = *stack_a;
	// check if linked list has at least two nodes
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	// set the head to point to the second node instead of the first one
	*stack_a = (*stack_a)->next;
	// set the temporary pointer's next pointer to the second node
	temp->next = (*stack_a)->next;
	// set the second node's next pointer to point to the first node
	(*stack_a)->next = temp;
	ft_printf("sa\n");
}
 */
/* printf("stack_a:\t");
	print_list(stack_a);
	printf("stack_b:\t");
	print_list(stack_b);
	
	op_pb(&stack_a, &stack_b);
	printf("stack_a:\t");
	print_list(stack_a);
	printf("stack_b:\t");
	print_list(stack_b);
	
	op_pa(&stack_a, &stack_b);
	printf("stack_a:\t");
	print_list(stack_a);
	printf("stack_b:\t");
	print_list(stack_b);
	
	op_rra(&stack_a);
	printf("stack_a:\t");
	print_list(stack_a);
	printf("stack_b:\t");
	print_list(stack_b);
	
	op_pb(&stack_a, &stack_b);
	printf("stack_a:\t");
	print_list(stack_a);
	printf("stack_b:\t");
	print_list(stack_b);
	
	op_pb(&stack_a, &stack_b);
	printf("stack_a:\t");
	print_list(stack_a);
	printf("stack_b:\t");
	print_list(stack_b);
	
	op_pb(&stack_a, &stack_b);
	printf("stack_a:\t");
	print_list(stack_a);
	printf("stack_b:\t");
	print_list(stack_b);
	
	op_rr(&stack_a, &stack_b);
	printf("stack_a:\t");
	print_list(stack_a);
	printf("stack_b:\t");
	print_list(stack_b);

	op_rrr(&stack_a, &stack_b);
	printf("stack_a:\t");
	print_list(stack_a);
	printf("stack_b:\t");
	print_list(stack_b); */