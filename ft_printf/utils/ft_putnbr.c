/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:55:51 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/07 20:37:41 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int nbr)
{
	int			sign;
	static int	i;

	sign = 0;
	i = 0;
	if (nbr == -2147483648)
	{
		i += write(1, "-2147483648", 11);
		return (i);
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		sign = 1;
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
	}
	i += ft_putchar(nbr % 10 + 48);
	return (i + sign);
}
