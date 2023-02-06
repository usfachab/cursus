/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dry.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:12:43 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/01 18:11:16 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

static void	first_cmd(t_var *args, int who)
{
	args->infile = open(args->argv[1], O_RDONLY);
	if (args->infile < 0)
		err_msg("Error: can't open infile check permission or file existance");
	if (!args->argv[2][0])
		err_msg("Error: Command not found.");
	if (dup2(args->infile, STDIN_FILENO) < 0)
		err_msg("Error: dup 2 of command 1 failed.");
	dry(args, who);
	err_msg("Error: cmd1 not executed.");
}

static void	second_cmd(t_var *args, int who)
{
	args->outfile = open(args->argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (args->outfile < 0)
		err_msg("Error: can't open outfile");
	if (!args->argv[3][0])
		err_msg("Error: Command not found.");
	if (dup2(args->outfile, STDOUT_FILENO) < 0)
		err_msg("Error: dup 2 of command 2 failed.");
	dry(args, who);
	err_msg("Error: command 2 not executed.");
}

void	child_pro_1(t_var *args, int *fd)
{
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		err_msg("Error: dup 2 of child 1 failed.");
	first_cmd(args, 0);
}

void	child_pro_2(t_var *args, int *fd)
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) < 0)
		err_msg("Error: dup 2 of child 2 failed.");
	second_cmd(args, -1);
}

void	dry(t_var *args, int who)
{
	int		i;
	char	**_cmdarg;
	char	*str;

	i = 0;
	if (who == 0)
		_cmdarg = args->cmd1args;
	else
		_cmdarg = args->cmd2args;
	str = ft_strrchr(_cmdarg[0], '/');
	while (args->splited_paths[i])
	{
		if (!args->splited_paths[i] || !_cmdarg[0])
			err_msg("Error: command not found.");
		check_and_join(args, _cmdarg, str, i);
		if (!args->path)
			err_msg("Error: command path not found");
		if (access(args->path, X_OK) == 0)
			execve(args->path, _cmdarg, args->env);
		free(args->path);
		i++;
	}
	free_cmdarg(_cmdarg);
}
