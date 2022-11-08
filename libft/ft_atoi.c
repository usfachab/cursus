/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:25 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/01 10:11:09 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*skip all while spaces and check if the string passed start with a - sign*/
static int	ft_skip(const char *str, int i, int *sign)
{
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

/*
  -> loop thrugh the string passed and check
  	if the charachter is a number or not
  -> start converting & check if the stored
  	value (number) is greather than the long max
*/

int	ft_atoi(const char	*str)
{
	int				i;
	int				sign;
	unsigned long	stored_value;

	sign = 1;
	i = 0;
	stored_value = 0;
	i = ft_skip(str, i, &sign);
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (stored_value > __LONG_MAX__)
			break ;
		stored_value = (stored_value * 10) + (str[i] - 48);
		i++;
	}
	if (stored_value > __LONG_MAX__)
	{
		if (sign < 0)
			return (0);
		return (-1);
	}
	return (stored_value * sign);
}
