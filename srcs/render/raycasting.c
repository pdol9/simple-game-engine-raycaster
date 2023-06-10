/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:28:14 by pdolinar          #+#    #+#             */
/*   Updated: 2022/12/01 17:32:52 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Delta = x / y measurement of each grid element (side to side) 
	camera IS the x-coordinate of the camera plane, ranginng
	between -1 to 1. */
void	ray_casting(t_vars *vars, t_graphics *rays, int x)
{
	rays->camera = 2 * x / (double)vars->display.size.x - 1;
	rays->raydir_x = vars->map.pos.dir_x + vars->map.pos.plane_x * rays->camera;
	rays->raydir_y = vars->map.pos.dir_y + vars->map.pos.plane_y * rays->camera;
	rays->delta_dist_x = fabs(1 / rays->raydir_x);
	rays->delta_dist_y = fabs(1 / rays->raydir_y);
	rays->map_x = (int)vars->map.pos.x;
	rays->map_y = (int)vars->map.pos.y;
}

/*	map_x = starting position from player.
	curlen = length of ray from current position to 
	next x or y-side. 
	move = value of a direction to move to. 
	
	Function gets values for ray length. */
void	grid_scanning(t_vars *vars, t_graphics *rays)
{
	if (rays->raydir_x < 0)
	{
		rays->step_x = -1;
		rays->side_dist_x = (vars->map.pos.x - rays->map_x)
			* rays->delta_dist_x;
	}
	else
	{
		rays->step_x = 1;
		rays->side_dist_x = (rays->map_x + 1.0 - vars->map.pos.x)
			* rays->delta_dist_x;
	}
	if (rays->raydir_y < 0)
	{
		rays->step_y = -1;
		rays->side_dist_y = (vars->map.pos.y - rays->map_y)
			* rays->delta_dist_y;
	}
	else
	{
		rays->step_y = 1;
		rays->side_dist_y = (rays->map_y + 1.0 - vars->map.pos.y)
			* rays->delta_dist_y;
	}
}

/* Scans for the walls, using DDA.
	Working way: goes through grid, skipping every x and y.
	IF wall is hit, wall variable = 1; 
	 */
void	wall_mapping(t_vars *vars, t_graphics *rays)
{
	int	wall;

	wall = 0;
	while (wall == 0)
	{
		if (rays->side_dist_x < rays->side_dist_y)
		{
			rays->side_dist_x += rays->delta_dist_x;
			rays->map_x += rays->step_x;
			rays->side = 0;
		}
		else
		{
			rays->side_dist_y += rays->delta_dist_y;
			rays->map_y += rays->step_y;
			rays->side = 1;
		}
		if (vars->map.layout[rays->map_y][rays->map_x] == '1')
			wall = 1;
	}
}

/* Draws the wall. 
	1. Calculates distance from player's direction towards
	wall. 
	2. Calculated height of wall to be drawn
	3. Draws the wall.  */
void	wall_projec(t_vars *vars, t_graphics *rays)
{
	if (rays->side == 0)
		rays->perp_wall_dist = rays->side_dist_x - rays->delta_dist_x;
	else
		rays->perp_wall_dist = rays->side_dist_y - rays->delta_dist_y;
	rays->wallheight = (int)(vars->display.size.y / rays->perp_wall_dist);
	rays->start_draw = -rays->wallheight / 2 + vars->display.size.y / 2;
	if (rays->start_draw < 0)
		rays->start_draw = 0;
	rays->end_draw = rays->wallheight / 2 + vars->display.size.y / 2;
	if (rays->end_draw >= vars->display.size.y)
		rays->end_draw = vars->display.size.y - 1;
}
