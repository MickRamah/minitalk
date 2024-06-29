/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:29:54 by zramahaz          #+#    #+#             */
/*   Updated: 2024/06/29 12:05:39 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void sig_handler(int signum);

int main(int argc, char **argv)
{
    int	pid_server;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid_server = getpid();
	ft_printf("PID SERVER = %d\n", pid_server);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (argc == 1)
		pause ();
	return (0);
}

static void sig_handler(int signum)
{
    static int	bit;
	static int	i;

	if (signum == SIGUSR1)
		i |= (1 << bit);
		// i |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}
