/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:30:06 by zramahaz          #+#    #+#             */
/*   Updated: 2024/06/14 11:54:11 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str);
static void	ft_send_signal(int pid, char c);

int main(int argc, char **argv)
{
    int pid;
	int	i;

    if (argc != 3)
    {
        write(2, "Error\n", 6);
		return (1);
    }
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_send_signal(pid, argv[2][i]);
		i++;
	}
	ft_send_signal(pid, 0);
	return (0);
}

static void	ft_send_signal(int pid, char c)
{
	int	bit;
    int value;

	bit = 0;
	while (bit < 8)
	{
        // value = (c & (1 << bit));
        value = ((c >> (7 - bit)) & 1);
		if (value)
        {
            write(1, "1", 1);
			kill(pid, SIGUSR1);
        }
		else
        {
            write(1, "0", 1);
			kill(pid, SIGUSR2);
		}
		usleep(500);
		bit++;
	}
}

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