/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:48:51 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/01 18:24:39 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

void	ft_pipex(t_var *args)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) < 0)
		err_msg("Error: pipe");
	pid1 = fork();
	if (pid1 < 0)
		err_msg("Error: fork");
	if (!pid1)
		child_pro_1(args, fd);
	else
	{
		pid2 = fork();
		if (pid2 < 0)
			err_msg("Error: fork");
		if (!pid2)
			child_pro_2(args, fd);
		close(fd[0]);
		close(fd[1]);
		close(args->infile);
		close(args->outfile);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
}
