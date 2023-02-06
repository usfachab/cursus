/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:14:41 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/29 18:26:20 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

char	*global_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
			return (env[i]);
		i++;
	}
	err_msg("Error: can't find PATH variable");
	return (NULL);
}

char	*_join(char *path, char *cmd)
{
	size_t		i;
	size_t		j;
	char		*ptr;

	i = 0;
	ptr = malloc(ft_strlen(path) + ft_strlen(cmd) + 2);
	if (!ptr)
		return (NULL);
	while (i < ft_strlen(path))
	{
		ptr[i] = path[i];
		i++;
	}
	ptr[i] = '/';
	i += 1;
	ptr[i] = 0;
	j = 0;
	while (j < ft_strlen(cmd))
	{
		ptr[i + j] = cmd[j];
		j++;
	}
	ptr[i + j] = 0;
	return (ptr);
}

void	check_and_join(t_var *args, char **_cmdarg, char *str, int i)
{
	if (!access(_cmdarg[0], F_OK))
			args->path = _join("", _cmdarg[0]);
	else
	{
		if (str != NULL)
			args->path = _join("", str + 1);
		else
			args->path = _join(args->splited_paths[i], _cmdarg[0]);
	}
}

void	free_cmdarg(char **_cmdarg)
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
