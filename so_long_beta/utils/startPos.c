/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startPos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:02:51 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/08 13:09:01 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

s_pos	player_position(char **map, char c)
{
	int			i;
	int			j;
	s_pos	pl_pos;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				pl_pos.y = i;
				pl_pos.x = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (pl_pos);
}