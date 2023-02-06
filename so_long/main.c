/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:04:06 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/15 12:08:38 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/so_long.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	*string;
	t_data	data;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || fd > 10240)
		err_msg("Error: can't find this file\n");
	string = read_file_lines(fd);
	if (!string)
		err_msg("Error: read_file_lines throw exception!\n");
	close(fd);
	if (execheck(string, argv[1]) == 0 && argc == 2)
	{
		init_data(&data, string);
		ft_render(&data);
		mlx_key_hook(data.mlx_win, key_hook, &data);
		mlx_hook(data.mlx_win, 17, 0L, ft_close, &data);
		mlx_loop(data.mlx);
	}
	else
		err_msg("Error: less or more than 2 arguments\n");
	return (0);
}
