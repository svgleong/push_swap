/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:37:13 by svalente          #+#    #+#             */
/*   Updated: 2022/11/18 17:48:31 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}

/* #include <string.h>
#include <stdio.h>

int	main()
{
	const char str1[] = "a sofia idiotaaaaaaaaaaaaaaaaaaaaaaa";
	char str2[] = "o rodri";

	printf("dest = %s\n", str2);
	ft_memcpy(str2, str1, 20);
	printf("%s\n", str2);

	const char str1[] = "a sofia";
	char str2[] = "o rodri nao sabe o que diz";
	
	printf("dest_unmodified = %s\n", str2);
	ft_memcpy(str2, str1, 37);
	printf("des_modified = %s\n", str2);
}
 */