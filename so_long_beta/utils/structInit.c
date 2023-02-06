/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structInit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:10:42 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/12 00:26:57 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

s_data	*val_init(s_data *data)
{
	data->n_row = 0;
	data->n_collect = 0;
	data->n_player = 0;
	data->n_exit = 0;
	data->i = 0;
	return (data);
}

s_var init_fat(void)
{
	s_var wall_vars;
	
	wall_vars.i = 0;
	wall_vars.j = 0;
	wall_vars.k = 0;
	return (wall_vars);
}

void	init_data(s_data *data, char *string)
{
	s_data	*test;
	s_pos	pl_pos;
	s_pos	exit_pos;
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->string = string;
	data->map = ft_split(string, '\n');
	pl_pos = player_position(data->map, 'P');
	exit_pos = player_position(data->map, 'E');
	data->img_height = 60;
	data->img_width = 60;
	int len = 0;
	while (data->map[len])
		len++;
	data->len_row = len;
	data->len_col = ft_strlen(data->map[0]);
	data->mlx_win = mlx_new_window(data->mlx, data->len_col * IMGX, data->len_row * IMGY, "Hello world!");
	if (!data->mlx_win)
		exit(1);
	data->pl_pos_x = pl_pos.x;
	data->pl_pos_y = pl_pos.y;
	data->exit_pos_x = exit_pos.x;
	data->exit_pos_y = exit_pos.y;
	test = check_line(data->map);
	data->n_collect = test->n_collect;
}