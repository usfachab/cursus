/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:38:26 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/03 22:28:24 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex_bonus.h"

static void	first_cmd(t_var *args, int i)
{
	int	_isheredoc;

	_isheredoc = ft_memcmp(args->argv[1], "here_doc", 8);
	if (_isheredoc == 0)
	{
		close (args->fd[i][1]);
		if (dup2(args->fd[i][0], STDIN_FILENO) < 0)
			err_msg("Error: problem in dupping infile");
		if (dup2(args->fd[i + 1][1], STDOUT_FILENO) < 0)
			err_msg("Error: problem in writing in 2 cmd");
	}
	else
	{
		close(args->fd[i][0]);
		close(args->fd[i][1]);
		if (dup2(args->infile, STDIN_FILENO) < 0)
			err_msg("Error: problem in dupping infile");
		if (dup2(args->fd[i + 1][1], STDOUT_FILENO) < 0)
			err_msg("Error: problem in writing in second cmd");
	}
}

static void	last_cmd(t_var *args, int i)
{
	close(args->fd[i][1]);
	if (dup2(args->fd[i][0], STDIN_FILENO) < 0)
		err_msg("Error: problem in reading in last cmd");
	if (dup2(args->outfile, STDOUT_FILENO) < 0)
		err_msg("Error: problem in writing in last cmd");
}

static void	other_cmd(t_var *args, int i)
{
	close(args->fd[i][1]);
	if (dup2(args->fd[i][0], STDIN_FILENO) < 0)
		err_msg("Error: problem in reading in other cmd");
	if (dup2(args->fd[i + 1][1], STDOUT_FILENO) < 0)
		err_msg("Error: problem in writing in other cmd");
}

void	exec_cmd(t_var *args, int i, int _isheredoc)
{
	int	k;

	k = 0;
	while (k < args->cmd_nbr)
	{
		if (i != k)
			close(args->fd[k][0]);
		if (i + 1 != k)
			close(args->fd[k][1]);
		k++;
	}
	if (i == 0)
	{
		if (args->infile < 0 && _isheredoc != 0)
			err_msg("Error: can't open infile");
		if (args->outfile < 0)
			err_msg("Error: can't open outfile");
		first_cmd(args, i);
	}
	else if (i != 0 && i != args->cmd_nbr - 1)
		other_cmd(args, i);
	else if (i != 0 && i == args->cmd_nbr - 1)
		last_cmd(args, i);
	_exec(args, i);
}

void	close_wait(t_var *args)
{
	int	i;

	i = 0;
	while (i < args->cmd_nbr)
	{
		close(args->fd[i][1]);
		i++;
	}
	close(args->infile);
	close(args->outfile);
	i = 0;
	while (i < args->cmd_nbr)
	{
		waitpid(args->pid[i], NULL, 0);
		i++;
	}
}
