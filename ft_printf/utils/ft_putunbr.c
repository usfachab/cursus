/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:55:51 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/10 17:19:15 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(int nbr)
{
	static int		j;
	unsigned int	n;

	j = 0;
	n = nbr;
	if (n > 9)
		ft_putunbr(n / 10);
	j++;
	ft_putchar(n % 10 + 48);
	return (j);
}
