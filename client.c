/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:30:06 by zramahaz          #+#    #+#             */
/*   Updated: 2024/06/04 17:08:42 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str);
static void ft_send_signal(unsigned int octet, char c, int pid);

int main(int argc, char **argv)
{
    int pid;
    long        i;
    
    if (argc != 3)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    pid = ft_atoi(argv[1]);
    i = 0;
    while (argv[2][i])
    {
        ft_send_signal(7, argv[2][i] , pid);
        usleep(10);
        i++;
    }
    return 0;
}

static void ft_send_signal(unsigned int octet, char c, int pid)
{
    int   binary;

    if (octet == -1)
        return ;
    binary = (c >> (octet) & 1);
    if (binary == 0)
        // kill(pid, SIGUSR1);
        printf("%d ", binary);
    else
        // kill(pid, SIGUSR2);
        printf("%d ", binary);
    ft_send_signal(octet - 1, c, pid);
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