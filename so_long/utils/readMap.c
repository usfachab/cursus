/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:40:13 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/14 17:17:45 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

char	*read_file_lines(int fd)
{
	int		readed;
	char	*string;
	char	*buffer;
	char	*tmp;

	readed = 0;
	string = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		readed = read(fd, buffer, 1);
		if (readed == 0)
			break ;
		buffer[readed] = 0;
		tmp = ft_strjoin(string, buffer);
		free(string);
		string = tmp;
	}
	free(buffer);
	return (string);
}
