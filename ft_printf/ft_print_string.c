/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:41:17 by zramahaz          #+#    #+#             */
/*   Updated: 2024/03/14 14:11:17 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_string(va_list args, int *count)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		*count += 6;
		write(1, "(null)", 6);
		return ;
	}
	while (*str)
	{
		ft_putchar(*str);
		str++;
		*count += 1;
	}
}
