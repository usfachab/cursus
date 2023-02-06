/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initargs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:10:42 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/01 18:02:36 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

void	init_args(t_var *args, char **argv, char **env)
{
	args->argv = argv;
	args->env = env;
	args->path = global_path(env);
	args->splited_paths = ft_split(args->path + 5, ':');
	args->cmd1args = ft_split(args->argv[2], ' ');
	args->cmd2args = ft_split(args->argv[3], ' ');
}
