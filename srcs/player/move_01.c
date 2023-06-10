/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:30:49 by mluik             #+#    #+#             */
/*   Updated: 2022/12/02 15:32:47 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movement_helper(t_vars *vars)
{
	if (vars->map.pos.dir_y == 0)
		vars->map.pos.dir_y = 0.01;
	if (vars->map.pos.dir_x == 0)
		vars->map.pos.dir_x = 0.01;
}

int	rotate_left(t_vars *vars)
{
	double	tmp;
	double	tmp_02;

	tmp = vars->map.pos.dir_x;
	vars->map.pos.dir_x = cos (-ROTATE_SPEED) * vars->map.pos.dir_x \
		- vars->map.pos.dir_y * sin(-ROTATE_SPEED);
	vars->map.pos.dir_y = sin(-ROTATE_SPEED) * tmp \
		+ cos (-ROTATE_SPEED) * vars->map.pos.dir_y;
	tmp_02 = vars->map.pos.plane_x;
	vars->map.pos.plane_x = cos (-ROTATE_SPEED) * vars->map.pos.plane_x \
		- vars->map.pos.plane_y * sin (-ROTATE_SPEED);
	vars->map.pos.plane_y = sin (-ROTATE_SPEED) * tmp_02 \
		+ cos (-ROTATE_SPEED) * vars->map.pos.plane_y;
	return (0);
}

int	rotate_right(t_vars *vars)
{
	double	tmp;
	double	tmp_02;

	tmp = vars->map.pos.dir_x;
	vars->map.pos.dir_x = cos (ROTATE_SPEED) * vars->map.pos.dir_x \
		- vars->map.pos.dir_y * sin(ROTATE_SPEED);
	vars->map.pos.dir_y = sin(ROTATE_SPEED) * tmp \
		+ cos (ROTATE_SPEED) * vars->map.pos.dir_y;
	tmp_02 = vars->map.pos.plane_x;
	vars->map.pos.plane_x = cos (ROTATE_SPEED) * vars->map.pos.plane_x \
		- vars->map.pos.plane_y * sin (ROTATE_SPEED);
	vars->map.pos.plane_y = sin (ROTATE_SPEED) * tmp_02 \
		+ cos (ROTATE_SPEED) * vars->map.pos.plane_y;
	return (0);
}

int	use_key(int keycode, void *vars)
{
	movement_helper(vars);
	if (keycode == ESC)
		mlx_close(vars);
	else if (keycode == D_KEY)
		move_right(vars);
	else if (keycode == A_KEY)
		move_left(vars);
	else if (keycode == S_KEY)
		move_back(vars);
	else if (keycode == W_KEY)
		move_forward(vars);
	else if (keycode == LEFT_KEY)
		rotate_left(vars);
	else if (keycode == RIGHT_KEY)
		rotate_right(vars);
	fov_rendering(vars);
	return (0);
}
