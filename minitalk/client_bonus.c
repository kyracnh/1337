/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:35:17 by aanmazir          #+#    #+#             */
/*   Updated: 2024/12/22 11:11:53 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf/ft_printf.h"

void	response(int signal, siginfo_t *info, void *context)
{
	(void)signal;
	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		ft_printf("The Server Received the Message perfectly 👋\n");
	exit(EXIT_SUCCESS);
}

void	send_signal(int pid, char c)
{
	int	i;
	i = 7;
	while (i >= 0)
	{
		int bit;

		bit = (c >> i) & 1;
		if (bit == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Error sending SIGUSR1\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Error sending SIGUSR2\n");
				exit(1);
			}
		}
		usleep(60);
		i--;
	}
}

int main(int argc, char *argv[])
{
	struct sigaction	sa;
	int	server_pid;
	int	i;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Use : %s <server_pid> \"message\"\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	sa.sa_sigaction = response;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	while (message[i] != '\0')
	{
		send_signal(server_pid, message[i]);
		ft_printf("Signal %i has been sent perfectly 🚀\n", i);
		i++;
	}
	send_signal(server_pid, '\0');
	return (0);
}
