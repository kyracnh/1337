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
		usleep(60);
		i--;
	}
}

int main(int argc, char *argv[])
{
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
	while (message[i] != '\0')
	{
		send_signal(server_pid, message[i]);
		printf("Signal %i has been sent perfectly 🚀\n", i);
		i++;
	}
	send_signal(server_pid, '\0');
	return (0);
}
