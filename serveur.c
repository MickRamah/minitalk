/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:29:54 by zramahaz          #+#    #+#             */
/*   Updated: 2024/06/04 17:15:19 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void sig_handler(int signum);

int main(void)
{
    pid_t   pid;

    pid = getpid();
    printf("PID serveur : %d\n", pid);
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);
    while (1)
        pause();
    return (0);
}

static void sig_handler(int signum)
{
    
    return ;
}
