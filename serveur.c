/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:29:54 by zramahaz          #+#    #+#             */
/*   Updated: 2024/06/14 11:42:59 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void sig_handler(int signum);

int main(int argc, char **argv)
{
    int	pid;

	if (argc != 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	pid = getpid();
	printf("PID server = %d\n", pid);
    signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (argc == 1)
		pause ();
	return (0);
}

void sig_handler(int signum)
{
    static int	bit;
	static int	i; 

	if (signum == SIGUSR1)
	{
		// i |= (1 << bit);
		write(1, "1", 1);
		i |= (1 << (7 - bit));
	}
	else
		write(1, "0", 1);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		write(1, "\n", 1);
		bit = 0;
		i = 0;
	}
}
