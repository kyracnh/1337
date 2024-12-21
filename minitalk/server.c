/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:55:22 by aanmazir          #+#    #+#             */
/*   Updated: 2024/12/15 14:33:27 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

signal_data data = {0, 0, 0};

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;

	if (data.client_pid == 0)
		data.client_pid = info->si_pid;

	data.current_char <<= 1;

	if (signal == SIGUSR1)
		data.current_char |= 0;
	else if (signal == SIGUSR2)
		data.current_char |= 1;
	data.current_bit++;
	if (data.current_bit == 8)
	{
		write(1, &data.current_char,1);
		data.current_bit = 0;
		data.current_char = 0;

		if (data.client_pid != 0)
			kill(data.client_pid, SIGUSR1);
	}
}

int main(void)
{
	struct sigaction sa;
	
	sigemptyset(&sa.sa_mask);
	//sigaddset(&sa.sa_mask, SIGUSR1);
	//sigaddset(&sa.sa_mask, SIGUSR2);

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		printf("Error Regestering SIGUSR1 handler");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		printf("Error registering SIGUSR2 handler");
		return (1);
	}
	printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
