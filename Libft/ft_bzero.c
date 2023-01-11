/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:12:00 by svalente          #+#    #+#             */
/*   Updated: 2022/11/09 10:20:28 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	if (!s || !c || n <= 0)
		return (s);
	p = (char *)s;
	i = 0;
	while (p[i] && i < n)
	{
		p[i] = c;
		i++;
	}
	return (p);
} */

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/* #include <string.h>
#include <stdio.h>

int	main()
{
	char	str[] = "222222222";
	void *t;
	
	ft_memset(t, '5', 3);

	printf("%p\n", t);
	
	ft_bzero(t, 3);

	printf("%p\n", t);

	printf("str = %s\n", str);
	printf("%p\n", );
	// printf("%p\n", memset(&str, '5', 1));
	printf("%p\n", str);
	printf("str = %s\n", str);
} */