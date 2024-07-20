/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:41:02 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/20 11:41:53 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		isoverflow(long long int check, long long int res);
int		is_sspace(const char *str, int *pt);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		check(char *str);
int		errors_in_main(int ac, char **av);
void	send_msg(int pid, char *str);
void	receive_signals(int signal);
#endif
