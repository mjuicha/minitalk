/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:20:32 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/21 13:49:19 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_reset(unsigned char *current_char, int *b)
{
	*current_char = 0;
	*b = 0;
}

void	receive_signal(int signal, siginfo_t *s, void *c)
{
	static unsigned char	current_char;
	static int				b;
	static int				pid;

	c = 0;
	if (pid != s->si_pid)
		ft_reset(&current_char, &b);
	pid = s->si_pid;
	current_char <<= 1;
	current_char |= (signal == SIGUSR2);
	b++;
	if (b == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		b = 0;
		current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &receive_signal;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("SERVER PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
