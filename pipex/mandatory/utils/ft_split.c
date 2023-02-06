/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:16:09 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/21 13:35:19 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

static char	**ft_free(char **word)
{
	int	i;

	i = 0;
	while (word[i])
	{
		free(word[i]);
		i++;
	}	
	free(word);
	return (NULL);
}

static int	count_word(const char *string, char delim)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] != delim
			&& (string[i + 1] == delim || string[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**word_alloc(const char *s, char d)
{
	char	**word;

	word = (char **)ft_calloc(sizeof(char *), count_word(s, d) + 1);
	return (word);
}

static char	*str_cpy(const char *string, int size)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = ft_calloc(sizeof(char), size + 1);
	if (!ptr)
		return (0);
	while (i < size)
	{
		ptr[i] = *string;
		i++;
		string++;
	}
	return (ptr);
}

char	**ft_split(const char *string, char delim)
{
	int		i;
	int		index;
	int		size;
	int		char_index;
	char	**word;

	i = 0;
	index = -1;
	word = word_alloc(string, delim);
	if (!word)
		return (NULL);
	while (++index < count_word(string, delim))
	{
		while (string[i] == delim)
			i++;
		char_index = i;
		size = 0;
		i--;
		while (string[++i] != delim && string[i])
			size++;
		word[index] = str_cpy(string + char_index, size);
		if (word[index] == NULL)
			return (ft_free(word));
	}
	return (word);
}
