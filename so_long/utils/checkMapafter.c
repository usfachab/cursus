/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapafter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:41:41 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/16 12:36:03 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

// this function for change exit to 1 and check 
//if it blocks one of the main charachters
void	make_e_one(char **map, t_pos *exit_pos)
{
	map[exit_pos->y][exit_pos->x] = '1';
}

// this func helps _blocked func
static int	what_rest(char **map, int y, int x)
{
	if (map[y][x] == 'C' || map[y][x] == 'E' || map[y][x] == 'P')
		return (1);
	else
		return (0);
}

// check the remainning charachters if true the map is invalid
void	_blocked(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (what_rest(map, i, j))
			{
				err_msg("Error: there is some blocked charachter\n");
			}
			j++;
		}
		i++;
	}
}
