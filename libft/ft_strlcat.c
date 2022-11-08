/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:25:18 by yachaab           #+#    #+#             */
/*   Updated: 2022/10/30 21:03:52 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlength;
	size_t	srclength;

	i = 0;
	srclength = ft_strlen(src);
	if (size == 0)
		return (srclength);
	dstlength = ft_strlen(dst);
	if (dstlength < size)
	{
		while (dstlength + i < size - 1 && src[i])
		{
			dst[dstlength + i] = src[i];
			i++;
		}
		dst[dstlength + i] = '\0';
		return (dstlength + srclength);
	}
	if (dstlength >= size)
		return (srclength + size);
	return (0);
}
