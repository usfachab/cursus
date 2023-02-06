/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:48:51 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/04 11:43:53 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex_bonus.h"

void	ft_pipex(t_var *args)
{
	int	i;
	int	_isheredoc;

	i = 0;
	init_pipes(args->fd, args->cmd_nbr);
	_isheredoc = ft_memcmp(args->argv[1], "here_doc", 8);
	if (_isheredoc == 0)
		ft_heredoc(args->fd[0][1], args->argv[2]);
	close(args->fd[0][1]);
	while (i < args->cmd_nbr)
	{
		args->pid[i] = fork();
		if (args->pid[i] < 0)
			err_msg("Error: problem in forking");
		if (args->pid[i] == 0)
		{
			if ((access(args->infile_path, R_OK) < 0 && _isheredoc)
				|| access(args->argv[args->ac - 1], F_OK) < 0)
				err_msg("Error: Permission denied1111");
			exec_cmd(args, i, _isheredoc);
		}
		i++;
	}
	close_wait(args);
}
