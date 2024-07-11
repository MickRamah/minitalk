/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:21:01 by zramahaz          #+#    #+#             */
/*   Updated: 2024/07/11 16:33:52 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

static char	*ft_strcpy(char *dest, char const *src)
{
	int	i;

	i = -1;
	while (src[++i] != '\0')
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strcat(char *dest, char const *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = -1;
	while (src[++j])
		dest[i++] = src[j];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s1);
	len += ft_strlen(s2);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	ft_strcpy(dest, s1);
	ft_strcat(dest, s2);
	free((char *)s1);
	return (dest);
}

char	*ft_stack_str(char *str, char c)
{
	char	*dest;

	if (str == NULL)
	{
		str = malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		*str = '\0';
	}
	dest = ft_strjoin(str, &c);
	return (dest);
}

void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				bit_itr = -1;
	static unsigned char	c;
	static char				*str;

	(void)ucontent;
	if (bit_itr < 0)
		bit_itr = 7;
	if (signum == SIGUSR1)
		c |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0 && c)
	{
		str = ft_stack_str(str, c);
		c = 0;
		return ;
	}
    if (bit_itr < 0 && c == 0)
	{
		ft_printf("%s\n", str);
		free(str);
		str = NULL;
        kill(info->si_pid, SIGUSR2);
	}
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handle_sigusr;
	sa_newsig.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_newsig.sa_mask);
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		ft_printf("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		ft_printf("Failed to change SIGUSR2's behavior");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("SERVER PID = %d\n\n", pid);
    config_signals();
	while (1)
	{
	}
	return (0);
}
