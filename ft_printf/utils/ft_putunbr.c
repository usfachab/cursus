/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:55:51 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/14 06:37:45 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(int nbr)
{
	static int		i;
	unsigned int	n;

	i = 0;
	n = nbr;
	if (n > 9)
		ft_putunbr(n / 10);
	i++;
	ft_putchar(n % 10 + 48);
	return (i);
}
