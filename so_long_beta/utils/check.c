/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:20:08 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/12 11:09:57 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

// check file existance & extension
void	check_map_file(int fd, char *ext)
{
	int	i;
	
	i = 0;
	if (fd < 0)
		err_msg("Error: can't find this file\n", NULL, NULL);
	while (ext[i])
		i++;
	if (i < 5)
		err_msg("Error: map extension doesn't match\n", NULL, NULL);
	i -= 4;
	if (ext[i] != '.' || ext[i + 1] != 'b' || ext[i + 2] != 'e' || ext[i + 3] != 'r')
		err_msg("Error: map extension doesn't match\n", NULL, NULL);
}

// check for new lines
void	check_new_line(char *string)
{
	int	i;

	i = 0;
	if (string[i] == '\0' || string[i]== '\n')
		err_msg("Error: file corrapted\n", NULL, NULL);
	while (string[i])
	{
		if ((string[i] == '\n' && string[i + 1] == '\n') || (string[i] == '\n' && string[i + 1] == '\0'))
			err_msg("Error: two or more new line\n", NULL, NULL);
		i++;
	}
}

void	check_map_size(s_data *data)
{
	if (data->n_player != 1 || data->n_exit != 1 || data->n_collect < 1)
		err_msg("more than 1 player or exit or less than 1 collective\n", data, data->map);
	data->j = 0;
	while (data->n_col[data->j + 1] != 0)
	{
		if (data->n_col[data->j] != data->n_col[data->j + 1])
			err_msg("Error: something wrong in the length of cols and rows\n", data, data->map);
		data->j++;
	}
}

// calculate number of P and C and E also rows and cols
s_data	*check_line(char **line)
{
	s_data	*data;
	data  = (s_data *)malloc(sizeof(s_data));
	data = val_init(data);

	while (line[data->i])
	{
		data->j = 0;
		while (line[data->i][data->j])
		{
			check_char(line, data);
			data->j++;
			data->n_col[data->i] = data->j;
		}
		data->n_row++;
		data->i++;
	}
	data->n_col[data->i] = 0;
	check_map_size(data);
	return (data);
}

void	check_wall(char **line)
{
	s_var	fat;
	s_data	*map;

	map = check_line(line);
	fat = init_fat();
	// while(line[fat.i])
	// 	fat.i++;
	fat.j = map->n_col[0];
	fat.i = map->n_row;
	if (ft_strcmp(line[0], line[fat.i - 1]) != 0)
		err_msg("Error: First and last row are not the same\n", map, line);
	// while (line[fat.i - 1][fat.k])
	// {
	// 	if (line[fat.i - 1][fat.k] != '1')
	// 		err_msg("Error: fchkel hadchi\n", map);
	// 	fat.k++;
	// }
	fat.i = 0;
	while (line[fat.i])
	{
		if (line[fat.i][0] != '1' || line[fat.i][fat.j - 1] != '1')
			err_msg("Error: right col is diffrent then the left\n", map, line);
		fat.i++;
	}
}