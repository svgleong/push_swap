/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalente <svalente@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:06:45 by svalente          #+#    #+#             */
/*   Updated: 2022/11/24 15:38:30 by svalente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putnbrbase(char *base, long long nb)
{
	long long	len;
	int			count;

	count = 0;
	len = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		count++;
	}
	if (nb >= len)
		count += ft_putnbrbase(base, nb / len);
	return (count += ft_putchar(base[nb % len]));
}

int	ft_putnbrpointer(char *base, unsigned long int nb, int checker)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(base);
	if (!nb)
		return (ft_putstr("(nil)"));
	if (checker == 0)
		count = ft_putstr("0x");
	if (nb >= (unsigned long)len)
		count += ft_putnbrpointer(base, nb / len, 1);
	return (count += ft_putchar(base[nb % len]));
}

// int	main(void)
// {
// 	int	str = -0123456;
// 	char *ptr = "";
// 	printf("return:\t\t%i\n", printf("result: \t%u\t%xaaa\t%s\n", str, str, ptr));
// 	ft_printf("returnfake:\t%i\n", ft_printf("result: \t%u\t%xaaa\t%s\n", str, str, ptr));
// }
/*include <stdio.h>

int	main()
{
	int nb = -54;
	char	*base = "0123456789";
	printf("\n%d\n", ft_putnbr(nb));
} */
/* if (nb > 9)
{
	count += ft_putnbr (nb / 10);
	count += ft_putchar (nb % 10 + '0');
}
else
	count += ft_putchar (nb % 10 + '0'); */