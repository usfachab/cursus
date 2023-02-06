/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:25:53 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/03 21:54:49 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/pipex_bonus.h"

int	is_heredoc(char *str, char *arg, int one)
{
	int	str_len;
	int	arg_len;

	str_len = ft_strlen(str) + one;
	arg_len = ft_strlen(arg);
	if (str_len == arg_len && ft_memcmp(str, arg, arg_len) == 0)
		return (1);
	return (0);
}

int	main(int argc, char *argv[], char *env[])
{
	t_var	args;
	int		is_here;

	if (argc < 5)
		err_msg("Error: number of argument not correct");
	is_here = is_heredoc("here_doc", argv[1], 0);
	if (is_here)
	{
		if (argc != 6)
			err_msg("Error: number of argument not correct");
		init_args_hrdoc(&args, argc, argv, env);
	}
	else
		init_args(&args, argc, argv, env);
	ft_pipex(&args);
	return (0);
}
