/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:58:35 by zramahaz          #+#    #+#             */
/*   Updated: 2024/03/14 14:10:28 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putnbr_i(int n, int *count)
{
	if (n < 0)
	{
		ft_putchar(45);
		*count += 1;
		n = -n;
		ft_putnbr_i(n, count);
	}
	else if (n > 9)
	{
		ft_putnbr_i(n / 10, count);
		ft_putnbr_i(n % 10, count);
	}
	else
	{
		ft_putchar(n + 48);
		*count += 1;
	}
}

void	ft_print_int(va_list args, int *count)
{
	int	n;

	n = va_arg(args, int);
	if (n == -2147483648)
	{
		*count += 2;
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr_i(147483648, count);
	}
	else
		ft_putnbr_i(n, count);
}
