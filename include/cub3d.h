/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:45:53 by mluik             #+#    #+#             */
/*   Updated: 2022/12/02 16:59:20 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE		1024

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <libft.h>
# include "../mlx/mlx.h"

# define A_KEY				97
# define W_KEY				119
# define S_KEY				115
# define D_KEY				100
# define LEFT_KEY			65361
# define RIGHT_KEY			65363
# define ESC				65307

# define SCR_WIDTH			1200
# define SCR_HEIGHT			600

# define ROTATE_SPEED		0.03
# define MOVEMENT_SPEED		0.05

typedef struct s_vector {
	int			x;
	int			y;
}	t_vector;

/* y - height (up-down direction on 2D map)
   x - length (left-right direction) */
typedef struct s_player {
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}	t_player;

typedef struct s_image {
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}	t_image;

/* env */
typedef struct s_texture {
	t_image		north;
	t_image		south;
	t_image		east;
	t_image		west;
	int			c;
	int			f;
	int			wallcode;
}	t_texture;

/* rays */
typedef struct s_graphics {
	double		camera;
	double		perp_wall_dist;
	double		raydir_x;
	double		raydir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
	int			wallheight;
	int			tex_x;
	double		tex_y;
	double		move_tex;
	double		wall_x;
	int			end_draw;
	int			start_draw;
	double		tex_pos;
}	t_graphics;

typedef struct s_map {
	char		**layout;
	t_vector	size;
	t_player	pos;
}	t_map;

typedef struct s_meta {
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	char			*floor_f;
	char			*floor_s;
	char			*floor_t;
	char			*ceiling_f;
	char			*ceiling_s;
	char			*ceiling_t;
	int				check_north;
	int				check_south;
	int				check_west;
	int				check_east;
	int				check_floor;
	int				check_ceiling;
	int				firstrow;
}	t_meta;

typedef struct s_screen {
	t_vector	size;
	t_graphics	rays;
}	t_screen;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_image		img;
	t_map		map;
	t_screen	display;
	t_texture	env;
	t_meta		meta;
}	t_vars;

/* Functions in file "parse_rgb.c" */
int		ft_checkcheck(t_vars *vars);
int		ft_count_char(char *line, int i);
void	ft_parse_colors(t_vars *vars, char *line);
void	ft_parse_textures(t_vars *vars, char *line, char x, char y);

/* Functions in file "parse_rgb.c" */
int		return_int(char *string);
int		ft_findfirst(char *line, int start);

/* Functions in file "parse_rgb.c" */
void	init_colors_c(t_vars *vars);
void	init_colors_f(t_vars *vars);
int		ft_count_comma(int i, char *line);
int		parse_ceiling(t_vars *vars, char *line);
int		parse_floor(t_vars *vars, char *line);

/* Functions in file "savemeta.c" */
void	ft_saveeast(int i, char *line, t_vars *vars);
void	ft_savewest(int i, char *line, t_vars *vars);
void	ft_savesouth(int i, char *line, t_vars *vars);
void	ft_savenorth(int i, char *line, t_vars *vars);
int		ft_check_order(t_vars *vars, char *line);

/* Functions in file "libft_f.c" */
char	*ft_strstr(char *str, char *substr);

/* Functions in file "get_next_line.c" */
char	*get_before_newline(const char *s);
char	*get_after_newline(const char *s);
void	ft_read_line(int fd, char **keep, char **tmp);
char	*ft_parse_line(char **keep, char **tmp);
char	*get_next_line(int fd);

/* Functions in file "get_next_line_utils.c" */
int		contains_newline(const char *s);
char	*join_strs(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
void	*ft_malloc_zero(size_t count, size_t size);
void	ft_free_strs(char **str, char **str2, char **str3);

/* Functions in file "exit.c" */
void	error(t_vars *vars, char *msg);
int		close_map(t_vars *vars);
int		mlx_close(void *vars);

/* Functions in file "render.c" */
void	grid_scanning(t_vars *vars, t_graphics *rays);
void	draw_tex(t_image *img, t_vars *vars, int x);
void	fov_rendering(t_vars *vars);

/* Functions in file "move_02.c" */
int		move_forward(t_vars *vars);
int		move_back(t_vars *vars);
int		move_left(t_vars *vars);
int		move_right(t_vars *vars);

/* Functions in file "move_01.c" */
void	movement_helper(t_vars *vars);
int		rotate_left(t_vars *vars);
int		move(int keycode, t_vars *vars);
int		use_key(int keycode, void *vars);

/* Functions in file "pos_player.c" */
int		ft_save_dir(t_vars *vars, char pchar);
void	position_player(t_vars *vars);

/* Functions in files "layout.c" && "check_file.c" */
void	ft_finalcheck(t_vars *vars);
int		check_map_characters(t_vars *vars);
int		check_objects(t_vars *vars);
int		check_walls(t_vars *vars);
int		check_layout(t_vars *vars);
void	ft_bugreport_end(char *line, int i);
void	ft_checkfor_doubles(t_vars *vars, char **argv);

/* Functions in file "init.c" */
int		ft_init_game(t_vars *vars, char **argv);
void	ft_parse_meta(t_vars *vars, char *line);
int		ft_get_mapsize(t_vars *vars, char **argv);
void	ft_parse_map(t_vars *vars, char **argv);
int		ft_check_map(int argc, char **argv);

/* Functions in file "init_vars.c" */
t_vars	ft_init_vars(void);
void	init_mlx_data(t_vars *vars);

/* render_utils.c */
void	put_pixel(t_image *img, int x, int y, int color);
void	background(t_vars *vars);
t_image	*get_wall_img(t_texture *tex);
void	ft_setwall(t_vars *vars, t_graphics *rays);

/* raycasting.c */
void	ray_casting(t_vars *vars, t_graphics *rays, int x);
void	grid_scanning(t_vars *vars, t_graphics *rays);
void	wall_mapping(t_vars *vars, t_graphics *rays);
void	wall_projec(t_vars *vars, t_graphics *rays);

#endif
