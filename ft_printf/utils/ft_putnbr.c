/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:55:51 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/09 15:46:08 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nbr)
{
	static int	i;
	int			sign;

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
