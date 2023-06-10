/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:21:29 by mluik             #+#    #+#             */
/*   Updated: 2022/11/30 20:24:00 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vars	init_display(t_vars vars)
{
	vars.display.size.x = SCR_WIDTH;
	vars.display.size.y = SCR_HEIGHT;
	vars.display.rays.camera = 0;
	vars.display.rays.raydir_x = -1;
	vars.display.rays.raydir_y = 0;
	vars.display.rays.delta_dist_x = 0;
	vars.display.rays.delta_dist_y = 0;
	vars.display.rays.side_dist_y = 0;
	vars.display.rays.side_dist_x = 0;
	vars.display.rays.map_x = 0;
	vars.display.rays.map_y = 0;
	vars.display.rays.step_x = 0;
	vars.display.rays.step_y = 0;
	vars.display.rays.side = 0;
	vars.env.wallcode = 0;
	vars.display.rays.move_tex = 0;
	vars.display.rays.wall_x = 0;
	vars.display.rays.tex_y = 0;
	vars.display.rays.tex_pos = 0;
	vars.display.rays.end_draw = 0;
	vars.display.rays.start_draw = 0;
	return (vars);
}

t_vars	ft_init_vars(void)
{
	t_vars	vars;

	vars = init_display(vars);
	vars.map.size.x = 0;
	vars.map.size.y = 0;
	vars.map.pos.plane_x = 0;
	vars.map.pos.plane_y = 0.66;
	vars.map.pos.dir_x = 0;
	vars.map.pos.dir_y = 0;
	vars.map.pos.x = 0;
	vars.map.pos.y = 0;
	vars.meta.check_ceiling = 0;
	vars.meta.check_east = 0;
	vars.meta.check_floor = 0;
	vars.meta.check_north = 0;
	vars.meta.check_south = 0;
	vars.meta.check_west = 0;
	vars.env.north.img_ptr = NULL;
	vars.env.east.img_ptr = NULL;
	vars.env.south.img_ptr = NULL;
	vars.env.west.img_ptr = NULL;
	return (vars);
}

static
void	init_textures(t_vars *vars, t_image *img, char *wall)
{
	img->img_ptr = mlx_xpm_file_to_image(vars->mlx, wall,
			&img->width, &img->height);
	if (img->img_ptr == NULL)
		error(vars, "Error\nFailed to initialise texture.\n");
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->img_ptr == NULL)
		error(vars, "Error\nFailed to initialise texture.\n");
}

void	init_mlx_data(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		error(vars, "Error\nFailed to initialise mlx.\n");
	vars->win = mlx_new_window(vars->mlx, vars->display.size.x, \
		vars->display.size.y, "cub3D");
	if (vars->win == NULL)
		error(vars, "Error\nFailed to initialise mlx window.\n");
	vars->img.img_ptr = mlx_new_image(vars->mlx, SCR_WIDTH, SCR_HEIGHT);
	if (vars->img.img_ptr == NULL)
		error(vars, "Error\nFailed to initialise image.\n");
	vars->img.addr = mlx_get_data_addr(vars->img.img_ptr,
			&vars->img.bits_per_pixel, &vars->img.line_length,
			&vars->img.endian);
	if (vars->img.addr == NULL)
		error(vars, "Error\nFailed to initialise image addr.\n");
	init_textures(vars, &vars->env.north, vars->meta.north);
	init_textures(vars, &vars->env.south, vars->meta.south);
	init_textures(vars, &vars->env.east, vars->meta.east);
	init_textures(vars, &vars->env.west, vars->meta.west);
}
