/* void	sort_medium(t_stack **a, t_stack **b)
{
	t_mid	*mid;
	int		*chunk_sizes;
	int		i;

	mid = malloc(sizeof(t_mid *));
	chunk_sizes = malloc(sizeof(int) * 5);
	i = -1;
	while (stack_size(*a) > 2)
	{
		find_midpoint(*a, stack_size(*a), mid);
		chunk_sizes[++i] = send_smaller(a, b, mid, stack_size(*a), 1);
	}
	sort_small(a, b);
	while (i >= 0)
	{
		sort_chunk(a, b, chunk_sizes[i], 'b');
		i--;
	}
	free(chunk_sizes);
	free(mid);
}

void	sort_chunk(t_stack **a, t_stack **b, int chunk_size, char id)
{
	t_mid	*mid;
	int		new_chunk_size;
	int		tmp;

	new_chunk_size = 0;
	mid = malloc(sizeof(t_mid *));
	while (chunk_size)
	{
		if (id == 'a' && is_sorted(*a, chunk_size))
			break ;
		if (id == 'b' && is_sorted_descending(*b, chunk_size))
			sort_chunk(a, b, new_chunk_size, 'a'); 
		if (chunk_size <= 2)
			tmp = small_push(a, b, chunk_size, id);
		else if (id == 'a')
		{
			find_midpoint(*a, chunk_size, mid);
			tmp = send_smaller(a, b, mid, chunk_size, 0);
		}
		else if (id == 'b')
		{
			find_midpoint(*b, chunk_size, mid);
			tmp = send_bigger(a, b, mid, chunk_size);
		}
		chunk_size -= tmp;
		new_chunk_size += tmp;
	if (new_chunk_size)
	{
		if (id == 'a' && !is_sorted(*b, new_chunk_size))
			sort_chunk(a, b, new_chunk_size, 'b');
		else if (id == 'b' && !is_sorted(*a, new_chunk_size))
			sort_chunk(a, b, new_chunk_size, 'a');
	}
	}
	free(mid);
} */