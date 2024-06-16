/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:33:45 by zramahaz          #+#    #+#             */
/*   Updated: 2024/03/14 14:09:21 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putnbr_hex(long unsigned n, int *count)
{
	if (n > 15)
	{
		ft_putnbr_hex(n / 16, count);
		ft_putnbr_hex(n % 16, count);
	}
	else if (n > 9 && n < 16)
	{
		ft_putchar(n + 87);
		*count += 1;
	}
	else
	{
		ft_putchar(n + 48);
		*count += 1;
	}
}

void	ft_print_address(va_list args, int *count)
{
	long unsigned	p;

	p = (long unsigned)va_arg(args, void *);
	if (!p)
	{
		*count += 5;
		write(1, "(nil)", 5);
		return ;
	}
	*count += 2;
	ft_putchar(48);
	ft_putchar('x');
	ft_putnbr_hex(p, count);
}
