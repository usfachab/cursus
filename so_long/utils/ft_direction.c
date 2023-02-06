/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:32:32 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/14 17:55:17 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	left(t_data *data, int *i)
{
	if (data->map[data->pl_pos_y][data->pl_pos_x - 1] == 'C')
		data->n_collect -= 1;
	if (data->map[data->pl_pos_y][data->pl_pos_x - 1] != 'E')
	{
		data->map[data->pl_pos_y][data->pl_pos_x] = '0';
		data->pl_pos_x -= 1;
		data->map[data->pl_pos_y][data->pl_pos_x] = 'P';
		*i += 1;
		ft_putnbr(*i);
		write(1, "\n", 1);
	}
	else if (data->map[data->pl_pos_y][data->pl_pos_x - 1] == 'E'
		&& data->n_collect == 0)
		data->pl_pos_x -= 1;
}

void	right(t_data *data, int *i)
{
	if (data->map[data->pl_pos_y][data->pl_pos_x + 1] == 'C')
		data->n_collect -= 1;
	if (data->map[data->pl_pos_y][data->pl_pos_x + 1] != 'E')
	{
		data->map[data->pl_pos_y][data->pl_pos_x] = '0';
		data->pl_pos_x += 1;
		data->map[data->pl_pos_y][data->pl_pos_x] = 'P';
		*i += 1;
		ft_putnbr(*i);
		write(1, "\n", 1);
	}
	else if (data->map[data->pl_pos_y][data->pl_pos_x + 1] == 'E'
		&& data->n_collect == 0)
		data->pl_pos_x += 1;
}

void	up(t_data *data, int *i)
{
	if (data->map[data->pl_pos_y - 1][data->pl_pos_x] == 'C')
		data->n_collect -= 1;
	if (data->map[data->pl_pos_y - 1][data->pl_pos_x] != 'E')
	{
		data->map[data->pl_pos_y][data->pl_pos_x] = '0';
		data->pl_pos_y -= 1;
		data->map[data->pl_pos_y][data->pl_pos_x] = 'P';
		*i += 1;
		ft_putnbr(*i);
		write(1, "\n", 1);
	}
	else if (data->map[data->pl_pos_y - 1][data->pl_pos_x] == 'E'
		&& data->n_collect == 0)
		data->pl_pos_y -= 1;
}

void	down(t_data *data, int *i)
{
	if (data->map[data->pl_pos_y + 1][data->pl_pos_x] == 'C')
		data->n_collect -= 1;
	if (data->map[data->pl_pos_y + 1][data->pl_pos_x] != 'E')
	{
		data->map[data->pl_pos_y][data->pl_pos_x] = '0';
		data->pl_pos_y += 1;
		data->map[data->pl_pos_y][data->pl_pos_x] = 'P';
		*i += 1;
		ft_putnbr(*i);
		write(1, "\n", 1);
	}
	else if (data->map[data->pl_pos_y + 1][data->pl_pos_x] == 'E'
		&& data->n_collect == 0)
		data->pl_pos_y += 1;
}
