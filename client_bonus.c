/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:12:49 by zramahaz          #+#    #+#             */
/*   Updated: 2024/06/29 15:38:06 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str);
static void ft_config_signals(void);
static void sig_handler(int signum);
static void ft_send_msg(pid_t pid_server, char *msg);

int main(int argc, char **argv)
{
    pid_t   pid_server;

    if (argc != 3 || argv[2][0] == '\0')
    {
        ft_printf("Error\n");
		return (1);
    }
	pid_server = ft_atoi(argv[1]);
    ft_config_signals();
    ft_send_msg(pid_server, argv[2]);
    while (1)
        pause();
    return (0);
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

static void ft_config_signals(void)
{
    struct sigaction    sa;
    
    sa.sa_handler = &sig_handler;
    sa.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        ft_printf("ERROR\n");
        exit(1);
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_printf("ERROR\n");
        exit(1);
    }
}

static void sig_handler(int signum)
{
    if (signum == SIGUSR2)
        ft_printf("caractere recus!\n");
}

static void ft_send_msg(pid_t pid_server, char *msg)
{
    unsigned char    c;
    int nb_bits;

    while (*msg)
    {
        c = *msg;
        nb_bits = 8;
        while (nb_bits--)
        {
            if (c & 0b10000000)
                kill(pid_server, SIGUSR1);
            else
                kill(pid_server, SIGUSR2);
            usleep(50);
            c <<= 1;
        }
        msg++;
    }
    c = *msg;
    nb_bits = 8;
    while (nb_bits--)
    {
        if (c & 0b10000000)
            kill(pid_server, SIGUSR1);
        else
            kill(pid_server, SIGUSR2);
        usleep(50);
        c <<= 1;
    }
}