/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:57:07 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/13 19:46:53 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

// check file existance & extension
void	check_map_file(char *fileName)
{
	int	i;

	i = 0;
	i = ft_strlen(fileName);
	if (i < 5)
		err_msg("Error: map fileName extension doesn't match\n");
	i -= 4;
	if (fileName[i] != '.' || fileName[i + 1] != 'b'
		|| fileName[i + 2] != 'e' || fileName[i + 3] != 'r')
		err_msg("Error: map extension doesn't match\n");
}

// check for new lines
void	check_new_line(char *string)
{
	int	i;

	i = 0;
	if (ft_strlen(string) == 0)
		err_msg("Error: new line at the end or emty file\n");
	while (string[i])
	{
		if ((string[i] == '\n' && string[i + 1] == '\n')
			|| (string[i] == '\n' && string[i + 1] == '\0'))
			err_msg("Error: two or more new line\n");
		i++;
	}
}

// this function helps calc_elem_and_size 
void	check_char(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] != '1'
			&& string[i] != '0'
			&& string[i] != 'C'
			&& string[i] != 'P'
			&& string[i] != 'E'
			&& string[i] != '\n')
			err_msg("Error: Some charachter is not true\n");
		i++;
	}
}

// check if there is a wall
void	check_wall(char **map)
{
	int		i;
	int		row_l;
	int		col_l;

	i = 0;
	row_l = row_len(map) - 1;
	col_l = col_len(map) - 1;
	if (ft_strcmp(map[0], map[row_l]) != 0)
		err_msg("Error: First and last row are not the same\n");
	while (map[0][i])
	{
		if (map[0][i] != '1')
			err_msg("Error: something wrong with first row and last row\n");
		if (map[row_l][i] != '1')
			err_msg("Error: something wrong with first row and last row\n");
		i++;
	}
	row_l = 0;
	while (map[row_l])
	{
		if (map[row_l][0] != '1' || map[row_l][col_l] != '1')
			err_msg("Error: right col is diffrent then the left\n");
		row_l++;
	}
}
/// man check this function |^ again