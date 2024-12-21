/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:35:17 by aanmazir          #+#    #+#             */
/*   Updated: 2024/12/15 15:44:18 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t ack_received = 0;

void handle_ack(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	(void)signal;
	ack_received = 1;
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
				printf("Error sending SIGUSR1\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				printf("Error sending SIGUSR2\n");
				exit(1);
			}
		}
		usleep(500);
		i--;
	}
}

int main(int argc, char *argv[])
{
	struct sigaction sa;
	int	server_pid;
	int	i;
	char	*message;

	if (argc != 3)
	{
		printf("Use : %s <server_pid> \"message\"\n", argv[0]);
		return (1);
	}
	server_pid = atoi(argv[1]);
	message = argv[2];
	i = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_ack;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		printf("Error regestering SIGUSR1 Handler");
		exit(1);
	}
	while (message[i] != '\0')
	{
		send_signal(server_pid, message[i]);
		i++;
		while (!ack_received)
			pause();
		ack_received = 0;
	}
	send_signal(server_pid, '\0');
	printf("Server received the message Perfectly 🚀");
	return (0);
}
