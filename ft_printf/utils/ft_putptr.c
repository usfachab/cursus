/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:16:01 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/07 20:37:55 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	static int	i;

	i = 0;
	if (ptr > 15)
		ft_putptr(ptr / 16);
	if (ptr % 16 > 9)
	{
		ft_putchar(ptr % 16 + 87);
		i++;
	}
	else
	{
		ft_putchar(ptr % 16 + 48);
		i++;
	}
	return (i);
}
