/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:10:42 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/04 11:43:04 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex_bonus.h"

void	init_args(t_var *args, int argc, char **argv, char **env)
{
	args->ac = argc;
	args->which = 2;
	args->infile_path = argv[1];
	args->argv = argv;
	args->cmd_nbr = argc - 3;
	args->env = env;
	args->infile = open(args->infile_path, O_RDONLY);
	args->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	args->path = global_path(env);
	args->splited_paths = ft_split(args->path + 5, ':');
	args->pid = init_pid(args->pid, args->cmd_nbr);
	args->fd = init_fd(args->fd, args->cmd_nbr);
}

void	init_args_hrdoc(t_var *args, int argc, char **argv, char **env)
{
	args->ac = argc;
	args->which = 3;
	args->argv = argv;
	args->cmd_nbr = argc - 4;
	args->env = env;
	args->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0777);
	args->path = global_path(env);
	args->splited_paths = ft_split(args->path + 5, ':');
	args->pid = init_pid(args->pid, args->cmd_nbr);
	args->fd = init_fd(args->fd, args->cmd_nbr);
}
