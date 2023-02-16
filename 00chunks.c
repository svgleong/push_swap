/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:55:16 by svalente          #+#    #+#             */
/*   Updated: 2023/02/09 18:14:13 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunks(int size)
{
	int	num_chunks;

	num_chunks = 0;
	if (size > 5 && size < 52)
		num_chunks = 4;
	else if (size > 51 && size < 102)
		num_chunks = 8;
	else if (size > 101 && size < 252)
		num_chunks = 30;
	else if (size > 251 && size < 502)
		num_chunks = 30;
	else if (size > 501)
		num_chunks = 20;
	return (num_chunks);
}

void	div_chunks(int *array, int size, t_chunk *all_chunks)
{
	int	num_chunks;
	int	chunk_size;
	int	i;

	i = 0;
	num_chunks = chunks(size);
	chunk_size = size / num_chunks;
	while (i < num_chunks)
	{
		all_chunks[i].beg = array[i * chunk_size];
		all_chunks[i].index_beg = i * chunk_size;
		if (i == num_chunks - 1)
		{
			all_chunks[i].end = array[size - 2];
			all_chunks[i].index_end = size - 2;
		}
		else
		{
			all_chunks[i].end = array[(i + 1) * chunk_size - 1];
			all_chunks[i].end = (i + 1) * chunk_size - 1;
		}
		i++;
	}
}