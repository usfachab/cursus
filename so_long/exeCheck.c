/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeCheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:06:03 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/16 12:44:38 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

int	execheck(char *string, char *argv)
{
	char	**map;
	t_pos	position;

	map = ft_split(string, '\n');
	if (!map)
		err_msg("Error: split throw exception!\n");
	check_map_file(argv);
	check_new_line(string);
	check_char(string);
	check_wall(map);
	count_charachters(string);
	get_position(map, &position, 'P');
	ft_flood(map, position);
	_blocked(map);
	map = ft_split(string, '\n');
	if (!map)
		err_msg("Error: split throw exception!\n");
	get_position(map, &position, 'E');
	make_e_one(map, &position);
	get_position(map, &position, 'P');
	ft_flood(map, position);
	_blocked(map);
	return (0);
}
