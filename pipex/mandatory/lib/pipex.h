/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:50:02 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/01 18:21:35 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

typedef struct s_var
{
	int		infile;
	int		outfile;
	char	*path;
	char	**argv;
	char	**env;
	char	**splited_paths;
	char	**cmd1args;
	char	**cmd2args;
}	t_var;

// <----- lib/stderr.c ----->
void	err_msg(const char *str);

// <----- utils/pipex.c ----->
void	ft_pipex(t_var *args);

// <----- utils/helpers.c ----->
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strrchr(const char *s, int c);

// <----- utils/parsing.c ----->
char	*global_path(char **env);
char	*_join(char *path, char *cmd);
void	check_and_join(t_var *args, char **_cmdarg, char *str, int i);
void	free_cmdarg(char **_cmdarg);

// <----- utils/ft_split.c ----->
char	**ft_split(const char *string, char delim);

// <----- utils/initargs.c ----->
void	init_args(t_var *args, char **argv, char **env);

// <----- utils/dry.c ----->
void	child_pro_1(t_var *args, int *fd);
void	child_pro_2(t_var *args, int *fd);
void	dry(t_var *args, int who);
#endif