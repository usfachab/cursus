/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:33 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/07 20:36:33 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_param(const char param, va_list list_pointer)
{
	if (param == '%')
		return (ft_putchar('%'));
	if (param == 'c')
		return (ft_putchar(va_arg(list_pointer, int)));
	if (param == 's')
		return (ft_putstr(va_arg(list_pointer, char *)));
	if (param == 'd' || param == 'i')
		return (ft_putnbr(va_arg(list_pointer, int)));
	if (param == 'u')
		return (ft_putunbr(va_arg(list_pointer, int)));
	if (param == 'x' || param == 'X')
		return (ft_puthex(va_arg(list_pointer, int), param));
	if (param == 'p')
	{
		ft_putstr("0x");
		return (ft_putptr(va_arg(list_pointer, unsigned long)) + 2);
	}
	return (0);
}

int	ft_printf(const char *placeholder, ...)
{
	int		i;
	int		s;
	va_list	list_pointer;

	i = 0;
	s = 0;
	va_start(list_pointer, placeholder);
	while (placeholder[i])
	{
		if (placeholder[i] == '%')
		{
			while (placeholder[i + 1] == ' ')
				placeholder++;
			if (placeholder[i + 1] == '\0')
				break ;
			s += ft_check_param(placeholder[i + 1], list_pointer);
			i++;
		}
		else
			s += ft_putchar(placeholder[i]);
		i++;
	}
	va_end(list_pointer);
	return (s);
}

/*
	1- va_list create a pointer that well point to 
	the first element of the VARIABLE ARGUMENT LIST.
	currently list_pointer is UNINTIALIZED
*/

/* 
	2- va_start now we make list_pointer point to
	the first argument in the list "VARIABLE ARGUMENT LIST".
	PLACEHOLDER argument is called the "LAST MANDATORY ARGUMENT"
*/

/*
	3- va_args(list_pointer, type) return the value of the
	argument pointer by list_pointer and update to pointer
	the next argument in this list
*/