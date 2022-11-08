/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:44:06 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/05 11:49:29 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	char	*bigo;

	i = 0;
	bigo = (char *)big;
	if (little[i] == '\0')
		return (bigo);
	while (i < len && bigo[i])
	{
		j = 0;
		while ((bigo[i + j] == little[j]) && (i + j) < len)
		{
			if (little[j + 1] == '\0' )
				return (bigo + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
