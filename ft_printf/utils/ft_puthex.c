/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:19:19 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/09 15:46:03 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(int hex, char param)
{
	static int		i;
	int				dec;
	unsigned int	uhex;

	dec = 87;
	uhex = hex;
	i = 0;
	if (param == 'X')
		dec = 55;
	if (uhex > 15)
		ft_puthex(uhex / 16, param);
	if (uhex % 16 > 9)
		i += ft_putchar(uhex % 16 + dec);
	else
		i += ft_putchar(uhex % 16 + 48);
	return (i);
}
