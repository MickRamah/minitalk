/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:30:06 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/11 14:21:04 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str);

static int	ft_atoi(const char *str)
{
	int	i;
	int	resultat;
	int	signe;

	i = 0;
	resultat = 0;
	signe = 1;
	while ((unsigned char)str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			signe *= -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		resultat *= 10;
		resultat += str[i] - 48;
		i++;
	}
	resultat *= signe;
	return (resultat);
}
