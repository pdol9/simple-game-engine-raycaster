/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluik <mluik@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:26:20 by mluik             #+#    #+#             */
/*   Updated: 2022/12/02 12:32:07 by mluik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_forward(t_vars *vars)
{
	double	tmp;
	double	tmp02;

	tmp = vars->map.pos.y;
	tmp += vars->map.pos.dir_y * MOVEMENT_SPEED;
	tmp02 = vars->map.pos.x;
	tmp02 += vars->map.pos.dir_x * MOVEMENT_SPEED;
	if (vars->map.layout[(int)tmp][(int)tmp02] == '0')
	{
		vars->map.pos.y += vars->map.pos.dir_y * MOVEMENT_SPEED;
		vars->map.pos.x += vars->map.pos.dir_x * MOVEMENT_SPEED;
	}
	return (0);
}

int	move_back(t_vars *vars)
{
	double	tmp;
	double	tmp02;

	tmp = vars->map.pos.y;
	tmp -= vars->map.pos.dir_y * MOVEMENT_SPEED;
	tmp02 = vars->map.pos.x;
	tmp02 -= vars->map.pos.dir_x * MOVEMENT_SPEED;
	if (vars->map.layout[(int)tmp][(int)tmp02] == '0')
	{
		vars->map.pos.y -= vars->map.pos.dir_y * MOVEMENT_SPEED;
		vars->map.pos.x -= vars->map.pos.dir_x * MOVEMENT_SPEED;
	}
	return (0);
}

int	move_left(t_vars *vars)
{
	if (vars->map.pos.dir_y >= 0 && vars->map.pos.dir_x >= 0 \
		&& vars->map.layout[(int)vars->map.pos.y][(int)vars->map.pos.x] == '0')
	{
		vars->map.pos.y -= MOVEMENT_SPEED * fabs(vars->map.pos.dir_x);
		vars->map.pos.x += MOVEMENT_SPEED * fabs(vars->map.pos.dir_y);
	}
	if (vars->map.pos.dir_y < 0 && vars->map.pos.dir_x < 0 \
		&& vars->map.layout[(int)vars->map.pos.y][(int)vars->map.pos.x] == '0')
	{
		vars->map.pos.y += MOVEMENT_SPEED * fabs(vars->map.pos.dir_x);
		vars->map.pos.x -= MOVEMENT_SPEED * fabs(vars->map.pos.dir_y);
	}
	if (vars->map.pos.dir_y >= 0 && vars->map.pos.dir_x < 0 \
		&& vars->map.layout[(int)vars->map.pos.y][(int)vars->map.pos.x] == '0')
	{
		vars->map.pos.y += MOVEMENT_SPEED * fabs(vars->map.pos.dir_x);
		vars->map.pos.x += MOVEMENT_SPEED * fabs(vars->map.pos.dir_y);
	}
	if (vars->map.pos.dir_y < 0 && vars->map.pos.dir_x >= 0 \
		&& vars->map.layout[(int)vars->map.pos.y][(int)vars->map.pos.x] == '0')
	{
		vars->map.pos.y -= MOVEMENT_SPEED * fabs(vars->map.pos.dir_x);
		vars->map.pos.x -= MOVEMENT_SPEED * fabs(vars->map.pos.dir_y);
	}
	return (0);
}

int	move_right(t_vars *vars)
{
	if (vars->map.pos.dir_y >= 0 && vars->map.pos.dir_x >= 0 \
		&& vars->map.layout[(int)vars->map.pos.y][(int)vars->map.pos.x] == '0')
	{
		vars->map.pos.y += MOVEMENT_SPEED * fabs(vars->map.pos.dir_x);
		vars->map.pos.x -= MOVEMENT_SPEED * fabs(vars->map.pos.dir_y);
	}
	if (vars->map.pos.dir_y < 0 && vars->map.pos.dir_x < 0 \
		&& vars->map.layout[(int)vars->map.pos.y][(int)vars->map.pos.x] == '0')
	{
		vars->map.pos.y -= MOVEMENT_SPEED * fabs(vars->map.pos.dir_x);
		vars->map.pos.x += MOVEMENT_SPEED * fabs(vars->map.pos.dir_y);
	}
	if (vars->map.pos.dir_y >= 0 && vars->map.pos.dir_x < 0 \
		&& vars->map.layout[(int)vars->map.pos.y][(int)vars->map.pos.x] == '0')
	{
		vars->map.pos.y -= MOVEMENT_SPEED * fabs(vars->map.pos.dir_x);
		vars->map.pos.x -= MOVEMENT_SPEED * fabs(vars->map.pos.dir_y);
	}
	if (vars->map.pos.dir_y < 0 && vars->map.pos.dir_x >= 0 \
		&& vars->map.layout[(int)vars->map.pos.y][(int)vars->map.pos.x] == '0')
	{
		vars->map.pos.y += MOVEMENT_SPEED * fabs(vars->map.pos.dir_x);
		vars->map.pos.x += MOVEMENT_SPEED * fabs(vars->map.pos.dir_y);
	}
	return (0);
}
