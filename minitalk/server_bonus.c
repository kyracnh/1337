/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanmazir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:55:22 by aanmazir          #+#    #+#             */
/*   Updated: 2024/12/22 11:21:47 by aanmazir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf/ft_printf.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;
	static char	current_char = 0;
	static int	current_bit = 0;

	current_char <<= 1;
	if (signal == SIGUSR1)
		current_char |= 0;
	else if (signal == SIGUSR2)
		current_char |= 1;
	current_bit++;
	if (current_bit == 8)
	{
		write(1, &current_char, 1);
		if (current_char == '\0')
			kill(info->si_pid, SIGUSR1);
		current_bit = 0;
		current_char = 0;
	}
}

int main(void)
{
	struct sigaction sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	//sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error Regestering SIGUSR1 handler");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error registering SIGUSR2 handler");
		return (1);
	}
	ft_printf("Server PID 📡: %d\n", getpid());
	while (1)
	{}
	return (0);
}
