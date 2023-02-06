/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:57:09 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/11 22:45:48 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

void	check_blockage(s_data *map_size, char **line)
{
	int		i;
	int		j;

	i = 1;
	while (i < map_size->n_row)
	{
		j = 1;
		while (j < map_size->n_col[0])
		{
			if (line[i][j] == 'C' || line[i][j] == 'E'
				|| line[i][j] == 'P' || line[i][j] == '0')
				err_msg("Error: there is some blockage\n", map_size, line);
			j++;
		}
		i++;
	}
}

void	get_map_size(char **line)
{
	s_data	*map_size;
	s_pos	player_pos;

	map_size = check_line(line);
	player_pos = player_position(line, 'P');
	flood(line, map_size, player_pos);
}


int	main_func(char *argv)
{
	s_data		*map_size;
	s_pos		check_pl_pos;
	int			fd;
	char		*string;
	char		**line;

	fd = open(argv, O_RDONLY);
	check_map_file(fd, argv);
	string = read_file_lines(fd);
	
	close(fd);
	
	check_new_line(string);
	line = ft_split(string, '\n');
	check_line(line);
	map_size = check_line(line);
	check_wall(line);
	check_pl_pos = player_position(line, 'P');
	get_map_size(line);
	check_blockage(map_size, line);
	int i = 0;
	free(map_size->map);
	free(map_size);
	free(string);
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
	return (0);
}
