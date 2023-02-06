/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:40:13 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/10 20:51:31 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

char	*read_file_lines(int fd)
{
	int		readed;
	char	*string;
	char	*buffer;

	readed = 0;
	string = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	while (1)
	{
		readed = read(fd, buffer, 1);
		if (readed == 0)
			break ;
		buffer[readed] = 0;
		string = ft_strjoin(string, buffer);
		//free(string);
		//string = tmp;
	}
	free(buffer);
	return (string);
}