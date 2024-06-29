/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:21:01 by zramahaz          #+#    #+#             */
/*   Updated: 2024/06/29 15:33:35 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void ft_config_signals(void);
static void sig_handler(int signum, siginfo_t *info, void *content);

int main(void)
{
    pid_t   pid_server;

    pid_server = getpid();
    ft_printf("PID SERVER = %d\n", pid_server);
    while (1)
        ft_config_signals();
    return (0);
}

static void ft_config_signals(void)
{
    struct sigaction  sa;

    sa.sa_sigaction = &sig_handler;
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

static void sig_handler(int signum, siginfo_t *info, void *content)
{
    static int  bit_itr = -1;
    static unsigned char    c;

    (void)content;
    if (bit_itr < 0)
        bit_itr = 7;
    if (signum == SIGUSR1)
        c |= 1 << bit_itr;
    bit_itr--;
    if (bit_itr < 0 && c)
    {
        ft_printf("%c", c);
        c = 0;
        return ;
    }
    if (bit_itr < 0 && c == 0)
    {
        if (kill(info->si_pid, SIGUSR2) == -1)
        {
            ft_printf("ERROR\n");
            exit(1);
        }    
    }
    
    if (kill(info->si_pid, SIGUSR1) == -1)
    {
        ft_printf("ERROR\n");
        exit(1);
    }
}
