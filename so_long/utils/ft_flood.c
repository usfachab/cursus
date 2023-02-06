/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:49:59 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/15 12:20:01 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

static int	is_not_one(char **map, int y, int x)
{
	if (map[y][x] == '0' || map[y][x] == 'C'
		|| map[y][x] == 'E' || map[y][x] == 'P')
		return (1);
	else
		return (0);
}

static void	init_pos(t_pos *p, int x, int y)
{
	p->x = x;
	p->y = y;
}

void	ft_flood(char **map, t_pos pos)
{
	t_pos	p;

	map[pos.y][pos.x] = 'Y';
	if (pos.y > 1 && is_not_one(map, pos.y - 1, pos.x))
	{
		init_pos(&p, pos.x, pos.y - 1);
		ft_flood(map, p);
	}
	if (pos.y < row_len(map) - 2 && is_not_one(map, pos.y + 1, pos.x))
	{
		init_pos(&p, pos.x, pos.y + 1);
		ft_flood(map, p);
	}
	if (pos.x < col_len(map) - 2 && is_not_one(map, pos.y, pos.x + 1))
	{
		init_pos(&p, pos.x + 1, pos.y);
		ft_flood(map, p);
	}
	if (pos.x > 1 && is_not_one(map, pos.y, pos.x - 1))
	{
		init_pos(&p, pos.x - 1, pos.y);
		ft_flood(map, p);
	}
}
