/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:16:44 by yachaab           #+#    #+#             */
/*   Updated: 2022/10/31 20:28:04 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* check if the characters of the main string is in set string */
static int	ft_is_set(char ch, const char *set)
{
	int	i;

	i = 0;
	while (*set)
	{
		if (ch == *set)
			return (1);
		set++;
	}
	return (0);
}

/*
	check if set is in the end of the string 
	and calculate the length of the string to allocate for
*/

static int	ft_end_set(const char *str, const char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (ft_is_set(str[i], set) || !str[i])
		i--;
	while (j <= i)
		j++;
	return (j);
}

/*
	the main function (check  if set is in the start of the string
	and execute ft_end_set for the length to allocate enough space) 
	use ft_strlcpy to copy the string 
*/

char	*ft_strtrim(const char *s1, const char *set)
{
	int		len;
	int		i;
	char	*tr;

	i = 0;
	if (!set)
		return (ft_strdup(s1));
	while (ft_is_set(s1[i], set))
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	len = ft_end_set(&s1[i], set);
	tr = ft_calloc(len + 1, sizeof(char));
	if (!tr)
		return (NULL);
	ft_strlcpy(tr, s1 + i, len + 1);
	return (tr);
}
