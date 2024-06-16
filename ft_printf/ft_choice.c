/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:35:14 by zramahaz          #+#    #+#             */
/*   Updated: 2024/03/14 14:08:59 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_choice(const char *format, va_list args, int *count)
{
	if (*format == 'c')
	{
		ft_putchar(va_arg(args, int));
		*count += 1;
	}
	else if (*format == 's')
		ft_print_string(args, count);
	else if (*format == 'p')
		ft_print_address(args, count);
	else if (*format == 'd' || *format == 'i')
		ft_print_int(args, count);
	else if (*format == 'u')
		ft_print_ui(args, count);
	else if (*format == 'x')
		ft_print_lower_hex(args, count);
	else if (*format == 'X')
		ft_print_upper_hex(args, count);
	else if (*format == '%')
	{
		ft_putchar('%');
		*count += 1;
	}
}
