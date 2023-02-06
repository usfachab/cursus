/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:55:51 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/14 06:30:18 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nbr)
{
	int			sign;
	static int	i;

	i = 0;
	sign = 0;
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
		ft_putnbr(nbr / 10);
	i += ft_putchar(nbr % 10 + 48);
	return (i + sign);
}
