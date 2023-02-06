/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:50:02 by yachaab           #+#    #+#             */
/*   Updated: 2023/02/04 11:42:28 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

typedef struct s_var
{
	int		which;
	int		infile;
	int		outfile;
	int		cmd_nbr;
	int		ac;
	char	*infile_path;
	int		*pid;
	int		**fd;
	char	*path;
	char	**argv;
	char	**env;
	char	**splited_paths;
	char	**cmdargs;
}	t_var;

// <----- lib/stderr.c ----->
void	err_msg(char *str);

// <----- utils/pipex.c ----->
void	ft_pipex(t_var *args);

// <----- utils/ft_help.c ----->
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// <----- utils/parsing.c ----->
char	*global_path(char **env);
char	*_join(char *path, char *cmd);
char	*ft_strrchr(const char *s, int c);
void	check_and_join(t_var *args, char **_cmdarg, char *str, int i);

// <----- utils/ft_split.c ----->
char	**ft_split(const char *string, char delim);

// <----- utils/initargs.c ----->
void	init_args(t_var *args, int argc, char **argv, char **env);
void	init_args_hrdoc(t_var *args, int argc, char **argv, char **env);

// <----- utils/dry.c ----->
// void	child_proc(t_var *args, int **fd);
void	_exec(t_var *args, int proc_index);

// <----- utils/pipex_help.c ----->
int		*init_pid(int *pid, int cmd_nbr);
int		**init_fd(int **fd, int cmd_nbr);
void	init_pipes(int **fd, int cmd_nbr);
void	exec_cmd(t_var *args, int i, int _isheredoc);
void	close_wait(t_var *args);

// <----- function/get_next_line ----->
char	*get_next_line(int fd);

// <----- utils/ft_heredoc.c ----->
void	ft_heredoc(int fd, char *limiter);

// main.c
int		is_heredoc(char *arg, char *str, int one);
#endif