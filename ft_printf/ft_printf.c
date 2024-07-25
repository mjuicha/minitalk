/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:00:57 by mjuicha           #+#    #+#             */
/*   Updated: 2024/01/04 01:24:46 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mm(va_list ap, const char format, int *count)
{
	if (format == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(ap, int), count);
	else if (format == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (format == 'u')
		ft_putunsignednbr(va_arg(ap, unsigned int), count);
	else if (format == 'x')
		lowerhex(va_arg(ap, unsigned int), count);
	else if (format == 'X')
		upperhex(va_arg(ap, unsigned int), count);
	else if (format == 'p')
		ft_address(va_arg(ap, void *), count);
	else if (format == '%')
		ft_putchar('%', count);
	else
		ft_putchar(format, count);
	return (*count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	if (write(1, "", 0) < 0)
		return (-1);
	va_start(ap, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			mm(ap, format[++i], &count);
			i++;
		}
		else
			ft_putchar(format[i++], &count);
	}
	va_end(ap);
	return (count);
}
