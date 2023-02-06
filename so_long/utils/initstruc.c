/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstruc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:55:33 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/14 17:55:51 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	init_data(t_data *data, char *string)
{
	data->mlx = mlx_init();
	data->string = string;
	data->map = ft_split(data->string, '\n');
	data->n_row = row_len(data->map);
	data->n_col = col_len(data->map);
	data->mlx_win = mlx_new_window(data->mlx,
			data->n_col * IMGX, data->n_row * IMGY, "Hello world!");
	data->n_collect = init_collect(data->string);
}
