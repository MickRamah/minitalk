/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:18:58 by zramahaz          #+#    #+#             */
/*   Updated: 2024/03/14 14:11:31 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putnbr_ui(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_putnbr_ui(n / 10, count);
		ft_putnbr_ui(n % 10, count);
	}
	else
	{
		ft_putchar(n + 48);
		*count += 1;
	}
}

void	ft_print_ui(va_list args, int *count)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_ui(n, count);
}
