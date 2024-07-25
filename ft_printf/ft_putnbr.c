/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:39:35 by mjuicha           #+#    #+#             */
/*   Updated: 2023/12/05 17:10:17 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-', count);
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0', count);
	}
	else
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
}

void	ft_putunsignednbr(unsigned int n, int *count)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0', count);
	else
	{
		ft_putunsignednbr(n / 10, count);
		ft_putchar((n % 10) + '0', count);
	}
}
