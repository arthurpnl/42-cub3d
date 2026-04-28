/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoudad <skoudad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 21:21:42 by skoudad           #+#    #+#             */
/*   Updated: 2026/02/21 01:36:00 by skoudad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "get_next_line.h"

# include <mlx.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <errno.h>
# include <string.h>
# include <signal.h>
# include <stdbool.h>
# include <limits.h>

# define WIN_HEIGHT 720
# define WIN_WIDTH 1080
# define FOV 60
# define PI 3.14159265358979323846
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

typedef enum e_keycode
{
	KEY_ESC = 65307,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_W = 'w',
	KEY_A = 'a',
	KEY_S = 's',
	KEY_D = 'd',
	KEY_Z = 'z',
	KEY_Q = 'q',
}	t_keycode;

typedef struct s_keys
{
	int	forward;
	int	backward;
	int	strafe_left;
	int	strafe_right;
	int	rot_left;
	int	rot_right;
}	t_keys;

typedef enum e_direction
{
	N,
	E,
	S,
	W,
}	t_direction;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_player
{
	float	x;
	float	y;
	float	orientation;
}	t_player;

typedef struct s_line
{
	char			*str;
	struct s_line	*next;
}	t_line;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		tex_w;
	int		tex_h;
}	t_img;

typedef struct s_ray
{
	float	dir_x;
	float	dir_y;
	float	delta_x;
	float	delta_y;
	float	side_x;
	float	side_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		side;
	float	wall_dist;
}	t_ray;

typedef struct s_col
{
	int		x;
	int		start;
	int		end;
	int		h;
	t_img	*tex;
	int		tex_x;
}	t_col;

typedef struct s_data
{
	char		*textures[4];
	t_color		floor;
	t_color		ceiling;
	char		**map;
	int			map_w;
	int			map_h;
	t_player	player;
	t_line		*beggin;
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		tex[4];
	t_keys		keys;
}	t_data;

// Main utils
void	ft_error(char *str);
int		ft_strslen(char **strs);
void	free_strs(char **strs);
void	free_parsing(t_data *data);

// -- Math --
float	ft_sin(float x);
float	ft_cos(float x);

// -- Parsing --
int		parsing(t_data *data, char *path);
int		check_suffix(char *path, char *suffix);
void	free_textures(char **textures);
int		check_texture(t_data *data, int fd);
int		put_color(t_color *color, char *floorc);
bool	check_empty(char **strs, int expected_len);
int		check_map(t_data *data, int fd);
char	**map_table(t_line *curr);
int		is_in(char c, char *str);
int		flood_fill(char **map, int x, int y);
t_line	*fill_line(char *line);
void	free_line(t_line *curr, bool free_str);
char	**ft_strsdup(char **srcs);

// -- Rendering --
int		rendering(t_data *data);
int		load_textures(t_data *data);
int		render_frame(t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		color_to_int(t_color color);

// -- 3D Rendering --
void	render_3d(t_data *data);

// -- Raycasting --
void	cast_ray(t_data *data, float angle, t_ray *ray);

// -- Movement --
void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	strafe_left(t_data *data);
void	strafe_right(t_data *data);
void	rotate_player(t_data *data, int direction);
void	update_movement(t_data *data);

// -- Rendering cleanup --
void	free_rendering(t_data *data);
int		close_window(t_data *data);
int		handle_key(int keycode, t_data *data);
int		handle_keyrelease(int keycode, t_data *data);

#endif
