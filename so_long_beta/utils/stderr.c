/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stderr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:17:43 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/12 11:08:26 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	err_msg(char *msg, s_data *map, char **line)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(msg);
	write(2, msg, len);
	printf("%s-%s", map->string, line[0]);
	
	// if (map)
	// 	free(map);
	// if (line)
	// {
	// 	while (line[i])
	// 	{
	// 		free(line[i]);
	// 	}
	// }
	free(line);
	exit(1);
}