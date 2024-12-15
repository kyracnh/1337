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

signal_data data = {0, 0};

void	handle_signal(int signal)
{
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
	}
}

int main(void)
{
	struct sigaction sa;

	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("Error Regestering SIGUSR1 handler");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("Error registering SIGUSR2 handler");
		return (1);
	}
	printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
