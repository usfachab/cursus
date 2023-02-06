/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkHelp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:44:56 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/11 23:18:36 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	check_char(char **line, s_data *data)
{
	if (line[data->i][data->j] == 'P')
		data->n_player += 1;
	if (line[data->i][data->j] == 'C')
		data->n_collect += 1;
	if (line[data->i][data->j] == 'E')
		data->n_exit += 1;
	if (line[data->i][data->j] != '1'
		&& line[data->i][data->j] != '0'
		&& line[data->i][data->j] != 'C'
		&& line[data->i][data->j] != 'P'
		&& line[data->i][data->j] != 'E')
		err_msg("Error: Some charachter is not true\n", data, line);
}