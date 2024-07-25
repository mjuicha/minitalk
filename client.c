/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:21:19 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/24 04:27:53 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	errors_in_main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	if (!check(av[1]))
		return (1);
	return (0);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	send_msg(int pid, char *str)
{
	int	i;
	int	b;

	i = 0;
	while (1)
	{
		b = 8;
		while (b--)
		{
			if (((str[i] >> b) & 1) == 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error();
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_error();
			}
			usleep(900);
		}
		if (str[i] == '\0')
			break ;
		i++;
	}
}

int	main(int ac, char *av[])
{
	int		pid;
	char	*msg;

	if (errors_in_main(ac, av))
		return (-1);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (-1);
	msg = av[2];
	send_msg(pid, msg);
	return (0);
}
