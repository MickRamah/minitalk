/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:12:49 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/11 15:12:06 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	args_check(int argc, char **argv)
{
	if (argc != 3)
		ft_printf("Invalid number of arguments");
	if (*argv[2] == 0)
		ft_printf("Invalid message (empty)");
}

void	send_msg(pid_t sv_pid, char *msg)
{
	unsigned char	c;
	int				nbr_bits;

	while (*msg)
	{
		c = *msg;
		nbr_bits = 8;
		while (nbr_bits--)
		{
			if (c & 0b10000000)
				kill(sv_pid, SIGUSR1);
			else
				kill(sv_pid, SIGUSR2);
			usleep(100);
			c <<= 1;
		}
		msg++;
	}
	c = *msg;
	nbr_bits = 8;
	while (nbr_bits--)
	{
		if (c & 0b10000000)
			kill(sv_pid, SIGUSR1);
		else
			kill(sv_pid, SIGUSR2);
		usleep(100);
		c <<= 1;
	}
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
	{
		ft_printf("message has been sucessfully receieved!\n");
		exit(0);
	}
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_handler = &sig_handler;
	sa_newsig.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_newsig.sa_mask);
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		ft_printf("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		ft_printf("Failed to change SIGUSR2's behavior");
}

int	main(int argc, char **argv)
{
	pid_t		sv_pid;

	args_check(argc, argv);
	sv_pid = ft_atoi(argv[1]);
	config_signals();
	send_msg(sv_pid, argv[2]);
	while (1)
		pause();
	return (0);
}
