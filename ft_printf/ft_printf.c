/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:33 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/14 06:34:58 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_check_param(const char param, va_list args)
{
	if (param == '%')
		return (ft_putchar('%'));
	if (param == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (param == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (param == 'd' || param == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (param == 'u')
		return (ft_putunbr(va_arg(args, int)));
	if (param == 'x' || param == 'X')
		return (ft_puthex(va_arg(args, int), param));
	if (param == 'p')
	{
		ft_putstr("0x");
		return (ft_putptr(va_arg(args, unsigned long)) + 2);
	}
	else
		return (ft_putchar(param));
	return (0);
}

int	ft_printf(const char *placeholder, ...)
{
	int		i;
	int		s;
	va_list	args;

	i = 0;
	s = 0;
	va_start(args, placeholder);
	while (placeholder[i])
	{
		if (placeholder[i] == '%')
		{
			if (placeholder[i + 1] == '\0')
				break ;
			s += ft_check_param(placeholder[i + 1], args);
			i++;
		}
		else
			s += ft_putchar(placeholder[i]);
		i++;
	}
	va_end(args);
	return (s);
}
