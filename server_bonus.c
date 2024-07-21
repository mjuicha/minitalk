/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:07:45 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/20 16:51:09 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*t;
	size_t			i;

	t = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		t[i] = (unsigned char)0;
		i++;
	}
}

void	ft_reset(unsigned char *current_char, int *b)
{
	*current_char = 0;
	*b = 0;
}

void	handle_unicode(unsigned char current_char, siginfo_t *s)
{
	static t_unicode	unicode;
	static int			pid;

	if (pid != s->si_pid)
	{
		pid = s->si_pid;
		unicode.bytes = 0;
		unicode.i = 0;
	}
	if (current_char >= 194 && current_char <= 223)
		unicode.bytes = 2;
	else if (current_char >= 224 && current_char <= 239)
		unicode.bytes = 3;
	else if (current_char >= 240 && current_char <= 244)
		unicode.bytes = 4;
	unicode.p[unicode.i++] = current_char;
	if (unicode.i == unicode.bytes)
	{
		write(1, unicode.p, unicode.i);
		unicode.i = 0;
		unicode.bytes = 0;
		ft_bzero(unicode.p, 4);
	}
}

void	signal_handler(int signal, siginfo_t *s, void *c)
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
		{
			ft_printf("\n");
			kill(s->si_pid, SIGUSR1);
		}
		else if (current_char > 0 && current_char <= 127)
			ft_printf("%c", current_char);
		else
			handle_unicode(current_char, s);
		b = 0;
		current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("SERVER PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
