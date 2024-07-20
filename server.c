/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:20:32 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/20 11:38:03 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_signal(int signal)
{
	static char	current_char;
	static int	b;

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
	ft_printf("SERVER PID: %d\n", getpid());
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1)
		pause();
	return (0);
}
