/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initHelper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:38:59 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/14 17:57:17 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

// calculate the number of rows
int	row_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

// calculate the number of cols
int	col_len(char **map)
{
	int		i;
	size_t	last_row_len;

	i = 0;
	while (map[i])
		i++;
	i--;
	last_row_len = ft_strlen(map[i]);
	while (--i >= 0)
	{
		if (last_row_len != ft_strlen(map[i]))
			err_msg("Error: col length are not the same\n");
	}
	return (last_row_len);
}

// calculate number of P and C and E also rows and cols
void	count_charachters(char *string)
{
	int	i;
	int	p;
	int	c;
	int	e;

	i = 0;
	p = 0;
	c = 0;
	e = 0;
	while (string[i])
	{
		if (string[i] == 'P')
			p += 1;
		if (string[i] == 'C')
			c += 1;
		if (string[i] == 'E')
			e += 1;
		i++;
	}
	if (c < 1)
		err_msg("Error: less than one collect\n");
	if (p != 1)
		err_msg("Error: less or more than one player\n");
	if (e != 1)
		err_msg("Error: less or more than one exit\n");
}

// get payer or exit position
void	get_position(char **map, t_pos *position, char C)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == C)
			{
				position->x = j;
				position->y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	init_collect(char *string)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!string)
		err_msg("Error: string empty\n");
	while (string[i])
	{
		if (string[i] == 'C')
			j += 1;
		i++;
	}
	return (j);
}
