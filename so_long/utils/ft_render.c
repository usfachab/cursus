/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:53:13 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/18 20:54:59 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	convert_and_put_img(t_data *data, char *img_path, int _y, int _x)
{
	int	img_width;
	int	img_height;

	data->img = mlx_xpm_file_to_image(data->mlx, img_path,
			&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img, _x * IMGX, _y * IMGY);
}

void	ft_render(t_data *data)
{
	int	_y;
	int	_x;

	_y = 0;
	mlx_clear_window(data->mlx, data->mlx_win);
	while (_y < data->n_row)
	{
		_x = 0;
		while (_x < data->n_col)
		{
			if (data->map[_y][_x] == '1')
				convert_and_put_img(data, "./img/wall.xpm", _y, _x);
			if (data->map[_y][_x] == 'P')
				convert_and_put_img(data, "./img/player.xpm", _y, _x);
			if (data->map[_y][_x] == 'C')
				convert_and_put_img(data, "./img/coin.xpm", _y, _x);
			if (data->map[_y][_x] == 'E')
				convert_and_put_img(data, "./img/exit.xpm", _y, _x);
			_x++;
		}
		_y++;
	}
}
