/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:19:13 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/12 11:10:44 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/so_long.h"

void	free_exit(s_data *data)
{
	int i = 0;
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->string);
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	system("leaks so_long\n");
	exit(0);
	//free(data->map);
}	

int	key_hook(int keycode, s_data *data)
{
	if (keycode == 123 && (data->pl_pos_x > 1)
		&& (data->map[data->pl_pos_y][data->pl_pos_x - 1] != '1'))
		left(data);
		
    if (keycode == 124 && (data->pl_pos_x < data->len_col - 2)
		&& (data->map[data->pl_pos_y][data->pl_pos_x + 1] != '1'))
		right(data);

	if (keycode == 126 && (data->pl_pos_y > 1)
		&& (data->map[data->pl_pos_y - 1][data->pl_pos_x] != '1')) // right arrow
		up(data);

	if (keycode == 125 && (data->pl_pos_y < data->len_row - 1)
		&& (data->map[data->pl_pos_y + 1][data->pl_pos_x] != '1')) // right arrow
		down(data);
	if (data->n_collect == 0 && data->pl_pos_x == data->exit_pos_x && data->pl_pos_y == data->exit_pos_y)
		free_exit(data);
	ft_render(data);
    return 0;
}

void	convert_and_put_img(s_data *data, char *img_path, int _y, int _x)
{
	data->img = mlx_xpm_file_to_image(data->mlx, img_path, &(data->img_width), &(data->img_height));
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, _x * IMGX, _y * IMGY);
}

void	ft_render(s_data *data)
{
	int _y;
	int _x;

	mlx_clear_window(data->mlx, data->mlx_win);
	_y = 0;
	while (_y < data->len_row)
	{
		_x = 0;
		while (_x < data->len_col)
		{
			if (data->map[_y][_x] == '1')
				convert_and_put_img(data,"./img/wall.xpm", _y,  _x);
			if (data->map[_y][_x] == 'P')
				convert_and_put_img(data, "./img/player.xpm", _y,  _x);
			if (data->map[_y][_x] == 'C')
				convert_and_put_img(data, "./img/coin.xpm", _y,  _x);
			if (data->map[_y][_x] == 'E')
				convert_and_put_img(data, "./img/exit.xpm", _y,  _x);
			_x++;
		}
		_y++;
	}
}

int	main(int argc, char *argv[])
{
	if (main_func(argv[1]) == 0 && argc == 2)
	{
		s_data	data;
		int		fd;
		char	*string;
		fd = open(argv[1], O_RDONLY);
		string = read_file_lines(fd);
		close(fd);
		init_data(&data, string);
		ft_render(&data);
		mlx_key_hook(data.mlx_win, key_hook, &data);
		mlx_loop(data.mlx);
	}
}

