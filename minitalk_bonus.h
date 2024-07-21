/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:01:44 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/21 13:36:53 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <unistd.h>

typedef struct struct_unicode
{
	char			p[4];
	int				i;
	int				bytes;
}	t_unicode;

int		isoverflow(long long int check, long long int res);
int		is_sspace(const char *str, int *pt);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		check(char *str);

#endif