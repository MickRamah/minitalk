/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:35:02 by zramahaz          #+#    #+#             */
/*   Updated: 2024/03/14 14:11:51 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putnbr_uphex(unsigned int n, int *count)
{
	if (n > 15)
	{
		ft_putnbr_uphex(n / 16, count);
		ft_putnbr_uphex(n % 16, count);
	}
	else if (n > 9 && n < 16)
	{
		ft_putchar(n + 55);
		*count += 1;
	}
	else
	{
		ft_putchar(n + 48);
		*count += 1;
	}
}

void	ft_print_upper_hex(va_list args, int *count)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_uphex(n, count);
}
