/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:26:57 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/12 00:26:39 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_H
#define INC_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif
#define IMGX 60
#define IMGY 60
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
// typedef struct t_map
// {
// 	int	n_player;
// 	int	n_collect;
// 	int	n_exit;
// 	int n_row;
// 	int	n_col[100];
// 	int	i;
// 	int	j;
// 	char **map;
// } s_data;

typedef struct t_var
{
	int i;
	int j;
	int k;
} s_var;

typedef struct t_position
{
	int	x;
	int	y;
} s_pos;

typedef struct	t_data
{
	void	*img;
	int		*addr;
	void	*mlx;
	void	*mlx_win;
	char	*string;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_height;
	int		img_width;
	char	**map;
	int		len_col;
	int		len_row;
	int		pl_pos_x;
	int		pl_pos_y;
	int		exit_pos_x;
	int		exit_pos_y;
	int		n_player;
	int		n_collect;
	int		n_exit;
	int		n_row;
	int		n_col[100];
	int		i;
	int		j;
}	s_data;

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(const char *string, char delim);
int		ft_strcmp(const char *s1, const char *s2);
// init struct
s_data	*val_init(s_data *data);
s_var	init_fat(void);
void	err_msg(char *msg, s_data *map, char **line);
// check map
s_pos	player_position(char **map, char c);
void	check_map_file(int fd, char *ext);
void	check_new_line(char *string);
s_data	*check_line(char **line);
void	check_wall(char **line);
void	check_char(char **line, s_data *data);
void	check_map_size(s_data *number);
char	*read_file_lines(int fd);
void	check_blockage(s_data *map_size, char **line);
void	flood(char **line, s_data *size, s_pos pos);
// execute outher functions
int		main_func(char *argv);

void	ft_render(s_data *data);

void	init_data(s_data *data, char *string);

void	right(s_data *data);

void	left(s_data *data);

void	up(s_data *data);

void	down(s_data *data);
#endif