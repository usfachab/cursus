/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stderr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:17:43 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/15 12:09:36 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/so_long.h"

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	write (2, "bye!\n", 5);
	exit (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	err_msg(char *msg)
{
	int	len;

	len = ft_strlen(msg);
	write(2, msg, len);
	exit(1);
}
