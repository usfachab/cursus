/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:32:50 by yachaab           #+#    #+#             */
/*   Updated: 2022/11/22 16:02:42 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*trim(char *n_tr_line)
{
	int		i;
	char	*tr_line;

	i = 0;
	if (!n_tr_line)
		return (NULL);
	i = is_new_line(n_tr_line);
	if (i < 0)
		return (ft_strdup(n_tr_line));
	tr_line = malloc(i + 1);
	if (!tr_line)
		return (NULL);
	i = 0;
	while (n_tr_line[i] != '\n')
	{
		tr_line[i] = n_tr_line[i];
		i++;
	}
	tr_line[i] = '\n';
	tr_line[i + 1] = '\0';
	return (tr_line);
}

static char	*rest_line(char *n_tr_line)
{
	int		j;
	char	*rest_line;

	if (!n_tr_line)
		return (NULL);
	if (is_new_line(n_tr_line) < 0)
	{
		free(n_tr_line);
		return (NULL);
	}
	j = 0;
	while (n_tr_line[is_new_line(n_tr_line) + j] != '\0')
		j++;
	rest_line = malloc(j + 1);
	if (!rest_line)
		return (NULL);
	j = 0;
	while (n_tr_line[is_new_line(n_tr_line) + j] != '\0')
	{	
		rest_line[j] = n_tr_line[is_new_line(n_tr_line) + j];
		j++;
	}
	rest_line[j] = 0;
	free(n_tr_line);
	return (rest_line);
}

char	*read_line(int fd, char *hold)
{
	char		*buffer;
	ssize_t		readed;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1 || (readed <= 0 && *hold == '\0'))
			return (tobe_freed(&hold, &buffer));
		buffer[readed] = 0;
		hold = ft_strjoin(hold, buffer);
		if (!hold)
			return (tobe_freed(&hold, &buffer));
		if (is_new_line(hold) >= 0 || readed == 0)
			break ;
	}
	free(buffer);
	return (hold);
}

void	*tobe_freed(char **line, char **buffer)
{
	free(*line);
	free(*buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*n_tr_line;
	char			*tr_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10240)
		return (NULL);
	if (!n_tr_line)
		n_tr_line = ft_strdup("");
	n_tr_line = read_line(fd, n_tr_line);
	tr_line = trim(n_tr_line);
	n_tr_line = rest_line(n_tr_line);
	return (tr_line);
}
