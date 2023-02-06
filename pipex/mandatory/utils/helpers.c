/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:57:31 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/28 13:57:23 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

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

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	if (len > 0)
	{
		while (i < len)
		{
			str[i] = (unsigned char)c;
			i++;
		}
		return (str);
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((count != 0 && (size > SIZE_MAX / count)))
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, (count * size));
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
			i--;
	}
	return (NULL);
}
