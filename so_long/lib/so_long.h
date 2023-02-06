/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:58:29 by yachaab           #+#    #+#             */
/*   Updated: 2023/01/16 12:18:56 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define IMGX 60
# define IMGY 60
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_data
{
	void	*mlx;
	char	*string;
	char	**map;
	int		n_row;
	int		n_col;
	void	*mlx_win;
	void	*img;
	int		*addr;
	int		pl_pos_x;
	int		pl_pos_y;
	int		n_player;
	int		n_collect;
	int		n_exit;
	int		e_pos_x;
	int		e_pos_y;
}	t_data;

// STANDERD ERROR <-- stderr.c-->
int		ft_close(t_data *data);
size_t	ft_strlen(const char *s);
void	err_msg(char *msg);

// CHECK FUNCTIONS <-- checkMap.c-->
void	check_map_file(char *fileName);
void	check_new_line(char *string);
void	check_char(char *string);
void	check_wall(char **map);

// FUNCTION THAT RUN ALL CHECK FUNCTIONS <-- exeCheck.c-->
int		execheck(char *string, char *argv);

// DATAT STRUCT INIT <-- initstruct.c-->
void	init_data(t_data *data, char *string);

// Initialisation helpers <-- initHelper.c-->
int		row_len(char **map);
int		col_len(char **map);
void	count_charachters(char *string);
void	get_position(char **map, t_pos *pos, char C);
int		init_collect(char *string);

// helper functions <-- helper.c-->
char	**ft_split(const char *string, char delim);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*read_file_lines(int fd);

// check if there is any blockad <-- ft_flood.c-->
void	ft_flood(char **map, t_pos pos);

// <-- checkMapafter.c -->
void	_blocked(char **map);

// IMAGES RENDERING <-- ft_render.c-->
void	ft_render(t_data *data);

/// KEYHOOKS <-- ft_keyhook.c-->
int		key_hook(int keycode, t_data *data);

// DIRECTIONS <-- ft_derictions.c-->
void	left(t_data *data, int *i);
void	right(t_data *data, int *i);
void	up(t_data *data, int *i);
void	down(t_data *data, int *i);

// put number
void	ft_putnbr(int nb);

// SPECIALE CASE 
void	make_e_one(char **map, t_pos *exit_pos);

#endif