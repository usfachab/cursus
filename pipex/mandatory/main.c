/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:25:53 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/01 18:03:37 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	t_var	args;

	if (argc != 5)
		err_msg("Error: number of argument not correct");
	init_args(&args, argv, env);
	ft_pipex(&args);
	return (0);
}
