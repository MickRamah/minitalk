/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 10:11:33 by zramahaz          #+#    #+#             */
/*   Updated: 2024/03/14 14:20:50 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_choice(format, args, &count);
			format++;
		}
		else
		{
			ft_putchar(*format);
			format++;
			count++;
		}
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	char	len = 'A';
	char	*len2 = &len;

	ft_printf(" %s \n", len2);
	printf(" %s \n", len2);
	//printf("%d\n", len);
	//ft_printf("%d\n", len2);

	//printf(" %d \n", INT_MIN + 1);
	//ft_printf(" %d \n", INT_MIN + 1);

	printf(" %p  \n", len2);
	ft_printf(" %p  \n", len2);

	return (0);
}*/
