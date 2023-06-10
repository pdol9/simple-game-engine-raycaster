/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:28:14 by pdolinar          #+#    #+#             */
/*   Updated: 2022/12/01 33:32:36 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* set the adjusted coord. values of textures for the wall */
void	set_tex_values(t_vars *vars, t_image *tex)
{
	if (vars->display.rays.side == 0)
		vars->display.rays.wall_x = vars->map.pos.y
			+ vars->display.rays.perp_wall_dist * vars->display.rays.raydir_y;
	else
		vars->display.rays.wall_x = vars->map.pos.x
			+ vars->display.rays.perp_wall_dist * vars->display.rays.raydir_x;
	vars->display.rays.wall_x -= floor(vars->display.rays.wall_x);
	vars->display.rays.tex_x = (int)(vars->display.rays.wall_x
			* (double)tex->width);
	if ((vars->display.rays.side == 0 && vars->map.pos.dir_x > 0)
		|| (vars->display.rays.side == 1 && vars->map.pos.dir_y < 0))
		vars->display.rays.tex_x = tex->width - vars->display.rays.tex_x;
	vars->display.rays.move_tex = tex->height
		/ (double)vars->display.rays.wallheight;
	vars->display.rays.tex_y = 0;
	if (vars->display.rays.wallheight > vars->display.size.y)
		vars->display.rays.tex_y = (vars->display.rays.wallheight
				- vars->display.size.y) * vars->display.rays.move_tex / 2;
}

void	draw_tex(t_image *img, t_vars *vars, int x)
{
	t_graphics	*rays;
	char		*addr;
	int			y_coor;
	int			color;

	rays = &vars->display.rays;
	set_tex_values(vars, img);
	y_coor = rays->start_draw;
	while (y_coor < rays->end_draw)
	{
		addr = NULL;
		addr = img->addr + ((int)(rays->tex_y) % img->height * img->line_length
				+ rays->tex_x % img->width * (img->bits_per_pixel / 8));
		color = *(int *)addr;
		put_pixel(&(vars->img), x, y_coor, color);
		rays->tex_y += rays->move_tex;
		y_coor++;
	}
}
