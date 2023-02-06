/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:29:21 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/14 17:57:02 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

static void	ft_destro(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	write(1, "You win!\n", 9);
	exit(0);
}

static void	init_element(t_data *data)
{
	int		i;
	t_pos	pl_pos;

	i = 0;
	get_position(data->map, &pl_pos, 'P');
	data->pl_pos_x = pl_pos.x;
	data->pl_pos_y = pl_pos.y;
	get_position(data->map, &pl_pos, 'E');
	data->e_pos_x = pl_pos.x;
	data->e_pos_y = pl_pos.y;
}

int	key_hook(int keycode, t_data *data)
{
	static int	i;

	init_element(data);
	if ((keycode == 123 || keycode == 0) && (data->pl_pos_x > 1)
		&& (data->map[data->pl_pos_y][data->pl_pos_x - 1] != '1'))
		left(data, &i);
	if ((keycode == 124 || keycode == 2) && (data->pl_pos_x < data->n_col - 2)
		&& (data->map[data->pl_pos_y][data->pl_pos_x + 1] != '1'))
		right(data, &i);
	if ((keycode == 126 || keycode == 13) && (data->pl_pos_y > 1)
		&& (data->map[data->pl_pos_y - 1][data->pl_pos_x] != '1'))
		up(data, &i);
	if ((keycode == 125 || keycode == 1) && (data->pl_pos_y < data->n_row - 1)
		&& (data->map[data->pl_pos_y + 1][data->pl_pos_x] != '1'))
		down(data, &i);
	if (keycode == 53)
		err_msg("You exit\n");
	if (data->n_collect == 0 && data->pl_pos_x == data->e_pos_x
		&& data->pl_pos_y == data->e_pos_y)
		ft_destro(data);
	ft_render(data);
	return (0);
}
