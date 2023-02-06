/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:12:43 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/03 22:32:15 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex_bonus.h"

static void	free_cmdarg(char **_cmdarg)
{
	int	i;

	i = 0;
	while (_cmdarg[i])
	{
		free(_cmdarg[i]);
		_cmdarg[i] = NULL;
		i++;
	}
	free(_cmdarg);
	_cmdarg = NULL;
}

void	_exec(t_var *args, int proc_index)
{
	int		i;
	char	**_cmdarg;
	char	*str;

	i = 0;
	_cmdarg = ft_split(args->argv[proc_index + args->which], ' ');
	if (!args->splited_paths[i] || _cmdarg[0] == '\0')
		err_msg("Error: path or cmd args empty.");
	str = ft_strrchr(_cmdarg[0], '/');
	while (args->splited_paths[i])
	{
		check_and_join(args, _cmdarg, str, i);
		if (!args->path)
			err_msg("Error: joined path and cmd failed successfully.");
		if (access(args->path, X_OK) == 0)
			execve(args->path, _cmdarg, args->env);
		free(args->path);
		i++;
	}
	free_cmdarg(_cmdarg);
	err_msg("Error: command doesn't executed");
}
