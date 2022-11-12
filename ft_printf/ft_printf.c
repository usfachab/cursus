/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:33 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/12 09:15:37 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	operation(const char *placeholder, va_list args)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (placeholder[i])
	{
		if (placeholder[i] == '%')
		{
			while (placeholder[i + 1] == ' ')
				i++;
			if (placeholder[i] == ' ')
				s += ft_putchar(' ');
			if (placeholder[i + 1] == '\0')
				break ;
			s += ft_check_param(placeholder[i + 1], args);
			i++;
		}
		else
			s += ft_putchar(placeholder[i]);
		i++;
	}
	return (s);
}

int	ft_printf(const char *placeholder, ...)
{
	int		s;
	va_list	args;

	s = 0;
	va_start(args, placeholder);
	s = operation(placeholder, args);
	va_end(args);
	return (s);
}

/*
	1- va_list create a pointer that well point to 
	the first element of the VARIABLE ARGUMENT LIST.
	currently args is UNINTIALIZED
*/

/* 
	2- va_start now we make args point to
	the first argument in the list "VARIABLE ARGUMENT LIST".
	PLACEHOLDER argument is called the "LAST MANDATORY ARGUMENT"
*/

/*
	3- va_args(args, type) return the value of the
	argument pointer by args and update to pointer
	the next argument in this list
*/