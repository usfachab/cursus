/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_var_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:14:52 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/04 11:43:32 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex_bonus.h"

int	*init_pid(int *pid, int cmd_nbr)
{
	pid = malloc(sizeof(int) * cmd_nbr);
	if (!pid)
		err_msg("Error: can't allocate for pid");
	return (pid);
}

int	**init_fd(int **fd, int cmd_nbr)
{
	int	i;

	i = 0;
	fd = (int **)malloc(sizeof(int *) * cmd_nbr);
	if (!fd)
		err_msg("Error: can't allocate for fd");
	i = 0;
	while (i < cmd_nbr)
	{
		fd[i] = malloc(sizeof(int) * 2);
		if (!fd[i])
			err_msg("Error: can't allocate for fd[i]");
		i++;
	}
	return (fd);
}

void	init_pipes(int **fd, int cmd_nbr)
{
	int	i;

	i = 0;
	while (i < cmd_nbr)
	{
		if (pipe(fd[i]) < 0)
			err_msg("Error: pipping problem");
		i++;
	}
}
