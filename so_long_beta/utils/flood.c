/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:38:37 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/12 20:40:56 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

void	flood(char **line, s_data *size, s_pos pos)
{
    s_pos p;
	
    line[pos.y][pos.x] = 'F';
    if (pos.y > 1 && (line[pos.y - 1][pos.x] == '0' || line[pos.y - 1][pos.x] == 'C' || line[pos.y - 1][pos.x] == 'E' || line[pos.y - 1][pos.x] == 'P'))
    {
        p.x = pos.x;
        p.y = pos.y - 1;
        flood(line, size, p); 
    }
    if ((pos.y < (size->n_row - 1)) && (line[pos.y + 1][pos.x] == '0' || line[pos.y + 1][pos.x] == 'P' || line[pos.y + 1][pos.x] == 'C' || line[pos.y + 1][pos.x] == 'E'))
    {
        p.x = pos.x;
        p.y = pos.y + 1;
        flood(line, size, p);
    }
    if ((pos.x < (size->n_col[0] - 1)) && (line[pos.y][pos.x + 1] == '0' || line[pos.y][pos.x + 1] == 'P' || line[pos.y][pos.x + 1] == 'C' || line[pos.y][pos.x + 1] == 'E'))
    {
        p.x = pos.x + 1;
        p.y = pos.y;
        flood(line, size, p);
    }
    if (pos.x > 1 && (line[pos.y][pos.x - 1] == '0' || line[pos.y][pos.x - 1] == 'P' || line[pos.y][pos.x - 1] == 'C' || line[pos.y][pos.x - 1] == 'E'))
    {
        p.x = pos.x - 1;
        p.y = pos.y;
        flood(line, size, p);
    }
}
