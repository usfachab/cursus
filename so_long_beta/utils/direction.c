/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:32:32 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/10 17:10:15 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	left(s_data *data)
{
	if (data->map[data->pl_pos_y][data->pl_pos_x - 1] == 'C')
		data->n_collect -= 1;
	data->map[data->pl_pos_y][data->pl_pos_x] = '0';
	data->pl_pos_x -= 1;
	data->map[data->pl_pos_y][data->pl_pos_x] = 'P';
}


void	right(s_data *data)
{
	if (data->map[data->pl_pos_y][data->pl_pos_x + 1] == 'C')
		data->n_collect -= 1;
	data->map[data->pl_pos_y][data->pl_pos_x] = '0';
	data->pl_pos_x += 1;
	data->map[data->pl_pos_y][data->pl_pos_x] = 'P';	
}

void	up(s_data *data)
{
	if (data->map[data->pl_pos_y - 1][data->pl_pos_x] == 'C')
		data->n_collect -= 1;
	data->map[data->pl_pos_y][data->pl_pos_x] = '0';
	data->pl_pos_y -= 1;
	data->map[data->pl_pos_y][data->pl_pos_x] = 'P';
}

void	down(s_data *data)
{
	if (data->map[data->pl_pos_y + 1][data->pl_pos_x] == 'C')
		data->n_collect -= 1;
	data->map[data->pl_pos_y][data->pl_pos_x] = '0';
	data->pl_pos_y += 1;
	data->map[data->pl_pos_y][data->pl_pos_x] = 'P';	
}
